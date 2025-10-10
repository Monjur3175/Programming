#include <iostream>
using namespace std;

int n;           // Number of elements
int targetSum;   // Target sum
int setArray[20];
int subset[20];

void printSubset(int subset[], int subsetSize) {
    cout << "{ ";
    for (int i = 0; i < subsetSize; i++) {
        cout << subset[i] << " ";
    }
    cout << "}" << endl;
}

void sumOfSubsets(int i, int currentSum, int subsetSize) {
    if (currentSum == targetSum) {
        printSubset(subset, subsetSize);
        return;
    }

    if (i == n || currentSum > targetSum) {
        return;
    }

    // Include setArray[i]
    subset[subsetSize] = setArray[i];
    sumOfSubsets(i + 1, currentSum + setArray[i], subsetSize + 1);

    // Exclude setArray[i]
    sumOfSubsets(i + 1, currentSum, subsetSize);
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> setArray[i];
    }

    cout << "Enter target sum: ";
    cin >> targetSum;

    cout << "\nSubsets that sum to " << targetSum << " are:\n";
    sumOfSubsets(0, 0, 0);

    return 0;
}
