#include "ttkradiusprogresswidgetproperty.h"
#include "ttkradiusprogresswidget.h"
#if TTK_QT_VERSION_CHECK(5,10,0)
#  include <QRandomGenerator>
#endif
#include <QTimer>
#include <QDateTime>

static int random(int value)
{
#if TTK_QT_VERSION_CHECK(5,10,0)
    return QRandomGenerator::global()->bounded(value);
#else
    return qrand() % value;
#endif
}

TTKRadiusProgressWidgetProperty::TTKRadiusProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
#if !TTK_QT_VERSION_CHECK(5,10,0)
    qsrand(QDateTime::currentMSecsSinceEpoch());
#endif
    m_item = new TTKRadiusProgressWidget(this);
    //
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateRender()));

    m_timer->setInterval(TTK_DN_S2MS / 2);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKRadiusProgressWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, true);
    objectItem->addSubProperty(activityItem);
    //
    m_browser->addProperty(objectItem);
}

TTKRadiusProgressWidgetProperty::~TTKRadiusProgressWidgetProperty()
{
    delete m_timer;
}

void TTKRadiusProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    if(property->propertyName() == "Activity")
    {
        if(value)
        {
            m_timer->start();
        }
        else
        {
            m_timer->stop();
        }
    }
}

void TTKRadiusProgressWidgetProperty::updateRender()
{
    TTKRadiusProgressWidget *widget = TTKObjectCast(TTKRadiusProgressWidget*, m_item);
    widget->setValue(random(100) + 1);
}
