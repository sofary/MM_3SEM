#include "h.h"

My::My(){
  Re=rand()%50;
  Im=rand()%50;
}
My My::operator +(const My &p)
{
My sum;
sum.Re=Re+p.Re;
sum.Im=Im+p.Im;
return sum;
}
 bool operator == (const My& a, const My& b)
    {
      if ((a.Re == b.Re) && (a.Im == b.Im))
      {
        return true;
      }
      else
      {
        return false;
      }
    }

My My::operator -(const My &p)
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
}

    Matrix Matrix::operator +(const Matrix &p)
    {
        int m=MN(n, p.n);
        Matrix r(m);
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
        
           (r.Matr[i][j])=(Matr[i][j])+(p.Matr[i][j]);
        
        return r;
    }

    Matrix Matrix::operator -(const Matrix &p)
    {
         int m=MN(n, p.n);
             Matrix r(m);
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
        
           r.Matr[i][j]=Matr[i][j]-p.Matr[i][j];
        
        return r;
    }

void Matrix::Display()
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    cout.width(4);
                    (Matr[i][j]).prCC();
                }
                cout << endl;
            }
        }

        Matrix::~Matrix()
        {
        for (int z=0; z<n; z++)
                delete[] Matr[z];
            delete[] Matr;
        }

Matrix::Matrix (const Matrix& v)//konstr kopirovaniya
{
        n=v.n;
            Matr = new My*[n];
            for (int z=0; z<n; z++)
                Matr[z] = new My[n];
            for(int i=0;i<v.n;i++)
for(int j=0;j<v.n;j++)
{
	Matr[i][j]=v.Matr[i][j];
}
        
}


Matrix::Matrix( Matrix &&v)//konstructor peremesh'eniya
{
   // cout<<"!!"<<endl;
n=v.n;
Matr=v.Matr;
v.Matr=nullptr;
v.n=0;
}



    Matrix& Matrix::operator=(const Matrix &tmp)//prisv copy
    {
    if (this == &tmp) return *this;
    n = tmp.n;
        for (int z=0; z<n; z++)
                delete[] Matr[z];
            delete[] Matr;
    Create();
    for(int i = 0; i < n; i++)
        for(int j=0;j<n;j++)
           (Matr[i][j])= (tmp.Matr[i][j]);
    return *this;
}



Matrix& Matrix::operator =(Matrix &&a) //prisv pereme
{
    My zer(0,0);
        if(this==&a) return *this;
        for (int z=0; z<n; z++)
                delete[] Matr[z];
            delete[] Matr;
    n=a.n;
    Matr=a.Matr;
    a.Matr=nullptr;
    a.n=0;

           return *this;
}












