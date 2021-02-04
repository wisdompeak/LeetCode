### 1746.Maximum-Subarray-Sum-After-One-Operation

这就是在常规的max subarray sum的基础上，再套一个“是否使用自乘权力”的选择。令a表示截止到目前为止“没有使用该权力”得到的最大子区间sum，b表示截止到目前为止“已经使用过该权力”得到的最大子区间sum，

状态转移如下：
```
a = max(a+x, x)
b = max(a+x*x, x*x, b+x, x)
ret = max(ret, a, b)
```
注意，需要在每回合的时候都更新ret，因为最大区间和可能截止在任何位置。
