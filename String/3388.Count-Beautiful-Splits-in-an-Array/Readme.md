### 3388.Count-Beautiful-Splits-in-an-Array

根据n的数量级，考虑如果暴力枚举两处分界点的话，那么需要能以o(1)的时间判定一段subarray是否是另一段subarray的前缀。此时常见的方法只有rolling hash。事实上，每个nums[i]的数值有上限50，故可以类比于字符串的rolling hash，方法应该是可行的。

需要注意的几个细节：
1. 每个nums[i]的数值上限是50，故可以选取质数53作为进制。
2. 一段区间的`hash[i:j] = prefix_hash[j] - prefix_hash[i-1] * power[j-i+1]`，同时取余的过程要始终保证是正数。
3. 判定subarray1是否subarray2的前缀时，要保证subarray2的长度不能小于subarray1. 同理判定subarray2是否subarray3的前缀，也需要考虑这个约束。
