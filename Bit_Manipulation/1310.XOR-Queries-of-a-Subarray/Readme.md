### 1310.XOR-Queries-of-a-Subarray

求区间的异或和，可以转化为前缀异或和的异或。即```xor[i:j] = pre_xor[j] ^ pre_xor[i-1]```.
