#include <iostream>
using namespace std;
class Solution {
public:
   int reverse(int x) {
       const int max = 0x7fffffff;//int 的最大值
       const int min = 0x80000000;//int 的最小值
       long long sum = 0; //中间过程可能出现相加为long long的情形
       while(x){
           int temp = x%10;
           sum =sum*10 + temp;
           x = x/10;
           if(sum < min ||sum >max) 
                return sum >0?max:min;
       }
       return sum;
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
