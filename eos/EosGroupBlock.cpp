#include "EosGroupBlock.h"
#include "core/manager/BlockList.h"

#include "core/CoreController.h"
#include "core/eos/EosOSCManager.h"
#include "core/osc/OSCNetworkManager.h"
#include "core/connections/Nodes.h"


bool EosGroupBlock::s_registered = BlockList::getInstance().addBlock(EosGroupBlock::info());

EosGroupBlock::EosGroupBlock(CoreController* controller, QString uid)
    : OneInputBlock(controller, uid)
    , m_groupNumber(1)
    , m_lastValue()
{
    connect(m_inputNode, SIGNAL(dataChanged()), this, SLOT(onValueChanged()));
}

void EosGroupBlock::getAdditionalState(QCborMap& state) const {
    state[QStringLiteral("groupNumber")] = getGroupNumber();
}

void EosGroupBlock::setAdditionalState(const QCborMap &state) {
    setGroupNumber(int(state["groupNumber"].toInteger()));
}

void EosGroupBlock::onValueChanged() {
    HSV hsv = m_inputNode->constData().getHsvAt(0, 0);
    if (hsv.h != m_lastValue.h || hsv.s != m_lastValue.s) {
        QString message = "/eos/user/0/group/%1/param/hue/saturation";
        message = message.arg(QString::number(m_groupNumber));
        m_controller->lightingConsole()->sendMessage(message, hsv.h * 360, hsv.s * 100);
    }
    if (hsv.v != m_lastValue.v) {
        QString message = "/eos/user/0/group/%1";
        message = message.arg(QString::number(m_groupNumber));
        m_controller->lightingConsole()->sendMessage(message, hsv.v * 100);
    }
    m_lastValue = hsv;
}
