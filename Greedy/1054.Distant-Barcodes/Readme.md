### 1054.Distant-Barcodes

#### 解法1：
将所有元素按照频次从大到小排列（所以相同的元素都会排在一起）。然后将这些元素先顺次填满答案序列index为奇数的位置，然后在顺次填满答案序列index为偶数的位置。这样就能尽可能地保证相同的元素不会排在一起了。

#### 解法2：
套路题：将所有数字按照频次放在一个优先队列里。每次从队列首取出两种不同的数字。频次减一之后再放回。

注：本题与```767.Reorganize String```完全一致。

[Leetcode Link](https://leetcode.com/problems/distant-barcodes)
