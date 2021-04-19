#include "digitalclock.h"
#include "digitalclockplugin.h"

#include <QtPlugin>

DigitalClockPlugin::DigitalClockPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void DigitalClockPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool DigitalClockPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *DigitalClockPlugin::createWidget(QWidget *parent)
{
    return new DigitalClock(parent);
}

QString DigitalClockPlugin::name() const
{
    return QLatin1String("DigitalClock");
}

QString DigitalClockPlugin::group() const
{
    return QLatin1String("");
}

QIcon DigitalClockPlugin::icon() const
{
    return QIcon(QLatin1String(":/digital-clock.png"));
}

QString DigitalClockPlugin::toolTip() const
{
    return QLatin1String("");
}

QString DigitalClockPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool DigitalClockPlugin::isContainer() const
{
    return false;
}

QString DigitalClockPlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\n"
           "<widget class=\"DigitalClock\" name=\"digitalClock\">\n"
           "  <property name=\"geometry\">\n"
           "   <rect>\n"
           "    <x>0</x>\n"
           "    <y>0</y>\n"
           "    <width>200</width>\n"
           "    <height>100</height>\n"
           "   </rect>\n"
           "  </property>\n"
           "  <property name=\"toolTip\" >\n"
           "   <string>The current time</string>\n"
           "  </property>\n"
           "  <property name=\"whatsThis\" >\n"
           "   <string>The digital clock widget displays the current time.</string>\n"
           "  </property>\n"
           "</widget>\n"
           "</ui>\n");
}

QString DigitalClockPlugin::includeFile() const
{
    return QLatin1String("digitalclock.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(digitalclockplugin, DigitalClockPlugin)
#endif // QT_VERSION < 0x050000
