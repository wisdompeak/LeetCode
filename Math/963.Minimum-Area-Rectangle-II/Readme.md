### 963.Minimum-Area-Rectangle-II

我们穷举任意的一对点（记作点i和点j），那么ij所组成的一条线段，可以用```deltaX = xj-xi, deltaY = yj-ji```来表示它的方向和长度。我们将同属于```{deltaX,deltaY}```的point pair（或者说线段）放在一起，即
```
Map[{deltaX,deltaY}].push_back({i,j}); 
```
那么对于同一个```key = {deltaX,deltaY}```所代表的这些线段，两两之间都一定可以组成一个平行四边形！

我们遍历这些平行四边形。对于每一个平行四边形，它们的四个点的坐标都是已知的（比如记作ijkt）。我们可以通过考察向量ij和向量jk是否垂直来判定这个四边形是否是矩形。数学上，具体的做法是考察两个二维向量的点积是否为零。即
```
v1(x1,y1)垂直于v2(x2,y2) <=> x1*x2+y1*y2 = 0
```

如果确认是矩形，那我们很容易计算它的面积，记录下来求最小值即可。

这种做法的效率较高，原因是我们将所有的线段（N^2)条按照“长度+方向”进行了分类。每一类里的线段数目其实比较少，做两两组合（构建平行四边形）的开销不大。


[Leetcode Link](https://leetcode.com/problems/minimum-area-rectangle-ii)