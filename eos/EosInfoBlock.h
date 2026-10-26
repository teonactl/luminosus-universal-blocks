#ifndef EOSINFOBLOCK_H
#define EOSINFOBLOCK_H

#include "core/block_basics/BlockBase.h"
#include "core/helpers/utils.h"


class EosInfoBlock: public BlockBase
{
    Q_OBJECT

public:

    static bool s_registered;

    static BlockInfo info() {
        static BlockInfo info;
        info.typeName = "Eos Info";
        info.nameInUi = "Debug Info";
        info.category << "ETC Consoles" << "Eos";
        info.helpText = "Shows some useful information about the connection to the Eos console.";
        info.qmlFile = "qrc:/universal-blocks/eos/EosInfoBlock.qml";
        info.complete<EosInfoBlock>();
        return info;
    }

    explicit EosInfoBlock(CoreController* controller, QString uid);

public slots:
    virtual BlockInfo getBlockInfo() const override { return info(); }
};

#endif // EOSINFOBLOCK_H
