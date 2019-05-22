#ifndef SHORTCUTWORKER_H
#define SHORTCUTWORKER_H

#include <QString>
#include <QStringList>
#include "imagesworker.h"

class ShortcutWorker : public ImagesWorker{
    QFile shortcut_file;
    bool changes_flag;
public:
    ShortcutWorker();
    void addLink(QString link);
    void removeCurLink(QString link);
    ~ShortcutWorker();
};

#endif // SHORTCUTWORKER_H
