### 932.Beautiful-Array

此题的突破点是：如果A是奇数，B是偶数，那么A和B的摆放位置是任意的，因为不可能有C夹在AB之间且C*2=A+B.所以这就提示我们如果我们把所有的奇数组成一个beautiful array，所有的偶数组成一个beautiful array，那么把这两个array简单的拼接，就能组成一个完整的beautiful array.

那么我们怎么把所有的奇数,比如说[1,3,5,7]组成一个beautiful array呢？这是一个四元素的数组，我们很容易想到，如果已知[1,2,3,4]组成的beautiful array，那么将它们统统乘以2减去1，就能得到用[1,3,5,7]组成的beautiful array了。同理，将[1,2,3,4]组成的beautiful array乘以2，也能得到[2,4,6,8]组成的beautiful array。于是两者拼接，就有了从1到8组成的beautiful array。

由此可见，这道题就是考察了简单的递归思想。


[Leetcode Link](https://leetcode.com/problems/beautiful-array)