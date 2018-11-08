#ifndef SFZPARAMETERGROUPASSEMBLY_H
#define SFZPARAMETERGROUPASSEMBLY_H

#include "sfzparametergroup.h"

class SfzParameterGroupAssembly
{
public:
    // Chargement
    SfzParameterGroupAssembly() {}
    void newGroup() { _listeDivisions << SfzParameterGroup(); }
    void addParam(QString opcode, QString valeur)
    {
        if (_listeDivisions.size() == 0)
        {
            if (opcode == "group_label")
                _label = valeur;
            else
                _paramGlobaux << SfzParameter(opcode, valeur);
        }
        else
            _listeDivisions.last() << SfzParameter(opcode, valeur);
    }
    void moveOpcodesInGlobal(SfzParameterGroup &globalZone);
    void moveKeynumInSamples(SfzParameter::OpCode opCodeKeynum, SfzParameter::OpCode opCodeBase);
    void moveOpcodeInSamples(SfzParameter::OpCode opcode, QVariant::Type type);
    void moveModInSamples();
    void moveModInSamples(QList<SfzParameter::OpCode> opCodeList);
    void checkSampleValid(QString path);
    void checkFilter();
    void simplifyAttenuation();
    void adjustStereoVolumeAndCorrection(QString path);
    void adjustModulationVolume();
    bool isChannel10();
    double getAmpliMax();
    void adjustVolume(double offset);
    QString getLabel() { return _label; }

    // Décodage
    void decode(SoundfontManager * sf2, EltID idInst, QString pathSfz);

private:
    SfzParameterGroup _paramGlobaux;
    QList<SfzParameterGroup> _listeDivisions;
    QString _label;
};

#endif // SFZPARAMETERGROUPASSEMBLY_H