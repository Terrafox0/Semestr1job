#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <thread>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QDir>
int number = 1;
QString info[15][4];
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::refresh()
{
    QString numberst=QString::number(number);
    ui->info->setText("Номер товара -> "+numberst+"\nТовар -> "+info[number][0]+"\nИмя -> "+info[number][1]+"\nКоличество -> "+info[number][2]+"\nЦена ->"+info[number][3]);
    ui->name->setText("");
    ui->type->setText("");
    ui->num->setValue(0);
    ui->price->setValue(0);

}
MainWindow::~MainWindow()
{

    QString n;
    QString m;

    delete ui;
}


void MainWindow::on_new_2_clicked()
{
    info[number][0] = ui->name->toPlainText();
    info[number][1] = ui->type->toPlainText();
    info[number][2] = ui->num->text();
    info[number][3] = ui->price->text();
    refresh();
}












void MainWindow::on_past_clicked()
{
    if (number>1) {number--; refresh();}
    else {ui->info->setText("Начало корзины"); number=0;}

}

void MainWindow::on_next_clicked()
{
    number++;
    refresh();
}



void MainWindow::on_delete_2_clicked()
{
    info[number][0] = NULL;
    info[number][1] = NULL;
    info[number][2] = NULL;
    info[number][3] = NULL;
    refresh();
}

void MainWindow::on_pushButton_clicked()
{
    for (int i=1;i<15;i++)
    for (int j=0;j<5;j++)
    info[i][j] = NULL;
    refresh();
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile save_file("test");
    save_file.open(QIODevice::ReadWrite | QIODevice::Text);

    for (int i=1;i<15;i++){
    for (int j=0;j<5;j++){
        QString save_text = info[i][j];//сохранение измененного текста
        QTextStream out(&save_file);
        out<<save_text+" ";



    }}
    save_file.close();
    refresh();
}

void MainWindow::on_pushButton_3_clicked()
{
    QFile save_file("test");
    save_file.open(QIODevice::ReadWrite | QIODevice::Text);
    for (int i=1;i<15;i++){
    for (int j=0;j<5;j++){
        QString save_text;
      QTextStream in(&save_file);
      in>>info[i][j];
    }}
    refresh();

    }

