### 2375.Construct-Smallest-Number-From-DI-String

首先我们知道，必须将尽量小的字符放在前面使用。

我们将pattern前加上一个“I”，这样pattern的长度就与字符串相等。我们发现，将每个“IDD...D”视作一个section，那么后一个section必然要完全高于前一个section。我们虚拟地令当前的最大字符是0，然后把后续整个字符串的相对走势都表达出来后（必然都大于0），得到的就是用1~9组成的字典序最小的字符串。

注：本题是`942. DI String Match`的follow-up，并且和`484.Find-Permutation`一模一样
