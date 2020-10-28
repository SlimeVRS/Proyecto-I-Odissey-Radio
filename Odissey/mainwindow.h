#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QtDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void on_pagButton_clicked();

    void on_progress_sliderMoved(int position);

    void on_progress_changed(qint64 position);

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
};
#endif // MAINWINDOW_H
