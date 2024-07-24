#include<stdio.h>
int main()
{
    FILE *ps;
    //char name[20]="Monjur Morshed";
    //int age=50;
    //int length=strlen(name);
    ps=fopen("Monjur.txt","r");
    /*for(int i=0;i<length;i++)
    {
        fputc(name[i],ps);//fputc(string,filename);
    }
        fprintf(ps,"\n");
        fprintf(ps,"%d\n",age);//fprintf(file pointer,format specifiers,variable);*/
        /*char ch;
        while(!feof(ps))
        {
            ch=fgetc(ps);
            printf("%c",ch);
        }*/
        //fgets(variable,size,filepointer);
        /*char ch[30];
        while(!feof(ps))
        {
            fgets(ch,30,ps);
            printf("%s\n",ch);
        }*/
        //fscanf(filepointer,format specifier,variable name);
        char fn[8];
        char ln[8];
        int age;
        fscanf(ps,"%s %s %d",&fn,&ln,&age);
        printf("%s %s %d",fn,ln,age);

    fclose(ps);
    return 0;
}
