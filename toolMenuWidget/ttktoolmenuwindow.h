#ifndef TTKTOOLMENUWINDOW_H
#define TTKTOOLMENUWINDOW_H

/* =================================================
 * This file is part of the TTK WidgetTools project
 * Copyright (C) 2015 - 2018 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include <QMainWindow>

namespace Ui {
class TTKToolMenuWindow;
}

class TTKToolMenuWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit TTKToolMenuWindow(QWidget *parent = 0);
    ~TTKToolMenuWindow();

private:
    Ui::TTKToolMenuWindow *ui;

};

#endif // TTKTOOLMENUWINDOW_H
