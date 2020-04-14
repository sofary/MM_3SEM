#include "h.h"
int main()
{
    srand (time(0));
    Matrix G, P, Msum, Mraz;
    Msum=G-G+P-G-P+G;
    Mraz=G-P;
   // printf("1_matr\n");
   // G.prM();
   // printf("2_matr\n");
    //P.prM();
    printf("sum\n");
    Msum.prM();
    //printf("razn\n");
   // Mraz.prM();

    return 0;
}
