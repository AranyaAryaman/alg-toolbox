#include <iostream>

int fib(long long n)
{
    if(n<=1) return n;
    int A[n+1];
    A[0]=0;A[1]=1;
    for(int i=2;i<=n;i++){
        A[i]=(A[i-1]+A[i-2])%10;
    }
    return A[n];
}

int fibonacci_sum_squares_naive(long long n) {
    int x = fib(n%60);
    int y = fib((n+1)%60);
    return (x*y)%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
