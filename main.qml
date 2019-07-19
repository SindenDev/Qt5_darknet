import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtMultimedia 5.0
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.0
import com.amin.classes 1.0

Window {
    id : window
    visible: true
    width: 800
    height: 600
    color: "#2b2626"
    title: qsTr("Face Detection")

    property string cfg_batch: "0"
    property string cfg_subdivisions: ""
    property string cfg_width: ""
    property string cfg_height: ""
    property string cfg_channels: ""
    property string cfg_momentum: ""
    property string cfg_decay: ""
    property string cfg_angle: ""
    property string cfg_saturation: "5"
    property string cfg_exposure: ""
    property string cfg_hue: ""
    property string cfg_learning_rate: ""
    property string cfg_burn_in: ""
    property string cfg_max_batches: ""
    property string cfg_policy: ""
    property string cfg_steps: ""
    property string cfg_scales: ""

    //Cfg 설정값을 cfg_editor 로 전송하는 데 쓰이는 시그널
    signal sigCfg(string cfg_batch,
                  string cfg_subdivisions,
                  string cfg_width ,
                  string cfg_height,
                  string cfg_channels,
                  string cfg_momentum,
                  string cfg_decay,
                  string cfg_angle,
                  string cfg_saturation,
                  string cfg_exposure,
                  string cfg_hue,
                  string cfg_learning_rate,
                  string cfg_burn_in,
                  string cfg_max_batches,
                  string cfg_policy,
                  string cfg_steps,
                  string cfg_scales);

    //cfg_editor 에서 설정한 cfg 값을 mainwindow 로 전송해오는 시그널
    signal sigSaveCfg(string cfg_batch,
                      string cfg_subdivisions,
                      string cfg_width ,
                      string cfg_height,
                      string cfg_channels,
                      string cfg_momentum,
                      string cfg_decay,
                      string cfg_angle,
                      string c널fg_saturation,
                      string cfg_exposure,
                      string cfg_hue,
                      string cfg_learning_rate,
                      string cfg_burn_in,
                      string cfg_max_batches,
                      string cfg_policy,
                      string cfg_steps,
                      string cfg_scales);

    Connections{

        target: window

        //cfg_editor 에서 시그널을 보내면 cfgproperty에 값들을 저장한뒤 SaveCfgFile 함수를 이용해 실제 cfg 에 저장한다.
        onSigSaveCfg:{
            cfgproperty.select_num = 1
            cfgproperty.cfgValue = cfg_batch
            cfgproperty.select_num = 2
            cfgproperty.cfgValue = cfg_subdivisions
            cfgproperty.select_num = 3
            cfgproperty.cfgValue = cfg_width
            cfgproperty.select_num = 4
            cfgproperty.cfgValue = cfg_height
            cfgproperty.select_num = 5
            cfgproperty.cfgValue = cfg_channels
            cfgproperty.select_num = 6
            cfgproperty.cfgValue = cfg_momentum
            cfgproperty.select_num = 7
            cfgproperty.cfgValue = cfg_decay
            cfgproperty.select_num = 8
            cfgproperty.cfgValue = cfg_angle
            cfgproperty.select_num = 9
            cfgproperty.cfgValue = cfg_saturation
            cfgproperty.select_num = 10
            cfgproperty.cfgValue = cfg_exposure
            cfgproperty.select_num = 11
            cfgproperty.cfgValue = cfg_hue
            cfgproperty.select_num = 12
            cfgproperty.cfgValue = cfg_learning_rate
            cfgproperty.select_num = 13
            cfgproperty.cfgValue = cfg_burn_in
            cfgproperty.select_num = 14
            cfgproperty.cfgValue = cfg_max_batches
            cfgproperty.select_num = 15
            cfgproperty.cfgValue = cfg_policy
            cfgproperty.select_num = 16
            cfgproperty.cfgValue = cfg_steps
            cfgproperty.select_num = 17
            cfgproperty.cfgValue = cfg_scales
            cfgproperty.SaveCfgFile();
        }
    }


    CvDetectFilter
    {
        id: testFilter
    }

    MediaPlayer{
        id:videoPlayer
        //                source: "rtsp://admin:1234@222.105.216.252:9154/h264"
        source : "file:///home/goback/다운로드/city.mp4"
        autoPlay: true
    }

    ColumnLayout {
        id: colLayout
        width: window.width
        height: window.height
        anchors.fill: parent
        spacing: 0


        Rectangle {
            id: rectangle
            width: colLayout.width
            height: 200
            color: "#221818"
            Layout.fillHeight: true
            Layout.fillWidth: true

            VideoOutput
            {
                id: video
                anchors.fill: parent
                // - rowLayout.height

                //autoOrientation: false

                source: videoPlayer

                filters: []
            }
        }

        ColumnLayout {
            id: columnLayout
            width: window.width
            height: 100
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter


            RowLayout {
                id: rowLayout1
                width: columnLayout.width
                height: 100
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter


                RoundButton {
                    id: pauseButton
                    text: ""
                    font.capitalization: Font.MixedCase
                    wheelEnabled: false
                    spacing: 5
                    focusPolicy: Qt.StrongFocus
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    //                    background:Image{
                    //                            source: "file:///home/goback/다운로드/pngtree-pause-vector-icon-png-image_470715.jpg"
                    //                        }
                    onClicked: videoPlayer.pause()

                }
                RoundButton {
                    id: playButton
                    text: "\u25b6"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    focusPolicy: Qt.StrongFocus
                    onClicked:
                    {
                        videoPlayer.seek(videoPlayer.position + 5000)
                        videoPlayer.play()
                    }
                }

                Timer{
                    interval: 500;running:true;repeat: true
                    onTriggered: {
                        slider.value = videoPlayer.position
                    }
                }

                Slider {
                    id: slider
                    to:videoPlayer.duration
                    value: 0
//                    moved: {playButton.text = "asdf"}
                    onMoved: {
                        videoPlayer.seek(videoPlayer.position + (slider.value-videoPlayer.position))
                    }
                }

            }
            RowLayout {
                id: rowLayout
                width: window.width
                height: 150
                spacing: 15
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                transformOrigin: Item.Center


                Button {
                    id: button
                    text: qsTr("필터 on")
                    font.family: "Courier"
                    background: Rectangle{
                        color: "gray"
                    }
                    spacing: 6
                    focusPolicy: Qt.WheelFocus
                    onClicked: video.filters=[testFilter]
                }

                Button {
                    id: button1
                    text: qsTr("필터 off")
                    font.family: "Courier"
                    background: Rectangle{
                        color: "gray"
                    }
                    focusPolicy: Qt.StrongFocus
                    onClicked: {
                        video.filters = []
                    }
                }
                Button {
                    id: button3
                    text: qsTr("cfg 파일 변경")
                    font.family: "Courier"
                    background: Rectangle{
                        color: "gray"
                    }
                    onClicked: {
                        cfgproperty.select_num = 1
                        cfg_batch=cfgproperty.cfgValue
                        cfgproperty.select_num = 2
                        cfg_subdivisions=cfgproperty.cfgValue
                        cfgproperty.select_num = 3
                        cfg_width=cfgproperty.cfgValue
                        cfgproperty.select_num = 4
                        cfg_height=cfgproperty.cfgValue
                        cfgproperty.select_num = 5
                        cfg_channels=cfgproperty.cfgValue
                        cfgproperty.select_num = 6
                        cfg_momentum=cfgproperty.cfgValue
                        cfgproperty.select_num = 7
                        cfg_decay=cfgproperty.cfgValue
                        cfgproperty.select_num = 8
                        cfg_angle=cfgproperty.cfgValue
                        cfgproperty.select_num = 9
                        cfg_saturation=cfgproperty.cfgValue
                        cfgproperty.select_num = 10
                        cfg_exposure=cfgproperty.cfgValue
                        cfgproperty.select_num = 11
                        cfg_hue=cfgproperty.cfgValue
                        cfgproperty.select_num = 12
                        cfg_learning_rate=cfgproperty.cfgValue
                        cfgproperty.select_num = 13
                        cfg_burn_in=cfgproperty.cfgValue
                        cfgproperty.select_num = 14
                        cfg_max_batches=cfgproperty.cfgValue
                        cfgproperty.select_num = 15
                        cfg_policy=cfgproperty.cfgValue
                        cfgproperty.select_num = 16
                        cfg_steps=cfgproperty.cfgValue
                        cfgproperty.select_num = 17
                        cfg_scales=cfgproperty.cfgValue


                        //cfgproperty.SaveCfgFile();

                        var component = Qt.createComponent("cfg_editor.qml")
                        var cfgwindow = component.createObject(cfgwindow)
                        cfgwindow.show()

                        sigCfg(cfg_batch,
                               cfg_subdivisions,
                               cfg_width ,
                               cfg_height ,
                               cfg_channels,
                               cfg_momentum,
                               cfg_decay,
                               cfg_angle,
                               cfg_saturation ,
                               cfg_exposure,
                               cfg_hue,
                               cfg_learning_rate,
                               cfg_burn_in,
                               cfg_max_batches,
                               cfg_policy,
                               cfg_steps,
                               cfg_scales);
                    }
                }

                Button {
                    id: button2
                    text: qsTr("종료")
                    enabled: true
                    font.family: "Courier"
                    onClicked: Qt.quit()
                    background: Rectangle{
                        color: "gray"
                    }
                }
                //                FileDialog{
                //                    id: fileDialog
                //                    title: "Please"
                //                    folder: shortcuts.home
                //                    onAccepted: {

                //                    }
                //                    onRejected: {

                //                    }
                //                    Component.onCompleted: visible=true
                //                }
            }
        }

    }


    Component.onCompleted: {
        Qt.quit()
    }


}
