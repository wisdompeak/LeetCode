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

        if (child==NULL && next==NULL)
            return h;
        else if (child!=NULL && next==NULL)
        {
            h->next = child;
            child->prev = h;
            Node* childEnd = findEnd(child);
            return childEnd;
        }
        else if (child==NULL && next!=NULL)
        {
            Node* nextEnd = findEnd(next);
            return nextEnd;
        }
        else
        {
            h->next = child;
            child->prev = h;
            Node* childEnd = findEnd(child);            
            childEnd->next = next;
            next->prev = childEnd;
            return findEnd(next);
        }
    }
};
