class Solution {
public:
    bool isValidSerialization(string preorder) 
    {

        int count=0;
        for (int i=0; i<preorder.size(); i++)
        {
            if (preorder[i]!=',' && preorder[i]!='#')
            {
                while (i<preorder.size() && preorder[i]!=',')
                    i++;
                count--;
            }
            else if (preorder[i]=='#')
            {
                count++;
                i++;
            }
            
            if (i<preorder.size()-1 && count>0) return false;
        }
        
        if (count!=1) return false;
        return true;
    }
};
