import numpy as np
import matplotlib.pyplot as plt

indices = np.loadtxt("masa.txt")[:, 0]
masa = np.loadtxt("masa.txt")[:, 1]


plt.scatter(indices, masa, s=0.8, label="M/Mch vs nt")
plt.title("M/Mch vs nt")
plt.xlabel("nt")
plt.ylabel("M/Mch")
plt.legend(loc=0)
plt.savefig("nr=1.5|a=1.0|b=1.0|(M(Mch vs nt).png")
