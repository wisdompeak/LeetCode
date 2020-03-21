### 722.Remove-Comments

令s代表待输出的一行。此题考虑这么几个问题：

1. 遇到"//"怎么办？ 这一行的字符就直接跳过，直接将s加入result（注意，此时必须是非comment模式）
2. 遇到"/*"怎么办？ 进入了comment模式
3. 遇到"*/"怎么办？ comment模式结束，可以将s加入result
4. 普通字符？将字符加入s
5. 始终在comment模式里？ 那么继续遍历字符
6. 如果到了行结束，且不是comment模式，那么就可以将s加入result

要能够和谐地处理以上这几种情况，我们可以设置一个bool变量comment。

1. comment off && "//"怎么办？ 直接挑出该行
2. comment off && "/*"怎么办？ 进入了comment模式
3. comment on && "*/"怎么办？ 退出comment模式
4. comment off && 普通字符？将字符加入s
5. comment on && 普通字符？忽略该字符
6. 到了行结束，&& comment off：那么就可以将s加入result，清空s


[Leetcode Link](https://leetcode.com/problems/remove-comments)