#include <bits/stdc++.h>
using namespace std;

void solution(){

int n,sum=0;
cin>>n;
while (n>0)
{
    int last_digit=n%10;
    sum=sum+last_digit;
    n=n/10;
}
cout<<sum<<endl;
}

int main() {
int t;
cin >> t;
while(t--){
solution();
}
return 0;
}