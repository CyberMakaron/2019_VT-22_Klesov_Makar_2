#include "imagesworker.h"

void ImagesWorker::openDirectory(){
    path = QFileDialog::getExistingDirectory(nullptr, "Выбор папки", "");
    QDir dir(path);
    QStringList filterList;
    filterList << "*.jpg" << "*.bmp" << "*.png";
    dir.setNameFilters(filterList);
    images_list = dir.entryList(QDir::Files);
    cur_img_num = -1;
    img_num = images_list.size();
}

QString ImagesWorker::getNext(){
    cur_img_num = (cur_img_num + 1) % img_num;
    return path + '/' + images_list[cur_img_num];
}

QString ImagesWorker::getPrevious(){
    if (cur_img_num == 0) cur_img_num = img_num - 1;
    else cur_img_num = (cur_img_num - 1) % img_num;
    return path + '/' + images_list[cur_img_num];
}

int ImagesWorker::getImgNum(){
    return img_num;
}

int ImagesWorker::getCurrenrImgNum(){
    return cur_img_num;
}
