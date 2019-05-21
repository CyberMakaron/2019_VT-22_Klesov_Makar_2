#ifndef IMAGESWORKER_H
#define IMAGESWORKER_H

#include <QString>
#include <QDir>
#include <QFileDialog>

class ImagesWorker
{
    QString path;
    QStringList images_list;
    int cur_img_num, img_num;
public:
    ImagesWorker(): path(), images_list(), cur_img_num(-1), img_num(0){}
    void openDirectory();

    int getImgNum();
    int getCurrenrImgNum();
    QString getNext();
    QString getPrevious();
};

#endif // IMAGESWORKER_H
