#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QtDebug>
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    void add_song(QString ID,QString nombre,QString Artista,QString Album,QString Genero,QString largo);


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void play_song(QString ID);

    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void on_pagButton_clicked();

    void on_progress_sliderMoved(int position);

    void on_progress_changed(qint64 position);

    void on_informacion_doubleClicked(const QModelIndex &index);

    void on_informacion_itemDoubleClicked(QTreeWidgetItem *item, int column);



    void on_loadButton_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;

};
#endif // MAINWINDOW_H
