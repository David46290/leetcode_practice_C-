# include <vector>
# include <iostream>
# include <unordered_map>

using namespace std;


 struct ListNode
 {
      int val;
      ListNode *next;
      // 3 constructors
      ListNode() : val(0), next(nullptr) {} // assign 0 to val; null to next
      ListNode(int x) : val(x), next(nullptr) {} // assign x to val; null to next
      ListNode(int x, ListNode *next) : val(x), next(next) {} // assign x to val; next(of the argument) to next
      
 };

class linked_list
{
    public:
    ListNode *head;
    // default constructor
    linked_list() {head = NULL;}

    void insert_at_head(int value)
    {
        // h: head node, n: node, v: nums, v_size: numsSize
        // (nums) v[0], v[1], v[2], v[3], v[v_size]
        // (init)                            h
        // (1st)                      h  <-  n
        // (2nd)               h <-   n  <-  n
        // (3rd)         h <-  n <-   n  <-  n
        // ... ...
        ListNode *new_node = new ListNode(value); // creating space for new ListNode sturcture, and the pointer "new_node" can point to it
        if (head == NULL) // if the list is empty
        {
            head = new_node;
            return;
        }
        
        new_node->next = this->head;
        this->head = new_node;
    }
    
};

class Solution1 // three pointers
{
public:
    ListNode* reverseList(ListNode* head)
    {
        // turn the head to last node (pointing null pointer)
        // turn the last node to head (not pointing null anymore)
        ListNode* previous_node = NULL; // to makie the new link, cause we want current node point to the previous node
        ListNode* current_node = head;  // check whether hit the null ptr, which is the end of the original linked list
        ListNode* next_node; // to save the original link
        while (current_node != NULL)
        {
            
            next_node = current_node->next; // save the original link first
            current_node->next = previous_node; // make a reversed link
            cout << "done with node " << current_node->val << ", ";
            //move on to next node in the original linked list
            previous_node = current_node;
            current_node = next_node; 
            //cout << "moving to next node " << current_node->val << endl;
        } 

        return previous_node;
    }
};



int main(void)
{
    Solution1 func;
    linked_list list;
    vector<int> nums = {0, 1, 2, 3};
    ListNode *ans;
    for (int i=nums.size()-1; i>=0; i--)
    {
        list.insert_at_head(nums[i]);
    }
    ListNode *test_node1 = new ListNode(19);
    ListNode *test_node2 = new ListNode(20);
    ListNode *test_node3 = new ListNode(21);
    test_node1->next = test_node2;
    test_node2->next = test_node3;
    //list.head -> next = test_node1;
    //test_node1->next = list.head -> next;
    ans = func.reverseList(list.head);
    return 0;
}
