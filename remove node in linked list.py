class Solution:
    #Function to remove a loop in the linked list.
    def removeLoop(self, head):
        # code here
        # remove the loop without losing any nodes
        slow_ptr = head
        fast_ptr = head
        prev = head
        while fast_ptr.next and fast_ptr.next.next:
            prev = slow_ptr
            slow_ptr = slow_ptr.next
            fast_ptr = fast_ptr.next.next
            if slow_ptr == fast_ptr:
                break
        if fast_ptr:
            fast_ptr = head
            while fast_ptr.next and slow_ptr.next:
                if fast_ptr == slow_ptr:
                    prev.next = None
                    break
                prev = slow_ptr
                slow_ptr = slow_ptr.next
                fast_ptr = fast_ptr.next
