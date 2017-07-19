#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        
        if(x == 0) return 0;
        
        bool minus = false;
        if(x < 0) {
            minus = true;
            x = -x;
        }
        
        long long answer = 0;
        while(x) {
            answer = 10*answer + x % 10;
            x /= 10;
        }
        //此处的处理很妙！！！
        //如果answer移动31位还有数值，说明已经超出了整型数的范围
        if(answer >> 31) return 0;
        
        if(minus) {
            answer = -answer;
        }
        return answer;
    }
};


int main(){
    int samp;
    cin>>samp;
    Solution solution;
    int rever = solution.reverse(samp);
    cout<<rever<<endl;
    return 0;
}
