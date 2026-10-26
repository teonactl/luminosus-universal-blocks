#ifndef EOSCMDBLOCK_H
#define EOSCMDBLOCK_H

#include "core/block_basics/BlockBase.h"
#include "core/helpers/utils.h"


class EosCmdBlock : public BlockBase
{
    Q_OBJECT

    Q_PROPERTY(int userId READ getUserId WRITE setUserId NOTIFY userIdChanged)

public:

    static bool s_registered;

    static BlockInfo info() {
        static BlockInfo info;
        info.typeName = "Eos Cmd";
        info.nameInUi = "Commandline";
        info.category << "ETC Consoles" << "Eos";
        info.helpText = "Shows the current commandline text of the selected Eos user.";
        info.qmlFile = "qrc:/universal-blocks/eos/EosCmdBlock.qml";
        info.complete<EosCmdBlock>();
        return info;
    }

    explicit EosCmdBlock(CoreController* controller, QString uid);

    virtual void getAdditionalState(QCborMap& state) const override;
    virtual void setAdditionalState(const QCborMap& state) override;

signals:
    void userIdChanged();

public slots:
    virtual BlockInfo getBlockInfo() const override { return info(); }

    int getUserId() const { return m_userId; }
    void setUserId(int value) { m_userId = limit(0, value, 999); emit userIdChanged(); }

protected:
    int m_userId;
};

#endif // EOSCMDBLOCK_H
