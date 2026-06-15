#define MAX_REGISTROS 100
#define MAX_LETRAS 30
#include <stdlib.h>
#include <stdio.h>

int main (){
    
int option;
char list [MAX_REGISTROS][MAX_LETRAS];
char name [MAX_LETRAS];
int conditional = 0;
int free_space = -1;

printf ("1 - Create an User.");
printf ("2 - User's List.");
printf ("3 - Edit User.");
printf ("4 - Delete User.");
scanf  ("%d", &option);


switch (option)
{
case 1:
    printf ("Enter Username: ");
    scanf  ("%s", name);
    for    (int i = 0; i < MAX_REGISTROS; i++){
        if (strcmp(list[i], nome) == 0){
            conditional = 1;
        }
    }
    
    if (existe){
        printf ("ERROR: USERNAME ALREADY EXISTS.");
    }
    else{
        for (i = 0; i < MAX_REGISTROS; i++){
            if (list[i][0] == '\0'){
                free_space = i;
                break;
            }

        }

    if (free_space == -1){
        printf ("ERROR: THE LIST IS FULL.");
    }    
    else{
        strcpy (list[free_space], name);
        printf ("The User Was Added!");
    }
    }
     break;

default:
    break;
}

return 0;
}