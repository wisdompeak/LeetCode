/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) 
    {
        if (quadTree1->isLeaf && quadTree2->isLeaf)
        {
            Node* node = new Node(quadTree1->val || quadTree2->val, true, NULL, NULL, NULL, NULL);
            return node;
        }
        
        if (quadTree1->isLeaf && quadTree1->val || quadTree2->isLeaf && quadTree2->val)
        {
            Node* node = new Node(1, true, NULL, NULL, NULL, NULL);
            return node;
        }
        
        Node* A;
        Node* B;
            
        A = quadTree1->isLeaf ? quadTree1 : quadTree1->topLeft;
        B = quadTree2->isLeaf ? quadTree2 : quadTree2->topLeft;            
        Node* topLeft = intersect(A,B);
            
        A = quadTree1->isLeaf ? quadTree1 : quadTree1->topRight;
        B = quadTree2->isLeaf ? quadTree2 : quadTree2->topRight;            
        Node* topRight = intersect(A,B);
            
        A = quadTree1->isLeaf ? quadTree1 : quadTree1->bottomLeft;
        B = quadTree2->isLeaf ? quadTree2 : quadTree2->bottomLeft;            
        Node* bottomLeft = intersect(A,B);
            
        A = quadTree1->isLeaf ? quadTree1 : quadTree1->bottomRight;
        B = quadTree2->isLeaf ? quadTree2 : quadTree2->bottomRight;            
        Node* bottomRight = intersect(A,B);
            
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf \\
            && topLeft->val==topRight->val && topRight->val==bottomLeft->val && bottomLeft->val==bottomRight->val )
        {
            Node* node = new Node(topLeft->val, true, NULL, NULL, NULL, NULL);
            return node;
        }
        else
        {
            Node* node = new Node(0, false, NULL, NULL, NULL, NULL);
            node->topLeft = topLeft;
            node->topRight = topRight;
            node->bottomLeft = bottomLeft;
            node->bottomRight = bottomRight;
            return node;
        }
    }
};
