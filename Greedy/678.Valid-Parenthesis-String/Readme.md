### 678.Valid-Parenthesis-String

回想一下，如果没有“\*”的话，我们怎么处理？我们其实只需要一个计数器count表示未匹配的括号，遇到左括号就加一，遇到右括号就减一。在遍历的过程中，count不能小于零；在结束遍历后，count必须等于零。

那么有“\*”的情况下，我们的计数器需要表示一个范围[lower,upper]，表示未匹配的左括号的可能的数目。为什么？遇到左括号，未匹配的左括号数就加一；遇到右括号，未匹配的左括号数就减一，这个规则没有变。但是遇到\*的时候，它可以当做左括号，也可以当做右括号,也可以当做空号。所以我们需要处理的方法是：lower--; upper++。

那么遍历的过程中这个范围会有什么变化呢？首先，当lower小于0的时候，物理上不可能发生，所以要置0。这说明之前出现的某个\*不能再代表右括号了，但可以表示成空号或者左括号。所以lower可以加上1变成0，而upper保持不变（因为当前upper的值是假设那个星号是左括号，这个假设目前仍然合理）。

P.S. 特别注意,如果题目中说的是\*不能作为空号而只能用作左右括号的话,此时的lower应该置为1,因为我们是把一个可能用作右括号的\*确定必须为左括号.一正一反相当于lower的值会增2。此时upper的值仍然不变。

遍历的过程中,upper不能小于0。因为当upper小于0时,说明即使把所有的\*当做左括号来处理,都不能抵消非常多的右括号.这种极端情况下,可以提前判断终止.

最关键的一点，在遍历结束后，这个范围需要满足什么条件？lower不能大于零。大于零说明必然有至少一个永不可能匹配的括号，需要返回false。如果lower等于0，不管upper如何，都可以返回true。

类似的题有[lintcode 1475.Minimum-Legal-Bracket-Sequence](https://github.com/wisdompeak/LintCode/tree/master/Greedy/1475.Minimum-Legal-Bracket-Sequence)


[Leetcode Link](https://leetcode.com/problems/valid-parenthesis-string)