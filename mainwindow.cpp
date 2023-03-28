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
    QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
//    qDebug()<< document;
    QJsonObject json_object = document.object();
    ui->textBrowser->insertPlainText("City: " + json_object["name"].toString() + "\n" );
    QVariantMap v_map = json_object["wind"].toObject().toVariantMap();
    ui->textBrowser->insertPlainText("Wind speed:  " + v_map["speed"].toString() + "\n" );

}


void MainWindow::on_pushButton_clicked()
{
    networkManger = new QNetworkAccessManager();
    connect(networkManger, &QNetworkAccessManager::finished, this, &MainWindow::onResult);
    networkManger->get(QNetworkRequest(QUrl("https://api.openweathermap.org/data/2.5/weather?q=London&units=metric&appid=918897e4f3f23239a1b447c8dd3be48a")));

}

