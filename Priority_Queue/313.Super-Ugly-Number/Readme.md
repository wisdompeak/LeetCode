### 313.Super-Ugly-Number

本题本质就是find the n-th largest element from k sorted lists. 从1开始，每次从优先队列里弹出当前最小的数，然后分别乘以k个质数再放入队列中。直至弹出n个数为止。

注意到装入队列的元素可能会是重复的。所以此处用set更方便。
