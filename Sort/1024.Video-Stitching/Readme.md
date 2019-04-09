### 1024.Video-Stitching

此题非常类似 45.Jump Game II，整体就是一个贪心的策略。略微的差异就是我们需要预先将这些clips排序，排序的原则就是左端点靠前的优先，其次右端点靠后的优先。

我们维护一个[left,right]的区间，将所有左端点位于这个区间内的clips都扫描一遍，根据他们的右端点得到能够推进到最远的位置far。这表示一次操作能够推进的最大长度。然后更新left=right，right=far，得到更新后的[left,right]，重复之前的操作，直到抵达target。
