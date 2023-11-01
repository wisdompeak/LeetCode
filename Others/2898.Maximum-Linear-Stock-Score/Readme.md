### 2898.Maximum-Linear-Stock-Score

将`prices[indexes[j]] - prices[indexes[j - 1]] == indexes[j] - indexes[j - 1]` 变形一下就是`prices[indexes[j]] - indexes[j] == prices[indexes[j - 1]] - indexes[j - 1]`。所以本题就是要找一组索引i，使得`prices[i]-(i+1)`相等。

所以我们用Hash将所有`prices[i]-(i+1)`相同的元素prices[i]都汇聚起来算sum，取最大的一个。
