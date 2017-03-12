###30. Substring-with-Concatenation-of-All-Words
典型的双指针算法题，常规思路：右指针一路前进，遇到不符合条件的情况就移动左指针直至消除负面条件，再接着移动右指针。
具体的实现比较复杂，需要注意这么几点：
1. 增加一个外层循环，双指针的起始点可以从0~M, M是每个词的长度
```cpp
        for (int begin=0; begin<M; begin++ )
        {
            int left=begin;
            int right=left;
            int count=0;
            showTime 映射要清零！
            ...
        }
```
2. 左右指针的移动幅度都是M
3. 当右指针加入的新元素不在字典中，记得要将count和showTime都清零！
4. 当右指针加入的新元素存在字典中，更新showTime和count。  
(a) 如果count++，考虑是否满足总条件count==Target，是的话就记录结果，左指针前移一步并更新showTime和count  
(b) 如果反而count--，说明当前新单词的出现次数过多了，同样需要让左指针不断前移并更新showTime和count，直到当前showTime[str]==Map[str]
5. 重复循环，让右指针前移一步，考虑下一个新元素。
