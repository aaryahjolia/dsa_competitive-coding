/*
Given a binary tree A of integers. Return an array of integers representing the right view of the Binary tree.
Right view of a Binary Tree: is a set of nodes visible when the tree is visited from Right side.

Example Input

Input :

        1
      /   \
     2    3
    / \  / \
   4   5 6  7
  /
 8 

Output :

 [1, 3, 7, 8]

We will use BFS traversal for solving this problem. As we want to print right view of Binary Tree, 
we will push only last element of queue into vector.(Pushing right-most element of a level.)
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    vector<int> v;
    //Condition for empty tree
    if(A==NULL) return v;
    //Initializing queue for BfS Traversal
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            //Pushing last element of queue
            if(i==n-1)
                v.push_back(q.front()->val);
            if(q.front()->left!=NULL) q.push(q.front()->left);
            if(q.front()->right!=NULL) q.push(q.front()->right);
            q.pop();
        }
    }
    return v;
}