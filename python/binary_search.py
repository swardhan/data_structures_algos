def binarySearch(arr, item):
	left = 0
	right = len(arr)-1
	found = False

	while left <= right and not found:
		mid = int(left + (right-left/2))
		if arr[mid] == item:
			found = True
			return mid
		else:
			if item < arr[mid]:
				right = mid-1
			else:
				left = mid + 1

	return -1

arr = []
size = int(input("Enter the number elements in the list: "))
for i in range(0,size):
	arr.append(int(input("")))

arr.sort()
if binarySearch(arr,23):
	print("Element Found.")
else:
	print("Element not Found.")