### 480.Sliding-Window-Median

希望能够自动排序的容器，首选set或者multiset。对于这类非线性的容器，不能用+k或-k来实现迭代器的移动，必须用for循环不断++/--，或者使用next或prev。例如
```cpp
set<int>::iterator mid = next(Set.begin(),k); //从Set.begin()开始后移k个
set<int>::iterator mid = prev(Set.end(),k);  //从Set.end()开始前移k个
```
本题里设置一个multiset，初始化时用next命令把mid定位到最中间（k为奇数）、或者中间靠右（k为偶数）的那个迭代器。

每次一进一出的操作如下，这段代码对于k的奇偶性而言是通用的：

```cpp
            
        for (int i=k; i<=nums.size(); i++)
        {            
            results.push_back((*mid+*prev(mid,1-k%2))/2.0);  //读取或者计算median （根据k的奇偶性）
            if (i==nums.size()) return results;
                
            Set.insert(nums[i]); //注意，如果有多个相同key的元素，新加入的放在最后一个。
                
            if (nums[i]<*mid) mid--; 
                
            if (nums[i-k]<=*mid) mid++; //判断语句中必须加入==的情况，因为极有可能下一步删除的就是mid迭代器，那样的话mid就失效了，必须提前处理
                
            Set.erase(Set.lower_bound(nums[i-k])); //注意，如果有多个相同key的元素，删除的是第一个。           
        }
```        
每次内循环之后，mid的定义不变（最中间或者最中间靠右的迭代器）。
