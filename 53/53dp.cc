#include <iostream>
#include <vector>
using namespace std;
//时间复杂度为。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return dp(nums,0,nums.size()-1);
    }
private:
    int dp(vector<int>& nums,int start,int end){
        if()
        //divide and conquer
        int mid = (start+end)/2;
        int leftmax = dp(nums,start,mid);
        int rightmax = dp(nums,mid+1,end);
        
        
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