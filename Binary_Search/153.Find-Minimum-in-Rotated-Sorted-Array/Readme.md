### 153.Find-Minimum-in-Rotated-Sorted-Array

常规的二分搜索，目标是右区间的第一个元素。如果中位数nums[k]>=nums[0]，那么说明k在左区间，我们将搜索范围调整为[k+1,j]。如果中位数nums[k]<nums[0]，那么说明k在右区间，我们将搜索范围调整为[i,k]。

因为此题必然有解，所以当收敛到i==j时，就是答案。
