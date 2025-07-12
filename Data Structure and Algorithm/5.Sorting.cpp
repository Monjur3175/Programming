#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// ========== SORTING ALGORITHMS ==========

// 1. Bubble Sort - O(n^2)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Early exit if already sorted
    }
}

// 2. Selection Sort - O(n^2)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// 3. Insertion Sort - O(n^2) best case O(n)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// 4. Merge Sort - O(n log n)
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> temp(r-l+1);
    int i = l, j = m+1, k = 0;
    
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    
    for (int p = 0; p < k; p++) {
        arr[l+p] = temp[p];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// 5. Quick Sort - O(n log n) average, O(n^2) worst
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

// 6. Heap Sort - O(n log n)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    // Build max heap
    for (int i = n/2-1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Extract elements one by one
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 7. Shell Sort - O(n log n) to O(n^2)
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap) {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}

// 8. Counting Sort - O(n+k)
void countingSort(vector<int>& arr) {
    if (arr.empty()) return;
    
    int max_val = *max_element(arr.begin(), arr.end());
    vector<int> count(max_val+1, 0);
    
    for (int num : arr) count[num]++;
    
    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        while (count[i]-- > 0) {
            arr[index++] = i;
        }
    }
}

// 9. Radix Sort - O(d(n+k))
void countingSortRadix(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    vector<int> count(10, 0);

    for (int num : arr) count[(num/exp)%10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i-1];
    for (int i = arr.size()-1; i >= 0; i--) {
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    arr = output;
}

void radixSort(vector<int>& arr) {
    if (arr.empty()) return;
    int max_val = *max_element(arr.begin(), arr.end());
    for (int exp = 1; max_val/exp > 0; exp *= 10) {
        countingSortRadix(arr, exp);
    }
}

// 10. Bucket Sort - O(n+k)
void bucketSort(vector<float>& arr) {
    if (arr.empty()) return;
    
    int n = arr.size();
    vector<vector<float>> buckets(n);
    
    // Put elements into buckets
    for (float num : arr) {
        int bucket_idx = n * num;
        buckets[bucket_idx].push_back(num);
    }
    
    // Sort individual buckets
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
    }
    
    // Concatenate all buckets
    int index = 0;
    for (auto& bucket : buckets) {
        for (float num : bucket) {
            arr[index++] = num;
        }
    }
}

// ========== UTILITY FUNCTIONS ==========
void printArray(const vector<int>& arr, const string& name) {
    cout << name << ": ";
    for (int num : arr) cout << num << " ";
    cout << endl;
}

void printFloatArray(const vector<float>& arr, const string& name) {
    cout << name << ": ";
    for (float num : arr) cout << num << " ";
    cout << endl;
}

// ========== MAIN FUNCTION ==========
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    vector<float> floatArr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    
    // Integer sorting algorithms
    vector<int> bubbleArr = arr;
    bubbleSort(bubbleArr);
    printArray(bubbleArr, "Bubble Sort");
    
    vector<int> selectionArr = arr;
    selectionSort(selectionArr);
    printArray(selectionArr, "Selection Sort");
    
    vector<int> insertionArr = arr;
    insertionSort(insertionArr);
    printArray(insertionArr, "Insertion Sort");
    
    vector<int> mergeArr = arr;
    mergeSort(mergeArr, 0, mergeArr.size()-1);
    printArray(mergeArr, "Merge Sort");
    
    vector<int> quickArr = arr;
    quickSort(quickArr, 0, quickArr.size()-1);
    printArray(quickArr, "Quick Sort");
    
    vector<int> heapArr = arr;
    heapSort(heapArr);
    printArray(heapArr, "Heap Sort");
    
    vector<int> shellArr = arr;
    shellSort(shellArr);
    printArray(shellArr, "Shell Sort");
    
    vector<int> countingArr = arr;
    countingSort(countingArr);
    printArray(countingArr, "Counting Sort");
    
    vector<int> radixArr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(radixArr);
    printArray(radixArr, "Radix Sort");
    
    // Float sorting algorithm
    vector<float> bucketArr = floatArr;
    bucketSort(bucketArr);
    printFloatArray(bucketArr, "Bucket Sort");
    
    return 0;
}