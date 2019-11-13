#include<stdio.h>

int compare(char *p, char *q)
{
    while(*p!='\0')
    {
        if(*p==*q)
        {
            p++;
            q++;
        }
        else
        {

          if(*p-*q>0)
          {
            return 1;
          }
          else
          {
            return -1;
          }
        }
    }
    return 0;
}


int main()
{
   char s1[20];
   char s2[20];
   printf("enter s1\n");
   gets(s1);
   printf("enter s2\n");
   gets(s2);

   printf("%d",compare(s1,s2));
   return 0;

}
