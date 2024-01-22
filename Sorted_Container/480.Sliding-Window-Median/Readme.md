### 480.Sliding-Window-Median

希望能够自动排序的容器，首选set或者multiset。对于这类非线性的容器，不能用+k或-k来实现迭代器的移动，必须用for循环不断++/--，或者使用next或prev。例如
```cpp
set<int>::iterator pos = next(Set.begin(),k); //从Set.begin()开始后移k个
set<int>::iterator pos = prev(Set.end(),k);  //从Set.end()开始前移k个
```
本题里设置一个multiset，初始化时用next命令把pos定位到最中间（Set容量为奇数）、或者中间靠右（Set容量为偶数）的那个迭代器。

每次一进一出的操作如下。对于k奇偶性通用的代码比较难理解，那就索性分别讨论容易理清思路。

```cpp            
        for (int i=k; i<=nums.size(); i++)
        {
            if (k%2==1) results.push_back(*pos);
            else results.push_back(*pos/2.0+*prev(pos,1)/2.0);
            
            if (i==nums.size()) break;
            
            Set.insert(nums[i]);
            
            if (k%2==1)   // 当k为奇数时，Set内的排列为 OXO，X为pos指针
            {
                if (nums[i]>=*pos)
                    pos++;
                                
                // 加入一个元素后，此时阵型为 OOXO
                if (nums[i-k]>*pos)
                    pos--;
                else if (nums[i-k]<*pos)
                    ;
                else if (nums[i-k]==*pos && *prev(pos,1)!=*pos)  
                    // 如果X左边是个重复元素，则无需改动；如果X左边不是重复元素，则X会被删除，指针需左移
                    pos--;                
            }
            else    // 当k为偶数时，Set内的排列为 OOXO，X为pos指针
            {
                if (nums[i]<*pos)
                    pos--;
                
                // 加入一个元素后，此时阵型为 OOXOO
                if (nums[i-k]<*pos)
                    pos++;
                else if (nums[i-k]>*pos)
                    ;
                else if (nums[i-k]==*pos)
                    // 如果X左边是个重复元素，则会删除那个O；如果X左边不是重复元素，则会删除X。两种情况下指针都需右移
                    pos++;
            }
            
            Set.erase(Set.lower_bound(nums[i-k]));     
        }
```

每次内循环之后，pos的定义不变（最中间或者最中间靠右的迭代器）。


[Leetcode Link](https://leetcode.com/problems/sliding-window-median)