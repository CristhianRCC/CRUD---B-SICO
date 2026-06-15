# CRUD de Usuários — Sistema de Gerenciamento em C

Atividade Avaliativa — Laboratório de Programação  
Engenharia da Computação — UFMA  
Prof. Rondineli Seba Salomão

---

## Discentes

| Matrícula | Nome |
|---|---|
| 2022030799 | Cristhian Renan Campos Costa |
| 220033791 | Lucas André do Nascimento Nogueira |
| 2022045586 | Fábio Carvalho Everton |

---

## Descrição do Problema

O projeto consiste na implementação de um sistema CRUD (Create, Read, Update e Delete) utilizando exclusivamente os conteúdos estudados até o momento na disciplina.

Como ainda não foram abordados arquivos ou estruturas (`struct`), os dados são armazenados em uma matriz de caracteres (`char`), simulando um pequeno banco de dados textual em memória.

O sistema permite cadastrar, buscar, modificar, remover e listar usuários durante a execução do programa.

---

## Análise do Problema

### Como funciona o sistema

O programa mantém uma lista de usuários armazenada em uma matriz de caracteres.

Cada linha da matriz representa um registro de usuário e pode armazenar um nome com até 29 caracteres.

Durante a execução, o usuário interage com um menu que disponibiliza todas as operações do CRUD.

---

## Funcionalidades Implementadas

### Criar Usuário (Create)

Permite cadastrar um novo usuário.

O sistema:

- Solicita um nome ao usuário;
- Verifica se o nome já existe;
- Impede cadastros duplicados;
- Procura a primeira posição livre na matriz;
- Informa quando a lista estiver cheia.

### Buscar Usuário (Read/Search)

Permite localizar um usuário específico.

O sistema:

- Solicita um nome para pesquisa;
- Realiza uma busca linear na matriz;
- Exibe a posição onde o usuário foi encontrado;
- Informa quando o nome não existir.

### Modificar Usuário (Update)

Permite alterar o nome de um usuário existente.

O sistema:

- Procura o usuário informado;
- Solicita o novo nome;
- Verifica se o novo nome já está em uso;
- Atualiza o registro caso seja válido.

### Apagar Usuário (Delete)

Permite remover um usuário do sistema.

O sistema:

- Procura o nome informado;
- Marca a posição como vazia;
- Libera o espaço para futuros cadastros.

### Listar Usuários

Exibe todos os usuários cadastrados.

O sistema:

- Percorre toda a matriz;
- Exibe apenas posições ocupadas;
- Informa quando não houver usuários cadastrados.

---

## Definição das Variáveis

| Nome | Tipo | Finalidade |
|---|---|---|
| `option` | `int` | Armazena a opção escolhida no menu |
| `list` | `char[100][30]` | Matriz que armazena os nomes dos usuários |
| `name` | `char[30]` | Nome digitado pelo usuário |
| `new_name` | `char[30]` | Novo nome utilizado na edição |
| `conditional` | `int` | Indica se o usuário já existe |
| `free_space` | `int` | Guarda a primeira posição livre encontrada |
| `found` | `int` | Guarda a posição do usuário encontrado |
| `exists` | `int` | Indica se o novo nome já existe |
| `vazio` | `int` | Verifica se a lista possui usuários cadastrados |

---

## Estrutura de Dados Utilizada

O armazenamento é feito através da matriz:

```c
char list[MAX_REGISTROS][MAX_LETRAS] = {0};
```

Onde:

- `MAX_REGISTROS = 100`
- `MAX_LETRAS = 30`

Exemplo:

```text
list[0] = "Joao"
list[1] = "Maria"
list[2] = "Carlos"
```

Cada linha representa um usuário cadastrado.

---

## Regras de Negócio

### Cadastro

- O nome deve ser único;
- Não é permitido cadastrar usuários repetidos;
- O cadastro falha se a matriz estiver cheia.

### Alteração

- O usuário deve existir;
- O novo nome não pode pertencer a outro usuário já cadastrado.

### Remoção

- O usuário deve existir;
- A remoção libera a posição para novos cadastros.

### Busca

- A pesquisa é realizada através de busca linear.

---

## Explicação da Lógica

O programa permanece em execução através de um laço `while`, permitindo que o usuário realize diversas operações sem reiniciar o sistema.

As operações são selecionadas através de um menu implementado com `switch-case`.

As buscas realizadas pelo sistema utilizam busca linear, percorrendo a matriz posição por posição até encontrar o usuário desejado.

As funções da biblioteca `string.h` são utilizadas para manipular os nomes:

- `strcmp()` — comparação de strings;
- `strcpy()` — cópia de strings.

Uma posição vazia da matriz é identificada através do caractere especial:

```c
'\0'
```

Esse caractere indica que não há nenhum nome armazenado naquela posição.

---

## Como Compilar e Executar

### Requisitos

- GCC instalado (Linux, Windows ou MacOS).

### Compilar

```bash
gcc main.c -o crud
```

### Executar

Linux:

```bash
./crud
```

Windows (PowerShell):

```powershell
.\crud.exe
```

---

## Exemplo de Uso

### Cadastro de Usuário

**Entrada**

```text
Opcao: 1
Insira o nome do novo usuario: Joao
```

**Saída**

```text
Usuario adicionado com sucesso!
```

---

### Busca de Usuário

**Entrada**

```text
Opcao: 2
Digite o nome que deseja buscar: Joao
```

**Saída**

```text
Nome encontrado na posicao 0.
```

---

### Alteração de Usuário

**Entrada**

```text
Opcao: 3
Insira o nome do usuario: Joao
Insira um novo nome para o usuario: Pedro
```

**Saída**

```text
Usuario alterado com sucesso!
```

---

### Remoção de Usuário

**Entrada**

```text
Opcao: 4
Insira o nome do usuario que deseja apagar: Pedro
```

**Saída**

```text
Usuario apagado com sucesso!
```

---

## Estrutura do Repositório

```text
CRUD-USUARIOS/
├── main.c
└── README.md
```

---
