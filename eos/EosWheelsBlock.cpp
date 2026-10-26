#include "EosWheelsBlock.h"
#include "core/manager/BlockList.h"

bool EosWheelsBlock::s_registered = BlockList::getInstance().addBlock(EosWheelsBlock::info());

EosWheelsBlock::EosWheelsBlock(CoreController* controller, QString uid)
    : BlockBase(controller, uid)
{

}
