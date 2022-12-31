### 2514.Count-Anagrams

本题的本质就是计算每个单词的distinct permutation的乘积。

对于一个单词长度为n，则distinct permutation的数目就是`n! / prod{k_i !}`，其中k_i就是每个字母在该单词中出现的频次。

本题的难点在于模下计算。上述公式中ki的阶乘是在分母上，所以需要取逆元。即转换为 `n! * prod{inv[k_i]!}`。因为ki的频次不超过1e5，所以我们可以提前预处理，用线性时间算出1e5以内所有的inv[i].
