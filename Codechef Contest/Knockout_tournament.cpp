#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<int> max_wins = {4, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0};

    while (T--) {
        vector<int> skills(16);
        unordered_map<int, int> skill_to_wins;

        for (int i = 0; i < 16; ++i) {
            cin >> skills[i];
        }

        vector<int> sorted_skills = skills;
        sort(sorted_skills.begin(), sorted_skills.end(), greater<int>());

        for (int i = 0; i < 16; ++i) {
            skill_to_wins[sorted_skills[i]] = max_wins[i];
        }

        for (int i = 0; i < 16; ++i) {
            cout << skill_to_wins[skills[i]] << " ";
        }
        cout << endl;
    }

    return 0;
}
