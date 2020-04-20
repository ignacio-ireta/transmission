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

iterations, npeople, x_As, x_Bs, y_As, y_Bs = data[0].split("\t")
x_A = float(x_As)
x_B = float(x_Bs)
y_A = float(y_As)
y_B = float(y_Bs)


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
plt.axis([x_A, x_B,  y_A, y_B])


ax.grid()

#n = 0
for b in range(len(X[0])):   
    plt.cla()
    ax.set(xlabel='x', ylabel='y',
           title='view2D')
    plt.axis([x_A, x_B,  y_A, y_B])        
    ax.grid()
    
    for u,v in zip(X,Y):
        #if n>1:
        #    ax.plot(u[:b-1], v[:b-1],'ro')
        #n=n+1
        ax.plot(u[b-1:b], v[b-1:b],'ko')
    plt.pause(0.1)

    
fig.savefig("view2D.png")
plt.show()


