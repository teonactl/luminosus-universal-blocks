#ifndef EOSCUELISTBLOCK_H
#define EOSCUELISTBLOCK_H

#include "core/block_basics/BlockBase.h"
#include "core/helpers/utils.h"


class EosCueListBlock: public BlockBase
{
    Q_OBJECT

    Q_PROPERTY(int cueListNumber READ getCueListNumber WRITE setCueListNumber NOTIFY cueListNumberChanged)

public:

    static bool s_registered;

    static BlockInfo info() {
        static BlockInfo info;
        info.typeName = "Eos CueList";
        info.nameInUi = "Cue List";
        info.category << "ETC Consoles" << "Eos";
        info.helpText = "Shows the selected Cue List.\n\n"
                        "A Cue can be edited by clicking on the pen icon. "
                        "The changes will be transmitted to the console after a click on the "
                        "green tick icon.";
        info.qmlFile = "qrc:/universal-blocks/eos/EosCueListBlock.qml";
        info.complete<EosCueListBlock>();
        return info;
    }

    explicit EosCueListBlock(CoreController* controller, QString uid);

    virtual void getAdditionalState(QCborMap& state) const override;
    virtual void setAdditionalState(const QCborMap& state) override;

signals:
    void cueListNumberChanged();

public slots:
    virtual BlockInfo getBlockInfo() const override { return info(); }

    int getCueListNumber() const { return m_cueListNumber; }
    void setCueListNumber(int value) { m_cueListNumber = limit(1, value, 999); emit cueListNumberChanged(); }

protected:
    int m_cueListNumber;

};

#endif // EOSCUELISTBLOCK_H
