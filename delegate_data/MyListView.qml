import QtQuick 2.4

ListView {
  id: root

  signal removeClicked(int modelIndex)

  property var delegateColorFactor

  property bool colorFromModel

  spacing: 3

  Component.onCompleted: {
    if (delegateColorFactor === undefined)
      delegateColorFactor = 1
  }

  delegate: Rectangle {
    id: theDelegate
    height: 30
    width: 250

    property var delegateR
    property var delegateG
    property var delegateB

    Component.onCompleted: {
      delegateR = Math.random()
      delegateG = Math.random()
      delegateB = Math.random()
    }

    // Storing this in the delegate is bad but that is not relevant
    // to this testcase
    property int clickAmount

    color: colorFromModel ?
        Qt.lighter(model.color, root.delegateColorFactor)
      : Qt.rgba(delegateR, delegateG, delegateB, root.delegateColorFactor)

    Text {
      anchors.centerIn: parent
      text: model.display + " was clicked " + theDelegate.clickAmount + " times"
    }

    MouseArea {
      anchors.fill: parent
      onClicked: {
        ++theDelegate.clickAmount;
      }
    }

    Rectangle {
      anchors.right: parent.right
      width: 30
      height: 30
      color: "red"
      MouseArea {
        anchors.fill: parent
        onClicked: {
          removeClicked(model.index)
        }
      }
    }
  }

  removeDisplaced: Transition {
    SequentialAnimation {
      PauseAnimation { duration: 3000 }
      NumberAnimation { properties: "x,y"; duration: 1000 }
    }
  }

  remove: Transition {
    ParallelAnimation {
      NumberAnimation { property: "opacity"; to: 0; duration: 4000 }
      NumberAnimation { properties: "x"; to: 100; duration: 4000 }
    }
  }
}
