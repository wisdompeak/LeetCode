### 087.Scramble-String

本题的数据规模不大，所以暴力递归即可。基本的思想就是：在S1上找到一个切割点，左边长度为i, 右边长为len - i。 有2种情况表明它们是IsScramble

(1) S1的左边和S2的左边是IsScramble， S1的右边和S2的右边是IsScramble

(2) S1的左边和S2的右边是IsScramble， S1的右边和S2的左边是IsScramble （实际上是交换了S1的左右子树）

我们可以在递归中加适当的剪枝：在进入递归前，先直接比较2个字符串，如果相同则直接返回true。

另外，本题需要记忆化以提高效率。

[Leetcode Link](https://leetcode.com/problems/scramble-string)
