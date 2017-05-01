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
每次取q中的前K个元素（每个元素代表不同的字符）加入临时数组temp；取完后将这些temp里的元素的个数减一后再放回q中；直至q中的元素（不同字符种类）少于K个。
```cpp
        while (q.size()>=k)
        {
            vector<pair<int,char>>temp;
            
            for (int i=0; i<k; i++)
            {
                result+=q.top().second;
                temp.push_back(q.top());
                temp.back().first--;
                q.pop();
            }
            for (int i=0; i<k; i++)
            {
                if (temp[i].first>0)
                    q.push(temp[i]);
            }
        }
```
这时候查看，如果q中还有字符、并且字符的频次大于1的话，说明此时再取K个字符的话必定会造成重复。
```
        if (q.empty()) return result;  //已经恰取完，OK
        
        if (q.top().first>1)  //q中还有字符、并且字符的频次大于1的话，失败
        {
            result="";
            return result;
        }
        
        while (!q.empty())  //q中还有字符、并且字符的频次等于1，可以放心地加入result
        {
            result+=q.top().second;
            q.pop();
        }
        return result;
```        
