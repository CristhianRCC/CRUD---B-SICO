#define MAX_REGISTROS 100
#define MAX_LETRAS 30
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    //Variaveis essenciais do programa
    int option = -1;

    char list[MAX_REGISTROS][MAX_LETRAS] = {0};
    char name[MAX_LETRAS];
    char new_name[MAX_LETRAS];

    //Continua perguntando sem ter que executar manualmente 
    while(option != 0)
    {
        printf("\n===== CRUD DE USUARIOS =====\n");
        printf("1 - Criar usuario\n");
        printf("2 - Buscar usuario\n");
        printf("3 - Editar usuario\n");
        printf("4 - Apagar usuario\n");
        printf("5 - Listar usuarios\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        scanf("%d", &option);

        //Menu
        switch(option)
        {
            case 1:
            {
                int conditional = 0;
                int free_space = -1;
                //Adiciona uma string de ate 29 caracteres 
                printf("Insira o nome do novo usuario: ");
                scanf("%29s", name);

                //Verifica se o usuario ja existe
                for(int i = 0; i < MAX_REGISTROS; i++)
                {
                    if(strcmp(list[i], name) == 0)
                    {
                        conditional = 1;
                        break;
                    }
                }

                if(conditional)
                {
                    printf("ERROR: O USUARIO JA EXISTE.\n");
                }
                else
                {
                    for(int i = 0; i < MAX_REGISTROS; i++)
                    {
                        if(list[i][0] == '\0')
                        {
                            free_space = i;
                            break;
                        }
                    }

                    if(free_space == -1)
                    {
                        printf("ERROR: A LISTA ESTA CHEIA.\n");
                    }
                    else
                    {
                        strcpy(list[free_space], name);
                        printf("Usuario adicionado com sucesso!\n");
                    }
                }

                break;
            }

            case 2:
            {
                int found = -1;

                printf("Digite o nome que deseja buscar: ");
                scanf("%29s", name);

                for(int i = 0; i < MAX_REGISTROS; i++)
                {
                    if(strcmp(list[i], name) == 0)
                    {
                        found = i;
                        break;
                    }
                }

                if(found == -1)
                {
                    printf("Nome nao encontrado.\n");
                }
                else
                {
                    printf("Nome encontrado na posicao %d.\n", found);
                }

                break;
            }

            case 3:
            {
                //Caso para a modificacao de usuario
                int found = -1;
                int exists = 0;

                printf("Insira o nome do usuario: ");
                scanf("%29s", name);

                for(int i = 0; i < MAX_REGISTROS; i++)
                {
                    if(strcmp(list[i], name) == 0)
                    {
                        found = i;
                        break;
                    }
                }

                if(found == -1)
                {
                    printf("Usuario nao encontrado.\n");
                    break;
                }

                printf("Insira um novo nome para o usuario: ");
                scanf("%29s", new_name);

                for(int i = 0; i < MAX_REGISTROS; i++)
                {
                    if(i != found && strcmp(list[i], new_name) == 0)
                    {
                        exists = 1;
                        break;
                    }
                }

                if(exists)
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
            {
                int found = -1;
                
                printf("Insira o nome do usuario que deseja apagar: ");
                scanf("%29s", name);

                for(int i = 0; i < MAX_REGISTROS; i++)
                {
                    if(strcmp(list[i], name) == 0)
                    {
                        found = i;
                        break;
                    }
                }

                if(found == -1)
                {
                    printf("Usuario nao encontrado.\n");
                }
                else
                {
                    list[found][0] = '\0';
                    printf("Usuario apagado com sucesso!\n");
                }

                break;
            }

            case 5:
            {
                int vazio = 1;

                printf("\n=== LISTA DE USUARIOS ===\n");
                //Verifica se todo o vetor linha esta preenchido
                for(int i = 0; i < MAX_REGISTROS; i++)
                {
                    if(list[i][0] != '\0')
                    {
                        printf("%d - %s\n", i, list[i]);
                        vazio = 0;
                    }
                }

                if(vazio)
                {
                    printf("Nenhum usuario cadastrado.\n");
                }

                break;
            }

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    }

    return 0;
}