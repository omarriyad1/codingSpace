

#include <iostream>
template <class T>
class node
{
public:
    T data;
    node* left;
    node* right;
    node* root = new node;
node()
{
    //node* root = new node;
}
node(T el, node* kk = 0, node* th = 0)
{

   /* if (root->data == NULL)
    {
        root->data = el;
        root->right = th;
        root->left = kk;
    }
    else*/
        data = el;
        left = kk;
        right = th;
}

node* getleft()
{
    return left;
}
node* getright()
{
    return right;
}
T getdata()
{
    return data;
}
node* insert(node* currentnode, T da)
{
    if (currentnode->data == NULL)
    {
        return new node(da);
    }
    else if (currentnode->data > da)
    {
        currentnode->left = insert(currentnode->left, da);
    }
    else
    {
        currentnode->right = insert(currentnode->right, da);
    }
    return currentnode;
}
void inorder(node* currentnode)
{
    if (currentnode == NULL) return;
    inorder(currentnode->left);
    cout << currentnode->data<<endl;
    inorder(currentnode->right);
}
void preorder(node* currentnode)
{
    if (currentnode == NULL) return;
    cout << currentnode->data << endl;
    inorder(currentnode->left);
    inorder(currentnode->right);
}
void postorder(node* currentnode)
{
    if (currentnode == NULL) return;
    inorder(currentnode->left);
    inorder(currentnode->right);
    cout << currentnode->data << endl;
}





    

    int main()
    {
        std::cout << "Hello World!\n";
    }
