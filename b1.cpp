//Kaustubh Rai 21BCE0050
#include "bits/stdc++.h"
using namespace std;
class ExpressionTreeFromInfix {
public:
 struct Node {
 char data;
 Node *left, *right;
 };
 Node *newNode(char data) {
 Node *temp = new Node;
 temp->data = data;
 temp->left = temp->right = nullptr;
 return temp;
 }
 bool isOperator(char c) {
 return (!isalpha(c) && !isdigit(c));
 }
 Node *constructTree(string postfix) {
 stack<Node *> st;
 Node *t, *t1, *t2;
 for (int i = 0; i < postfix.length(); i++) {
 if (!isOperator(postfix[i])) {
 t = newNode(postfix[i]);
 st.push(t);
 } else {
 t = newNode(postfix[i]);
 t1 = st.top();
 st.pop();
 t2 = st.top();
 st.pop();
 t->right = t1;
 t->left = t2;
 st.push(t);
 }
 }

 t = st.top();
 st.pop();
 return t;
 }
 void inorder(Node *t) {
 if (t) {
 inorder(t->left);
 cout << t->data << " ";
 inorder(t->right);
 }
 }
};
int main() {
 string exp = "cd+gd*+";
 ExpressionTreeFromInfix et;
 ExpressionTreeFromInfix::Node *root = et.constructTree(exp);
 cout << "Infix Expression: ";
 et.inorder(root);
 return 0;
}
