/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    int find(Node* root){
        Node* temp=root->right;
        while(temp->left){
            temp=temp->left;
        }
        return temp->data;
    }
  
    int inOrderSuccessor(Node *root, Node *k) {
        if(k->right==nullptr){
            Node* curr=root;
            Node* parent=nullptr;
            while(curr->data!=k->data  && curr!=nullptr){
                if(k->data<curr->data){
                    parent=curr;
                    curr=curr->left;
                }
                else{
                    curr=curr->right;
                }
            }
            if(!curr)   return -1;
            return parent?parent->data:-1;
        }
        return find(k);
    }
};
