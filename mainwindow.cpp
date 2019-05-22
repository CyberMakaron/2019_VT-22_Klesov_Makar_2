#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>                   /// убрать
#include <QMessageBox>
#include <scaledpixmap.h>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DirImagesWorker dir_img_w;
    ShortcutWorker shortcut_w;
    mode = -1;
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setImage(QString img){
    QPixmap pix(img);
    ui->img_field->setScaledPixmap(pix);
    QString mes = img;
    switch (mode){
    case 1: mes = mes + " [" + QString::number(dir_img_w.getCurImgNum() + 1) + '/' + QString::number(dir_img_w.getImgNum()) + ']'; break;
    case 2: mes = mes + " [" + QString::number(shortcut_w.getCurImgNum() + 1) + '/' + QString::number(shortcut_w.getImgNum()) + ']';
    }
    ui->statusBar->showMessage(mes);
}

void MainWindow::on_openFolder_triggered(){
    mode = 1;
    QString img;
    dir_img_w.openDirectory();
    if (dir_img_w.getImgNum() == 0){
        QMessageBox::warning(this, "Внимание!", "Пустая папка!");
        return;
    }
    img = dir_img_w.getFirst();
    setImage(img);
}

void MainWindow::on_previous_img_clicked(){
    QString img;
    switch (mode){
    case 1: if (dir_img_w.getImgNum() != 0) img = dir_img_w.getPrevious(); break;
    case 2: if (shortcut_w.getImgNum() != 0) img = shortcut_w.getPrevious();
    }
    setImage(img);
}

void MainWindow::on_next_img_clicked(){
    QString img;
    switch (mode){
    case 1: if (dir_img_w.getImgNum() != 0) img = dir_img_w.getNext(); break;
    case 2: if (shortcut_w.getImgNum() != 0) img = shortcut_w.getNext();
    }
    setImage(img);
}

void MainWindow::on_addShortcut_triggered(){
    if (mode == 1){
    if (shortcut_w.imagesList().indexOf(dir_img_w.getCurrent()) == -1)
        shortcut_w.addLink(dir_img_w.getCurrent());
    else {
        QMessageBox::information(this, "Сообщение", "Этот файл уже добавлен!");
    }
    }
}

void MainWindow::on_Shortcut_triggered()
{
    mode = 2;
    QString img;
    if (shortcut_w.imgNum() == 0){
        QMessageBox::warning(this, "Внимание!", "Пустая папка!");
        return;
    }
    img = shortcut_w.getFirst();
    setImage(img);
}

void MainWindow::on_removeShortcut_triggered()
{
    if (shortcut_w.imgNum() == 0){
        QMessageBox::warning(this, "Внимание!", "Пустая папка!");
        return;
    }
    switch (mode){
    case 1: if (shortcut_w.imagesList().indexOf(dir_img_w.getCurrent()) == -1)
            QMessageBox::information(this, "Сообщение", "Этого файла не было в быстром доступе!");
        shortcut_w.removeCurLink(dir_img_w.getCurrent()); break;
    case 2: if (shortcut_w.imagesList().indexOf(shortcut_w.getCurrent()) == -1)
            QMessageBox::information(this, "Сообщение", "Этого файла не было в быстром доступе!");
        shortcut_w.removeCurLink(shortcut_w.getCurrent());
    }
    if (shortcut_w.getImgNum() != 0) setImage(shortcut_w.getCurrent());
}
