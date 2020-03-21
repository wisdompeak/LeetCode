### 591.Tag-Validator

此题的表述非常复杂，需要逐条分析，各个击破。

1. 首先检测是否 cdata 的段首关键字```<![CDATA[```。有的话,在遇到cdata段尾关键字```]]>```之前，所有字符不用check。
2. 如果不满足条件1，则检测是否 end tag 的标记```</```。有的话就遍历直到找到```>```，分割这段TagName，检测TagName是否和栈顶的tag匹配，退栈。另外，如果退栈后为空，说明这是最后一个end tag，此时应该对应code的末尾。
3. 如果不满足条件2，则检测是否 start tag 的标记```<```。有的话就就遍历直到找到```>```，分割这段TagName，判断TagName是否合法，将TagName推入栈。注意，另外，如果这是栈第一次非空，说明这是第一个start tag，此时应该对应code的开头。

在遍历完整个code字符串之后，还要保证栈空，且栈曾经非空过。这里可以用一个ever的变量来记录是否曾经有tag入栈过。


[Leetcode Link](https://leetcode.com/problems/tag-validator)