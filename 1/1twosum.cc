#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> num;
        bool flag = false
        for(int i=1;i<(target/2)+1;i++)
            if(i != target-i){
                sort(nums,num, i,target-i); 
            }
    return num;
    }
};
bool sort(vector<int>& nums,vector<int>& num, int i,j){
    for()
}


