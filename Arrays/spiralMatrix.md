<h2><a href="https://leetcode.com/problems/spiral-matrix-ii/">59. Spiral Matrix II</a></h2><h3>Medium</h3><hr><div><p>Given a positive integer <code>n</code>, generate an <code>n x n</code> <code>matrix</code> filled with elements from <code>1</code> to <code>n<sup>2</sup></code> in spiral order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> [[1,2,3],[8,9,4],[7,6,5]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> [[1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
</ul>
</div>

<h2>Code:</h2>

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>m(n,vector<int>(n,0));
        int c=1;
         int left=0,right=n-1,top=0,bottom=n-1;
        while(left<=right && top<=bottom){
            
                for(int i=left;i<=right;i++){
                    m[top][i]=c;
                    c++;
                }
                top++;
            
                for(int i=top;i<=bottom;i++){
                   m[i][right]=c;
                    c++; 
                }
                right--;
            
                for(int i=right;i>=left;i--){
                    m[bottom][i]=c;
                    c++;
                }
                bottom--;
            
             
                for(int i=bottom;i>=top;i--){
                   m[i][left]=c;
                    c++; 
                }
                left++;
            
        }
        return m;
    }
};
    
```
