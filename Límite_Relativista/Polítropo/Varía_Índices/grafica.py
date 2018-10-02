import numpy as np
import matplotlib.pyplot as plt

indices = np.loadtxt("masa.txt")[:, 0]
masa = np.loadtxt("masa.txt")[:, 1]

plt.figure()
plt.scatter(indices, masa, s=0.8, label="M/Mch vs nt")
plt.title("M/Mch vs nt")
plt.xlabel("n")
plt.ylabel("M/Mch")
plt.legend(loc=0)
#plt.savefig("m=1.5|alfa=1.0|beta=1.0|(M/Mch vs nt).png")
plt.savefig("m=1.5|alfa=1.0|beta=1.0|(M%Mch vs n).png")
