#ifndef TTKTILEBACKGROUNDLABEL_H
#define TTKTILEBACKGROUNDLABEL_H

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

#include <QWidget>
#include "ttkmoduleexport.h"

/*!
* @author Greedysky <greedysky@163.com>
*         feiyangqingyun <feiyangqingyun@163.com>
*/
class TTK_MODULE_EXPORT TTKTileBackgroundLabel : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKTileBackgroundLabel)
public:
    explicit TTKTileBackgroundLabel(QWidget *parent = nullptr);

    void setForegroundColor(const QColor &foregroundColor);
    void setBackgroundColor(const QColor &backgroundColor);
    void setBackgroundPixmap(const QPixmap &pix);

    virtual QSize sizeHint() const override final;

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    void drawBackground();

    QColor m_foregroundColor;
    QColor m_backgroundColor;
    QPixmap m_pix;

};

#endif // TTKTILEBACKGROUNDLABEL_H
