import matplotlib.pyplot as plt
import numpy as np

# Time complexity values for Heap Sort and Quick Sort for different array sizes
num_heap = np.array([500,1000,1500,2000,2500,3000,3500,4000,4500,5000])
tc_heap = np.array([0.0001100000009,0.0002269999968,0.0003420000139,0.0004159999953,0.000561999972,0.0007699999842,0.0008670000243,0.0008529999759,0.0009459999856,0.00091599999])

num_quick = np.array([500,1000,1500,2000,2500,3000,3500,4000,4500,5000])
tc_quick = np.array([0.0005380000221,0.002006999915,0.003351999912,0.004430999979,0.005874999799,0.007069000043,0.009491999634,0.01217199955,0.01529099979,0.01869199984])

plt.plot(num_heap, tc_heap, label='Heap sort')
plt.plot(num_quick, tc_quick, label='Quick sort')
plt.xlabel('Size of array')
plt.ylabel('Time Complexity')
plt.legend()
plt.title('Heap Sort vs Quick Sort')
plt.show()
