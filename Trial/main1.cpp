#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
  string regno;
  string name;
  double cgpa;

  Node *next;

  Node(double cgpa, string name, string regno)
  {
    this->cgpa = cgpa;
    this->name = name;
    this->regno = regno;
    next = NULL;
  }
};
Node *takeInput()
{
  string regno;
  string name;
  double cgpa;

  cout << "Enter the regno no.";
  cin >> regno;

  cout << "Enter the name";
  cin >> name;

  cout << "Enter the cgpa";
  cin >> cgpa;

  Node *head = NULL;
  Node *tail = NULL;

  while (regno != "end")
  {
    Node *newNode = new Node(cgpa, name, regno);
    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = tail->next;
    }
    cout << "Enter the regno no.";
    cin >> regno;

    if (regno != "end")
    {
      cout << "Enter the name";
      cin >> name;

      cout << "Enter the cgpa";
      cin >> cgpa;
    }
  }
  return head;
}
int print(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->regno << " ";
    cout << temp->name << " ";
    cout << temp->cgpa << " " << endl;
    temp = temp->next;
  }

  return 0;
};
Node *deleteNode(Node *head, double cgpa)
{
  if (head == NULL)
    return head;

  Node *temp = head;
  int count = 0;

  if (temp->cgpa >= cgpa)
  {
    head = head->next;
    return head;
  }

  if (temp == NULL)
  {
    return head;
  }
  if (temp->next != NULL && temp->cgpa < cgpa)
  {

    Node *a = temp->next;
    Node *b = a->next;

    temp->next = b;
    delete a;
  }
  return head;
}
int main()
{
  Node *head = takeInput();
  print(head);

  int cgpaExp = 0;

  deleteNode(head, cgpaExp);
  print(head);
}