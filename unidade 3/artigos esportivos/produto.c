#include "produto.h"
#define MAX_ITEMS 1000

void sub_menu_realizar_cadastro_produto()
{
    printf("\tArtigos esportivos\n\n");
    printf("\t\tMENU ADMINISTRADOR\n\n");
    printf("1 - Cadastrar tenis\n");
    printf("2 - Cadastrar camiseta\n");
    printf("3 - Cadastrar acessorio\n");
    printf("4 - Cadastrar bola\n");
    printf("5 - Cadastrar bone\n");
    printf("6 - Cadastrar chinelo\n");
    printf("7 - Cadastrar creatina\n");
    printf("0 - Sair\n");
}

void sub_menu_realizar_listar_produtos()
{
    printf("\tArtigos esportivos\n\n");
    printf("\t\tMENU ADMINISTRADOR\n\n");
    printf("1 - Listar tenis\n");
    printf("2 - Listar camisetas\n");
    printf("3 - Listar acessorios\n");
    printf("4 - Listar bolas\n");
    printf("5 - Listar bones\n");
    printf("6 - Listar chinelos\n");
    printf("7 - Listar creatinas\n");
    printf("8 - Listar todos\n");
    printf("0 - Sair\n");
}

void sub_menu_realizar_edicao_produtos()
{
    printf("\tArtigos esportivos\n\n");
    printf("\t\tMENU ADMINISTRADOR\n\n");
    printf("1 - Editar tenis\n");
    printf("2 - Editar camisetas\n");
    printf("3 - Editar acessorios\n");
    printf("4 - Editar bolas\n");
    printf("5 - Editar bones\n");
    printf("6 - Editar chinelos\n");
    printf("7 - Editar creatinas\n");
    printf("0 - Sair\n");
}

void sub_menu_edicao_produtos()
{
    int op;
    do
    {
        sub_menu_realizar_edicao_produtos();
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            editar_tenis();
            break;
        case 2:
            editar_camiseta();
            break;
        case 3:
            editar_acessorio();
            break;
        case 4:
            editar_bola();
            break;
        case 5:
            editar_bone();
            break;
        case 6:
            editar_chinelo();
            break;
        case 7:
            editar_creatina();
            break;
        case 0:
            system("cls");
            printf("Obrigado por utilizar nossos servicos!\n");
            break;
        default:
            break;
        }

    } while (op != 0);
}

void sub_menu_cadastro_produtos()
{
    int op;
    do
    {
        sub_menu_realizar_cadastro_produto();
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            realizar_cadastro_produto_tenis();
            break;
        case 2:
            realizar_cadastro_produto_camiseta();
            break;
        case 3:
            realizar_cadastro_produto_acessorio();
            break;
        case 4:
            realizar_cadastro_produto_bola();
            break;
        case 5:
            realizar_cadastro_produto_bone();
            break;
        case 6:
            realizar_cadastro_produto_chinelo();
            break;
        case 7:
            realizar_cadastro_produto_creatina();
            break;
        case 0:
            system("cls");
            printf("Obrigado por utilizar nossos servicos!\n");
            break;
        default:
            break;
        }

    } while (op != 0);
}
void sub_menu_listar_produtos()
{

    int op;
    FILE *arch;
    do
    {
        sub_menu_realizar_listar_produtos();
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            arch = fopen("tenis.txt", "r");
            listar_tenis(arch);
            fclose(arch);
            break;
        case 2:
            arch = fopen("camiseta.txt", "r");
            listar_camisetas(arch);
            fclose(arch);
            break;
        case 3:
            arch = fopen("acessorio.txt", "r");

            listar_acessorios(arch);
            fclose(arch);
            break;
        case 4:
            arch = fopen("bola.txt", "r");

            listar_bolas(arch);
            fclose(arch);
            break;
        case 5:
            arch = fopen("bone.txt", "r");

            listar_bones(arch);
            fclose(arch);
            break;
        case 6:
            arch = fopen("chinelo.txt", "r");

            listar_chinelos(arch);
            fclose(arch);
            break;
        case 7:
            arch = fopen("creatina.txt", "r");

            listar_creatinas(arch);
            fclose(arch);
            break;
        case 8:
            listar_produtos();
            break;
        case 0:
            system("cls");
            printf("Obrigado por utilizar nossos servicos!\n");
            break;
        default:
            break;
        }

    } while (op != 0);
}

struct produto *criar_produto(char *nome, float preco, int ID)
{
    struct produto *novo = (struct produto *)malloc(sizeof(struct produto));
    novo->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
    novo->preco = preco;
    novo->ID = ID;
    strcpy(novo->nome, nome);
    return novo;
}

struct tenis *criar_tenis_novo(char *genero, float tamanhoCM, char *marca, struct produto *prod)
{
    // Alocar memória para o struct tenis
    struct tenis *novo = (struct tenis *)malloc(sizeof(struct tenis));

    // Alocar e copiar o conteúdo de genero
    novo->genero = (char *)malloc((strlen(genero) + 1) * sizeof(char));
    strcpy(novo->genero, genero);

    // Alocar e copiar o conteúdo de marca
    novo->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    strcpy(novo->marca, marca);

    // Atribuir os outros campos
    novo->tamanhoCM = tamanhoCM;
    novo->prod = prod;

    return novo;
}



struct tenis *dados_tenis_novo() {
    // Dados do produto
    char *nome = (char *)malloc(50 * sizeof(char));
    float preco;
    int ID;

    // Dados específicos do tênis
    float tamanhoCM;
    char *genero = (char *)malloc(15 * sizeof(char));
    char *marca = (char *)malloc(30 * sizeof(char));

    // Coletar informações do produto
    printf("Insira o nome do produto: ");
    scanf("%s", nome);
    printf("Insira o preço do produto: ");
    scanf("%f", &preco);
    printf("Insira o ID do produto: ");
    scanf("%d", &ID);

    // Criar struct produto
    struct produto *prod = criar_produto(nome, preco, ID);

    // Coletar informações do tênis
    printf("Insira tamanho do tenis em cm: ");
    scanf("%f", &tamanhoCM);
    printf("Defina para qual gênero é o tenis: ");
    scanf("%s", genero);
    printf("Insira a marca do tenis: ");
    scanf("%s", marca);

    // Criar o tênis com base no produto e nos dados coletados
    struct tenis *tenisNovo = criar_tenis_novo(genero, tamanhoCM, marca, prod);

    // Liberar memória alocada para os dados temporários
    free(nome);
    free(genero);
    free(marca);

    return tenisNovo;
}


void inserir_tenis_no_arquivo(struct tenis *tenisNovo)
{

    FILE *arch = fopen("tenis.txt", "a");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(arch, "nome do produto: %s\nvalor: %f\nID: %i\n", tenisNovo->prod->nome, tenisNovo->prod->preco, tenisNovo->prod->ID);
    fprintf(arch, "tamanho: %f\ngenero: %s\nmarca: %s\n", tenisNovo->tamanhoCM, tenisNovo->genero, tenisNovo->marca);
    fclose(arch);
    free(tenisNovo);
}

void realizar_cadastro_produto_tenis()
{
    char *nome = (char *)malloc(30 * sizeof(char));
    float preco;
    int ID;
    printf("Insira o nome do produto: ");
    scanf("%s", nome);
    printf("Insira o nome do valor de venda do produto: ");
    scanf("%f", &preco);
    printf("Insira o ID para o produto: ");
    scanf("%i", &ID);
    struct tenis *tenisNovo = (struct tenis *)malloc(sizeof(struct tenis));
    tenisNovo->prod = (struct produto *)malloc(sizeof(struct produto));
    struct produto *prod = (struct produto *)malloc(sizeof(struct produto));
    prod = cadastrar_produto(nome, preco, ID, "tenis.txt");
    if (tenisNovo->prod != NULL)
    {
        tenisNovo = dados_tenis_novo();
        tenisNovo->prod = prod;
        inserir_tenis_no_arquivo(tenisNovo);
    }
}

struct produto *cadastrar_produto(char *nome, float preco, int ID, const char *nome_arquivo)
{
    struct produto *novo;
    novo = criar_produto(nome, preco, ID);

    if (verificar_produto(novo->ID, nome_arquivo) != NULL)
    {
        system("cls");
        printf("Produto ja cadastrado no sistema\n");
        return NULL;
    }
    else
    {
        return novo;
    }
}

struct produto *verificar_produto(int ID, const char *nome_arquivo)
{
    FILE *arch = fopen(nome_arquivo, "r");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }
    char nome[MAX_LEN];
    float valor;
    int IDaux;

    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\n", nome, &valor, &IDaux) == 3)
    {
        if (IDaux == ID)
        {
            struct produto *aux = criar_produto(nome, valor, IDaux);
            fclose(arch);
            return aux;
        }
    }

    fclose(arch);
    return NULL;
}
struct camiseta *criar_camiseta_novo(char *marca, char *nome, float preco, int ID, char tamanho, char genero, const char *nome_arquivo)
{
    // Alocar memória para o struct camiseta
    struct camiseta *nova = (struct camiseta *)malloc(sizeof(struct camiseta));

