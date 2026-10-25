#ifndef STYLEDTEXTBLOCK_H
#define STYLEDTEXTBLOCK_H

#include "core/block_basics/BlockBase.h"


class StyledTextBlock : public BlockBase
{
    Q_OBJECT

public:

    static bool s_registered;
    static BlockInfo info() {
        static BlockInfo info;
        info.typeName = "Styled Text";
        info.nameInUi = "Styled Text";
        info.category << "General" << "Content";
        info.helpText = "Shows a piece of text with custom font, size, color and style.\n\n"
                        "Can be used to add titles or labels directly on the canvas.";
        info.qmlFile = "qrc:/universal-blocks/content/StyledTextBlock.qml";
        info.orderHint = 0 + 200 + 2;
        info.complete<StyledTextBlock>();
        return info;
    }

    explicit StyledTextBlock(CoreController* controller, QString uid);

public slots:
    virtual BlockInfo getBlockInfo() const override { return info(); }

protected:
    StringAttribute m_text;
    IntegerAttribute m_fontSize;
    StringAttribute m_fontFamily;
    StringAttribute m_color;
    BoolAttribute m_bold;
    BoolAttribute m_underline;
    BoolAttribute m_centered;
    BoolAttribute m_shadow;
    StringAttribute m_shadowColor;
};

#endif // STYLEDTEXTBLOCK_H
