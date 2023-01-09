### 2532.Time-to-Cross-a-Bridge

首先注意，这是一个模拟题，不是一个优化策略问题。所有的规则已经完备地定义了所有工人该如何运作。我们需要设计代码将这个模拟过程实现。

我们针对左岸设立两个优先队列。leftArrive收集所有预期到达左岸（准备渡河）的工人id和时间，按照到达时间从早到晚排序。leftWait收集截止nextFree（桥空闲）时刻已经在等待渡河的工人id，按照efficiency排序。同理我们设计rightArrive和rightWait。

初始状态：所有的工人都在leftArrive里，到达时刻是0. 另外nextFree就是0.

每个回合，我们根据当前的nextFree，将leftArrive里面所有到达时间早于nextFree的工人都转移到leftWait里。同理，将rightArrive里面所有到达时间早于nextFree的工人都转移到rightWait里。这意味着，在nextFree时刻，我们会在leftWait和rightWait这两个队列里按照规则选择一个人过桥。但是注意，此时可能出现一种情况，那就是leftWait和rightWait依然都为空。这是因为nextFree可能太早，即桥已经空闲的时候，左右两边还没有人到。这个时候，我们需要调整nextFree，将其延后至leftArrive和rightArrive队列中各自队首元素的较小值，然后根据更新后的nextFree重复上述过程，将一个或若干个工人加入wait队列。

在leftWait或rightWait有了人之后，我们就按照规则选取一个人过河。如果rightWait队列有人，我们就取排位第一的工人（记做id）去渡河，那么nextFree就会延后time[id][2]（即过桥的过程），同时leftArrive就会新增一个预期的到达，即id会在时刻`nextFree+time[id][2]+time[id][3]`重回左岸。如果右边队列没人，我们就取leftWait排位第一的工人（记做id）去渡河，那么nextFree就会延后time[id][0]，同时rightArrive就会新增一个预期的到达，即id会在时刻`nextFree+time[id][0]+time[id][1]`重回右岸。

当我们发现有n个人（次）从右岸到了左岸，那么第n次右岸到左岸的nextFree就是答案。

此外本题有个坑。我们只需要n个人（次）从左岸到右岸，如何之后继续允许左岸到右岸的操作，有可能会延误右岸的人的回归。所以当第n次左岸到右岸操作后，我们需要将永久性地将leftArrive和leftWait清空。
