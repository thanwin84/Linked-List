// time: O(n) and space: O(26)
// We could solve the problem simply by using hashmap but here we have cotinuous flow of character which is coming. so we can't just use only hashmap here
// here we have to find out the first non repeating character every time a char is inserted. So to maintain this order we can use queue. 
// whenever we get a char, we will push it to the q and hashmap. we will check if the peak of the queue freq is more than 1, that means it's not firstNonRepeatingCha
//if freq is 1, that means it's the first non repeating char

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
