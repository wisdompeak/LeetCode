### 2499.minimum-total-cost-to-make-arrays-unequal

首先我们考虑答案至少是多少？如果所有的same pairs能够在“内部调整”后满足要求，即交换只涉及same pairs所在的位置，那么答案就是这些same pairs的下标之和。显然，这个答案是最小的。

那么什么情况下我们能够保证所有的same pairs在“内部调整”后就能满足要求呢？只要其中的majority element不超过same pairs的总数的一半即可。举个例子`(2,2),(2,2),(2,2),(1,1),(3,3),(4,4),`我们必然可以
