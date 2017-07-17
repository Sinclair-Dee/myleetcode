#include <iostream>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        while(n){
           sum += n/5;
           n /= 5;
        }
    return sum;
    }
};
int main(){
    int sum;
    Solution solution;
    sum = solution.trailingZeroes(686);
    cout<<sum<<endl;
    return 0;
}