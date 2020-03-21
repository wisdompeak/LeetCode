### 1191.K-Concatenation-Maximum-Sum

假设我们有一段maxSum Subarray长得像这个样子：```ATT...TTB```，其中A是arr的末尾的一段，B是arr的开头的一段，中间有若干个完整的arr（写作T）。那么我们一定可以推论出T>0（也就是原始的arr的数组和必须大于零）。否则的话，T<0显然是个累赘，拖累了```A+B```，肯定不会满足```ATT...TTB```是maxSum Subarray的假设（因为比不过```A+B```）。反过来说，如果T>0，那么maxSum Subarray也一定是长得是```ATT...TTB```的模式（中间有k-2个T）。那么怎么确定A和B呢？其实只要将arr重复两次，在这个新数组```arr2```里面，```AB```是一段尾首相接的subarray，很容易找出最大的maxsum subarry。

反之T<0的话，我们肯定不会让maxSum Subarray里面夹着任何完整的arr。所以maxSum Subarray就在```arr2```里面找就可以了。


[Leetcode Link](https://leetcode.com/problems/k-concatenation-maximum-sum)