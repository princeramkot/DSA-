#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define reads(x) string x; cin>>x
#define readl(x) long long x; cin >> x
using namespace std;
 

int buildSt(int arr[],vector<int>&st, int start,int end,int currentIndex){
	
	if(start==end){
		st[currentIndex]=arr[start];
		return arr[start];
	}

	int leftChild = 2 * currentIndex+1;
	int rightChild = 2 * currentIndex+2;
	
	int mid=start+(end-start)/2;
	
	st[currentIndex]=min(buildSt(arr,st,start,mid,leftChild) , buildSt(arr,st,mid+1,end,rightChild));
	
	return st[currentIndex];
}


int getMin(int arr[],int start,int end,vector<int>&st,int l, int r,int currentIndex){
	
	
	if(end<l || start>r)
	return INT_MAX;
	
	else if(start>=l && end<=r)
	return st[currentIndex];
	
	
	int mid=start+(end-start)/2;
	
	return min(getMin(arr,start,mid,st,l,r,2*currentIndex+1) , getMin(arr,mid+1,end,st,l,r,2*currentIndex+2));
	
}

int updateSt(vector<int>&st, int start, int end, int index, int newVal, int currentIndex){
	
	if(index<start || index> end)
	{
		return st[currentIndex];
	}
	
	
	if(start==end && start==index)
	{
		st[currentIndex]=newVal;
		return newVal;
	}
	else if(start==end){
		return st[currentIndex];
	}
	
	else{
	
		int mid=start+(end-start)/2;
		st[currentIndex]=min(updateSt(st,start,mid,index,newVal,2*currentIndex+1),updateSt(st,mid+1,end,index,newVal,2*currentIndex+2));	 
	}
	 
}

int main() {
 
int arr[]={4,2,1,5,3,2,1};
int sz=7;


    //Height of segment tree 
    int x = (int)(ceil(log2(sz))); 
    int max_size = 2*(int)pow(2, x) - 1; 

	vector<int>st(max_size,INT_MAX);
	
	buildSt(arr,st,0,sz-1,0);

	int input=3;
	while(input!=0){
		
		cout<<"1 -> To get min from l to r "<<endl;
		cout<<"2 -> To Update Value at any Index "<<endl;
		cout<<"3 -> To Print Array "<<endl;
		cin>>input;
		
		if(input==1){
			cout<<"Enter l and r"<<endl;
			int l,r;cin>>l>>r;
			if(l<1 || l>sz || r>sz || r<1)
			cout<<"Invalid Range"<<endl;
			else
			cout<<getMin(arr,0,sz-1,st,l-1,r-1,0)<<endl;
		}
		else if(input==2){
			int index,value;
			cout<<"Enter index and value "<<endl;
			cin>>index>>value;
			index--;
			if(index>=0 && index<=sz-1){
				arr[index]=value;
				updateSt(st,0,sz-1,index,value,0);
				cout<<"Done"<<endl;
			}
			else cout<<"Invalid Index"<<endl;
		}
		else if(input==3){
			for(int i=0;i<sz;i++)
			cout<<arr[i]<<" ";
			cout<<endl;
		}
		else break;
		
	}


	

   return 0;
}
