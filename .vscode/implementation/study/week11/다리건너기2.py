import sys
input=sys.stdin.readline
def dfs(y,x,n):
    MAP[y][x]=n 
    for dy,dx in dpos:
        ny,nx=y+dy,x+dx
        if 0<=nx<N and 0<=ny<M and MAP[nx][ny]==1:
            dfs(ny,nx,n)
        
N,M =map(int,input().split())
dpos= [(0,1),(1,0),(0,-1),(-1,0)]
MAP=[]
nodeNum=2
for i in range(N): 
    MAP.append(list(map(int,input().split())))
for i in range(N):
    for j in range(M):
        if MAP[i][j] == 1:
            dfs(i,j,1
            ) 
            nodeNUm+=1
    
