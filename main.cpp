/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  Node *prev;
Node (int data)
  {
    this->data = data;
    next = NULL;
    prev = NULL;
  }
};
Node *takeinput ()
{
  int data;
  cin >> data;
  Node *head = NULL;
  Node *tail = NULL;
  while (data != -1)
    {
      Node *newNode = new Node (data);
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
      cin >> data;
    }
  return head;
}

void print (Node * head)
{
  Node *temp = head;
  while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
}

Node *insert (Node * head, int pos, int data)
{
  Node *newNode = new Node (data);
  Node *temp = head;
  int count = 0;
  if (pos == 0)
    {
      //Node* newNode=new Node(data);
      newNode->next = head;
      head = newNode;
    }
  while (temp != NULL && count < (pos - 1))
    {
      temp = temp->next;
      count++;
    }
  if (temp != NULL)
    {
      //Node* newNode=new Node(data);
      Node *a = temp->next;
      temp->next = newNode;
      newNode->next = a;
    }
  return head;
}

int main ()
{
  Node *head = takeinput ();
  print (head);
  cout << endl;
  int pos,data;
  cin>>pos>>data;
  Node *newi = insert (head, 5, 9);
  print (newi);
  return 0;
}
