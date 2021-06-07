### 1889.Minimum-Space-Wasted-From-Packaging

很显然，我们会对packages和每组box分别进行排序。从小到大查看每个box[i]，我们看它能新装下哪些packages（这是一个区间），计算wasted space。

一种解法就是双指针。对于一组box，我们分别移动指向packages和box的指针，找到最大的j使得```packages[j]<=box[i]```. 双指针需要用o(m+n)的时间来计算总共的wasted space。假设有k组box，那么总的时间就是o(mk+nk)。虽然m,n,k都是1e5量级，但其中o(nk)是所有组的盒子总数，题目中说明了是1e5量级。但是o(mk)仍然会有1e10量级，故会TLE。

另一种解法就是双指针，对于一组box的某个盒子box[i]，直接在packages里面用二分法，找到最大的j使得```packages[j]<=box[i]```。处理一批盒子，需要的时间复杂度是```o(logM*n)```，假设有k组，那么就是```o(logM*nk)```。因为m和nk分别是1e5量级，故时间复杂度可以接受。

此题还可以用packages前缀和来简化计算针对每个box[i]的wasted space的代码。
