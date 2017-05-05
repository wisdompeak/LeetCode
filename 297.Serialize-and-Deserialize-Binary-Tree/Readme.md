### 297.Serialize-and-Deserialize-Binary-Tree

本题按照leetcode介绍的编码方式。构建队列，按照BFS逐层遍历二叉树，遇到非NULL节点就记录数值，遇到NULL就记录'#'，每个节点之间用','分开。遍历到队首的非NULL节点，其两个子节点都会加入队列；对于队首的NULL节点，则跳过不加入元素。

整个编码过程和BFS遍历过程没有太大区别。
```cpp
    string serialize(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        string result;
        while (!q.empty())
        {
            TreeNode *node=q.front();
            q.pop();
            if (node==NULL)
                result+='#';
            else
            {
                result+=to_string(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            result+=',';
        }
        cout<<result<<endl;
        return result;
        
    }
```
解码的时候，先将整个编码字符串根据逗号的分隔存入一个字符串数组q中；数组中的每个元素代表一个节点。构建一个nodeArray存储节点指针与q可以一一对应。
```cpp
        int i=0;
        int j=0;
        while (i<data.size())
        {
            if (data[i]==',')
            {
                i++;
                continue;
            }
            else
            {
                string temp;
                while (data[i]!=',')
                {
                    temp+=data[i];
                    i++;
                }
                q.push_back(temp);
            }
        }
```        
首先根据q[0]可以的到nodeArray[0].
```cpp
        if (q[0]=="#")
            nodeArray[0]= NULL;
        else
            nodeArray[0]= new TreeNode(stoi(q[0],nullptr,10));
```            
设置初始指针i=0表示当前父节点,j=1表示当前子节点。

对于父节点i,对应的两个子节点必为j和j+1. 所以可以根据q[j]和q[j+1]的值创建两个节点，并分别作为nodeArray[i]的左右子节点。然后i++,j+=2. 注意此时如果q[i]==“#”,则说明nodeArary[i]并没有子节点被记录，故继续i++直到找到非NULL的节点作为j和j+1的父节点。
```cpp
        i=0;
        j=1;
        while (i<q.size())
        {
            if (q[i]=="#")
            {
                i++;
                continue;
            }
            else
            {
                if (q[j]=="#")
                {
                    nodeArray[j] = NULL;
                }
                else
                {
                    int val;
                    val = stoi(q[j],nullptr,10);
                    nodeArray[j] = new TreeNode(val);
                }
                nodeArray[i]->left = nodeArray[j];
                j++;
                
                if (q[j]=="#")
                {
                    nodeArray[j] = NULL;
                }
                else
                {
                    int val;
                    val = stoi(q[j],nullptr,10);
                    nodeArray[j] = new TreeNode(val);
                }
                nodeArray[i]->right = nodeArray[j];
                j++;
                
                i++;
            }
        }
        
        return nodeArray[0];
```        
