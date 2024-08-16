#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int m;
        cin >> m;
        while (m--)
        {
            int fr[26];
            for (int i = 0; i < 26; i++)
                fr[i] = 1e9 + 7;
            string s;
            cin >> s;
            if (s.size() != n)
                cout << "NO" << endl;
            else
            {
                string ss = "YES";
                for (int i = 0; i < n; i++)
                {
                    if (fr[s[i] - 'a'] == (1e9 + 7))
                    {
                        for (int j = 0; j < 26; j++)
                        {
                            if (a[i] == fr[j])
                                ss = "NO";
                        }
                        if (ss != "NO")
                            fr[s[i] - 'a'] = a[i];
                    }
                    else
                    {
                        if (a[i] != fr[s[i] - 'a'])
                            ss = "NO";
                    }
                    if (ss == "NO")
                        break;
                }
                cout << ss << endl;
            }
        }
    }
}