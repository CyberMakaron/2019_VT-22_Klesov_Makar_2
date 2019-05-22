#include "shortcutworker.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

ShortcutWorker::ShortcutWorker() : ImagesWorker(), shortcut_file("shortcut_links.txt"), changes_flag(false){
    if(!shortcut_file.exists()){
        shortcut_file.open(QIODevice::WriteOnly);
        shortcut_file.close();
    }
    shortcut_file.open(QIODevice::ReadOnly);
    if (shortcut_file.size() > 0){
        QTextStream fin(&shortcut_file);
        QString line;
        while (true)
        {
            line = fin.readLine();
            if (line.isNull())
                break;
            else
                imagesList().append(line);
        }
    }
    shortcut_file.close();
    imgNum() = imagesList().size();
}

void ShortcutWorker::addLink(QString link){
    changes_flag = true;
    imagesList().append(link);
    imgNum()++;
}

void ShortcutWorker::removeCurLink(QString link){
    changes_flag = true;
    int k = imagesList().indexOf(link);
    if (k == -1) return;
    imagesList().removeAt(k);
    imgNum()--;
    if (imgNum() == 0) curImgNum() = -1;
    else curImgNum() = (curImgNum() % imgNum() + 1) % imgNum();
}

ShortcutWorker::~ShortcutWorker(){
    if (!changes_flag) return;
    shortcut_file.open(QIODevice::WriteOnly);
    QTextStream fout(&shortcut_file);
    for(int i = 0; i < imagesList().size(); i++)
        fout << imagesList()[i] << "\n";
    shortcut_file.close();
}
