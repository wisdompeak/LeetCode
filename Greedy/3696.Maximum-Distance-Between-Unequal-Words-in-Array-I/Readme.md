### 3696.Maximum-Distance-Between-Unequal-Words-in-Array-I

此题有非常巧妙的贪心法。如果首尾元素不同，那么答案就是n。如果首尾元素不同，那么答案必然是在以下两种可能之中：首元素与某个与其不相同的元素；或者尾元素与某个与其不相同的元素。所以两遍one pass即可。
