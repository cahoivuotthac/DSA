#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, *right;
};
void Init(Node * root) 
{
    root = NULL;
}
Node* CreateNode(int data)
{
    Node *p = new Node;
    if(p == NULL) return NULL;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void PreOrder_Recursion(Node* root) 
{
    if(root == NULL) return;
    cout << root->data << " ";
    PreOrder_Recursion(root->left);
    PreOrder_Recursion(root->right);
}
void LevelOrder(Node *root)
{
    if(root == NULL) return;
    stack<Node *> s;
    s.push(root);
    while(!s.empty()) 
    {
        Node *cur = s.top();
        cout << cur->data << " ";
        s.pop();

        if(cur->right != NULL) s.push(cur->right);
        if(cur->left != NULL) s.push(cur->left);
    }
}
void InOrder_Recursion(Node *root)
{
    if (root != NULL)
    {
        PreOrder_Recursion(root->left);
        cout << root->data << " ";
        PreOrder_Recursion(root->right);
    }
}
void PostOrder_Recursion(Node *root)
{
    if (root != NULL)
    {
        PreOrder_Recursion(root->left);
        PreOrder_Recursion(root->right);
        cout << root->data << " ";
    }
}
void CountNodes(Node *root, int &dem)
{
    if (root != NULL) 
    {
        dem++;
        CountNodes(root->left, dem);
        CountNodes(root->right, dem);
    }
}
void CountNodesHaveChilds(Node *root, int &dem)
{
    if (root != NULL)
    {
        if (root->left != NULL || root->right != NULL)
            dem++;
        CountNodes(root->left, dem);
        CountNodes(root->right, dem);
    }
}
void CountNodesHaveOnly1Child(Node *root, int &dem)
{
    if (root != NULL) 
    {
        if (root->left != NULL && root->right == NULL || root->right != NULL && root->right == NULL)
            dem++;
        CountNodes(root->left, dem);
        CountNodes(root->right, dem);
    }
}
void CountNodesHave2Childs(Node *root, int &dem)
{
    if (root != NULL) 
    {
        if (root->left != NULL && root->right != NULL) dem++;
        CountNodes(root->left, dem);
        CountNodes(root->right, dem);
    }
}
void CountLeafNodes(Node *root, int &dem)
{
    if (root != NULL) 
    {
        if (root->left == NULL && root->right == NULL) dem++;
        CountNodes(root->left, dem);
        CountNodes(root->right, dem);
    }
}
int NodeLevel(Node *root)
{
    int level = 0;
    if (root->left != NULL) level++;
    if (root->right != NULL) level++;
    return level;
}
void TreeLeVel(Node *root, int &maxlevel)
{
    if(root != NULL)
    {
        int level = NodeLevel(root);
        if(level > maxlevel)
        {
            maxlevel = level;
            if(maxlevel == 2) return;
        }
        TreeLeVel(root->left, maxlevel);
        TreeLeVel(root->right, maxlevel);
    }
}
void HeightOfTree(Node* root, int &maxheight, int height)
{
    if(root != NULL)
    {
        if(height > maxheight) maxheight = height;
        height++;
        HeightOfTree(root->left, maxheight, height);
        HeightOfTree(root->right, maxheight, height);
    }
}
// Find First Node has data X. If exists return its level in Tree
void FindNodeHasDataX(Node* root, int data, int level, int &count)
{
    bool check = false;
    if(root != NULL && check == false)
    {
        if(root->data == data)
        {
            check = true;
            count = level;
            return;
        }
        level++;
        FindNodeHasDataX(root->left, data, level, count);
        FindNodeHasDataX(root->right, data, level, count);
    }
}
