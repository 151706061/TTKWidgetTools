#ifndef TTKANIMATIONSTACKEDWIDGET_H
#define TTKANIMATIONSTACKEDWIDGET_H

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

#include <QStackedWidget>
#include "ttkmoduleexport.h"

class QPropertyAnimation;

class TTK_MODULE_EXPORT TTKAnimationStackedWidget : public QStackedWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKAnimationStackedWidget)
public:
    enum class Module
    {
        LeftToRight,
        RightToLeft,
        TopToBottom,
        BottomToTop
    };

    explicit TTKAnimationStackedWidget(QWidget *parent = nullptr);
    ~TTKAnimationStackedWidget();

    void start(int index);
    void setLength(int length, Module type);

    void setDuration(int duration);
    int duration() const;

    virtual QSize sizeHint() const override final;

private Q_SLOTS:
    void valueChanged(const QVariant &value);
    void animationFinished();

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    void renderPreviousWidget(QPainter *painter, QTransform &transform);
    void renderCurrentWidget(QPainter *painter, QTransform &transform);

    bool m_isAnimating;
    float m_currentValue;
    int m_currentIndex, m_previousIndex;
    Module m_type;
    QPropertyAnimation *m_animation;

};

#endif // TTKANIMATIONSTACKEDWIDGET_H
