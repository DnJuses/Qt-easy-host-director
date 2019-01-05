#include "TimerLineEdit.h"
#include "HostDirectorFileWriter.h"
#include <QTimer>

#define TIMER_INTERVAL 1 * 1000

TimerLineEdit::TimerLineEdit(QWidget *parent)
    : QLineEdit(parent),
      hours(0),
      minutes(0),
      seconds(0),
      fileWriter(new HostDirectorFileWriter(this))
{

}

TimerLineEdit::~TimerLineEdit()
{
    this->deleteLater();
}

void TimerLineEdit::startTimer(quint8 h, quint8 m, quint8 s)
{
    hours = h;
    minutes = m;
    seconds = s;
    this->setDisplayedTimerValues(hours, minutes, seconds);
    QTimer::singleShot(TIMER_INTERVAL, this, &TimerLineEdit::updateTimer);
}

void TimerLineEdit::stopTimer()
{
    this->setDisplayedTimerValues(0, 0, 0);
    emit timerStopped();
}

void TimerLineEdit::updateTimer()
{
    if(minutes == 0 && seconds == 0 && hours != 0)
    {
        minutes = 60;
        hours--;
    }
    if(seconds == 0 && minutes != 0)
    {
        seconds = 60;
        minutes--;
    }
    if(seconds == 0 && minutes == 0 && hours == 0)
    {
        this->stopTimer();
        return;
    }
    seconds--;
    this->setDisplayedTimerValues(hours, minutes, seconds);
    QTimer::singleShot(TIMER_INTERVAL, this, &TimerLineEdit::updateTimer);
}

void TimerLineEdit::setDisplayedTimerValues(quint8 h, quint8 m, quint8 s)
{
    this->setText(QString::number(h / 10)
                + QString::number(h % 10)
                + ":"
                + QString::number(m / 10)
                + QString::number(m % 10)
                + ":"
                + QString::number(s / 10)
                + QString::number(s % 10)
                );
}

void TimerLineEdit::resizeEvent(QResizeEvent *event)
{
    // Font resizing that depends on widget's size
    QFont font = this->font();
    QFontMetrics fontMetrics(font);
    qint32 fontWidth = fontMetrics.width(this->text());
    qint32 fontHeight = fontMetrics.height();
    while(fontWidth < this->width() - 3 && fontHeight < this->height())
    {
        font.setPointSize(font.pointSize() + 1);
        QFontMetrics tm(font);
        fontWidth = tm.width(this->text());
        fontHeight = tm.height();
    }
    while(fontWidth > this->width() - 3 || fontHeight > this->height())
    {
        font.setPointSize(font.pointSize() - 1);
        QFontMetrics tm(font);
        fontWidth = tm.width(this->text());
        fontHeight = tm.height();
    }
    this->setFont(font);
}
