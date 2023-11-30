class Builder:
  def getWheel(self):
      pass

  def getContainer(self):
      pass

  def getBody(self):
      pass

class Wheel:
  def __init__(self, size=None):
      self.size = size

class Container:
  def __init__(self, volume=None):
      self.volume = volume

class Body:
  def __init__(self, shape=None):
      self.shape = shape

class Widget:
    def __init__(self):
        self.wheels = list()
        self.container = None
        self.body = None

    def attachWheel(self, wheel):
        self.wheels.append(wheel)

    def setContainerVolume(self, volume):
        self.container = volume

    def setBody(self, bodytype):
        self.body = bodytype

    @classmethod
    def create_widget(cls, builder):
        widget = cls()
        widget.attachWheel(builder.getWheel())
        widget.setContainerVolume(builder.getContainer())
        widget.setBody(builder.getBody())  # Corrected line
        return widget

class ConcreteBuilder1(Builder):
  def getWheel(self):
      wheel = Wheel(size=4)
      return wheel

  def getContainer(self):
      container = Container(volume=5)
      return container

  def getBody(self):
      body = Body(shape="bucket")
      return body

class ConcreteBuilder2(Builder):
  def getWheel(self):
      wheel = Wheel(size=2)
      return wheel

  def getContainer(self):
      container = Container(volume=3)
      return container

  def getBody(self):
      body = Body(shape="glass")
      return body

builder1 = ConcreteBuilder1()
widget1 = Widget.create_widget(builder1)
print("Widget 1:")
print("Wheels:", widget1.wheels[0].size)
print("Container Volume:", widget1.container.volume)
print("Body Type:", widget1.body.shape)
print()

builder2 = ConcreteBuilder2()
widget2 = Widget.create_widget(builder2)
print("Widget 2:")
print("Wheels:", widget2.wheels[0].size)
print("Container Volume:", widget2.container.volume)
print("Body Type:", widget2.body.shape)
