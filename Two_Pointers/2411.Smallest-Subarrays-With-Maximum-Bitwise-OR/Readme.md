### 2411.Smallest-Subarrays-With-Maximum-Bitwise-OR

我们设想，对于i而言，如果将这个区间的右边界j设置为n-1，那么必然能够得到Maximum Bitwise OR，记做OrSum. 我们该如何减小这个区间但是又不影响OrSum的值呢？最基本的想法就是，先尝试看看去掉nums[j]，答案还是OrSum吗？我们如何验证呢，是将[i,j-1]区间内的所有元素再做一遍OR操作吗？显然这个效率太低了。

我们这样思考：如果去掉nums[j]对于OrSum没有影响，说明对于nums[j]里某个是1的bit位而言，nums[i:j-1]里必然已经有至少一个元素在该bit位上是1了。 这就提示我们需要统计一下nums[i:j]里面在每个bit位上的1的总个数。举个例子：如果对于某个bit位，区间[i:j]里面有三个1，且nums[j]本身就是1，那么如果把j刨除这个区间后，OR[i:j-1]在这个bit位上不受影响。再比如，如果对于某个bit位，区间[i:j]里面只有一个1，且nums[j]本身就是1，那么如果把j刨除这个区间后，OrSum[i:j-1]在这个bit位上就是0了，显然就不会是maximum Bitwise OR了，所以我们不能将j排除。

所以如果我们已知一个区间[i:j]能够得到关于i的maximum bitwise or，并且有如上的count计数器（记录32个bit位里的1的个数），那么能否缩小右区间的范围j，就看
```cpp
for (int k=0; k<32; k++)
{
  if (count[k]==1 && ((nums[j]>>k)&1) {
    return false;
  }
}
return true;
```
根据以上的check函数，我们就可以一路缩小j，直至得到关于i的最小的subarray。

那么此时我们想得到关于i-1的答案，是否需要重新将j放回n-1的位置，重复以上的步骤呢？其实不必。因为我们已知[j+1:n-1]的各个位置上的1bit都完全与[i:j]区间重复了。因为[i:j]的存在，[j+1:n-1]这部分区间对于i-1而言也是没有用的。所以当我们考察i-1的答案时，不需要重置j，直接继承i对应的区间右端点即可。
