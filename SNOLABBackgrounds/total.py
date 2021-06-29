import pandas as pd
import matplotlib.pyplot as plt

energy_range = list(pd.read_csv("SnoLab_Th-gamma_albedo.dat", "\t")["0"])

length = 262

U_df = list(pd.read_csv("SnoLab_U-gamma_albedo.dat", "\t")["0.1"])
TH_df = list(pd.read_csv("SnoLab_Th-gamma_albedo.dat", "\t")["0.1"])
K40_df = list(pd.read_csv("SnoLab_K40-gamma_albedo.dat", "\t")["0.1"])

# appending 0s in the end
U_df = U_df + [0]*(262 - len(U_df))
TH_df = TH_df + [0]*(262 - len(TH_df))
K40_df = K40_df + [0]*(262 - len(K40_df))

U_t = 1.4
TH_t = 3.15
K40_t = 2.9

U_df = list(map(lambda x: x/U_t, U_df))
TH_df = list(map(lambda x: x/TH_t, TH_df))
K40_df = list(map(lambda x: x/K40_t, K40_df))

total = list(map(lambda x: x[0] + x[1] + x[2], zip(U_df, TH_df, K40_df)))
plt.yscale('log')
plt.plot(energy_range[0:len(U_df)][0:50], U_df[0:50], label="U")
plt.plot(energy_range[0:len(TH_df)][0:50], TH_df[0:50], label="Th")
plt.plot(energy_range[0:len(K40_df)][0:50], K40_df[0:50], label="K40")
plt.plot(energy_range[0:len(total)][0:50], total[0:50], label="total")
plt.legend()
plt.grid()
plt.savefig("total.png")

with open("total-gamma.dat", "w+") as total_file:
    output = ""
    for energy, value in zip(energy_range, total):
        output = output + f"{energy}\t{value}\n"
    total_file.write(output)
