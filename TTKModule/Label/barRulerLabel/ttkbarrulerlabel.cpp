#include "ttkbarrulerlabel.h"

#include <QTimer>
#include <QPainter>

TTKBarRulerLabel::TTKBarRulerLabel(QWidget *parent)
    : QWidget(parent),
      m_minValue(0),
      m_maxValue(100),
      m_value(0),
      m_precision(0),
      m_longStep(10),
      m_shortStep(1),
      m_space(20),
      m_animation(true),
      m_animationStep(0.5),
      m_backgroundColorStart(100, 100, 100),
      m_backgroundColorEnd(60, 60, 60),
      m_lineColor(255, 255, 255),
      m_barBackgroundColor(220, 220, 220),
      m_barColor(100, 184, 255),
      m_reverse(false),
      m_currentValue(0)
{
    m_timer = new QTimer(this);
    m_timer->setInterval(10 * TTK_DN_MS);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateValue()));

    setFont(QFont("Arial", 8));
}

TTKBarRulerLabel::~TTKBarRulerLabel()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }
}

void TTKBarRulerLabel::setRange(double minValue, double maxValue)
{
    if(minValue >= maxValue)
    {
        return;
    }

    m_minValue = minValue;
    m_maxValue = maxValue;

    if(m_value < m_minValue || m_value > m_maxValue)
    {
        setValue(m_value);
    }

    update();
}

void TTKBarRulerLabel::setMinValue(double minValue)
{
    setRange(minValue, m_maxValue);
}

void TTKBarRulerLabel::setMaxValue(double maxValue)
{
    setRange(m_minValue, maxValue);
}

void TTKBarRulerLabel::setValue(double value)
{
    if(value < m_minValue || value > m_maxValue)
    {
        return;
    }

    if(value > m_value)
    {
        m_reverse = false;
    }
    else if(value < m_value)
    {
        m_reverse = true;
    }

    m_value = value;

    if(!m_animation)
    {
        m_currentValue = value;
        update();
    }
    else
    {
        m_timer->start();
    }
}

void TTKBarRulerLabel::setPrecision(int precision)
{
    if(precision <= 2 && m_precision != precision)
    {
        m_precision = precision;
        update();
    }
}

void TTKBarRulerLabel::setLongStep(int longStep)
{
    if(longStep < m_shortStep)
    {
        return;
    }

    if(m_longStep != longStep)
    {
        m_longStep = longStep;
        update();
    }
}

void TTKBarRulerLabel::setShortStep(int shortStep)
{
    if(m_longStep < shortStep)
    {
        return;
    }

    if(m_shortStep != shortStep)
    {
        m_shortStep = shortStep;
        update();
    }
}

void TTKBarRulerLabel::setSpace(int space)
{
    if(m_space != space)
    {
        m_space = space;
        update();
    }
}

void TTKBarRulerLabel::setAnimation(bool animation)
{
    if(m_animation != animation)
    {
        m_animation = animation;
        update();
    }
}

void TTKBarRulerLabel::setAnimationStep(double animationStep)
{
    if(m_animationStep != animationStep)
    {
        m_animationStep = animationStep;
        update();
    }
}

void TTKBarRulerLabel::setBackgroundColorStart(const QColor &backgroundColorStart)
{
    if(m_backgroundColorStart != backgroundColorStart)
    {
        m_backgroundColorStart = backgroundColorStart;
        update();
    }
}

void TTKBarRulerLabel::setBackgroundColorEnd(const QColor &backgroundColorEnd)
{
    if(m_backgroundColorEnd != backgroundColorEnd)
    {
        m_backgroundColorEnd = backgroundColorEnd;
        update();
    }
}

void TTKBarRulerLabel::setLineColor(const QColor &lineColor)
{
    if(m_lineColor != lineColor)
    {
        m_lineColor = lineColor;
        update();
    }
}

void TTKBarRulerLabel::setBarBackgroundColor(const QColor &barBackgroundColor)
{
    if(m_barBackgroundColor != barBackgroundColor)
    {
        m_barBackgroundColor = barBackgroundColor;
        update();
    }
}

