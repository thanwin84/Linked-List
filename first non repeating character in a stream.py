from collections import deque
class Solution:
    def FirstNonRepeating(self, A):
        seen = {}
        q = deque()
        result = ""
        for char in A:
            q.append(char)
            if char in seen:
                seen[char] += 1
            else:
                seen[char] = 1
            while q and seen[q[0]] > 1:
                q.popleft()
            if q:
                result += q[0]
            else:
                result += '#'
        return result
