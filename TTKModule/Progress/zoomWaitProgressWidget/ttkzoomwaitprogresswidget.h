#ifndef TTKZOOMWAITPROGRESSWIDGET_H
#define TTKZOOMWAITPROGRESSWIDGET_H

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
 */
class TTK_MODULE_EXPORT TTKZoomWaitProgressWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKZoomWaitProgressWidget)
public:
    explicit TTKZoomWaitProgressWidget(QWidget *parent = nullptr);

    void setColor(const QColor &color);
    void setZoomOut(bool zoom);
    void setZoomDelta(int delta);
    void setMinRadious(int value);
    void setRadious(int value);

    virtual QSize sizeHint() const override final;

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    void drawZoomWait(QPainter *painter);
    void fixRadious(int max);

    QColor m_color;
    bool m_zoomOut;
    int m_zoomDelta;
    int m_radious;
    int m_minRadious;

    QTimer *m_timer;

};

#endif // TTKZOOMWAITPROGRESSWIDGET_H
