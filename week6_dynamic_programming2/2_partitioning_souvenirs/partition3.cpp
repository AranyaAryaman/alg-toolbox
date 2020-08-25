#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
using std::vector;

int partition3(vector<int> &A) {
  int sum=0;
  for(int i=0;i<A.size();i++)
    sum+=A[i];
  if(sum%3!=0)  return 0;
  int val = sum/3;
  for(int i=0;i<A.size();i++)
    if(A[i]>val) return 0;
  int x = A.size();
  if(x<3) return 0;
  vector<vector<int> > B(2*val+1,vector<int>(x+1,0));
  for(int i=0;i<2*val+1;i++)
    B[i][0]=0;
  for(int j=1;j<=x;j++)
    B[0][j]=0;
  for(int i=1;i<=2*val;i++){
    for(int j=1;j<=x;j++){
      B[i][j]=B[i][j-1];
      if(i>=A[j-1])
        B[i][j]= max(B[i][j],A[j-1]+B[i-A[j-1]][j-1]);
    }
  }
  
  //  for(int i=0;i<=2*val;i++){
  //    for(int j=0;j<=x;j++)
  //      cout<<B[i][j]<<" ";
  //    cout<<"\n";
  //  }
  return B[val][x]==val && B[2*val][x]==2*val;

}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
