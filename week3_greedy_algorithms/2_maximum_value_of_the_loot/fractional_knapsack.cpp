#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

bool compare(pair<double,double> &p1,pair<double,double> &p2)
{
  return (double)(p1.first/p1.second) > (double)(p2.first/p2.second);
}

double get_optimal_value(int capacity, vector<pair<double,double>> array) {
  double value = 0.0;
  int n=array.size();
  sort(array.begin(),array.end(),compare);
  int i=0;
  int current = capacity;
  while(i<=n && current>0)
  {
    if(array[i].second>=current)  {
      value+= (double)(array[i].first/array[i].second) * current;
      current =0;
    }

    else
    {
        value+= array[i].first;
        current -= array[i].second;
        i++;
    }    
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<pair<double,double>> array(n);
  for (int i = 0; i < n; i++) {
    cin>> array[i].first >> array[i].second;
  }

  double optimal_value = get_optimal_value(capacity, array);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
