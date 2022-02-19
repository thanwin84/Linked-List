# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow_ptr = head
        fast_ptr = head
        # find the middle element
        while fast_ptr.next and fast_ptr.next.next:
            slow_ptr = slow_ptr.next
            fast_ptr = fast_ptr.next.next
        # we found the middle element
        middle_element = slow_ptr
        # this current is the head of the right half linked list
        current = slow_ptr.next
        prev = None
        # now reverse the linked list
        while current:
            _next = current.next
            current.next = prev
            prev = current
            current = _next
        # prev: new head of the right half linked list
        # link the left half linked with right half
        middle_element.next = prev
        
        slow_ptr = slow_ptr.next
        # move head and slow pointer by one step each time and check if both value is equal
        while slow_ptr:
            if head.val != slow_ptr.val:
                return False
            slow_ptr = slow_ptr.next
            head = head.next
        # arriving at the end of the linked list means given linked list is palindrone
        return True
