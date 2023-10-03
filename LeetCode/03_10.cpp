#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    
    unordered_map<int, int> digits;
    vector<int> nums = { 1, 2, 3, 1, 1, 3 };
    /*
        (x*(x-1))/2
    */
    int res = 0;
    
    for (int n : nums) {
        digits[n]++;
    }
    
    for (pair<int, int> par : digits) {
        
        if (par.second > 1) {
            res += ( par.second*(par.second-1) ) / 2;
        }
        
    }
    
    
    cout << res;
    
    
    
    return 0;
}

