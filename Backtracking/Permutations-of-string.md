## Problem: Print All Permutations of a String/Array

### Input
- An array `arr` of distinct integers.

### Output
- Print all permutations of the given array.

### Intuition
To generate all permutations of an array, we can use backtracking. The idea is to swap each element with every other element in the array and recursively generate permutations for the remaining elements. This process is repeated for each element in the array, resulting in all possible permutations.

Let's understand the intuition with an example:

Example:
Suppose we have an array `arr = [1, 2, 3]`.

1. Start with the first element of the array, which is `1`.
2. Swap `1` with every other element (`2` and `3`), generating the following permutations:
   - `[1, 2, 3]`
   - `[1, 3, 2]`
3. Now, move to the next element, which is `2`.
4. Swap `2` with every other remaining element (`3`), generating the following permutations:
   - `[2, 1, 3]`
   - `[2, 3, 1]`
5. Finally, move to the last element, which is `3`.
6. Swap `3` with itself (no change), generating the following permutations:
   - `[3, 2, 1]`
   - `[3, 1, 2]`

The process ends here since we have considered all elements. The resulting permutations are:
   ` [
    [1, 2, 3],
    [1, 3, 2],
    [2, 1, 3],
    [2, 3, 1],
    [3, 2, 1],
    [3, 1, 2]
    ] `
    
    
    
### Code in Java

```java
import java.util.ArrayList;
import java.util.List;

class Permutations {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> permutations = new ArrayList<>();
        backtrack(nums, 0, permutations);
        return permutations;
    }

    private void backtrack(int[] nums, int start, List<List<Integer>> permutations) {
        if (start == nums.length - 1) {
            // If we have reached the end of the array, add the current permutation to the result
            List<Integer> permutation = new ArrayList<>();
            for (int num : nums) {
                permutation.add(num);
            }
            permutations.add(permutation);
            return;
        }

        for (int i = start; i < nums.length; i++) {
            // Swap the current element with each element after it
            swap(nums, start, i);
            // Recursively generate permutations for the remaining elements
            backtrack(nums, start + 1, permutations);
            // Restore the array to its original state by swapping back
            swap(nums, start, i);
        }
    }

    private void swap(int[] nums, int i, int j) {
        // Helper function to swap two elements in the array
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3};
        Permutations permutations = new Permutations();
        List<List<Integer>> result = permutations.permute(arr);
        System.out.println(result);     // this will eventually print out the result in console
    }
}

```
