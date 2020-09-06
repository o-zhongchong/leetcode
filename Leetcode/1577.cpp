class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mymap1, mymap2;
        int cnt = 0;
        
        for(auto i : nums1)
        {
            if(mymap1.find(i) == mymap1.end())
            {
                mymap1.insert(make_pair(i, 1));
            }
            else
            {
                ++mymap1[i];
            }
        }
        
        for(auto i : nums2)
        {
            if(mymap2.find(i) == mymap2.end())
            {
                mymap2.insert(make_pair(i, 1));
            }
            else
            {
                ++mymap2[i];
            }
        }
        
        for(auto i : nums1)
        {
            long long s = (long long)i * (long long)i;
            
            for(auto j: nums2)
            {
                if(s % j != 0)
                {
                    continue;
                }
                
                int k = s / j;
                
                if(mymap2.find(k) != mymap2.end())
                {
                    if(k == j && mymap2[k] == 1)
                    {
                        continue;
                    }
                    else if(k == j && mymap2[k] > 1)
                    {
                        cnt += mymap2[k] - 1;
                    }
                    else if(k != j)
                    {
                        cnt += mymap2[k];
                    }
                }
            }
        }
        
        for(auto i : nums2)
        {
            long long s = (long long)i * (long long)i;
            
            for(auto j: nums1)
            {
                if(s % j != 0)
                {
                    continue;
                }
                
                int k = s / j;
                
                if(mymap1.find(k) != mymap1.end())
                {
                    if(k == j && mymap1[k] == 1)
                    {
                        continue;
                    }
                    else if(k == j && mymap1[k] > 1)
                    {
                        cnt += mymap1[k] - 1;
                    }
                    else if(k != j)
                    {
                        cnt += mymap1[k];
                    }
                }
            }
        }
        
        return cnt/2;
    }
};