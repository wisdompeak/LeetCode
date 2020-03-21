### 460.LFU-Cache

本题用到了STL里的一个新的数据结构，list。list和vector的用法差不多，但其在内存中的存储并不是线性的，而是链表状的，所以它的插入、删除都很方便（因为已经被封装好了，我们不必实现链表插入、删除的细节）。

删除list中一个元素，可以有这些操作：pop_front(), pop_back(), erase(iterator);     
在list中加入一个元素，push_back(value), 其对应的iterator就是 --List.end()

本题的数据结构需要如下三个：
```cpp
    int cap, minfreq;
    unordered_map<int,pair<int,int>>Map; // key -> value, freq;
    unordered_map<int,list<int>>freq; // freq -> keys
    unordered_map<int,list<int>::iterator>iter; // key -> the iterator of key in freq
```
Map记录了一个key所对应的value和操作频率；    
freq记录了对应一个操作频率的key有哪些；   
iter记录了对应一个key，其在freq数据结构中的迭代器（或者说指针、内存位置）。   

对于get函数：
```cpp
    int get(int key) 
    {
        if (Map.find(key)==Map.end()) return -1;
        int f=Map[key].second;
        freq[f].erase(iter[key]); // 原频次f里去除key，通过迭代器iter[key]来删除。
        freq[f+1].push_back(key);  // 新频次f+1里增加key，直接塞在链表的最末
        iter[key]=--freq[f+1].end();  //key的迭代器位置需要更新，现在是在freq[f+1]的链表末尾
        Map[key].second++;    // Map[key]的信息
        if (freq[minfreq].size()==0)
            minfreq++;
        return Map[key].first;
    }
```    

对于put函数
```cpp
    void put(int key, int value) 
    {
        if (cap<=0) return;
        if (get(key)!=-1)  //已经收录了这个key，则get(key)包括了更新频次的操作
        {
            Map[key].first=value;  //此时只需要更新value
            return;
        }
        else
        {
            if (Map.size()>=cap)
            {
                int minKey=freq[minfreq].front();  //找到需要弹出的minKey，位于freq[minfreq]链表的最前端
                iter.erase(minKey);     //不再需要保留记录这个minKey的迭代器地址
                Map.erase(minKey);      //不再需要保留记录这个minKey的值信息
                freq[minfreq].pop_front();  //频次映射里也不再需要保留记录这个minKey的频次信息
            }
            Map[key]={value,1};
            freq[1].push_back(key);   //频次为1的映射里需要添加这个key
            iter[key]=--freq[1].end();  //迭代器映射里要添加这个key的指针地址
            minfreq=1;
            return;
        }
    }
```


[Leetcode Link](https://leetcode.com/problems/lfu-cache)