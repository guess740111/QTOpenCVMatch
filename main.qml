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

    signal newInfo(string str)

    function newinfo(str){
        displayinfo.text = str;
    }

    Component.onCompleted: {
        mainWin.newInfo.connect( newinfo );
    }

    Row{
        id: row1
        spacing: 10
        height: parent.height/8
        width: parent.width
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        IconBtItem{
            id: bt1
            property int number: 1
        }
        IconBtItem{
            id: bt2
            property int number: 2
        }
        IconBtItem{
            id: bt3
            property int number: 3
        }
        IconBtItem{
            id: bt4
            property int number: 4
        }
        IconBtItem{
            id: bt5
            property int number: 5
        }
        IconBtItem{
            id: bt6
            property int number: 6
        }
        IconBtItem{
            id: bt7
            property int number: 7
        }
        IconBtItem{
            id: bt8
            property int number: 8
        }
        IconBtItem{
            id: bt9
            property int number: 9
        }
        IconBtItem{
            id: bt10
            property int number: 10
        }
    }
    Rectangle {
        id: mainrectangle
        anchors.top: row1.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.right: parent.right
        width: parent.width
        height: (parent.height/8)*6 -5
        Rectangle{
            id: rec1
            width: parent.width/2
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            Image{
                id: img1
                anchors.fill: parent
                source: "file:/"+mainui.IconPath["source"]
//                source: "image://videoCapture/hoge"
                Connections{
                    target: mainui
                    onCallQmlRefeshImg:{
                        img1.source = "image://CodeImg/"+ Math.random()
                    }
                }
            }
        }
        Rectangle{
            id: rec2
            width: parent.width/2
            anchors.left: rec1.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            Image{
                id: img
                anchors.fill: parent
                source: "image://videoCapture/hoge"
            }
            Timer {
                interval: 100
                running: true
                repeat: true
                onTriggered:  {
                    if (img.status === Image.Ready) {
                        img.source = "image://videoCapture/" + Math.random()
                    }
                }
            }
        }

    }
    Text {
        id: displayinfo
        height: parent.height/8
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
//        Rectangle{
//            id: buttonid1
//            width: 100
//            height: parent.height
//            anchors.top: parent.top
//            anchors.topMargin: 15
//            anchors.bottom: parent.bottom
//            anchors.bottomMargin: 15
//            anchors.right: parent.right
//            anchors.rightMargin: 15
//            color: "#A084c1ff"
//            radius: 20
//            border.color: "white"
//            border.width: 2
//            Text {
//                id: name
//                text: qsTr("學習")
//                verticalAlignment: Text.AlignVCenter
//                horizontalAlignment: Text.AlignHCenter
//                anchors.fill: parent
//                color: "red"
//                font.pointSize: 14
//                MouseArea{
//                    anchors.fill: parent
//                    onClicked: {
//                        buttonid1.color = "#A084c1ff"
//                    }
//                }
//            }
//        }
    }
}
