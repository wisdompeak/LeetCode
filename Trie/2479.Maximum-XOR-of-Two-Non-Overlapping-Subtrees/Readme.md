### 2479.Maximum-XOR-of-Two-Non-Overlapping-Subtrees

显然我们可以通过一遍dfs求得每个节点对应的子树元素和。另外，对于一个数组pool，和一个固定的元素n，我们知道可以用`1707.Maximum-XOR-With-an-Element-From-Array`的算法，高效地得到n在pool里的最大XOR值。但是本题的难点在于，如何添加元素进入pool的顺序，以及求max XOR的顺序，因为我们需要排除两个重合子树被XOR的可能性。

本题的精彩解法是设计一个后序遍历的dfs。对于每个节点node，我们依次处理它的子节点v，先在pool里查询v可以得到的最大XOR值，然后递归处理v，最后将v加入pool。这样处理完所有的孩子节点，我们会发现，所有的query都不会发生在节点v与它的直系下级之间，只会发生在v与亲戚节点之间。至于node本身，我们不会在当前的dfs里处理，而是由其parent所在的dfs里进行query、递归处理和添加。再次注意这三者之间的顺序，这保证了query任何一个节点的时候，它的子树都没有被处理，子节点和本身都还没有被添加进pool里。

另外，因为所有的节点都是依次加入pool的，而且入pool之前都与pool内的元素query过一次最大XOR的寻找，所以这个方法不会遗漏任何配对。
