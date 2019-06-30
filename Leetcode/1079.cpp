#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char,int> alphaSet;
        for (unsigned int i = 0; i < tiles.size(); ++i)
        {
            auto search = alphaSet.find(tiles[i]);
            if (search == alphaSet.end())
            {
                alphaSet.insert( make_pair(tiles[i], 1) );
            }
            else
                ++search->second;
        }
        return dfs(alphaSet);
    }
private:
    int dfs(unordered_map<char,int> &alphaSet)
    {
        int sum = 0;
        for ( auto &v : alphaSet )
        {
            if (v.second == 0)
                continue;

            --v.second;
            ++sum;
            sum += dfs(alphaSet);
            ++v.second;
        }
        return sum;
    }
};
