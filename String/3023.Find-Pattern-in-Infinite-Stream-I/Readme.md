### 3023.Find-Pattern-in-Infinite-Stream-I

此题是KMP的模板题。先将pattern进行预处理求得它的前缀数组`suf`。然后对stream产生的nums[i]逐位处理，利用`suf`计算nums的前缀数组dp[i]。其中dp[i]的定义是以nums[i]结尾的最长后缀，同时也是pattern的前缀。

当发现某处的dp[i]等于pattern的长度m时，说明`i-m+1`就是匹配的位置。
