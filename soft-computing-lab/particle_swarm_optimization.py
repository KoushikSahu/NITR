import numpy as np
import matplotlib.pyplot as plt
import pyswarms as ps
from pyswarms.utils.plotters import plot_contour, plot_surface
from pyswarms.utils.plotters.formatters import Designer
from pyswarms.utils.plotters.formatters import Mesher


def f(X):
   X = np.array(X)
   x, y = X.T[0], X.T[1]
   particle_values = (x-3.14)**2 + (y-2.72)**2 + np.sin(3*x + 1.14) + np.sin(4*y-1.73)
   return np.array(particle_values)


options = {'c1': 0.1, 'c2': 0.1, 'w':0.8}
optimizer = ps.single.GlobalBestPSO(n_particles=20, dimensions=2,options=options)
cost, pos = optimizer.optimize(f, iters=1000)

print("X-value: ", round(pos[0], 3))
print("Y-value: ", round(pos[1], 3))

fig =plt.figure(figsize=(12, 10))
ax = plt.axes(projection='3d')

x = np.linspace(0, 5, 500)
y = np.linspace(0, 5, 500)
X = np.array([x, y]).T
f_value = f(X)
ax.plot3D(x, y, f_value, 'blue')

x = [optimizer.pos_history[i].T[0] for i in range(1000)]
y = [optimizer.pos_history[i].T[1] for i in range(1000)]
X = np.array([x, y]).T
ax.scatter3D(x, y, f(X), c=f(X))

plt.xlim([0, 5])
plt.ylim([0, 5])

ax.set_xlabel("x-value")
ax.set_ylabel("y-value")
ax.set_zlabel("Function Value")
plt.show()

