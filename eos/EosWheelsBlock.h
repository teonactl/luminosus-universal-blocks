#ifndef EOSWHEELSBLOCK_H
#define EOSWHEELSBLOCK_H

#include "core/block_basics/BlockBase.h"
#include "core/helpers/utils.h"


class EosWheelsBlock: public BlockBase
{
    Q_OBJECT

public:

    static bool s_registered;

    static BlockInfo info() {
        static BlockInfo info;
        info.typeName = "Eos Wheels";
        info.nameInUi = "Channel Parameters";
        info.category << "ETC Consoles" << "Eos";
        info.helpText = "Shows the available parameters and their values for the active channels.\n\n"
                        "Attention: The shown parameters depend on the selected channels for the "
                        "current OSC User ID (see Eos Debug Info). This may not be the same as "
                        "the console user.";
        info.qmlFile = "qrc:/universal-blocks/eos/EosWheelsBlock.qml";
        info.complete<EosWheelsBlock>();
        return info;
    }

    explicit EosWheelsBlock(CoreController* controller, QString uid);

public slots:
    virtual BlockInfo getBlockInfo() const override { return info(); }
};

#endif // EOSWHEELSBLOCK_H
