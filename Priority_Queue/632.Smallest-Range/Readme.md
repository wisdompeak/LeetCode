### 632.Smallest-Range

很明显，需要用到优先队列(priority_queue)。

假设有N个数组，那么这个队列里要有N个元素，最开始每个数组出一个。每个回合从队列中弹出一个最小值，再从这个最小值所对应数组里添加一个入队列，更新此时的MIN和MAX。直到有任何一个数组为空为止。

其他要注意的时，priority_queue默认是大顶堆，需要手工设计cmp来实现小顶堆。priority_queue本质是个栈，所以小顶堆的cmp定义应该是大的元素放前面，即a.first>b.first。
