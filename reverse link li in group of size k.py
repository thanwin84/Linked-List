class Solution:
    def reverse(self,head, k):
        if head is None:
            return head
        prev = None
        next = None
        current = head
        count = 0
        while current and count < k:
            next = current.next
            current.next = prev
            prev = current
            current = next
            count += 1
        next_head = self.reverse(next, k)
        head.next = next_head
        return prev
