#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJSEngine>
#include <QJSValue>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setFocusPolicy(Qt::StrongFocus);
    ui->lineEdit->setFocus();
    QVector<QString> a{"C", "=", "+/-"};
    for (auto* button : this->findChildren<QPushButton*>()) {
        // qDebug() << button->objectName() <<a.contains(button->objectName());
        if(!a.contains(button->text()))
            connect(button, &QPushButton::clicked, this, &MainWindow::on_Button_clicked);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_clicked() {

    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;


    ui->lineEdit->setText(ui->lineEdit->text() + (btn->text() == "x" ? "*":btn->text()));
    // Handle input based on text
    ui->lineEdit->setFocus();  // ensure cursor stays active
}

void MainWindow::on_pushButton_7_clicked() {
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();  // ensure cursor stays active

}

void MainWindow::on_pushButton_2_clicked() {
    QJSEngine engine;
    QString expr = ui->lineEdit->text();
    QJSValue result = engine.evaluate(expr);
    ui->lineEdit->setText(result.toString());
    ui->lineEdit->setFocus();  // ensure cursor stays active
}

void MainWindow::on_pushButton_clicked() {
    ui->lineEdit->backspace();
}
