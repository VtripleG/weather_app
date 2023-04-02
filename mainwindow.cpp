#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onResult(QNetworkReply *reply)
{

    b_font.setPointSize(100);
    b_font.setFamily("Ubuntu");
    b_font.setBold(true);
    l_font = b_font;
    h_font = b_font;
    h_font.setPointSize(13);
    l_font.setPointSize(17);

    QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
    QJsonObject json_object = document.object();
    ui->textBrowser->clear();
    ui->textBrowser->setAlignment(Qt::AlignCenter);
    //city name
    write_city_name(json_object);
    //weather
    write_weather(json_object);
    //tempereture now
    write_n_tempereture(json_object);
    //feels like tempereture
    write_fl_tempereture(json_object);
    //wind speed
    write_wind_speed(json_object);
    //min tempereture
    write_min_tempereture(json_object);
    //max tempereture
    write_max_tempereture(json_object);
    //pressure
    write_pressure(json_object);


}

void MainWindow::on_pushButton_clicked()
{
    networkManger = new QNetworkAccessManager();
    connect(networkManger, &QNetworkAccessManager::finished, this, &MainWindow::onResult);
    networkManger->get(QNetworkRequest(QUrl("https://api.openweathermap.org/data/2.5/weather?q=Murmansk&units=metric&appid=918897e4f3f23239a1b447c8dd3be48a")));

}



void MainWindow::write_city_name(QJsonObject json_object)
{
    ui->textBrowser->setCurrentFont(h_font);
    ui->textBrowser->insertPlainText(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss") + "\n");
    ui->textBrowser->insertPlainText("City: " + json_object["name"].toString() + "\n");

}

void MainWindow::write_weather(QJsonObject json_object)
{
    QJsonArray weather_array = json_object["weather"].toArray();
    qDebug() << weather_array;
    QVariantMap weather_map;
    for (const QJsonValue   &weather_value : weather_array)
    {
        QJsonObject object = weather_value.toObject();
        weather_map.insert(object.toVariantMap());
    }

    set_image_background(weather_map["main"].toString());
}

void MainWindow::write_n_tempereture(QJsonObject json_object)
{
    v_map = json_object["main"].toObject().toVariantMap();
    buff = floor(v_map["temp"].toDouble());
    buff_object->insert("temp",buff);
    v_map = buff_object->toVariantMap();

     ui->textBrowser->setCurrentFont(b_font);
     ui->textBrowser->insertPlainText(v_map["temp"].toString());
     ui->textBrowser->setCurrentFont(l_font);
     ui->textBrowser->insertPlainText(" ॰C\n");
     ui->textBrowser->setCurrentFont(h_font);
     ui->textBrowser->insertPlainText("Tempereture now\n\n" );


}

void MainWindow::write_fl_tempereture(QJsonObject json_object)
{
    v_map = json_object["main"].toObject().toVariantMap();
    buff = floor(v_map["feels_like"].toDouble());
    buff_object->insert("feels_like",buff);
    v_map = buff_object->toVariantMap();
    ui->textBrowser->setCurrentFont(b_font);
    ui->textBrowser->insertPlainText(v_map["feels_like"].toString());
    ui->textBrowser->setCurrentFont(l_font);
    ui->textBrowser->insertPlainText(" ॰C\n");
    ui->textBrowser->setCurrentFont(h_font);
    ui->textBrowser->insertPlainText("Tempereture feels like\n\n" );

}

void MainWindow::write_wind_speed(QJsonObject json_object)
{
    v_map = json_object["wind"].toObject().toVariantMap();
    buff = floor(v_map["speed"].toDouble());
    buff_object->insert("speed",buff);
    v_map = buff_object->toVariantMap();
    ui->textBrowser->setCurrentFont(b_font);
    ui->textBrowser->insertPlainText(v_map["speed"].toString());
    ui->textBrowser->setCurrentFont(l_font);
    ui->textBrowser->insertPlainText(" m/s\n");
    ui->textBrowser->setCurrentFont(h_font);
    ui->textBrowser->insertPlainText("Wind speed\n\n" );

}

void MainWindow::write_min_tempereture(QJsonObject json_object)
{
    v_map = json_object["main"].toObject().toVariantMap();
    buff = floor(v_map["temp_min"].toDouble());
    buff_object->insert("temp_min",buff);
    v_map = buff_object->toVariantMap();
    ui->textBrowser->setCurrentFont(b_font);
    ui->textBrowser->insertPlainText(v_map["temp_min"].toString());
    ui->textBrowser->setCurrentFont(l_font);
    ui->textBrowser->insertPlainText(" ॰C\n");
    ui->textBrowser->setCurrentFont(h_font);
    ui->textBrowser->insertPlainText("Minimum day tempereture\n\n" );

}

void MainWindow::write_max_tempereture(QJsonObject json_object)
{
    v_map = json_object["main"].toObject().toVariantMap();
    buff = floor(v_map["temp_max"].toDouble());
    buff_object->insert("temp_max",buff);
    v_map = buff_object->toVariantMap();
    ui->textBrowser->setCurrentFont(b_font);
    ui->textBrowser->insertPlainText(v_map["temp_max"].toString());
    ui->textBrowser->setCurrentFont(l_font);
    ui->textBrowser->insertPlainText(" ॰C\n");
    ui->textBrowser->setCurrentFont(h_font);
    ui->textBrowser->insertPlainText("Maximum day tempereture\n\n" );
}

void MainWindow::write_pressure(QJsonObject json_object)
{
    v_map = json_object["main"].toObject().toVariantMap();
    buff = floor(v_map["pressure"].toDouble()/1.33);
    buff_object->insert("pressure",buff);
    v_map = buff_object->toVariantMap();
    ui->textBrowser->setCurrentFont(b_font);
    ui->textBrowser->insertPlainText(v_map["pressure"].toString());
    ui->textBrowser->setCurrentFont(l_font);
    ui->textBrowser->insertPlainText(" mm\n");
    ui->textBrowser->setCurrentFont(h_font);
    ui->textBrowser->insertPlainText("ATM pressure\n\n" );
}

void MainWindow::set_image_background(QString bkgr)
{
    QString string;
    if (bkgr=="Clouds")
       string = "../weather_app/Clouds.png";
    else if (bkgr=="Rain")
       string = "../weather_app/Rain.png";
    else if (bkgr == "Clear")
       string = "../weather_app/Clear.png";
    else if (bkgr == "Snow")
       string = "../weather_app/Snow.png";
//    QPixmap bkgnd("../weather_app/rain.png");
    QPixmap bkgrnd(string);
    bkgrnd = bkgrnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette();
    p.setBrush(QPalette::Window, bkgrnd);
    ui->centralwidget->setPalette(p);
}

