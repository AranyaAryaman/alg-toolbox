#include<bits/stdc++.h>

using namespace std;

int optimal_weight(int n, const vector<int> &w) {
  int m = w.size();
   if(n==0||m==0) return 0;
   vector<vector<int> > A(n+1,vector<int>(m+1,0));
  //  for(int i=0;i<=n;i++)
  //     A[i][0]=0;
  //  for(int j=0;j<=m;j++)
  //     A[0][j]=0;
  //   if(m==1 && w[0]>n)  return 0;
  //   else return w[0];
   for(int i=0;i<=n;i++){
     for(int j=0;j<=m;j++){
        if(i==0||j==0) A[i][j]=0;
        else if(w[j-1]>i)  
          A[i][j]=A[i][j-1];
        else
          A[i][j]=max(A[i-w[j-1]][j-1]+w[j-1],A[i][j-1]);
     }
   }

   return A[n][m];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
