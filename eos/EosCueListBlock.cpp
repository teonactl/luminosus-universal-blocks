#include "EosCueListBlock.h"
#include "core/manager/BlockList.h"

#include "core/CoreController.h"


bool EosCueListBlock::s_registered = BlockList::getInstance().addBlock(EosCueListBlock::info());

EosCueListBlock::EosCueListBlock(CoreController* controller, QString uid)
    : BlockBase(controller, uid)
    , m_cueListNumber(1)
{
    m_widthIsResizable = true;
    m_heightIsResizable = true;
}

void EosCueListBlock::getAdditionalState(QCborMap& state) const {
    state[QStringLiteral("cueListNumber")] = getCueListNumber();
}

void EosCueListBlock::setAdditionalState(const QCborMap& state) {
    setCueListNumber(int(state["cueListNumber"].toInteger()));
}