    // Alocar e copiar o conteúdo de marca
    nova->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    strcpy(nova->marca, marca);

    // Criar o struct produto
    nova->prod = cadastrar_produto(nome, preco, ID, "camiseta.txt");
    if (nova->prod == NULL)
    {
        free(nova->marca);
        free(nova);
        return NULL;
    }

    // Atribuir os outros campos
    nova->tamanho = tamanho;
    nova->genero = (char *)malloc(2 * sizeof(char)); // Alocar memória para o caractere e o terminador nulo
    nova->genero[0] = genero; // Armazenar o caractere do gênero
    nova->genero[1] = '\0';    // Adicionar o terminador nulo

    return nova;
}

struct camiseta *criar_camiseta_nova(char *marca, char *nome, float preco, int ID, char tamanho, char genero, const char *nome_arquivo)
{
    // Alocar memória para o struct camiseta
    struct camiseta *nova = (struct camiseta *)malloc(sizeof(struct camiseta));
    if (nova == NULL) {
        return NULL; // Verificar se a alocação foi bem-sucedida
    }

    // Alocar e copiar o conteúdo de marca
    nova->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    if (nova->marca == NULL) {
        free(nova); // Liberar a memória alocada para camiseta
        return NULL; // Verificar se a alocação foi bem-sucedida
    }
    strcpy(nova->marca, marca);

    // Criar o struct produto manualmente
    nova->prod = (struct produto *)malloc(sizeof(struct produto));
    if (nova->prod == NULL) {
        free(nova->marca);
        free(nova);
        return NULL; // Verificar se a alocação foi bem-sucedida
    }

    // Atribuir os campos do struct produto
    nova->prod->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
    if (nova->prod->nome == NULL) {
        free(nova->prod);
        free(nova->marca);
        free(nova);
        return NULL; // Verificar se a alocação foi bem-sucedida
    }
    strcpy(nova->prod->nome, nome);
    
    nova->prod->preco = preco;
    nova->prod->ID = ID;

    // Atribuir os outros campos
    nova->tamanho = tamanho;
    nova->genero = (char *)malloc(2 * sizeof(char)); // Alocar memória para o caractere e o terminador nulo
    if (nova->genero == NULL) {
        free(nova->prod->nome);
        free(nova->prod);
        free(nova->marca);
        free(nova);
        return NULL; // Verificar se a alocação foi bem-sucedida
    }
    nova->genero[0] = genero; // Armazenar o caractere do gênero
    nova->genero[1] = '\0';    // Adicionar o terminador nulo

    return nova;
}


struct camiseta *dados_camiseta_novo(const char *nome_arquivo)
{
    char *marca = (char *)malloc(30 * sizeof(char));
    char *nome = (char *)malloc(30 * sizeof(char));
    float preco;
    int ID;
    char tamanho;
    char genero;

    printf("Insira a marca da camiseta: ");
    scanf("%s", marca);
    printf("Insira o nome do produto: ");
    scanf("%s", nome);
    printf("Insira o preco da camiseta: ");
    scanf("%f", &preco);
    printf("Insira o ID para a camiseta: ");
    scanf("%d", &ID);
    printf("Insira o tamanho da camiseta: ");
    scanf(" %c", &tamanho);
    printf("Insira o gênero da camiseta (M/F): ");
    scanf(" %c", &genero);

    return criar_camiseta_novo(marca, nome, preco, ID, tamanho, genero, nome_arquivo);
}


void inserir_camiseta_no_arquivo(struct camiseta *camisetaNovo, const char *nome_arquivo)
{
    FILE *arch = fopen(nome_arquivo, "a");
    if (arch == NULL)
    {
        perror("Erro ao abrir o arquivo para inserção");
        exit(EXIT_FAILURE);
    }

    fprintf(arch, "nome do produto: %s\nvalor: %f\nID: %i\ntamanho: %c\ngenero: %c\n", camisetaNovo->prod->nome, camisetaNovo->prod->preco, camisetaNovo->prod->ID, camisetaNovo->tamanho, camisetaNovo->genero);
    fprintf(arch, "marca: %s\n", camisetaNovo->marca);
    fclose(arch);
}


void realizar_cadastro_produto_camiseta()
{
    struct camiseta *camisetaNovo = dados_camiseta_novo("camiseta.txt");
    if (camisetaNovo != NULL)
    {
        inserir_camiseta_no_arquivo(camisetaNovo, "camiseta.txt");
        free(camisetaNovo->marca);
        free(camisetaNovo->prod->nome);
        free(camisetaNovo->prod);
        free(camisetaNovo);
    }
}


struct acessorio *criar_acessorio_novo(char *marca, char *nome, float preco, int ID, const char *nome_arquivo)
{
    struct acessorio *novo = (struct acessorio *)malloc(sizeof(struct acessorio));
    novo->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    novo->prod = cadastrar_produto(nome, preco, ID, nome_arquivo);

    if (novo->prod == NULL)
    {
        free(novo->marca);
        free(novo);
        return NULL;
    }

    strcpy(novo->marca, marca);
    return novo;
}

struct acessorio *dados_acessorio_novo(const char *nome_arquivo)
{
    char *marca = (char *)malloc(30 * sizeof(char));
    char *nome = (char *)malloc(30 * sizeof(char));
    float preco;
    int ID;

    printf("Insira a marca do acessório: ");
    scanf("%s", marca);
    printf("Insira o nome do produto: ");
    scanf("%s", nome);
    printf("Insira o preco do acessório: ");
    scanf("%f", &preco);
    printf("Insira o ID para o acessório: ");
    scanf("%d", &ID);

    return criar_acessorio_novo(marca, nome, preco, ID, nome_arquivo);
}

void inserir_acessorio_no_arquivo(struct acessorio *acessorioNovo, const char *nome_arquivo)
{
    FILE *arch = fopen(nome_arquivo, "a");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(arch, "nome do produto: %s\nvalor: %f\nID: %i\n", acessorioNovo->prod->nome, acessorioNovo->prod->preco, acessorioNovo->prod->ID);
    fprintf(arch, "marca: %s\n", acessorioNovo->marca);
    fclose(arch);
}

void realizar_cadastro_produto_acessorio()
{
    struct acessorio *acessorioNovo = dados_acessorio_novo("acessorio.txt");
    if (acessorioNovo != NULL)
    {
        inserir_acessorio_no_arquivo(acessorioNovo, "acessorio.txt");
        free(acessorioNovo->marca);
        free(acessorioNovo->prod->nome);
        free(acessorioNovo->prod);
        free(acessorioNovo);
    }
}

struct bola *criar_bola_nova(char *marca, char *nome, float preco, int ID, const char *nome_arquivo)
{
    struct bola *nova = (struct bola *)malloc(sizeof(struct bola));
    nova->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    nova->prod = cadastrar_produto(nome, preco, ID, nome_arquivo);

    if (nova->prod == NULL)
    {
        free(nova->marca);
        free(nova);
        return NULL;
    }

    strcpy(nova->marca, marca);
    return nova;
}

struct bola *criar_bola_novo(char *marca, char *nome, float preco, int ID, const char *nome_arquivo)
{
    struct bola *nova = (struct bola *)malloc(sizeof(struct bola));
    if (nova == NULL) {
        return NULL; // Verificação de alocação de memória
    }

    // Alocar e copiar o conteúdo de marca
    nova->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    if (nova->marca == NULL) {
        free(nova);
        return NULL; // Verificação de alocação de memória
    }
    strcpy(nova->marca, marca);

    // Criar o struct produto manualmente
    nova->prod = (struct produto *)malloc(sizeof(struct produto));
    if (nova->prod == NULL) {
        free(nova->marca);
        free(nova);
        return NULL; // Verificação de alocação de memória
    }

    // Atribuir os valores manualmente
    nova->prod->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
    if (nova->prod->nome == NULL) {
        free(nova->prod);
        free(nova->marca);
        free(nova);
        return NULL; // Verificação de alocação de memória
    }
    strcpy(nova->prod->nome, nome);
    
    nova->prod->preco = preco; // Atribuir preço
    nova->prod->ID = ID;       // Atribuir ID

    return nova;
}



struct bola *dados_bola_nova(const char *nome_arquivo)
{
    char *marca = (char *)malloc(30 * sizeof(char));
    char *nome = (char *)malloc(30 * sizeof(char));
    float preco;
    int ID;

    printf("Insira a marca da bola: ");
    scanf("%s", marca);
    printf("Insira o nome do produto: ");
    scanf("%s", nome);
    printf("Insira o preco da bola: ");
    scanf("%f", &preco);
    printf("Insira o ID para a bola: ");
    scanf("%d", &ID);

    return criar_bola_nova(marca, nome, preco, ID, nome_arquivo);
}

void inserir_bola_no_arquivo(struct bola *bolaNova, const char *nome_arquivo)
{
    FILE *arch = fopen(nome_arquivo, "a");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(arch, "nome do produto: %s\nvalor: %f\nID: %i\n", bolaNova->prod->nome, bolaNova->prod->preco, bolaNova->prod->ID);
    fprintf(arch, "marca: %s\n", bolaNova->marca);
    fclose(arch);
}

