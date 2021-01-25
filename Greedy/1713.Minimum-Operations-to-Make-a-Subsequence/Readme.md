### 1713.Minimum-Operations-to-Make-a-Subsequence

首先我们的目标是希望尽量多地在arr里面用到target已经存在的元素，并且这些元素在两个数组中都是subsequence（出现的先后顺序相同）。于是我们立刻就感觉本质就是求两个数组的longest common subsequence。这段LCS是arr所能利用的最大信息量，剩下的必须靠额外的插入了。

传统的LCS的DP算法需要o(MN)，这已经是最优的算法了，但在这里会超时，为什么呢？我们注意到题目中强调了target的每个元素是unique的。这个条件很不寻常。此时我们如果把target的元素抽象成[a,b,c,d,e...]，一切就柳暗花明了。我们其实需要在arr中找的就是尽量长的递增字母序列！这就是longest increasing subsequence的问题，可以用o(NlogN)的复杂度来解决。

所以此题的算法是，将target里面的所有元素顺次映射成1,2,3...，然后将target在arr里面的元素也都替换成对应的1,2,3...其他没有在target里出现的数字都忽略。于是我们可以计算target和arr的LIS。最终的答案就是target的长度减去LIS的长度。
