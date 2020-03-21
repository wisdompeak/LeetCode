### 358.Rearrange-String-k-Distance-Apart

构建priority_queue<pair<int,char>>q; q的元素表示字符及其频次。注意到priority_queue默认大顶堆，自动按照频次从大到小排列。
```cpp
        unordered_map<char,int>Map;
        for (int i=0; i<s.size(); i++)
            Map[s[i]]++;
        
        priority_queue<pair<int,char>>q;
        for (auto a:Map)
            q.push({a.second,a.first});
```            
每次取q中的前K个元素（每个元素代表不同的字符）加入临时数组temp；取完后将这些temp里的元素的个数减一后再放回q中。直至某一回合，如果pq的字符种类个数小于K，但是该轮结束后temp非空，说明我们还需要往result里加字符，这样就会违法K个相邻字符不能有相同字符的规则，返回空。
```cpp
        while (!pq.empty())
        {
            int n = min(k, (int)pq.size());
            vector<pair<int,char>>temp;
            
            for (int i=0; i<n; i++)
            {
                int num = pq.top().first;
                int ch = pq.top().second;
                pq.pop();
                result+=ch;
                num--;
                if (num!=0) temp.push_back({num,ch});
            }
            if (n<k && temp.size()>0) return "";
            for (auto a:temp) pq.push(a);
        }
```


[Leetcode Link](https://leetcode.com/problems/rearrange-string-k-distance-apart)