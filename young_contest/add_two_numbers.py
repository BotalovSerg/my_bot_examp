# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        temp1 = l1
        temp2 = l2
        a = []
        b = []
        c = []
        while temp1 is not None:
            a.append(temp1.val)
            temp1 = temp1.next
        while temp2 is not None:
            b.append(temp2.val)
            temp2 = temp2.next
        a = a[::-1]
        b = b[::-1]
        aa = ""
        for i in range(len(a)):
            aa += str(a[i])
        ab = int(aa)
        bb = ""
        for i in range(len(b)):
            bb += str(b[i])
        ba = int(bb)
        cc = ab + ba
        st = str(cc)
        for i in range(len(st) - 1, -1, -1):
            c.append(int(st[i]))
        temp3 = ListNode(c[0])
        ll = temp3
        temp4 = temp3

        for i in range(1, len(c)):
            new_node = ListNode(c[i])
            ll.next = new_node
            ll = ll.next
        return temp4


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()
        current = head
        carry = 0
        while (l1 != None or l2 != None or carry != 0):
            l1_value = l1.val if l1 else 0
            l2_value = l2.val if l2 else 0
            total = l1_value + l2_value + carry
            current.next = ListNode(total % 10)
            carry = total // 10
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
            current = current.next
        return head.next

l1 = [2, 4, 3]
l2 = [5, 6, 4]
res = Solution().addTwoNumbers(l1=l1, l2=l2)
print(res)
