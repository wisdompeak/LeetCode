### 1414.Find-the-Minimum-Number-of-Fibonacci-Numbers-Whose-Sum-Is-K

直观上，我们构造出所有小于k的斐波那契数列的元素，然后依次贪心地从大到小选取即可（选完一个就从k里面减去它）。我们发现这个方法似乎总是成立的。

更严谨的证明可以见[这里](https://leetcode-cn.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/solution/he-wei-k-de-zui-shao-fei-bo-na-qi-shu-zi-shu-mu-by/)
