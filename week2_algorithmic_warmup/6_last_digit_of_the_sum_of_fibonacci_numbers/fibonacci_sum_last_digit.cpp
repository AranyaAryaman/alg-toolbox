#include<iostream>
using namespace std;

int64_t fib_sum_digit(int64_t n)
{
    int fl[60] ={0};
    fl[0] = 0;
    fl[1] = 1;

    for(int i = 2 ; i<60 ; i++)
    {
        fl[i] = (fl[i-1] +fl[i-2])%10 ; 
    }


    int64_t sum = 0;

    for(int i = 1; i<=(n%60); i++ )
    {
        sum += (fl[i]);
    }

return sum%10;
}

int main()
{
     int64_t n;
    cin>>n;

    int64_t ans = fib_sum_digit(n);
    cout<<ans;

    return 0;
}