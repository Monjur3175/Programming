#include <bits/stdc++.h>
using namespace std;

#define Monjur_Morshed (ios_base::sync_with_stdio(false), cin.tie(NULL));

typedef long long ll;


void solution()
{
    string s;
	cin>>s;
	string t;
	cin>>t;
	int i=0,j=0;
	while(i<s.length())
	{
		if(s[i]=='?'||s[i]==t[j])
		{
			s[i]=t[j];
			j++;
		}
		if(j==t.length())
			break;
		i++;
	}
	while(i<s.length())
	{
		if(s[i]=='?')
			s[i]='a';
		i++;
	}
	if(j==t.length())
	{
		cout<<"YES\n"<<s<<endl;
	}
	else
		cout<<"NO"<<endl;
	return;
}

int main()
{
    Monjur_Morshed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
