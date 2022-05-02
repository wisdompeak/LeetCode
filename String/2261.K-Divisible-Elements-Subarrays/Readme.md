### 2261.K-Divisible-Elements-Subarrays

#### 解法1：暴力
用o(N^2)的算法枚举所有的subarray，然后强行将整个subarray放入一个集合之中判断是否重复。注意，这个集合操作不是o(1). 总的时间复杂度是o(N^3)，刚好够。

#### 解法2：Rolling Hash
更高效的集合操作是存入subarray的某种编码，而不是subarray本身。这样对集合的写操作和查找操作才是真正的o(1)。考虑到每个元素不超过200，所以我们取201为base，将subarray拼接成一个201进制的数即可。同样，Rolling Hash会遇到数据类型溢出的问题。对于C++而言，采用unsigned long long的自然溢出来实现最大化的取模，是最方便的写法。参见```2223.Sum-of-Scores-of-Built-Strings```.
