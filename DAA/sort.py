import matplotlib.pyplot as plt
import numpy as np

num_a = np.array([500,1000,1500,2000,2500,3000,3500,4000,4500,5000])
tc_a = np.array([0.001000000047,0.002000000095,0.004999999888,0.008999999613,0.01700000092,0.02199999988,0.02999999933,0.0390000008,0.05099999905,0.05900000036])

num_b = np.array([500,1000,1500,2000,2500,3000,3500,4000,4500,5000])
tc_b = np.array([0,0.001000000047,0.002000000095,0.003000000026,0.004999999888,0.007000000216,0.008999999613,0.0120000001,0.01400000043,0.01899999939,])

plt.plot(num_a, tc_a, label='Bubble sort')
plt.plot(num_b, tc_b, label='Selection sort')
plt.xlabel('Size of array')
plt.ylabel('Time Complexity')
plt.legend()
plt.title('Bubble Sort vs Selection Sort')
plt.show()