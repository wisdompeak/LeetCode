class Solution {
public:
    Node* insert(Node* head, int insertVal) 
    {
        if (head==NULL)
        {
            Node* h = new Node(insertVal);
            h->next = h;
            return h;
        }
        
        Node* h = head->next;
        Node* pre = head;

        while (h!=head)
        {
            if (h->val >= pre->val )
            {
                h = h->next;
                pre = pre->next;
            }
            else                
                break;
        }
        
        Node* NewHead = h;        
        while (h->next!=NewHead && !(h->val<=insertVal && h->next->val>=insertVal))
            h = h->next;
        
        Node* temp = h->next;
        h->next = new Node(insertVal);
        h = h->next;
        h->next = temp;
        
        return head;
        
    }
};
