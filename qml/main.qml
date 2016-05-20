import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.5
//import ulan.treeviewmodel 1.0
import QtQml.Models 2.2
//import QtQuick.Layouts 1.1

ApplicationWindow {
    visible: true
    id: itemWindow

    //flags:    Qt.Window | Qt.CustomizeWindowHint
    width: 1000
    height: 600
    minimumWidth: 800
    minimumHeight: 480

    title: qsTr("板卡测试工具")

/*
    menuBar: MenuBar {
        Menu {
            title: qsTr("文件")
            MenuItem {

                text: qsTr("导入板卡信息")
                onTriggered: Qt.quit();
            }
            MenuItem {
                text: qsTr("退出")
                onTriggered: Qt.quit();
            }
        }
        Menu {
            title: qsTr("设置")
            MenuItem {
                text: qsTr("导入板卡信息")
                onTriggered: Qt.quit();
            }
        }
    }
*/
/*
    Grid {
        id: indicator
        anchors.margins: 8
        spacing: 4
        rows: 2

        Repeater {
            model: 16
            Rectangle {
                width: 10; height: 10
                color: 'blue'
                border.color: Qt.lighter(color)
            }
        }
    }
*/
/*
    ListView {
        model: treeViewModel

        delegate: Text {
            text: display
        }
    }
    */

    /*
    //标题
    Rectangle {
        id: itemTitle

        height: 30
        anchors.top: windowTop
        anchors.left: parent.left
        anchors.right: parent.right

        color: "#56955b"
    }*/

    TreeView {
        id: itemTreeView
        model: treeViewModel

        anchors.top: parent.top
        anchors.bottom: parent.bottom

        itemDelegate: Item {
            CheckBox {
                 id: itemCheckBox

                 checked: model["checkBoxRole"]
                 text: styleData.value    //styleData.value默认代表rolename 为display的值
                 onCheckedChanged: {
                     model["checkBoxRole"] = itemCheckBox.checked
                 }
            }
        }

        headerDelegate: Item {
            height: 30
            Text {
                id: name
                text: '显示当前选中的信息'
            }
        }

        sortIndicatorColumn: 5
        sortIndicatorVisible: true

        TableViewColumn {
            title: '连接列表'
            role: 'textRole'
            resizable: false
        }
    }

    //显示测试结果
    Rectangle {
        id: itemPresentation

        anchors.top: parent.top
        anchors.left: itemTreeView.right
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 200

        color: 'lightblue'
    }

    //控制区域
    Rectangle {
        id: itemControlPanel

        anchors.top: itemPresentation.bottom
        anchors.left: itemTreeView.right
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        color: 'lightgray'

        Button {
            id: buttonRefresh

            width: 50
            height: 30
            anchors.centerIn: parent

            text: '刷新'
        }
    }
}
