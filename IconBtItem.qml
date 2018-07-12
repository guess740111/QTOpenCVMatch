import QtQuick 2.0

Rectangle {
    width: parent.width/10 -10
    height: parent.height
    Image{
        anchors.fill: parent
        source: "file:/"+defaultText
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            mainWin.btClicked(1,defaultText);
        }
    }
}