void realizar_cadastro_produto_bola()
{
    struct bola *bolaNova = dados_bola_nova("bola.txt");
    if (bolaNova != NULL)
    {
        inserir_bola_no_arquivo(bolaNova, "bola.txt");
        free(bolaNova->marca);
        free(bolaNova->prod->nome);
        free(bolaNova->prod);
        free(bolaNova);
    }
}

struct bone *criar_bone_novo(char *marca, char *nome, float preco, int ID, const char *nome_arquivo)
{
    struct bone *novo = (struct bone *)malloc(sizeof(struct bone));
    novo->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    novo->prod = cadastrar_produto(nome, preco, ID, nome_arquivo);

    if (novo->prod == NULL)
    {
        free(novo->marca);
        free(novo);
        return NULL;
    }

    strcpy(novo->marca, marca);
    return novo;
}

struct bone *dados_bone_novo(const char *nome_arquivo)
{
    char *marca = (char *)malloc(30 * sizeof(char));
    char *nome = (char *)malloc(30 * sizeof(char));
    float preco;
    int ID;

    printf("Insira a marca do boné: ");
    scanf("%s", marca);
    printf("Insira o nome do produto: ");
    scanf("%s", nome);
    printf("Insira o preco do boné: ");
    scanf("%f", &preco);
    printf("Insira o ID para o boné: ");
    scanf("%d", &ID);

    return criar_bone_novo(marca, nome, preco, ID, nome_arquivo);
}

void inserir_bone_no_arquivo(struct bone *boneNovo, const char *nome_arquivo)
{
    FILE *arch = fopen(nome_arquivo, "a");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(arch, "nome do produto: %s\nvalor: %f\nID: %i\n", boneNovo->prod->nome, boneNovo->prod->preco, boneNovo->prod->ID);
    fprintf(arch, "marca: %s\n", boneNovo->marca);
    fclose(arch);
}

void realizar_cadastro_produto_bone()
{
    struct bone *boneNovo = dados_bone_novo("bone.txt");
    if (boneNovo != NULL)
    {
        inserir_bone_no_arquivo(boneNovo, "bone.txt");
        free(boneNovo->marca);
        free(boneNovo->prod->nome);
        free(boneNovo->prod);
        free(boneNovo);
    }
}

struct chinelo *criar_chinelo_novo(char *marca, float tamanhoCM, char *nome, float preco, int ID, const char *nome_arquivo)
{
    struct chinelo *novo = (struct chinelo *)malloc(sizeof(struct chinelo));
    novo->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    novo->prod = cadastrar_produto(nome, preco, ID, nome_arquivo);

    if (novo->prod == NULL)
    {
        free(novo->marca);
        free(novo);
        return NULL;
    }

    strcpy(novo->marca, marca);
    novo->tamanhoCM = tamanhoCM;
    return novo;
}

struct chinelo *dados_chinelo_novo(const char *nome_arquivo)
{
    char *marca = (char *)malloc(30 * sizeof(char));
    char *nome = (char *)malloc(30 * sizeof(char));
    float tamanhoCM;
    float preco;
    int ID;

    printf("Insira a marca do chinelo: ");
    scanf("%s", marca);
    printf("Insira o tamanho do chinelo em cm: ");
    scanf("%f", &tamanhoCM);
    printf("Insira o nome do produto: ");
    scanf("%s", nome);
    printf("Insira o preco do chinelo: ");
    scanf("%f", &preco);
    printf("Insira o ID para o chinelo: ");
    scanf("%d", &ID);

    return criar_chinelo_novo(marca, tamanhoCM, nome, preco, ID, nome_arquivo);
}

void inserir_chinelo_no_arquivo(struct chinelo *chineloNovo, const char *nome_arquivo)
{
    FILE *arch = fopen(nome_arquivo, "a");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(arch, "nome do produto: %s\nvalor: %f\nID: %i\n", chineloNovo->prod->nome, chineloNovo->prod->preco, chineloNovo->prod->ID);
    fprintf(arch, "tamanho: %f\nmarca: %s\n", chineloNovo->tamanhoCM, chineloNovo->marca);
    fclose(arch);
}

void realizar_cadastro_produto_chinelo()
{
    struct chinelo *chineloNovo = dados_chinelo_novo("chinelo.txt");
    if (chineloNovo != NULL)
    {
        inserir_chinelo_no_arquivo(chineloNovo, "chinelo.txt");
        free(chineloNovo->marca);
        free(chineloNovo->prod->nome);
        free(chineloNovo->prod);
        free(chineloNovo);
    }
}

struct creatina *criar_creatina_nova(float quantidadeML, char *marca, char *nome, float preco, int ID, const char *nome_arquivo)
{
    struct creatina *nova = (struct creatina *)malloc(sizeof(struct creatina));
    nova->quantidadeML = quantidadeML;
    nova->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    nova->prod = cadastrar_produto(nome, preco, ID, nome_arquivo);

    if (nova->prod == NULL)
    {
        free(nova->marca);
        free(nova);
        return NULL;
    }

    strcpy(nova->marca, marca);
    return nova;
}

struct creatina *dados_creatina_nova(const char *nome_arquivo)
{
    char *marca = (char *)malloc(30 * sizeof(char));
    char *nome = (char *)malloc(30 * sizeof(char));
    float quantidadeML;
    float preco;
    int ID;

    printf("Insira a quantidade de creatina em ml: ");

    scanf("%f", &quantidadeML);
    printf("Insira a marca da creatina: ");
    scanf("%s", marca);
    printf("Insira o nome do produto: ");
    scanf("%s", nome);
    printf("Insira o preco da creatina: ");
    scanf("%f", &preco);
    printf("Insira o ID para a creatina: ");
    scanf("%d", &ID);

    return criar_creatina_nova(quantidadeML, marca, nome, preco, ID, nome_arquivo);
}

void inserir_creatina_no_arquivo(struct creatina *creatinaNova, const char *nome_arquivo)
{
    FILE *arch = fopen(nome_arquivo, "a");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(arch, "nome do produto: %s\nvalor: %f\nID: %i\n", creatinaNova->prod->nome, creatinaNova->prod->preco, creatinaNova->prod->ID);
    fprintf(arch, "quantidade: %f\nmarca: %s\n", creatinaNova->quantidadeML, creatinaNova->marca);
    fclose(arch);
}

void realizar_cadastro_produto_creatina()
{
    struct creatina *creatinaNova = dados_creatina_nova("creatina.txt");
    if (creatinaNova != NULL)
    {
        inserir_creatina_no_arquivo(creatinaNova, "creatina.txt");
        free(creatinaNova->marca);
        free(creatinaNova->prod->nome);
        free(creatinaNova->prod);
        free(creatinaNova);
    }
}

struct NodeTenis *criar_no_tenis(struct tenis *tenis) {
    struct NodeTenis *novo_no = (struct NodeTenis *)malloc(sizeof(struct NodeTenis));
    if (novo_no == NULL) {
        exit(EXIT_FAILURE);
    }
    novo_no->tenis = tenis;
    novo_no->next = NULL;
    return novo_no;
}


void listar_tenis(FILE *arch) {
    char nome[MAX_LEN];
    float preco;
    int ID;
    float tamanhoCM;
    char genero;  // Alterado para char, já que é apenas um caractere
    char marca[MAX_LEN];

    struct NodeTenis *head = NULL;
    struct NodeTenis *tail = NULL;

    printf("\n--- Carregando Tênis para Lista ---\n");

    // Alteração no fscanf para ler apenas um caractere para 'genero'
    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\ntamanho: %f\ngenero: %c\nmarca: %99[^\n]\n",
                  nome, &preco, &ID, &tamanhoCM, &genero, marca) == 6) {

        // Criar o struct produto
        struct produto *prod = criar_produto(nome, preco, ID);
        
        // Criar o struct tenis com os dados lidos
        struct tenis *tenisNovo = criar_tenis_novo(&genero, tamanhoCM, marca, prod);
    
        // Criar um nó para armazenar o tenis
        struct NodeTenis *novo_no = criar_no_tenis(tenisNovo);

        // Inserir o nó na lista
        if (head == NULL) {
            head = novo_no;
            tail = novo_no;
        } else {
            tail->next = novo_no;
            tail = novo_no;
        }
    }

    fclose(arch);

    // Exibir os itens da lista
    printf("\n--- Listagem de Tênis ---\n");
    struct NodeTenis *current = head;
    while (current != NULL) {
        // Armazenando os valores em variáveis locais
        char *nome_local = current->tenis->prod->nome;
        float preco_local = current->tenis->prod->preco;
        int ID_local = current->tenis->prod->ID;
        float tamanhoCM_local = current->tenis->tamanhoCM;
        char genero_local = *current->tenis->genero;  // Agora é um único caractere
        char *marca_local = current->tenis->marca;

        // Usando as variáveis locais para exibir os dados
        printf("nome do produto: %s\n", nome_local);
        printf("valor: %f\n", preco_local);
        printf("ID: %i\n", ID_local);
        printf("tamanho: %f\n", tamanhoCM_local);
        printf("genero: %c\n", genero_local);  // Exibir como caractere
        printf("marca: %s\n", marca_local);

        current = current->next;
    }

    // Liberar a memória usada pela lista
    current = head;
    while (current != NULL) {
        struct NodeTenis *temp = current;
        current = current->next;
        free(temp->tenis->prod->nome);
        free(temp->tenis->prod);
        free(temp->tenis->genero);  // Mesmo que seja char*, deve ser liberado
        free(temp->tenis->marca);
        free(temp->tenis);
        free(temp);
    }
}


