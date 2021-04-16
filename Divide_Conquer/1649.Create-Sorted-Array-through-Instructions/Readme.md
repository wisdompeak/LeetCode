### 1649.Create-Sorted-Array-through-Instructions

#### 解法1：分治法（归并排序）
遍历这个数组里的每个元素，对于nums[i]，其实我们需要求的其实就是数一下[0,i-1]里有多少个元素严格比它小（或者大）。这不就是Count-of-Smaller-Numbers-Before-Self吗？立马联想到```LC315.Count-of-Smaller-Numbers-After-Self```，这是一道标准的分治法+归并排序的题。

所谓的“分治+归并排序”，抽象地说，是对研究原数组的问题，拆分为两个小数组的问题（有点像递归）。但是注意，分别解决完这两个小数组的问题，并不意味着就解决了整个大数组的问题。我们在递归的过程中，将这两个小数组保持有序，然后再归并成一个有序的大数组。这个归并的过程中，可以额外做些操作来彻底解决这个大数组的问题。

就本题而言，数组A按照index的先后拆分为两个小数组B和C。我们递归处理，得到B里面每个元素的Count-of-Smaller-Numbers-Before-Self，另外得到C里面每个元素的Count-of-Smaller-Numbers-Before-Self。然后我们再试图求解A问题。我们发现，A里面的B部分元素已经不需要再做任何更新了（B的所有smaller numbers before self依然在B里面，而B的问题已经解决了）。但是A里面的C部分元素还没有完全求解，因为B里面也有不少元素是C元素的smaller numbers before self。所以如果B是有序的话，那么我们就很容易通过二分法，求得B里面有多少个元素比C[i]小，那么C[i]的最终结果就可以得到进一步的更新。注意，结束之后我们需要将B和C归并起来得到一个有序的A，返回上一层的调用。

本题OJ对于这种方法的C++解法要求很苛刻，必须全部采用数组（而非vector）才有可能AC。

#### 解法2：树状数组
根据数组元素的范围，我们开辟一个计数数组count[100001].如果我们遇到nums[i]，那么就相应的在计数器count[nums[i]]++。于是，对于nums[i]的Count-of-Smaller-Numbers-Before-Self，本质上就是求count数组在区间[1,nums[i]-1]上的和。对于一个mutable array，动态地求区间和，那么BIT或者线段树是最合适的数据结构。

BIT的模板相对更简单一些。简单的说，我们将1-index的原数组nums，做一些变换映射到1-index的新数组bitArray.我们对于nums的单点更新、区间求和，都可以映射成在bitArray上的一些操作。BIT提供了两个API，分别是update(i,delta)和querySum(i,j)，前者是用来单点更新nums[i]+=delta，后者是用来求区间nums[i:j]的和。

#### 解法3：线段树
我们构造一棵线段树，线段树中的叶子节点代表着instruction里出现过的ordered distinct number，节点的info表示该数字出现的频次。注意，在初始建树的时候，所有节点的info都是零。

记instruction[i]为x。每一个回合，我们需要分别统计这棵树里小于x的叶子节点个数、大于x的叶子节点个数。但我们不必关心x的数值。我们只需要知道x对应的index，这样我们就是在线段树中查询区间[0,index-1]的叶子节点的总频次（即info的总和）、以及查询区间[index+1,n-1]的叶子节点的info总和。所以我们需要一个方法queryRangeFreq(root,a,b). 

在这个回合结束之后，我们将x加入这棵线段树。注意我们不需要新增节点，我们只是将数值为x的叶子节点的频次加1（事实上就是将第index个元素加1），所以我们需要一个方法updateSingleNode(root, index)。

因为我们不关心instruction里面每个元素x的具体数值，只关心他们在线段树中的位置。所以我们预处理的时候要做“离散化”，建立x和index的映射关系。

#### 解法4：pbds
