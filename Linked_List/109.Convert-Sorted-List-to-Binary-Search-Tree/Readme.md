### 109.Convert-Sorted-List-to-Binary-Search-Tree

用快慢指针fast/slow的方法定位到链表的中点，即为根结点，然后把中点前的ListNode切断。这样根结点的左子树即可递归调用 sortedListToBST(head)，右子树即可递归调用 sortedListToBST(slow-next). 

细节：
1. 为了能把中点前的ListNode切断，需要设置一个temp来保存慢指针的旧值。
2. 注意递归的边界条件。首先 (head==NULL) 必然需要单独处理；其次 (head->next==NULL)也需要单独处理；最后 (head->next->next==NULL) 也需要单独处理，因为在这种情况下，快指针是无法前进的，无法定位链表的中点。


[Leetcode Link](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree)