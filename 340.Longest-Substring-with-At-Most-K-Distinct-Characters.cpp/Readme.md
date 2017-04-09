### 340.Longest-Substring-with-At-Most-K-Distinct-Characters.cpp

请多练，条件判断要考虑全面，做到bug free  

1，Map[s[j]]>0 该怎么办？  
要更新Map[s[j]]；更新result；j++；

2，Map[s[j]]==0 && count<k 该怎么办？  
要更新Map[s[j]]；更新result；j++；count++;

3，Map[s[j]]==0 && count==k 该怎么办？  
要更新Map[s[i]]；更新count；i--；
