### 209.Minimum-Size-Subarray-Sum

基本思路：因为题意保证所有数组元素都是正数，可以用双指针定界。当双指针之间子数组和大于sum时，记录Len并left++；否则right++。

实际编程中，用for循环来控制右指针的思路比较清晰，左指针仅当固定了一个右指针的前提下进行移动；相对而言，用while来控制双指针比较容易出错。

细节：注意在什么条件下更新len。


[Leetcode Link](https://leetcode.com/problems/minimum-size-subarray-sum)