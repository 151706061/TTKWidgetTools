#ifndef TTKCLOCKMETERWIDGETPROPERTY_H
#define TTKCLOCKMETERWIDGETPROPERTY_H

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

#include "ttkwidgetproperty.h"

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKClockMeterWidgetProperty : public TTKWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKClockMeterWidgetProperty(QWidget *parent = nullptr);

private Q_SLOTS:
    virtual void enumPropertyChanged(QtProperty *property, int value) override final;
    virtual void colorPropertyChanged(QtProperty *property, const QColor &value) override final;

};

#endif // TTKCLOCKMETERWIDGETPROPERTY_H
