#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/**
 * deklaracie funkcii
 */

double Random(int max);
int float2Q(double RealCislo, int n);
double Q2float(int Q, int n);

int main() {
    int m, n, max, Q;
    double f, f1, difference, sum = 0, average, MaxAverage;

    scanf("%d %d", &m, &n); // nacitanie m, n z klavesnice

    max = (int) pow(2, m) - (int) pow(2, -n); //max hodnota, po ktoru mozno generovat

    if (m + n != 16)
    {
        printf("ERROR!");  //pokial m+n nie je 16, tak chyba
        return 1;
    }

    else
    {
        srand(time(NULL));  // podla coho ma generator generovat cisla

        for (int i = 0; i < 1000; ++i) {
            f = Random(max);
            Q = float2Q(f, n);
            f1 = Q2float(Q, n);

            if (f - f1 < 0)
                difference = - (f - f1);
            else
                difference = f - f1;

            sum = sum + difference;
        }

        MaxAverage = pow(2, -n);    //vypocitane 2^-n
        average = sum / 1000;

        if (average <= MaxAverage) {
            printf("%f", average);
        }
        else {
            printf("ERROR!");
        }
    }

    return 0;
}

double Random(int max)
{
    return (rand() % (max + 1));    //generuje od 0 po max (negarantujem presnost)
}

int float2Q(double RealCislo, int n) {

    double x = RealCislo * pow(2, n);
    return round (x);   //zaokruhlovanie na int
}

double Q2float(int Q, int n) {
    return Q / pow(2, n);
}
