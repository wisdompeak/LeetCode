### 3306.Count-of-Substrings-Containing-Every-Vowel-and-K-Consonants-II

此题和`3298.Count-Substrings-That-Can-Be-Rearranged-to-Contain-a-String-II`非常相似。

我们令count0统计元音的种类个数，count1统计辅音的字符个数。对于固定左端点i的区间而言，如果发现`count0<5 || count1<k`，我们必然会不断向右延伸右端点j。注意当我们停止移动j时，我们有`count0==5 && count1>=k`. 此时两种情况：
1. 如果count1>k，那么我们必然会尝试右移左端点i，因为再右移右端点j的话必然不会满足count1.
2. 如果count1==k，那么我们就找到了一组合法区间[i:j]。那么我们是否还有其他以i为左端点的合法区间呢？事实上，如果j右边有连续的元音出现的话，这些都是可以纳入合法区间的。所以我们可以提前计算一个数组A[k]，记录k及k右边连续有多少个元音。这样答案就增加了`1+A[j+1]`个。

以上就考虑完了所有以i为左端点的情况。下一步就是将i右移一步，更新count0和count1，然后继续探索右端点即可。
