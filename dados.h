#define TAMANHO_CLIENTES 10
#define TAMANHO_LIVROS 10

char livro_locado[60], cliente_loca[60], data_loca[TAMANHO_LIVROS], nome_busca[60], livro_busca[60];
    int  j;
    int  data[TAMANHO_LIVROS],opc_menu;
    int i, buscado, contaLivro,qtdClientes = 0 ,qtdLivros=0;

typedef struct clientes {
        char nome_cliente[60];
        char cpf[15];
        char telefone[30];
        char nome_busca[60];
        int cod_livro_locado;
        char cliente_loca[60];
        char data_loca[20];	
    }cli;
    cli c[TAMANHO_CLIENTES];

    struct livros {
        char  nome_livro[60];
        char autor[30];
        char ano[4];
        char livro_busca[60];
       
    };
    struct livros l[TAMANHO_LIVROS];

void inicializa_array(){
    for (int i=0; i < TAMANHO_CLIENTES; i++){
        strcpy(c[i].nome_cliente, "");
        strcpy(c[i].cpf, "");
        strcpy(c[i].telefone, "");
        c[i].cod_livro_locado = -1;
    }
    for (int j=0; j < TAMANHO_LIVROS; j++){
        strcpy(l[j].nome_livro,"");
        strcpy(l[j].autor,"");
        strcpy(l[j].ano, "");
    }
}    

void dados_teste(){
    strcpy(c[qtdClientes].nome_cliente, "eu");
    strcpy(c[qtdClientes].cpf, "1231231");
    strcpy(c[qtdClientes].telefone, "11");
    qtdClientes++;
    strcpy(c[qtdClientes].nome_cliente, "eu2");
    strcpy(c[qtdClientes].cpf, "12331231");
    strcpy(c[qtdClientes].telefone, "121");
    qtdClientes++;
    strcpy (l[qtdLivros].nome_livro,"teste");
    strcpy (l[qtdLivros].autor, "euzinha");
    strcpy (l[qtdLivros].ano, "2020");
    qtdLivros++;
}

//funções de clientes
char* ObterNomeCliente(int i){
    return c[i].nome_cliente;
}

char* ObterTelefone(int i){
    return c[i].telefone;
}

char* ObterCPF(int i){
    return c[i].cpf;
}

int CadastramentoCliente (char nome[], char telefone[], char cpf[] ){

    strcpy(c[qtdClientes].nome_cliente,nome);
    strcpy(c[qtdClientes].telefone, telefone);
    strcpy(c[qtdClientes].cpf, cpf);
    qtdClientes++;
    
    return 1;
}

int validaCliente(int i, char nome_busca[] ){
    if (strcmp(c[i].nome_cliente, nome_busca) == 0){
        return 1;
    }  else {
        return 2;
    }
}

int codigoClienteDelete(int codigo){
    if (codigo < 0 || codigo > qtdClientes-1){
        return 2;
    }
}

void dadosClientesDeletados (int codigo){
    strcpy(c[codigo].nome_cliente, "\0");
    strcpy(c[codigo].cpf, "\0");
    strcpy(c[codigo].telefone,"\0");
    
}

void atualizaClientes (int i){
    strcpy(c[i].nome_cliente, c[i+1].nome_cliente);
    strcpy(c[i].cpf, c[i+1].cpf);
    strcpy(c[i].telefone, c[i+1].telefone);
    qtdLivros--;
}
//fim de funções de clientes

//funções de livro
int CadastramentoLivro (char nome[], char ano[], char autor[]){
    if(verificaLivro() == 0){
        return 0;
    }
    strcpy(l[qtdLivros].nome_livro, nome);
    strcpy(l[qtdLivros].ano, ano );
    strcpy(l[qtdLivros].autor, autor);
    qtdLivros++;

    return 1;
}

int verificaLivro(){
    if (qtdLivros == TAMANHO_LIVROS){
        return 0;
    } else {
        return 1;
    }
}


void ObterDadosLivro (int i, char nome[], char ano[], char autor[]){
    strcpy(nome,l[i].nome_livro);
    strcpy(ano,l[i].ano);
    strcpy(autor , l[i].autor);
}

int validaLivro(int i, char livro_busca[]){
    if (strcmp(livro_busca, l[i].nome_livro)==0){
        return 1;
    }  else {
        return 2;
    }
}

int buscaCodigoLivroDelete(int codigo){
    if (codigo < 0 || codigo > qtdLivros-1){
        return 1;
    }else{ 
        return 0;
    }
}

int buscaCodigoLivroEmprestado(int codigo){
    if (c[codigo].cod_livro_locado != -1){
        return 1;
    }
}
int listagemLivros(int i){
    if (c[i].cod_livro_locado != -1){
        return 1;
    } else {
        return 0;
    }
}

void dadosLivrosDeletados (int codigo){
    strcpy(l[codigo].nome_livro, "\0");
        strcpy(l[codigo].autor, "\0");
        strcpy(l[codigo].ano,"\0");
}

void atualizaLivros (int i){
    strcpy(l[i].nome_livro, l[i+1].nome_livro);
            strcpy(l[i].autor, l[i+1].autor);
            strcpy(l[i].ano, l[i+1].ano);
            qtdLivros--;
}
//fim funções Livros


//funções de locação

int clienteValidoLocacao(int codigo_cliente){
    if (codigo_cliente < 0 || codigo_cliente >= qtdClientes){
        printf ("Cliente nao encontrado");
        return 0;
    } 
}

int livroValidoLocacao (int codigo_livro){
    if (codigo_livro < 0 || codigo_livro >= qtdLivros){
        printf ("Livro nao encontrado");
        return 0;
    }
}

void clienteComLivro(int codigo_cliente){
    if (c[codigo_cliente].cod_livro_locado != -1){
        printf ("O cliente ja possui livro locado");
        return;
    }
}

int confirmaLocacao (int codigo_cliente, int cod_livro_locado, int codigo_livro){
    if (clienteValidoLocacao != 0){
        c[codigo_cliente].cod_livro_locado = codigo_livro;
    }
    return 1;
}

void dadosLocacao (int codigo_cliente, char data_locacao[], char nome_cliente[], char nome_livro[]){
    strcpy(data_locacao,c[codigo_cliente].data_loca);
    strcpy(nome_cliente, c[codigo_cliente].nome_cliente);
    strcpy(nome_livro, l[codigo_cliente].nome_livro );
}

void livroLocado (int i, char nome[], char cliente[], char data[]){
    strcpy(nome , l[c[i].cod_livro_locado].nome_livro);
    strcpy(cliente,c[i].nome_cliente);
    strcpy(data, c[i].data_loca);
}

int contaCliente(int i){
    if (i < qtdClientes && i >= 0){
        return 1;
    }else {
        return 2;
    }
}

void devolucao (int i){
    c[i].cod_livro_locado = -1;
    strcpy(c[i].data_loca," ");
}