### 355.Design-Twitter

设计如下的数据结构：
unordered_map<int,set<int>>Friends; 记录每个用户的好友（包括自己）   
int global_id; 全局变量，记录所有推文的时间顺序。    
unordered_map<int,vector<pair<int,int>>>Tweets; 记录每个用户发推的global_id和tweetID。   

在getNewsFeed时，遍历所有好友的推文记录，寻找最近的10个。基本思路是构造一个数据结构news，每次放进一个推文，它能够自动保持根据global_id保持有序。怎么实现这个功能呢？有两个方案：priority_queue，或者有序map（set亦可）。
