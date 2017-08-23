### 452.Minimum-Number-of-Arrows-to-Burst-Balloons

将所有的气球按照右边界进行从小到大的排序。

按照排序后的右边界的值right进行遍历。对于所有未被射破的、左边界小于right的气球（此时他们的右边界必然大于right，因为right是从小到大遍历的），只要沿着right进行射击，就能最大效率地射破这些气球。

接下来寻找未被射破的下一个最小的right。
