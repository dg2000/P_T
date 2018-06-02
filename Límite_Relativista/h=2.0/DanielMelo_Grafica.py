import numpy as np

import matplotlib.pyplot as plt 


n = np.loadtxt("frontera_vs_n.txt")[:, 0]

frontera = np.loadtxt("frontera_vs_n.txt")[:, 1]

derivada = np.loadtxt("frontera_vs_n.txt")[:, 2]

h = np.loadtxt("frontera_vs_n.txt")[:, 3]

masa = -4.0*np.pi*frontera*frontera*derivada/h[0]

plt.scatter(n, frontera, label="Radio Maximo vs n")
plt.xlabel("n")
plt.ylabel("Radio Maximo")
plt.legend(loc=0)

plt.savefig("RadioMax_vs_n.png")


plt.figure()
plt.scatter(n, derivada, label ="Derivada Frontera vs n")
plt.xlabel("n")
plt.ylabel("Derivada Frontera")
plt.legend(loc=0)

plt.savefig("DerivadaFront_vs_n.png")


plt.figure()
plt.scatter(n, masa, label = "Masa vs n")
plt.xlabel("n")
plt.ylabel("Masa")
plt.legend(loc=0)

plt.savefig("Masa_vs_n.png")


