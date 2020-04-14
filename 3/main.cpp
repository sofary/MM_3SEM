#include "1.h"
int main(void)
{


char s[7]={'f','a','2','2','a','g','\0'};

    const int SIZE = 100;
    int yes=1, i=0;
    while(yes==1)
    {   char q[SIZE];
    cout<<"Vvedite nazvaniye faila:"<<endl;
    cin>>q;
    Tokonizer K(s,q);
    K.pr_tok();
    K.Info();
    //K.LL.getLast();
    ++i;
    cout<<"Vvesti noviy fail? Da 1    Net 0  :"<<endl;
    cin>>yes;

    if(yes==0) break;

    }

    return 0;



 }
