import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Define some color codes
RED = '\033[91m'
GREEN = '\033[92m'
YELLOW = '\033[93m'
BLUE = '\033[94m'
END = '\033[0m'


# Define the function to fit
def f(x, a, b):
    return a * (np.log(x)) + b


def g(x, a, b):
    return a * x + b


def h(x, a, b):
    return a * x + b


options = {
    '1': 'cmake-build-release/linear_search.txt',
    '2': 'cmake-build-release/binary_search.txt',
    '3': 'cmake-build-release/binary_search_tree.txt',
    '4': 'cmake-build-release/hash_table.txt',
    '5': 'all'
}


def plot_files(choice):
    # Load the data from the file
    datafile1 = 'cmake-build-release/linear_search.txt'
    datafile2 = 'cmake-build-release/binary_search.txt'
    datafile3 = 'cmake-build-release/binary_search_tree.txt'
    datafile4 = 'cmake-build-release/hash_table.txt'

    data = np.genfromtxt(datafile1, delimiter='\t', skip_header=2, max_rows=10)
    data2 = np.genfromtxt(datafile1, delimiter='\t', skip_header=12, max_rows=10)
    data3 = np.genfromtxt(datafile1, delimiter='\t', skip_header=22, max_rows=10)
    data4 = np.genfromtxt(datafile1, delimiter='\t', skip_header=32, max_rows=10)

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
    fig, ax = plt.subplots()
    if choice == '1':
        ax.errorbar(x, y, yerr=err, fmt='yo', label='mätvärde')
        ax.plot(x, g(x, *popt), 'y-', label=r'$linear search$')
    if choice == '2':
        ax.errorbar(x2, y2, yerr=err2, fmt='ro', label='mätvärde')
        ax.plot(x2, f(x2, *popt2), 'r-', label=r'$Binary search$')
    if choice == '3':
        ax.errorbar(x3, y3, yerr=err3, fmt='bo', label='mätvärde')
        ax.plot(x3, f(x3, *popt3), 'b-', label=r'$Binary search tree$')
    if choice == '4':
        ax.errorbar(x4, y4, yerr=err4, fmt='go', label='mätvärde')
        ax.plot(x4, h(x4, *popt4), 'g-', label=r'$Hashtable search$')
    if choice == '5':
        ax.errorbar(x, y, yerr=err, fmt='yo', label='mätvärde')
        ax.plot(x, g(x, *popt), 'y-', label=r'$linear search$')

        ax.errorbar(x2, y2, yerr=err2, fmt='ro', label='mätvärde')
        ax.plot(x2, f(x2, *popt2), 'r-', label=r'$Binary search$')

        ax.errorbar(x3, y3, yerr=err3, fmt='bo', label='mätvärde')
        ax.plot(x3, f(x3, *popt3), 'b-', label=r'$Binary search tree$')

        ax.errorbar(x4, y4, yerr=err4, fmt='go', label='mätvärde')
        ax.plot(x4, h(x4, *popt4), 'g-', label=r'$Hashtable search$')

    # Add a legend and labels
    ax.legend()
    ax.set_xlabel('Input size (n)')
    ax.set_ylabel('Running time (µs)')
    ax.set_title('Search algorithms - Varying series')

    # Show the plot
    plt.show()


def menu():
    while True:
        print(GREEN + "Select an option to plot:" + END)
        print("\t\t1. linear search")
        print("\t\t2. binary search")
        print("\t\t3. binary search tree")
        print("\t\t4. hashtable search")
        print("\t\t5. all search")
        choice = input("Enter your choice (1-6): ")
        if choice == '6':
            break
        if choice not in options:
            print("Invalid choice. Please try again.")
            continue
        else:
            plot_files(choice)


menu()
