### 843.Guess-the-Word

此题的原理很简单：我们任取一个word，调用API查看它与secret的匹配度k。于是我们可知，任何与word匹配度不是k的单词，肯定都不会是secret，于是就可以从candidate中删除。

一旦我们取到某个word，与secret的匹配度是6，那么就是答案。
