class Solution:
       
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        self.Next = collections.defaultdict(list)
        self.Val = collections.defaultdict(float)
    
        for i in range(len(equations)):
            pair = equations[i]
            val = values[i]
            self.Next[pair[0]].append(pair[1])
            self.Val[pair[0]+":"+pair[1]]=val
            self.Next[pair[1]].append(pair[0])
            self.Val[pair[1]+":"+pair[0]]=1.0/val
        
        def DFS(a,b,visited):
            if a not in self.Next: return -1.0
            if a==b: return 1.0
            for k in self.Next[a]:
                if k in visited: continue
                visited.add(k)
                temp = DFS(k,b,visited)
                if temp!=-1: 
                    return self.Val[a+":"+k]*temp
                visited.remove(k)
            return -1.0        
        
        results =[]    
        for pair in queries:            
            visited={pair[0]}
            results.append(DFS(pair[0],pair[1],visited))
        return results
