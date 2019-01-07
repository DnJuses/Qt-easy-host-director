#ifndef FONTRESIZABLELINEEDIT_H
#define FONTRESIZABLELINEEDIT_H

#include <QLineEdit>
#include "HostDirectorFileWriter.h"

class TimerLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit TimerLineEdit(QWidget *parent = nullptr);
    ~TimerLineEdit();
public slots:
    void startTimer(quint8 hours, quint8 minutes, quint8 seconds);
    void stopTimer();
private slots:
    void updateTimer();
private:
    quint8 hours;
    quint8 minutes;
    quint8 seconds;
    HostDirectorFileWriter *fileWriter;
    void setDisplayedTimerValues(quint8 hours, quint8 minutes, quint8 seconds);
signals:
    void timerStarted();
    void timerStopped();
protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // FONTRESIZABLELINEEDIT_H
