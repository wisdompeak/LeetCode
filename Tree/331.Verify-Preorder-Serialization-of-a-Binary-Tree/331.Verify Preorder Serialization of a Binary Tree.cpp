class Solution {
public:
    bool isValidSerialization(string preorder) 
    {

        int count=0;
        for (int i=0; i<preorder.size()-1; i++)
        {
            if (preorder[i]!=',' && preorder[i]!='#')
            {
                while (i<preorder.size() && preorder[i]!=',')
                    i++;
                count++;
            }
            else if (preorder[i]=='#')
            {
                count--;
                i++;
            }
            
            if (count<0) return false;
        }
        
        if (count!=0) return false;
        if (preorder.back()!='#') return false;
        return true;
    }
};
