#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data =data;
        next=NULL;
    }
};

int main()
{
    Node s1(10);
    Node *head=&s1;

    Node s2(20);
    s1.next =&s2;

    Node s3(30);
    s2.next =&s3;
}