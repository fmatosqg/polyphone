#ifndef TOOLFREQUENCYPEAKS_H
#define TOOLFREQUENCYPEAKS_H

#include "abstracttoolonestep.h"

class ToolFrequencyPeaks: public AbstractToolOneStep
{
public:
    ToolFrequencyPeaks();

    /// Icon, label and category displayed to the user to describe the tool
    QString getIconName() const override
    {
        return ":/tool/peak_export.svg";
    }

    QString getLabel() const override
    {
        return trUtf8("Visualiser les pics de fréquences");
    }

    QString getCategory() const override
    {
        return trUtf8("Analyse");
    }

    /// Internal identifier
    QString getIdentifier() const override
    {
        return "smpl:frequencyPeaks";
    }

    /// Process asynchronously run
    void process(SoundfontManager * sm, IdList ids, AbstractToolParameters * parameters) override;

protected:
    /// Return true if the tool can be used on the specified ids
    bool isCompatible(IdList ids) override;

    /// Get a confirmation message after the tool is run
    QString getConfirmation() override;
};

#endif // TOOLFREQUENCYPEAKS_H