#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        int res = reverse(x);
        string s = to_string(x);
        string sres = to_string(res);
        if(s == sres)
        return true;
    }
private:
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
    Solution solution;
    bool sulotion = solution.isPalindrome(1211);
    if(sulotion)
    cout<<"palindrome"<<endl;
    if(!sulotion)
    cout<<"not palindrome"<<endl;
    return 0;
}