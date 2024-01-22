### 2926.Maximum-Balanced-Subsequence-Sum

很明显，变形一下式子就有```nums[i_j] - i_j >= nums[i_(j-1)] - i_(j-1)```. 我们令新数组`arr[i] = nums[i]-i`，我们就是想要在arr里面找一个递增的subsequence，记做{k}，使得这个subsequence对应的 {nums[k]} 的和能够最大。

很容易看出可以用o(N^2)的dp来做。令dp[i]表示以i为结尾的递增subsequence的最大nums之和。那么就有
```cpp
for (int i=0; i<n; i++)
  for (int j=0; j<i; j++)
    if (arr[j] < arr[i])
      dp[i] = max(dp[i], dp[j] + nums[i]);
```
接下来考虑如何降低时间复杂度。我们看到第二个循环的效率不是很高，这个遍历里面满足if条件的位置j是不固定的。我们设想如果i之前的dp已经按照arr的数值放入一个有序容器中，我们就只需要遍历dp的某个前缀即可. 于是我们重新定义dp[x]表示以数值x为结尾的的递增subsequence的最大nums之和，并且dp是按照x从小到大排序的容器。
```cpp
for (int i=0; i<n; i++)
{
  int x = arr[i];
  for (int y: sorted(arr[0:i-1]) & y < x)    
      dp[x] = max{dp[y]} + nums[i];
}  
```
在某一个前缀数组里查询最大值，这可以用线段树来实现。在这里，我们介绍另外一种更好写的方法。

我们知道，dp本质是一个map，是按照key的大小排列的有序容器（其中key就是arr的值）。但是我们还可以给它加一个属性：让其value也保持递增。这个哲学思想就是，对于dp里存在 dp[a]=A, dp[b]=B，且a<b, A>=B，那么对于任何一个新元素arr[i]=x，我们如果可以把x接在b后面构造子序列，那么显然不如我们把x接在a后面构成子序列更优。这样我们就可以把b从dp里弹出去。

所以我们将dp按照key和value都递增的顺序排列后，一个最大的好处出现了。对于任何一个新元素arr[i]=x，我们不需要在dp里遍历所有key小于x的元素，只需要知道恰好小于等于x的key（假设是y），那么就有`dp[x]=dp[y]+nums[i]`。任何key比y小的元素，虽然都可以接上x，但是它们的value并没有dp[y]有优势。

当我们确定dp[x]的最优值之后，再将x插入dp里面。记得此时要向后依次检查比x大的那些key，看它们的value（也就是dp值）是否小于dp[x]，是的话就将他们弹出去。

时间复杂度：对于任何的arr[i]=x，我们在dp里面按照key二分查询恰好小于等于x的key，是log(n)。所以总的时间复杂度是o(NlogN). 有人会问，似乎每个回合，都有线性弹出的操作，但其实总共你最多只会弹出N个元素，这个弹出操作的总是也只是o(N)，与循环无关。


