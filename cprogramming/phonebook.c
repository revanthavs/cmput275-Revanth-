#include <stdio.h>
#include <string.h>

int main(void){
   FILE *file = fopen("phonebook.csv", "a");

   char *name;
   char *number;
   scanf("%s", name);
   scanf("%s", number);

   fprintf(file, "%s,%s\n", name, number);

   fclose(file);
}
