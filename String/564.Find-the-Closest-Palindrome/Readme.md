### 564.Find-the-Closest-Palindrome

看到题目最直观的想法是，想要尽量接近原数，那就保持高位不变，将数字的前半部分翻转后拼接到后半部分，比如说12345，那么我们就找12321，它必然是回文数。

但是这样的策略找到不一定是离原数最接近的。比如12399，如果我们选择直接翻转，12321就不是最优解，最优解应该是12421. 再比如19200,直接翻转的19291不是最优解，最优解是19191. 总之，直接翻转的策略，我们无法确定得到的是next greater palindrome，还是next smaller palindrome。而closest palindrome可能是两者的任意一个。于是这道题其实就转换成了分别求next greater palindrome和next smaller palindrome的问题。

根据以上的例子，我们发现如果“直接翻转”得到的是next greater palindrome，那么我们想求next smaller palindrome的话，就需要将数字的前半部分减一后再翻转。对于形如ABCXX的奇数长度形式，它的next smaller palindrome就是(ABC-1)再对称翻转（总长度不变）；同理，对于形如ABCXXX的偶数长度形式，它的next smaller palindrome也是(ABC-1)再对称翻转（总长度不变）。

类似地，发现如果“直接翻转”得到的是next smaller palindrome，那么我们想求next greater palindrome的话，就需要将数字的前半部分加一后再翻转。对于形如ABCXX的奇数长度形式，它的next greater palindrome就是(ABC+1)再对称翻转（注意翻转轴，要保持总长度不变）；同理，对于形如ABCXXX的偶数长度形式，它的next greater palindrome也是(ABC+1)再对称翻转（注意翻转轴，要保持总长度不变）。

但是，如果遇到加减之后位数变化的情况怎么办呢？比如10001,我们对前三位100减１之后得到的99，复制翻转拼接之后得到的999，位数一下子就少了两位．类似的对于999，我们如果对于前两位99加一变成100,复制翻转拼接后变成10001,位数一下子就多了两位．类似的情况对于偶数位的数字也会出现．怎么办呢？假设原数是n位数，对于这种位数加一会导致位数变化的情况，那么我们就直接返回n+1位数的100...0001；如果减一会导致位数变化的情况，那么我们就直接返回n-1位数的99...99。

综上，我们有了next greater palindrome和next smaller palindrome，选取和原数最接近的就是答案了．


[Leetcode Link](https://leetcode.com/problems/find-the-closest-palindrome)
