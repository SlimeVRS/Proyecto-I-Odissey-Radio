#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{

    ui->setupUi(this);

    QObject *qmlAudio = nullptr;
    //player= new QMediaPlayer(this);
    player = qvariant_cast<QMediaPlayer *>(qmlAudio->property(""));
    //connect(player, &QMediaPlayer::positionChanged,this,&Dialog::cambioDuracion);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_playButton_clicked()
{
    //carga de archivo
    //player->
    //player->setMedia(QUrl::fromLocalFile("/Desktop/fma_small/000"));
}

void Dialog::on_pauseButton_clicked()
{

}

void Dialog::on_progressBar_sliderMoved(int position)
{

}

void Dialog::cambioDuracion(qint64 position)
{

}
