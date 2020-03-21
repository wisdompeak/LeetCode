### 041.First-Missing-Positive

首先，将nums数组之前添加一个零元素。于是本题的一个思路是：如果尝试把正整数1~N尽可能地按照顺序放入nums[1]~nums[N]后，那么从头到尾再遍历一遍nums，找到的第一个nums[i]!=i的数，就是所求的结果。 

那么如何尝试one pass就把正整数1~N尽可能地按照顺序放入nums[1]~nums[N]呢？这就是经典的array indexing的算法。遍历所有元素的时候，发现如果nums[i]!=i时，说明当前的nums[i]这个数没有被放置在合适的位置，根据对应的规则，它应该被放在nums[nums[i]]这个位置。

于是我们持续交换nums[i]和nums[nums[i]]。每一次交换的结果是：把nums[i]送到了它应该在的位置；同时i位置的元素又有了新的值，可以再次进行交换。如果这样的步骤持续到 nums[i]==i（说明第i个元素的位置已经得到满足了）或者nums[nums[i]]==nums[i]（说明第nums[i]个元素的位置也已经得到了满足），就不需要交换了。

当把所有的i都遍历一遍之后，就完成了“力所能及”的排序，意思就是nums里面所有处于1\~N之间的数，都已经在它规定的位置上了。如前所述，此时从头到尾再遍历一遍nums，找到的第一个nums[i]!=i的数，就是原先nums里面1~N之间所缺失的数。 

和本题非常相似的还有:
```
287.Find the Duplicate Number
442.Find-All-Duplicates-in-an-Array 
448.Find-All-Numbers-Disappeared-in-an-Array 
645.Set Mismatch，
```
也用到了array indexing.


[Leetcode Link](https://leetcode.com/problems/first-missing-positive)