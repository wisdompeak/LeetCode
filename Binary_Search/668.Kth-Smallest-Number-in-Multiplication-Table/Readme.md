### 668.Kth-Smallest-Number-in-Multiplication-Table

此题非常巧妙地用到了二分（值）查找的思想。

初始状态left=1,right=n*m，每次确定mid之后，查看乘法表里小于等于mid的数目有多少，然后与k比较大小确定两个边界的变动。

查看乘法表里小于等于mid的数目，只要按照行i进行遍历，count+=min(mid/i,n)。
