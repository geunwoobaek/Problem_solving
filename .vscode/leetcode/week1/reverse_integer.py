class Solution:
    def reverse(self, x: int) -> int:
        res=0
        isMinus= x<0
        if(isMinus):
            x*=-1
        while(x/10>0):
            res*=10
            res+=x%10
            x/=10
            x=int(x)
        if(res>2**31):
            res=0
        if(isMinus):
            res*=-1
        return res
solution =Solution
print(Solution.reverse(solution,
1534236469))
