#include "EosCmdBlock.h"
#include "core/manager/BlockList.h"

bool EosCmdBlock::s_registered = BlockList::getInstance().addBlock(EosCmdBlock::info());

EosCmdBlock::EosCmdBlock(CoreController* controller, QString uid)
    : BlockBase(controller, uid)
    , m_userId(1)
{

}

void EosCmdBlock::getAdditionalState(QCborMap& state) const {
    state[QStringLiteral("userId")] = getUserId();
}

void EosCmdBlock::setAdditionalState(const QCborMap &state) {
    setUserId(int(state["userId"].toInteger()));
}
