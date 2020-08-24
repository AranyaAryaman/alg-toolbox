#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

int bin(int q,int n,int arr[]){
    int l = 0;
    int r = n-1;
    while(l<=r){
        int mid = floor(l+(r-l)/2);
        if(arr[mid]==q)
            return mid;

        else if(arr[mid]<q)
            l = mid+1;
        else
            r = mid-1;
    }

    return -1;
}


int32_t main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int k;
    cin>>k;
    int b[k];
    for(int i=0;i<k;i++)
        cin>>b[i];

    vector<int> v;

    for(int i=0;i<k;i++){
        v.push_back(bin(b[i],n,a));
    }

    for(int s:v)
        cout<<s<<" ";
    return 0;
}