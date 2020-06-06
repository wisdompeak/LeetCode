### 1063.Number-of-Valid-Subarrays

对于任意一个nums[i]作为subarray的左端点的话，右端点最远可以是哪里呢？显然是the next smaller element，假设位置是在j。那么显然从[i,j-1]区间内的任意一个元素都可以是组成合法subarray的右端点，因此```count+=j-i```.

求数组内每个元素的next smaller element就是常规的单调栈的操作。

特别注意的是，遍历结束的时候，栈里面可能还存有递增的元素，这些元素作为左端点的subarray都还未被计数。为了强制清空栈，我们可以nums的末尾添加一个INT_MIN，这样所有的nums的元素最终都会被退栈（退栈的时候会计算对应的subarray的数目）。
