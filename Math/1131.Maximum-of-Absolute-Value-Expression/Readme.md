### 1131.Maximum-of-Absolute-Value-Expression

本题的本质就是求一堆三维空间内的点，找出曼哈顿距离最大的一个。其中每个点的坐标就是(arr1[i],arr2[i],i). 这个问题如何求解呢？我们先来解决更简单点的问题，也就是在一堆二维空间中的点如何找到曼哈顿距离最远的两个。

在二维平面中，设曼哈顿距离最远的两点坐标为 (a1,b1) (a2,b2)， 则其曼哈顿距离为： |a1−a2|+|b1−b2|

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
max |ai−aj|+|bi−bj|= max over (i,j){
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


[Leetcode Link](https://leetcode.com/problems/maximum-of-absolute-value-expression)