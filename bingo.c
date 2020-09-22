#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

FILE* abrirArquivoEscrita(char *Nome)
{
    FILE *fArq;
    fArq = fopen(Nome, "w");
    if ( fArq == NULL)
    {
        printf("Nao foi possível abrir o arquivo %s !",
               Nome);
        return(NULL);
    }
    return (fArq);
}


int main()
{
    int k,cartelas,i;
    FILE *fp;
    char *NomeArquivo=("Cartela_00%d.txt", k);
    int B[5], I[5], N[5], G[5], O[5];
    srand(time(NULL));


    printf("Quantas cartelas deseja gerar?\n");
    scanf("%d", &cartelas);

    if ( (fp=abrirArquivoEscrita(NomeArquivo) )== NULL)
    {
        return(1);
    }
    while (cartelas>0)
    {

        fprintf(fp,"  B   I   N   G   O\n\n");
        for (k=0; k<5; k++)
        {
            B[k]= (rand()% 15)+1;
            I[k]= (rand()% 15)+16;
            N[k]= (rand()% 15)+31;
            G[k]= (rand()% 15)+46;
            O[k]= (rand()% 15)+61;
            if(k!=2)
            {
                fprintf (fp,"%3d %3d %3d %3d %3d\n\n", B[k],I[k],N[k],G[k],O[k]);
            }
            else
            {
                fprintf (fp,"%3d %3d  *  %3d %3d\n\n", B[k],I[k],G[k],O[k]);
            }
        }
        fprintf(fp,"\n\n");
        cartelas= cartelas -1;
    }
    fclose(fp);
}





