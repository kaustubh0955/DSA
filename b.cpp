#include"bits/stdc++.h"
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
    void insert(int data)
    {
        if (data <= this->data)
        {
            if (left == NULL)
            {
                left = new BinaryTreeNode(data);
            }
            else
            {
                left->insert(data);
            }
        }
        else
        {
            if (right == NULL)
            {
                right = new BinaryTreeNode(data);
            }
            else
            {
                right->insert(data);
            }
        }
    }
    void deleteNode(int data)
    {
        if (data < this->data)
        {
            if (left != NULL)
            {
                left->deleteNode(data);
            }
        }
        else if (data > this->data)
        {
            if (right != NULL)
            {
                right->deleteNode(data);
            }
        }
        else
        {
            if (left != NULL && right != NULL)
            {
                this->data = right->data;
                right->deleteNode(this->data);
            }
            else if (left != NULL)
            {
                BinaryTreeNode
                    *temp = left;
                this->data = left->data;
                left = left->left;
                right = left->right;
                temp->left = NULL;
                temp->right = NULL;
                delete temp;
            }
            else if (right != NULL)
            {
                BinaryTreeNode
                    *temp = right;
                this->data = right->data;
                left = right->left;
                right = right->right;
                temp->left = NULL;
                temp->right = NULL;
                delete temp;
            }
            else
            {
                delete this;
            }
        }
    }
    void search(int data)
    {
        if (data < this->data)
        {
            if (left != NULL)
            {
                left->search(data);
            }
        }
        else if (data > this->data)
        {
            if (right != NULL)
            {
                right->search(data);
            }
        }
        else
        {
            cout << "Found" << endl;
        }
    }
    void minimum()
    {
        if (left == NULL)
        {
            cout << "Minimum: " << data << endl;
        }
        else
        {
            DA - 3 21BDS0026 left->minimum();
        }
    }
    void maximum()
    {
        if (right == NULL)
        {
            cout << "Maximum: " << data << endl;
        }
        else
        {
            right->maximum();
        }
    }
    void inOrder()
    {
        if (left != NULL)
        {
            left->inOrder();
        }
        cout << data << " ";
        if (right != NULL)
        {
            right->inOrder();
        }
    }
    void preOrder()
    {
        cout << data << " ";
        if (left != NULL)
        {
            left->preOrder();
        }
        if (right != NULL)
        {
            right->preOrder();
        }
    }
    void postOrder()
    {
        if (left != NULL)
        {
            left->postOrder();
        }
        if (right != NULL)
        {
            right->postOrder();
        }
        cout << data << " ";
    }
};
int main()
{
    BinaryTreeNode *root = new BinaryTreeNode(10);
    root->insert(5);
    root->insert(15);
    root->insert(3);
    root->insert(7);
    root->insert(12);
    root->insert(18);
    root->insert(1);
    root->insert(4);
    root->insert(6);
    root->insert(8);
    root->insert(11);
    root->insert(13);
    root->insert(16);
    root->insert(19);
    root->insert(2);
    root->insert(9);
    root->insert(14);
    root->insert(17);
    root->insert(20);
    root->inOrder();
    cout << endl;
    root->preOrder();
    cout << endl;
    root->postOrder();
    cout << endl;
    root->minimum();
    root->maximum();
    root->search(10);
    root->search(5);
    root->search(15);
    root->search(3);
    root->search(7);
    root->search(12);
    root->search(18);
    root->search(1);
    root->search(4);
    root->search(6);
    root->search(8);
    root->search(11);
    root->search(13);
    root->search(16);
    root->search(19);
    root->search(2);
    root->search(9)