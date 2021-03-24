### 923.3Sum-With-Multiplicity

我们可以在第一层循环中枚举中间的元素k，再用双指针的思想来遍历{i,j}配对。第二层循环里枚举元素i，然后从右往左移动指针j来寻找```arr[i]+arr[k]+arr[j]==target```.

这里需要注意的是，两个指针移动时需要考虑与arr[i]相同的元素个数count1，与arr[j]相同的元素个数count2。统计时需要加上```count1*count2```.
