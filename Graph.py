import matplotlib.pyplot as plt
# Define the x and y values for each line
# Quick Sort
x = [100, 200, 600, 1000]
y1 = [7900, 92100, 70200, 61100]
# Insertion Sort
y2 = [400, 6100, 9500, 1400]
# merge Sort
y3 = [6300, 10900, 22300, 278300]
plt.grid(True)
# Plot the Quick Sort line
plt.plot(x, y1, label='Quick Sort')
# Plot the Merge Sort line
plt.plot(x, y2, label='Merge Sort')
# Plot the Insertion Sort line
plt.plot(x, y3, label='Insertion') 
         # Add a legend to the graph
plt.legend()
# Add labels to the x and y axis
plt.xlabel('X-Size')
plt.ylabel('Y-Time in ns')
# Add a title to the graph
plt.title('The comparison of time taken by Quick Sort,Insertion Sort and Merge Sort Sorting technique')
# Display the graph
plt.show()