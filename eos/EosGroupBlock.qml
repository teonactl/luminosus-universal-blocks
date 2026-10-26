import QtQuick 2.5
import CustomElements 1.0
import "qrc:/core/ui/items"
import "qrc:/core/ui/controls"

BlockBase {
    id: root
    width: 70*dp
    height: 60*dp
    settingsComponent: settings

    StretchColumn {
        anchors.fill: parent

        NumericInput {
            centered: true
            minimumValue: 1
            maximumValue: 9999
            value: block.groupNumber
            onValueChanged: {
                if (value !== block.groupNumber) {
                    block.groupNumber = value
                }
            }
        }

        DragArea {
            text: "Group"
            InputNode {
                node: block.node("inputNode")
            }
        }
    }  // end main Column

    Component {
        id: settings
        StretchColumn {
            leftMargin: 15*dp
            rightMargin: 15*dp
            defaultSize: 30*dp

            BlockRow {
                Text {
                    text: "Group Number:"
                    width: parent.width - 40*dp
                }
                NumericInput {
                    width: 40*dp
                    minimumValue: 1
                    maximumValue: 9999
                    value: block.groupNumber
                    onValueChanged: {
                        if (value !== block.groupNumber) {
                            block.groupNumber = value
                        }
                    }
                }
            }
        }
    }  // end Settings Component
}

