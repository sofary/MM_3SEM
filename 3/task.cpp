#include "1.h"
void List::PrintIT()
{iterator k=this->begin();
 iterator en=this->end();   
  if (isEmpty()) { cout << "List is empty" << endl; return; }
   do
   {
    cout << "("<< (*k) ;
    cout<<" , "<< (-k) <<")"<< " ";
    ++k;
  } while (k!=en);
  cout<<endl;

}

Node* List::Add(char* num, Node* node)//
{
  Node *elem = new Node();
  int cc=strlen(num);
  elem->field = new char[cc+1];
  for(int i=0;i<cc;i++)
      if(num[i]!='\0' && num[i]!='\n'){
  elem->field[i] = num[i];
      }
  elem->field[cc] = '\0';

  elem->chi=cc;
  count++;
  if (node == NULL)
  {
    if (head == NULL) {
      elem->ptr = NULL;
      head = elem;
    }
    else {
      elem->ptr = head;
      head = elem;
    }
    return head;
  }
  elem->ptr = node->ptr;
  node->ptr = elem;
  return head;
}



Node* List::Next(Node* node)
{
  if (isEmpty()) return NULL;
  return node->ptr;
}
Node* List::Prev(Node* node)
{
  if (isEmpty()) return NULL;
  if (node == head) return NULL;
  Node *p = head;
  while (p->ptr != node)
    p = p->ptr;
  return p;
}
Node* List::getLast()
{
  Node* p = head;
  while (p != NULL)
    p = Next(p);
  return p;
}

int List::Delete(Node* node)
{
  if (node == NULL) { return 0; }
  count--;
  if (node == head)
        {
    head = node->ptr;
   
    delete node;
    return 1;
  }
  Node* prev = Prev(node);
  prev->ptr = node->ptr;
  
  delete node;
  return 1;
}
void List::Clear()
{
 class Node *p = head;
  if (p == NULL) return;

  while (Delete(p)) {
   p=head;}
}

void List::Print()
{Node* p=head;
    Node *k;
    k=p;
  if (isEmpty()) { cout << "List is empty" << endl; return; }

  do {
    cout << "("<<getValue(k);
    cout<<" , "<<getChi(k)<<")"<< " ";
    k = Next(k);
  } while (k != NULL);
  cout << endl;
  p=k;
}




void List::Swap(Node* node1, Node* node2)
{
  if (node1 == NULL || node2 == NULL) return;
  if (node1 == node2) return;
  if (node2->ptr == node1)
  {
    Node *p = node1;
    node1 = node2;
    node2 = p;
  }
  Node *prev1 = Prev(node1);
  Node *prev2 = Prev(node2);
  Node *next1 = Next(node1);
  Node *next2 = Next(node2);
  if (next1 == node2)
  {
    if (prev1 != NULL)
      prev1->ptr = node2;
    else
      head = node2;
    node2->ptr = node1;
    node1->ptr = next2;
    return;
  }
  if (prev1 != NULL)
    prev1->ptr = node2;
  else
    head = node2;
  if (prev2 != NULL)
    prev2->ptr = node1;
  else
    head = node1;
  node2->ptr = next1;
  node1->ptr = next2;
}



char * get_line(FILE *fp, int *err)
{
  int i = 0;
  int c;
  char *t;
  char *s = new char[1];
  while ((c = fgetc (fp)) != '\n' && c != EOF)
    {
      s[i] = c;
      i++;
      t = new char [i+1];
      for (int j = 0; j < i; j++)
        t[j] = s[j];
      delete [] s;
      s = t;
    }
  s[i] = '\0';
  if (i == 0 && c == EOF)
    {
      delete [] s;
      *err = 0;
      return  NULL;
    }
  if (c == EOF)
    {
      *err =  1;
    }

  *err = 2;
  return s;
}

void Tokonizer::pr_tok()
{
cout<<"TOKKENS Print:"<<endl;
LL.Print();
cout<<"TOKKENS iterator:"<<endl;
LL.PrintIT();
}

  void Tokonizer::getTokN(int m)
  {
     if(m<ts){
      Node* B=LL.getFirst();
      for(int i=0;i<m;i++)
        {B=B->ptr;     
        }
      B->print_();}
  }


void Tokonizer::Info()
{
int m;
cout<<"Tokken in List: "<<ts<<endl;
  cout<<"Vvedi nomer tokkena ot 0 do "<<(ts-1)<<endl;
  cin>>m;
this->getTokN(m);
}


Tokonizer::~Tokonizer()
{
//cout<<"___tok_des___";
}

Tokonizer::Tokonizer(const char s[8], char file_name[100] )
{

  int dlin;
  int k=0;
  int err=0;
  char* ss;
  char* t;
  char* q;
  int flag;
  ts=0;
  //cout<<"Stroka: "<<s<<endl;
  FILE* fp;
  fp=fopen(file_name, "r");
  dlin=strlen(s);
  //cout<<"Dlina stroki "<<dlin<<endl;
  q=get_line(fp,&err);
 // cout<<"Razdeliteli: "<<q<<endl;
if(dlin>0)
{
if(strchr(q,s[0])==NULL) {flag=1;} else {flag=0;}
int i=0;
while(s[i]!='\0')
{
    if (flag==0 && i<dlin)
    {
        while(strchr(q,s[i])!=NULL && i<dlin)
            i++;

    }
     if(i<dlin && strchr(q,s[i])==NULL)
    {
   flag=1;
   ss=new char[dlin];
    while(strchr(q,s[i])==NULL)
    {
        ss[k]=s[i];
        ++k;
        ++i;
         }
         t=new char[k+1];
         for(int u=0;u<k;u++)
             t[u]=ss[u];
         delete [] ss;
         t[k]='\0';

    LL.Add(t,LL.getLast());
    delete [] t;
    k=0;
    flag=0;
    ++ts;
    }
    ++i;
}

}

delete[] q;
}



 
