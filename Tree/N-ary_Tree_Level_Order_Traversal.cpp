/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    queue<Node*> q;
    vector<vector<int>> levelOrder(Node* root) {
        
        
        vector<int> v;
        vector<vector<int>> level;
        if(root!=NULL)
        {
            q.push(root);
            v.push_back(root->val);
            level.push_back(v);
        }
        while(!q.empty())
        {
            int m = q.size();
            v.clear();
            for(int i=0;i<m;++i)
            {
                Node* temp = q.front();
                q.pop();
                for(int j=0;j<temp->children.size();++j)
                {
                    q.push(temp->children[j]);
                    v.push_back(temp->children[j]->val);
                }
            }
            if(!v.empty())
            level.push_back(v);
        }
        return level;
    }
};
