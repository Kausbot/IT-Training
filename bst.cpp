#include<iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *left , *right;

  Node()
  {
    left = NULL;
    right = NULL;
  }
};

class bst
{
public:
  Node *root = NULL;

  Node* insert(int x, Node *n )
  {
    if(n == NULL)
    {

      Node *temp = new Node;
      temp->data = x;
      cout<<"inserted "<<x<<endl<<endl;
      return temp;
    }

    else
    {
      if(x < n->data)
      {
        cout<<"going left from "<< n->data<<endl;
        n->left =  insert(x , n->left);
      }
      else{

        cout<<"going right from "<< n->data<<endl;
        n->right =  insert(x, n->right);
      }
    }
  }

  void preorder(Node *n)
  {
    if(n == NULL) return;
    cout<<n->data<<" ";
    preorder(n->left);
    preorder(n->right);
  }

  void inorder(Node *n)
  {
    if(n == NULL) return;
    inorder(n->left);
    cout<<n->data<<" ";
    inorder(n->right);

  }

  void postorder(Node *n)
  {
    if (n == NULL) return ;
    postorder(n->left);
    postorder(n->right);
    cout<<n->data<<" ";
  }


};


int main()
{

  bst T;
T.root =   T.insert(6,T.root);
T.root =   T.insert(5,T.root);
T.root =   T.insert(9,T.root);
T.root =   T.insert(3,T.root);
T.root =   T.insert(1,T.root);
T.root =   T.insert(4,T.root);
T.root =   T.insert(10,T.root);

T.inorder(T.root);
cout<<endl;
T.preorder(T.root);
cout<<endl;
//T.postorder(T.root);


  return 0;
}
