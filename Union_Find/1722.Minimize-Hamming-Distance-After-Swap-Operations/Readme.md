### 1722.Minimize-Hamming-Distance-After-Swap-Operations

我们将所有互相连接的allowedSwap的位置都union起来，这些位置上的数字其实都是可以任意重新排列的。我们只需要将source里这些位置上的元素集合，与target里这些位置上的元素集合进行比较，数一下有多少不同元素，就是Hamming distances.
