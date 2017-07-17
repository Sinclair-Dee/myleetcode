#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int sum = nums[0];
        int max = sum;
        for(int i = 1;i<len;i++){
            sum = nums[i]+(sum>0?sum:0);
            //max储存每次加完一个数之后的最大值。
            if(sum>max) max = sum; 
        }
    return max;
    }
};
//test
int main(){
    int max;
    //example:
    int num[9]={-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums(num,num+8); //给vector赋初值的一种方式
    Solution solution;
    int sum = solution.maxSubArray(nums);
    cout<<sum<<endl;
    return 0;
}