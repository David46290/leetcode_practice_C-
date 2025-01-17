# include <vector>
# include <iostream>
# include <unordered_map>

using namespace std;


struct PrefixNode 
{
    unordered_map<char, PrefixNode*> children = {};
    bool end_of_word = false;
    // if inserting a new char 'a', then use children['a'] = PrefixNode() to insert the node
};

class PrefixTree 
{
public:
    PrefixNode* root = new PrefixNode(); // creating space for new PrefixNode sturcture, and the pointer "root" can point to it

    PrefixTree() //Initializes the prefix tree object.
    {
        
    }
    
    void insert(string word) //Inserts the string word into the prefix tree.
    {
        PrefixNode* current_node = this->root;
        string::iterator iter; 
        
        for (iter=word.begin(); iter<word.end(); iter++)
        {
            if (current_node->children.find(*iter) == current_node->children.end(*iter)) // prefix tree doesn't contain that char in that layer yet
            {
                current_node->children[*iter] =  new PrefixNode(); // creating space for new PrefixNode sturcture, and the pointer children[*iter] can point to it
            }
            current_node = current_node->children[*iter]; // move on to next layer of prefix tree
        }
        current_node->end_of_word = true; // the current_node would stop at the end char of "word" after the for loop, so mark that char as the end 

    }
    
    bool search(string word) //Returns true if the string word is in the prefix tree, and false otherwise.
    {
        PrefixNode* current_node = this->root;
        string::iterator iter; 
        for (iter=word.begin(); iter<word.end(); iter++)
        {
            if (current_node->children.find(*iter) == current_node->children.end(*iter)) // prefix tree doesn't contain that char in that layer yet
            {
                return false;
            }
            current_node = current_node->children[*iter];
        }
        
        return current_node->end_of_word; // after the for loop (the last char of "word"), current_node should be the last node if the prefix tree do contain the whole "word", no more or less.
    }
    
    bool startsWith(string prefix) //  Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
    {
        PrefixNode* current_node = this->root;
        string::iterator iter; 
        for (iter=prefix.begin(); iter<prefix.end(); iter++)
        {
            if (current_node->children.find(*iter) == current_node->children.end(*iter)) // prefix tree doesn't contain that char in that layer yet
            {
                return false;
            }
            current_node = current_node->children[*iter];
        }
        return true; // after the for loop, the chars in "prefix" surely have correct hierarchy in the prefix tree
    }
};

class PrefixTreeNode {
public:
    PrefixTreeNode* children[26]; // make spaces for 26 PrefixTreeNode structures, and children would be a pointer storaging those memories
    bool isWord;
    
    PrefixTreeNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL; // each node of the prefix tree should contain a~z 26 children nodes, and if theres no such char inside, the child node is NULL
        }
        isWord = false;
    }
};

class PrefixTree2 
{
public:
    PrefixTree2() 
    {
        root = new PrefixTreeNode();
    }
    
    void insert(string word) { // only work with lowercase
        PrefixTreeNode* node = root; // using int to store char
        int curr = 0;
        
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a'; // 'a'-'a'=0, 'b'-'a'=1, 'c'-'a'=2, ...
            if (node->children[curr] == NULL) {
                node->children[curr] = new PrefixTreeNode();
            }
            node = node->children[curr];
        }
        
        node->isWord = true;
    }
    
    bool search(string word) { // only work with lowercase
        PrefixTreeNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                return false;
            }
            node = node->children[curr];
        }
        
        return node->isWord;
    }
    
    bool startsWith(string prefix) { // only work with lowercase
        PrefixTreeNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < prefix.size(); i++) {
            curr = prefix[i] - 'a';
            if (node->children[curr] == NULL) {
                return false;
            }
            node = node->children[curr];
        }
        
        return true;
    }
    
private:
    PrefixTreeNode* root;
};


int main(void)
{
    vector<string> input = {"PrefixTree", "insert", "apple", "search", "apple", "search", "app", "startsWith", "app", "insert", "app", "search", "app"};
    PrefixTree prefixTree;
    prefixTree.insert("apple");
    prefixTree.insert("ape");
    prefixTree.insert("application");
    if (!prefixTree.search("apple"))
    {
        cout << "no 'apple' in the prefix tree" << endl;
    }
    else
    {
        cout << "'apple' do be in the prefix tree" << endl;
    }
    if (!prefixTree.search("app"))
    {
        cout << "No 'app' in the prefix tree" << endl;
    }
    else
    {
        cout << "Get 'app'" << endl;
    }
    if (!prefixTree.startsWith("app"))
    {
        cout << "No prefix 'app" << endl;
    }
    else
    {
        cout << "Get prefix 'app" << endl;
    }
    prefixTree.insert("app");
    if (!prefixTree.search("app"))
    {
        cout << "No 'app' in the prefix tree" << endl;
    }
    else
    {
        cout << "'Get 'app'" << endl;
    }

    cout << 'c' - 'a' << endl;
    cout << 'C' - 'a' << endl;
    cout << 'c' - 'A' << endl;

    int int_list[26];
    return 0;
}