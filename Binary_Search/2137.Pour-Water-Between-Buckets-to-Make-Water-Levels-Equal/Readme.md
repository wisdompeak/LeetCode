### 2137.Pour-Water-Between-Buckets-to-Make-Water-Levels-Equal

二分搜值，猜测一个最终水位level。然后遍历所有水桶，将所有高于level的水量累计起来记做s1，将所有低于level的水量累计起来记做s2，如果s1扣除损耗之后仍然大于s2，那么就可以上调level，否则就下调level。
