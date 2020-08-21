#include <iostream>

int get_change(int m) {
  int tens,fives;
  tens = m/10;
  m -= tens * 10;
  fives = m/5;
  m -= fives * 5;
  return tens+fives+m;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
