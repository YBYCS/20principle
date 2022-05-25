#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qvalidator.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(QPixmap("img/sakura.png")));
    ui->et_intervalDuration->setValidator(new QIntValidator(0,600,this));
    ui->et_restDuration->setValidator(new QIntValidator(0,600,this));
    createDB();
    createTable();
    queryTable();
    isPause = true;
    isRest = false;//是否在休息
    initTray();


    isPause = false;
    timer = new QTimer;
    TimeRecord = new QTime;
    alertTimer = new QTimer;
    //连接槽函数，将timer的timeout行为，连接到updateTime函数中
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    ui->Timer->setDigitCount(8);
    ui->bt_start->setText("现在:计时中");
    on_bt_start_toggled();//调用一次开始计时
    ui->lb_explain->setText("距下次休息时间:");

    connect(ui->bt_isOpen,SIGNAL(cliked()),this,SLOT(on_bt_isOpen_toggled(bool checked)));
    connect(ui->bt_save,SIGNAL(cliked()),this,SLOT(on_bt_save_clicked()));
    connect(ui->bt_start,SIGNAL(cliked()),this,SLOT(on_bt_start_toggled(bool checked)));
}

//析构函数
MainWindow::~MainWindow()
{
    delete ui;

}

//创建数据库
void MainWindow::createDB(){
    //添加数据库驱动
    db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库名字
    db.setDatabaseName("data.db");
    db.open();
}

//创建表并完成初始化
void MainWindow::createTable(){
    QSqlQuery query(db);
    QString str = QString ("create table data ("
                           "id INTEGER PRIMARY KEY,"
                           "name char(50) NOT NULL,"
                           "state char(50) NOT NULL)");



    if(query.exec(str)){
        //第一次成功创建表
        str = QString("insert into data values(null,'%1','%2')").arg("intervalDuration").arg("20");
        query.exec(str);
        str = QString("insert into data values(null,'%1','%2')").arg("restDuration").arg("20");
        query.exec(str);
        str = QString("insert into data values(null,'%1','%2')").arg("title").arg("时间已到,速速休息");
        query.exec(str);
        str = QString("insert into data values(null,'%1','%2')").arg("isOpen").arg("1");
        query.exec(str);
        autoOpen(true);
    }
}
//查询表初始化数据
void MainWindow::queryTable(){

    //获取间隔时间(工作时间)
    QString sql = "SELECT * FROM data WHERE name='intervalDuration'";
    QSqlQuery query(db);
    query.exec(sql);
    query.next();
    ui->et_intervalDuration->setText(query.value("state").toString());
    interval = query.value("state").toInt();

    //获取间隔时间(休息时间)
    sql = "SELECT * FROM data WHERE name='restDuration'";
    query.exec(sql);
    query.next();
    ui->et_restDuration->setText(query.value("state").toString());
    rest = query.value("state").toInt();


    //获取标题
    sql = "SELECT * FROM data WHERE name='title'";
    query.exec(sql);
    query.next();
    ui->et_title->setText(query.value("state").toString());
    title = query.value("state").toString();

    sql = "SELECT * FROM data WHERE name='isOpen'";
    query.exec(sql);
    query.next();
    if(query.value("state").toInt()){

        isOpen = true;
        ui->bt_isOpen->setText("现在:开机开启");
    }
    else{
        isOpen = false;
        ui->bt_isOpen->setText("现在:手动开启");
    }
}

//初始化时间
void MainWindow::initTime(){
    if(isRest){
        TimeRecord->setHMS(0,0,rest);
        ui->Timer->display(TimeRecord->toString("hh:mm:ss"));
    }
    else{
        TimeRecord->setHMS(0,interval,0);
        ui->Timer->display(TimeRecord->toString("hh:mm:ss"));
    }

}

//响应计时结束函数
void MainWindow::updateTime(){
    //每次更新时间，TimeRecord增加1
    *TimeRecord = TimeRecord->addSecs(-1);

    if(TimeRecord->hour()==0&&TimeRecord->minute()==0&&TimeRecord->second()==0){
        toAlert();
    }

    ui->Timer->display(TimeRecord->toString("hh:mm:ss"));
}

//开始和暂停计时 按钮
void MainWindow::on_bt_start_toggled()
{

    //暂停
    if(isPause){
        pauseClock();
        isPause = false;
        ui->bt_start->setText("开始");
    }
    else{//开始

        startClock();
        isPause = true;
        ui->bt_start->setText("暂停");
    }
}


//初始化时间并且开始计时
void MainWindow::startClock(){
    initTime();
    timer->start(1000);//计时间隔
}

//暂停计时
void MainWindow::pauseClock(){
    timer->stop();
}


//处理弹出提示框事件
void MainWindow::toAlert(){
    on_bt_start_toggled();
    hadClick = 1;
    alertTimer->start(10000);
    connect(alertTimer,SIGNAL(timeout()),this,SLOT(showAlert()));
}


