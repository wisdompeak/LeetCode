### 3721.Longest-Balanced-Subarray-II

既然是求区间，那么不妨考虑“前缀之差”。根据经验，我们需要记录每个前缀里“unique even numbers与unique odd numbers的个数之差”。任何两个差相同的前缀，意味着一个符合条件的区间，即“unique even numbers与unique odd numbers的个数相等”。

对于一个nums[0:i]的前缀，如何表达“unique even numbers与unique odd numbers的个数之差”呢？因为每个unique number可能出现在很多位置，为了便于分析，我们约定只关心每个unique number最后一次出现的位置。记作lastPos[x]。比如偶数4最后一次出现在了a这个位置，那么我们就记录array[a]=1；假设奇数7最后一次出现在了b这个位置，那么我们就记录array[b]=-1.可见，只要计算这个01数组array[0:i]的前缀和，就可以知道nums[0:i]里“unique even numbers与unique odd numbers的个数之差”。

所以我们需要构造一棵线段树seg，其中节点seg[i]表示array[0:i]的前缀和。如果seg[i]与之前的某个seg[j]相同，那么就意味着[j:i]是一个符合条件的区间。注意对于线段树，是可以支持log(n)时间去实现`find_first_equal`的操作。这个我们后面再提。

现在，我们需要理解为什么必须用线段树而不是普通的数组来记录上面的seg[i]呢？因为随着i的增大，lastPos[]会改变（比如，最新的x=nums[i]会导致`lastPos[x]=i`的更新）。这继而会造成array[]也会改变（显然，array[i]会是一个非零值，而之前x所在的位置的array值会置零）。这继而又会造成array的前缀和，即seg[i]的改变。对于一个mutable的数组，想用log的时间实现`find_first_equal`是不可能的。

接下来我们思考，随着前缀下标i的增大，这棵线段树该怎么更新。当前缀移动到i位置时，记x=nums[i]，原先的lastPos[x]=j。这就意味着：原来的array[j]从1（或者-1）要变成0，而array[i]要填充为1（或者-1）。对于array的前缀和而言，下标从j到i-1的前缀和（即seg[j]到seg[i-1]）都需要撤回1（或者增加1）；而最新的seg[i]就是在seg[i-1]的基础上加上array[i]的影响。可见，对于线段树而言，上述的操作本质就是树上的区间更新。

解决了线段树怎么更新，接下来讲`find_first_equal`的实现。我们对于线段树的每个节点（对应array的一个前缀和）维护其最大值和最小值两个val。如果max=>target并且min<=target，那么必然在这个节点对应的区间有一个节点的值是target。为什么能保证必然存在target呢，其实在于本题的特点：就是随着元素的增加，前缀和的变化永远是+1或者-1。因此如果前缀和从min变化到max，且target位于min与max之间，那么前缀和必然经过target。由此我们通过线段树二分处理的性质，可以用log时间找到第一个等于target的节点。
