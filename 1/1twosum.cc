//下边这种算法是不正确的，因为题目中没有说vector里的数学是正的还是负的。
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> num;
        for(int i = 0;i<(target/2)+1;i++){
            if(sort(nums,num, i,target-i))
                return num;
        }
    }
private:
    bool sort(vector<int>& nums,vector<int>& num, int idx1,int idx2){
        int cnt = 0;
        //if(idx1 == idx2) return false;
        for(int i =0;i < nums.size();i++){
            if(idx1 == nums[i]||idx2 == nums[i]){
                num.push_back(i);
                cnt ++;
            }
        if(cnt == 2) return true;
        }
        return false;
    }
};

int main(){
    int num[4]={0,3,2,0};
    vector<int> nums(num,num+4); //给vector赋初值的一种方式
    vector<int> sum;
    int target =6;
    Solution solution;
    sum = solution.twoSum(nums, target);
    return 0;
}

