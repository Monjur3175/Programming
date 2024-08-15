#include <bits/stdc++.h>
using namespace std;

void solve(vector <int> v){
  int n=v.size();
  int s1=0,s2=0;
  for(int i=0;i<n;i++){
      s2+=v[i];
  }
  int count=0;
  for(int i=0;i<n;i++){
      s1+=v[i];
      s2-=v[i];
      if(v[i]==0&&(s1==s2+1||s2==s1+1)){
          count++;
      }
     else if(v[i]==0&&s1==s2){
         count+=2;
     }
     
  }
   cout<<count<<endl;
}

int main() {
	int t,l=0;
	cin>>t;
	vector<vector<int>> v(t);
	while(t--){
	    int n;
	    cin>>n;
	   for(int i=0;i<n;i++){
	       int x;
	       cin>>x;
	       v[l].push_back(x);
	   }
	   l++;
	}
	for(int i=0;i<l;i++){
	    solve(v[i]);
	}
}