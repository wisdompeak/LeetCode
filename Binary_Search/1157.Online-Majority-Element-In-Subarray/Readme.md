### 1157.Online-Majority-Element-In-Subarray

我的突破口是考虑出现频次最多的元素a，它应该有最大的概率是[left,right]区间内的majority。这个怎么判断呢？显然我们将所有出现a的位置按照从小到大的顺序列出来作为数组p，然后找到left和right能插入的位置。比如，我们找到pos1表示p里面第一个大于等于left的位置，pos2表示p里面最后一个小于等于right的位置。这样，pos2-pos1+1就是在[left,right]区间内a出现的次数。将其与threshold比较就可以判断是否满足题意。

如果a不合题意，那么数组里剩余元素的总数total就减少了pos2-pos1+1个。如果频率次高的b也不符合题意，那么剩余的total会进一步减少。如果直到剩余的total小于threshold时，说明剩下的元素即使都是同一个，也无法满足题意了，此时就可以直接返回-1.
