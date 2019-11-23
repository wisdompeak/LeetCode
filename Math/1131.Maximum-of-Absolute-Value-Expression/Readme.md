### 1131.Maximum-of-Absolute-Value-Expression

在二维平面中，设距离最远的两点坐标为 (a1,b1) (a2,b2)， 则其曼哈顿距离为： |a1−a2|+|b1−b2|

去掉绝对值便有四种形式：
```
(a1−a2)+(b1−b2)，
(a1−a2)+(b2−b1)，
(a2−a1)+(b1−b2)，
(a2−a1)+(b2−b1)，
```
我们需要注意到，|a1−a2|+|b1−b2|其实就是这四个式子中的最大值，即
```
max {
(a1−a2)+(b1−b2)，
(a1−a2)+(b2−b1)，
(a2−a1)+(b1−b2)，
(a2−a1)+(b2−b1) }
```
变化一下就成了
```
max {
(a1+b1)−(a2+b2)，
(a1−b1)−(a2−b2)，
(−a1+b1)−(−a2+b2)，
(−a1−b1)−(−a2−b2) }
```
那么对于任意的i，j，我们有
```
|ai−aj|+|bi−bj|= max over (i,j){
  max {
      (ai+bi)−(aj+bj)，
      (ai−bi)−(aj−bj)，
      (−ai+bi)−(−aj+bj)，
      (−ai−bi)−(−aj−bj) }
}
```
调换两个max的顺序，即是
```
 max{
    max over (i,j)  {(ai+bi)−(aj+bj)},
    max over (i,j)  {(ai−bi)−(aj−bj)},
    max over (i,j)  {(−ai+bi)−(−aj+bj)},
    max over (i,j)  {(−ai−bi)−(−aj−bj)},
 }
```
显然，其中第一项
```
max over (i,j)  {(ai+bi)−(aj+bj)} 
=   max {ak+bk} for any k
  - min {ak+bk} for any k
```
于是，整个算法就是：k个维度的坐标(x1,...,xk)，就有2^k种状态。对于每一种状态(s1,..,sk)，（其中每种状态的分量都是+1或者-1）我们遍历所有元素i，计算 sum(xi\*si)里面的最大值mx和最小值mn，得到maxDiff = mx-mn。最终答案就是在所有状态对应的maxDiff中再取最大值。
