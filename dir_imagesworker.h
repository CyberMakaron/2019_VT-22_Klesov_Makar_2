#ifndef DIRIMAGESWORKER_H
#define DIRIMAGESWORKER_H

#include <QFileDialog>
#include "imagesworker.h"

class DirImagesWorker : public ImagesWorker{
    QString path;
public:
    DirImagesWorker(): ImagesWorker(), path() {}
    void openDirectory();
    QString getPrevious();
    QString getNext();
    QString getCurrent();
    QString getFirst();
};

#endif // DIRIMAGESWORKER_H
