#include "EosMacroBlock.h"
#include "core/manager/BlockList.h"

#include "core/CoreController.h"
#include "core/eos/EosOSCManager.h"
#include "core/osc/OSCNetworkManager.h"
#include "core/connections/Nodes.h"


bool EosMacroBlock::s_registered = BlockList::getInstance().addBlock(EosMacroBlock::info());

EosMacroBlock::EosMacroBlock(CoreController* controller, QString uid)
    : OneInputBlock(controller, uid)
    , m_macroNumber(1)
    , m_lastValue(0.0)
    , m_runInbackground(this, "runInBackground", false)
{
    connect(m_inputNode, SIGNAL(dataChanged()), this, SLOT(onValueChanged()));
}

void EosMacroBlock::getAdditionalState(QCborMap& state) const {
    state[QStringLiteral("macroNumber")] = getMacroNumber();
}

void EosMacroBlock::setAdditionalState(const QCborMap &state) {
    setMacroNumber(int(state["macroNumber"].toInteger()));
}

void EosMacroBlock::onValueChanged() {
    double value = m_inputNode->getValue();
    if (value >= LuminosusConstants::triggerThreshold && m_lastValue < LuminosusConstants::triggerThreshold) {
        fire(1.0);
    } else if (value < LuminosusConstants::triggerThreshold && m_lastValue >= LuminosusConstants::triggerThreshold) {
        fire(0.0);
    }
    m_lastValue = value;
}

void EosMacroBlock::fire(double edge) {
    QString message = "/eos/user/1/macro/%1/fire";
    if (m_runInbackground) {
        message = "/eos/user/0/macro/%1/fire";
    }
    message = message.arg(QString::number(m_macroNumber));
    m_controller->lightingConsole()->sendMessage(message, edge);
}
