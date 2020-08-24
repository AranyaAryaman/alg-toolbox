#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using std::vector;
using namespace std;


vector<long long> optimal_sequence(long long m){
 
  long long count[m+1];
  count[0]=0;
  count[1]=0;
  count[2]=1;
  count[3]=1;
  vector<long long> sequence;
  long long n;

  for(n=4;n<=m;n++){
    if(n%3==0 && n%2==0){
      long long x= min(count[n/3]+1,count[n/2]+1);
      count[n] = min(x,1+count[n-1]);   
    }

    else if(n%3==0 && n%2!=0){
      count[n] = min(1+count[n-1],1+count[n/3]);
    }

    else if(n%3!=0 && n%2==0){
      count[n]= min(1+count[n-1],1+count[n/2]);
    }

    else
    {
      count[n] = 1+count[n-1];
    }
  }

  n=m;
  sequence.push_back(m);
  while(n>=1){ 
    if(count[n]==1+count[n-1]){
      sequence.push_back(n-1);
      n=n-1;
    }

    else if(count[n]==1+count[n/2]){
      sequence.push_back(n/2);
      n=n/2;
    } 

    else{
      sequence.push_back(n/3);
      n=n/3;
    }
  }
  reverse(sequence.begin(),sequence.end());
  sequence.erase(sequence.begin());
  return sequence;
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
