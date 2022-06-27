### 2321.Maximum-Score-Of-Spliced-Array

我们思考将nums1的某一段替换成nums2后元素和最大，肯定是希望"增量"最大。显然，我们构造```gain[i] = nums2[i]-nums1[i]```，必然就是在gain中找一段maximum subarray sum. 将这段subarray sum加在nums1原先的元素和上，就是nums1经过区间替换后的最大元素和。
