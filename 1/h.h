#define N 3
#include <stdio.h>
#include<stdlib.h>
#include <time.h>



using namespace std;

class My//����������� �����
{int Re,Im;
public:
    My();
     My (int r, int i) // ����������� �� ���������
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
    //M=new My*[n][n];//������ ��������� ������ �����������

    public:
    Matrix();//����������� ��� ����������
    ~Matrix();
    Matrix operator+(Matrix&);
    Matrix operator-(Matrix&);
    void prM();
};

