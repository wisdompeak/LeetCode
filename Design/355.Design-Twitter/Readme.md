### 355.Design-Twitter

设计如下的数据结构：    
unordered_map<int,set<int>>Friends; //记录每个用户的好友（包括自己）   
int global_id; // 全局变量，记录所有推文的时间顺序。    
unordered_map<int,vector<pair<int,int>>>Tweets; // 记录每个用户发推的global_id和tweetID。   

在getNewsFeed时，遍历所有好友的推文记录，寻找最近的10个。   
基本思路是构造一个数据结构news，每次放进一个推文，news能够自动保持根据global_id保持有序。什么数据结构能实现这个功能呢？有两个方案：priority_queue，或者有序set。考虑到set里的元素已经是pair，并且其自动排序就是依照pair的第一个key从小到大，在这里更为方便。
```cpp
        set<pair<int,int>>news;  //第一个key是推文的global_id，第二个才是其tweetId
        for (auto i:friends[userId]) //遍历所有userId的好友
        {
            for (int j=tweets[i].size()-1; j>=0; j--) //遍历该好友的所有推文，从最近的开始
            {
                if (news.size()<10)
                    news.insert(tweets[i][j]);   // 加入新元素后，news会自动排序
                else if (tweets[i][j].first> news.begin()->first)  //如果新元素比news的首元素更新，说明可以入列
                {
                    news.erase(news.begin());  //删除map的首元素
                    news.insert(tweets[i][j]);  //在map里加入元素
                }
                else
                    break;
            }
        }
```


[Leetcode Link](https://leetcode.com/problems/design-twitter)