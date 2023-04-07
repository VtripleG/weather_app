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
#include "SelectCity.h"



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

    void on_select_Button_clicked();


public slots:
    void new_city (QString city);

private:
    SelectCity *selectcity = new SelectCity;
    QFont b_font;
    QFont l_font;
    QFont h_font;
    int buff;
    QString url_path;
    QString f_p_url = ("https://api.openweathermap.org/data/2.5/weather?q=");
    QString t_p_url = ("&units=metric&appid=918897e4f3f23239a1b447c8dd3be48a");
    QString def_city = "Voronezh";
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
    void URL_request();





};
#endif // MAINWINDOW_H
