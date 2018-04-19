
//
//       Filename:  main.c
//
//    Description:
//        Created: 13/03/2014 |11:07:29
//
//         Author: Marlon Ramos on 13/03/2014 11:07:29
//         E-mail: marlon.ramos@fis.puc-rio.br
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[])
{
    int number_lines, number_column;
    char str_sple[1024];

    int i, j, k, NA;

    double **col, **col2;

    FILE *inpf;
    FILE *outf;


    double x;

    if(!(argc==6)){
        printf("ERROR: invalid argument Usage:\n");

        printf("use: %s [sample files] [average file] [number of samples] [number of columns] [number of lines]\n", argv[0]);

        return 0;
    }

    NA=atoi(argv[3]);
    number_column=atoi(argv[4]);
    number_lines=atoi(argv[5]);


    col = (double **)realloc(NULL, number_column * sizeof(double *));
    for(i=0;i<number_column;i++){
        col[i]=(double *)calloc(number_lines, sizeof(double));
    }


    col2 = (double **)realloc(NULL, number_column * sizeof(double *));
    for(i=0;i<number_column;i++){
        col2[i]=(double *)calloc(number_lines, sizeof(double));
    }



    for (i=0; i<NA; i++) {

        sprintf(str_sple, "%s%d.dat", argv[1], i+1);
        printf("%s\n", str_sple);
        inpf=fopen(str_sple, "r");

        for (j=0; j<number_lines; j++) {
            for (k=0; k<number_column; k++) {
                fscanf(inpf, "%lf", &x);
                col[k][j]+=x;
                col2[k][j]+=x*x;
            }
        }

        fclose(inpf);

    }




    outf=fopen(argv[2], "w");
    double m, m2;

    for (j=0; j<number_lines; j++) {
        for (k=0; k<number_column; k++) {
            m=(double)col[k][j]/NA;
            m2=(double)(col2[k][j]-NA*m*m)/(NA-1);

            m2=sqrt(m2);
            //printf("%.10lf %.10lf ", m, m2);
            fprintf(outf, "%.10lf %.10lf ", m, m2);
        }
        fprintf(outf, "\n");
        //printf("\n");
    }

    fclose(outf);


    return 0;
}
