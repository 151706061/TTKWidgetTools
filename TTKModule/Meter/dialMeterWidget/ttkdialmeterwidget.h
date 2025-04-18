#ifndef TTKDIALMETERWIDGET_H
#define TTKDIALMETERWIDGET_H

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
class TTK_MODULE_EXPORT TTKDialMeterWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKDialMeterWidget)
public:
    enum class PointerStyle
    {
        Circle = 0,
        Indicator = 1,
        IndicatorR = 2,
        Triangle = 3
    };

    explicit TTKDialMeterWidget(QWidget *parent = nullptr);

    void setRange(double minValue, double maxValue);

    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    void setValue(double value);

    void setPrecision(int precision);
    void setScaleMajor(int scaleMajor);
    void setScaleMinor(int scaleMinor);
    void setStartAngle(int startAngle);
    void setEndAngle(int endAngle);

    void setShowValue(bool showValue);

    void setDarkColor(const QColor &darkColor);
    void setLightColor(const QColor &lightColor);
    void setTextColor(const QColor &textColor);

    void setPointerStyle(const PointerStyle &pointerStyle);

    virtual QSize sizeHint() const override;

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawBorderCircle(QPainter *painter);
    void drawBackgroundCircle(QPainter *painter);
    void drawPointerCircle(QPainter *painter);
    void drawPointerIndicator(QPainter *painter);
    void drawPointerIndicatorR(QPainter *painter);
    void drawPointerTriangle(QPainter *painter);
    void drawCenterCircle(QPainter *painter);
    void drawValue(QPainter *painter);

    double m_minValue;
    double m_maxValue;
    double m_value;
    int m_precision;
    int m_scaleMajor;
    int m_scaleMinor;
    int m_startAngle;
    int m_endAngle;

    QColor m_darkColor;
    QColor m_lightColor;
    QColor m_textColor;
    bool m_showValue;
    PointerStyle m_pointerStyle;

};

#endif  // TTKDIALMETERWIDGET_H
