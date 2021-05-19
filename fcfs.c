#include<stdio.h>
void main() {
    FILE *fp;
    int a[20], b[20], p[20], prio[20], i, j, n=0, np=0, t=0, tt=0, wt=0, ex[20];
    float awt, att;

    fp = fopen("fcfsinput.txt", "r");

    while(!feof(fp)) {
        fscanf(fp, "%d\t%d\t%d\t%d", &p[np], &a[np], &b[np], &prio[np]);
        np++;
    }

    for(i=0; i<np-1; i++) {
        for(j=i+1; j<np; j++) {
            int t1, t2, t3, t4;
            if(a[i]>a[j]) {
                t1 = a[i];
                t2 = b[i];
                t3 = p[i];
                t4 = prio[i];

                a[i] = a[j];
                b[i] = b[j];
                p[i] = p[j];
                prio[i] = prio[j];

                a[j] = t1;
                b[j] = t2;
                p[j] = t3;
                prio[j] = t4;
            }
        }
    }

    printf("\nPROCESS\tEXECUTION TIME");

    if(a[0]!=0) {
        printf("[x]\t0");
    }
    ex[0] = a[0];
    printf("\n%d\t%d", p[0], a[0]);

    for(i=1; i<np; i++) {
        if(a[i]>(ex[i-1]+b[i-1])) {
            printf("\n%d\t%d", p[i], a[i]);
            ex[i] = a[i];
        }
        else {
            ex[i] = ex[i-1]+b[i-1];
            printf("\n%d\t%d", p[i], ex[i]);
        }
    }

    for(i=0; i<np; i++) {
        wt = wt+(ex[i]-a[i]);
        tt = tt+(ex[i]-a[i])+b[i];
    }

    awt = (float)wt/(float)np;
    att = (float)tt/(float)np;

    printf("\n\nAverage waiting time : %f\nAverage turn around time : %f\n\n", awt, att);

    fclose(fp);
}