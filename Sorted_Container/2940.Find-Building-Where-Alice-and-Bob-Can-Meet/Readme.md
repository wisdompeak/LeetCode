### 2940.Find-Building-Where-Alice-and-Bob-Can-Meet

我们考虑一个query所给的两个位置a和b（其中a<b），显然题意要求在位置大于等于b的heights里，找到第一个大于max(heights[a],heights[b])的位置（记做target）。如果heights[b:n-1]这个后缀已经是按照高度有序的了，比如说放入了一个有序容器里（注意key是高度，value是index），那么我们用upper_bound命令就可以找到第一个大于target的高度。但是这个高度是否对应着leftmost的index呢？不见得，理论上我们要把所有大于taget的heights的对应的index都遍历一遍，取其中最小的一个。

那么能否有能优化的做法呢？显然我们可以将这个有序容器做一些改进。容易发现，如果容器里有两个元素，他们的index是x<y但heights[x]>heights[y]，那么事实上y就可以从容器里移除。因为x更靠近左边且更高，任何满足(a,b)->y的query，必然也满足(a,b)->x且x是比y更优的解（更靠近左边）。这就提示我们，如果我们将heights里的元素按照从右往左的顺序加入有序容器的话，那么就可以用上述的性质：新柱子的加入可以弹出所有比它矮的旧柱子。这就导致了这个有序容器里的柱子不仅是按照height递增的，而且他们对应的index也是递增的。也就是说，有序容器里对于任意的heights[x]<heights[y]，都有x<y；反之亦然，即对于任意的x<y，都有heights[x]<heights[y]。

有了这个性质，对于一个query所给的两个位置a和b（其中a<b），我们将所有大于b的柱子都加入有序容器里，这样在有序容器里只要用upper_bound命令找到第一个大于target的元素，其对应的index就是答案，而不需要再遍历更多。因为在这个容器里，比target更靠左的柱子必然都比target矮，不符合query的要求。

因此，我们就知道，第一步的操作是将所有的query按照b从大到小排序。这样依次处理query的时候，就会逐渐往这个有序容器里添加映射`heights[i]-> i`(for i>b)，同时更新容器移除陈旧的值（即那些相比于i，更靠右且更矮的柱子）。然后一个upper_bound解决该query。往容器里添加和删除元素的数据量都是线性的。

此外，本题需要处理两个小细节。如果heights[a]==heights[b]以及a==b的这两种情况，直接输出答案b即可。
