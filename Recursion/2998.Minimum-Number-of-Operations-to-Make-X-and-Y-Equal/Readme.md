### 2998.Minimum-Number-of-Operations-to-Make-X-and-Y-Equal

因为除法操作最高效，所有的增减操作都是为了能够凑出除法操作。所以当x>y时，我们想要将x拉低至y，只需要考虑以下五种操作：
1. 增加x，使得x能被11整除
2. 减小x，使得x能被11整除
3. 增加x，使得x能被5整除
4. 减小x，使得x能被5整除
5. 直接将x与y拉平。

此外，本题需要记忆化来提升效率。
