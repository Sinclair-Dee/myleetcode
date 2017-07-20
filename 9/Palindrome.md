## An easy c++ 8 lines code (only reversing till half and then compare)
```
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};
```
-原作者的代码写的巧妙，主要思想就把一个数整型数拆成两部分， 后半部分作reserse处理。
-两边比较，注意如果数x是基数位，要把中间的数除去。