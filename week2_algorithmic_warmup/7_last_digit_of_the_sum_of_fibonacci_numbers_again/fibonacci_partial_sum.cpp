#include <iostream>
#include <vector>
using std::vector;

int fib(long long n)
{
    if (n==0) return 1;
    if (n==1) return 2;
    if (n==2) return 3;
    int F[n+3];
    F[0]=0;F[1]=1;
    for(long long i=2;i<=n+2;i++){
        F[i] = (F[i-1] + F[i-2])%10;
    }
    return F[n+2];
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    // std::cout<<fib(from-1)<<"\n";
    // std::cout<<fib(to)<<"\n";
    to = to%60;
    from = (from-1)%60;
    int x = (fib(to) - fib(from))%10;
    if(x>=0)
        std::cout << x << "\n";
    else
        std::cout<< 10+x << "\n";
}
