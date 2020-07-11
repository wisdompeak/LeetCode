/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) 
    {
        findEnd(head);
        return head;
    }

    Node* findEnd(Node* h)
    {   
        if (h==NULL) return NULL;

        Node* next = h->next;
        Node* child = h->child;
        h->child = NULL;

        if (child == NULL)
        {
            h->next = next;
            if (next == NULL) 
                return h;
            else
            {
                next->prev = h;
                return findEnd(next);
            }                
        }
        else
        {
            h->next = child;
            child->prev = h;
            Node* childEnd = findEnd(child);
            if (next==NULL)
            {
                childEnd->next = NULL;
                return childEnd;
            }
            else
            {
                childEnd->next = next;
                next->prev = childEnd;
                return findEnd(next);
            }
        }
    }
};
