#https://realpython.com/python-csv/#:~:text=Reading%20CSV%20files%20is%20possible,easy%20to%20use%20data%20structures.

import pandas 

def readData(filename):
    
    df = pandas.read_csv(filename, header=None, names=['x', 'y'])
    data = list(zip(df['x'], df['y']))
    return data

# Example usage:
filename = 'e2p2data.csv'
dataList = readData(filename)


print("List of Coordinates:")
for x, y in dataList:
    print(f"({x}, {y})")