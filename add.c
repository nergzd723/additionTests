#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

extern int additionTHEBEST(int, int);
extern int additionADD(int, int);
extern int additionLEA(int, int);

int main(){
    int i, rand1, rand2;
    struct timeval st, et;  
    double time_spentBEST, time_spentADD, time_spentLEA;
    srand(time(NULL));
    gettimeofday(&st, NULL);
    for (i = 0; i < 1000; i++){
        rand1 = rand()%256;
        rand2 = rand()%256;
        additionTHEBEST(rand1, rand2);
    }
    gettimeofday(&et, NULL);
    time_spentBEST = ((et.tv_sec - st.tv_sec) * 1000000) + (et.tv_usec - st.tv_usec);
    gettimeofday(&st, NULL);
    for (i = 0; i < 1000; i++){
        rand1 = rand()%256;
        rand2 = rand()%256;
        additionADD(rand1, rand2);
    }
    gettimeofday(&et, NULL);
    time_spentADD = ((et.tv_sec - st.tv_sec) * 1000000) + (et.tv_usec - st.tv_usec);
    gettimeofday(&st, NULL);
    for (i = 0; i < 1000; i++){
        rand1 = rand()%256;
        rand2 = rand()%256;
        additionLEA(rand1, rand2);
    }
    gettimeofday(&et, NULL);
    time_spentLEA = ((et.tv_sec - st.tv_sec) * 1000000) + (et.tv_usec - st.tv_usec);
    printf("THE BEST %f microsec, ADD %f microsec, LEA %f microsec\n", time_spentBEST, time_spentLEA, time_spentADD);
    return 0;
}