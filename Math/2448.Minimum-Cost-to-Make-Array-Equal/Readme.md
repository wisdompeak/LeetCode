### 2448.Minimum-Cost-to-Make-Array-Equal

#### 解法1：
如果本题的所有cost[i]都是1的话，我们发现这其实就是`296.Best-Meeting-Point`。我们应该对这个结论很熟悉：对于一维序列{xi}，我们想找一个位置p使得`sum{abs(xi-p)}`最小化，那么p的位置一定就是{xi}的中位数。

对于本题而言，我们想找一个位置p使得`sum{abs(xi-p)*cost[i]}`最小化。这其实可以卡成将每个xi复制cost[i]份，从而得到一个长度为totalCost的序列，然后回归到上述的问题。显然，我们想要找的位置就是新序列的中位数。我们只需要每查看一个xi，就增加`count+=cost[i]`，直至发现count恰好超过了totalCost的一半时候为止，这个xi就是best equal value.


#### 解法2：
对于这类题目，我们通常会有一个大胆的猜测，最优解所对应的“best equal value”一定是nums里的某一个元素。为什么呢？假设这个best equal value是x，位于排序后的某两个元素之间（记做nums[i]和nums[j]），那么我们可以论证还会有比x更优的解。假如我们将equal value设为x+1，那么对于右边的元素，总共会减少costSum[j:n-1]，对于左边的元素，总共会增加costSum[0:i]，即`delta1 = costSum[0:i]-costSum[j:n-1]`. 假如我们将equal value设为x-1，类似的会有`delta2 = -costSum[0:i]+costSum[j:n-1]`。通常情况下delta1和delta2必然是一正一负，这就意味着必然有一个方向能够得到更优的策略（即x+1或者x-1）。这个方向的移动可以持续，直至best equal value设置在了nums[i]或者nums[j]上。

有了这个想法，我们只需要遍历一遍每个nums[i]，假想它是equal value的话，cost是多少。cost包括了左边元素的提升costLeft，以及右边元素的下降costRight。我们从左往右遍历的时候，costLeft都是可以一路累加的，即`costLeft[i] = costLeft[i-1]+costSum[i:i-1]*(nums[i]-nums[i-1])`. 同理我们从右往左走一遍，求得所有的costRight[i]。最终我们挑选最小的`costLeft[i]+costRight[i]`.
