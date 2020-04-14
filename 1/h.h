#define N 3
#include <stdio.h>
#include<stdlib.h>
#include <time.h>



using namespace std;

class My//комплексные числа
{int Re,Im;
public:
    My();
     My (int r, int i) // конструктор по умолчанию
   {
      Re = r;
      Im = i;
   }


    My operator+(My &);
    My operator-(My &);

    void prCC();
    ~My(){};
};


class Matrix
{
    My M[N][N];
    //M=new My*[n][n];//создаю двумерный массив комплексных

    public:
    Matrix();//конструктор без аргументов
    ~Matrix();
    Matrix operator+(Matrix&);
    Matrix operator-(Matrix&);
    void prM();
};

