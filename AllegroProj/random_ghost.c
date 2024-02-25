#include "head.h"
void RandomSymbol(int num,Monsterp monster,int seed)
{

    srand( time(NULL) );
    for (int i=0;i<num;i++)
    {
        monster->symbol[i] = (rand()*(i+seed))%4+1;
        printf("%d ",monster->symbol[i]);
    }
    printf("\n");
    monster->now_symbol = 0;
    monster->symboled = true;

}
