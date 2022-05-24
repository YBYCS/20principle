#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define AUTO_RUN "HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"
#include<QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlError>
#include<QDebug>
#include <QMainWindow>
#include<QSystemTrayIcon>
#include<QDesktopServices>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <QTime>
#include <QDir>
#include <QSettings>
#include <QCoreApplication>
#include <qt_windows.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createActions();
    void createMenu();
private:
    void createDB();
    void createTable();
    void queryTable();
    void initTray();
    void toAlert();//调用展示提示框
    void startClock();
    void pauseClock();
    void autoOpen(bool isStart);//自动启动



private slots:
    void on_bt_start_toggled();

    void on_bt_isOpen_toggled(bool checked);

    void on_bt_save_clicked();

    void TrayIconAction(QSystemTrayIcon::ActivationReason reason);//对托盘图标操作的槽：本代码实现单机图标恢复窗口功能

    void updateTime();

    void initTime();//初始化时间

    void dealClick();//处理信息点击

    void showAlert();//展示到点提示框

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;//建立Qt和数据库链接
    QSqlQueryModel model;//保存model
    QString title;

    QSystemTrayIcon *tray;//托盘图标
    QMenu *menu;//托盘菜单
    QAction *reset;//菜单实现功能：恢复窗口
    QAction *quit;//菜单实现功能：退出程序

    QTimer *timer, *alertTimer;
    QTime *TimeRecord;


    int interval,rest;//工作和休息持续时长
    bool isOpen;//是否开机启动
    bool isPause;//是否在暂停状态
    bool isRest;//是否在休息装填
    int hadClick;//用来防止用户点太多次消息回调了

protected:
    //void closeEvent(QCloseEvent *event);
    void hideEvent(QHideEvent  *event);
};
#endif // MAINWINDOW_H
