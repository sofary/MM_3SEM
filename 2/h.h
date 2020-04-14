#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <iostream>
#include <string.h>
#define MX(a, b) (a > b ? a : b)
#define MN(a, b) (a > b ? b : a)

using namespace std;
class Matrix;

class My
{int Re,Im;
public:
    My();
     My (int r, int i) // конструктор по умолчанию
   {
      Re = r;
      Im = i;
   }

    My operator+(const My &);
    My operator-(const My &);


    friend bool operator == (const My&,const My&);


    void prCC();
    ~My(){};
};


class Matrix
{
    private:
        My **Matr;
        int n;

        void Create()//void
        {
            Matr = new My*[n];
            for (int z=0; z<n; z++)
                Matr[z] = new My[n];
        }//zasunut' v konstr kopir

    public:
        Matrix(): n(5) { Create(); }
        Matrix(int i):  n(i) { Create(); }
        ~Matrix();

Matrix(Matrix &&);//konstructor peremesh'eniya
Matrix (const Matrix&);//konstr kopirovaniya
Matrix& operator =(Matrix &&a); //prisv pereme
Matrix& operator=(const Matrix &tmp);//prisv copy
    void Display();
    Matrix operator+(const Matrix &);
    Matrix operator-(const Matrix &);

};
