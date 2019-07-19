import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3

Window{

    id : cfg

    title: "cfg_editor"

    width: 575
    height: 360

    signal sigSteps(string cfg_steps);

    Connections{
        target : window

        onSigCfg:{
            batchField.text = cfg_batch
            subdivisionField.text = cfg_subdivisions
            widthField.text = cfg_width
            heightField.text = cfg_height
            channelsField.text = cfg_channels
            momentumField.text = cfg_momentum
            decayField.text = cfg_decay
            angleField.text = cfg_angle
            saturationField.text = cfg_saturation
            exposureField.text = cfg_exposure
            hueField.text = cfg_hue
            learningrateField.text = cfg_learning_rate
            burninField.text = cfg_burn_in
            maxbatchesField.text = cfg_max_batches
            policyField.text = cfg_policy
            stepsField.text = cfg_steps
            scalesField.text = cfg_scales
        }
    }

    Rectangle {
        id: rectangle1
        width: cfg.width - rectangle2.width
        height: cfg.height
        color: "#ffffff"

        Rectangle {
            id: textSet1
            y: rectangle1.height /9 *0
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"

            TextField{
                id : batchField
                width: 100
                height: 30
                text: ""
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: batchText
                width: 100
                text: "batch"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
            }

        }

        Rectangle {
            id: textSet2
            x: rectangle1.width/2
            y: rectangle1.height /9 *0
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: exposureField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: exposureText
                width: 100
                text: "exposure"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }

        Rectangle {
            id: textSet3
            x: 0
            y: rectangle1.height / 9 * 1
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: subdivisionField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: subdivisionText
                width: 100
                text: "subdivisions"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }

        Rectangle {
            id: textSet4
            x: rectangle1.width/2
            y: rectangle1.height/9*1
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: hueField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: hueText
                width: 100
                text: "hue"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }

        Rectangle {
            id: textSet5
            x: 0
            y: rectangle1.height/9 * 2
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: widthField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: widthText
                width: 100
                text: "width"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }

        Rectangle {
            id: textSet6
            x: rectangle1.width / 2
            y: rectangle1.height / 9 *2
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: learningrateField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: learningrateText
                width: 100
                text: "learning_rate"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }

        Rectangle {
            id: textSet7
            x: 0
            y: rectangle1.height/9 * 3
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: heightField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: heightText
                width: 100
                text: "height"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }

        Rectangle {
            id: textSet8
            x: rectangle1.width / 2
            y: rectangle1.height / 9 *3
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: burninField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: burninText
                width: 100
                text: "burn_in"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }

        Rectangle {
            id: textSet9
            x: 0
            y: rectangle1.height/9 * 4
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: channelsField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: channelsText
                width: 100
                text: "channels"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }

        Rectangle {
            id: textSet10
            x: rectangle1.width / 2
            y: rectangle1.height / 9 *4
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: maxbatchesField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: maxbatchesText
                width: 100
                text: "max_batches"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }
        Rectangle {
            id: textSet11
            x: 0
            y: rectangle1.height/9 * 5
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: momentumField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: momentumText
                width: 100
                text: "momentum"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }

        Rectangle {
            id: textSet12
            x: rectangle1.width / 2
            y: rectangle1.height / 9 *5
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: policyField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: policyText
                width: 100
                text: "policy"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }
        Rectangle {
            id: textSet13
            x: 0
            y: rectangle1.height/9 * 6
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: decayField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: decayText
                width: 100
                text: "decay"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }

        Rectangle {
            id: textSet14
            x: rectangle1.width / 2
            y: rectangle1.height / 9 *6
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: stepsField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: stepsText
                width: 100
                text: "steps"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }

        Rectangle {
            id: textSet15
            x: 0
            y: rectangle1.height/9 * 7
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: angleField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: angleText
                width: 100
                text: "angle"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }

        Rectangle {
            id: textSet16
            x: rectangle1.width / 2
            y: rectangle1.height / 9 *7
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: scalesField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: scalesText
                width: 100
                text: "batch"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }

        Rectangle {
            id: textSet17
            x: 0
            y: rectangle1.height/9 * 8
            width: rectangle1.width/2
            height: rectangle1.height / 9
            color: "#ffffff"
            TextField {
                id: saturationField
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

            Text {
                id: saturationText
                width: 100
                text: "saturation"
                anchors.topMargin: 0
                horizontalAlignment: Text.AlignRight
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.bottomMargin: 0
            }
        }
    }

    Rectangle {
        id: rectangle2
        x: rectangle1.width
        width: 125
        height: cfg.height
        color: "#ffffff"

        Button {
            id: save_btn
            text: qsTr("저장")
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10

            onClicked: {
                window.sigSaveCfg(batchField.text,
                           subdivisionField.text,
                           widthField.text,
                           heightField.text,
                           channelsField.text,
                           momentumField.text,
                           decayField.text,
                           angleField.text,
                           saturationField.text,
                           exposureField.text,
                           hueField.text,
                           learningrateField.text,
                           burninField.text,
                           maxbatchesField.text,
                           policyField.text,
                           stepsField.text,
                           scalesField.text)
                sigSteps(stepsField.text);
                cfg.close()
            }
        }

        Button {
            id: quit_btn
            x: -1
            y: -6
            text: qsTr("취소")
            anchors.topMargin: 70
            anchors.right: parent.right
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.rightMargin: 10

            onClicked: cfg.close()
        }
    }

}
