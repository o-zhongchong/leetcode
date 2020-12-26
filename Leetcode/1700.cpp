class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int len1 = students.size();
        int len2 = sandwiches.size();
        int i = 0, j = 0, cnt = 0;
        
        while(cnt < len1)
        {
            if(students[i] == sandwiches[j])
            {
                students.erase(students.begin() + i);
                --len1;
                i = cnt = 0;
                ++j;
            }
            else
            {
                i = (i + 1) % len1;
                ++cnt;
            }
        }
        
        return cnt;
    }
};