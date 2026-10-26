#include "EosMasterPlaybackBlock.h"
#include "core/manager/BlockList.h"

#include "core/CoreController.h"
#include "core/eos/EosOSCManager.h"
#include "core/osc/OSCNetworkManager.h"


bool EosMasterPlaybackBlock::s_registered = BlockList::getInstance().addBlock(EosMasterPlaybackBlock::info());

EosMasterPlaybackBlock::EosMasterPlaybackBlock(CoreController* controller, QString uid)
    : BlockBase(controller, uid)
{

}

void EosMasterPlaybackBlock::sendLoadEvent(qreal buttonEdge) {
    QString message = "/eos/user/1/key/fader_ab";
    m_controller->lightingConsole()->sendMessage(message, buttonEdge);
}

void EosMasterPlaybackBlock::sendUnloadEvent() {
    QString message = "/eos/user/1/key/shift";
    m_controller->lightingConsole()->sendMessage(message, 1.0);
    message = "/eos/user/1/key/fader_ab";
    m_controller->lightingConsole()->sendMessage(message);
    message = "/eos/user/1/key/shift";
    m_controller->lightingConsole()->sendMessage(message, 0.0);
}

void EosMasterPlaybackBlock::sendStopEvent(qreal buttonEdge) {
    QString message = "/eos/user/1/key/stop";
    m_controller->lightingConsole()->sendMessage(message, buttonEdge);
}

void EosMasterPlaybackBlock::sendGoEvent(qreal buttonEdge) {
    QString message = "/eos/user/1/key/go_0";
    m_controller->lightingConsole()->sendMessage(message, buttonEdge);
}
