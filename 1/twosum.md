##　C++11 新特性： unordered_map 与 map 的对比

unordered＿map和map类似，都是存储的key-value的值，可以通过key快速索引到value。
不同的是unordered＿map不会根据key的大小进行排序。

代码片段：
```
        vector<int> res;  
        int len = nums.size();  
        unordered_map<int,int> m;  
        for (int i = 0; i < len; i++){  
            if (m.count(target - nums[i])){  
                res.push_back(m[target - nums[i]]);  
                res.push_back(i);  
                return res;  
            }  
            m[nums[i]] = i;  
        }  
        return res;  
    }  
```
-建立unordered_map数据类型，key为map中的元素，value为其对应的下标。
-遍历输入nums中的元素，判断target-i是不是nums中的元素，如果是的话则说明已经找到了相加为target的两个数。
-如果没有找到就把该数字i放到map中，for语句继续运行。直到找到两个目标数。
-返回两个数组成的vector.