### 3635.Earliest-Finish-Time-for-Land-and-Water-Rides-II

其实有非常简单的贪心策略。

我们假设先乘坐land ride，那么必然会选择“最早结束”的那班，把结束时间记作minEnd. 然后我们考察所有的water rides：

1. 如果该班次startTime早于minEnd，那么此时就可以直接搭乘，结束时间就是minEnd 加上 Water Ride的durationTime.
2. 如果该班次startTime晚于minEnd，那么需要等待它开始，结束时间就是Water Ride的startTime + durationTime.

 遍历所有water ride后得到的最小值。然后将land和water的次序反过来再算一遍，取最小值。
