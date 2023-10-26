import pandas

def readData(filename):
    df = pandas.read_csv(filename, header=None, names=['x', 'y'])
    data = list(zip(df['x'], df['y']))
    return data

def checkPointPosition(x, y, z):
    a = y[1] - x[1]
    b = x[0] - y[0]
    c = x[0] * y[1] - y[0] * x[1]
    result = a * z[0] + b * z[1] - c
    return result

def convex_hull(points):
    hull = []
    for i in range(len(points)):
        for j in range(i + 1, len(points)):
            above, below = [], []
            for k in range(len(points)):
                if k != i and k != j:
                    orientation = checkPointPosition(points[i], points[j], points[k])
                    if orientation == 0:
                        continue
                    if orientation > 0:
                        above.append(points[k])
                    else:
                        below.append(points[k])
            if not above or not below:
                if points[i] not in hull:
                    hull.append(points[i])
                if points[j] not in hull:
                    hull.append(points[j])

    return hull

filename = 'e2p2data.csv'
dataList = readData(filename)
convex_hull_points = convex_hull(dataList)

print("Convex Hull Points:")
for x, y in convex_hull_points:
    print(f"({x}, {y})")
