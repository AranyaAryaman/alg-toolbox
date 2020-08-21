#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int current_refill=0;
    int number_of_refills=0;
    int last_refill;
    while(current_refill<stops.size()-1){
        last_refill=current_refill;
        while(current_refill<stops.size()-1 && stops[current_refill+1]-stops[last_refill]<=tank){
            current_refill++;
        }
        if(current_refill==last_refill)
            return -1;
        if(current_refill<stops.size()-1) number_of_refills++;
    }
    return number_of_refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+2);
    stops[0]=0;
    for (size_t i = 1; i < n+1; ++i)
        cin >> stops.at(i);
    stops[n+1]=d; 
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
