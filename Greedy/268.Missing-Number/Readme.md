### 268.Missing-Number

#### 解法1：
对于凡是与“从0到N”数字相关的题目，indexing sort（或者叫cyclic sort？）总是一个值得尝试的角度。我们试图将0~N这些数字依次填充到nums的第0\~N个位置。移动的方法就是逐个考察每个index，如果第i个位置的数字不是nums[i]，那么我们就交换nums[i]和nums[nums[i]]：目的是把nums[i]直接送到它应该所在的地方（也就是index是nums[i]的位置）；同时，如果交换来的nums[nums[i]]依然不是我们想要的数字i，那么我们就重复这个swap的操作，直至：
1. 当前的第i个位置放的就是数字i；or
2. nums[i]和nums[nums[i]]相等，也就是说swap(nums[i], nums[nums[i]])没有任何效果；or
3. nums[nums[i]]越界了，也就是nums[i]不是一个合法的index

按照以上规则处理完所有的index之后，我们就已经竭尽全力地把所有数字和索引相match。此时再扫一遍nums数组，唯一的一处nums[i]!=i的地方，就是说明数字i是missing的。

#### 解法2：
有一个更优雅的做法。nums[i]包含了0\~N的所有数（除了一个missing number，假设是x）。我们将其亦或起来。同时将这个结果再与0\~N都亦或一遍。这样，除了x，其他的数字都被xor了两遍而被消除。剩下的结果就是x。
