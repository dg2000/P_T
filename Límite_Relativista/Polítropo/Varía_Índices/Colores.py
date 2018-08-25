import numpy as np

import matplotlib.pyplot as plt 

matriz = np.loadtxt("matriz.txt")
matriz = np.log10(matriz)
#matriz = matrix/norma

imagen = matriz


plt.imshow(imagen, cmap=plt.cm.binary)
plt.xlabel("n -->")
plt.ylabel("<-- m")
plt.colorbar()
plt.title("Escala log10")

plt.savefig("matriz.png")
