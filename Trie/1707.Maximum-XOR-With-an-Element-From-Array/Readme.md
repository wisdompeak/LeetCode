### 1707.Maximum-XOR-With-an-Element-From-Array

我们将query按照m的大小逐个处理。对于每个query而言，就是在一堆数里面挑选一个与x亦或值最大的数。因此，本题的本质就是```421. Maximum XOR of Two Numbers in an Array```.具体算法是：我们将这堆数按照32位二进制编码构造一个Trie，然后在这棵前缀树里，尽量按照x的相反数（bit-flipped）去探索，只需要移动32次就能找到与x亦或值最大的数。

接下来再处理下一个query时，我们只需要在已有的前缀树里再增加若干节点即可（也就是比当前m小的数），然后同样地重复之前的步骤。

这种对于query排序的思路，很像```1697.Checking-Existence-of-Edge-Length-Limited-Paths```。在1697中，每次处理新query之前，会在一个已有的union网络里添加一些新的连接。
