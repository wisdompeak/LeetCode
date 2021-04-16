### 082.Remove-Duplicates-from-Sorted-List-II

注意实现上的小技巧。对于```... dummy->B1->B2->C1->C2-> D....```，我们做法是立足dummy，看到有若干个相同数值的B1、B2，就跳过他们，令```dummy->next = C1```。同样地，继续立足dummy，看到有若干个相同数值的C1、C2，就跳过他们，令```dummy->next = D```。

