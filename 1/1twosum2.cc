#include <iostream>
#include <vector>
using namespace std;

class Solution {  
public:  
    vector<int> twoSum(vector<int>& nums, int target) {  
        vector<int> res;  
        int len = nums.size();  
        unordered_map<int,int> m;  
        for (int i = 0; i < len; i++){  
            if (m.count(target - nums[i])){  
                res.push_back(i);  
                res.push_back(m[target - nums[i]]);  
                return res;  
            }  
            m[nums[i]] = i;  
        }  
        return res;  
    }  
};  