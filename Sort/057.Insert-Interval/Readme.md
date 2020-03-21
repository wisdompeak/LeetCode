### 057.Insert-Interval

#### 解法1：标准的插入
将intervals的所有元素全部遍历一遍，可以想见会依次遇到这些情况：    
1. intervals[i]如果整体都在newInterval之前，则可以直接将intervals[i]加入results;
2. intervals[i]如果和newInterval有交集，则与之融合生成新的newInterval；这样的融合可能会有若干次； 
```cpp
  while (i<intervals.size() && !(intervals[i].start>newInterval.end))
  {
     newInterval.start = min(newInterval.start,intervals[i].start);
     newInterval.end = max(newInterval.end,intervals[i].end);
     i++;
  }
```
3. intervals[i]如果整体都在newInterval之后，则将newInterval（可能经历了融合）加入results，并把未遍历的intervals[i]也都加入results; 

#### 解法2：priority_queue
将所有intervals都放入一个priority_queue里，使其能按照start从小到大自动排序。    
每次取出栈顶元素，如果它与栈顶的第二个元素不重合，则将其加入结果数组；如果栈顶元素与栈顶的第二个元素区间重合，则将二者融合之后再次扔进这个priority_queue里。如此循环直至队列空。


[Leetcode Link](https://leetcode.com/problems/insert-interval)