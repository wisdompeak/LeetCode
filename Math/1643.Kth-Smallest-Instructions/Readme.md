### 1643.Kth-Smallest-Instructions

根据矩阵的行数和列数，我们就可以知道整个路径需要多少个H和多少个V。本题的本质就是求```HHH..VVV...```的k-th permutation，这和 060.Permutation-Sequence的解法相同。

我们假设有h个H和v个V。那么K-th permuation的第一个字母该是H还是V呢？考虑如果第一位是H，那么后面的n-1位就由h-1个H和v个V组成，这样的不同的字符串总共有多少个呢？答案就是组合数```sum = C(h-1+v, h-1)```。

如果k<=sum，那么必然第一位就是H，否则第一位以V开头的任何排列在字典序的次序必然大于sum。所以下一步求h-1个H和v个V组成的第k-th permutation。

反之如果k>sum，必然第一位就是V，我们接下来求h个H和v-1个V组成的第(k-sum)-th permutation。

递归的终止条件就是当h为零的时候，一定输出V；或者当v为零的时候，一定输出H。
