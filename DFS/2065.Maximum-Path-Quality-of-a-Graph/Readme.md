### 2065.Maximum-Path-Quality-of-a-Graph

题意的约束中给出了```10 <= timej, maxTime <= 100```，这说明最多只能走10步。又因为There are at most four edges connected to each node，每一步出发最多只有四种选择，所以无脑搜索的话最多也只有4^10=1e6种可能。全部本题只要穷举所有的路径选择即可。
