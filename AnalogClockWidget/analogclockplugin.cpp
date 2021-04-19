#include "analogclock.h"
#include "analogclockplugin.h"

#include <QtPlugin>

AnalogClockPlugin::AnalogClockPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void AnalogClockPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool AnalogClockPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *AnalogClockPlugin::createWidget(QWidget *parent)
{
    return new AnalogClock(parent);
}

QString AnalogClockPlugin::name() const
{
    return QLatin1String("AnalogClock");
}

QString AnalogClockPlugin::group() const
{
    return QLatin1String("");
}

QIcon AnalogClockPlugin::icon() const
{
    return QIcon(QLatin1String(":/analog-clock.png"));
}

QString AnalogClockPlugin::toolTip() const
{
    return QLatin1String("");
}

QString AnalogClockPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool AnalogClockPlugin::isContainer() const
{
    return false;
}

QString AnalogClockPlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\n"
           "<widget class=\"AnalogClock\" name=\"analogClock\">\n"
           "  <property name=\"geometry\">\n"
           "   <rect>\n"
           "    <x>0</x>\n"
           "    <y>0</y>\n"
           "    <width>100</width>\n"
           "    <height>100</height>\n"
           "   </rect>\n"
           "  </property>\n"
           "  <property name=\"toolTip\" >\n"
           "   <string>The current time</string>\n"
           "  </property>\n"
           "  <property name=\"whatsThis\" >\n"
           "   <string>The analog clock widget displays the current time.</string>\n"
           "  </property>\n"
           "</widget>\n"
           "</ui>\n");
}

QString AnalogClockPlugin::includeFile() const
{
    return QLatin1String("analogclock.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(analogclockplugin, AnalogClockPlugin)
#endif // QT_VERSION < 0x050000
