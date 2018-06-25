import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component {
        id: delegate

        RowLayout {
            Label {
                text: brand
            }
            Label {
                text: model
            }
            Column {
                Repeater {
                    model: engines
                    Label {
                        text: modelData.horsepower + ' ' + modelData.torque
                    }
                }
            }
        }
    }

    ListView {
        id: mainList
        anchors.fill: parent
        model: myModel
        delegate: delegate
    }
}
