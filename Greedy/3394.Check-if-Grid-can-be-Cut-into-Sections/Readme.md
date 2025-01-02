### 3394.Check-if-Grid-can-be-Cut-into-Sections

本题的本质就是在横纵方向上，分别查验是否存在至少三个non-overlapping intervals.

数non-overlapping intervals的经典算法就是将所有区间按照首端点排序。将第一个区间的未端点记作far，然后依次查看后续区间的首端点是否小于等于far，是的话就说明必然存在overlap。同时，每查看一个后续区间，我们都用该区间的尾端点区更新far值（取max）。直至下一个区间的首端点在far之后停止。此时我们之前考察的所有区间，必然都是存在partial overlap的，但是他们merge后的整体不会与其他区间再有重合。

之后我们再从下一个区间开始，重复上面的操作，找到另一个存在overlap的区间群。依次类推。
