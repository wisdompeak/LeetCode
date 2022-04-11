### 2234.Maximum-Total-Beauty-of-the-Gardens

很明显，我们要将所有的花园分为两部分，一部分是将其变为complete，另一部分是保持incomplete。相比之下，我们肯定是将那些flowers数值已经较大的花园变为complete更为合算，因为能省下更多的种植配额去提升那些incomplete花园的短板。

于是我们自然会将flowers数组从小到大排序。我们需要遍历两种花园的分界点i，即编号0到i的花园必须都是incomplete，编号i+1到n-1的花园必须都是complete。对于后者，我们很容易算出所需要额外种植的数目：即忽略已经超过target的花园，将那些未满target的花园补足至target。于是我们将这个需要补足的数目从newFlowers中减去，可以知道剩余的配额，将会用来处理那些认定是incomplete的花园（即编号从0到i的花园）。此外，根据规则，后者部分我们的收益是```(n-i)*full```.

ok，此时我们的任务就是，在0到i的花园里分配剩余的newFlowers，使得可以将这些花园里的最小数目最大化（因为这部分的收益函数是最小的数目乘以partial）。但是需要注意一点的是，因为我们认定了这些花园是incomplete的，它们注定都不能超过target-1. 所以我们需要考虑第一种情况，如果newFlowers配额非常充裕，我们可以将这些incomplete的花园都补足到target-1，于是可以得分```(target-1)*partial```. 

第二种情况，就是newFlowers配额有限，只能用于增补那些数目最少的花园，以提升短板。此时我们就要考虑将可以将短板提升至多少？所谓提升短板，就是说我们需要确定一个位置p，使得newFlowers可以将编号从0到p的花园都提升到同一个数值。这个p是怎么得到的呢，其实是因为newFlowers不够大，只能将编号0到p的花园提升到同一个数值，但是无法将编号0到p+1的花园提升到同一个数值。所以我们就明确了p的意义，即寻找最大的p，使得```sum[0:p] + newFlowers >= flowers[p]*(p+1)```，或者说```flowers[p]*(p+1) - presum[p] <= newFlowers```。 我们令```diff[p] = flowers[p]*(p+1) - presum[p]```，即表示将前p+1个花园都提升至flowers[p]的数量所需要额外种植的配额，那么diff数值显然是个单调增函数，我们必然可以用二分法确定这个临界位置p。有了这个临界位置p，那么我们就可以用```(presum[p]+newFlowers) / (p+1)```来计算我们将前p+1个花园的短板最大提升至多少。

所以本题的时间复杂度是o(NlogN)，外层就是遍历incomplete/complete的分界点i，内部就是二分查找短板的范围p。

事实上p肯定也是单调从大到小变化的，所以搜索的过程理论上可以优化至o(N)，不过因为我们最开始需要对flowers排序，这点优化就没有必要了.
