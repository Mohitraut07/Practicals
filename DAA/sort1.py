import matplotlib.pyplot as plt

# Array sizes
array_sizes = [500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000]

# Time taken by Insertion Sort for each array size
insertion_sort_times = [3.99999999e-06, 9.999999975e-07, 9.999999975e-07, 0, 0, 9.999999975e-07, 1.999999995e-06, 9.999999975e-07, 1.999999995e-06, 9.999999975e-07]

# Time taken by Merge Sort for each array size
merge_sort_times = [0.0001189999966, 0.0002349999995, 0.0003849999921, 0.0005050000036, 0.0005859999801, 0.0007699999842, 0.0007980000228, 0.000858000014, 0.000979000004, 0.0009529999807]

# Plotting the data
plt.plot(array_sizes, insertion_sort_times, label='Insertion Sort', marker='o')
plt.plot(array_sizes, merge_sort_times, label='Merge Sort', marker='x')
plt.xlabel('Array Size')
plt.ylabel('Time Taken')
plt.title('Time Complexity of Insertion Sort vs Merge Sort')
plt.legend()
plt.show()
