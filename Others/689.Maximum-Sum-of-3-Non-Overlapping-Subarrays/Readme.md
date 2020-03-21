### 689.Maximum-Sum-of-3-Non-Overlapping-Subarrays

构建累加和数组LeftKSum[i]，表示在索引i左边（包括i）加和最大的连续k个数字；同理，rightKSum[i]表示索引i右边（包括i）加和最大的连续k个数字。这两个累加和数组都只要各扫一遍nums得到，是o(n)的计算量。

最终我们只要遍历第k到第N-2k-1个元素作为中间一个subarray的起始点，查看leftKSum[i-1]+sum(i~i+k-1)+rightKsum[i+k]的最大值即可。

因为此题还需要说出三个subarray的位置，所以我们多设一个LeftIdx和RightIdx，记录对应的索引位置，同构建LeftSum和RightSum的时候一起更新。


[Leetcode Link](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays)