828.Count-Unique-Characters-of-All-Substrings-of-a-Given-String

暴力的方法是枚举substring，然后考察这个区间里的字符哪些是unique的。这需要大致```o(N^2*26)```的复杂度。聪明的方法是考察每个字符，它可能在哪些substring里是unique的。

我们逐一遍历每个字符，现在考虑以i为结尾的各种substring。假设字符A在i之前最近两次出现的位置分别是a和b，如下图
```
X X X X A X X [A X X i]
        a      b
```
显然，形如[a+1:i], [a+2:i], ... [b:i]这些substring（总共b-a个）里面只出现过一次A，也就是说对于这些substring而言，A给它们的countUniqueChars都贡献了一分。我们可以直接将b-a分加入到全局的答案中。而以其他任何位置作为起点的substring，A都无法给countUniqueChars贡献分数了。

同理，我们可以考察字符B,C,...他们对以i结尾的substring的贡献，将这些分数直接加入总分里面。

综上，每考察一个位置i，我们遍历26个字母（即A-Z）在i之前出现的最后两个位置，可以计算它们各自可以给多少substring贡献UniqueChars。总的时间复杂度是o(26N)。
