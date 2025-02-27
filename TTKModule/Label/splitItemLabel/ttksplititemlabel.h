#ifndef TTKSPLITITEMLABEL_H
#define TTKSPLITITEMLABEL_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2025 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include <QLabel>
#include "ttkmoduleexport.h"

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKSplitItemLabel : public QLabel
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKSplitItemLabel)
public:
    explicit TTKSplitItemLabel(QWidget *parent = nullptr);

    void setSplitString(const QString &str);

Q_SIGNALS:
    void changed(const QString &value);

private:
    virtual void enterEvent(QtEnterEvent *event) override final;
    virtual void leaveEvent(QEvent *event) override final;
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void mouseMoveEvent(QMouseEvent *event) override final;
    virtual void paintEvent(QPaintEvent *event) override final;

    QRectF m_lineGeometry;
    QString m_splitString, m_currentString;

};

#endif // TTKSPLITITEMLABEL_H
