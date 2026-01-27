def u_swap(arr, a, b):
    arr[a], arr[b] = arr[a], arr[b]

def binarySearch(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def linearSearch(arr, target):
    for i in range(0, len(arr)):
        if arr[i] == target:
            return i
    return -1


def bubbleSort(arr):
    for i in range(len(arr)):
        swapped = False
        for j in range(0, len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                u_swap(arr, j, j+1)
                swapped = True
        if not swapped : break
        
def selectionSort(arr):
    for i in range(len(arr)) :
        minIndex = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[minIndex]:
                minIndex = j
                
        if minIndex != i:
            u_swap(arr, i, minIndex)
            
def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key :
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
        
def u_partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high) :
        if arr[j] <= pivot:
            i += 1
            u_swap(arr, i, j)

    u_swap(arr, i + 1, high)
    return i + 1

def u_quickSortRec(arr, low, high):
    if low < high:
        pi = u_partition(arr, low, high)

        u_quickSortRec(arr, low, pi - 1)
        u_quickSortRec(arr, pi + 1, high)
        
def quickSort(arr):
    if len(arr) <= 1 : return
    u_quickSortRec(arr, 0, len(arr) - 1)
    
def mergeSort(arr):
    if len(arr) <= 1:
        return

    mid = len(arr) // 2
    left = arr[:mid]
    right = arr[mid:]

    mergeSort(left)
    mergeSort(right)

    u_merge(arr, left, right)


def u_merge(arr, left, right):
    i = j = k = 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    while i < len(left):
        arr[k] = left[i]
        i += 1
        k += 1

    while j < len(right):
        arr[k] = right[j]
        j += 1
        k += 1
        
def u_heapify(arr, size, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < size and arr[left] > arr[largest]:
        largest = left

    if right < size and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        u_swap(arr, i, largest)
        u_heapify(arr, size, largest)
        
def heapSort(arr) :
    for i in range(len(arr) // 2 - 1, -1, -1):
        u_heapify(arr, len(arr), i)

    for i in range(len(arr) - 1, 0, -1):
        u_swap(arr, 0, i)
        u_heapify(arr, i, 0)
