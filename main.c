#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dados.h"

    
void cadastraCliente(){  
    
    if (qtdClientes < TAMANHO_CLIENTES){
        char nome [60];
        char telefone[60];
        char cpf[15];
        
        printf ("=======CADASTRO DE CLIENTES========\n");
        printf ("Informe seu nome: ");
        scanf ("%s", nome);
        printf ("Informe seu telefone: ");
        scanf ("%s", telefone);
        printf ("Informe o seu CPF: ");
        scanf ("%s", cpf);
        printf ("===================================\n");
        printf ("  CADASTRO CONCLUIDO COM SUCESSO   \n");
        CadastramentoCliente(nome,telefone,cpf);
    } else {
        printf ("===============ATENCAO==============\n");
        printf ("O sistema nao suporta mais cadastros\n");
        printf ("====================================\n");
    }
}
void mostraCliente(){
        
        printf ("==========DADOS DE CLIENTES==========\n");
        printf ("CODIGO \t NOME \t CPF \t TELEFONE\n");
        for (i =0; i < qtdClientes; i++){
            printf ("%d \t %s \t %s \t %s\n", i, ObterNomeCliente(i), ObterCPF(i), ObterTelefone(i));
        }
}   
char buscaCliente(){
    
    printf ("========BUSCA DE CLIENTES==========\n");
    printf ("Informe o nome do cliente: ");
    scanf ("%s", &nome_busca);

        for (i=0; i < qtdClientes; i++){
            if (validaCliente(i, nome_busca)==1){
                printf ("NOME       COD        CPF     TELEFONE\n");
                printf ("%s \t \t", ObterNomeCliente(i));
                printf ("%d \t", i);
                printf ("%s \t", ObterCPF(i));
                printf ("%s\n", ObterTelefone(i));
            } 
        }
        
        if (validaCliente(i, nome_busca)==0){
            printf ("========ATENCAO=======\n");
            printf ("Cliente nao encontrado");
        }   

}

void deletaCadastro(){

    int codigo;

    printf ("======EXCLUSAO DE CADASTRO==========\n");
    printf ("Informe o código do cliente: ");
    scanf ("%d", &codigo);
    
    if (codigoClienteDelete(codigo)==2){
        printf ("Usuario nao encontrado\n");
    } else {
        dadosClientesDeletados(codigo);
        for (i=codigo; i<=qtdClientes-1; i++){
              atualizaClientes(i);
        }
        printf ("Cadastro deletado com sucesso\n");
    }
}

