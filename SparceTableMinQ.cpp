#include<bits/stdc++.h>

#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define modi 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) long long x; cin >> x

#define reads(x) string x; cin>>x
#define nl "\n" 
#define int long long
#define ll  long long
#define ull  unsigned long long
#define line cout<<"#####################################################################"<<endl;
#define pr cout<<
#include <cmath>
#define test cout<<"Here"<<endl;
using namespace std;
template <typename T> T debug(T x, T y)
{
    cout<<"--> "<<x<<" "<<y<<nl;
}
template <typename T> T debug(T x)
{
    cout<<"--> "<<x<<nl;
}
ll comp(int a, int b){
	if(a==b)return 0;
	return a>b?-1:1;
}
ll Ceil(ll x,ll y){
    if(x%y==0) return (x/y);
    return (x/y)+1;
}



void buildSparseTable(vector<int>arr,vector<vector<int>>&sparseTable,int size){
	
	
	for(int i=0;i<size;i++){
		sparseTable[0][i]=arr[i]; 
	}
	
	for(int i=1;i<sparseTable.size();i++){
		for(int j=0;j+(1LL<<i)<=size;j++){
			sparseTable[i][j]=min(sparseTable[i-1][j],sparseTable[i-1][j+(1LL<<(i-1))]);
		}
	}
	
}
int getMinSparce(int l,int r,vector<vector<int>>&sparseTable){
	int diff=r-l+1;
	int k=log2(diff);
	return min(sparseTable[k][l], sparseTable[k][r - (1LL<<k) +1 ]);
}
signed main() {
	
	
	int n;cin>>n;
	vector<int>arr(n);
	for(auto &i:arr)
	cin>>i;
	
	int q;cin>>q;
	
	int size=arr.size();
	int sz=log2(size);
	vector<vector<int>>sparseTable(sz+1,vector<int>(size));
	buildSparseTable(arr,sparseTable,size);
	
	
	while(q--){
		int l,r;cin>>l>>r;
		cout<<(getMinSparce(l,r,sparseTable))<<endl;
	}
	


   return 0;
}
