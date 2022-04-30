### 2245.Maximum-Trailing-Zeros-in-a-Cornered-Path

首先，作为常识，Trailing zero的个数只与因子2和因子5的个数有关。

对于任何类型的cornered path，他们都有“拐点”。假设我们考虑这个拐点(i,j)伸出去的两条“长臂”分别是向上和向右，那么我们只需要统计向上走到顶的路径里有多少个2（记做up2）和多少个5（记做up5），向右走到边界的路径里有多少个2（记做right2）和多少个5（记做right5）。那么这个这个cornered path的trailing zero的个数就是```min(up2+right2-self2, up5+right5-self5)```. 其中self2表示(i,j)自身还有多少个2.

因此，我们需要提前预处理，用前缀和的思想去计算每个位置的left2[i][j],right2[i][j],up2[i][j],down2[i][j]，以及对应的left5[i][j],right5[i][j],up5[i][j],down5[i][j]。然后遍历每个位置，认为其是拐点，考虑四种形状，对于每种形状，计算两条长臂总共有多少个因子2和因子5，就可以知道他们乘积的trailing zero了。
