### 2867.Count-Valid-Paths-in-a-Tree

很显然，因为需要计数的path只有一个prime，我们必然count paths by prime.

我们考虑每个是质数的节点P，考虑经过它的有效路径。显然，一个最显著的pattern就是：从P某个联通的合数节点（不需要紧邻但是不能被其他质数隔开）开始，经过P，再到P的另一个联通的合数。

假设A有M个紧邻的合数节点（显然不会关注紧邻的质数节点），这些合数节点又各自分别于若干个合数节点联通，记这些联通区域里分别有m1,m2,m3...个联通的合数节点。显然，从m1里的任何一个节点，到除m1里的任意节点，都是合法路径。令`m1+m2+m3+...=total`，则有
```cpp
for (int i=1; i<=M; i++)
  count += m_i * (total - m_i);
```
但是注意，以上的count对于起点、终点互换的路径是重复计算了，所以最终有效的是count/2条路径。

另外，有效路径的第二个pattern，就是以P为起点，终点是任意与P联通的合数节点，这样的路径恰好就是total条。

最终的答案就是对于每个P，累加`count/2+total`.
