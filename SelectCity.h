#ifndef SELECTCITY_H
#define SELECTCITY_H
#include <QKeyEvent>
#include <QWidget>

namespace Ui {
class SelectCity;
}

class SelectCity : public QWidget
{
    Q_OBJECT

public:
    explicit SelectCity(QWidget *parent = nullptr);
    void keyPressEvent (QKeyEvent* event);

    ~SelectCity();

private:
    Ui::SelectCity *ui;

signals:
    void new_city(QString city_name);
private slots:
    void on_pushButton_clicked();
};

#endif // SELECTCITY_H
