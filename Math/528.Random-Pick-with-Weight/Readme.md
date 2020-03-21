### 528.Random-Pick-with-Weight

计算权重函数的前缀和数组，这样得到了一个类似累积概率分布的数组```p=[w0,w0+w1,w0+w1+w2,...,W]```。这个新数组的最后一个元素代表这权重的总份数W。

我们取一个[0,W]上的均匀分布随机变量t，然后查看t在p中的位置。因为t落在p的哪个位置，是和p里面各个元素之间的“区间大小”直接相关的，所以t被随机在哪里，直接反映了p中各个元素被采样的概率。比如，t落在p_k和p_k+1之间，就意味着这个t对应于采样了第k+1个元素。“区间间隔”越大的元素，t就越可能落在那里。

这就是inverse probability distribution method. 思考：我们利用一个均匀随机变量t，如何实现采样一个新的随机变量s，使得s的概率密度函数是pdf？方法就是s = cdf_{-1}(t).


[Leetcode Link](https://leetcode.com/problems/random-pick-with-weight)