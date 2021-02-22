### 1769.Minimum-Number-of-Operations-to-Move-All-Balls-to-Each-Box

本题的最优解可以用o(N)的复杂度实现。

我们令leftMoves[i]表示将i元素左边所有的盒子搬运过来需要的moves。我们有递推关系：```leftMoves[i] = leftMoves[i-1]+left[i]```，其中left[i]表示i元素左边盒子的数目。理解为两步走：先将i-1左边所有的盒子搬到i-1的位置上，然后将这些盒子都再搬一步到i的位置上。left[i]的递推关系也很明显：```left[i] = left[i-1]+ (boxes[i-1]=='1')```

同理我们也可以计算rightMoves[i]。那么最终的答案就是```rets[i] = leftMoves[i]+rightMoves[i]```.
