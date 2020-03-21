### 1348.Tweet-Counts-Per-Frequency

这题要注意到，允许有在同一个时刻存在多个tweetName相同的帖子。因此我们应该采用multiset<int>来记录每个帖子出现的时间，并使之始终保持有序。

然后比较容易想到的是用```auto iter = Map[tweetName].lower_bound(startTime);```来定位第一个大于等于startTime的帖子。那么接下来如何有条理地求得每一个区间呢？

因为我们要记录所有的区间，所以我的建议是：从startTime开始，以delta为间隔，不停地往后爬。
```cpp
// 目标：考察[startTime, startTime+delta)区间内有几个元素
while (startTime <= endTime)
{  
  if (*iter落在这个区间里）
  {
    count++;
    iter++;
  }
  else // 这个区间里不可能再有其他元素了，就close这个区间，开启下一个
  {
    rets.push_back(count);
    startTime+=delta;
    count = 0;
  }
  
}
```

但是要特别注意，\*iter有可能虽然落在了区间里但是在endTime之外。所以第一个if语句要写成：
```cpp 
if (iter!=Map[tweetName].end() && *iter < startTime+delta && *iter<=endTime)
```


[Leetcode Link](https://leetcode.com/problems/tweet-counts-per-frequency)