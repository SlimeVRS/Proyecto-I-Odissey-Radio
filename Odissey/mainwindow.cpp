#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <QDebug>
#include "../ListCreator.h"
#include "../tracks.cpp"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);

    connect(player, &QMediaPlayer::positionChanged,this, &MainWindow::on_progress_changed);
    //ui->treeWidget->setColumnCount(2);
    //add_song("000002","Maradona es mas grande que pele","Mama", "world","POP","1:35");
    //add_song("Malpino", "pele","20","10");
    //add_song("Holis", "papa","20","10");
    //add_song("Estoy mamadisimo ", "mama","20","10");
    //add_song("probando", "tata ","20","10");
    //add_song("oh yeah", "papa","20","10");
    //add_song("si pa", "holi","20","10");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_song(QString id,QString nombre,QString Artista,QString Album,QString Genero,QString largo){
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->informacion);
    item->setText(0,id);
    item->setText(1,nombre);
    item->setText(2,Artista);
    item->setText(3,Album);
    item->setText(4,Genero);
    item->setText(5,largo);
    //ui->informacion->clear();
    //QString oli = ui->informacion[0].textElideMode();


}
void MainWindow::add_art(QString art){
    QTreeWidgetItem *item= new QTreeWidgetItem(ui->treeWidget);
    item->setText(0,art);

}

void MainWindow::play_song(QString ID){

    QString carpeta=ID;
    QString path=QDir::homePath();
    path+="/fma_small/";
    path+=carpeta.remove(3,5);
    path+="/"+ID+".mp3";
    player->setMedia(QUrl::fromLocalFile(path));
    player->play();
    //ui->statusbar->showMessage(path);
    qDebug() << player-> errorString();

}

void MainWindow::on_playButton_clicked()
{
    player->play();
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

    ui->statusbar->showMessage("Now playing: "+ item->text(1)+",  "+item->text(2)+", "+item->text(3));

    //cargar archivo
    play_song(item->text(0));



}

void MainWindow::on_loadButton_clicked()
{
   LinkedList<Track> *list=readSmallMetadata();
   NodeLL<Track> *cancion=list->getFirst();

   while(cancion!=nullptr){
       Track *track=cancion->getData();
        add_song(QString::fromStdString(track->getTrackID()),QString::fromStdString(track->getTitle()),QString::fromStdString(track->getArtist()),
                 QString::fromStdString(track->getAlbum()),QString::fromStdString(track->getGenre()).remove(0,15),QString::fromStdString(track->getLenght()));
        cancion=cancion->getNext();
   }
   //ArtistListRecursive(list);
   LinkedList<Track> *artistas= ArtistListRecursive(list);
   NodeLL<Track> *artista=artistas->getFirst();

   while(artista!=nullptr){
       Track *trac=artista->getData();
       add_art(QString::fromStdString(trac->getArtist()));
       artista=artista->getNext();
   }

}
