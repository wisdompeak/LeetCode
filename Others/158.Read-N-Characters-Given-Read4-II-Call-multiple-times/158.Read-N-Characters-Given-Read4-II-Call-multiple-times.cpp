// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    char ReadBuf[4];
    int i = 0;  // buf pointer
    int count = 0;  // buf counter
    
    int read(char *buf, int n) 
    {
        int j = 0; // destination buff pointer;
        while (j<n)
        {
            if (count!=0)
            {
                buf[j]=ReadBuf[i];
                i++;
                count--;
                j++;
            }
            else
            {
                count = read4(ReadBuf);
                i = 0;
                if (count==0) break;
            }
        }
        return j;
        
    }
};
