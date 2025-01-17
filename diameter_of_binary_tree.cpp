# include <vector>
# include <iostream>
# include <map>

using namespace std;


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // make constructor so that TreeNode can be created with int argument x
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // make constructor so that TreeNode can be created with int argument x & two Nodes
};

class binary_tree
{
    public:
    TreeNode *root;
    // default constructor
    binary_tree() {root = NULL;}

    void insert_leaf(int value, string location)
    {
        // location: (ex)'rlr' => root -> right leaf (1st layer) -> left leaf (2nd layer) -> right leaf (3rd layer)
        TreeNode *new_node = new TreeNode(value); // creating space for new TreeNode sturcture, and the pointer "new_node" can point to it
        if (root == NULL) // if root hasn't been built
        {
            root = new_node;
            return;
        }
        string::iterator iter;
        int layer_num = 0;
        TreeNode* current_node = this->root;
        // if not hit the NULL or reaching designated layer => go to the next layer
        // else connect new_node to the current_node
        for (iter=location.begin(); iter<location.end(); iter++)
        {
            
            if (*iter == 'r')
            {
                if (current_node->right != NULL)
                {
                    current_node = current_node->right;
                }
                else
                {
                    current_node->right = new_node;
                    return;
                }
                
                
            }
            else if (*iter == 'l')
            {
                if (current_node->left != NULL)
                {
                    current_node = current_node->left;
                }
                else
                {
                    current_node->left = new_node;
                    return;
                }
            }
            else
            {
                cout << "something wrong with input tree string" << endl;
                return;
            }
        }
        
    }
    
};

class Solution1
{
public:
    int max_path=0;
    int diameterOfBinaryTree(TreeNode* root)
    {
        this->dfs(root);
        return this->max_path;
    }

    int dfs(TreeNode* current_node) // Depth First Search: return maximum height of the current_node
    {
        if (!current_node) // if its NULL, no depth 
        {
            return 0;
        }
        int height_branch_left = dfs(current_node->left);
        int height_branch_right = dfs(current_node->right);
        this->max_path = max(this->max_path, height_branch_left+height_branch_right); // max. path num. = sum of both-side branch lengths
        return 1 + max(height_branch_left, height_branch_right); // one more edge to add for connecting to current_node
    }
};

int main(void)
{
    Solution1 func;
    binary_tree tree;
    std::map<int, std::string> map_for_tree = {
        {std::make_pair(1, "")},
        {std::make_pair(2, "r")},
        {std::make_pair(3, "rl")},
        {std::make_pair(4, "rr")},
        {std::make_pair(5, "rll")},
    };
    
    for (std::map<int, std::string>::iterator iter=map_for_tree.begin(); iter!= map_for_tree.end(); iter++)
    {
        tree.insert_leaf(iter->first, iter->second);
    }
    
    int answer = func.diameterOfBinaryTree(tree.root);
    cout << "diameter of the tree is: " << answer << endl;

    return 0;
}