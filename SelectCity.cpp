#include "SelectCity.h"
#include "ui_SelectCity.h"
#include <QDebug>

SelectCity::SelectCity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectCity)
{
    ui->setupUi(this);
}

void SelectCity::keyPressEvent(QKeyEvent *event)
{
    if((ui->lineEdit->hasFocus()==true) && (event->key() == Qt::Key_Return))
        on_pushButton_clicked();
}


SelectCity::~SelectCity()
{
    delete ui;
}

void SelectCity::on_pushButton_clicked()
{
    emit(new_city(ui->lineEdit->text()));
    ui->lineEdit->clear();
    this->close();
}

