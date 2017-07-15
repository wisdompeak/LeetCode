### 354. Russian-Doll-Envelopes
此题的基本思路是先按照长度将所有信封排序（注意，对于pair类型的数组，sort的默认排序就是按照第一个index的大小递增排序），接下来按照宽度取最长递增子序列（LIS），得到的结果就是满足长度递增、宽度也递增的最长序列。

但是本题需要考虑长度相等的信封该怎么处理？长度相等的信封，不能互相嵌套，即在LIS中对应的长度必须都是唯一的。怎么办？    

技巧是，对envelopes排序的时候，除了按照长度递增排序，还按照宽度递减排序。这样对于长度相同的所有信封，不可能有两个或以上出现在按宽度排列的同一组LIS里面。
```cpp
    static bool cmp(pair<int,int>a, pair<int,int>b)
    {
        if (a.first!=b.first)
            return a.first<b.first;
        else
            return a.second>=b.second;
    }
```
