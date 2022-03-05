# time: O(n) and space: O(1)
# even_head: 
class Solution:
    def divide(self, N, head):
        # code here
        even_head = node()
        even_head.data = 0
        even = even_head
        odd_head = None
        current = head
        prev = None
        while current:
            _next = current.next
            if current.data % 2 == 0:
                even.next = current
                even = even.next
                if prev is None:
                    prev = current
                else:
                    if prev.data % 2 != 0:
                        prev.next = _next
            else:
                if odd_head is None:
                    odd_head = current
                prev = current
            current = _next
        if even_head.next and odd_head != None:
            even.next = odd_head
            return even_head.next
        else:
          return head
