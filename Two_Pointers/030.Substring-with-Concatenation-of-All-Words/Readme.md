### 30. Substring-with-Concatenation-of-All-Words  
典型的双指针算法题，常规思路：右指针一路前进，遇到不符合条件的情况就移动左指针直至消除负面条件，再接着移动右指针。  
具体的实现比较复杂，需要注意这么几点：  
1.增加一个外层循环，双指针的起始点可以从0~M, M是每个词的长度. 注意count和showTime在每个start都要清零，故设置为循环内变量。 
```cpp
        for (int start=0; start<M; start++ )
        {
            int i=start;
            int j=start;
            int count=0;
            unordered_map<string,int> showTime;
            
            while (j<s.size() && i<=j)
            {
                ...
            }
        }
```
2.每次考察右指针对应的待加入的子串，
```cpp
                string ss = s.substr(j,M);
```
但不要着急移动右指针，进入如下的判断：

(a).待加入的新元素不在字典中，则count和showTime全部都清零！移动两个指针：都移到右指针的下一个位置
```cpp
                if (Map.find(ss)==Map.end())
                {
                    j+=M;
                    i=j;
                    count=0;
                    showTime.clear();
                }
```
(b).待加入的新元素在字典中，且没有溢出，则加入并更新统计。移动右指针。  
    注意，加入之后如果已经满足条件，则记录并处理。
```cpp
                else if (Map_temp[ss]<Map[ss])
                {
                    j+=M;
                    showTime[ss]++;
                    if (showTime[ss]==Map[ss])
                        count++;
                    
                    if (count==N)
                    {
                        results.push_back(i);
                        string tt = s.substr(i,M);
                        showTime[tt]--;
                        count--;
                        i+=M;
                    }
                }
```
  (c) 待加入的新元素虽然在字典中，但会造成溢出，则不加入统计。移动左指针，退出最左边的元素。
```cpp
                else
                {
                    string tt = s.substr(i,M);
                    showTime[tt]--;
                    if (showTime[tt]==Map[tt]-1)
                        count--;
                    i+=M;
                }
```
5.重复循环。


[Leetcode Link](https://leetcode.com/problems/substring-with-concatenation-of-all-words)