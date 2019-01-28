import numpy as np
import matplotlib.pyplot as plt

indices = np.loadtxt("masa.txt")[:, 0]
masa = np.loadtxt("masa.txt")[:, 1]

r = len(masa)
otra = ""
var = ""
if(masa[r-2] == 0.0):
	otra = "n"
	var = "m"
elif (masa[r-2] == 1.0):
	otra = "m"
	var = "n"
elif (masa[r-2] == 2.0):
        var = "alfa"
        otra = "beta"
elif(masa[r-2] == 3.0):
        var = "beta"
        otra = "alfa"
        

plt.figure()
plt.scatter(indices[:r-4], masa[:r-4], s=0.8, label="M/Mch vs " + var)
plt.title("M/Mch vs " + var)
plt.xlabel(var)
plt.ylabel("M/Mch")
plt.legend(loc=0)
#plt.savefig("alfa=1.0|beta=1.0|(M/Mch vs nt).png")
if (masa[r-2] <=1.0):
        plt.savefig("alfa=" + str(indices[r-3]) + "|beta=" + str(masa[r-3]) + "|" + otra + "=" + str(indices[r-2]) + "|" + var + "[" + str(indices[r-1]) + "," + str(masa[r-1]) + "]|(M%Mch vs " + var + ").png")

else:
        plt.savefig("n=" + str(indices[r-3]) + "|m=" + str(masa[r-3]) + "|" + otra + "=" + str(indices[r-2]) + "|" + var + "[" + str(indices[r-1]) + "," + str(masa[r-1]) + "]|(M%Mch vs " + var + ").png")