struct NodeCamiseta *criar_no_camiseta(struct camiseta *camiseta) {
    // Alocar memória para o novo nó
    struct NodeCamiseta *novo_no = (struct NodeCamiseta *)malloc(sizeof(struct NodeCamiseta));
    
    // Atribuir a camiseta ao nó
    novo_no->camiseta = camiseta;
    
    // Inicializar o ponteiro next como NULL
    novo_no->next = NULL;

    return novo_no;
}


void listar_camisetas(FILE *arch) {
    char nome[MAX_LEN];
    float preco;
    int ID;
    char tamanho;  // Mantido como char
    char genero;   // Agora é um único caractere
    char marca[MAX_LEN];

    struct NodeCamiseta *head = NULL;
    struct NodeCamiseta *tail = NULL;

    printf("\n--- Listagem de Camisetas ---\n");

    // Carregar as camisetas da entrada
    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\ntamanho: %c\ngenero: %c\nmarca: %99[^\n]\n",
                  nome, &preco, &ID, &tamanho, &genero, marca) == 6) {
        
        // Criar o struct produto
        struct produto *prod = criar_produto(nome, preco, ID);
        
        // Criar o struct camiseta
        struct camiseta *camisetaNova = criar_camiseta_nova(marca, nome, preco, ID, tamanho, &genero, nome);

        // Criar um nó para armazenar a camiseta
        struct NodeCamiseta *novo_no = criar_no_camiseta(camisetaNova);

        // Inserir o nó na lista
        if (head == NULL) {
            head = novo_no;
            tail = novo_no;
        } else {
            tail->next = novo_no;
            tail = novo_no;
        }
    }

    fclose(arch);

    // Exibir os itens da lista
    printf("\n--- Listagem de Camisetas ---\n");
    struct NodeCamiseta *current = head;
    while (current != NULL) {
        // Armazenando os valores em variáveis locais
        char *nome_local = current->camiseta->prod->nome;
        float preco_local = current->camiseta->prod->preco;
        int ID_local = current->camiseta->prod->ID;
        char tamanho_local = current->camiseta->tamanho;
        char genero_local = current->camiseta->genero;  // Agora é um único caractere
        char *marca_local = current->camiseta->marca;

        // Usando as variáveis locais para exibir os dados
        printf("nome do produto: %s\n", nome_local);
        printf("valor: %f\n", preco_local);
        printf("ID: %i\n", ID_local);
        printf("tamanho: %c\n", tamanho_local);  
        printf("genero: %c\n", genero_local);  
        printf("marca: %s\n", marca_local);

        current = current->next; // Avançar para o próximo nó
    }

    // Liberar a memória usada pela lista
    current = head;
    while (current != NULL) {
        struct NodeCamiseta *temp = current;
        current = current->next;
        free(temp->camiseta->prod->nome);
        free(temp->camiseta->prod);
        free(temp->camiseta->marca);
        free(temp->camiseta);
        free(temp);
    }
}


void listar_acessorios(FILE *arch)
{
    char nome[MAX_LEN];
    float preco;
    int ID;
    char marca[MAX_LEN];

    struct NodeAcessorio *head = NULL;
    struct NodeAcessorio *tail = NULL;

    printf("\n--- Carregando Acessórios para Lista ---\n");

    // Carregar os acessórios da entrada
    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\nmarca: %99[^\n]\n",
                  nome, &preco, &ID, marca) == 4)
    {
        // Criar o struct produto manualmente
        struct produto *prod = (struct produto *)malloc(sizeof(struct produto));
        if (prod == NULL) {
            // Tratar erro de alocação
            fprintf(stderr, "Erro ao alocar memória para produto.\n");
            continue; // Pular este item
        }

        // Alocar e copiar o conteúdo de nome
        prod->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
        if (prod->nome == NULL) {
            free(prod);
            fprintf(stderr, "Erro ao alocar memória para o nome do produto.\n");
            continue; // Pular este item
        }
        strcpy(prod->nome, nome);

        // Atribuir os campos do struct produto
        prod->preco = preco;
        prod->ID = ID;

        // Criar o struct acessorio (substitua "struct acessorio" pelo nome correto)
        struct acessorio *acessorioNovo = (struct acessorio *)malloc(sizeof(struct acessorio));
        if (acessorioNovo == NULL) {
            free(prod->nome);
            free(prod);
            fprintf(stderr, "Erro ao alocar memória para acessório.\n");
            continue; // Pular este item
        }

        // Alocar e copiar o conteúdo de marca
        acessorioNovo->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
        if (acessorioNovo->marca == NULL) {
            free(prod->nome);
            free(prod);
            free(acessorioNovo);
            fprintf(stderr, "Erro ao alocar memória para a marca do acessório.\n");
            continue; // Pular este item
        }
        strcpy(acessorioNovo->marca, marca);

        // Atribuir o produto ao acessório
        acessorioNovo->prod = prod;

        // Criar um nó para armazenar o acessório
        struct NodeAcessorio *novo_no = (struct NodeAcessorio *)malloc(sizeof(struct NodeAcessorio));
        if (novo_no == NULL) {
            free(acessorioNovo->marca);
            free(acessorioNovo->prod->nome);
            free(acessorioNovo->prod);
            free(acessorioNovo);
            fprintf(stderr, "Erro ao alocar memória para nó do acessório.\n");
            continue; // Pular este item
        }
        novo_no->acessorio = acessorioNovo;
        novo_no->next = NULL;

        // Inserir o nó na lista
        if (head == NULL) {
            head = novo_no;
            tail = novo_no;
        } else {
            tail->next = novo_no;
            tail = novo_no;
        }
    }

    fclose(arch);

    // Exibir os itens da lista
    printf("\n--- Listagem de Acessórios ---\n");
    struct NodeAcessorio *current = head;
    while (current != NULL)
    {
        // Armazenando os valores em variáveis locais
        char *nome_local = current->acessorio->prod->nome;
        float preco_local = current->acessorio->prod->preco;
        int ID_local = current->acessorio->prod->ID;
        char *marca_local = current->acessorio->marca;

        // Usando as variáveis locais para exibir os dados
        printf("nome do produto: %s\n", nome_local);
        printf("valor: %f\n", preco_local);
        printf("ID: %i\n", ID_local);
        printf("marca: %s\n", marca_local);

        current = current->next; // Avançar para o próximo nó
    }

    // Liberar a memória usada pela lista
    current = head;
    while (current != NULL)
    {
        struct NodeAcessorio *temp = current;
        current = current->next;
        free(temp->acessorio->marca);
        free(temp->acessorio->prod->nome);
        free(temp->acessorio->prod);
        free(temp->acessorio);
        free(temp);
    }
}


void listar_bolas(FILE *arch)
{
    char nome[MAX_LEN];
    float preco;
    int ID;
    char marca[MAX_LEN];

    struct NodeBola *head = NULL;
    struct NodeBola *tail = NULL;

    printf("\n--- Carregando Bolas para Lista ---\n");

    // Ler os dados do arquivo e criar a lista encadeada
    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\nmarca: %99[^\n]\n",
                  nome, &preco, &ID, marca) == 4)
    {
        // Criar o struct produto
        struct produto *prod = (struct produto *)malloc(sizeof(struct produto));
        prod->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
        strcpy(prod->nome, nome);
        prod->preco = preco;
        prod->ID = ID;

        // Criar o struct bola (supondo que você tenha uma função criar_bola_nova)
       struct bola *bolaNova = criar_bola_novo(marca, prod->nome, prod->preco, prod->ID, "bola.txt");

        // Criar um nó para armazenar a bola
        struct NodeBola *novo_no = (struct NodeBola *)malloc(sizeof(struct NodeBola));
        novo_no->bola = bolaNova;
        novo_no->next = NULL;

        // Inserir o nó na lista
        if (head == NULL)
        {
            head = novo_no;
            tail = novo_no;
        }
        else
        {
            tail->next = novo_no;
            tail = novo_no;
        }
    }

    fclose(arch);

    // Exibir os itens da lista
    printf("\n--- Listagem de Bolas ---\n");
    struct NodeBola *current = head;
    while (current != NULL)
    {
        char *nome_local = current->bola->prod->nome;
        float preco_local = current->bola->prod->preco;
        int ID_local = current->bola->prod->ID;
        char *marca_local = current->bola->marca;

        printf("nome do produto: %s\n", nome_local);
        printf("valor: %f\n", preco_local);
        printf("ID: %i\n", ID_local);
        printf("marca: %s\n", marca_local);

        current = current->next; // Avançar para o próximo nó
    }

    // Liberar a memória usada pela lista
    current = head;
    while (current != NULL)
    {
        struct NodeBola *temp = current;
        current = current->next;
        free(temp->bola->prod->nome);
        free(temp->bola->prod);
        free(temp->bola->marca);
        free(temp->bola);
        free(temp);
    }
}


