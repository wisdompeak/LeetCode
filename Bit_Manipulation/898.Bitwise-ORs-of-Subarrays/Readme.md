### 898.Bitwise-ORs-of-Subarrays

本题的突破口在于，OR的结果不会特别多，因为OR得越多，越趋近于`111.11`. 我们能够存储下以每一个元素为右端点时所有subarray的可能OR值。
