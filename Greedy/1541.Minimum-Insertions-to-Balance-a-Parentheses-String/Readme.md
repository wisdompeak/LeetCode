### 1541.Minimum-Insertions-to-Balance-a-Parentheses-String

本题和 ```921 Minimum Add to Make Parentheses Valid```本质一样。区别只在于一个左括号必须和两个连续的右括号匹配。我们仍然可以沿用贪心法的思想，用count来记录未被匹配的左括号的数目。变化在于：
1. 我们需要连续两个右括号，才能试图与之前的一个左括号对消。如果不存在连续的两个右括号，我们必须先手工增加一个右括号，即```ret++```，然后再试图匹配左括号消减count。
2. 如果最终有剩余未被匹配的左括号，我们需要增加两倍数目的右括号与之对应，即```ret+=count*2```.
