#include "FontResizableLineEdit.h"

FontResizableLineEdit::FontResizableLineEdit(QWidget *parent)
    : QLineEdit(parent)
{

}

void FontResizableLineEdit::resizeEvent(QResizeEvent *event)
{
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
