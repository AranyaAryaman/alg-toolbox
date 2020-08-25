#include <iostream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

// int edit_distance(const string &str1, const string &str2) {
//   int m=str1.size();
//   int n=str2.size();
//   if(n==0) return m;
//   if(m==0) return n;
//   int A[n+1][m+1];
//   for(int i=0;i<n+1;i++)
//     A[i][0]=i;
//   for(int j=0;j<m+1;j++)
//     A[0][j]=j;

//   for(int j=1;j<m+1;j++){
//     for(int i=1;i<n+1;i++){
//       int del = A[i-1][j]+1;
//       int ins = A[i][j-1]+1;
//       int diff = str1[i-1]==str2[j-1]?0:1;
//       int subs = A[i-1][j-1] + diff;
//       int x = min(del,ins);
//       A[i][j] = min(x,subs);
//     }
//   }
//   return A[n][m];
// }


int min(int x, int y, int z) 
{ 
    return min(min(x, y), z); 
} 
  
int editDistDP(string str1, string str2) 
{ 
  int m = str1.size();
  int n= str2.size();
  int dp[m + 1][n + 1];   
    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 

            if (i == 0) 
                dp[i][j] = j; 

            else if (j == 0) 
                dp[i][j] = i; 

            else if (str1[i - 1] == str2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1]; 
  
            else
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]); 
        } 
    } 
  
    return dp[m][n]; 
} 

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << editDistDP(str1, str2) << std::endl;
  return 0;
}
