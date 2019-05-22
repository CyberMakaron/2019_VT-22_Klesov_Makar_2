#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPixmap>
#include "dir_imagesworker.h"
#include "shortcutworker.h"

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

    void on_addShortcut_triggered();

    void on_Shortcut_triggered();

    void on_removeShortcut_triggered();

private:
    Ui::MainWindow *ui;
    DirImagesWorker dir_img_w;
    ShortcutWorker shortcut_w;
    int mode;
};

#endif // MAINWINDOW_H
