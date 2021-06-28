import matplotlib.pyplot as plt

wall = [0, 2, 4, 6, 8]
drus = [235, 28.3927, 23.2704, 20.503, 20.0482]

plt.plot(wall, drus)
plt.scatter(wall, drus)
plt.title("Wall vs DRU")
plt.xlabel("Wall width (cm)")
plt.ylabel("DRU (/kg/keV/day)")
plt.grid()
plt.savefig("wall_vs_dru.png")