void listar_bones(FILE *arch)
{
    char nome[MAX_LEN];
    float preco;
    int ID;
    char marca[MAX_LEN];

    printf("\n--- Listagem de Bonés ---\n");
    
    // Estruturas de nó para bonés
    struct NodeBone *head = NULL;
    struct NodeBone *tail = NULL;

    // Carregar os bonés da entrada
    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\nmarca: %99[^\n]\n",
                  nome, &preco, &ID, marca) == 4)
    {
        // Criar o struct produto
        struct produto *prod = (struct produto *)malloc(sizeof(struct produto));
        prod->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
        strcpy(prod->nome, nome);
        prod->preco = preco;
        prod->ID = ID;

        // Criar o struct bone
        struct bone *boneNovo = (struct bone *)malloc(sizeof(struct bone));
        boneNovo->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
        strcpy(boneNovo->marca, marca);
        boneNovo->prod = prod;

        // Criar um nó para armazenar o boné
        struct NodeBone *novo_no = (struct NodeBone *)malloc(sizeof(struct NodeBone));
        novo_no->bone = boneNovo;
        novo_no->next = NULL;

        // Inserir o nó na lista
        if (head == NULL) {
            head = novo_no;
            tail = novo_no;
        } else {
            tail->next = novo_no;
            tail = novo_no;
        }
    }

    fclose(arch);

    // Exibir os itens da lista
    struct NodeBone *current = head;
    while (current != NULL) {
        // Usando os valores armazenados na estrutura
        printf("nome do produto: %s\n", current->bone->prod->nome);
        printf("valor: %f\n", current->bone->prod->preco);
        printf("ID: %i\n", current->bone->prod->ID);
        printf("marca: %s\n", current->bone->marca);

        current = current->next; // Avançar para o próximo nó
    }

    // Liberar a memória usada pela lista
    current = head;
    while (current != NULL) {
        struct NodeBone *temp = current;
        current = current->next;
        free(temp->bone->prod->nome);
        free(temp->bone->prod);
        free(temp->bone->marca);
        free(temp->bone);
        free(temp);
    }
}


void listar_chinelos(FILE *arch) {
    char nome[MAX_LEN];
    float preco;
    int ID;
    char marca[MAX_LEN];
    float tamanhoCM;

    printf("\n--- Listagem de Chinelos ---\n");

    // Estruturas de nó para chinelos
    struct NodeChinelo *head = NULL;
    struct NodeChinelo *tail = NULL;

    // Carregar os chinelos da entrada
    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\ntamanho (cm): %f\nmarca: %99[^\n]\n",
                  nome, &preco, &ID, &tamanhoCM, marca) == 5) {
        // Criar o struct produto
        struct produto *prod = (struct produto *)malloc(sizeof(struct produto));
        prod->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
        strcpy(prod->nome, nome);
        prod->preco = preco;
        prod->ID = ID;

        // Criar o struct chinelo
        struct chinelo *chineloNovo = (struct chinelo *)malloc(sizeof(struct chinelo));
        chineloNovo->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
        strcpy(chineloNovo->marca, marca);
        chineloNovo->tamanhoCM = tamanhoCM;
        chineloNovo->prod = prod;

        // Criar um nó para armazenar o chinelo
        struct NodeChinelo *novo_no = (struct NodeChinelo *)malloc(sizeof(struct NodeChinelo));
        novo_no->chinelo = chineloNovo;
        novo_no->next = NULL;

        // Inserir o nó na lista
        if (head == NULL) {
            head = novo_no;
            tail = novo_no;
        } else {
            tail->next = novo_no;
            tail = novo_no;
        }
    }

    // Checar se alguma entrada foi lida
    if (head == NULL) {
        printf("Nenhum chinelo encontrado no arquivo.\n");
    }

    // Exibir os itens da lista
    struct NodeChinelo *current = head;
    while (current != NULL) {
        printf("nome do produto: %s\n", current->chinelo->prod->nome);
        printf("valor: %f\n", current->chinelo->prod->preco);
        printf("ID: %i\n", current->chinelo->prod->ID);
        printf("tamanho (cm): %f\n", current->chinelo->tamanhoCM);
        printf("marca: %s\n", current->chinelo->marca);
        printf("-------------------------\n");

        current = current->next; // Avançar para o próximo nó
    }

    // Liberar a memória usada pela lista
    current = head;
    while (current != NULL) {
        struct NodeChinelo *temp = current;
        current = current->next;
        free(temp->chinelo->prod->nome);
        free(temp->chinelo->prod);
        free(temp->chinelo->marca);
        free(temp->chinelo);
        free(temp);
    }
}


void listar_creatinas(FILE *arch) {
    char nome[MAX_LEN];
    float preco;
    int ID;
    char marca[MAX_LEN];
    float quantidadeML;

    printf("\n--- Listagem de Creatinas ---\n");

    // Estruturas de nó para creatinas
    struct NodeCreatina *head = NULL;
    struct NodeCreatina *tail = NULL;

    // Carregar as creatinas da entrada
    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\nquantidade (ml): %f\nmarca: %99[^\n]\n",
                  nome, &preco, &ID, &quantidadeML, marca) == 5) {
        // Criar o struct produto
        struct produto *prod = (struct produto *)malloc(sizeof(struct produto));
        prod->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
        strcpy(prod->nome, nome);
        prod->preco = preco;
        prod->ID = ID;

        // Criar o struct creatina
        struct creatina *creatinaNova = (struct creatina *)malloc(sizeof(struct creatina));
        creatinaNova->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
        strcpy(creatinaNova->marca, marca);
        creatinaNova->quantidadeML = quantidadeML;
        creatinaNova->prod = prod;

        // Criar um nó para armazenar a creatina
        struct NodeCreatina *novo_no = (struct NodeCreatina *)malloc(sizeof(struct NodeCreatina));
        novo_no->creatina = creatinaNova;
        novo_no->next = NULL;

        // Inserir o nó na lista
        if (head == NULL) {
            head = novo_no;
            tail = novo_no;
        } else {
            tail->next = novo_no;
            tail = novo_no;
        }
    }

    // Checar se alguma entrada foi lida
    if (head == NULL) {
        printf("Nenhuma creatina encontrada no arquivo.\n");
    }

    // Exibir os itens da lista
    struct NodeCreatina *current = head;
    while (current != NULL) {
        printf("nome do produto: %s\n", current->creatina->prod->nome);
        printf("valor: %f\n", current->creatina->prod->preco);
        printf("ID: %i\n", current->creatina->prod->ID);
        printf("quantidade (ml): %f\n", current->creatina->quantidadeML);
        printf("marca: %s\n", current->creatina->marca);
        printf("-------------------------\n");

        current = current->next; // Avançar para o próximo nó
    }

    // Liberar a memória usada pela lista
    current = head;
    while (current != NULL) {
        struct NodeCreatina *temp = current;
        current = current->next;
        free(temp->creatina->prod->nome);
        free(temp->creatina->prod);
        free(temp->creatina->marca);
        free(temp->creatina);
        free(temp);
    }
}

void listar_produtos()
{
    const char *arquivos[] = {
        "camiseta.txt",
        "acessorio.txt",
        "bola.txt",
        "bone.txt",
        "chinelo.txt",
        "creatina.txt",
        "tenis.txt"};

    size_t num_arquivos = sizeof(arquivos) / sizeof(arquivos[0]);
    FILE *arch = NULL;

    for (size_t i = 0; i < num_arquivos; ++i)
    {
        arch = fopen(arquivos[i], "r");
        if (arch == NULL)
        {
            printf("Não foi possível abrir o arquivo %s\n", arquivos[i]);
            continue;
        }

        if (strstr(arquivos[i], "camiseta") != NULL)
        {
            listar_camisetas(arch);
        }
        else if (strstr(arquivos[i], "acessorio") != NULL)
        {
            listar_acessorios(arch);
        }
        else if (strstr(arquivos[i], "bola") != NULL)
        {
            listar_bolas(arch);
        }
        else if (strstr(arquivos[i], "bone") != NULL)
        {
            listar_bones(arch);
        }
        else if (strstr(arquivos[i], "chinelo") != NULL)
        {
            listar_chinelos(arch);
        }
        else if (strstr(arquivos[i], "creatina") != NULL)
        {
            listar_creatinas(arch);
        }
        else if (strstr(arquivos[i], "tenis") != NULL)
        {
            listar_tenis(arch);
        }

        fclose(arch);
    }
}

