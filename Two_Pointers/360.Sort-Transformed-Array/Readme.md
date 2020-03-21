### 360.Sort-Transformed-Array

注意a等于零和正负情况，会影响结果。如果a==0时，函数结果本身就是单调的，但要根据b是否大于0来改变顺序。

当a不等于零时，设置左右两个指针，可以根据nums[left]、num[right]离中轴线(-b/2a)的距离来移动较远的那个指针，特别注意细节，不是比较left/right和中轴线的距离。令两个指针不断靠近，直至left==right.

也可以直接用比较两个指针对应的func[i]的大小来移动指针。当a>0时，优先移动二者之间较大的，最后结果反序；当a<0时，优先移动二者之间较小的。


[Leetcode Link](https://leetcode.com/problems/sort-transformed-array)