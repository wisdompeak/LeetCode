### 1675.Minimize-Deviation-in-Array

对于奇数x，它可以变换成2x,x; 对于偶数x，它可以变换成x, x/2, x/4, ... 直至变成一个奇数。我们将每个数和它的变换数看作是一组。于是本题就是要求从每组里面取一个数，使得所取的这些数的range最小。这样看来，本题的本质就是和```632.Smallest-Range-Covering-Elements-from-K-Lists```一模一样了。

具体的方法是，查看全局最大值x，考虑如果以x为range最大值时，此时最优的range最小值是什么？显然，除了x所在的“组”，其他的组我们都会选取该组的最大值，因为它们比同组的其他元素离x更近。于是等效于我们pick了所有组的最大元素组成一个range。如果我们用优先队列来盛装这n个元素组成的range，我们就可以知道这个range里面的最小值y，于是x-y就是deviation。

接下来，我们会将全局最大值x扔掉，那么它所在组就会用该组第二大的元素来“替补”这个代表席位并放进range里。此时，全局次大值x'必然也在这个range里（因为它必然是此时某组的最大值）。于是x'减去此时range的最小值，得到的就是x'所对应的最优range的deviation。

依次类推，每一轮我们扔掉之前的全局最大值，同时递补进该组的下一个元素。此时range里面的n个元素的deviation，就对应了“当前最大值”作为“range最大值”时的最优解。

此题本质上和```632.Smallest-Range-Covering-Elements-from-K-Lists```非常类似。
