### 1101.The-Earliest-Moment-When-Everyone-Become-Friends

本题考察的是常规的Union Find的操作．但是一个比较有意思的知识点是，如果快速判定我们已经聚了几个类呢？

方法是，如果一开始有Ｎ个元素，那就是Ｎ类．每两个不属于同一个类的元素进行union操作，就会少一个类．我们不断聚类的过程中，如果这个类计数器变为了１，那么就说明所有的元素都已经聚为了一类了．这个和 305. Number of Islands II 非常相似．


[Leetcode Link](https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends)