import numpy as np
import matplotlib.pyplot as plt


z = np.loadtxt("1(z_w_w*).txt")[:, 0]

a = len(z)

primera = np.loadtxt("1(z_w_w*).txt")[:, 1]
segunda = np.loadtxt("2(z_w_w*).txt")[:, 1]
tercera = np.loadtxt("3(z_w_w*).txt")[:, 1]

plt.plot(z[:a-3], primera[:a-3], c='b', label = "n=m=10|alfa=beta=1")
plt.plot(z[:a-3], segunda[:a-3], c='r', label = "n=m=10|alfa=1|beta=0.9")
plt.plot(z[:a-3], tercera[:a-3], c='g', label = "n=m=10|alfa=1|beta=0.8")

plt.title("w vs z")
plt.xlabel("z")
plt.ylabel("w")
plt.legend(loc=0)
plt.savefig("superposicion(Pr>Pt).png")
