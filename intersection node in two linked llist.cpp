//naive approach:
//we will run two while loops. each node address in outer loop will be checked in inner loop if the both address is same. This is will take O(n * m) time.
//using hashmap: we will store each node either of two loop. then we will treverse other link list to check if there is any same node. time: O(n + m) and space: O(n)
// *********another approach******
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenght1 = 0;
        int lenght2 = 0;
        //count the lenght of both linked list simultinously
        ListNode * current1 = headA;
        ListNode * current2 = headB;
        while (current1 or current2){
            if (current1){
                lenght1 += 1;
                current1 = current1->next;
            }
            if (current2){
                lenght2 += 1;
                current2 = current2->next;
            }
        }
        //reset both to starting node
        current1 = headA;
        current2 = headB;
        int skip = abs(lenght1 - lenght2);
        if (lenght1 > lenght2){
            int count = 0;
            //skip to make both link lenght same
            while(count < skip){
                current1 = current1->next;
                count++;
            }
        }
        else if (lenght1 < lenght2){
            int count = 0;
            //skip to make both lenght same 
            while(count < skip){
                current2 = current2->next;
                count++;
            }
        }
      //now we have both linked of same lenght
        while (current1 && current2){
            if (current1 == current2){
                //we got the intersection point
                cout << current1->val << endl;
                return current1;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        //we did't get intersaction point
        return nullptr;
        
    }
};
//time: if the shortest link list lenght is n and the longest is m. we can say: 
//O(m): to get the lenght of both linked list
//O(m - n) : we have to skip this much step in longest linked list
//O(m): to find out the intersection node
//O(n) + O(m - n) + O(m) -> O(n + m) and space: O(1) since we are not using any extra space to store any node;
//*******optimized approach*****
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr){
            return nullptr;
        }
        ListNode* dummy1 = headA;
        ListNode * dummy2 = headB;
        //if we get same node, we will stop the loop
        while (dummy1 != dummy2){
            // the moment we reach the end of linked list, we have to reset head to another linked list
            dummy1 = dummy1 == nullptr ? headB: dummy1->next;
            dummy2 = dummy2 == nullptr ? headA: dummy2->next;
        }
        return dummy1;
        
    }
};
//time: O(n + m) and space: O(1)
//explaination vidoe link: https://youtu.be/u4FWXfgS8jw

