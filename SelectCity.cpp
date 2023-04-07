#include "SelectCity.h"
#include "ui_SelectCity.h"

SelectCity::SelectCity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectCity)
{
    ui->setupUi(this);
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

