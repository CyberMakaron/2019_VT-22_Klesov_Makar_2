#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPixmap>
#include "imagesworker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setImage(QString img);
    ~MainWindow();

private slots:
    void on_openFolder_triggered();

    void on_previous_img_clicked();

    void on_next_img_clicked();

private:
    Ui::MainWindow *ui;
    ImagesWorker im_w;
};

#endif // MAINWINDOW_H
