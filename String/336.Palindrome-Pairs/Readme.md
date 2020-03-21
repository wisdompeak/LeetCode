### 336.Palindrome-Pairs

最直观的想法是将数组里的字符串两两比较，o(n^2)的时间复杂度，每次比较需要遍历两个字符串拼接后的全部长度，所以会超时。

AC的解法是构建一个集合，遍历字符串数组的过程中，将每个字符串与集合中已有的字符串进行考察，看是否有符合条件的配对。

首先，将字符串数组按照字符串长度从小到大排列：
```cpp
    static bool cmp(string a, string b)
    {
        return (a.size()<b.size());
    }

    sort(words.begin(),words.end(),cmp);
```
在遍历的过程中，假设string t=words[i];    
遍历t的长度，将t拆分为两部分s1和s2. 注意这样的拆分，可以使s1从空字符串一直变化到t。

考虑两种情况是符合要求的：   
1.s1的反序已经在集合中，并且s2本身就是回文，这样s1s2s1'构成回文；    
2.s2的反序已经在集合中，并且s1本身就是回文，这样s2's1s2构成回文。

然后就可以把t添加到集合中，考察下一个t。   
```cpp
        for (int i=0; i<words.size(); i++)
        {
            string t=words[i];

            for (int k=0; k<=t.size(); k++)
            {
                string s1=t.substr(0,k);
                reverse(s1.begin(),s1.end());
                string s2=t.substr(k,t.size()-k);
                if (Set.find(s1)!=Set.end() && palindrome(s2))
                    result.push_back({Map[t],Map[s1]});
                    
                s1=t.substr(0,k);
                s2=t.substr(k,t.size()-k);
                reverse(s2.begin(),s2.end());                
                if (Set.find(s2)!=Set.end() && palindrome(s1))
                    result.push_back({Map[s2],Map[t]});
                    
            }
            
            Set.insert(t);
        }
```


[Leetcode Link](https://leetcode.com/problems/palindrome-pairs)