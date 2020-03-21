### 946.Validate-Stack-Sequences

本题的解法类似于贪心。我们从前往后观察pushed，一旦发现pushed末尾有任何长度的序列和poped队首的对应长度序列正好是反向关系，就将两者相消。然后继续观察剩下的pushed和poped，继续往后遍历pushed，做同样的操作。直到两者的序列都彼此消掉，说明两者对应的是一个合法的入栈/出栈操作。

```
   A     B    C     D
*******++++++*****++++++
                  ++++++  E
                  ----------  F
*******++++++*****---------- 
  J       I    H    G
```
举如上的例子，相同的序列段用同样的字符表示。实际栈操作的顺序是 +A +B +C +D -E +F -G -H -I -J。所以相应的pushed = ABCDF, poped = EGHIJ。其中D和E是对应的，F和G是对应的，H和C是对应的，I和B是对应的，J和A是对应的。

根据我们上述的算法，当查看到pushed里面的B时，发现恰好与poped中的E相同，根据规则需要将B和E进行相消。但实际上的操作里面，D与E才是相消关系。所以这种算法合理吗？

答案是合理的。因为尽管我们将B和E进行了错误的对消，但是必然存在D和I也可以在后续得到对消。不信我们试一试，此时栈操作的顺序（根据我们的算法理解）变相成了 +A +B -E +C +D +F -G -H -I -J，尽管提前做了出栈的操作-E，但总的pushed = ABCDF, poped = EGHIJ 依然不变。就是这么神奇。


[Leetcode Link](https://leetcode.com/problems/validate-stack-sequences)