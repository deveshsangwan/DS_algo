#include <iostream>
#include <queue>
using namespace std;

class BinaryTreeNode{
  public:
int data;
  BinaryTreeNode* left;
  BinaryTreeNode* right;
  
  BinaryTreeNode(int data){
      this -> data = data;
      left = NULL;
      right = NULL;
  }
  
  ~BinaryTreeNode(){
      delete left;
      delete right;
  }
};

void printTree(BinaryTreeNode* root){
    if(root == NULL){
        return;
    }
    cout << root -> data << ":";
    if(root -> left != NULL){
        cout << "L" << root -> left -> data;
    }
    if(root -> right != NULL){
        cout << "R" << root -> right -> data;
    }
    cout << endl;
    printTree(root -> left);
    printTree(root -> left);
}

BinaryTreeNode* takeInputLevelwise(){
    int rootdata;
    cout << "enter root data" << endl;
    cin >> rootdata;
    BinaryTreeNode* root = new BinaryTreeNode(rootdata);
    queue<BinaryTreeNode*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode* front = pendingNodes.front();
        pendingNodes.pop();
        
        cout << "enter left child of" << front -> data << endl;
        int leftchildData;
        cin >> leftchildData;
        BinaryTreeNode* child = new BinaryTreeNode(leftchildData);
        front -> left = child;
        pendingNodes.push(child);
        
        cout << "enter right child of" << front -> data << endl;
        int rightchildData;
        cin >> rightchildData;
        child = new BinaryTreeNode(rightchildData);
        front -> right = child;
        pendingNodes.push(child);
    }
    return root;
}

BinaryTreeNode* takeInputBT(){
    int data;
    cout << "enter data" << endl;
    cin >> data;
    if(data == -1){
        return NULL;
    }
    BinaryTreeNode* root = new BinaryTreeNode(data);
    BinaryTreeNode* leftchild = takeInputBT();
    BinaryTreeNode* rightchild = takeInputBT();
    root -> left = leftchild;
    root -> right = rightchild;
    return root;
}

int main(){
    //BinaryTreeNode* root = takeInputBT();
    BinaryTreeNode* root = takeInputLevelwise();
    printTree(root);
    return 0;
}