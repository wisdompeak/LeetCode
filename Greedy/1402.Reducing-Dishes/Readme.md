### 1402.Reducing-Dishes

两个突破点。首先我们肯定会把dishes按照满意度排序，满意度高的肯定放在后面做。其次，在选取相同数目的dishe的前提下，我们肯定会取满意度最高的若干个。于是答案的本质就是选多少dishes。

于是我们就是要尝试取最高的1个，或者2个，或者3个...，直至n个满意度最高的dishes，计算最后总得分，取最大值。

这里有个化简计算的方法。我们将dishe按照满意度从高到低排列。如果取一个，答案是```satisfaction[0]```；如果取两个，答案是```2*satisfaction[0] + satisfaction[1]```；如果取三个，答案是```3*satisfaction[0] + 2*satisfaction[1] + satisfaction[2]```。可见答案每次都在前者的基础上增加```presum[i]```，其中presum是satisfaction的前缀和。