void editar_camiseta()
{
    int ID;
    char nome[MAX_LEN];
    float preco;
    char tamanho;
    char genero;  // Altere para 'char'
    char marca[MAX_LEN];
    int total = 0;
    struct camiseta camisetas[MAX_ITEMS] = {0};

    ler_camisetas(camisetas, &total);
    quicksort_camisetas(camisetas, 0, total - 1);

    printf("Insira o ID da camiseta a ser editada: ");
    scanf("%d", &ID);

    int indice = busca_binaria_camisetas(camisetas, total, ID);

    if (indice != -1)
    {
        printf("Camiseta encontrada! Insira os novos dados:\n");

        printf("Novo nome do produto: ");
        scanf(" %[^\n]", nome);
        printf("Novo valor do produto: ");
        scanf("%f", &preco);
        printf("Novo tamanho: ");
        scanf(" %c", &tamanho);
        printf("Novo gênero (M/F): ");
        scanf(" %c", &genero);
        printf("Nova marca: ");
        scanf(" %[^\n]", marca);

        free(camisetas[indice].prod->nome);
        camisetas[indice].prod->nome = strdup(nome);
        camisetas[indice].prod->preco = preco;
        camisetas[indice].tamanho = tamanho;
        camisetas[indice].genero = genero; 
        free(camisetas[indice].marca);
        camisetas[indice].marca = strdup(marca);

        gravar_camisetas(camisetas, total);
    }
    else
    {
        printf("Camiseta com ID %d não encontrada.\n", ID);
    }
}



void editar_acessorio()
{
    int ID;
    char nome[MAX_LEN];
    float preco;
    char marca[MAX_LEN];
    int total = 0;
    struct acessorio acessorios[MAX_ITEMS] = {0};

    ler_acessorios(acessorios, &total);
    quicksort_acessorios(acessorios, 0, total - 1);

    printf("Insira o ID do acessório a ser editado: ");
    scanf("%d", &ID);

    int indice = busca_binaria_acessorios(acessorios, total, ID);

    if (indice != -1)
    {
        printf("Acessório encontrado! Insira os novos dados:\n");

        printf("Novo nome do produto: ");
        scanf(" %[^\n]", nome);
        printf("Novo valor do produto: ");
        scanf("%f", &preco);
        printf("Nova marca: ");
        scanf(" %[^\n]", marca);

        free(acessorios[indice].prod->nome);
        acessorios[indice].prod->nome = strdup(nome);
        acessorios[indice].prod->preco = preco;
        free(acessorios[indice].marca);
        acessorios[indice].marca = strdup(marca);

        gravar_acessorios(acessorios, total);
    }
    else
    {
        printf("Acessório com ID %d não encontrado.\n", ID);
    }
}


void editar_bola()
{
    int ID;
    char nome[MAX_LEN];
    float preco;
    char marca[MAX_LEN];
    int total = 0;
    struct bola bolas[MAX_ITEMS] = {0};

    ler_bolas(bolas, &total);
    quicksort_bolas(bolas, 0, total - 1);

    printf("Insira o ID da bola a ser editada: ");
    scanf("%d", &ID);

    int indice = busca_binaria_bolas(bolas, total, ID);

    if (indice != -1)
    {
        printf("Bola encontrada! Insira os novos dados:\n");

        printf("Novo nome do produto: ");
        scanf(" %[^\n]", nome);
        printf("Novo valor do produto: ");
        scanf("%f", &preco);
        printf("Nova marca: ");
        scanf(" %[^\n]", marca);

        free(bolas[indice].prod->nome);
        bolas[indice].prod->nome = strdup(nome);
        bolas[indice].prod->preco = preco;
        free(bolas[indice].marca);
        bolas[indice].marca = strdup(marca);

        gravar_bolas(bolas, total);
    }
    else
    {
        printf("Bola com ID %d não encontrada.\n", ID);
    }
}


void editar_bone()
{
    int ID;
    char nome[MAX_LEN];
    float preco;
    int total = 0;
    struct bone bones[MAX_ITEMS];

    ler_bones(bones, &total);
    quicksort_bone(bones, 0, total - 1);

    printf("Insira o ID do boné a ser editado: ");
    scanf("%d", &ID);

    int indice = busca_binaria_bone(bones, total, ID);

    if (indice != -1)
    {
        printf("Boné encontrado! Insira os novos dados:\n");

        if (bones[indice].prod == NULL)
        {
            fprintf(stderr, "Erro: Produto não inicializado.\n");
            return;
        }

        printf("Novo nome do produto: ");
        scanf(" %[^\n]", nome);
        printf("Novo valor do produto: ");
        scanf("%f", &preco);
        printf("Nova marca: ");
        scanf(" %[^\n]", nome);

        free(bones[indice].prod->nome);
        bones[indice].prod->nome = strdup(nome);

        bones[indice].prod->preco = preco;

        free(bones[indice].marca);
        bones[indice].marca = strdup(nome);

        gravar_bones(bones, total);
    }
    else
    {
        printf("Boné com ID %d não encontrado.\n", ID);
    }
}

void editar_chinelo()
{
    int ID;
    char nome[MAX_LEN];
    float preco;
    float tamanhoCM;
    char marca[MAX_LEN];
    int total = 0;
    struct chinelo chinelos[MAX_ITEMS] = {0};

    // Ler todos os chinelos do arquivo
    ler_chinelos(chinelos, &total);
    quicksort_chinelos(chinelos, 0, total - 1);

    // Solicitar o ID do chinelo a ser editado
    printf("Insira o ID do chinelo a ser editado: ");
    scanf("%d", &ID);

    // Buscar o chinelo com o ID fornecido
    int indice = busca_binaria_chinelos(chinelos, total, ID);

    if (indice != -1)
    {
        printf("Chinelo encontrado! Insira os novos dados:\n");

        printf("Novo nome do produto: ");
        scanf(" %[^\n]", nome);
        printf("Novo valor do produto: ");
        scanf("%f", &preco);
        printf("Novo tamanho (cm): ");
        scanf("%f", &tamanhoCM);
        printf("Nova marca: ");
        scanf(" %[^\n]", marca);

        free(chinelos[indice].prod->nome);
        chinelos[indice].prod->nome = strdup(nome);
        chinelos[indice].prod->preco = preco;
        chinelos[indice].tamanhoCM = tamanhoCM;
        free(chinelos[indice].marca);
        chinelos[indice].marca = strdup(marca);

        gravar_chinelos(chinelos, total);
    }
    else
    {
        printf("Chinelo com ID %d não encontrado.\n", ID);
    }
}


void editar_creatina()
{
    int ID;
    char nome[MAX_LEN];
    float preco;
    float quantidadeML;
    char marca[MAX_LEN];
    int total = 0;
    struct creatina creatinas[MAX_ITEMS] = {0};

    // Ler todas as creatinas do arquivo
    ler_creatinas(creatinas, &total);
    quicksort_creatinas(creatinas, 0, total - 1);

    // Solicitar o ID da creatina a ser editada
    printf("Insira o ID da creatina a ser editada: ");
    scanf("%d", &ID);

    // Buscar a creatina com o ID fornecido
    int indice = busca_binaria_creatinas(creatinas, total, ID);

    if (indice != -1)
    {
        printf("Creatina encontrada! Insira os novos dados:\n");

        printf("Novo nome do produto: ");
        scanf(" %[^\n]", nome);
        printf("Novo valor do produto: ");
        scanf("%f", &preco);
        printf("Nova quantidade (ml): ");
        scanf("%f", &quantidadeML);
        printf("Nova marca: ");
        scanf(" %[^\n]", marca);

        // Atualizar os dados da creatina
        free(creatinas[indice].prod->nome);
        creatinas[indice].prod->nome = strdup(nome);
        creatinas[indice].prod->preco = preco;
        creatinas[indice].quantidadeML = quantidadeML;
        free(creatinas[indice].marca);
        creatinas[indice].marca = strdup(marca);

        // Gravar as creatinas atualizadas no arquivo
        gravar_creatinas(creatinas, total);
    }
    else
    {
        printf("Creatina com ID %d não encontrada.\n", ID);
    }
}


void editar_tenis()
{
    int ID;
    char nome[MAX_LEN];
    float preco;
    float tamanhoCM;
    char genero;
    char marca[MAX_LEN];
    int total = 0;
    struct tenis tenis[MAX_ITEMS] = {0};

    ler_tenis(tenis, &total);
    quicksort_tenis(tenis, 0, total - 1);

    printf("Insira o ID do tênis a ser editado: ");
    scanf("%d", &ID);

    int indice = busca_binaria_tenis(tenis, total, ID);

    if (indice != -1)
    {
        printf("Tênis encontrado! Insira os novos dados:\n");

        printf("Novo nome do produto: ");
        scanf(" %[^\n]", nome);
        printf("Novo valor do produto: ");
        scanf("%f", &preco);
        printf("Novo tamanho em CM: ");
        scanf("%f", &tamanhoCM);
        printf("Novo gênero (M/F): ");
        scanf(" %c", &genero);
        printf("Nova marca: ");
        scanf(" %[^\n]", marca);

        free(tenis[indice].prod->nome);
        tenis[indice].prod->nome = strdup(nome);
        tenis[indice].prod->preco = preco;
        tenis[indice].tamanhoCM = tamanhoCM;
        tenis[indice].genero = genero;
        free(tenis[indice].marca);
        tenis[indice].marca = strdup(marca);

        gravar_tenis(tenis, total);
    }
    else
    {
        printf("Tênis com ID %d não encontrado.\n", ID);
    }
}

