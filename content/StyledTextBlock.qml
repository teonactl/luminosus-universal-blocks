import QtQuick 2.12
import CustomElements 1.0
import "qrc:/core/ui/items"
import "qrc:/core/ui/controls"

BlockBase {
    id: root
    width: 200*dp
    height: Math.max(label.implicitHeight + 38*dp, 60*dp)
    onWidthChanged: if (block) block.positionChanged()
    settingsComponent: settings

    property bool editing: textInput.activeFocus

    StretchColumn {
        anchors.fill: parent

        Item {
            implicitHeight: -1

            // shadow copy, offset and drawn first:
            Text {
                id: shadowLabel
                visible: block.attr("shadow").val
                anchors.fill: parent
                anchors.margins: 4*dp
                x: 1*dp
                y: 1*dp
                horizontalAlignment: block.attr("centered").val ? Text.AlignHCenter : Text.AlignLeft
                wrapMode: Text.Wrap
                text: block.attr("text").val
                color: block.attr("shadowColor").val
                font.family: block.attr("fontFamily").val
                font.pixelSize: block.attr("fontSize").val * dp
                font.bold: block.attr("bold").val
                font.underline: block.attr("underline").val
            }

            Text {
                id: label
                visible: !editing
                anchors.fill: parent
                anchors.margins: 4*dp
                horizontalAlignment: block.attr("centered").val ? Text.AlignHCenter : Text.AlignLeft
                wrapMode: Text.Wrap
                text: block.attr("text").val
                color: block.attr("color").val
                font.family: block.attr("fontFamily").val
                font.pixelSize: block.attr("fontSize").val * dp
                font.bold: block.attr("bold").val
                font.underline: block.attr("underline").val

                MouseArea {
                    anchors.fill: parent
                    onClicked: textInput.focus = true
                }
            }

            TextEdit {
                id: textInput
                visible: editing
                anchors.fill: parent
                anchors.margins: 4*dp
                horizontalAlignment: block.attr("centered").val ? Text.AlignHCenter : Text.AlignLeft
                wrapMode: TextEdit.Wrap
                selectByMouse: true
                color: block.attr("color").val
                font.family: block.attr("fontFamily").val
                font.pixelSize: block.attr("fontSize").val * dp
                font.bold: block.attr("bold").val
                font.underline: block.attr("underline").val

                text: block.attr("text").val
                onTextChanged: {
                    if (text !== block.attr("text").val) {
                        block.attr("text").val = text
                    }
                }
                Keys.onEscapePressed: focus = false
            }
        }

        DragArea {
            text: "Styled Text"

            WidthResizeArea {
                target: root
                minSize: 80*dp
                maxSize: 2000*dp
            }
        }
    }  // end main Column

    Component {
        id: settings
        StretchColumn {
            leftMargin: 15*dp
            rightMargin: 15*dp
            defaultSize: 30*dp
            height: implicitHeight

            BlockRow {
                StretchText {
                    text: "Font Size:"
                }
                AttributeNumericInput {
                    width: 60*dp
                    implicitWidth: 0
                    attr: block.attr("fontSize")
                }
            }
            BlockRow {
                StretchText {
                    text: "Font:"
                }
                TextInput {
                    width: parent.width * 0.5
                    text: block.attr("fontFamily").val
                    onAccepted: {
                        if (text !== block.attr("fontFamily").val) {
                            block.attr("fontFamily").val = text
                        }
                    }
                    font.pixelSize: 16*dp
                    color: "white"
                    clip: true
                }
            }
            BlockRow {
                StretchText {
                    text: "Color:"
                }
                TextInput {
                    width: parent.width * 0.5
                    text: block.attr("color").val
                    onAccepted: {
                        if (text !== block.attr("color").val) {
                            block.attr("color").val = text
                        }
                    }
                    font.pixelSize: 16*dp
                    color: "white"
                    clip: true
                }
            }
            BlockRow {
                StretchText {
                    text: "Bold:"
                }
                AttributeCheckbox {
                    width: 30*dp
                    attr: block.attr("bold")
                }
            }
            BlockRow {
                StretchText {
                    text: "Underline:"
                }
                AttributeCheckbox {
                    width: 30*dp
                    attr: block.attr("underline")
                }
            }
            BlockRow {
                StretchText {
                    text: "Centered:"
                }
                AttributeCheckbox {
                    width: 30*dp
                    attr: block.attr("centered")
                }
            }
            BlockRow {
                StretchText {
                    text: "Shadow:"
                }
                AttributeCheckbox {
                    width: 30*dp
                    attr: block.attr("shadow")
                }
            }
            BlockRow {
                visible: block.attr("shadow").val
                leftMargin: 10*dp
                StretchText {
                    text: "Shadow Color:"
                }
                TextInput {
                    width: parent.width * 0.5
                    text: block.attr("shadowColor").val
                    onAccepted: {
                        if (text !== block.attr("shadowColor").val) {
                            block.attr("shadowColor").val = text
                        }
                    }
                    font.pixelSize: 16*dp
                    color: "white"
                    clip: true
                }
            }
        }
    }  // end Settings Component
}
