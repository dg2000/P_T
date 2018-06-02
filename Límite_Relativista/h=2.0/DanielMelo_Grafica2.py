import numpy as np

import matplotlib.pyplot as plt

z = np.loadtxt("z_w_w*.txt")[:, 0]

y1 = np.loadtxt("z_w_w*.txt")[:, 1]

y2 = np.loadtxt("z_w_w*.txt")[:, 2]

h = np.loadtxt("z_w_w*.txt")[:, 3]

masa  = -4.0*np.pi*z[len(z)-1]*z[len(z)-1]*y1[len(z)-1]/h[0]

if(z[len(z)-1] == 0.0):
    print "No se pudo encontrar una frontera en el intervalo dado"
    
    
else:
    print "La frontera del sistema se encontro en z = " + str(z[len(z)-1]) + ". La derivada en la frontera fue " + str(y1[len(z)-1]) + ". La masa del sistema fue de: " + str(masa)  + ". Se tuvo n = " + str(y2[len(z)-1]) + " y h = " + str(h[0])



if(z[len(z)-1] == 0.0):
    z2 = np.linspace(1e-6, z[len(z)-2])
else:
    z2 = np.linspace(1e-6, z[len(z)-1])


#def fun(z):
 #   a = (1 + z*z/3)**0.5

  #  return 1/a



plt.scatter(z[:len(z)-1], y1[:len(z)-1], s=0.8, label = "w vs z")
#plt.plot(z2, fun(z2), c="yellow" , label = "Analitica")
plt.xlabel("z")
plt.ylabel("w")
plt.legend(loc=0)

plt.savefig("n" + "(w_vs_z).png")


plt.figure()
plt.scatter(y1[:len(z)-1], y2[:len(z)-1], s=0.8,  label = " w' vs w ")
plt.xlabel("w")
plt.ylabel("w'")
plt.legend(loc=0)

plt.savefig("n" + "(w'_vs_w).png")

plt.figure()
plt.scatter(z[:len(z)-1], y2[:len(z)-1], s=0.8, label = "w'vs z")
plt.xlabel("z")
plt.ylabel("w'")
plt.legend(loc=0)

plt.savefig("n" + "(w'_vs_z).png")

f = open ('frontera_vs_n.txt','a')
f.write('\n' + str(y2[len(z)-1]) + " " + str(z[len(z)-1]) + " " + str(y1[len(z)-1]) + " " + str(h[0]))
f.close()


