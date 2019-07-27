class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ret;
        unordered_map<string, int> domain_count;

        for (unsigned int i = 0; i<cpdomains.size(); ++i)
        {
            string sub_domain;
            int position, count;

            position = cpdomains[i].find(" ");
            if (position == string::npos)
                return ret;
            else
            {
                string c = cpdomains[i].substr(0);
                count = atoi(c.c_str());
                sub_domain = cpdomains[i].substr(position + 1);
            }

            while (!sub_domain.empty())
            {
                auto search = domain_count.find(sub_domain);
                if (search == domain_count.end())
                {
                    domain_count.insert( make_pair(sub_domain, count) );
                }
                else
                {
                    search->second += count;
                }

                sub_domain = cut_str(sub_domain, ".");
            }
        }

        for (auto &i : domain_count)
        {
            string s = to_string(i.second) + " " + i.first;
            ret.push_back(s);
        }

        return ret;
    }
private:
    string cut_str(string str, string split_str)
    {
        string ret;
        int position = str.find(split_str);
        int len = split_str.size();

        if (position != string::npos && position + len < str.size())
        {
            ret = str.substr(position + len);
        }
        return ret;
    }
};