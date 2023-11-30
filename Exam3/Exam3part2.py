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

class Builder:
  def getWheel(self):
      pass

  def getContainer(self):
      pass

  def getBody(self):
      pass

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

# Example usage:
builder1 = ConcreteBuilder1()
widget1 = Widget()
widget1.attachWheel(builder1.getWheel())
widget1.setContainerVolume(builder1.getContainer())
widget1.setBody(builder1.getBody())

builder2 = ConcreteBuilder2()
widget2 = Widget()
widget2.attachWheel(builder2.getWheel())
widget2.setContainerVolume(builder2.getContainer())
widget2.setBody(builder2.getBody())
