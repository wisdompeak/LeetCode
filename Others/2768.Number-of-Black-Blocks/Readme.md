### 2768.Number-of-Black-Blocks

为了不重不漏地数block，我们需要定义cell与block的关系。我们令每个block左上角的cell作为该block的“代表”，那么数block就转换成了数cell。

对于每个black cell，我们设想它可能属于block。显然，它最多属于四个不同的block，这些block对应的“代表”就是(x-1,y-1),(x,y-1),(x-1,y),(x,y).于是我们只需要给这四个block（的代表）各自加上一票即可。最终，每个block（的代表）所得的票数就意味着它所包含的black cell的个数。

注意，在右边界和下边界的cell是不能代表一个合法的block的。
