#ifndef TOOLTRIMEND_H
#define TOOLTRIMEND_H

#include "abstracttooliterating.h"
#include <QObject>

class ToolTrimEnd: public AbstractToolIterating
{
    Q_OBJECT

public:
    ToolTrimEnd() : AbstractToolIterating(elementSmpl) {}

    /// Icon, label and category displayed to the user to describe the tool
    QString getIconName() const override
    {
        return ":/tool/trim_loop.svg";
    }

    QString getCategory() const override
    {
        return trUtf8("Sample processing");
    }

    /// Internal identifier
    QString getIdentifier() const override
    {
        return "smpl:trimEnd";
    }

    /// Process an element
    void process(SoundfontManager * sm, EltID id, AbstractToolParameters * parameters) override;

    /// Trim a sample
    static void trim(EltID id);

protected:
    QString getLabelInternal() const override
    {
        return trUtf8("Trim to end of loop");
    }
};

#endif // TOOLTRIMEND_H
