#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:  
    vector<int> twoSum(vector<int>& nums, int target) {  
};

int main(){
    int num[4]={1,3,2,6};
    vector<int> nums(num,num+4); //给vector赋初值的一种方式
    vector<int> sum;
    int target =7;
    Solution solution;
    sum = solution.twoSum(nums, target);
    int sum0 = sum[0];
    int sum1 = sum[1];
    cout<<"["<<sum0<<","<<sum1<<"]"<<endl;
    return 0;
}

