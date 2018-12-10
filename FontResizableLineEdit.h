#ifndef FONTRESIZABLELINEEDIT_H
#define FONTRESIZABLELINEEDIT_H

#include <QLineEdit>
#include <QToolButton>

class FontResizableLineEdit : public QLineEdit
{
public:
    explicit FontResizableLineEdit(QWidget *parent = nullptr);
protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // FONTRESIZABLELINEEDIT_H
