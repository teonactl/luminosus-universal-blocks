#include "EosOscMonitorBlock.h"
#include "core/manager/BlockList.h"

#include "core/CoreController.h"


bool EosOscMonitorBlock::s_registered = BlockList::getInstance().addBlock(EosOscMonitorBlock::info());

EosOscMonitorBlock::EosOscMonitorBlock(CoreController* controller, QString uid)
    : BlockBase(controller, uid)
{
    m_widthIsResizable = true;
    m_heightIsResizable = true;
}
