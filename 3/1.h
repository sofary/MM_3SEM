#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

class Node
{public:
  char* field;
  int chi;
  Node *ptr;
  void print_() 
  {
    cout << "("<<this->field<<" , "<<this->chi<<")"<< " "<<endl;
  }
  
Node(char* data, int m)
   {
      field = data;
      chi = m;
   }
   Node()
   {
      field = NULL;
      chi = 0;
   }
~Node() 
{
delete [] field;
//cout<<"__nod__dest___"<<endl;
}
  friend class List;
  friend class Tokonizer;
};
class List
{
  Node *head;    
  int count = 0; 
  Node* Prev(Node *); 
public:

    
    
class iterator
{
List *l; Node* n;
public:
iterator(List* l, Node* n){this->l=l; this->n=n;}
friend class List;
char* operator*(){return n->field;}
int operator-(){return n->chi;}
void operator++(){n=n->ptr;}
int operator !=(const iterator&b){return n!=b.n;}
};
public:
  List() { head = NULL; }
  ~List(){Clear();/*cout<<"_dest__"<<endl;*/};
  int getCount() { return count; } 
  bool isEmpty() { return head == NULL; } 
  char* getValue(Node* p) { return p->field; }
  int getChi(Node* p) {return p->chi;}
  void setValue(Node *p, char* val) { p->field = val; p->chi=strlen(p->field);} 
  Node* getFirst() { return head; } 
  Node* getLast();      
  void Clear();        
  Node* Next(Node *);      
  Node* Add(char*, Node*);    
  int Delete(Node*);    
  void Print();        
  void Swap(Node*, Node*);  

  void PrintIT();
  iterator begin(){return iterator(this,this->getFirst());}
  iterator end(){return iterator(this,this->getLast());}
  friend class Node;
  friend class Tokonizer;
};
class Tokonizer
{
    List LL;
    int ts;
    public:
    Tokonizer(const char s[7] , char file_name[100]);
    ~Tokonizer();
    void pr_tok();
    void Info();
    void getTokN(int m);    
    friend class List;
    friend class Node;
};
