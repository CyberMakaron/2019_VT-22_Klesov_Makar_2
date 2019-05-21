#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>                   /// убрать
#include <QMessageBox>
#include <scaledpixmap.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ImagesWorker im_w;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setImage(QString img){
    QPixmap pix(img);
    /*int w = ui->image_field->width();
    int h = ui->image_field->height();
    pix.scaled(w, h, Qt::KeepAspectRatio);
    ui->image_field->setPixmap(pix);*/
    ui->img_field->setScaledPixmap(pix);
    QString mes = img + " [" + QString::number(im_w.getCurrenrImgNum() + 1) + '/' + QString::number(im_w.getImgNum()) + ']';
    ui->statusBar->showMessage(mes);
}

void MainWindow::on_openFolder_triggered()
{
    QString img;
    im_w.openDirectory();
    if (im_w.getImgNum() == 0){
        QMessageBox::warning(this, "Внимание!", "Пустая папка!");
        return;
    }
    img = im_w.getNext();
    setImage(img);
}

void MainWindow::on_previous_img_clicked()
{
    QString img = im_w.getPrevious();
    setImage(img);
}
void MainWindow::on_next_img_clicked()
{
    QString img = im_w.getNext();
    setImage(img);
}
