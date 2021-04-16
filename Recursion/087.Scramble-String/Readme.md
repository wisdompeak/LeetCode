### 087.Scramble-String

基本的思想就是：在S1上找到一个切割点，左边长度为i, 右边长为len - i。 有2种情况表明它们是IsScramble

(1). S1的左边和S2的左边是IsScramble， S1的右边和S2的右边是IsScramble

(2). S1的左边和S2的右边是IsScramble， S1的右边和S2的左边是IsScramble （实际上是交换了S1的左右子树）

我们可以在递归中加适当的剪枝：在进入递归前，先把2个字符串排序，再比较，如果不相同，则直接退出掉。


[Leetcode Link](https://leetcode.com/problems/scramble-string)