### 1520.Maximum-Number-of-Non-Overlapping-Substrings

考虑一个substring里面，如果出现了字母a，那么所有字母a必须出现在这个substring中，一个直接的想法是，这个substring必然要跨越a出现的所有位置。也就是说起始点必然是start['a']，截止点必然至少是end['a']（可能更靠后，下面会解释）。于是我们的注意力就集中在了26个substring上，他们就是以每个字母最早和最晚出现的位置为跨度的字符串。

但是显然并不是上面26种substring都是符合题目中第二个条件的。假设第一个a在第1个位置，最后一个a在第10个位置；但是同时有第一个b在第5个位置，最后一个b在第15个位置。所以当我们考虑以第一个a为起始的字符串时（left=1），此时[1,10]的区间内包含了字母b，所以我们不得不把区间的右端点后移，至少要移动到end['b']的位置。于是我们就一路往后遍历，不断拓展右边界，直到找到一个right，使得[left,right]所包含的所有字母的start/end都在这个区间内。

我们重复利用这个策略，就可以得到26种符合第二个条件的substring，他们的起始点分别是第一个a、第一个b、第一个c...所谓“符合第二个条件”就是题意中的 A substring that contains a certain character c must also contain all occurrences of c。注意，实现这个的时间复杂度是o(26N). 

接下来特别注意，这（最多）26种substring，要么互斥，要么互相嵌套，不可能出现部分相交的情况。（Why？假设有两个按照上述规则生成的合法区间ABC和BCD，而之所以BCD成立是因为BC本身必定不是合法的必须延伸到D，那么这与ABC本身已经合法相互矛盾。）对于互相嵌套的区间，根据题意 If there are multiple solutions with the same number of substrings, return the one with minimum total length. 我们再两两比较一下每对区间，将互相嵌套的大区间都排除即可。
