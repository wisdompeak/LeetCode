### 2856.Minimum-Array-Length-After-Pair-Removals

本题的本质就是Boyer-Moore Majority Voting Algorithm的实现。当存在一个超过半数的majority时，显然其他所有元素“联合”起来不能使它“消除”。反过来的结论也是成立的。

所以，当存在一个超过半数的majority时，记它的频次是f。那么剩余元素的频次是n-f。每个其他元素消灭一个多数元素，剩下的就是`n-(n-f)*2`.

当不存在超过半数的majority时，理论上是能够最终彼此消灭的，但是别忘了n的奇偶性。当n是奇数时一定会有一个元素留下来。
