import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Define some color codes
RED = '\033[91m'
GREEN = '\033[92m'
YELLOW = '\033[93m'
BLUE = '\033[94m'
END = '\033[0m'


# Define the function to fit for O(log(n))
def f(x, a, b):
    return a * (np.log(x)) + b


# linear fit O(n)
def g(x, a, b):
    return a * x + b


# to fit, time complexity for hashtable search
def h(x, a, b):
    return a * x + b


options = {
    '1': 'cmake-build-release/linear_search.txt',
    '2': 'cmake-build-release/binary_search.txt',
    '3': 'cmake-build-release/binary_search_tree.txt',
    '4': 'cmake-build-release/hash_table.txt',
    '5': 'all'
}

# Load the data from the file
datafile1 = 'cmake-build-release/linear_search.txt'
datafile2 = 'cmake-build-release/binary_search.txt'
datafile3 = 'cmake-build-release/binary_search_tree.txt'
datafile4 = 'cmake-build-release/hash_table.txt'
SAMPLE = 20
data = np.genfromtxt(datafile1, delimiter='\t', skip_header=2, max_rows=SAMPLE)
data2 = np.genfromtxt(datafile2, delimiter='\t', skip_header=2, max_rows=SAMPLE)
data3 = np.genfromtxt(datafile3, delimiter='\t', skip_header=2, max_rows=SAMPLE)
data4 = np.genfromtxt(datafile4, delimiter='\t', skip_header=2, max_rows=SAMPLE)

# Extract the x, y, and error bar values
x = data[:, 0]
y = data[:, 1]
err = data[:, 2]

x2 = data2[:, 0]
y2 = data2[:, 1]
err2 = data2[:, 2]

x3 = data3[:, 0]
y3 = data3[:, 1]
err3 = data3[:, 2]

x4 = data4[:, 0]
y4 = data4[:, 1]
err4 = data4[:, 2]

# Fit the function to the data
fit_results = curve_fit(g, x, y, sigma=err)
popt = fit_results[0]
pcov = fit_results[1]

fit_results2 = curve_fit(f, x2, y2, sigma=err2)
popt2 = fit_results2[0]
pcov2 = fit_results2[1]

fit_results3 = curve_fit(f, x3, y3, sigma=err3)
popt3 = fit_results3[0]
pcov3 = fit_results3[1]

fit_results4 = curve_fit(h, x4, y4, sigma=err4)
popt4 = fit_results4[0]
pcov4 = fit_results4[1]

# Calculate the residuals
resid = y - g(x, *popt)
resid2 = y2 - f(x2, *popt2)
resid3 = y3 - f(x3, *popt3)
resid4 = y4 - h(x4, *popt4)

# Calculate the chi-squared value
chi2 = np.sum((resid / err) ** 2)
chi22 = np.sum((resid2 / err2) ** 2)
chi23 = np.sum((resid3 / err3) ** 2)
chi24 = np.sum((resid4 / err4) ** 2)

# Create the plot
fig, ax = plt.subplots(2, 2, figsize=(16, 8))
ax[0][0].set_title("Linear search")
ax[0][0].errorbar(x, y, yerr=err, fmt='k+', markersize=5, ecolor='b', capsize=0, capthick=1, elinewidth=1,
                  label='Data (O(n))')
ax[0][0].plot(x, g(x, *popt), 'k-', label=r'$Linear search$')

ax[0][1].set_title("Binary search")
ax[0][1].errorbar(x2, y2, yerr=err2, fmt='r+', markersize=5, ecolor='k', capsize=0, elinewidth=1,
                  label='Data (O(log n))')
ax[0][1].plot(x2, f(x2, *popt2), 'k-', label=r'$Binary search$')

# ax[1][0].set_title("Binary search tree")
ax[1][0].errorbar(x3, y3, yerr=err3, markersize=5, fmt='r+', label='Data (O(log n))')
ax[1][0].plot(x3, f(x3, *popt3), 'k-', label=r'$Binary search tree$')

# ax[1][1].set_title("Hashtable search")
ax[1][1].errorbar(x4, y4, yerr=err4, markersize=5, fmt='r+', label='Data (O(1))')
ax[1][1].plot(x4, h(x4, *popt4), 'k-', label=r'$Hashtable search$')

# Add a legend and labels
for i in range(2):
    for j in range(2):
        ax[i][j].legend()
        ax[i][j].set_xlabel('Input size (n)', fontsize=10)
        ax[i][j].set_ylabel('Running time (µs)', fontsize=10)

fig.suptitle('Search algorithms - Varying series', fontsize=16)

# Show the plot
plt.show()
