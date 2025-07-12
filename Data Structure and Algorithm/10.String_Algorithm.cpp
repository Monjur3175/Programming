// String Algorithms in C++

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//----------------------------------
// 1. Naive Pattern Matching
//----------------------------------
void naiveSearch(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) j++;
        if (j == m) cout << "Pattern found at index " << i << endl;
    }
}

//----------------------------------
// 2. KMP Algorithm
//----------------------------------
vector<int> computeLPS(string pattern) {
    int m = pattern.size();
    vector<int> lps(m);
    int len = 0, i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) lps[i++] = ++len;
        else if (len != 0) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}

void KMPSearch(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) i++, j++;
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

//----------------------------------
// 3. Rabin-Karp
//----------------------------------
void rabinKarp(string text, string pattern, int d = 256, int q = 101) {
    int n = text.size(), m = pattern.size();
    int h = 1;
    for (int i = 0; i < m - 1; ++i) h = (h * d) % q;
    int p = 0, t = 0;
    for (int i = 0; i < m; ++i) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    for (int i = 0; i <= n - m; ++i) {
        if (p == t) {
            int j;
            for (j = 0; j < m; ++j)
                if (text[i + j] != pattern[j]) break;
            if (j == m) cout << "Pattern found at index " << i << endl;
        }
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
}

//----------------------------------
// 4. Boyer-Moore (Bad Character Heuristic)
//----------------------------------
#define NO_OF_CHARS 256
void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS]) {
    fill(badchar, badchar + NO_OF_CHARS, -1);
    for (int i = 0; i < size; i++) badchar[(int) str[i]] = i;
}

void boyerMoore(string text, string pattern) {
    int m = pattern.size(), n = text.size();
    int badchar[NO_OF_CHARS];
    badCharHeuristic(pattern, m, badchar);
    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) j--;
        if (j < 0) {
            cout << "Pattern found at index " << s << endl;
            s += (s + m < n) ? m - badchar[text[s + m]] : 1;
        } else {
            s += max(1, j - badchar[text[s + j]]);
        }
    }
}

//----------------------------------
// 5. Longest Palindromic Substring (DP)
//----------------------------------
string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    string ans = "";
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && (len <= 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                if (len > ans.size()) ans = s.substr(i, len);
            }
        }
    }
    return ans;
}

//----------------------------------
// 6. Z-Algorithm
//----------------------------------
vector<int> Zalgo(string s) {
    int n = s.size();
    vector<int> Z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) Z[i] = min(r - i + 1, Z[i - l]);
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) Z[i]++;
        if (i + Z[i] - 1 > r) l = i, r = i + Z[i] - 1;
    }
    return Z;
}

//----------------------------------
// 7. Trie Operations
//----------------------------------
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
};

void insert(TrieNode* root, string key) {
    TrieNode* node = root;
    for (char ch : key) {
        if (!node->children[ch]) node->children[ch] = new TrieNode();
        node = node->children[ch];
    }
    node->isEndOfWord = true;
}

bool search(TrieNode* root, string key) {
    TrieNode* node = root;
    for (char ch : key) {
        if (!node->children[ch]) return false;
        node = node->children[ch];
    }
    return node && node->isEndOfWord;
}

void autoComplete(TrieNode* node, string prefix) {
    if (node->isEndOfWord) cout << prefix << endl;
    for (auto& [ch, child] : node->children)
        autoComplete(child, prefix + ch);
}

//----------------------------------
// Main for Testing
//----------------------------------
int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";
    cout << "Naive Search:\n"; naiveSearch(text, pattern);
    cout << "\nKMP Search:\n"; KMPSearch(text, pattern);
    cout << "\nRabin-Karp:\n"; rabinKarp(text, pattern);
    cout << "\nBoyer-Moore:\n"; boyerMoore(text, pattern);

    string s = "babad";
    cout << "\nLongest Palindromic Substring: " << longestPalindrome(s) << endl;

    string zstr = "aabxaabxcaabxaabxay";
    auto z = Zalgo(zstr);
    cout << "Z-array: "; for (int i : z) cout << i << " "; cout << endl;

    TrieNode* root = new TrieNode();
    insert(root, "hello"); insert(root, "hell"); insert(root, "help");
    cout << "\nSearching 'hell': " << (search(root, "hell") ? "Found" : "Not Found") << endl;
    cout << "\nAuto-complete for 'hel':\n"; autoComplete(root, "hel");

    return 0;
}