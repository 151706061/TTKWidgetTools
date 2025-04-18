#ifndef TTKPAINTMETERWIDGET_H
#define TTKPAINTMETERWIDGET_H

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
class TTK_MODULE_EXPORT TTKPaintMeterWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKPaintMeterWidget)
public:
    explicit TTKPaintMeterWidget(QWidget *parent = nullptr);

    void setThreshold(double value);
    void setValue(double value);

    virtual QSize sizeHint() const override final;

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    void drawCrown(QPainter *painter);
    void drawBackground(QPainter *painter);
    void drawTicks(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawUnits(QPainter *painter);
    void drawNeedle(QPainter *painter);
    void drawThresholdLine(QPainter *painter);
    void drawNumericValue(QPainter *painter);
    void drawCoverGlass(QPainter *painter);
    void drawLabel(QPainter *painter);
    void drawValidWindow(QPainter *painter);
    void drawWarningWindow(QPainter *painter);
    void thresholdManager();

    double m_value, m_minValue, m_maxValue;
    int m_precision, m_precisionNumeric;
    QString m_units, m_label;
	int m_steps;
    double m_startAngle, m_endAngle, m_threshold;
    bool m_thresholdFlag, m_enableValidWindow;
    double m_beginValidValue, m_endValidValue;    
    bool m_enableWarningWindow;
    double m_beginWarningValue, m_endWarningValue;
    bool m_thresholdEnabled, m_numericIndicatorEnabled;
    QColor m_foregroundColor, m_backgroundColor;

};

#endif  // TTKPAINTMETERWIDGET_H
