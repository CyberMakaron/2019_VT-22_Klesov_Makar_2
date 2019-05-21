#include "scaledpixmap.h"
#include <QPainter>

void ScaledPixmap::setScaledPixmap(const QPixmap &pixmap){
    p_map = pixmap;
    update();
}

void ScaledPixmap::paintEvent(QPaintEvent *event){
    QPainter p(this);
    if(!p_map.isNull()){
        QSize widget_size = size();
        QPixmap scaledPixmap = p_map.scaled(widget_size, Qt::KeepAspectRatio);
        QPoint center((widget_size.width() - scaledPixmap.width())/2, (widget_size.height() - scaledPixmap.height())/2);
        p.drawPixmap(center, scaledPixmap);
    }
    QWidget::paintEvent(event);
}

QSize ScaledPixmap::sizeHint() const{
    return p_map.size();
}
