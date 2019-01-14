#include "MagneticWidget.h"
#include <QtEvents>

#define LEFT_EDGE 16
#define RIGHT_EDGE 19
#define SEPARATOR 16
#define TITLE_HEIGHT 38
#define DOWN_EDGE 3
#define UPPER_EDGE 0

MagneticWidget::MagneticWidget(const QWidget *magnetToWidget) :
    magnetizedWidget(magnetToWidget),
    magnet(false)
{

}

MagneticWidget::~MagneticWidget()
{
    this->deleteLater();
}

bool MagneticWidget::isMagnetic() const
{
    return magnet;
}

void MagneticWidget::moveEvent(QMoveEvent *event)
{
    // Magnet to right-top edge;
    if(((magnetizedWidget->x() + magnetizedWidget->width()) - this->x() <= -LEFT_EDGE && (magnetizedWidget->x() + magnetizedWidget->width()) - this->x() >= -RIGHT_EDGE) && (magnetizedWidget->y() - this->y() >= -7 && magnetizedWidget->y() - this->y() <= 4))
    {
        this->move(magnetizedWidget->x() + magnetizedWidget->width() + SEPARATOR, magnetizedWidget->y());
    }
    // Magnet to right-bottom edge;
    else if(((magnetizedWidget->x() + magnetizedWidget->width()) - this->x() <= -LEFT_EDGE && (magnetizedWidget->x() + magnetizedWidget->width()) - this->x() >= -RIGHT_EDGE) && ((magnetizedWidget->y() + magnetizedWidget->height()) - (this->y() + this->height()) >= -7 && ((magnetizedWidget->y() + magnetizedWidget->height()) - (this->y() + this->height()) <= 4)))
    {
        this->move(magnetizedWidget->x() + magnetizedWidget->width() + SEPARATOR, magnetizedWidget->y() + magnetizedWidget->height() - this->height());
    }
    // Magnet to right edge;
    else if(((magnetizedWidget->x() + magnetizedWidget->width()) - this->x() <= -LEFT_EDGE && (magnetizedWidget->x() + magnetizedWidget->width()) - this->x() >= -RIGHT_EDGE) && ((this->y() + this->height()) >= (magnetizedWidget->y() - TITLE_HEIGHT) && this->y() <= (magnetizedWidget->y() + magnetizedWidget->height() + TITLE_HEIGHT)))
    {
        this->move(magnetizedWidget->x() + magnetizedWidget->width() + SEPARATOR, this->y());
    }
    // Magnet to left-top edge;
    else if((magnetizedWidget->x() - (this->x() + this->width()) >= LEFT_EDGE && magnetizedWidget->x() - (this->x() + this->width()) <= RIGHT_EDGE) && (magnetizedWidget->y() - this->y() >= -7 && magnetizedWidget->y() - this->y() <= 4))
    {
        this->move(magnetizedWidget->x() - this->width() - SEPARATOR, magnetizedWidget->y());
    }
    // Magnet to left-bottom edge;
    else if((magnetizedWidget->x() - (this->x() + this->width()) >= LEFT_EDGE && magnetizedWidget->x() - (this->x() + this->width()) <= RIGHT_EDGE) && ((magnetizedWidget->y() + magnetizedWidget->height()) - (this->y() + this->height()) >= -7 && ((magnetizedWidget->y() + magnetizedWidget->height()) - (this->y() + this->height()) <= 4)))
    {
        this->move(magnetizedWidget->x() - this->width() - SEPARATOR, magnetizedWidget->y() + magnetizedWidget->height() - this->height());
    }
    // Magnet to left edge;
    else if(magnetizedWidget->x() - (this->x() + this->width()) >= LEFT_EDGE && magnetizedWidget->x() - (this->x() + this->width()) <= RIGHT_EDGE && ((this->y() + this->height()) >= (magnetizedWidget->y() - TITLE_HEIGHT) && this->y() <= (magnetizedWidget->y() + magnetizedWidget->height() + TITLE_HEIGHT)))
    {
        this->move(magnetizedWidget->x() - this->width() - SEPARATOR, this->y());
    }
    // Magnet to bottom-right edge;
    else if(((magnetizedWidget->y() + magnetizedWidget->height()) - this->y() + TITLE_HEIGHT <= -UPPER_EDGE && (magnetizedWidget->y() + magnetizedWidget->height()) - this->y() + TITLE_HEIGHT >= -DOWN_EDGE) && ((magnetizedWidget->x() + magnetizedWidget->width() + SEPARATOR) - (this->x() + this->width()) >= LEFT_EDGE && (magnetizedWidget->x() + magnetizedWidget->width() + SEPARATOR) - (this->x() + this->width()) <= RIGHT_EDGE))
    {
        this->move(magnetizedWidget->x() + magnetizedWidget->width() - this->width(), magnetizedWidget->y() + magnetizedWidget->height() + TITLE_HEIGHT);
    }
    // Magnet to bottom-left edge;
    else if(((magnetizedWidget->y() + magnetizedWidget->height()) - this->y() + TITLE_HEIGHT <= -UPPER_EDGE && (magnetizedWidget->y() + magnetizedWidget->height()) - this->y() + TITLE_HEIGHT >= -DOWN_EDGE) && (magnetizedWidget->x() - SEPARATOR - this->x() <= -LEFT_EDGE && magnetizedWidget->x() - SEPARATOR - this->x() >= -RIGHT_EDGE))
    {
        this->move(magnetizedWidget->x(), magnetizedWidget->y() + magnetizedWidget->height() + TITLE_HEIGHT);
    }
    // Magnet to bottom edge;
    else if(((magnetizedWidget->y() + magnetizedWidget->height()) - this->y() + TITLE_HEIGHT <= -UPPER_EDGE && (magnetizedWidget->y() + magnetizedWidget->height()) - this->y() + TITLE_HEIGHT >= -DOWN_EDGE) && ((this->x() + this->width()) >= magnetizedWidget->x() - SEPARATOR && this->x() <= magnetizedWidget->x() + magnetizedWidget->width() + SEPARATOR))
    {
        this->move(this->x(), magnetizedWidget->y() + magnetizedWidget->height() + TITLE_HEIGHT);
    }
    // Magnet to top-right edge;
    else if(((magnetizedWidget->y() - TITLE_HEIGHT) - (this->y() + this->height()) >= UPPER_EDGE && (magnetizedWidget->y() - TITLE_HEIGHT) - (this->y() + this->height()) <= DOWN_EDGE) && ((magnetizedWidget->x() + magnetizedWidget->width() + SEPARATOR) - (this->x() + this->width()) >= LEFT_EDGE && (magnetizedWidget->x() + magnetizedWidget->width() + SEPARATOR) - (this->x() + this->width()) <= RIGHT_EDGE))
    {
        this->move(magnetizedWidget->x() + magnetizedWidget->width() - this->width(), magnetizedWidget->y() - this->height() - TITLE_HEIGHT);
    }
    // Magnet to top-left edge;
    else if(((magnetizedWidget->y() - TITLE_HEIGHT) - (this->y() + this->height()) >= UPPER_EDGE && (magnetizedWidget->y() - TITLE_HEIGHT) - (this->y() + this->height()) <= DOWN_EDGE) && (magnetizedWidget->x() - SEPARATOR - this->x() <= -LEFT_EDGE && magnetizedWidget->x() - SEPARATOR - this->x() >= -RIGHT_EDGE))
    {
        this->move(magnetizedWidget->x(), magnetizedWidget->y() - this->height() - TITLE_HEIGHT);
    }
    // Magnet to top edge;
    else if(((magnetizedWidget->y() - TITLE_HEIGHT) - (this->y() + this->height()) >= UPPER_EDGE && (magnetizedWidget->y() - TITLE_HEIGHT) - (this->y() + this->height()) <= DOWN_EDGE) && ((this->x() + this->width()) >= magnetizedWidget->x() - SEPARATOR && this->x() <= magnetizedWidget->x() + magnetizedWidget->width() + SEPARATOR))
    {
        this->move(this->x(), magnetizedWidget->y() - this->height() - TITLE_HEIGHT);
    }
    // No magnet available;
    else
    {
        magnet = false;
        return;
    }
    // If already magnetized - ignore move event to prevent widget shaking;
    if(magnet)
    {
        event->ignore();
    }
    magnet = true;
}
