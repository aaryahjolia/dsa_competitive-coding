// "static void main" must be defined in a public class.
public class Search_2d_matrix {
    public static boolean searchMatrix(int[][] matrix, int target) {
        int row = 0;
        int col = matrix[0].length - 1;

        while (row < matrix.length && col >= 0) {
            // if here value is match then it will simply return the true value.
            if (matrix[row][col] == target) {
                return true;
                // if here target is less then we shift the column by 1.
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                // if value is greater then we have to shift to next row.
                row++;
            }
        }
        // if target value is not found then it will return false.
        return false;
    }

    public static void main(String[] args) {
        // we have decalare the 2d array
        int[][] matrix = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } };
        int target = 3;
        // here we are calling the searchMatrix method in which we have passed two
        // argument.
        System.out.println(searchMatrix(matrix, target));
        // O(log(m * n))
    }
}