#ifndef PRODUTO_H
#define PRODUTO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
struct produto
{
    char *nome;
    float preco;
    int ID;
};

struct NodeCreatina {
    struct creatina *creatina; // Ponteiro para a estrutura da creatina
    struct NodeCreatina *next; // Ponteiro para o próximo nó na lista
};

struct NodeTenis {
    struct tenis *tenis;
    struct NodeTenis *next;
};

struct NodeCamiseta {
    struct camiseta *camiseta; // Ponteiro para a estrutura camiseta
    struct NodeCamiseta *next; // Ponteiro para o próximo nó
};

struct NodeAcessorio {
    struct acessorio *acessorio; // Ponteiro para a estrutura acessorio
    struct NodeAcessorio *next;   // Ponteiro para o próximo nó
};

struct NodeBola {
    struct bola *bola;     // Ponteiro para a estrutura bola
    struct NodeBola *next; // Ponteiro para o próximo nó da lista
};

struct NodeBone {
    struct bone *bone;       // Ponteiro para a estrutura bone
    struct NodeBone *next;   // Ponteiro para o próximo nó da lista
};

struct NodeChinelo {
    struct chinelo *chinelo;   // Ponteiro para o struct chinelo
    struct NodeChinelo *next;   // Ponteiro para o próximo nó
};

struct tenis
{
    float tamanhoCM;
    char *genero;
    char *marca;
    struct produto *prod;
};

struct camiseta
{
    char tamanho;
    char *genero;
    char *marca;
    struct produto *prod;
};

struct acessorio
{
    char *marca;
    struct produto *prod;
};

struct bola
{
    char *marca;
    struct produto *prod;
};

struct bone
{
    char *marca;
    struct produto *prod;
};

struct chinelo
{
    char *marca;
    float tamanhoCM;
    struct produto *prod;
};

struct creatina
{
    float quantidadeML;
    char *marca;
    struct produto *prod;
};

struct produto *verificar_produto(int ID, const char *nome_arquivo);
struct produto *criar_produto(char *nome, float preco, int ID);

struct tenis *criar_tenis_novo(char *genero, float tamanhoCM, char *marca, struct produto *prod);
struct tenis *dados_tenis_novo();
void inserir_tenis_no_arquivo(struct tenis *tenisNovo);
void realizar_cadastro_produto_tenis();
struct produto *cadastrar_produto(char *nome, float preco, int ID, const char *nome_arquivo);
struct camiseta *criar_camiseta_novo(char *marca, char *nome, float preco, int ID, char tamanho, char genero, const char *nome_arquivo);
struct camiseta *dados_camiseta_novo(const char *nome_arquivo);
void inserir_camiseta_no_arquivo(struct camiseta *camisetaNova, const char *nome_arquivo);
void realizar_cadastro_produto_camiseta();
struct acessorio *criar_acessorio_novo(char *marca, char *nome, float preco, int ID, const char *nome_arquivo);
struct acessorio *dados_acessorio_novo(const char *nome_arquivo);
void inserir_acessorio_no_arquivo(struct acessorio *acessorioNovo, const char *nome_arquivo);
void realizar_cadastro_produto_acessorio();
struct bola *criar_bola_nova(char *marca, char *nome, float preco, int ID, const char *nome_arquivo);
struct bola *dados_bola_nova(const char *nome_arquivo);
void inserir_bola_no_arquivo(struct bola *bolaNova, const char *nome_arquivo);
void realizar_cadastro_produto_bola();
struct bone *criar_bone_novo(char *marca, char *nome, float preco, int ID, const char *nome_arquivo);
struct bone *dados_bone_novo(const char *nome_arquivo);
void inserir_bone_no_arquivo(struct bone *boneNovo, const char *nome_arquivo);
void realizar_cadastro_produto_bone();
struct chinelo *criar_chinelo_novo(char *marca, float tamanhoCM, char *nome, float preco, int ID, const char *nome_arquivo);
struct chinelo *dados_chinelo_novo(const char *nome_arquivo);
void inserir_chinelo_no_arquivo(struct chinelo *chineloNovo, const char *nome_arquivo);
void realizar_cadastro_produto_chinelo();
struct creatina *criar_creatina_nova(float quantidadeML, char *marca, char *nome, float preco, int ID, const char *nome_arquivo);
struct creatina *dados_creatina_nova(const char *nome_arquivo);
void inserir_creatina_no_arquivo(struct creatina *creatinaNova, const char *nome_arquivo);
void realizar_cadastro_produto_creatina();

void listar_tenis(FILE *arch);
void listar_camisetas(FILE *arch);
void listar_acessorios(FILE *arch);
void listar_bolas(FILE *arch);
void listar_bones(FILE *arch);
void listar_chinelos(FILE *arch);
void listar_creatinas(FILE *arch);
void listar_produtos();

void sub_menu_realizar_listar_produtos();
void sub_menu_listar_produtos();
void sub_menu_realizar_cadastro_produto();
void sub_menu_cadastro_produtos();
void sub_menu_edicao_produtos();
void sub_menu_realizar_edicao_produtos();

void editar_camiseta();
void editar_bone();
void editar_acessorio();
void editar_chinelo();
void editar_creatina();
void editar_tenis();
void editar_bola();

int busca_binaria_bone(struct bone bones[], int total, int ID);
int busca_binaria_tenis(struct tenis tenis[], int total, int ID);
int busca_binaria_camisetas(struct camiseta camiseta[], int total, int ID);
int busca_binaria_bolas(struct bola bolas[], int total, int ID);
int busca_binaria_acessorios(struct acessorio acessorios[], int total, int ID);

int particionar_tenis(struct tenis tenis[], int baixo, int alto);
int particionar_bone(struct bone bones[], int baixo, int alto);
int particionar_camisetas(struct camiseta camiseta[], int baixo, int alto);
int particionar_bolas(struct bola bolas[], int baixo, int alto);
int particionar_acessorios(struct acessorio acessorios[], int baixo, int alto);

void ler_tenis(struct tenis tenis[], int *total);
void ler_bones(struct bone bones[], int *total);
void ler_camisetas(struct camiseta camiseta[], int *total);
void ler_bolas(struct bola bolas[], int *total);
void ler_acessorios(struct acessorio acessorios[], int *total);

void gravar_tenis(struct tenis tenis[], int total);
void gravar_bones(struct bone bones[], int total);
void gravar_camisetas(struct camiseta camiseta[], int total);
void gravar_bolas(struct bola bolas[], int total);
void gravar_acessorios(struct acessorio acessorios[], int total);

void quicksort_acessorios(struct acessorio acessorios[], int baixo, int alto);
void quicksort_tenis(struct tenis tenis[], int baixo, int alto);
void quicksort_bone(struct bone bones[], int baixo, int alto);
void quicksort_camisetas(struct camiseta camiseta[], int baixo, int alto);
void quicksort_bolas(struct bola bolas[], int baixo, int alto);

#endif