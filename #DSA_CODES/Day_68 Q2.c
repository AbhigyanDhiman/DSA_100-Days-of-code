class Solution {
public:
    string findOrder(vector<string> &words) {
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        for (auto word : words) {
            for (char c : word) {
                present[c - 'a'] = true;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                    indegree[w2[j] - 'a']++;
                    found = true;
                    break;
                }
            }

            if (!found && w1.size() > w2.size()) return "";
        }

        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string result = "";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result += (char)(node + 'a');

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        int count = 0;
        for (bool p : present) if (p) count++;

        if (result.size() != count) return "";

        return result;
    }
};
