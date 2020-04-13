#!/usr/bin/env python3

import matplotlib
import matplotlib.pyplot as plt
import numpy as np
from time import sleep


# Data for plotting

#t = np.arange(0.0, 2.0, 0.01)
#s = 1 + np.sin(2 * np.pi * t)

with open("view2D.dat") as f:
    data = f.readlines()

iterations, npeople = data[0].split("\t")
iterations = iterations[1:]

npeople = int(npeople)
iterations = int(iterations)

X = [[] for x in range(npeople)]
Y = [[] for x in range(npeople)]

fig, ax = plt.subplots()


iterator = 0

for line in data:
    if not "#" in line[0]:        
        age, gender, status, time_recovery, position, velocity = line.split("\t")

        position = position[1:-2]
        print(position)
        x,y = position.split(",")
        x = float(x)
        y=float(y)
        print(iterator)
        X[iterator].append(x)
        Y[iterator].append(y)
        if iterator == npeople-1:
            iterator = 0
        else:
            iterator = iterator+1

ax.set(xlabel='x', ylabel='y',
       title='view2D')
plt.axis([-10, 10, -10, 10])


ax.grid()


for b in range(len(X[0])):   
    for u,v in zip(X,Y):
        ax.plot(u[:b], v[:b],'ko-')
    plt.pause(1.0)

    
fig.savefig("view2D.png")
plt.show()


