#include <bits/stdc++.h>
using namespace std;

int get_change(int m) {
    if(m==1 || m==3 || m==4)  return 1;
    if(m==2) return 2;
    int noc[m+1];
    noc[0]=0;
    noc[1]=1;
    noc[2]=2;
    noc[3]=1;
    noc[4]=1;
    for(int i=5;i<=m;i++){
      int x =min(1+noc[i-1],1+noc[i-3]);
      noc[i]=min(1+noc[i-4],x);
    }
    return noc[m];
    
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
