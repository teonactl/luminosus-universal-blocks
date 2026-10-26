#ifndef EOSGROUPBLOCK_H
#define EOSGROUPBLOCK_H

#include "core/block_basics/OneInputBlock.h"
#include "core/helpers/utils.h"
#include "core/connections/Matrix.h"


class EosGroupBlock : public OneInputBlock
{
    Q_OBJECT

    Q_PROPERTY(int groupNumber READ getGroupNumber WRITE setGroupNumber NOTIFY groupNumberChanged)

public:

    static bool s_registered;

    static BlockInfo info() {
        static BlockInfo info;
        info.typeName = "Eos Group";
        info.nameInUi = "Group";
        info.category << "ETC Consoles" << "Eos";
        info.helpText = "Controls the intensity and color of the selected group of an Eos console.\n\n"
                        "Sets OSC user implicitly to 0.";
        info.qmlFile = "qrc:/universal-blocks/eos/EosGroupBlock.qml";
        info.complete<EosGroupBlock>();
        return info;
    }

    explicit EosGroupBlock(CoreController* controller, QString uid);

    virtual void getAdditionalState(QCborMap& state) const override;
    virtual void setAdditionalState(const QCborMap& state) override;

signals:
    void groupNumberChanged();

public slots:
    virtual BlockInfo getBlockInfo() const override { return info(); }

    void onValueChanged();

    int getGroupNumber() const { return m_groupNumber; }
    void setGroupNumber(int value) { m_groupNumber = limit(1, value, 9999); emit groupNumberChanged(); }

protected:
    int m_groupNumber;
    HSV m_lastValue;
};


#endif // EOSGROUPBLOCK_H
