### 877.Stone-Game

此题当N为偶数时，先手总是能够胜利。因为先手总是可以选择，他永远拿奇数堆，或者永远拿偶数堆。

比较值得锻炼的是当N为奇数的情况。我们知道肯定是用递归算法，但是该如何设计递归函数呢？比较好的一个选择是
```
int BestWin(arr,a,b)
```
表示我是先手来处理[a,b]堆时可以得到的最大值。那么先手取得最后胜利的条件就是：
```
int sum = accumulate(arr.begin(),a.end(),0);
int MyBest = BestWin(arr,0,N-1);
return MyBest>=sum-MyBest ? 1:2;
```
对于任意的[a,b]的情况，BestWin(arr,a,b)该如何转移下去呢？不要怕麻烦，逐一讨论：

1.我选择了a，那么对手可能选a+1，那么我会接下来先手处理 ```BestWin(arr,a+2,b)```; 对手也可能选b，那么我会接下来先手处理 ```BestWin(arr,a+1,b-1)```。那么对手究竟是会选什么呢？他会选择使得我在后期得利更小的那个方案。比如说，如果```BestWin(arr,a+2,b)>BestWin(arr,a+1,b-1)```，那么队手就会选择b。所以，只要我选择了a，那么我的最终得利就是 ```arr[a]+min(BestWin(arr,a+2,b),BestWin(arr,a+1,b-1))```.

2.同理分析，如果我选择了b，那么对手可能选a+1，也可能选择b-1，最终对手的决策依据是让我接下来的得利最小。所以我的得利会是 ```arr[a] + min(BestWin(arr,a+2,b-1), BestWin(arr,a,b-2))```.

然后，我在本轮的最终决策是上述两只之间的较大值。

此题的递归处理有点绕，保持清晰的思路就能写出简介的代码。


[Leetcode Link](https://leetcode.com/problems/stone-game)