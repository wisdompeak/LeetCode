### 1319.Number-of-Operations-to-Make-Network-Connected

首先想到的是，属于同一组互联的多个计算机可能会有一些冗余的连接线。那么冗余多少呢？很简单，有N个计算机已经互联的话，那么只需要N-1条线就可以保证它们互联，多余的线其实都是可以拔掉的，我们可以改用它来连接不同局域网。

接下来，我们知道，如果将M个不相连的局域网都互通，那么需要M-1条线。

所以总体的算法是：用Union Find的方法来数一下有M个局域网；再计算每个局域网里有多少冗余的传输线并相加。如果所有冗余的传输线数目K>=M-1的话，那么就可以把所有的计算机都连接起来。


[Leetcode Link](https://leetcode.com/problems/number-of-operations-to-make-network-connected)