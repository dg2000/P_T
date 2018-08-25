import numpy as np

import matplotlib.pyplot as plt 



r = np.loadtxt("r_p_p*.txt")[:, 0]

y1 = np.loadtxt("r_p_p*.txt")[:, 1]

y2 = np.loadtxt("r_p_p*.txt")[:, 2]

a = len(r)


print "La frontera fue encontrada en R = " +  str(r[a-3]) + ". Derivada en frontera = " + str(y2[a-3]) + ". Densidad central = " + str(r[a-2]) + ". Alfa = " + str(y1[a-2]) + ". Beta = " + str(y2[a-2]) + ". n = " + str(r[a-1]) + ". m = " + str(y1[a-1])


plt.scatter(r[:a-3], y1[:a-3], s=0.8, label = "p vs r")
plt.title("Densidad vs radio")
plt.xlabel("Radio")
plt.ylabel("Densidad")
plt.legend(loc=0)
plt.savefig("p_vs_r")


plt.figure()
plt.scatter(r[:a-3], y2[:a-3], s=0.8, label = "p' vs r")
plt.title("p' vs r")
plt.xlabel("Radio")
plt.ylabel("Derivada densidad")
plt.legend(loc=0)
plt.savefig("p'_vs_r")


plt.figure()
plt.scatter(y1[:a-3], y2[:a-3], s=0.8, label = "p' vs p")
plt.title("p' vs p")
plt.xlabel("Densidad")
plt.ylabel("Derivada densidad")
plt.legend(loc=0)
plt.savefig("p'_vs_p")
