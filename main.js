function u_swap(arr, a, b) {
    let temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

function binarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;

    while (left <= right) {
        let mid = Math.floor((left + right) / 2);

        if (arr[mid] === target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

function linearSearch(arr, target) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === target) return i;
    }
    return -1;
}

function bubbleSort(arr) {
    for (let i = 0; i < arr.length - 1; i++) {
        let swapped = false;
        for (let j = 0; j < arr.length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                u_swap(arr, j, j+1)
                swapped = true
            }
        }
        if (!swapped) {break}
    }
}
        
function selectionSort(arr) {
    for (let i = 0; i < arr.length - 1; i++) {
        let minIndex = i;
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            u_swap(arr, i, minIndex);
        }
    }
}

function insertionSort(arr) {
    for (let i = 1; i < arr.length; i++) {
        let key = arr[i];
        let j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

function u_partition(arr, low, high) {
    let pivot = arr[high];
    let i = low - 1;

    for (let j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            u_swap(arr, i, j);
        }
    }

    u_swap(arr, i + 1, high);
    return i + 1;
}

function u_quickSortRec(arr, low, high) {
    if (low < high) {
        let pi = u_partition(arr, low, high);

        u_quickSortRec(arr, low, pi - 1);
        u_quickSortRec(arr, pi + 1, high);
    }
}

function quickSort(arr) {
    if (arr.length <= 1) return arr;
    u_quickSortRec(arr, 0, arr.length - 1);
}

function mergeSort(arr) {
    if (arr.length <= 1) return arr;

    let mid = Math.floor(arr.length / 2);
    let left = arr.slice(0, mid);
    let right = arr.slice(mid);

    mergeSort(left);
    mergeSort(right);

    u_merge(arr, left, right)
}

function u_merge(arr, left, right) {
    let i = 0;
    let j = 0;
    let k = 0;

    while (i < left.length && j < right.length) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i += 1;
        } else {
            arr[k] = right[j];
            j += 1;
        }
        k += 1;
    }
    while (i < left.length) {
        arr[k] = left[i];
        i += 1;
        k += 1;
    }
    while (j < right.length){
        arr[k] = right[j];
        j += 1;
        k += 1;
    }
}

function u_heapify(arr, size, i) {
    let largest = i;
    let left = 2 * i + 1;
    let right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest !== i) {
        u_swap(arr, i, largest);
        u_heapify(arr, size, largest);
    }
}

function heapSort(arr) {
    for (let i = Math.floor(arr.length / 2) - 1; i >= 0; i--) {
        u_heapify(arr, arr.length, i);
    }

    for (let i = arr.length - 1; i > 0; i--) {
        u_swap(arr, 0, i);
        u_heapify(arr, i, 0);
    }
}
