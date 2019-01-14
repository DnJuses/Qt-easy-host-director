#ifndef MAGNETICWIDGET_H
#define MAGNETICWIDGET_H

#include <QWidget>

class MagneticWidget : public QWidget
{
    Q_OBJECT
public:
    MagneticWidget(const QWidget *magnetToWidget);
    ~MagneticWidget() override;
    bool isMagnetic() const;
protected:
    void moveEvent(QMoveEvent *event) override;

private:
    const QWidget *magnetizedWidget;
    bool magnet;
};

#endif // MAGNETICWIDGET_H
