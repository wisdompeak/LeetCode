### 1825.Finding-MK-Average

我们设计三个mulitset：left, mid, right，分别盛装stream中从小到大的前k个、中间m-2k个、后k个元素。

首先我们处理加入的num。根据是否小于等于left尾元素的值、是否大于等于right首元素的值，分别判断是否加入left或者right，否则就加入mid。此时left或者right的个数可能会大于k个。如果left的个数大于k，那么我们将left的最后一个元素移给mid。如果right的个数大于k，那么我们将right的第一个元素移给mid。此次操作后，left和right保持k个，mid的个数应该是m-2k+1个。

然后我们处理删除的num。根据是否小于等于left尾元素的值、是否大于等于right首元素的值，分别判断是否从left或者right中移出。此时left或者right的个数可能会小于k个。如果left的个数小于k，那么我们将mid的第一个元素移给left。如果right的个数小于k，那么我们将mid的最后一个元素移给right。此次操作后，left和right保持k个，mid的个数应该是m-2k个。

我们构造两个util函数可以简化代码：shiftRight(set1, set2)将set1的最后一个元素移给set2，shiftLeft(set1, set2)将set2的第一个元素移给set1，
