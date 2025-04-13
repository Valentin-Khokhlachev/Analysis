import pandas as pd
import matplotlib.pyplot as plt
import os

name = "interpLagTest"

path_to_graph = "graph/"
flag_save_pic = True

data = pd.read_csv("../results/" + name + ".csv", sep=';')

if (not os.path.exists(path_to_graph)):
    os.mkdir(path_to_graph)

#print(data)

plt.figure()
plt.plot(data.t_i, data.u_i,
         color = 'black',
         linestyle = '-', linewidth = 0.5,
         marker = '.', markersize = 2,
         label = 'initial data')
plt.plot(data.t_f, data.u_f,
         color = 'red',
         linestyle = 'none', linewidth = 0.5,
         marker = '.', markersize = 2,
         label = 'interpolation')
plt.legend(loc = 'best')

if (flag_save_pic):
    plt.savefig(path_to_graph + name + "Result" + ".svg")

