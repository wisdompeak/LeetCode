### 1850.Minimum-Adjacent-Swaps-to-Reach-the-Kth-Smallest-Number

很明显，本题分为两部分。

第一部分是求一个字符串的K-th next permuation. 可以调用```LC31 next permuation```的代码连续K次，或者用C++自带的next permuation. 这部分的时间是o(NK).

第二部分是求一个新字符串与原字符串相比，需要多少次adjacent swap。这本质就是求逆序对的问题。举个例子，问多少次adjacent swap能够使得字符串35241变得有序？对于1而言，它前面有4个字符比它大，所以需要交换4次使得1排到最前面；对于2而言，它前面有3个字符比它大，所以要交换3次能排到除1外的最前面；对于3而言，它前面没有字符比它大，它不需要主动交换，只需等着被动swap就能排到最终的第3个位置...由此我们发现，总共需要交换的次数就是逆序对的个数。逆序对指的是，```i<j && nums[i]>nums[j]```. 求解逆序对其实就是```LC 493.Reverse-Pairs```，有o(NlogN)的算法。

在本题中，我们根据新字符串重新定义各个字符之间的“有序”。这样从旧字符串变换成为新字符串的过程，就可以等同于上述的过程，也就是转化为求逆序对。注意，对于相同的字符，我们始终保持它们之前的相对顺序。很显然，对于相同字母，我们永远不会做swap.

考虑到本题中字符的个数N不超过1e3，暴力的冒泡贪心l(N^2)也是可以做的。具体方法是：对于new[i]，我们从old[0]开始找起、直到找到第一个old[j]==new[i]，那么从0到j的过程中所遇到的尚未匹配的字符个数，就是需要的adjacent swap次数。注意对于匹配好的new[j]，我们立即将其替换为'#'作为标记。比如说
```
old: abcd
new: bcda
step 1: old-> a#cd  +1
step 2: old-> a##d  +1
step 3: old-> a###  +1
step 4: old-> ####  +0
```
所以总共3次swap将old变成new。
