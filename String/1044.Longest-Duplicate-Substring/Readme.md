### 1044.Longest-Duplicate-Substring

本题就是```1062. Longest Repeating Substring```的follow up，不仅求repeating（也就是duplicate） substring的长度，并且要把这个substring打印出来。

和1062完全一样，本题的high level的思想是二分搜索这样的substring长度。对于一个固定的len，如果能在S里找到两处相同的子串滑窗，那么我们就可以对len的值再往上调整；反之，我们就必须将len的估再往下调。

于是本题转化为，如果快速在S里找到两处相同的、长度都是len的滑窗。比较直观的想法是对每一处滑窗组成的字符串都放入集合，如果看到集合中已经有一个相同的substring了，就意味着duplicate了。但是当len很大的时候，将字符串放入集合的内置hash化操作很耗时。于是rolling hash是比较常见的解决方案。

Rolling hash的基本思想就是将abcd转化为26进制的0123.将一个数作为key放入集合很轻松。除此之外，对于abcdef这样的字符串，如果已经知道了[abcd]这个子串的hash key是0123，那么再求相邻的[bcde]的hash key 1234就非常高效，只需要将之前的key的最高位数字去掉(a对应的0)、左移一位、加上最低位数字(e对应的4）。用o(1)的时间就能完成。

总结一下，rolling hash的思想，就是将两个字符串的比较，转化为hash化之后的两个26进制数的比较。但是当len很大时，这个数可能很大，我们通常不得不对一个大数取模再作为hash key。这样就会有两个不同的字符串，但是会对应同一个hash key（26进制数取模后的结果）。针对这种hash collision的情况，我们可以调整base和mod来规避。或者使用两套hash规则来生成两个key，那么不同字符串拥有两个相同key的概率就会大大降低。

#### Update
随着测试数据的增加，为了避免hash collision，base和mod的调参越来越困难。这里提供一个hack的方法。我们知道mod越大，就越能避免hash碰撞，所以可以试图将mod取到最大。最大是什么呢？就是```2^64```. 具体的做法是，将所有的数据结构改为uint64_t类型，并且取消所有的mod操作。uint64_t是无符号的数据类型，对于它的加减乘操作所造成的溢出，都自动等效为将结果```mod (2^64)```. 

当然，OJ还是可以针对这个mod设计测试数据fail这个代码。
