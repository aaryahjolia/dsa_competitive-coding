## Question Link :

https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

## Code solution :

C++

class Solution {
public:
    double average(vector<int>& salary) {
        
        int minv = *min_element(salary.begin(), salary.end());
        int maxv = *max_element(salary.begin(), salary.end());

        double sum = accumulate(salary.begin(), salary.end(), 0) - minv - maxv;
        return sum / (salary.size() - 2);
    }
};
