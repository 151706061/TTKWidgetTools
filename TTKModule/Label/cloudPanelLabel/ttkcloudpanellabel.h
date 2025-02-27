#ifndef TTKCLOUDPANELLABEL_H
#define TTKCLOUDPANELLABEL_H

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
class TTK_MODULE_EXPORT TTKCloudPanelLabel : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKCloudPanelLabel)
public:
    enum class CloudStyle
    {
        Black = 0,
        White = 1,
        Blue = 2,
        Purple = 3
	};

    explicit TTKCloudPanelLabel(QWidget *parent = nullptr);

    void setBackgroundColor(const QColor &backgroundColor);
    void setBaseColor(const QColor &baseColor);

    void setArcColor(const QColor &arcColor);
    void setBorderColor(const QColor &borderColor);

    void setIconColor(const QColor &textColor);
    void setPressColor(const QColor &pressColor);

    void setCloudStyle(const CloudStyle cloudStyle);

Q_SIGNALS:
    void mousePressed(int position);

private:
    virtual void resizeEvent(QResizeEvent *event) override final;
    virtual void enterEvent(QtEnterEvent *event) override final;
    virtual void leaveEvent(QEvent *event) override final;
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void mouseReleaseEvent(QMouseEvent *event) override final;
    virtual void paintEvent(QPaintEvent *event) override final;

    void recalcLayout();
    bool isPointIn(const QPoint &pos, int &bp);
    void drawCircle(QPainter *painter, int radius, const QBrush &brush);
    void drawArc(QPainter *painter);
    void drawButton(QPainter *painter);

    bool m_enter;
    bool m_pressed;

    QColor m_backgroundColor;
    QColor m_baseColor;
    QColor m_arcColor;
    QColor m_borderColor;
    QColor m_iconColor;
    QColor m_pressColor;
    CloudStyle m_cloudStyle;

    QPoint m_lastPoint;
    QRectF m_centerRect;
    QRectF m_leftRect;
    QRectF m_topRect;
    QRectF m_rightRect;
    QRectF m_bottomRect;
    QRectF m_leftTopRect;
    QRectF m_rightTopRect;
    QRectF m_leftBottomRect;
    QRectF m_rightBottomRect;
    QFont m_iconFont;

};

#endif // TTKCLOUDPANELLABEL_H
