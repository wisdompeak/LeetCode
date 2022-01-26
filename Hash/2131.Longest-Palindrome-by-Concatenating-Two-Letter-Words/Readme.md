### 2131.Longest-Palindrome-by-Concatenating-Two-Letter-Words

假设有字符串ab出现了count1次，字符串ba出现了count2次。那么我们就可以用min(count1,count2)个ab和ba对称放置组成回文串。

假设有字符串cc出现了count3次，那么我们就可以用```count3/2*2```个cc对称放置组成回文串。特别注意，如果有落单的、但是形如xx的字符串，我们可以额外放在正中间增加回文串的长度by 2.
