import QtQuick 2.3

Item {
  width: 600
  height: 800

  Text {
    x: 30
    y: 5
    wrapMode: Text.WordWrap
    text: "Click entries in the list, then click the red square to remove it.\n\nWhile it fades out, click it.\n\nThe interaction causes bindings to be re-evaluated, and artifacts to be created."
  }

  FruitModel {
    id: fruitModel1
  }

  MyListView {
    x: 30
    y: 100
    width: 250
    height: 300

    model: fruitModel1

    onRemoveClicked: {
      if (modelIndex >= 0)
        fruitModel1.remove(modelIndex)
    }
  }

  FruitModel {
    id: fruitModel2
  }

  Text {
    x: 30
    y: 350
    wrapMode: Text.WordWrap
    text: "Anything can cause a binding to be evaluated while it is being deleted.\n\nBelow an animation on a 'global' pulse causes it."
  }

  MyListView {
    x: 30
    y: 410
    width: 250
    height: 300

    colorFromModel: true

    SequentialAnimation on delegateColorFactor {
        id: anim
        loops: Animation.Infinite
        property real duration: 2000
        property real from: 0.5
        property real to: 1
        NumberAnimation {
          from: anim.from
          to: anim.to
          duration: anim.duration / 2
        }
        NumberAnimation {
          from: anim.to
          to: anim.from
          duration: anim.duration / 2
        }
    }

    model: fruitModel2

    onRemoveClicked: {
      if (modelIndex >= 0)
        fruitModel2.remove(modelIndex)
    }
  }
}