void mostraLivro(){
    
    printf ("=========CATALOGO DE LIVROS ==============\n");
    printf ("CODIGO     LIVRO     DATA   AUTOR   \n");

    for (i=0; i < qtdLivros; i++){
        char nome[60], autor[60], ano[4];
        ObterDadosLivro(i, nome, ano, autor);
        printf ("  %d   -   %s -", i, nome);
        printf ("  %s   -   %s \n", ano, autor);
    }
}
void cadastraLivro(){

    if (verificaLivro()){
        char nome_livro[60];
        char ano[4];
        char autor[60];

        printf ("Informe o título do livro: ");    
        scanf ("%s", nome_livro);
        printf ("Informe o ano de publicacao: ");
        scanf ("%s", ano);
        printf ("Informe o nome do autor: ");
        scanf ("%s", autor);
        CadastramentoLivro(nome_livro, ano, autor);
    }else if (verificaLivro()==0) {
        printf ("\n===============ATENCAO==============\n");
        printf ("O sistema nao suporta mais cadastros\n");
        printf ("====================================\n");
    }
}
void buscaLivro(){
        
        printf ("----------BUSCA DE LIVROS------------------\n");
        printf ("Informe qual livro voce deseja buscar: ");
        scanf ("%s", &livro_busca);
        
        for (i=0; i < qtdLivros; i++){
            
            if (validaLivro(i, livro_busca)==1){
                char nome[60];
                char ano [4];
                char autor[60];
                ObterDadosLivro(i, nome, ano, autor);
                printf ("CODIGO \t NOME \t  AUTOR \t  ANO PUBLI.\n");
                printf ("%d \t", i);
                printf ("%s \t", nome);
                printf ("%s \t", autor);
                printf ("%s \t \n", ano);
            } 
        }

        if (validaLivro(i, livro_busca)==0){
            printf ("\n \t =ATENCAO=\n");
            printf ("Livro nao encontrado\n");
        }
}
void deletaLivro(){
    int codigo;
    printf ("================EXCLUSAO DE LIVROS===================\n");
    printf ("Informe o codigo do livro que voce deseja deletar: ");
    scanf ("%d", &codigo);
        
    if (buscaCodigoLivroDelete(codigo)==1){
        printf ("Livro nao encontrado\n");
    } 
    
    if (buscaCodigoLivroEmprestado(codigo)==1){
        printf ("O livro foi emprestado");
    } else {
        dadosLivrosDeletados(codigo);
        printf ("Cadastro deletado com sucesso.\n");
        for (i=codigo; i<=qtdLivros-1; i++){
               atualizaLivros(i);
        }
        printf ("Livro deletado com sucesso\n"); 
    }
}
void loca_livro(){

    int codigo_livro, codigo_cliente;

    printf ("==========LOCACAO DE LIVROS===========\n\n");
    mostraCliente();
    printf ("\n");
    printf ("Informe o codigo do cliente: ");
    scanf ("%d", &codigo_cliente);
    clienteValidoLocacao(codigo_cliente);
    printf ("\n ");
    mostraLivro();
    printf ("\n");
    printf ("Informe o codigo do livro: ");
    scanf ("%d", &codigo_livro);
    livroValidoLocacao(codigo_livro);
    clienteComLivro(codigo_cliente);
    printf ("Informe a data de entrega: ");
    scanf ("%s", c[codigo_cliente].data_loca);
    
    char nome_livro[60];
    char nome_cliente[60];
    char data_locacao[10];

    dadosLocacao (codigo_cliente, data_locacao, nome_cliente, nome_livro);

    printf ("Cliente: %s \n", nome_cliente);
    printf ("Livro: %s\n", nome_livro);
    printf ("Data de entrega: %s\n",data_locacao);
    
}

void lista_livro(){
    
    printf ("===========LIVROS LOCADOS================\n");
        printf ("NOME LIVRO     CLIENTE LOCADO    DATA\n");
        for (i=0; i < qtdClientes; i++){
             if (listagemLivros(i)){
                 char nome[60];
                 char cliente[60];
                 char data[5];
                livroLocado(i,nome, cliente, data);

                printf("%s \t", nome);		
                printf ("%s \t", cliente);	
                printf ("%s \t", data);		
             }
        }
}

void devolve_livro(){
    printf ("===========DEVOLUCAO DE LIVROS===========\n");
    printf ("codigo do cliente: ");
    scanf ("%d", &i);
    if (contaCliente(i)==1){
        devolucao(i);
    } else if(contaCliente(i)==2) {
        printf ("Cliente invalido\n");
    }
}

int main(){
    
    inicializa_array();
    dados_teste();
    do {
        printf ("\n=====BIBLIOTECA PATOLECA=====\n");
        printf ("[0] - Sair\n");
        printf ("[1] - Listar clientes \n");
        printf ("[2] - Cadastrar cliente pelo codigo: \n");
        printf ("[3] - Pesquisar cliente pelo nome: \n");
        printf ("[4] - Excluir cliente pelo codigo. \n");
        printf ("[5] - Listar livros \n");
        printf ("[6] - Cadastrar livro pelo codigo.\n");
        printf ("[7] - Pesquisar livro pelo nome.\n");
        printf ("[8] - Excluir livro pelo codigo.\n");
        printf ("[9] - Listar livros locados. \n");
        printf ("[10] - Locar livro. \n");
        printf ("[11] - Devolver livro pelo codigo do cliente.\n");
        scanf ("%d", &opc_menu);
        system ("cls");
        switch (opc_menu){
                 case 1:
                mostraCliente();  
            break;
            case 2:
                cadastraCliente();
            break;
            case 3:
                buscaCliente();
            break;
            case 4:
                deletaCadastro();
            break;
            case 5:
                mostraLivro();
            break;
            case 6:
                cadastraLivro();
            break;
            case 7:
                buscaLivro();
            break;
            case 8:
                deletaLivro();
            break;
            case 9:
                lista_livro();
            break;
            case 10:
                loca_livro();
            break;
            case 11:
                devolve_livro();
            break;
        }
    } while (opc_menu!=0);

    return 0;
}
