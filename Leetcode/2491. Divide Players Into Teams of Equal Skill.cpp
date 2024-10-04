class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long chemistry = 0;
        int n = skill.size();
        sort(skill.begin(), skill.end());
        long totalskill = skill[0] + skill[n-1];
        for(int i = 0; i < (n/2); i++)
        {
            if((skill[i] + skill[n - i - 1]) != totalskill)
                return -1;
            chemistry += skill[i] * skill[n-i -1];
        }
        return chemistry;
    }
};