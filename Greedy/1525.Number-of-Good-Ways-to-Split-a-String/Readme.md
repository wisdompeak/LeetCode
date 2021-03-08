### 1525.Number-of-Good-Ways-to-Split-a-String

遍历p和q的分界点的位置i。我们可以提前用two pass计算出i左边的字符种类数left[i]，i右边的字符种类数right[i]。然后第三次遍历所有位置i，检查当```left[i]==right[i]```的时候，说明在此处划分字符串是符合要求的。
