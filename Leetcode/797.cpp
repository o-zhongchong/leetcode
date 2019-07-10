class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        stack<int> path_stack;
        vector<int> path;
        vector<vector<int>> result;
        int index, end = graph.size() - 1;

        if (graph.size() <= 0)
            return result;
        path_stack.push(0);

        while ( !path_stack.empty()  )
        {
            index = path_stack.top();
            if ( !path.empty() && path.back() == index )
            {
                path.pop_back();
                path_stack.pop();
                continue;
            }

            if ( index == end )
            {
                path.push_back(index);
                result.push_back(path);
                path.pop_back();
                path_stack.pop();
            }
            else
            {
                if ( !graph[index].empty() )
                {
                    path.push_back(index);
                    for ( auto node : graph[index] )
                        path_stack.push(node);
                }
                else
                    path_stack.pop();
            }
        }
        return result;
    }
};