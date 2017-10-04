### 253.Meeting-Rooms-II

此题用到了sort和pq的组合拳，是一类题目的典型。

先将intervals按照start进行从先到后排序。然后构建一个pq，按照end自动排序，end小的排在栈顶。pq表示当前正在同时进行的会议。

遍历intervals的元素，如果pq.top().end>intervals[i].start，说明正在进行的会议里，即使最早结束的那个，也都晚于当前考虑的会议intervals[i]的开始时间。没办法，但当前会议必须开，所以要将intervals[i]加入pq里面。pq的size因此变大。然后考虑下一个i，直至pq.top().end<=intervals[i].start。

然后将pq弹出最早结束的一个会议，重复之前的操作，会有新的会议加入需要同时举行。

输出结果就是pq在整个遍历过程中的最大size。
