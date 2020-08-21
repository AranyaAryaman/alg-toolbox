#include <iostream>
#include <vector>

using std::vector;

vector<long long> optimal_summands(long long n) {
  vector<long long> summands;
  long long i;
  for(i=1;i<=n;i++){
    if(i*(i+1)/2 > n)
      break;
  }
  long long temp_sum=0;
  for(long long j=1;j<i-1;j++){
    summands.push_back(j);
    temp_sum+=j;
  }
  summands.push_back(n-temp_sum);
  return summands;
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
