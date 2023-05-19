#include <stdio.h>
#include <simpio.h>
#include <strlib.h>
#include <string.h>


#define MaxLine 100

int main(){

    FILE *fp;
    char buffer[MaxLine];
    int ch;
    char n;
    int Minmax;
    int len;
    int i,N,j;
    char c[MaxLine];
    int syntel;
    char helper[MaxLine];








            //open file

            fp = fopen("grammiko2.txt","r");
            if(fp==NULL)
            {
                printf("Error at the open");
                exit(0);
            }


            //Minmax

            else
            {
                while ((ch = getc(fp)) != 'z')
                    {
                        if(ch == 'n')
                        {
                            Minmax = -1;
                        }
                        else if(ch =='x')
                        {
                            Minmax = 1;
                        }

                    }
            }

            if(Minmax!=1 && Minmax!=-1)
            {
                exit(0); //elegxos minmax
            }



            int k;
            k=0;

            //Pinakas C
            printf("C:");
            while ((ch = getc(fp)) != '\n')
                        {


                            helper[i] = ch;


                            if(ch == 'x')
                            {

                                c[k] = helper[i-1];
                                if(Minmax == 1)
                                {
                                    printf("-%c ",c[k]);
                                    k++;
                                }
                                else
                                {
                                    printf("%c ",c[k]); //Print C
                                k++;
                                }




                            }
                            i++;

                        }
                        ch = helper[i-1]; //briskw thn timh toy M

            printf("\n");


            // checking st
            if (fgets(buffer, MaxLine, fp)!=NULL)
                {
                    len = strlen(buffer);
                    if(len != 3)
                    {
                        exit(0);
                    }

                }



                //briksw to plhthos ton texnologikwn periorismwn

                N=0;
                while (fgets(buffer, MaxLine, fp)!=NULL)
                        {
                            for(i=0;i<1;i++)
                            {
                                if(buffer[i] = '\n')
                                {
                                    N++;
                                }
                            }

                        }
                N--;








        //dilwsi pinakwn
        char A[MaxLine][N];
        char B[N];
        int Eqin[N];


        //syntelestes A B
        //epanaferw ton buffer ekei poy thelw sto arxeio
        fseek(fp,0,SEEK_SET);
        i=0;
        while(i<2)
        {
            if (fgets(buffer, MaxLine, fp)!='\n')

                i++;
        }






        i=0;
        printf("A:");

            for(j=0;j<N;j++)
            {

                 k=0;
                while ((ch = getc(fp)) != '\n')
                {


                    buffer[i] = ch;

                    if(ch == 'x')
                    {

                        A[k][j] = buffer[i-1];

                        printf("%c ",A[k][j]); //Print A
                        k++;

                    }

                    if(ch =='<')
                    {
                        Eqin[j] = -1;
                    }

                    else if(ch == '>')
                    {
                        Eqin[j] = 1;
                    }

                    if(buffer[i-1] == '=')
                    {
                        B[j] = buffer[i];

                    }

                    i++;




                }



                if(Eqin[j]!=-1 && Eqin[j]!=1)
                {
                    Eqin[j] = 0;

                }



            }
            int replays_k;
            replays_k = k;//apothikeyw to k



            printf("\n");
            printf("B:");

            for(j=0;j<N;j++)
            {
                printf("%c ",B[j]); //Print B
            }

            printf("\n");
            printf("Eqin:");

            for(j=0;j<N;j++)
            {
                printf("%d ",Eqin[j]); //Print Eqin
            }



            printf("\n");
            printf("Minmax is %d",Minmax);





             FILE*wp;
            char teliko[]="teliko.txt";


            wp = fopen(teliko,"w");
            fprintf(wp,"Min ");
            for(j=0;j<N-1;j++)
            {
                fprintf(wp,"%cw%d+",B[j],j+1);

            }
            N++;
            fprintf(wp,"%cw%d \n",B[j],j+1);
            fprintf(wp,"st\n");



            int num;



          for(i=0;i<replays_k;i++)
          {
              num = 1;
              for(j=0;j<N-2;j++)
              {
                  fprintf(wp,"%cw%d+",A[i][j],num);
                  num++;
              }
              fprintf(wp,"%cw%d",A[i][j],num);


              if(Minmax == 1)
              {
                fprintf(wp,">=");
              }
              else if(Minmax == -1)
              {
                  fprintf(wp,"<=");
              }

              if(Minmax == 1)
              {
                  fprintf(wp,"-%c ",c[i]);
              }
              else
              {
                  fprintf(wp,"%c",c[i]);
              }



              fprintf(wp,"\n");
          }








    fclose(fp);




    return 0;
    }

