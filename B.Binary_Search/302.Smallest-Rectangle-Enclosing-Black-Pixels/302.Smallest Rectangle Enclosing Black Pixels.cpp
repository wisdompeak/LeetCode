class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) 
    {
        int M=image.size();
        int N=image[0].size();
        
        int upper = UPPER(image,0,x,0,N-1);
        int down = DOWN(image,x,M-1,0,N-1);
        int left = LEFT(image,0,M-1,0,y);
        int right = RIGHT(image,0,M-1,y,N-1);
        
        return (right-left+1)*(down-upper+1);

    }
    
    int UPPER(vector<vector<char>>& image,int RowMin, int RowMax, int ColMin, int ColMax)
    {
        int left = RowMin;
        int right = RowMax;
        int mid;
        while (left<right)
        {
            mid = left+(right-left)/2;
            int flag = 0;
            for (int i=ColMin; i<=ColMax; i++)
            {
                if (image[mid][i]=='1')
                {
                    flag = 1;
                    break;
                }
            }
            if (flag==0)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
    
    int DOWN(vector<vector<char>>& image,int RowMin, int RowMax, int ColMin, int ColMax)
    {
        int left = RowMin;
        int right = RowMax;
        int mid;
        while (left<right)
        {
            mid = left+(right-left)/2+1;
            int flag = 0;
            for (int i=ColMin; i<=ColMax; i++)
            {
                if (image[mid][i]=='1')
                {
                    flag = 1;
                    break;
                }
            }
            if (flag==0)
                right = mid-1;
            else
                left = mid;
        }
        return left;
    }
    
    int LEFT(vector<vector<char>>& image,int RowMin, int RowMax, int ColMin, int ColMax)
    {
        int left = ColMin;
        int right = ColMax;
        int mid;
        while (left<right)
        {
            mid = left+(right-left)/2;
            int flag = 0;
            for (int i=RowMin; i<=RowMax; i++)
            {
                if (image[i][mid]=='1')
                {
                    flag = 1;
                    break;
                }
            }
            if (flag==1)
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }    
    
    int RIGHT(vector<vector<char>>& image,int RowMin, int RowMax, int ColMin, int ColMax)
    {
        int left = ColMin;
        int right = ColMax;
        int mid;
        while (left<right)
        {
            mid = left+(right-left)/2+1;
            int flag = 0;
            for (int i=RowMin; i<=RowMax; i++)
            {
                if (image[i][mid]=='1')
                {
                    flag = 1;
                    break;
                }
            }
            if (flag==1)
                left = mid;
            else
                right = mid-1;
        }
        return left;
    }     
    
};
