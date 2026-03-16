### 3873.Maximum-Points-Activated-with-One-Addition

非常明显的Union Find。我们将所有属于同一个x坐标的点union起来，再将所有属于同一个y坐标的点union起来。这样所有的点就被聚类成了若干个group。此时我们只需要用额外的一个点，就可以将最大的两个group再union起来。具体的做法：在group A里取一个点(xa,ya), 在group B里取一个点(xb,yb)，那么我们构造(xa,yb)或者(xb,ya)就可以将这两个点连同各自的group连接起来，
