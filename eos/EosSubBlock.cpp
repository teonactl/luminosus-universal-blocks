#include "EosSubBlock.h"
#include "core/manager/BlockList.h"

#include "core/CoreController.h"
#include "core/eos/EosOSCManager.h"
#include "core/osc/OSCNetworkManager.h"
#include "core/connections/Nodes.h"

bool EosSubBlock::s_registered = BlockList::getInstance().addBlock(EosSubBlock::info());

EosSubBlock::EosSubBlock(CoreController* controller, QString uid)
    : OneInputBlock(controller, uid)
    , m_subNumber(1)
    , m_value(0.0)
{
    m_heightIsResizable = true;
    connect(m_inputNode, SIGNAL(dataChanged()), this, SLOT(onValueChanged()));
}

void EosSubBlock::getAdditionalState(QCborMap& state) const {
    state[QStringLiteral("subNumber")] = getSubNumber();
    state[QStringLiteral("value")] = getValue();
}

void EosSubBlock::setAdditionalState(const QCborMap &state) {
    setSubNumber(int(state["subNumber"].toInteger()));
    setValue(state["value"].toDouble());
}

void EosSubBlock::onValueChanged() {
    double value = m_inputNode->getValue();
    setValue(value);
}

void EosSubBlock::sendBumpEvent(double edge) {
    QString message = "/eos/sub/%1/fire";
    message = message.arg(QString::number(m_subNumber));
    m_controller->lightingConsole()->sendMessage(message, edge);
}

void EosSubBlock::setValue(double value) {
    if (value == m_value) return;
    m_value = value;
    emit valueChanged();

    QString message = "/eos/sub/%1";
    message = message.arg(QString::number(m_subNumber));
    m_controller->lightingConsole()->sendMessage(message, value);
}
