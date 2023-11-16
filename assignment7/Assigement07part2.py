from abc import ABC, abstractmethod


# Shapes
class Shape(ABC):
    def __init__(self, formatter):
        self.formatter = formatter

    @abstractmethod
    def draw(self):
        pass


class Square(Shape):
    def __init__(self, formatter):
        super().__init__(formatter)

    def draw(self):
        self.formatter.drawLine(0, 0, 1, 1)
        self.formatter.drawLine(1, 1, 2, 2)


class Circle(Shape):
    def __init__(self, formatter):
        super().__init__(formatter)

    def draw(self):
        self.formatter.drawCircle(0, 0, 5)


# Formatters
class Screen:
    def drawLine(self, x1, y1, x2, y2):
        print(f"Drawing line on screen: ({x1}, {y1}) to ({x2}, {y2})")

    def drawCircle(self, x, y, radius):
        print(f"Drawing circle on screen: center({x}, {y}), radius={radius}")


class Printer:
    def drawLine(self, x1, y1, x2, y2):
        print(f"Printing line: ({x1}, {y1}) to ({x2}, {y2})")

    def drawCircle(self, x, y, radius):
        print(f"Printing circle: center({x}, {y}), radius={radius}")


if __name__ == "__main__":
    square = Square(Screen())
    square.draw()

    circle = Circle(Printer())
    circle.draw()

class Polygon(Shape):
  def __init__(self, formatter):
      super().__init__(formatter)

  def draw(self):
      self.formatter.drawLine(0, 0, 1, 1)
      self.formatter.drawLine(1, 1, 2, 2)
      self.formatter.drawLine(2, 2, 0, 0)


class XMLFormatter:
  def drawLine(self, x1, y1, x2, y2):
      print(f"<line x1='{x1}' y1='{y1}' x2='{x2}' y2='{y2}'/>")

  def drawCircle(self, x, y, radius):
      print(f"<circle cx='{x}' cy='{y}' r='{radius}'/>")


if __name__ == "__main__":
  polygon = Polygon(XMLFormatter())
  polygon.draw()

