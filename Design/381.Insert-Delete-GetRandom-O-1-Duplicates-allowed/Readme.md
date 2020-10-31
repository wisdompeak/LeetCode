### 381.Insert-Delete-GetRandom-O-1-Duplicates-allowed

此题是380的follow up。基本思路仍然是用Map来查找元素，用array来新增元素。

显然对于val->pos的映射应该构建 unordered_map<int,unordered_set<int>>val2pos, 以存储val对应的所有在数组中的（若干个）位置。

在Delete(val)过程中，腾出的位置要用```val2 = array.back()```来替换，相应地```val2pos[val2]```也要更新，即删除val2原来的位置（也就是nums的末尾），添加val的位置。

特别注意：如果val就是nums末尾的元素（即```val==val2```)，最好单独处理，否则容易出错。


[Leetcode Link](https://leetcode.com/problems/insert-delete-getrandom-o-1-duplicates-allowed)
