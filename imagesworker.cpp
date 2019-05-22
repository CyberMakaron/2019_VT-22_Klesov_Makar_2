#include "imagesworker.h"

QString ImagesWorker::getNext(){
    cur_img_num = (cur_img_num + 1) % img_num;
    return images_list[cur_img_num];
}

QString ImagesWorker::getPrevious(){
    if (cur_img_num == 0) cur_img_num = img_num - 1;
    else cur_img_num = (cur_img_num - 1) % img_num;
    return images_list[cur_img_num];
}

QString ImagesWorker::getFirst(){
    cur_img_num = 0;
    return images_list[cur_img_num];
}

QStringList& ImagesWorker::imagesList(){
    return images_list;
}

int ImagesWorker::getImgNum(){
    return img_num;
}

int ImagesWorker::getCurImgNum(){
    return cur_img_num;
}

int& ImagesWorker::imgNum(){
    return img_num;
}

int& ImagesWorker::curImgNum(){
    return cur_img_num;
}

QString ImagesWorker::getCurrent(){
    return images_list[cur_img_num];
}