//处理点击消息框 防止消息框多次点击 多次重复暂停
void MainWindow::dealClick(){

    if(hadClick){


        //如果还没点击
        hadClick = 0;
        isRest = !isRest;//改变时间状态
        on_bt_start_toggled();

    }
}

//弹出提示框
void MainWindow::showAlert(){
    if(isRest){
        tray->showMessage(QString("休息时间结束惹"),QString("速速开始工作"),tray->icon(),2000);
        connect(tray, SIGNAL(messageClicked()), this, SLOT(dealClick()));
    }
    else{
        tray->showMessage(QString("眼睛累了需要休息一下呢"),QString(title),tray->icon(),2000);
        connect(tray, SIGNAL(messageClicked()), this, SLOT(dealClick()));
    }
}




//是否开机启动
void MainWindow::on_bt_isOpen_toggled(bool checked)
{
    QSqlQuery query(db);
    isOpen = !isOpen;
    QString str;
    if(isOpen){
        ui->bt_isOpen->setText("现在:开机开启");
        str = QString("update data set state=1 WHERE name='isopen'");
        autoOpen(true);


    }
    else{
        ui->bt_isOpen->setText("现在:手动开启");
        str = QString("update data set state=0 WHERE name='isopen'");
        autoOpen(false);
    }
    query.exec(str);
}

void MainWindow::autoOpen(bool isStart){

    QSettings *settings = new QSettings(AUTO_RUN, QSettings::NativeFormat);
    QString application_name = QCoreApplication::applicationName();//获取应用名称

    if(isStart)
    {
        QString appPath = QCoreApplication::applicationFilePath();//找到应用的目录
        QString newPath = QDir::toNativeSeparators(appPath); //toNativeSeparators的意思是将"/"替换为"\"

        settings->setValue(application_name, newPath);
    }
    else
    {
        settings->remove(application_name);
    }

    settings->deleteLater();

    QString appPath = QCoreApplication::applicationDirPath();
    QString newPath = QDir::toNativeSeparators(appPath);
    SetCurrentDirectoryA(newPath.toStdString().c_str());
}

//保存数据
void MainWindow::on_bt_save_clicked()
{

    QString str,data;
    QSqlQuery query(db);
    query.prepare("update data set state=:state where name='restDuration'");
    data = ui->et_restDuration->text();
    rest = data.toInt();
    query.bindValue(":state",data);
    query.exec();
    query.prepare("update data set state=:state where name='intervalDuration'");
    data = ui->et_intervalDuration->text();
    interval = data.toInt();
    query.bindValue(":state",data);
    query.exec();
    query.prepare("update data set state=:state where name='title'");
    data = ui->et_title->text();
    title = data;
    query.bindValue(":state",data);
    query.exec();
}

void MainWindow::initTray(){
    tray=new QSystemTrayIcon(this);
    tray->setIcon(QIcon(QPixmap("img/sakura.png")));
    tray->show();
    //连接信号与槽，实现单击图标恢复窗口的功能，槽是自定义的槽
    QObject::connect(tray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(TrayIconAction(QSystemTrayIcon::ActivationReason)));


    //***初始化托盘菜单及功能***
     menu=new QMenu(this);//初始化菜单
     reset=new QAction(this);//初始化恢复窗口
     reset->setText("显示窗口");
     QObject::connect(reset,SIGNAL(triggered()),this,SLOT(showNormal()));//菜单中的显示窗口，单击连接显示窗口

     quit=new QAction(this);//初始化退出程序
     quit->setText("退出程序");
     QObject::connect(quit,SIGNAL(triggered()),qApp,SLOT(quit()));//菜单中的退出程序，单击连接退出</span>
     //qApp，是Qt自带的demo中的知识点，查了一下文档，qApp是Qt中所有app的指针，关闭它就可以关闭当前的程序</span>
    //之所以不用this，close()，是由于软件要求关闭改为最小化到托盘，所以close()的功能已经不再是关闭窗口的功能，所以要另寻方法
     //***将定义好的菜单加入托盘的菜单模块中***
     tray->setContextMenu(menu);
     menu->addAction(reset);
     menu->addAction(quit);

}


//关闭按钮是否重写
//void MainWindow::closeEvent(QCloseEvent *event){

//    hide();
//    event->ignore();
//}


//最小化到托盘
void MainWindow::hideEvent(QHideEvent *event){
    hide();
    event->ignore();
}

void MainWindow::TrayIconAction(QSystemTrayIcon::ActivationReason reason)
{
    //参数是Qt的保留字，表示对托盘图标的操作，该槽函数功能只实现了单击功能，可以实现其他功能比如双击、中击，具体可查文档或者Qt自带demo(关键字tray)
    if (reason==QSystemTrayIcon::Trigger)
        this->showNormal();//如果对图标进行单击，则显示正常大小的窗口
}


