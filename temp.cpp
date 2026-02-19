#include <iostream>
using namespace std;

// ------------------------------------
// Down-Heapify (Bubble Down) – 1 Based
// ------------------------------------
void downHeapify(int arr[], int heapSize, int i)
{
    int largest = i;
    int left  = 2 * i;       // left child
    int right = 2 * i + 1;   // right child

    // If left child exists and is greater
    if (left <= heapSize && arr[left] > arr[largest])
        largest = left;

    // If right child exists and is greater
    if (right <= heapSize && arr[right] > arr[largest])
        largest = right;

    // If largest is not the current index
    if (largest != i) {
        swap(arr[i], arr[largest]);
        downHeapify(arr, heapSize, largest);
    }
}

// ------------------------------------
// Build Max Heap (Bottom-Up) – 1 Based
// ------------------------------------
void buildMaxHeap(int arr[], int n)
{
    // First internal node = n/2
    for (int i = n / 2; i >= 1; i--) {
        downHeapify(arr, n, i);
    }
}

// ------------------------------------
// Heap Sort Algorithm – 1 Based Index
// ------------------------------------
void heapSort(int arr[], int n)
{
    // Step 1: Build Max Heap
    buildMaxHeap(arr, n);

    // Step 2: Repeatedly remove maximum element
    int heapSize = n;

    for (int end = n; end >= 2; end--)  
    {
        // Swap root (max) with last element
        swap(arr[1], arr[end]);

        // Reduce heap size
        heapSize--;

        // Restore heap property from index 1
        downHeapify(arr, heapSize, 1);
    }
}

// ------------------------------------
// Main Function
// ------------------------------------
int main()
{
    // NOTE: arr[0] is unused to maintain 1-based index
    int arr[] = {0, 4, 10, 3, 5, 1};  
    int n = 5;

    cout << "Original Array: ";
    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n);

    cout << "Sorted Array:   ";
    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
