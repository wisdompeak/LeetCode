### 527.Word-Abbreviation

设置一个Map和一个Set。Map是从缩写到原单词(数组)的映射。Set盛装所有仍需要进一步求缩写的原单词，初始化的时候则装所有的原单词。

在每次循环中，把Set里所有的单词都求其缩写加入Map，清空Set。然后查看Map的所有元素，对于那些仍然对应多个原单词的缩写，就把这些原单词加入Set。清空Map。

重复这样的循环直至Set不再有元素。


[Leetcode Link](https://leetcode.com/problems/word-abbreviation)