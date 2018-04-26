import matplotlib.pyplot as plt
import numpy as np

datos = np.loadtxt("datos.txt")

plt.figure()
plt.title("Evolucion de la funcion seno")
plt.xlabel("x")
plt.ylabel("y")
plt.plot(datos[:,0], datos[:, 1], label = "1.0")
plt.plot(datos[:,0], datos[:, 2], label = "0.5")
plt.plot(datos[:,0], datos[:, 3], label = "-0.5")
plt.plot(datos[:,0], datos[:, 4], label = "-1.0")
plt.legend()
plt.savefig("figura.pdf")
