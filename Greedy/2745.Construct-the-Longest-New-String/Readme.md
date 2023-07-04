### 2745.Construct-the-Longest-New-String

当我们仅考虑AA和BB时，我们可以将其交替串联，如BBAABBAA...，注意最后可以AA或BB结尾，使用两种片段的个数最多差1。这样能使用到的片段个数是 `min(x,y)*2 + min(abs(x-y),1)`.

然后考虑所有的AB，只需将其插入任何BB与AA之间即可，不影响之前的构造。

所以最终能使用到的片段个数是  `min(x,y)*2 + min(abs(x-y),1) +z`.
