#ifndef TTKSTYLESLIDER_H
#define TTKSTYLESLIDER_H

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

#include <QSlider>
#include "ttkmoduleexport.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKStyleSlider : public QSlider
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKStyleSlider)
public:
    explicit TTKStyleSlider(QWidget *parent = nullptr);

    void setHandleColor(const QColor &color);
    void setForegroundColor(const QColor &color);
    void setBackgroundColor(const QColor &color);

    virtual QSize sizeHint() const override final;

public Q_SLOTS:
    void setOrientation(Qt::Orientation orientation);

private:
    void setupProperties();

    QColor m_handleColor, m_backgroundColor, m_foregroundColor;

};

#endif // TTKSTYLESLIDER_H
