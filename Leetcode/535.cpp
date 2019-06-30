#include<unordered_map>

class Solution {
public:
    unordered_map<int,string> longUrlMap;
    int seq,maxSize;

    Solution()
    {
        seq = 0;
        maxSize=10000;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = "encode failed";
        if(seq >= maxSize)
            return shortUrl;

        shortUrl = to_string(seq);
        longUrlMap.insert({seq,longUrl});

        if(longUrlMap.size() == maxSize)
        {
            seq = maxSize;
            return shortUrl;
        }

        while(longUrlMap.find(seq) != longUrlMap.end())
        {
            ++seq;
            seq = seq % maxSize;
        }
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int seq = atoi(shortUrl.c_str());
        if(seq >=0 && seq < maxSize)
        {
            auto search = longUrlMap.find(seq);
            if(search != longUrlMap.end())
                return search->second;
        }
        return string("decode failed");
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
