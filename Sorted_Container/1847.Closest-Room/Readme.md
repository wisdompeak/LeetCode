### 1847.Closest-Room

对于某个query，我们需要在大于等于minSize的房间找id最接近的，我们自然希望池子里只有大于等于minSize的房间，这样我们就有机会用heap和二分来定位最接近id的元素。所以我们可以将query按照minSize排序，保证我在处理某个query时，池子里放入的全部都是大于等于minSize的房间。这就是离线querying的优势。

随着query的逐个处理，进入池子的房间会单调增多。我们用heap维护这些房间的id，就很容易找到最接近preferred的id。

离线查询的思想还有```LC 1697```和```LC 1707```.
