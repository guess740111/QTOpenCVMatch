import QtQuick 2.0

Rectangle {
    width: parent.width/10 -10
    height: parent.height
    Image{
        anchors.fill: parent
        source: "file:/"+mainui.IconPath["DeskPath"]+"/image/"+number+".jpg"
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            mainWin.btClicked(number,mainui.IconPath["DeskPath"]+"/image/"+number+".jpg");
        }
    }
}

