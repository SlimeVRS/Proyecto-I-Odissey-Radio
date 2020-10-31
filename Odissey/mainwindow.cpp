#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    connect(player, &QMediaPlayer::positionChanged,this, &MainWindow::on_progress_changed);
    //ui->treeWidget->setColumnCount(2);
    add_song("Maradona es mas grande que pele", "world","20","10");
    add_song("Malpino", "pele","20","10");
    add_song("Holis", "papa","20","10");
    add_song("Estoy mamadisimo ", "mama","20","10");
    add_song("probando", "tata ","20","10");
    add_song("oh yeah", "papa","20","10");
    add_song("si pa", "holi","20","10");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_song(QString nombre,QString Artista,QString largo,QString Genero){
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->informacion);
    item->setText(0,nombre);
    item->setText(1,Artista);
    item->setText(2,largo);
    item->setText(3,Genero);
    //ui->informacion->clear();
    //QString oli = ui->informacion[0].textElideMode();


}

void MainWindow::add_child(QTreeWidgetItem *parent,QString name){

}

void MainWindow::on_playButton_clicked()
{
    //cargar archivo
    player->setMedia(QUrl::fromLocalFile("/home/drump1/Desktop/Anuel AA - Keii [Official Video].mp3"));
    player->play();
    qDebug() << player-> errorString();
}

void MainWindow::on_pauseButton_clicked()
{
    player->pause();
}

void MainWindow::on_pagButton_clicked()
{

}

void MainWindow::on_progress_sliderMoved(int position)
{
    player->setPosition(position);
}

void MainWindow::on_progress_changed(qint64 position)
{
    ui->progress->setValue(position);
}

void MainWindow::on_informacion_doubleClicked(const QModelIndex &index)
{
   // QMessageBox::critical(this,"0",QString::informacion(index));

}

void MainWindow::on_informacion_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    QString str;
    str = item->text(0);
    str+=" ";
    str+= item->text(1);
    qDebug()<< str;
}
