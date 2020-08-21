#include <iostream>

long long pisano(long long m)
{
    
    long long previous=0;
    long long current=1;
    long long i;
    for(i=1;i<m*m;i++){
        long long temp_previous = previous;
        previous = current;
        current = (temp_previous+ previous)%m;
        if(previous==0 && current==1)   return i;     
    }
}

long long fibonacci_fast(long long  n, long long m) {
    if (n<=1) return n;
    long long arr[n+1];
    arr[0]=0;
    arr[1]=1;
    for(long long i=2;i<=n;i++)
        arr[i]=(arr[i-1]+arr[i-2])%m;
    
    return arr[n];
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    long long val = pisano(m);
    //std::cout<<val<<"\n";
    long long x = n%val;
    //std::cout<<x<<"\n";
    x=fibonacci_fast(x,m);
    //std::cout<<x<<"\n";
    return x % m;
}

int main() {
    long long n,m;
    std::cin >> n >> m;
    //std::cout<<pisano(m)<<"\n";
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
