#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <climits>
#include <stack>
#include <set>
#include <cmath>
using namespace std;

// Searching Algorithms
int binarySearch(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int linearSearch(vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) if (arr[i] == key) return i;
    return -1;
}

int binarySearchRecursive(vector<int>& arr, int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] > key) return binarySearchRecursive(arr, low, mid - 1, key);
    return binarySearchRecursive(arr, mid + 1, high, key);
}

int ternarySearch(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
        if (arr[mid1] == key) return mid1;
        if (arr[mid2] == key) return mid2;
        if (key < arr[mid1]) high = mid1 - 1;
        else if (key > arr[mid2]) low = mid2 + 1;
        else { low = mid1 + 1; high = mid2 - 1; }
    }
    return -1;
}

int jumpSearch(vector<int>& arr, int key) {
    int n = arr.size(), step = sqrt(n), prev = 0;
    while (arr[min(step, n) - 1] < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }
    while (arr[prev] < key) {
        prev++;
        if (prev == min(step, n)) return -1;
    }
    return (arr[prev] == key) ? prev : -1;
}

int interpolationSearch(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]);
        if (arr[pos] == key) return pos;
        if (arr[pos] < key) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int exponentialSearch(vector<int>& arr, int key) {
    if (arr[0] == key) return 0;
    int i = 1;
    while (i < arr.size() && arr[i] <= key) i *= 2;
    return binarySearchRecursive(arr, i / 2, min(i, (int)arr.size() - 1), key);
}

// Utility function to print search results
void printSearchResult(const string& name, int result) {
    cout << name << ": ";
    if (result != -1) {
        cout << "Found at index " << result << endl;
    } else {
        cout << "Not found" << endl;
    }
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int key = 23;

    cout << "Searching for " << key << " in the array: ";
    for (int num : arr) cout << num << " ";
    cout << "\n\n";

    printSearchResult("Linear Search", linearSearch(arr, key));
    printSearchResult("Binary Search", binarySearch(arr, key));
    printSearchResult("Recursive Binary Search", binarySearchRecursive(arr, 0, arr.size() - 1, key));
    printSearchResult("Ternary Search", ternarySearch(arr, key));
    printSearchResult("Jump Search", jumpSearch(arr, key));
    printSearchResult("Interpolation Search", interpolationSearch(arr, key));
    printSearchResult("Exponential Search", exponentialSearch(arr, key));

    return 0;
}