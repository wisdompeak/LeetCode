### 215.Kth-Largest-Element-in-an-Array

此题比较简单的方法就是用priority_queue,遍历整个数组,每次只保留最大的K个值.

另外还有一个理论上o(N)的算法,就是利用Qucik Sort的思想,成为Quick Select. 我们每次随机取一个pivot,然后遍历整个数组,将小于pivot的数放进一个small数组,大于pivot的放入一个large数组.如果我们要找的k小于等于small的大小,就在small里继续找.如果要找的k大于small和equal的大小,就在large里继续找.剩下的情况就说明要找的第k个元素就是pivot.

