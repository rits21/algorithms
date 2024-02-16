#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int> &arr, int i)
{
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    int largestInd = i;
    if (L <= arr.size() && arr[L] > arr[largestInd])
    {
        largestInd = L;
    }
    if (R <= arr.size() && arr[R] > arr[largestInd])
    {
        largestInd = R;
    }
    if (largestInd != i)
    {
        swap(arr[i], arr[largestInd]);
        maxHeapify(arr, largestInd);
    }
}
void buildMaxHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, i);
    }
}

int main()
{
    vector<int> arr = {3, 6, 5, 0, 8, 2, 1, 9};
    buildMaxHeap(arr);
    for (auto &&i : arr)
    {
        cout << i << " ";
    }
    return 0;
}