// time: O(n) and space: O(26)

class Solution {
public:
	string FirstNonRepeating(string A) {
		// Code here
		unordered_map<char, int> seen;
		string result;
		queue<char> q;
		for (auto i : A) {
			q.push(i);
			if (seen.count(i)) seen[i] += 1;
			else seen[i] = 1;
			while (q.size() > 0 && seen[q.front()] > 1) {
				q.pop();
			}
			if (q.size() > 0) {
				result += q.front();
			}
			else {
				result += '#';
			}
		}
		return result;
	}

};
