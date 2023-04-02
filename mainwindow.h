#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantList>
#include <cmath>
#include <QPalette>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_image_background(QString bkgr);
private slots:
    void onResult(QNetworkReply *reply);
    void on_pushButton_clicked();

private:
    QFont b_font;
    QFont l_font;
    QFont h_font;
    int buff;
    QJsonObject *buff_object = new QJsonObject;
    QVariantMap v_map;
    Ui::MainWindow *ui;
    QNetworkAccessManager *networkManger;
    void write_city_name(QJsonObject json_object);
    void write_weather (QJsonObject json_object);
    void write_n_tempereture (QJsonObject json_object);
    void write_fl_tempereture (QJsonObject json_object);
    void write_wind_speed (QJsonObject json_object);
    void write_min_tempereture (QJsonObject json_object);
    void write_max_tempereture (QJsonObject json_object);
    void write_pressure (QJsonObject json_object);





};
#endif // MAINWINDOW_H
