int main()
{
   char s1[50],s2[50],temp;

   printf("\nEnter String 1 : ");
   gets(s1);
   printf("\nEnter String 2 : ");
   gets(s2);

   printf("\nLengh of s1 = %d",strlen(s1));
   printf("\nCopy of s1 = %s",strcpy(s1,temp));
   printf("\nReverse = %s",strrev(s1));
   printf("\nConcat of s1 and s2 = %s",strcat(s1,s2));

   return 0;
}