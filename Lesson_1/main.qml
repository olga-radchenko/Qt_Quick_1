import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

Window {
    id: window
    visible: true
    width: 400
    height: 300
    title: qsTr("Вычислитель площади треугольника")

    Image {
        id: image
        width: window.width
        height: window.height
        fillMode: Image.PreserveAspectCrop
        source: "qrc:geometry.jpg"
    }

    Rectangle {
        x:20
        y:20
        width: 360
        height: 260
        color: "white"
        opacity: 0.97

        ColumnLayout {
            id: columnLayout
            anchors.fill: parent
            spacing: 10

            Text {
                id: element
                width: 280
                height: 40
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                text: qsTr("Введите значения сторон треугольника для рассчета площади")
                horizontalAlignment: Text.AlignHCenter
                Layout.fillHeight: false
                Layout.fillWidth: true
                wrapMode: Text.WordWrap
                font.pixelSize: 14
            }

            Row {
                id: row
                width: 280
                height: 50
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 10

                GroupBox {
                    id: groupBox1
                    title: "a:"
                    width: 80
                    height: parent.height

                    TextEdit {
                        id: textEdit
                        property int maximumLength: 3
                        property string previousText: text

                        width: 60
                        height: parent.height
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                        renderType: Text.QtRendering
                        font.pixelSize: 12

                        onTextChanged: {
                            if (text.length > maximumLength) {
                                var cursor = cursorPosition;
                                text = previousText;
                                if (cursor > text.length) {
                                    cursorPosition = text.length;
                                } else {
                                    cursorPosition = cursor-1;
                                }
                            }
                            previousText = text
                        }
                    }
                }

                GroupBox {
                    id: groupBox2
                    title: "b:"
                    width: 80
                    height: parent.height

                    TextEdit {
                        id: textEdit1
                        property int maximumLength: 3
                        property string previousText: text

                        width: 60
                        height: parent.height
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: 12

                        onTextChanged: {
                            if (text.length > maximumLength) {
                                var cursor = cursorPosition;
                                text = previousText;
                                if (cursor > text.length) {
                                    cursorPosition = text.length;
                                } else {
                                    cursorPosition = cursor-1;
                                }
                            }
                            previousText = text
                        }
                    }
                }

                GroupBox {
                    id: groupBox3
                    title: "c:"
                    width: 80
                    height: parent.height

                    TextEdit {
                        id: textEdit2
                        property int maximumLength: 3
                        property string previousText: text

                        width: 60
                        height: parent.height
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: 12

                        onTextChanged: {
                            if (text.length > maximumLength) {
                                var cursor = cursorPosition;
                                text = previousText;
                                if (cursor > text.length) {
                                    cursorPosition = text.length;
                                } else {
                                    cursorPosition = cursor-1;
                                }
                            }
                            previousText = text
                        }
                    }
                }
            }

            Row {
                id: row1
                width: 280
                height: 120
                Layout.fillWidth: true
                spacing: 10
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                GroupBox {
                    id: groupBox
                    width: 160
                    title: "Результат:"
                    height: parent.height
                    anchors.centerIn: parent

                    ColumnLayout {
                        id: columnLayout1
                        width: groupBox.implicitLabelWidth
                        height: columnLayout.height/2
                        spacing: 0
                        anchors.fill: parent

                        TextEdit {
                            id: textEdit3
                            width: 80
                            height: columnLayout.height/3
                            activeFocusOnPress: false
                            readOnly: true
                            horizontalAlignment: Text.AlignHCenter
                            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                            Layout.fillWidth: true
                            font.pixelSize: 12
                        }

                        Button {
                            id: button
                            width: columnLayout.width
                            height: columnLayout.height/3
                            text: qsTr("Рассчитать")
                            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
                            Layout.fillHeight: false
                            Layout.fillWidth: true
                            onClicked: textEdit3.text = count()
                        }
                    }
                }
            }
        }
    }

    function count() {
        var a = Number(textEdit.text);
        var b = Number(textEdit1.text);
        var c = Number(textEdit2.text);
        var p = ((a+b+c)/2);
        var S = Math.sqrt(p*(p-a)*(p-b)*(p-c));
        if(isNaN(S))
            S = "Такого треугольника нет";
        return S;
    }
}




