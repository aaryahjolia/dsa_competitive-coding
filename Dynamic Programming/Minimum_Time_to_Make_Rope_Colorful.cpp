/*Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. 
Bob can remove some balloons from the rope to make it colorful. 
You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
Return the minimum time Bob needs to make the rope colorful.

Example 1:

Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.
*/

class Solution {
public:
    int minCost(string c, vector<int>& t) {
        int n = c.size();
        if(n==1) return 0;
        if(n==2) {
            if(c[0] == c[1]) return min(t[0], t[1]);
            else return 0;
        }
        int time=0;
        int prev=0;
        for(int i=1;i<n;i++) {
             if(c[i] == c[prev]) {
                 if(t[prev] <= t[i]) {
                     time += t[prev];
                     prev = i;
                 }
                 else {
                     time += t[i];
                 }
             }
            else {
                prev = i;
            }
        }
        return time;
    }
};

