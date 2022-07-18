Given a 2D array, print it in spiral form. See the following examples.



```cpp
vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
  vector<int> ans;
        int row = A.size();
        int col = A[0].size();
        
        int count = 0;
        int total = row*col;
        
        //index initialisation
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;
        
        
        while(count < total) {
            
            //print starting row
            for(int index = startingCol; count < total && index<=endingCol; index++) {
                ans.push_back(A[startingRow][index]);
                count++;
            }
            startingRow++;
            
            //print ending column
            for(int index = startingRow; count < total && index<=endingRow; index++) {
                ans.push_back(A[index][endingCol]);
                count++;
            }
            endingCol--;
            
            //print ending row
            for(int index = endingCol; count < total && index>=startingCol; index--) {
                ans.push_back(A[endingRow][index]);
                count++;
            }
            endingRow--;
            
            //print starting column
            for(int index = endingRow; count < total && index>=startingRow; index--) {
                ans.push_back(A[index][startingCol]);
                count++;
            }
            startingCol++;
        } 
        return ans;
    }
