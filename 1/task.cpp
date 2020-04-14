#include "h.h"
#include <time.h>
My::My(){
  Re=rand()%50;
  Im=rand()%50;
}
My My::operator +(My &p)
{
My sum;
sum.Re=Re+p.Re;
sum.Im=Im+p.Im;
return sum;
}

My My::operator -(My &p)
{
My r;
r.Re=Re-p.Re;
r.Im=Im-p.Im;
return r;
}
void My::prCC()
{
    printf("%d",Re);
    printf("+i");
    printf("%d",Im);
    printf("  ");
   // cout << Re << "+i*" << Im <<"   "<< endl;
}

void Matrix::prM()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            (M[i][j]).prCC();
            printf("  ");
        }
        printf("\n");
    }
}
Matrix::Matrix(){}

Matrix::~Matrix(){}

Matrix Matrix::operator -(Matrix &p)
{
Matrix r;
for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
{
r.M[i][j]=(M[i][j])-(p.M[i][j]);// ругается на тип операторов
}
return r;
}


Matrix Matrix::operator +(Matrix &p)
{
Matrix r;
for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
{
r.M[i][j]=(M[i][j])+(p.M[i][j]);// ругается на тип операторов
}
return r;
}
