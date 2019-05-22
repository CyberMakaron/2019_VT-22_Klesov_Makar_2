#include "dir_imagesworker.h"

void DirImagesWorker::openDirectory(){
    path = QFileDialog::getExistingDirectory(nullptr, "Выбор папки", "");
    QDir dir(path);
    QStringList filterList;
    filterList << "*.jpg" << "*.bmp" << "*.png";
    dir.setNameFilters(filterList);
    imagesList() = dir.entryList(QDir::Files);
    curImgNum() = -1;
    imgNum() = imagesList().size();
}

QString DirImagesWorker::getPrevious(){
    if (curImgNum() == 0) curImgNum() = imgNum() - 1;
    else curImgNum() = (curImgNum() - 1) % imgNum();
    return path + '/' + imagesList()[curImgNum()];
}

QString DirImagesWorker::getNext(){
    curImgNum() = (curImgNum() + 1) % imgNum();
    return path + '/' + imagesList()[curImgNum()];
}

QString DirImagesWorker::getCurrent(){
    return path + '/' + imagesList()[curImgNum()];
}

QString DirImagesWorker::getFirst(){
    curImgNum() = 0;
    return path + '/' + imagesList()[curImgNum()];
}

