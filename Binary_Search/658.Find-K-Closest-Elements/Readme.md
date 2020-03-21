### 658.Find-K-Closest-Elements

容易想到的基本思路是，找一个k-size的滑窗，使得x-arr[left]和arr[right]-x尽量地接近。以此为依据，调整起始点left的二分搜索范围。但这种二分法，最后的收敛结果并不一定是最终理想的k-size滑窗的起始点。

有一个非常NB的方法。同样是调整起始点left的二分搜索范围，但是查看的是长度为k+1的滑窗。因为这个窗口有k+1个元素，肯定有一个元素不属于k-closest element，容易知道，这个不合格的元素肯定就是arr[left]和arr[left+k]中的一个！那怎么判断是其中哪一个呢？就找其中“相对不合格”的那个。

1. 如果```x-arr[left] > arr[left+k]-x```，说明arr[left]不合格，所以最终的k-size滑窗的起始点不会是left或其左边的任何位置。
2. 如果```x-arr[left] < arr[left+k]-x```，说明arr[left+k]不合格，所以最终的k-size滑窗的末尾点不会是right或其右边的任何位置，也就是说k-size滑窗的起始点不会是left右边的任何位置（注意可以是left）。
3. 如果```x-arr[left] == arr[left+k]-x```，说明arr[left]和arr[left+k]并列。根据规则，第k个closest只能算一个，所以那个不合格的元素只能给arr[left+k]，因此后续的处理就同2.

因为此题一定有解，所以收敛后的位置就一定是最终理想的k-size滑窗的起始点。


[Leetcode Link](https://leetcode.com/problems/find-k-closest-elements)