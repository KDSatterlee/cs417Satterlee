class Square:
  def __init__(self, number, length, center):
      self.number = number
      self.length = length
      self.center = center

  def __str__(self):
      return f"({self.number}, {self.center}, {self.length})"


class Command:
  def execute(self):
      pass

  def undo(self):
      pass


class CreateCommand(Command):
  def __init__(self, squares, number, length):
      self.squares = squares
      self.number = number
      self.length = length
      self.square = None

  def execute(self):
      center = (0, 0)  # Assume centered at the origin
      self.square = Square(self.number, self.length, center)
      self.squares.append(self.square)

  def undo(self):
      self.squares.remove(self.square)


class MoveCommand(Command):
  def __init__(self, square, new_center):
      self.square = square
      self.new_center = new_center
      self.old_center = None

  def execute(self):
      self.old_center = self.square.center
      self.square.center = self.new_center

  def undo(self):
      self.square.center = self.old_center


class ScaleCommand(Command):
  def __init__(self, square, factor):
      self.square = square
      self.factor = factor

  def execute(self):
      self.square.length *= self.factor

  def undo(self):
      self.square.length /= self.factor


class CommandProcessor:
  def __init__(self):
      self.squares = []
      self.history = []

  def process_command(self, command_str):
      parts = command_str.split()
      command_type = parts[0]

      if command_type == 'C':
          number, length = map(int, parts[1:3])
          command = CreateCommand(self.squares, number, length)
      elif command_type == 'M':
          number, new_center = map(int, parts[1:4]), map(int, parts[4:])
          square = next(sq for sq in self.squares if sq.number == number)
          command = MoveCommand(square, new_center)
      elif command_type == 'S':
          number, factor = map(int, parts[1:3])
          square = next(sq for sq in self.squares if sq.number == number)
          command = ScaleCommand(square, factor)
      elif command_type == 'U':
          command = self.history.pop()
          command.undo()
      elif command_type == 'R':
          if self.history:
              command = self.history[-1]
              command.execute()
              self.history.append(command)
      elif command_type == 'P':
          for square in self.squares:
              print(square)
          return
      elif command_type == 'X':
          exit()

      command.execute()
      self.history.append(command)


if __name__ == "__main__":
  processor = CommandProcessor()

  while True:
      command_str = input("Enter a command: ")
      processor.process_command(command_str)
