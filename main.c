#include <stdio.h>
#include <stdlib.h>

void u_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                u_swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            u_swap(&arr[i], &arr[minIndex]);
        }
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int u_partition(int arr[], int low, int high) {
    int pivot = arr[(low + high) / 2];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            u_swap(&arr[i], &arr[j]);
        }
    }

    u_swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void u_quickSortRec(int arr[], int low, int high) {
    if (low < high) {
        int pi = u_partition(arr, low, high);

        u_quickSortRec(arr, low, pi - 1);
        u_quickSortRec(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int size) {
    if (size <= 1) return;
    u_quickSortRec(arr, 0, size - 1);
}

void u_merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int size = right - left + 1;

    int *temp = malloc(size * sizeof(int));
    if (!temp) return;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = 0; i < size; i++)
        arr[left + i] = temp[i];

    free(temp);
}

void u_mergeSortRec(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        u_mergeSortRec(arr, left, mid);
        u_mergeSortRec(arr, mid + 1, right);
        u_merge(arr, left, mid, right);
    }
}

void mergeSort(int arr[], int size) {
    if (size <= 1)
        return;

    u_mergeSortRec(arr, 0, size - 1);
}

void u_heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        u_swap(&arr[i], &arr[largest]);
        u_heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        u_heapify(arr, size, i);

    for (int i = size - 1; i > 0; i--) {
        u_swap(&arr[0], &arr[i]);
        u_heapify(arr, i, 0);
    }
}
