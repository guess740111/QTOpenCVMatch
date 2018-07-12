import QtQuick 2.9
import QtQuick.Window 2.2


Window {
    id: mainWin
    visible: true
    width: 800
    height: 730
    color: "#100202"
    title: qsTr("OpenCV Test")

    signal btClicked(int numberBT,string path)

    signal reWriteDisplayInfo(string str)

    function rewritedisplayinfo(str){
        displayinfo.text = str;
    }

    Component.onCompleted: {
        mainWin.reWriteDisplayInfo.connect( rewritedisplayinfo );
    }

    Row{
        id: row1
        spacing: 10
        height: 100

        IconBtItem{
            id: bt1
            default property string defaultText: mainui.IconPath["bt1"]
        }
        IconBtItem{
            id: bt2
            default property string defaultText: mainui.IconPath["bt2"]
        }
        IconBtItem{
            id: bt3
            default property string defaultText: mainui.IconPath["bt3"]
        }
        IconBtItem{
            id: bt4
            default property string defaultText: mainui.IconPath["bt4"]
        }
        IconBtItem{
            id: bt5
            default property string defaultText: mainui.IconPath["bt5"]
        }
        IconBtItem{
            id: bt6
            default property string defaultText: mainui.IconPath["bt6"]
        }
        IconBtItem{
            id: bt7
            default property string defaultText: mainui.IconPath["bt7"]
        }
        IconBtItem{
            id: bt8
            default property string defaultText: mainui.IconPath["bt8"]
        }
        IconBtItem{
            id: bt9
            default property string defaultText: mainui.IconPath["bt9"]
        }
        IconBtItem{
            id: bt10
            default property string defaultText: mainui.IconPath["bt10"]
        }
    }
    Rectangle {
        id: mainrectangle
        anchors.top: row1.bottom
        anchors.topMargin: 15

        width: 800
        height: 570
        Image{
            id: img
            anchors.fill: parent
            source: "file:/"+mainui.IconPath["source"]
            Connections{
                target: mainui
                onCallQmlRefeshImg:{
                    img.source = "image://CodeImg/"+ Math.random()
                }
            }
        }
    }
    Text {
        id: displayinfo
        height: 30
        color: "#ffffff"
        text: ""
        font.pointSize: 12
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.top: mainrectangle.bottom
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
    }
}