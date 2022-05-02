### 2262.Total-Appeal-of-A-String

此题几乎和```828.Count-Unique-Characters-of-All-Substrings-of-a-Given-String```一模一样。

#### 解法1：
我们逐一遍历每个字符，现在考虑以i为结尾的各种substring。假设字符A在i之前最近一次出现的位置分别是a，如下图
```
X X X X X X [A X X i]
             a
```
显然，形如[a:i], [a-1:i], ... [0:i]这些substring（总共a+1个）里面必然都至少出现过一次A。也就是说对于这些substring而言，A给它们的appeal都贡献了一分。我们可以直接将a+1分加入到全局的答案中。而以其他任何位置作为起点的substring，A都无法给countUniqueChars贡献分数了。

同理，我们可以考察字符B,C,...他们对以i结尾的substring的贡献，将这些分数直接加入总分里面。

综上，每考察一个位置i，我们遍历26个字母（即A-Z）在i之前出现的最后位置，可以计算它们各自可以给多少substring贡献appeal。总的时间复杂度是o(26N)。

#### 解法2：
如果同一个字符串里有多个A出现，那么为了避免重复计数，我们约定，该字符串里关于A贡献的appeal只是由最左边的A给出。那么对于位置a处的字母A而言，假设它之前最近的一个字母A位于b，如下图
```
X X X A X X [A] X X X
      b      a
```
则确定由位置a上的A字符贡献appeal的substring，其左边界可以在“b右边”到“a左边”之间游动，其右边界可以在“a右边”到“最后一个字符右边”之间游动。所以组合的方案数是```(a-b)*(n-a)```.

综上，依次遍历所有的字符串nums[i]，找到该字符能贡献appeal的字符串的左右边界范围，计算组合数目。最终将全部结果都加起来，返回答案。时间复杂度是o(n).
