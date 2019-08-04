#include<stdio.h>
#include<math.h>
int main()
{
    float n1,n2,n3,n4,accuracy;
    char str2[100];
    int accurate=0;
    FILE *fp1 = fopen("test.txt","r");
    while((fscanf(fp1,"%f%f%f%f%s",&n1,&n2,&n3,&n4,str2))!=EOF)
    {
    FILE *fp = fopen("training.txt","r");
    float a[200][6],sl,sw,pl,pw,swap;
    char str[100];
    int i=0,j,k,k1=5,f1=0,f2=0,f3=0,size;
    while((fscanf(fp,"%f%f%f%f%s",&sl,&sw,&pl,&pw,str))!=EOF)
    {
        a[i][0]=sl;
        a[i][1]=sw;
        a[i][2]=pl;
        a[i][3]=pw;
        if(strcmp(str,"Iris-setosa")==0)
            a[i][4]=0;
        else if(strcmp(str,"Iris-versicolor")==0)
            a[i][4]=1;
        else
            a[i][4]=2;
        i++;
    }
    size=i;
    fclose(fp);
    for(i=0;i<size;i++)
    {
        a[i][5]=sqrt(pow((n1-a[i][0]),2)+pow((n2-a[i][1]),2)+pow((n3-a[i][2]),2)+pow((n4-a[i][3]),2));
    }
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-1-i;j++)
        {
            if(a[j][5]>a[j+1][5])
            {
                for(k=0;k<6;k++)
                {
                    swap=a[j][k];
                    a[j][k]=a[j+1][k];
                    a[j+1][k]=swap;
                }
            }
        }
    }
    for(i=0;i<k1;i++)
    {
       // printf("%.2f",a[i][4]);
        if(a[i][4]==0.0)
            f1++;
        else if(a[i][4]==1.0)
            f2++;
        else
            f3++;
    }
    if(f1>f2&&f1>f3)
    {
        printf("Iris-setosa\n");
        if(strcmp(str2,"Iris-setosa")==0)
            accurate++;
    }
    else if(f2>f3&&f2>f1)
    {
        printf("Iris-versicolor\n");
        if(strcmp(str2,"Iris-versicolor")==0)
            accurate++;
    }
    else
    {
        printf("Iris-virginica\n");
        if(strcmp(str2,"Iris-virginica")==0)
            accurate++;
    }
    }
    accuracy=accurate*100.0/30;
    printf("\nAccuracy = %f",accuracy);
    fclose(fp1);
    return 0;
}
