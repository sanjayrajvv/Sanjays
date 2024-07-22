class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Initialize a 2D vector to keep track of reachability
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        
        // Fill the initial reachability based on prerequisites
        for (const auto& prereq : prerequisites) {
            reachable[prereq[0]][prereq[1]] = true;
        }
        
        // Apply Floyd-Warshall algorithm to compute transitive closure
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
                }
            }
        }
        
        // Answer the queries
        vector<bool> ans;
        for (const auto& query : queries) {
            ans.push_back(reachable[query[0]][query[1]]);
        }
        
        return ans;
    }
};
