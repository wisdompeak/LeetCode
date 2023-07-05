### 2747.Count-Zero-Request-Servers

我们先将所有的server request排序。再将query按照时间顺序排序之后逐个处理，不难发现这就是一个固定长度的滑窗。我们需要计算的就是每处滑窗位置时，里面包含了多少个不同的server request。

更具体地，我们用一个Hash表来维护滑窗内的server。当处理某个query对应的时段[t-x,t]时，我们将所有小于等于t的request加入Hash表，同时将小于t-x的request移出Hash表。此时Hash表内的key的数目就是non-zero request servers. 此外，当处理下一个query对应的时段时，在request序列上的滑窗必然是单调移动的。
