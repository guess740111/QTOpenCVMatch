import QtQuick 2.0

Rectangle {
    width: 60
    height: 60
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

