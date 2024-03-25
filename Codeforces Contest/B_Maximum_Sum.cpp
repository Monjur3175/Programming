#include <iostream>
using namespace std;
#define LL long long

const LL p=1e9+7;
int t,n,k;
LL a[210000],maxs,sum,s;

int main()
{
	cin>>t;
	while(t--) {
		cin>>n>>k; sum=0,s=0,maxs=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			sum+=a[i],s+=a[i];
			if(s<0) s=0;
			maxs=max(maxs,s);
		}
		s=maxs,sum-=maxs;
		for(int i=1;i<=k;i++) s=s*2%p;
		sum=((sum+s)%p+p)%p;
		cout<<sum<<endl;
	}
	return 0;
}