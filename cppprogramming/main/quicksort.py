
def partition(arr, low, high):
	pivotIndex = (low-1)		 # index of smaller element
	pivotKey = arr[high]	 # pivot value

	for currIndex in range(low, high):

		# If current element is smaller than or
		# equal to pivot value
		if arr[currIndex] <= pivotKey:

			# increment index of smaller element
			pivotIndex = pivotIndex+1
			arr[pivotIndex], arr[currIndex] = arr[currIndex], arr[pivotIndex]

	# Move pivot value to acutal final location
	arr[pivotIndex+1], arr[high] = arr[high], arr[pivotIndex+1]
	assert (arr[pivotIndex]<=arr[pivotIndex+1])
	return (pivotIndex+1)

def quickSort(arr, low, high):
	if low < high:
		assert (low < high)
		# pi is partitioning index, arr[p] is now
		# at right place
		pivotIndex = partition(arr, low, high)
		assert (low <= pivotIndex <= high)

		# Separately sort elements before
		# partition and after partition
		quickSort(arr, low, pivotIndex-1)
		quickSort(arr, pivotIndex+1, high)


# Driver code to test above
arr = [10, 7, 8, 9, 1, 5]
#arr = [6,2,7,1,3,0,5,4]
#arr = [7,1,2,0,3,9,7,4]
#arr = [3,4,1,5,6,2,15]
arr = [3,2,15,5,12,25]
arr = [2,3,1,6,8,7,4]
# arr = sorted(arr)
n = len(arr)
quickSort(arr, 0, n-1)
print("Sorted array is:")
for i in range(n):
	print("%d " % arr[i], end=""),
print()
quickSort(arr, 0, n-1)

# This code is contributed by Mohit Kumra
