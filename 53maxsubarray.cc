#include <iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(int A[], int n) {
        long long ret = INT_MIN;
        long long cur = INT_MIN;
        for(int i = 0; i < n; i ++)
        {
            if(cur + A[i] > A[i])
                cur += A[i];
            else
                cur = A[i];
            ret = max(ret, cur);
        }
        return ret;
    }
};