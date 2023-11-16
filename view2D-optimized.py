#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np
from time import sleep
import matplotlib.patches as patches

ccolor = ['k', 'r', 'g']

# Data for plotting
with open("view2D.dat") as f:
    data = f.readlines()

# Extract simulation parameters from the first line of the file
iterations, npeople, x_As, x_Bs, y_As, y_Bs, r_circle = data[0].split("\t")
x_A = float(x_As)
x_B = float(x_Bs)
y_A = float(y_As)
y_B = float(y_Bs)
r_circle = float(r_circle)

iterations = iterations[1:]
npeople = int(npeople)
iterations = int(iterations)

# Create empty lists to store the positions and colors of each person
X = [[] for _ in range(npeople)]
Y = [[] for _ in range(npeople)]
C = [[] for _ in range(npeople)]

# Create a figure and axis object for plotting
fig, ax = plt.subplots()
iterator = 0

# Loop through each line of the data file
for line in data[1:]:
    # If the line starts with a "#" character, it contains simulation statistics
    if "#" in line[0]:
        iteration, healty,sick,immune,dead = line.split("\t")
        iteration=int(iteration[1:])
        plt.cla()
        ax.set(xlabel='x', ylabel='y',
                title='TICS UNAM Transmission')
        plt.axis([x_A, x_B,  y_A, y_B])        
        ax.grid()
        iterator = 0
    # Otherwise, the line contains information about a person's position and status
    else:
        age, gender, status, time_recovery, position, velocity = line.split("\t")
        position = position[1:-2]
        x,y = position.split(",")
        x = float(x)
        y=float(y)
        c=int(status)
        circle = plt.Circle((x, y), r_circle, color=ccolor[c])
        ax.add_artist(circle)
        iterator = iterator + 1

    # If we have plotted all the people for this iteration, add a legend and save the figure
    if (iterator == npeople):
        rect = patches.Rectangle((-47,-42),24,24,color='k',alpha=0.2,fill=True)
        ax.add_patch(rect)
        plt.text(-45,-25, "Healty: "+healty , fontsize=12)
        plt.text(-45,-30, "Sick: "+sick, fontsize=12,color='r')
        plt.text(-45,-35, "Immune: "+immune, fontsize=12,color='g')
        plt.text(-45,-45, "Dead: "+dead,color='b', fontsize=12)        
        plt.draw()
        fig.savefig("animation3/"+("%04d"%iteration)+"-view2D.png")
