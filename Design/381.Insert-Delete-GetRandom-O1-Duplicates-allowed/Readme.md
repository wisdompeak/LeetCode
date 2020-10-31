### 381.Insert-Delete-GetRandom-O1-Duplicates-allowed

此题是380的follow up。

设计数据结构的突破口就是在于getRandom的时间要求，o(1)必然说明我们需要维护一个数组nums，这样直接通过```nums[rand()% nums.size()]```就可以直接随机访问一个元素。

那么如何处理remove的操作呢？对于数组而言删除一个中间元素的代价很大。一个常见的想法就是，将最后一个元素挪到被删除的元素的位置上去。这样保证了数组依然是线性连续的。所以我们需要维护一个hash表来存储每个数值所出现的（所有）index。具体的操作包括：
1. 从Map[val]中挑一个位置pos，将nums.back()移过来。
2. 从Map[val]中删除pos
3. 更新Map[nums.back()]的位置，将原先的nums.size()-1改为pos
4. nums.pop_back()
5. 注意，如果Map[val]已经为空，那么请将val这个key从hash表中删除。

特别注意：如果val就是nums末尾的元素，最好单独处理，否则容易出错。


[Leetcode Link](https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed)
