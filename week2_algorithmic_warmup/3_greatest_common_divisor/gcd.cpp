#include <iostream>

int gcd_naive(int a, int b) {
  if(b>a) return gcd_naive(b,a);
  else if(a%b==0) return b; 
  else return gcd_naive(b,a%b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}