void ler_bones(struct bone bones[], int *total)
{
    FILE *arquivo = fopen("bone.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo de bonés");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    char buffer[MAX_LEN];
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL)
    {
        if (bones[i].prod == NULL)
        {
            bones[i].prod = (struct produto *)malloc(sizeof(struct produto));
            if (bones[i].prod == NULL)
            {
                perror("Erro ao alocar memória para produto");
                exit(EXIT_FAILURE);
            }
        }

        sscanf(buffer, "nome do produto: %99[^\n]\n", buffer);
        bones[i].prod->nome = strdup(buffer);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "valor: %f\n", &bones[i].prod->preco);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "ID: %d\n", &bones[i].prod->ID);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "marca: %99[^\n]\n", buffer);
        bones[i].marca = strdup(buffer);

        i++;
    }

    *total = i;
    fclose(arquivo);
}


int particionar_bone(struct bone bones[], int baixo, int alto)
{
    int pivô = bones[alto].prod->ID;
    int i = (baixo - 1);

    for (int j = baixo; j < alto; j++)
    {
        if (bones[j].prod->ID < pivô)
        {
            i++;
            struct bone temp = bones[i];
            bones[i] = bones[j];
            bones[j] = temp;
        }
    }
    struct bone temp = bones[i + 1];
    bones[i + 1] = bones[alto];
    bones[alto] = temp;

    return (i + 1);
}

void quicksort_bone(struct bone bones[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionar_bone(bones, baixo, alto);
        quicksort_bone(bones, baixo, pi - 1);
        quicksort_bone(bones, pi + 1, alto);
    }
}

void gravar_bones(struct bone bones[], int total)
{
    if (total <= 0)
    {
        printf("Nenhum bone para gravar.\n");
        return;
    }

    FILE *arquivo = fopen("bone.txt", "w");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para gravação");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < total; i++)
    {
        if (bones[i].prod != NULL && bones[i].prod->nome != NULL && bones[i].marca != NULL)
        {
            fprintf(arquivo, "nome do produto: %s\nvalor: %.2f\nID: %d\nmarca: %s\n",
                    bones[i].prod->nome, bones[i].prod->preco, bones[i].prod->ID, bones[i].marca);
        }
        else
        {
            printf("Erro: Bone %d contém dados incompletos.\n", i);
        }
    }

    fclose(arquivo);
    printf("Gravação concluída com sucesso.\n");
}

int busca_binaria_bone(struct bone bones[], int total, int ID)
{
    int inicio = 0, fim = total - 1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (bones[meio].prod->ID == ID)
        {
            return meio;
        }
        if (bones[meio].prod->ID < ID)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}

void ler_tenis(struct tenis tenis[], int *total)
{
    FILE *arquivo = fopen("tenis.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo de tênis");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    char buffer[MAX_LEN];
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL)
    {
        if (tenis[i].prod == NULL)
        {
            tenis[i].prod = (struct produto *)malloc(sizeof(struct produto));
            if (tenis[i].prod == NULL)
            {
                perror("Erro ao alocar memória para produto");
                exit(EXIT_FAILURE);
            }
        }

        sscanf(buffer, "nome do produto: %99[^\n]\n", buffer);
        tenis[i].prod->nome = strdup(buffer);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "valor: %f\n", &tenis[i].prod->preco);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "ID: %d\n", &tenis[i].prod->ID);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "tamanho: %f\n", &tenis[i].tamanhoCM);

        fgets(buffer, sizeof(buffer), arquivo);

        char tempGenero;
        sscanf(buffer, "genero: %c\n", &tempGenero);
        tenis[i].genero = tempGenero;

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "marca: %99[^\n]\n", buffer);
        tenis[i].marca = strdup(buffer);

        i++;
    }

    *total = i;
    fclose(arquivo);
}

int particionar_tenis(struct tenis tenis[], int baixo, int alto)
{
    int pivô = tenis[alto].prod->ID;
    int i = (baixo - 1);

    for (int j = baixo; j < alto; j++)
    {
        if (tenis[j].prod->ID < pivô)
        {
            i++;
            struct tenis temp = tenis[i];
            tenis[i] = tenis[j];
            tenis[j] = temp;
        }
    }
    struct tenis temp = tenis[i + 1];
    tenis[i + 1] = tenis[alto];
    tenis[alto] = temp;

    return (i + 1);
}

void quicksort_tenis(struct tenis tenis[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionar_tenis(tenis, baixo, alto);
        quicksort_tenis(tenis, baixo, pi - 1);
        quicksort_tenis(tenis, pi + 1, alto);
    }
}

void gravar_tenis(struct tenis tenis[], int total)
{
    FILE *arquivo = fopen("tenis.txt", "w");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para gravação");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < total; i++)
    {
        fprintf(arquivo, "nome do produto: %s\nvalor: %.2f\nID: %d\ntamanho: %.2f\ngenero: %c\nmarca: %s\n",
                tenis[i].prod->nome, tenis[i].prod->preco, tenis[i].prod->ID, tenis[i].tamanhoCM, tenis[i].genero, tenis[i].marca);
    }

    fclose(arquivo);
}

int busca_binaria_tenis(struct tenis tenis[], int total, int ID)
{
    int inicio = 0, fim = total - 1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (tenis[meio].prod->ID == ID)
        {
            return meio;
        }
        if (tenis[meio].prod->ID < ID)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}

void ler_camisetas(struct camiseta camisetas[], int *total)
{
    FILE *arquivo = fopen("camiseta.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo de camisetas");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    char buffer[MAX_LEN];
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL)
    {
        if (camisetas[i].prod == NULL)
        {
            camisetas[i].prod = (struct produto *)malloc(sizeof(struct produto));
            if (camisetas[i].prod == NULL)
            {
                perror("Erro ao alocar memória para produto");
                exit(EXIT_FAILURE);
            }
        }

        sscanf(buffer, "nome do produto: %99[^\n]\n", buffer);
        camisetas[i].prod->nome = strdup(buffer);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "valor: %f\n", &camisetas[i].prod->preco);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "ID: %d\n", &camisetas[i].prod->ID);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "tamanho: %c\n", &camisetas[i].tamanho);

        fgets(buffer, sizeof(buffer), arquivo);
        char tempGenero;
        if (sscanf(buffer, "genero: %c\n", &tempGenero) == 1)
        {
            camisetas[i].genero = tempGenero;
        }
        else
        {
            fprintf(stderr, "Formato inválido para o gênero\n");
            fclose(arquivo);
            exit(EXIT_FAILURE);
        }

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "marca: %99[^\n]\n", buffer);
        camisetas[i].marca = strdup(buffer);

        i++;
    }

    *total = i;
    fclose(arquivo);
}


int particionar_camisetas(struct camiseta camisetas[], int baixo, int alto)
{
    int pivô = camisetas[alto].prod->ID;
    int i = (baixo - 1);

    for (int j = baixo; j < alto; j++)
    {
        if (camisetas[j].prod->ID < pivô)
        {
            i++;
            struct camiseta temp = camisetas[i];
            camisetas[i] = camisetas[j];
            camisetas[j] = temp;
        }
    }
    struct camiseta temp = camisetas[i + 1];
    camisetas[i + 1] = camisetas[alto];
    camisetas[alto] = temp;

    return (i + 1);
}

void quicksort_camisetas(struct camiseta camisetas[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionar_camisetas(camisetas, baixo, alto);
        quicksort_camisetas(camisetas, baixo, pi - 1);
        quicksort_camisetas(camisetas, pi + 1, alto);
    }
}

void gravar_camisetas(struct camiseta camisetas[], int total)
{
    FILE *arquivo = fopen("camiseta.txt", "w");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para gravação");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < total; i++)
    {
        fprintf(arquivo, "nome do produto: %s\nvalor: %.2f\nID: %d\ntamanho: %c\ngenero: %c\nmarca: %s\n",
                camisetas[i].prod->nome, camisetas[i].prod->preco, camisetas[i].prod->ID,
                camisetas[i].tamanho, camisetas[i].genero, camisetas[i].marca);
    }

    fclose(arquivo);
}

int busca_binaria_camisetas(struct camiseta camisetas[], int total, int ID)
{
    int inicio = 0, fim = total - 1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (camisetas[meio].prod->ID == ID)
        {
            return meio;
        }
        if (camisetas[meio].prod->ID < ID)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}

void ler_bolas(struct bola bolas[], int *total)
{
    FILE *arquivo = fopen("bola.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo de bolas");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    char buffer[MAX_LEN];
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL)
    {
        if (bolas[i].prod == NULL)
        {
            bolas[i].prod = (struct produto *)malloc(sizeof(struct produto));
            if (bolas[i].prod == NULL)
            {
                perror("Erro ao alocar memória para produto");
                exit(EXIT_FAILURE);
            }
        }

        sscanf(buffer, "nome do produto: %99[^\n]\n", buffer);
        bolas[i].prod->nome = strdup(buffer);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "valor: %f\n", &bolas[i].prod->preco);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "ID: %d\n", &bolas[i].prod->ID);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "marca: %99[^\n]\n", buffer);
        bolas[i].marca = strdup(buffer);

        i++;
    }

    *total = i;
    fclose(arquivo);
}

