# naive approach
# we can take a unoordered_map<node, node>
# at first treversal, we will create a deep copy of every nodes of original linked list and then store it in hashmap
# at second treversal, we will check  for next pointer and random pointer. we will simply check hashmap for deep copy of next pointer and random pointer
# time: O(n) and space: O(n)

# O(1) space solution
# step 1: create a copy node and insert the copy node after the original node. It means every copy node of original linked list will be right next to each other
# step 2: set the random pointer of copy node
# step 3: separate the copy linked list from original linked list
class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None
        # creating all the copy node
        current = head
        front = head
        while current:
            front = current.next
            # creating copy node
            copy = Node(current.val)
            # link the copy node right next to orinal node
            current.next = copy
            copy.next = front
            current = front
        # setting random pointer
        # head of the original link
        current = head
        # head of the copy link
        copy = head.next
        while current:
            # next node of original linked list
            front = copy.next
            if current.random != None:
                copy.random = current.random.next
            current = front
            if current:
                copy = front.next
        # seperate orginal and copy linked list
        current = head
        dummy = Node(0)
        copy = dummy
        while current:
            front = current.next.next
            copy.next = current.next
            current.next = front
            copy = copy.next
            current = front
        return dummy.next
            
            
