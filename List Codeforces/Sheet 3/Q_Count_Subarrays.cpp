#include <iostream>
#include <vector>

using namespace std;

int countNonDecreasingSubarrays(vector<int>& arr) {
    int count = 1;  // Initialize count to 1 for the singleton sub-array
    int n = arr.size();
    int result = 0;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] <= arr[i + 1]) {
            count++;
        } else {
            result += (count * (count + 1)) / 2;
            count = 1;
        }
    }
    result += (count * (count + 1)) / 2;  // Add count for the last sub-array

    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        int result = countNonDecreasingSubarrays(arr);
        cout << result << endl;
    }

    return 0;
}
