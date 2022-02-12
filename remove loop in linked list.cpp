class Solution
 {
 public:
     //Function to remove a loop in the linked list.
     void removeLoop(Node* head)
     {
         // code here
         // just remove the loop without losing any nodes
         Node* slowPtr = head;
         Node* fastPtr = head;
         Node* prev = nullptr;
         while (fastPtr->next && fastPtr->next->next) {
             prev = slowPtr;
             slowPtr = slowPtr->next;
             fastPtr = fastPtr->next->next;
             if (slowPtr == fastPtr) {
                 break;
             }
         }
         if (fastPtr->next) {
             fastPtr = head;
             while (fastPtr->next && slowPtr->next) {
                 if (slowPtr == fastPtr) {
                     prev->next = nullptr;
                     break;
                 }
                 prev = slowPtr;
                 slowPtr = slowPtr->next;
                 fastPtr = fastPtr->next;
             }
         }
         return;
     }
 };
