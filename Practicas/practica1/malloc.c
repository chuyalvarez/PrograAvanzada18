#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int doFullName(char *firstName,char *lastName, char **fullName){
int sizeFirstName= strlen(firstName);
int sizeLastName= strlen(lastName);

*fullName=(char*)malloc((sizeFirstName+sizeLastName+1)*sizeof(char));
strcpy(*fullName,firstName);
strcpy(*fullName+sizeFirstName," ");
strcpy(*fullName+sizeFirstName+1,lastName);
return 0;
}


int main(){
  char firstName[] = "Jesus";
  char *lastName = "Alvarez";
  char *fullName;

  doFullName(firstName,lastName,&fullName);

  printf("Full Name = %s\n",fullName );
  free(fullName);
  return 0;
}
