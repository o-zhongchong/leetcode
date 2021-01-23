class Solution {
public:
    bool isCommon(vector<int>& x, vector<int>& y)
    {
        set<int> common;
        
        for(auto i : x)
        {
            common.insert(i);
        }
        
        for(auto i : y)
        {
            if(common.find(i) != common.end())
            {
                return true;
            }
        }
        
        return false;
    }
    
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        int len = friendships.size();
        vector<int> count(n, 0);
        set<int> users;
        
        for(int i=0; i<len; ++i)
        {
            int x = friendships[i][0] - 1;
            int y = friendships[i][1] - 1;
            
            if(!isCommon(languages[x], languages[y]))
            {
                users.insert(x);
                users.insert(y);
            }
        }
        
        int user_max = users.size();
        int user_min = user_max;
        
        for(auto x : users)
        {
            for(auto i : languages[x])
            {
                ++count[i-1];
                user_min = min(user_min, user_max - count[i-1]);
            }
        }
        
        return user_min;
    }
};