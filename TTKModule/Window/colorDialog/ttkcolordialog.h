#ifndef TTKCOLORDIALOG_H
#define TTKCOLORDIALOG_H

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
class TTK_MODULE_EXPORT TTKHlPalette : public QWidget
{
    Q_OBJECT
public:
    explicit TTKHlPalette(QWidget *parent = nullptr);

    QColor color() const;
    void setColor(const QColor &color);

    void initialize();

Q_SIGNALS:
    void colorChanged(const QColor &color);

public Q_SLOTS:
    void setSaturation(double dblsaturation);

private:
    virtual void paintEvent(QPaintEvent *event) override final;
    virtual void resizeEvent(QResizeEvent *event) override final;
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void mouseMoveEvent(QMouseEvent *event) override final;

    void calculateColor();

    QPoint m_ptVernierPos;
    QPointF m_ptfVernierPercentPos;
    QColor m_color;
    double m_dblSaturation;

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKHlSaturationPalette : public QWidget
{
    Q_OBJECT
public:
    explicit TTKHlSaturationPalette(QWidget *parent = nullptr);

    double saturation() const;
    void setSaturation(double dblsaturation);

Q_SIGNALS:
    void saturationChanged(double dblSaturation);

public Q_SLOTS:
    void setBaseColor(const QColor &color);

private:
    virtual void paintEvent(QPaintEvent *event) override final;
    virtual void resizeEvent(QResizeEvent *event) override final;
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void mouseMoveEvent(QMouseEvent *event) override final;

    void calculateSuration();

    QColor m_color;
    double m_dblVernierX, m_dblVernierPercentX, m_dblSaturation;

};

#endif // TTKCOLORDIALOG_H
