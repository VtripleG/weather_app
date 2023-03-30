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

void MainWindow::set_image_background()
{
    QPixmap bkgnd("../weather_app/rain.png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette();
    p.setBrush(QPalette::Window, bkgnd);
    ui->centralwidget->setPalette(p);
}

void MainWindow::onResult(QNetworkReply *reply)
{
    QFont b_font;
    QFont l_font;
    QFont h_font;
    b_font.setPointSize(100);
    b_font.setFamily("Ubuntu");
    b_font.setBold(true);
    l_font = b_font;
    h_font = b_font;
    h_font.setPointSize(13);
    l_font.setPointSize(17);
    QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
//    qDebug()<< document;
    QJsonObject json_object = document.object();
    ui->textBrowser->clear();
    ui->textBrowser->setAlignment(Qt::AlignCenter);


    //city name
    ui->textBrowser->setCurrentFont(h_font);
    ui->textBrowser->insertPlainText(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss") + "\n");
    ui->textBrowser->insertPlainText("City: " + json_object["name"].toString() + "\n");

    //weather


    QVariantMap v_map;
    //tempereture now
    v_map = json_object["main"].toObject().toVariantMap();
    int buff;
    buff = floor(v_map["temp"].toDouble());
    QJsonObject *buff_object = new QJsonObject;
    buff_object->insert("temp",buff);
    v_map = buff_object->toVariantMap();

     ui->textBrowser->setCurrentFont(b_font);
     ui->textBrowser->insertPlainText(v_map["temp"].toString());
     ui->textBrowser->setCurrentFont(l_font);
     ui->textBrowser->insertPlainText(" ॰C\n");
     ui->textBrowser->setCurrentFont(h_font);
     ui->textBrowser->insertPlainText("Tempereture now\n\n" );
     //feels like tempereture
     v_map = json_object["main"].toObject().toVariantMap();

     buff = floor(v_map["feel_like"].toDouble());
     buff_object->insert("feels_like",buff);
     v_map = buff_object->toVariantMap();

     ui->textBrowser->setCurrentFont(b_font);
     ui->textBrowser->insertPlainText(v_map["feels_like"].toString());
     ui->textBrowser->setCurrentFont(l_font);
     ui->textBrowser->insertPlainText(" ॰C\n");
     ui->textBrowser->setCurrentFont(h_font);
     ui->textBrowser->insertPlainText("Tempereture feels like\n\n" );


    //wind speed
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
    //tempereture bloc


    //min tempereture
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

    //max tempereture
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

    //pressure
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

    set_image_background();



}


void MainWindow::on_pushButton_clicked()
{
    networkManger = new QNetworkAccessManager();
    connect(networkManger, &QNetworkAccessManager::finished, this, &MainWindow::onResult);
    networkManger->get(QNetworkRequest(QUrl("https://api.openweathermap.org/data/2.5/weather?q=Voronezh&units=metric&appid=918897e4f3f23239a1b447c8dd3be48a")));

}

