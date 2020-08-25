#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
  int m= a.size();
  int n= b.size();
  int count=0;
  if(m==0 || n==0)  return 0;
  int A[m+1][n+1];
  
  for(int i=0;i<=m;i++)
    A[i][0]=0;
  for(int j=0;j<=n;j++)
    A[0][j]=0;

  if(m==1){
    for(int i=0;i<=n;i++)
      if(b[i]==a[0])
        return 1;
    return 0;
  }

   if(n==1){
    for(int i=0;i<=m;i++)
      if(b[0]==a[i])
        return 1;
    return 0;
  }

  for(int i=1;i<m+1;i++){
    for(int j=1;j<n+1;j++){
      if(a[i-1]==b[j-1]){
        //cout<<i<<" "<<j<<"\n";
        A[i][j]= 1+ A[i-1][j-1];
      }
      else{
        A[i][j]= max(A[i-1][j],A[i][j-1]);
      }
    }
  }  

  /*for(int i=0;i<m+1;i++){
    for(int j=0;j<n+1;j++){
      cout<<A[i][j]<<" ";
    }
    cout<<"\n";
  }*/

  return A[m][n];

}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
