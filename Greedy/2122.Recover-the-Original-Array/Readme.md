### 2122.Recover-the-Original-Array

我们将nums排序后，可以肯定的是，最小值一定是原先original里面的最小值mn减去k。那么如何能够知道mn或者k呢？自然我们想到original里面一定还存在mn+k，如果我们遍历元素并假设它是mn+k，那么我们就可以得到k，于是整个original的元素就可以试图从小到大依次确定下来（和LC 2007差不多的思想）；如果不成功就换一个元素作为mn+k。所以此题用o(N^2)可解。

更具体地，如果我们知道了k，可以用双指针的解法来确定original。将nums排序之后，我们设置left和right两个指针。对于nums[left]而言，我们一定是单调递增地移动right，试图寻找满足```nums[right]==nums[left]+2k```的位置。找到这对之后，将used[left]和used[right]都标记为1，这样在后续的寻找中，无论left和right都不能指向已经用过的位置。

双指针遍历的过程中，我们期望恰好找到n对。任何时候，left或right越界了，说明我们无法找到下一个合适的配对，就返回空集。
