### 2337.Move-Pieces-to-Obtain-a-String

此题和```777. Swap Adjacent in LR String```一模一样。

因为任何LR都不会彼此跨越，所以我们很容易得到一个必要条件，那就是将空格字符拿掉之后，start和target字符串必须完全一致，先相同位置上的字符都是彼此对应的。

其次，因为target里的L必须是从start里对应的L向左移动得到，所以另一个必要条件就是查看他们的初始位置：start里的L必须比target里对应的L更靠右。同理，start里的R必须比target里对应的R更靠左。如果不满足，就可以直接返回true。

以上两个必要条件都满足后，答案就是充分的。
