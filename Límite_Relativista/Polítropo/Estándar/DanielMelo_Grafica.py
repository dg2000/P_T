import numpy as np

import matplotlib.pyplot as plt 



r = np.loadtxt("z_w_w*.txt")[:, 0]

y1 = np.loadtxt("z_w_w*.txt")[:, 1]

y2 = np.loadtxt("z_w_w*.txt")[:, 2]

a = len(r)


print "La frontera fue encontrada en Z = " +  str(r[a-3]) + ". Derivada en frontera = " + str(y2[a-3]) + ". Densidad central = " + str(r[a-2]) + ". Alfa = " + str(y1[a-2]) + ". Beta = " + str(y2[a-2]) + ". n = " + str(r[a-1]) + ". m = " + str(y1[a-1])


plt.scatter(r[:a-3], y1[:a-3], s=0.8, label = "w vs z")
plt.title("w vs z")
plt.xlabel("z")
plt.ylabel("w")
plt.legend(loc=0)
plt.savefig("n="+str(r[a-1])+"|m="+str(y1[a-1])+"|alfa="+str(y1[a-2])+"|beta="+str(y2[a-2])+"(w_vs_z).png")


plt.figure()
plt.scatter(r[:a-3], y2[:a-3], s=0.8, label = "w' vs z")
plt.title("w' vs z")
plt.xlabel("z")
plt.ylabel("w'")
plt.legend(loc=0)
plt.savefig("n="+str(r[a-1])+"|m="+str(y1[a-1])+"|alfa="+str(y1[a-2])+"|beta="+str(y2[a-2])+"(w'_vs_z).png")


plt.figure()
plt.scatter(y1[:a-3], y2[:a-3], s=0.8, label = "w' vs w")
plt.title("w' vs w")
plt.xlabel("w")
plt.ylabel("w'")
plt.legend(loc=0)
plt.savefig("n="+str(r[a-1])+"|m="+str(y1[a-1])+"|alfa="+str(y1[a-2])+"|beta="+str(y2[a-2])+"(w'_vs_w).png")
