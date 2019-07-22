class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> hash_table;
        vector<int> ret;

        for (auto i : arr2)
        {
            if (hash_table.find(i) == hash_table.end())
                hash_table.insert( make_pair(i, 0) );
        }
        
        for (unsigned int i = 0; i < arr1.size(); ++i)
        {
            auto search = hash_table.find( arr1[i] );
            if (search == hash_table.end())
            {
                unsigned int j;
                for (j = 0; j < ret.size(); ++j)
                {
                    if (ret[j] > arr1[i])
                    {
                        ret.insert(ret.begin() + j, arr1[i]);
                        break;
                    }
                }
                if (j == ret.size())
                    ret.push_back(arr1[i]);
            }
            else
                search->second = search->second + 1;
        }

        for (int i = arr2.size() - 1; i >= 0; --i)
        {
            auto search = hash_table.find(arr2[i]);
            while (search->second)
            {
                ret.insert(ret.begin(), search->first);
                --search->second;
            }
        }
        return ret;
    }
};