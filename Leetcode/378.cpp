class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<int> pq;
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                pq.push(matrix[i][j]);
                if(pq.size() > k) pq.pop();
            }
        }
        
        return pq.top();
    }
};