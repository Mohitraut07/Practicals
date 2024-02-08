from matplotlib import pyplot as pl

bubbleSort = [ 0, 0, 1, 3, 5, 7, 10, 14, 18, 23 ]
selectionSort  = [0, 0, 0, 1, 1, 2, 3, 4, 5, 6]
dataSet = ["10k","20k","30k","40K","50k","60k","70k","80k","90k","100k"]

pl.xlabel("Data Set Size ")
pl.ylabel("Time Complexcity (Sec)")

pl.scatter(dataSet,bubbleSort)
pl.plot(dataSet,bubbleSort,label="Bubble Sort")

pl.scatter(dataSet,selectionSort)
pl.plot(dataSet,selectionSort , label="Selection Sort")
pl.legend()


pl.show()