//Kaustubh Rai 21BCE0050
#include "bits/stdc++.h"
using namespace std;
class AVLTree
{
private:
    struct Node
    {
        int key;
        int height;
        Node *left;
        Node *right;
        Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
    };
    Node *root;
    int getHeight(Node *node)
    {
        return node == nullptr ? 0 : node->height;
    }
    int getBalance(Node *node)
    {
        return node == nullptr ? 0 : getHeight(node->left) - getHeight(node->right);
    }
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        DA - 3 21BDS0026 y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }
    Node *insert(Node *node, int key)
    {
        if (node == nullptr)
        {
            return new Node(key);
        }
        if (key < node->key)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key);
        }
        else
        {
            return node;
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);
        if (balance > 1 && key < node->left->key)
        {
            return rightRotate(node);
        }
        if (balance < -1 && key > node->right->key)
        {
            return leftRotate(node);
        }
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    Node *minValueNode(Node *node)
    {
        DA - 3 21BDS0026 Node *current = node;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }
    Node *deleteNode(Node *root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (key < root->key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if ((root->left == nullptr) || (root->right == nullptr))
            {
                Node *temp = root->left ? root->left : root->right;
                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                {
                    *root = *temp;
                }
                delete temp;
            }
            else
            {
                Node *temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }
        if (root == nullptr)
        {
            return root;
        }
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);
        if (balance > 1 && getBalance(root->left) >= 0)
        {
            return rightRotate(root);
        }
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0)
        {
            return leftRotate(root);
        }
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    void preOrder(Node *root)
    {
        if (root != nullptr)
        {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}
    void insert(int key)
    {
        root = insert(root, key);
    }
    void deleteNode(int key)
    {
        root = deleteNode(root, key);
    }
    void preOrder()
    {
        preOrder(root);
    }
};
int main()
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    cout << "Preorder traversal of the constructed AVL tree is \n";
    tree.preOrder();
    tree.deleteNode(10);
    cout << "\nPreorder traversal after deletion of 10 \n";
    tree.preOrder();
    return 0;
}