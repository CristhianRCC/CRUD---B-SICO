#define MAX_REGISTROS 100
#define MAX_LETRAS 30
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int option;

    char list[MAX_REGISTROS][MAX_LETRAS] = {0};
    char name[MAX_LETRAS];
    char new_name[MAX_LETRAS];

    int conditional = 0;
    int free_space = -1;

    printf("1 - Criar um usuario.\n");
    printf("2 - Lista de usuarios.\n");
    printf("3 - Editar usuario.\n");
    printf("4 - Apagar usuario.\n");

    scanf("%d", &option);

    switch (option)
    {
    case 1:

        conditional = 0;
        free_space = -1;

        printf("Insira o nome do novo usuario: ");
        scanf("%s", name);

        // Verifica se o usuario ja existe
        for (int i = 0; i < MAX_REGISTROS; i++)
        {
            if (strcmp(list[i], name) == 0)
            {
                conditional = 1;
                break;
            }
        }

        if (conditional)
        {
            printf("ERROR: O USUARIO JA EXISTE.\n");
        }
        else
        {
            // Procura a primeira vaga livre
            for (int i = 0; i < MAX_REGISTROS; i++)
            {
                if (list[i][0] == '\0')
                {
                    free_space = i;
                    break;
                }
            }

            if (free_space == -1)
            {
                printf("ERROR: A LISTA ESTA CHEIA.\n");
            }
            else
            {
                strcpy(list[free_space], name);
                printf("Usuario adicionado!\n");
            }
        }

        break;

    case 2:

        printf("\n=== LISTA DE USUARIOS ===\n");

        for (int i = 0; i < MAX_REGISTROS; i++)
        {
            if (list[i][0] != '\0')
            {
                printf("%d - %s\n", i, list[i]);
            }
        }

        break;

    case 3:
    {
        int found = -1;
        int exists = 0;

        printf("Insira o nome do usuario: ");
        scanf("%s", name);

        // Procura o usuario
        for (int i = 0; i < MAX_REGISTROS; i++)
        {
            if (strcmp(list[i], name) == 0)
            {
                found = i;
                break;
            }
        }

        if (found == -1)
        {
            printf("Usuario nao encontrado.\n");
            break;
        }

        printf("Insira um novo nome para o usuario: ");
        scanf("%s", new_name);

        // Verifica se o novo nome ja existe
        for (int i = 0; i < MAX_REGISTROS; i++)
        {
            if (strcmp(list[i], new_name) == 0)
            {
                exists = 1;
                break;
            }
        }

        if (exists)
        {
            printf("ERROR: Esse nome ja existe.\n");
        }
        else
        {
            strcpy(list[found], new_name);
            printf("Usuario alterado com sucesso!\n");
        }

        break;
    }

    case 4:
        printf("");
        break;

    default:
        printf("");
        break;
    }

    return 0;
}