int particionar_bolas(struct bola bolas[], int baixo, int alto)
{
    int pivô = bolas[alto].prod->ID;
    int i = (baixo - 1);

    for (int j = baixo; j < alto; j++)
    {
        if (bolas[j].prod->ID < pivô)
        {
            i++;
            struct bola temp = bolas[i];
            bolas[i] = bolas[j];
            bolas[j] = temp;
        }
    }
    struct bola temp = bolas[i + 1];
    bolas[i + 1] = bolas[alto];
    bolas[alto] = temp;

    return (i + 1);
}

void quicksort_bolas(struct bola bolas[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionar_bolas(bolas, baixo, alto);
        quicksort_bolas(bolas, baixo, pi - 1);
        quicksort_bolas(bolas, pi + 1, alto);
    }
}

void gravar_bolas(struct bola bolas[], int total)
{
    FILE *arquivo = fopen("bola.txt", "w");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para gravação");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < total; i++)
    {
        fprintf(arquivo, "nome do produto: %s\nvalor: %.2f\nID: %d\nmarca: %s\n",
                bolas[i].prod->nome, bolas[i].prod->preco, bolas[i].prod->ID, bolas[i].marca);
    }

    fclose(arquivo);
}

int busca_binaria_bolas(struct bola bolas[], int total, int ID)
{
    int inicio = 0, fim = total - 1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (bolas[meio].prod->ID == ID)
        {
            return meio;
        }
        if (bolas[meio].prod->ID < ID)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}

void ler_acessorios(struct acessorio acessorios[], int *total)
{
    FILE *arquivo = fopen("acessorio.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo de acessórios");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    char buffer[MAX_LEN];
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL)
    {
        if (acessorios[i].prod == NULL)
        {
            acessorios[i].prod = (struct produto *)malloc(sizeof(struct produto));
            if (acessorios[i].prod == NULL)
            {
                perror("Erro ao alocar memória para produto");
                exit(EXIT_FAILURE);
            }
        }

        sscanf(buffer, "nome do produto: %99[^\n]\n", buffer);
        acessorios[i].prod->nome = strdup(buffer);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "valor: %f\n", &acessorios[i].prod->preco);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "ID: %d\n", &acessorios[i].prod->ID);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "marca: %99[^\n]\n", buffer);
        acessorios[i].marca = strdup(buffer);

        i++;
    }

    *total = i;
    fclose(arquivo);
}

int particionar_acessorios(struct acessorio acessorios[], int baixo, int alto)
{
    int pivô = acessorios[alto].prod->ID;
    int i = (baixo - 1);

    for (int j = baixo; j < alto; j++)
    {
        if (acessorios[j].prod->ID < pivô)
        {
            i++;
            struct acessorio temp = acessorios[i];
            acessorios[i] = acessorios[j];
            acessorios[j] = temp;
        }
    }
    struct acessorio temp = acessorios[i + 1];
    acessorios[i + 1] = acessorios[alto];
    acessorios[alto] = temp;

    return (i + 1);
}

void quicksort_acessorios(struct acessorio acessorios[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionar_acessorios(acessorios, baixo, alto);
        quicksort_acessorios(acessorios, baixo, pi - 1);
        quicksort_acessorios(acessorios, pi + 1, alto);
    }
}

void gravar_acessorios(struct acessorio acessorios[], int total)
{
    FILE *arquivo = fopen("acessorio.txt", "w");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para gravação");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < total; i++)
    {
        fprintf(arquivo, "nome do produto: %s\nvalor: %.2f\nID: %d\nmarca: %s\n",
                acessorios[i].prod->nome, acessorios[i].prod->preco, acessorios[i].prod->ID,
                acessorios[i].marca);
    }

    fclose(arquivo);
}

int busca_binaria_acessorios(struct acessorio acessorios[], int total, int ID)
{
    int inicio = 0, fim = total - 1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (acessorios[meio].prod->ID == ID)
        {
            return meio;
        }
        if (acessorios[meio].prod->ID < ID)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}


void ler_chinelos(struct chinelo chinelos[], int *total)
{
    FILE *arquivo = fopen("chinelo.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo de chinelos");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    char buffer[MAX_LEN];
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL)
    {
        if (chinelos[i].prod == NULL)
        {
            chinelos[i].prod = (struct produto *)malloc(sizeof(struct produto));
            if (chinelos[i].prod == NULL)
            {
                perror("Erro ao alocar memória para produto");
                exit(EXIT_FAILURE);
            }
        }

        sscanf(buffer, "nome do produto: %99[^\n]\n", buffer);
        chinelos[i].prod->nome = strdup(buffer);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "valor: %f\n", &chinelos[i].prod->preco);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "ID: %d\n", &chinelos[i].prod->ID);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "tamanho (cm): %f\n", &chinelos[i].tamanhoCM);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "marca: %99[^\n]\n", buffer);
        chinelos[i].marca = strdup(buffer);

        i++;
    }

    *total = i;
    fclose(arquivo);
}

int particionar_chinelos(struct chinelo chinelos[], int baixo, int alto)
{
    int pivô = chinelos[alto].prod->ID;
    int i = (baixo - 1);

    for (int j = baixo; j < alto; j++)
    {
        if (chinelos[j].prod->ID < pivô)
        {
            i++;
            struct chinelo temp = chinelos[i];
            chinelos[i] = chinelos[j];
            chinelos[j] = temp;
        }
    }
    struct chinelo temp = chinelos[i + 1];
    chinelos[i + 1] = chinelos[alto];
    chinelos[alto] = temp;

    return (i + 1);
}

void quicksort_chinelos(struct chinelo chinelos[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionar_chinelos(chinelos, baixo, alto);
        quicksort_chinelos(chinelos, baixo, pi - 1);
        quicksort_chinelos(chinelos, pi + 1, alto);
    }
}

void gravar_chinelos(struct chinelo chinelos[], int total)
{
    FILE *arquivo = fopen("chinelo.txt", "w");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para gravação");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < total; i++)
    {
        fprintf(arquivo, "nome do produto: %s\nvalor: %.2f\nID: %d\ntamanho (cm): %.2f\nmarca: %s\n",
                chinelos[i].prod->nome, chinelos[i].prod->preco, chinelos[i].prod->ID,
                chinelos[i].tamanhoCM, chinelos[i].marca);
    }

    fclose(arquivo);
}

int busca_binaria_chinelos(struct chinelo chinelos[], int total, int ID)
{
    int inicio = 0, fim = total - 1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (chinelos[meio].prod->ID == ID)
        {
            return meio;
        }
        if (chinelos[meio].prod->ID < ID)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}


void ler_creatinas(struct creatina creatinas[], int *total)
{
    FILE *arquivo = fopen("creatina.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo de creatinas");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    char buffer[MAX_LEN];
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL)
    {
        if (creatinas[i].prod == NULL)
        {
            creatinas[i].prod = (struct produto *)malloc(sizeof(struct produto));
            if (creatinas[i].prod == NULL)
            {
                perror("Erro ao alocar memória para produto");
                exit(EXIT_FAILURE);
            }
        }

        sscanf(buffer, "nome do produto: %99[^\n]\n", buffer);
        creatinas[i].prod->nome = strdup(buffer);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "valor: %f\n", &creatinas[i].prod->preco);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "ID: %d\n", &creatinas[i].prod->ID);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "quantidade (ml): %f\n", &creatinas[i].quantidadeML);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "marca: %99[^\n]\n", buffer);
        creatinas[i].marca = strdup(buffer);

        i++;
    }

    *total = i;
    fclose(arquivo);
}

int particionar_creatinas(struct creatina creatinas[], int baixo, int alto)
{
    int pivô = creatinas[alto].prod->ID;
    int i = (baixo - 1);

    for (int j = baixo; j < alto; j++)
    {
        if (creatinas[j].prod->ID < pivô)
        {
            i++;
            struct creatina temp = creatinas[i];
            creatinas[i] = creatinas[j];
            creatinas[j] = temp;
        }
    }
    struct creatina temp = creatinas[i + 1];
    creatinas[i + 1] = creatinas[alto];
    creatinas[alto] = temp;

    return (i + 1);
}

void quicksort_creatinas(struct creatina creatinas[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionar_creatinas(creatinas, baixo, alto);
        quicksort_creatinas(creatinas, baixo, pi - 1);
        quicksort_creatinas(creatinas, pi + 1, alto);
    }
}

void gravar_creatinas(struct creatina creatinas[], int total)
{
    FILE *arquivo = fopen("creatina.txt", "w");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para gravação");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < total; i++)
    {
        fprintf(arquivo, "nome do produto: %s\nvalor: %.2f\nID: %d\nquantidade (ml): %.2f\nmarca: %s\n",
                creatinas[i].prod->nome, creatinas[i].prod->preco, creatinas[i].prod->ID,
                creatinas[i].quantidadeML, creatinas[i].marca);
    }

    fclose(arquivo);
}

int busca_binaria_creatinas(struct creatina creatinas[], int total, int ID)
{
    int inicio = 0, fim = total - 1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (creatinas[meio].prod->ID == ID)
        {
            return meio;
        }
        if (creatinas[meio].prod->ID < ID)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}
