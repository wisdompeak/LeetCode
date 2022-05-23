### 6077.Sum-of-Total-Strength-of-Wizards

根据套路，我们不会去枚举所有的subarray再找其中的weakest。相反，我们遍历每个元素将其作为weakest，再找对应的subarray。

假设位置在i的元素nums[i]，其prevSmaller在位置a，nextSmaller在位置b。那么以nums[i]为weakest的subarray，左边界可以在a与i之间任意间隙，记做有```x = i-a```种可能；右边界可以在i与b之间的任意间隙，记做有```y = b-i```种可能。
```
a X X X X i X X X b
```
也就是说，共有```x*y```种subarray符合条件。我们需要累加所有这些subarray的元素和。然后再乘以nums[i]本身，加入最终答案。

那么"累加所有这些subarray元素和"呢？对于上面的例子，无论subarray的右边界在哪里，nums[a+1]只会当左边界在a/a+1之间时被计入，即被统计了一次。同理，nums[a+2]会当左边界在位于a/a+1之间，或者a+1/a+2之间时被计入，即被统计了两次。依次类推，i左边的四个元素被计入的次数是：
```
a X X X X i X X X b
  1 2 3 4
```
所以他们对"累加所有这些subarray元素和"的贡献就是：```M = S * y```，其中``` S = nums[a+1]*1 + nums[a+2]*2 + nums[a+3]*3 + nums[a+4]*4 ...``` 乘以y是因为无论subarray的右边界在哪个位置，nums[i]左边的这些元素都会以一样的频次被计入subarray，所以要重复y次。

接下来考虑如何计算S。不难构造以index为权重的前缀和```presum2[i] = sum{nums[k]*k} for k=0,1,2,..i```，那么就有```presum2[i-1]-presum2[a] = nums[a+1]*(a+1) + nums[a+2]*(a+2) + nums[a+3]*(a+3) + nums[a+4]*(a+4) ...```。显然只要将其再减去常规的区间```sum[a+1:i]*a```，就是S了。综上即有```S = presum2[i-1]-presum2[a] - (presum[i-1] - presum[a]) * a```.

类似地，我们希望处理右边的情况，我们同样标记i右边的是三个元素被计入的次数：
```
a X X X X i X X X b
            3 2 1
```
同理，这里我们希望计算``` S = nums[i+1]*3 + nums[i+2]*2 + nums[i+3]*...```。我们同样可以利用presum和presum2，具体的是```S = (presum[b-1]-presum[i])*b - (presum2[b-1]-presum2[i])```. 于是nums[i]右边的三个元素对于"累加所有这些subarray元素和"的贡献就是```S*x```. 

此外，别忘了nums[i]本身对于"累加所有这些subarray元素和"的贡献是```nums[i]*x*y```.

所以以上三部分相加，再乘以nums[i]本身，就是以nums[i]为weakest的subarray的total strength.

本题还有一个注意点，就是如果subarray里面如果有多个位置出现了最小值，那么哪个算weakest？为了避免重复，我们可以约定最左边出现的最小值算该subarray的weakest。所以本题中我们在预处理时，实际需要求的是prevSmallerOrEqual和nextSmaller。类似的题目见```2104.Sum-of-Subarray-Ranges```.