void TTKBarRulerLabel::setBarColor(const QColor &barColor)
{
    if(m_barColor != barColor)
    {
        m_barColor = barColor;
        update();
    }
}

QSize TTKBarRulerLabel::sizeHint() const
{
    return QSize(100, 350);
}

void TTKBarRulerLabel::updateValue()
{
    if(!m_reverse)
    {
        if(m_currentValue >= m_value)
        {
            m_currentValue = m_value;
            m_timer->stop();
        }
        else
        {
            m_currentValue += m_animationStep;
        }
    }
    else
    {
        if(m_currentValue <= m_value)
        {
            m_currentValue = m_value;
            m_timer->stop();
        }
        else
        {
            m_currentValue -= m_animationStep;
        }
    }
    update();
}

void TTKBarRulerLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    drawBackground(&painter);
    drawRuler(&painter);
    drawBarBackground(&painter);
    drawBar(&painter);
}

void TTKBarRulerLabel::drawBackground(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    QLinearGradient bgGradient(QPointF(0, 0), QPointF(0, height()));
    bgGradient.setColorAt(0.0, m_backgroundColorStart);
    bgGradient.setColorAt(1.0, m_backgroundColorEnd);

    painter->setBrush(bgGradient);
    painter->drawRect(rect());
    painter->restore();
}

void TTKBarRulerLabel::drawRuler(QPainter *painter)
{
    painter->save();
    painter->setPen(m_lineColor);

    const double initX = m_space + 20;
    double initY = m_space;

    const QPointF topPot(initX, initY);
    const QPointF bottomPot(initX, height() - m_space);
    painter->drawLine(topPot, bottomPot);

    const double length = height() - 2 * m_space;
    const double increment = length / (m_maxValue - m_minValue);

    constexpr int longLineLen = 10;
    int shortLineLen = 7;

    for(int i = m_maxValue; i >= m_minValue; i = i - m_shortStep)
    {
        if(i % m_longStep == 0)
        {
            const QPointF leftPot(initX + longLineLen, initY);
            const QPointF rightPot(initX, initY);
            painter->drawLine(leftPot, rightPot);

            const QString &strValue = QString("%1").arg(i * 1.0, 0, 'f', m_precision);
            const int fontWidth = QtFontWidth(fontMetrics(), strValue);
            const int fontHeight = painter->fontMetrics().height();
            const QPointF textPot(initX - fontWidth - 5, initY + fontHeight / 3.0);
            painter->drawText(textPot, strValue);
        }
        else
        {
            if(i % (m_longStep / 2) == 0)
            {
                shortLineLen = 7;
            }
            else
            {
                shortLineLen = 4;
            }

            const QPointF leftPot(initX + shortLineLen, initY);
            const QPointF rightPot(initX, initY);
            painter->drawLine(leftPot, rightPot);
        }
        initY += increment * m_shortStep;
    }
    painter->restore();
}

void TTKBarRulerLabel::drawBarBackground(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    const double initX = m_space + 20 + 15;
    const QPointF topLeftPot(initX, m_space);
    const QPointF bottomRightPot(width() - m_space , height() - m_space);
    m_barRect = QRectF(topLeftPot, bottomRightPot);

    painter->setBrush(m_barBackgroundColor);
    painter->drawRect(m_barRect);
    painter->restore();
}

void TTKBarRulerLabel::drawBar(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    const double barHeight = m_barRect.height();
    const double increment = barHeight / (m_maxValue - m_minValue);
    const double initY = (m_currentValue - m_minValue) * increment;

    const QPointF topLeftPot(m_barRect.topLeft().x(), m_barRect.bottomLeft().y() - initY);
    const QPointF bottomRightPot(m_barRect.bottomRight());
    const QRectF currentRect(topLeftPot, bottomRightPot);

    painter->setBrush(m_barColor);
    painter->drawRect(currentRect);
    painter->restore();
}
