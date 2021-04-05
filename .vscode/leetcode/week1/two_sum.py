from operator import truediv, mul, add, sub

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverse_num(self, num: int) -> int:
        x = 0
        while(num != 0):
            x = 10*x+num % 10
            num = int(num/10)
        return x

    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        result_node = ListNode(0)
        num1, num2 = l1.val, l2.val
        carry = 10
        while l1.next != None or l2.next != None:
            l1,l2 = l1.next,l2.next
            if(l1==None):
                l1=ListNode(0)
            if(l2==None):
                l2=ListNode(0)
            num1 += (l1.val)*carry
            num2 += (l2.val)*carry
            carry *= 10
        # num1 = Solution.reverse_num(Solution,num1)
        # num2 = Solution.reverse_num(Solution,num2)
        res = num1+num2
        res, result_node.val = divmod(res, 10)
        temp=result_node
        while res != 0:
            temp.next=ListNode(0)
            cur_node = temp.next
            res, cur_node.val = divmod(res, 10)
            temp=cur_node
        return result_node


list1 = ListNode(2)
list1.next = ListNode(4)
list1.next.next = ListNode(9)
list2 = ListNode(5)
list2.next = ListNode(6)
list2.next.next = ListNode(4)
list2.next.next.next = ListNode(9)
list3 = Solution.addTwoNumbers(Solution, list1, list2)
print(1e-6)
