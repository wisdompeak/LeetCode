### 808.Soup-Servings

此题很好地考察了概率的概念。

不要被题目中“the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time” 里面的这个plus所迷惑。其实这是一个or的关系。

也就是说，当 soup A will be empty first 时，返回概率值1；当 A and B become empty at the same time 时，返回概率值0.5。如果这两种情况在各个分支中都出现过，那么就把这些条件概率值累加起来。

所以在递归函数中应该写成：
```cpp
double DFS(int A,int B)
{
  if (A<=0 && B>0) return 1;    // 边界条件：A先倒完
  if (A<=0 && B<=0) return 0.5; // 边界条件：AB同时倒完
  if (A>0 && B<=0) return 0;    // 边界条件：B先倒完
  return 0.25*(DFS(A-100,B)+DFS(A-75,B-25)+DFS(A-50,B-50)+DFS(A-25,B-75));
}
```
特别注意，第三个边界条件很重要。很多人根据题意，以为只要```A<=0||B<0```意味着A或B无法满足任何操作的时候才返回0。其实这个条件太宽松，隐藏着隐患。比如当```A==75,B==0```的时候，这个时候B已经先于A清空，两个胜利的条件（即AB同时清空或者A比B先清空）都肯定再无法满足，这个时候就应该即使返回0，否则放任下一步操作的话，依然可以合法地通过操作1在下一轮得到```A==0, B==0```，而这个状态是会被判定为胜利条件之一的，于是这部分概率就被误叠加到最终结果了。


[Leetcode Link](https://leetcode.com/problems/soup-servings)