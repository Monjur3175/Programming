#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Creating a sample 1D array
    vector<int> arr = {10, 20, 30, 40, 50};

    //printing Elements
    cout << "Printing Elements:\n";
    for(int i:arr){
    cout << i<< " ";
    }
    cout<<"\n\n";

    // Accessing Elements
    cout << "Accessing Elements:\n";
    cout << "Element at index 2: " << arr[2] << endl;

    // Insertion
    cout << "\nInsertion:\n";
    arr.insert(arr.begin() + 2, 25);
    cout << "Array after insertion: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Deletion
    cout << "\nDeletion:\n";
    arr.erase(arr.begin() + 3);
    cout << "Array after deletion: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Updating
    cout << "\nUpdating:\n";
    arr[1] = 22;
    cout << "Array after updating: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Searching
    cout << "\nSearching:\n";
    auto it = find(arr.begin(), arr.end(), 30);
    if (it != arr.end()) {
        cout << "Element 30 found at index: " << distance(arr.begin(), it) << endl;
    } else {
        cout << "Element 30 not found in the array.\n";
    }

    // Traversal
    cout << "\nTraversal:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Concatenation
    cout << "\nConcatenation:\n";
    vector<int> arr2 = {60, 70, 80};
    arr.insert(arr.end(), arr2.begin(), arr2.end());
    cout << "Array after concatenation: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Sorting
    cout << "\nSorting:\n";
    sort(arr.begin(), arr.end());
    cout << "Array after sorting: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Reversing
    cout << "\nReversing:\n";
    reverse(arr.begin(), arr.end());
    cout << "Array after reversing: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Minimum
    cout << "\nMinimum:\n";
    int minValue = *min_element(arr.begin(), arr.end());
    cout << "Minimum value in the array: " << minValue << endl;

    // Maximum
    cout << "\nMaximum:\n";
    int maxValue = *max_element(arr.begin(), arr.end());
    cout << "Maximum value in the array: " << maxValue << endl;

    // Summation
    cout << "\nSummation:\n";
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    cout << "Sum of elements in the array: " << sum << endl;

    // Average
    cout << "\nAverage:\n";
    double average = static_cast<double>(sum) / arr.size();
    cout << "Average value of elements in the array: " << average << endl;

    // Intersection
    cout << "\nIntersection:\n";
    vector<int> arr3 = {30, 40, 60};
    vector<int> intersection;
    sort(arr.begin(), arr.end());
    sort(arr3.begin(), arr3.end());
    set_intersection(arr.begin(), arr.end(), arr3.begin(), arr3.end(), back_inserter(intersection));
    cout << "Intersection of arrays: ";
    for (int num : intersection) {
        cout << num << " ";
    }
    cout << endl;

    // Difference
    cout << "\nDifference:\n";
    vector<int> difference;
    set_difference(arr.begin(), arr.end(), arr3.begin(), arr3.end(), back_inserter(difference));
    cout << "Difference between arrays: ";
    for (int num : difference) {
        cout << num << " ";
    }
    cout << endl;

    // Subset Checking
    cout << "\nSubset Checking:\n";
    vector<int> subset = {30, 40};
    if (includes(arr.begin(), arr.end(), subset.begin(), subset.end())) {
        cout << "Subset found in the array.\n";
    } else {
        cout << "Subset not found in the array.\n";
    }

    // Empty Check
    cout << "\nEmpty Check:\n";
    vector<int> emptyArray;
    if (emptyArray.empty()) {
        cout << "The array is empty.\n";
    } else {
        cout << "The array is not empty.\n";
    }

    // Length/Size
    cout << "\nLength/Size:\n";
    cout << "Size of the array: " << arr.size() << endl;

    return 0;
}
