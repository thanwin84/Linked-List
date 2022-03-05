// naive approach
// we can take a unoordered_map<node, node>
// at first treversal, we will create a deep copy of every nodes of original linked list and then store it in hashmap
// at second treversal, we will check  for next pointer and random pointer. we will simply check hashmap for deep copy of next pointer and random pointer
//time: O(n) and space: O(n)
