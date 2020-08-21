#include <iostream>

int gcd_naive(int a, int b) {
  if(b>a) return gcd_naive(b,a);
  else if(a%b==0) return b; 
  else return gcd_naive(b,a%b);
}


long long lcm_naive(int a, int b) {
    int x= gcd_naive(a,b);
    long long l = (long long) a*b/x;
    return l;
}



int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
