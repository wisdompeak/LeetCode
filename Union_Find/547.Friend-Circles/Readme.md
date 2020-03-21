### 547.Friend-Circles

注意，最后需要重新遍历一遍所有节点，通过FindSet来更新所有的父节点。
```cpp
        unordered_set<int>Set;
        for (int i=0; i<N; i++)
        {
            Father[i] = FindSet(i);
            Set.insert(Father[i]);
        }
        return Set.size();
```


[Leetcode Link](https://leetcode.com/problems/friend-circles)