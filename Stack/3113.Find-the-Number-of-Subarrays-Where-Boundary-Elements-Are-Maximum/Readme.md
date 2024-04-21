### 3113.Find-the-Number-of-Subarrays-Where-Boundary-Elements-Are-Maximum

我们考虑以i为结尾的subarray，那么该subarray的首位置必然是在i之前、且数值与nums[i]相同的那些元素。这些我们是容易用hash准备好的。

同时，因为要求nums[i]是subarray里最大的元素，所以首元素的位置不能太靠前，越靠前的话subarray就越容易包含大于nums[i]的数。所以我们提前用单调栈计算出每个`i`的prev greater的位置。那么在所有与nums[i]相同的元素里，我们只会挑选位置在prevGreater[i]之后的那些，都可以作为subarray的首元素。
