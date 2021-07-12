import matplotlib.pyplot as plt

wall = [0, 2, 4, 6, 8]
drus = [302.989, 46.9591, 36.3427, 33.2136, 31.1318]

plt.plot(wall, drus)
plt.scatter(wall, drus)
plt.title("Wall vs DRU")
plt.xlabel("Wall width (cm)")
plt.ylabel("DRU (/kg/keV/day)")
plt.grid()
plt.savefig("wall_vs_dru.png")
