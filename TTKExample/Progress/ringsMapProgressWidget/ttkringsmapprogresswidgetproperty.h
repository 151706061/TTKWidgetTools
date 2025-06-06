#ifndef TTKRINGSMAPPROGRESSWIDGETPROPERTY_H
#define TTKRINGSMAPPROGRESSWIDGETPROPERTY_H

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
class TTK_MODULE_EXPORT TTKRingsMapProgressWidgetProperty : public TTKWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKRingsMapProgressWidgetProperty(QWidget *parent = nullptr);
    ~TTKRingsMapProgressWidgetProperty();

private Q_SLOTS:
    virtual void boolPropertyChanged(QtProperty *property, bool value) override final;

private Q_SLOTS:
    void updateRender();

private:
    QTimer *m_timer;

};

#endif // TTKRINGSMAPPROGRESSWIDGETPROPERTY_H
