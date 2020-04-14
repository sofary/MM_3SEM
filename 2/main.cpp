#include "h.h"

int main()
{
    srand (time(0));

    int k,t,mal;
    cin>>k;
    cin>>t;
    mal=MN(k, t);

    Matrix summ(11), razn(mal);
    Matrix g(k);
    Matrix v(t);

    cout<<"1_matrix"<<endl;
    g.Display();
    cout<<"2_matrix"<<endl;
    v.Display();

    cout<<"summa"<<endl;
    summ=g+v+g+v-g-g-v-v;
    summ.Display();
    cout<<"raznost'"<<endl;
   razn=g-v;
    razn.Display();
    return 0;
}
