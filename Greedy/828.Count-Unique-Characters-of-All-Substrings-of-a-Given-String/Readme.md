### 828.Count-Unique-Characters-of-All-Substrings-of-a-Given-String

暴力的方法是枚举substring，然后考察这个区间里的字符哪些是unique的。这需要大致```o(N^2*26)```的复杂度。聪明的方法是考察每个字符，它可能在哪些substring里是unique的。

#### 解法1：
我们逐一遍历每个字符，现在考虑以i为结尾的各种substring。假设字符A在i之前最近两次出现的位置分别是a和b，如下图
```
X X X X A X X [A X X i]
        a      b
```
显然，形如[a+1:i], [a+2:i], ... [b:i]这些substring（总共b-a个）里面只出现过一次A，也就是说对于这些substring而言，A给它们的countUniqueChars都贡献了一分。我们可以直接将b-a分加入到全局的答案中。而以其他任何位置作为起点的substring，A都无法给countUniqueChars贡献分数了。

同理，我们可以考察字符B,C,...他们对以i结尾的substring的贡献，将这些分数直接加入总分里面。

综上，每考察一个位置i，我们遍历26个字母（即A-Z）在i之前出现的最后两个位置，可以计算它们各自可以给多少substring贡献UniqueChars。总的时间复杂度是o(26N)。

#### 解法2：
我们考虑位于s[i]的字母A，能够给哪些substring的countUniqueChars提供这一分？显然，我们就是要寻找哪些substring仅包含这一个A。我们假设i之前最近的一个A在位置j，i之后最近的一个A在位置k，如下图
```
X X X X A [X X A X X] A X X 
        j      i      k
```
那么符合条件的substring的左边界可以在“j右边”到“i左边”之间游动；同理，这个substring的左边界可以在“i右边”到“k左边”之间游动。所以这样的substring的组合起来就有```(i-j)*(k-i)```个。

我们类似地对每一个s[i]这样处理，最终累加答案。这个解法的时间复杂度是o(N).

特别地，如果某个字符A在整个字符串里面只出现了一次或者两次，按照那么位置i之前或者之后可能就没有同样的字符出现。一个比较方便的处理方法是虚拟地认为在-1和n这两个位置都存在A。这样就依然可以当做上面的(j,i,k)的triplet来分析了。

我们把这类技巧称为```aggregate subarray by element```.当我们想累加若干个不同subarray的某种属性时，因为遍历subarray的复杂度较高，我们改为遍历数组元素，反向计算每个元素对于总属性的贡献。
