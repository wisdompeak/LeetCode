### 642.Design-Search-Autocomplete-System

如果不用trie来做的话，可以比较简单地用priority_queue来实现对所有候选语句的排序，选择最终未被弹出的三个字符串。

核心代码非常简单：
```
    struct cmp
    {
        bool operator()(pair<string,int>a, pair<string,int>b)
        {
            if (a.second==b.second)
                return a.first<b.first;
            else
                return a.second>b.second;
        }
    };
    priority_queue<pair<string,int>,vector<pair<string,int>>,cmp>pq;              
    for (auto x:Map)
    {
         string a=x.first;
         if (match(data,a))
         {                
             pq.push({a,Map[a]});
             if (pq.size()>3) pq.pop();
         }
    }    
```    


[Leetcode Link](https://leetcode.com/problems/design-search-autocomplete-system)