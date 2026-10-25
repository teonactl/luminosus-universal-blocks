#include "StyledTextBlock.h"

#include "core/manager/BlockList.h"


bool StyledTextBlock::s_registered = BlockList::getInstance().addBlock(StyledTextBlock::info());


StyledTextBlock::StyledTextBlock(CoreController* controller, QString uid)
    : BlockBase(controller, uid)
    , m_text(this, "text", "Text")
    , m_fontSize(this, "fontSize", 20, 6, 200)
    , m_fontFamily(this, "fontFamily", "Quicksand")
    , m_color(this, "color", "#ffffff")
    , m_bold(this, "bold", false)
    , m_underline(this, "underline", false)
    , m_centered(this, "centered", false)
    , m_shadow(this, "shadow", true)
    , m_shadowColor(this, "shadowColor", "#555555")
{
    m_widthIsResizable = true;
}
