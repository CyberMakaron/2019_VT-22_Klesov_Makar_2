#ifndef SCALEDPIXMAP_H
#define SCALEDPIXMAP_H
#include <QWidget>

class ScaledPixmap : public QWidget{
public:
    ScaledPixmap(QWidget *parent = nullptr) : QWidget(parent){}
    void setScaledPixmap(const QPixmap &pixmap);
    QSize sizeHint() const;
protected:
    void paintEvent(QPaintEvent *event);
private:
    QPixmap p_map;
};

#endif // SCALEDPIXMAP_H
