class Solution:
    def findMinStep(self, board, hand):
        """
        :type board: str
        :type hand: str
        :rtype: int
        """
        def DFS(board,hand):
            #print(board,hand)
            if (len(board)==0): return 0
            if (len(hand)==0): return -1            
            result = 10
            for i in range(len(hand)):
                if (i>0 and hand[i]==hand[i-1]): continue
                newhand=hand[0:i]+hand[i+1:]                                
                for j in range(len(board)):
                    if (board[j]!=hand[i] or j>0 and board[j]==board[j-1]): continue
                    newboard=board[0:j]+hand[i]+board[j:]
                    newboard=clean(newboard)
                    Next = DFS(newboard,newhand)
                    if Next!=-1:
                        result = min(result,Next+1)                
            if (result==10): return -1
            else: return result
            
        def clean(board):
            newboard=board
            board=""
            while (newboard!=board):                
                board=newboard;
                for i in range(len(board)):
                    j=i
                    while (j+1<len(board) and board[j+1]==board[j]):
                        j+=1
                    if (j-i+1>=3): 
                        newboard=board[0:i]+board[j+1:]
                        break
            return newboard
        
        print(clean("WWRRBBBWW"))
        hand = "".join((lambda x:(x.sort(),x)[1])(list(hand)))
        return DFS(board,hand)
                
                
            
                
