#include "EosInfoBlock.h"
#include "core/manager/BlockList.h"

bool EosInfoBlock::s_registered = BlockList::getInstance().addBlock(EosInfoBlock::info());

EosInfoBlock::EosInfoBlock(CoreController* controller, QString uid)
    : BlockBase(controller, uid)
{

}
