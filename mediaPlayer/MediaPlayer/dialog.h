#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtMultimedia/QMultimedia>
#include <QtMultimedia/QMediaPlayer>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void on_progressBar_sliderMoved(int position);

    void cambioDuracion(qint64 position);

private:
    Ui::Dialog *ui;
    QMediaPlayer *player;

};
#endif // DIALOG_H
