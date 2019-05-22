#ifndef IMAGESWORKER_H
#define IMAGESWORKER_H

#include <QString>
#include <QDir>

class ImagesWorker {
    QStringList images_list;
    int cur_img_num, img_num;
public:
    ImagesWorker() : images_list(), cur_img_num(-1), img_num(0) {}
    int getImgNum();
    int getCurImgNum();
    int& imgNum();
    int& curImgNum();
    QStringList& imagesList();
    QString getNext();
    QString getPrevious();
    QString getFirst();
    QString getCurrent();
};

#endif // IMAGESWORKER_H
