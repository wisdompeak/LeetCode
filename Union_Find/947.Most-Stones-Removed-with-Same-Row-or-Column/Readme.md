### 947.Most-Stones-Removed-with-Same-Row-or-Column

本题的核心就是找出这样的规律：将所有同行或者同列关系的石头两两归并，最终都融为一个group。在这一个group里面，依次取度为1的石头（即同行或同列还有剩余的石头），按照规则可以一直取到整个组只剩下一个为止。

因为每个group都只剩一个石头，所以可以移走的石头数目，就等于总共的石头数目减去group的数目。


[Leetcode Link](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column)