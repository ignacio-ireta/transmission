# Libraries and modules
import matplotlib.pyplot as plt
import numpy

data_path = '../data/'

healthy_particles  = []
infected_particles = []

with open(data_path + 'closed_border.dat', 'r') as f:
    lines = f.readlines()

num_iterations = int(lines[0].split()[1])
num_particles  = int(lines[0].split()[2])

for line in lines[1:]:
    if '#' in line:
        healthy = int(line.split()[2])

        healthy_particles.append(healthy)
        infected_particles.append(num_particles - healthy)

plt.plot(range(num_iterations + 1), healthy_particles)
plt.plot(range(num_iterations + 1), infected_particles)
plt.show()