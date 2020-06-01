#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <x86intrin.h>

extern int additionTHEBEST(int, int);
extern int additionADD(int, int);
extern int additionLEA(int, int);

int main(){
    int i, rand1, rand2;
    long long sum;
    unsigned long long a, b;
    unsigned long long c;
    __uint32_t AddArray[500];
    __uint32_t LeaArray[500];
    double avgADD, avgLEA;
    srand(time(NULL));
    for (i = 0; i < 50; i++){
        rand1 = rand()%256;
        rand2 = rand()%256;
        a = _rdtsc();
        additionADD(rand1, rand2);
        b = _rdtsc();
        c = b-a;
        AddArray[i] = (__uint32_t)c;
    }
    for (int loop = 0; loop < sizeof(AddArray); loop++){
        sum = sum + AddArray[loop];
    }
    avgADD = (int)sum / sizeof(AddArray);
    for (i = 0; i < 50; i++){
        rand1 = rand()%256;
        rand2 = rand()%256;
        a = _rdtsc();
        additionLEA(rand1, rand2);
        b = _rdtsc();
        c = b-a;
        LeaArray[i] = (__uint32_t)c;
    }
    sum = 0;
    for (int loop = 0; loop < sizeof(LeaArray); loop++){
        sum = sum + LeaArray[loop];
    }
    avgLEA = (float)sum / sizeof(LeaArray);
    printf("ADD %f microsec, LEA %f microsec\n", avgADD, avgLEA);
    printf("On your machine, ADD was faster by %f times\n", avgADD/avgLEA);
    return 0;
}