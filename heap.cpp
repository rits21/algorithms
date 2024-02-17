#include <iostream>
#include <vector>
#define SIZE 1001
using namespace std;

void maxHeapify(vector<int> &arr, int i, int size)
{
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    int largestInd = i;
    if (L < size && arr[L] > arr[largestInd])
    {
        largestInd = L;
    }
    if (R < size && arr[R] > arr[largestInd])
    {
        largestInd = R;
    }
    if (largestInd != i)
    {
        swap(arr[i], arr[largestInd]);
        maxHeapify(arr, largestInd, size);
    }
}

void buildMaxHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, i, n);
    }
}

int heapExtractMax(vector<int> &arr)
{
    if (arr.size() < 1)
    {
        return -1;
    }
    int max = arr[0];
    arr[0] = arr.back();
    arr.pop_back();
    maxHeapify(arr, 0, arr.size());
    return max;
}

void heapIncreaseKey(vector<int> &arr, int i, int key)
{
    if (key < arr[i])
    {
        cout << "Wrong Operation!";
        return;
    }
    arr[i] = key;
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) // percolate up
    {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapDecreaseKey(vector<int> &arr, int i, int key)
{
    if (key > arr[i])
    {
        cout << "Wrong Operation!";
        return;
    }
    arr[i] = key;
    maxHeapify(arr, i, arr.size()); // percolate down
}

void heapInsertElement(vector<int> &arr, int val)
{
    arr.push_back(val);
    int i = arr.size() - 1;
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) // percolate up
    {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapSort(vector<int> &arr) // TC: O(nlogn)
{
    buildMaxHeap(arr);
    for (int i = arr.size() - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, 0, i);
    }
}

void heapPush(vector<int> &heap, int val)
{
    if (heap.size() >= SIZE)
    {
        cout << "Overflow";
        return;
    }
    heap.push_back(val);
    int i = heap.size() - 1;
    while (i > 0 && heap[(i - 1) / 2] < heap[i])
    {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}

int heapPop(vector<int> &heap)
{
    int popped = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    maxHeapify(heap, 0, heap.size());
    return popped;
}

int main()
{
    vector<int> arr = {3, 6, 5, 81, 8, 2, 1, 7};
    heapSort(arr);
    for (auto &i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    buildMaxHeap(arr);
    heapInsertElement(arr, 66);
    for (auto &i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << heapPop(arr);
    return 0;
}
