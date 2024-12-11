#include<iostream>

using namespace std;

struct Node {
    int data;
    int fact;
    Node * left;
    Node * right;
    Node * parent;
    Node(int data):data(data), fact(0),left(nullptr),right(nullptr),parent(nullptr)
    {

    }
};
class AVL
{
private:
    /* data */
    Node *root;
public:
     AVL(/* args */);
    ~ AVL();
    void insert(int key);
    void print(Node * root);
    void factor(Node * node);
    int height(Node * node);
    void right_rotation(Node *);
    void left_rotation (Node * );
    void checkbalance(Node * node , int key );
};

void AVL::right_rotation(Node * node)
{
    Node * temp = node->left;
    node->left=node->left->right;
    node->left->right->parent = node->left;
    temp->right = node;
    if(node==root) 
    {
        temp->parent =nullptr;
    }
    else 
    {
        if(node->parent->left=node) temp->parent=node->parent->left;
        else temp->parent=node->parent->right;
    }
    node->parent = temp;
}

void AVL::left_rotation(Node * node)
{
    Node * temp = node->right;
    node->right=node->right->left;
    node->right->left->parent = node->right;
    temp->left = node;
    if(node==root) 
    {
        temp->parent =nullptr;
    }
    else 
    {
        if(node->parent->left=node) temp->parent=node->parent->left;
        else temp->parent=node->parent->right;
    }
    node->parent = temp;
}

void AVL::checkbalance(Node * node, int key)
{
    factor(node);
    
    if(node->fact < -1 && node->right->data < key) 
    {
        cout<<"RR CASE"<<endl;
        left_rotation(node);
    } 
    else if(node->fact>1 && node->left->data > key)
    {
        cout<<"LL case"<<endl;
        right_rotation(node);
    }
    else if(node->fact < -1 && node->right->data > key)
    {
        cout<<"RL CASE"<<endl;
        right_rotation(node->left);
        left_rotation(node);
    }
    else if(node->fact>1 && node->left->data < key)
    {
        cout<<"LR CASE"<<endl;
        left_rotation(node->right);
        right_rotation(node);
    }
}
int AVL::height(Node * node)
{
    if(node==nullptr) return -1;
    return max(height(node->left),height(node->right))+1;
}
void AVL ::factor(Node * node)
{
    node->fact = height(node->left) - height(node->right);
}
void AVL::insert(int key)
{
    Node * temp = new Node(key);
    if(root==nullptr) root = temp;
    else 
    {
         Node * curr = root , * prev ;
        while(curr)
        {
            prev = curr;
            if(curr->data > key) curr=curr->left;
            else curr=curr->right;
        }
        temp->parent = prev;
        if(prev->data > key) 
        {
            prev->left = temp;
        }
        else prev->right = temp;
    }
    checkbalance(temp,key);
    print(root);
    cout<<endl;
}

void AVL::print(Node * root)
{
    if(root==nullptr) return ;
    cout<<root->data<<' ';
    //print (root->left);
    print(root->right);
    
}
AVL:: AVL(/* args */):root(nullptr)
{
}
 AVL::~ AVL()
{
    delete root;
}

int main ()
{
    AVL A1;
    A1.insert(30);
    A1.insert(31);
    A1.insert(34);
    A1.insert(35);
    A1.insert(54);
    A1.insert(39);
    return 0;
}