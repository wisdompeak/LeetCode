### 274.H-Index

类似的题目里 275.H-Index II 给出排序后的citations，可以用双指针来做。本题中，考虑如果不先行排序的话，需要用到Hash表。

首先遍历数组，建立映射：引用数 -> 符合该引用数的文章数目。然后把Map放进pair类型的数组中，方便用sort直接排序。
```cpp
        for (int i=0; i<citations.size(); i++)
            Map[citations[i]]++;
        auto q = vector<pair<int,int>>(Map.begin(),Map.end());
        sort(q.begin(),q.end());
```        
然后对于q数组，从后往前考察：
```cpp
        int sum=0;        
        for (int i=q.size()-1; i>=0; i--)
        {
            if (q[i].first>sum+q[i].second) // 文章总数还小于citation量，可以尝试进一步扩大范围（考虑引用量更少的文章）
                sum+=q[i].second;
            else if (q[i].first==sum+q[i].second) // 文章总数恰好等于citation量，可以证明这就是最优解
                return q[i].first;
            else if (q[i].first<sum+q[i].second)  // 文章总数已经大于citation量，说明q[i]不可完全列入考虑范围。
                return max(q[i].first,sum);       // 这个操作非常关键！仔细思考。
        }
```



[Leetcode Link](https://leetcode.com/problems/h-index)