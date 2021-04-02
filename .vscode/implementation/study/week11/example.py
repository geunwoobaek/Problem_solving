  
import math
class queues:
	def __init__(self):
		self.data = []
	def popp(self):
		if len(self.data)>0:
			s = self.data.pop(0)
			return s
		else:
			return False

		    
def connectedSum(graph_nodes,graph_from,graph_to):
    m = {}
    for i in range(0,len(graph_from)):
            if graph_from[i] not in m:
                    m[graph_from[i]] = [graph_to[i]]
            else:
                    temp = m[graph_from[i]]
                    temp.append(graph_to[i])
                    m[graph_from[i]] = temp
           
    visits = [False]*9
    data = []
    count = 0
    for i in m:
            if visits[i]==False:
                    temp = bfs(m,i,visits)
                    count += temp
                    data.append(math.ceil(math.sqrt(temp)))
    data.append(graph_nodes-count)
    print(sum(data))
            
        





        

def bfs(dir,strt,visited):
    
    
    queue = queues()
    queue.data.append(strt)
    
    visited[strt] = True
    s = True
    count = 1
    while s!=False:
        s = queue.popp()
        if s in dir:
            for i in dir[s]:
                if visited[i]!=True:
                    queue.data.append(i)
                    visited[i] = True
                    count += 1
    return count               

            
connectedSum(10,[1,1,2,3,7],[2,3,4,5,8])