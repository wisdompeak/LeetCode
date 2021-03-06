### 1923.Longest-Common-Subpath

本题的正解是用“后缀数组”的高级数据结构，但是过于复杂，这里只讲比较容易理解的rolling hash的解法。

本题和```1062. Longest Repeating Substring```的做法很类似。High-level的思想是二分搜索这样的common subarray的长度len。对于一个固定的长度len，我们看所有的数组里是否存在完全相同、长度为len的subarray。如果存在，那么len还可以往大调整，这是因为len越大，所有数组存在一个相同的公共子串的概率就越低；否则len就需要往小调整。

那么如何寻找长度为k的公共子串呢？可以将所有长度为k的子串都扔进一个hash map里，统计它们出现的频次。如果某个子串出现了m次（但是在每个数组里只能最多被统计一次），那么说明它就是所有数组的公共子串了。但是直接将子串（即subarray）直接作为key是不实际的，因为这个子串可能会很长，时间和空间的消耗都很大。可行的解法是将子串进行“编码”。因为每个数字不超过1e5，所以我们将这个长度为k的子串，看做是含有k个digit、每个digiit是1e5进制的“数”。可以想见，这样的“数”和原始的子串必然是一一对应的。相比于拿子串（子数组）作为key，用“数”作为key更高效。

问题是这样的“数”会非常大，远远超过了数据结构能够支持的溢出范围。一般的处理方法是，在编码的过程中时刻对一个大质数mod取模，比如1e9+7. 但是这样就有hash碰撞的危险，即有若干个不同的子串对应同一个编码。显然，mod越大，冲突的概率越小。本题中一个数组的子串的数目可能有1e5个，一般要求mod大于(1e5)^2才能有效降低冲突的概率。这里介绍一个hack的技巧，那就是我们可以将mod取到C++的最大，也就是2^64. 具体的方法是将所有的数字都设置为uint64_t类型，并且取消所有取模的操作。无符号类型的一个特点就是，任何加减乘操作造成溢出的话，自动实现的是wrap-up，也就是相当于对2^64取模。因为2^64=1.8e19，这就显著减小了hash冲撞的概率，并且使得代码更简洁。

#### Update
新的测试数据又针对了上面的做法，现在无法AC了。我们只好采用双hash作为key（暂时还不需要改mod）。参见v2的代码。
