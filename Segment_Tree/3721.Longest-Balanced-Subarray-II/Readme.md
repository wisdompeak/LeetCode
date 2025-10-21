### 3721.Longest-Balanced-Subarray-II

既然是求区间，那么不妨考虑“前缀之差”。根据经验，我们需要记录每个前缀里“unique even numbers与unique odd numbers的个数之差”。任何两个差相同的前缀，意味着一个符合条件的区间，即“unique even numbers与unique odd numbers的个数相等”。

对于一个nums[0:i]的前缀，如何表达“unique even numbers与unique odd numbers的个数之差”呢？我们只需要关心每个unique number最后一次出现的位置。记作lastPos[x]。比如偶数4最后一次出现在了a这个位置，那么我们就记录array[a]=1；假设奇数7最后一次出现在了b这个位置，那么我们就记录array[b]=-1.可见，只要计算这个01数组array[0:i]的前缀和，就可以知道nums[0:i]里“unique even numbers与unique odd numbers的个数之差”。

所以我们需要构造一棵线段树seg，其中节点seg[i]表示array[0:i]的前缀和。如果seg[i]与之前的某个seg[j]相同，那么就意味着[j:i]是一个符合条件的区间。
