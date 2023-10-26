def checkPointPosition(x, y, z):
  a = y[1] - x[1]
  b = x[0] - y[0]
  c = x[0] * y[1] - y[0] * x[1]

  result = a * z[0] + b * z[1] - c

  return result

# Example usage:
x = (1, 2)
y = (3, 4)
z = (5, 6)

result = checkPointPosition(x, y, z)

if result > 0:
  print("The point is above or to the left of the line.")
elif result < 0:
  print("The point is below or to the right of the line.")
else:
  print("The point is on the line.")
