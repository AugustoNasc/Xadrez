//Augusto Nascimento de Oliveira
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 8
#define MOSTRAR_TAB printf("\n   a b c d e f g h");\
                    printf("\n   ---------------");\
                    for(int k=0; k<TAM; k++){       \
                        printf("\n");               \
                        printf("%d| ", k+1);        \
                        for(int j=0; j<TAM; j++){   \
                            if(tab[k][j]=='@'){     \
                                printf("'|");       \
                            }                       \
                            else{\
                            printf("%c|", tab[k][j]);\
                            }\
                        }\
                        printf(" |%d ", k+1);\
                    }\
                    printf("\n   ---------------");\
                    printf("\n   a b c d e f g h");

#define LIMPA_ALOCACOES for(int j=0; j<i; j++){\
                            free(jogadaTmp[j]);}\
                        for(int j=0; j<TAM; j++){\
                            free(tab[j]);\
                        }\
                        free(tab);

#define VERIFICAR_CHECK_REI_PRETO  if(tab[jogada[5]-'1'][jogada[4]-'a']=='r'){\
                            return 2;\
            }
#define VERIFICAR_CHECK_REI_BRANCO  if(tab[jogada[5]-'1'][jogada[4]-'a']=='R'){\
                            return 3;\
            }

#define JOGADA_DA_PECA if(verificacao==0){\
                    printf("falhou, tente outro movimento");\
                }\
\
                else if(verificacao==1){\
                fprintf(jogo, "%s\n", movimento);\
                }\
\
                else if(verificacao==2){\
                    fprintf(jogo, "%s\n", movimento);\
                    printf("As Brancas ganharam!\n");\
                    LIMPA_ALOCACOES;\
                    fclose(jogo);\
                    remove("jogo.bin");\
                    return 0;\
                }\
\
                else if(verificacao==3){\
                    fprintf(jogo, "%s\n", movimento);\
                    printf("As Pretas ganharam!\n");\
                    LIMPA_ALOCACOES;\
                    fclose(jogo);\
                    remove("jogo.bin");\
                    return 0;\
                }

FILE *jogo;
char **tab; //tab eh o tabuleiro [linha/numeros][coluna/letras], as linhas sao invertidas
int main(){
    //isto eh, comeca o 8 e daí, vai pra linha 1    primeiora posicao tab[7][0]
    char **jogada, **jogadaTmp= NULL; //jogada eh a string
    char movimento[7];
    int i=0;
    if( (jogo = fopen("jogo.bin", "a+b")) != NULL){
        rewind(jogo);
        tab = (char **)calloc(TAM, sizeof(char *)); //alocando o **tab
        if(tab==NULL){
            printf("Problema da alocacao");
            exit(1);
        }
        for(int j=0; j<TAM; j++){
            tab[j] = (char *)calloc(TAM, sizeof(char)); //alocando as colunas de **tab
            if(tab[j]==NULL){
                for(int k=0; k<j; k++){
                    free(tab[k]);
                }
                free(tab);
            }
        } //tab completamente alocado
        while(!feof(jogo)){
            jogada = (char **)realloc(jogadaTmp, (i+1)*sizeof(char *));
            if(jogada == NULL && jogadaTmp!=NULL){
                for(int j=0; j<i; j++){
                    free(jogadaTmp[j]);} //fazendo o devido free
                    for(int j=0; j<TAM; j++){
                        free(tab[j]);
                    }
                    free(tab);
            }
            else{
                jogadaTmp = jogada;
                jogada[i] = (char *)calloc(7, sizeof(char)); //7 eh o tamanho da string comando (incluindo \0)
                if(jogada[i]==NULL){
                    for(int j=0; j<i; j++){
                    free(jogadaTmp[j]); } //fazendo o devido free
                    for(int j=0; j<TAM; j++){
                        free(tab[j]);
                    }
                    free(tab);
                }
                fscanf(jogo, "%6s\n", jogada[i]); //^lembrar do \n quanto fizer o fprintf
                i++;
            }
        }
        void TabuleiroNoInicio(void);
        TabuleiroNoInicio();
        for(int j=0; j<i; j++){ //note que se i==0, isto eh, n tem nada no arquivo, nao vamos percorrer o for
            if(jogada[j][0]=='P'||jogada[j][0]=='p'){
                int movePeao(char **tab, char jogada[7]);
                if(movePeao(tab, jogada[j])==0){
              //      printf("falhou, tente outra jogada"); //isso nao vai ocorrer quando tivermos lendo a string
                }//mas custa nada botar, neh
            }


            if(jogada[j][0]=='T'||jogada[j][0]=='t'){
                int moveTorre(char **tab, char jogada[7]);
                if(moveTorre(tab, jogada[j])==0){
              //      printf("falhou, tente outra jogada"); //isso nao vai ocorrer quando tivermos lendo a string
                }//mas custa nada botar, neh
            }


            if(jogada[j][0]=='C'||jogada[j][0]=='c'){
                int moveCavalo(char **tab, char jogada[7]);
                if(moveCavalo(tab, jogada[j])==0){
            //        printf("falhou, tente outra jogada"); //isso nao vai ocorrer quando tivermos lendo a string
                }//mas custa nada botar, neh
            }


            if(jogada[j][0]=='B'||jogada[j][0]=='b'){
                int moveBispo(char **tab, char jogada[7]);
                if(moveBispo(tab, jogada[j])==0){
            //        printf("falhou, tente outra jogada"); //isso nao vai ocorrer quando tivermos lendo a string
                }//mas custa nada botar, neh
            }


            if(jogada[j][0]=='R'||jogada[j][0]=='r'){
                int moveRei(char **tab, char jogada[7]);
                if(moveRei(tab, jogada[j])==0){
            //        printf("falhou, tente outra jogada"); //isso nao vai ocorrer quando tivermos lendo a string
                }//mas custa nada botar, neh
            }


            if(jogada[j][0]=='D'||jogada[j][0]=='d'){
                int moveDama(char **tab, char jogada[7]);
                if(moveDama(tab, jogada[j])==0){
            //        printf("falhou, tente outra jogada"); //isso nao vai ocorrer quando tivermos lendo a string
                }//mas custa nada botar, neh
            }


        } //iso tudo foi so ler o que ja tinha no arquivo
        MOSTRAR_TAB;
        fseek(jogo, 0, SEEK_END);

        printf("\nDiga um movimento ('peca''coluna_atual''linha_atual'-'coluna_futura''linha_futura'): ");

        int verificacao;

        while(scanf(" %s", movimento)!=EOF){
            if(movimento[0]=='P'||movimento[0]=='p'){
                int movePeao(char **tab, char jogada[7]);
                verificacao = movePeao(tab, movimento);

                JOGADA_DA_PECA;
                
                MOSTRAR_TAB;
            }
            if(movimento[0]=='T'||movimento[0]=='t'){
                int moveTorre(char **tab, char jogada[7]);

                verificacao = moveTorre(tab, movimento);
                
                JOGADA_DA_PECA;

                MOSTRAR_TAB;
            }
            if(movimento[0]=='C'||movimento[0]=='c'){
                int moveCavalo(char **tab, char jogada[7]);

                verificacao = moveCavalo(tab, movimento);
                
                JOGADA_DA_PECA;
                
                MOSTRAR_TAB;
            }
            if(movimento[0]=='B'||movimento[0]=='b'){
                int moveBispo(char **tab, char jogada[7]);

                verificacao = moveBispo(tab, movimento);
                
                JOGADA_DA_PECA;
                
                MOSTRAR_TAB;
            }
            if(movimento[0]=='R'||movimento[0]=='r'){
                int moveRei(char **tab, char jogada[7]);

                verificacao = moveRei(tab, movimento);
                
                JOGADA_DA_PECA;
                
                MOSTRAR_TAB;
            }
            if(movimento[0]=='D'||movimento[0]=='d'){
                int moveDama(char **tab, char jogada[7]);

                verificacao = moveDama(tab, movimento);
                
                JOGADA_DA_PECA;
                
                MOSTRAR_TAB;
            }
            printf("\nDiga um movimento: ");
        }
        for(int j=0; j<i; j++){
            free(jogadaTmp[j]);} //fazendo o devido free
        for(int j=0; j<TAM; j++){
            free(tab[j]);
        }
        free(tab);
        fclose(jogo);
    }

    else{
        printf("Nao encontrei o jogo e o arquivo nao pode ser criado");
        fclose(jogo);
    }
    return 0;
}


void TabuleiroNoInicio(void){
    rewind(jogo);
    //@ sao os espacos sem pecas
    for(int j=2; j<TAM-2; j++){
        for(int k=0; k<TAM; k++)
        tab[j][k]='@';
    }
    tab[0][0]='T';tab[0][1]='C';tab[0][2]='B';tab[0][3]='R';tab[0][4]='D';tab[0][5]='B';tab[0][6]='C';tab[0][7]='T';
    tab[1][0]='P';tab[1][1]='P';tab[1][2]='P';tab[1][3]='P';tab[1][4]='P';tab[1][5]='P';tab[1][6]='P';tab[1][7]='P';
    tab[6][0]='p';tab[6][1]='p';tab[6][2]='p';tab[6][3]='p';tab[6][4]='p';tab[6][5]='p';tab[6][6]='p';tab[6][7]='p';
    tab[7][0]='t';tab[7][1]='c';tab[7][2]='b';tab[7][3]='r';tab[7][4]='d';tab[7][5]='b';tab[7][6]='c';tab[7][7]='t';
}


int movePeao(char **tab, char jogada[7]){//supondo que os brancos sempre estejam em baixo
//ex: jogada = "Pf1-c4"
    int linha1 = abs(jogada[2] - '1');
    int coluna1 = abs(jogada[1] - 'a');
    int linha2 = abs(jogada[5] - '1');
    int coluna2 = abs(jogada[4] - 'a');

    if(tab[linha1][coluna1]!='p'&&tab[linha1][coluna1]!='P'){
        return 0;
    }
        if(jogada[5]-jogada[2]==1||jogada[5]-jogada[2]==-1){ //uma linha pra frente ou pra traz

            if(jogada[4]-jogada[1]==0){ //mesma letra

                if(tab[linha2][coluna2]=='@'){ //note que na string esta invertido linha coluna

                    if(jogada[0]=='P' && (tab[linha2][coluna2]>'a'||tab[linha2][coluna2]=='@')){
                        if(jogada[5]-jogada[2]==1){ //pra frente
                            tab[linha1][coluna1]='@'; //deixando vazio no lugar que o peao saiu
                            tab[linha2][coluna2]='P';
                            return 1;
                        }
                        else {return 0;}
                    } //colocando peao no destino

                    else if(jogada[0]=='p'&& ((tab[linha2][coluna2]>'A'&& tab[linha2][coluna2]<'a')||tab[linha2][coluna2]=='@')){
                        if(jogada[5]-jogada[2]==-1){ //pre frente
                            tab[linha1][coluna1]='@';
                            tab[linha2][coluna2]='p';
                            return 1;
                            }
                        else {return 0;}
                    } //colocando peao no destino

                }
                else {return 0;}

            }
            else if(jogada[4]-jogada[1]==1||jogada[4]-jogada[1]==-1){ //indo para a direita ou esquerda

                if(tab[linha2][coluna2]!='@'){//peao so move na diagonal se tiver alguem pra comer
                    if(jogada[0]=='P'&& (tab[linha2][coluna2]>'a'||tab[linha2][coluna2]=='@')){
                        if(jogada[5]-jogada[2]==1){
                            VERIFICAR_CHECK_REI_PRETO;
                            tab[linha1][coluna1]='@';
                            tab[linha2][coluna2]='P';
                            return 1;
                        }
                        else return 0;
                    }
                    else if(jogada[0]=='p'&&((tab[linha2][coluna2]>'A'&& tab[linha2][coluna2]<'a')||tab[linha2][coluna2]=='@')){
                            if(jogada[5]-jogada[2]==-1){
                                VERIFICAR_CHECK_REI_BRANCO;
                                tab[linha1][coluna1]='@';
                                tab[linha2][coluna2]='p';
                                return 1;
                            }
                            else return 0;
                        }
                }
                else {return 0;}

            }
            else {return 0;}

        }
        else {return 0;}
}


int moveTorre(char **tab, char jogada[7]){//supondo que os brancos sempre estejam em baixo
//ex: jogada = "Pf1-c4"
    int linha1 = abs(jogada[2] - '1');
    int coluna1 = abs(jogada[1] - 'a');
    int linha2 = abs(jogada[5] - '1');
    int coluna2 = abs(jogada[4] - 'a');
    int menor, maior;

    if(coluna1<coluna2){menor = coluna1; maior = coluna2;}
    else {menor=coluna2; maior = coluna1;}

    if(tab[linha1][coluna1]!='t'&&tab[linha1][coluna1]!='T'){
        return 0;
    }
    if(jogada[2]==jogada[5]){ //mesmas linhas
        for(int j=menor+1; j<maior; j++){
            if(tab[linha1][j]!='@'){
                return 0;
            }
        }
        if(tab[linha1][coluna1]=='T' && (tab[linha2][coluna2]>'a'||tab[linha2][coluna2]=='@')){
            VERIFICAR_CHECK_REI_PRETO;
            tab[linha2][coluna2]='T';
            tab[linha1][coluna1]='@'; 
            return 1;
        }

        else if(tab[linha1][coluna1]=='t' &&((tab[linha2][coluna2]>'A'&& tab[linha2][coluna2]<'a')||tab[linha2][coluna2]=='@')){
            VERIFICAR_CHECK_REI_BRANCO;
            tab[linha2][coluna2]='t';
            tab[linha1][coluna1]='@'; 
            return 1;
            }
            else return 0;
    }
    else if(jogada[1]==jogada[4]){ //mesmas colunas
        for(int j=menor+1; j<maior; j++){
            if(tab[j][coluna1]!='@'){
                return 0;
            }
        }
        if(tab[linha1][coluna1]=='T'&& (tab[linha2][coluna2]>'a'||tab[linha2][coluna2]=='@')){
            VERIFICAR_CHECK_REI_PRETO;
            tab[linha2][coluna2]='T';
            tab[linha1][coluna1]='@'; 
            return 1;
            }

        else if(tab[linha1][coluna1]=='t'&&((tab[linha2][coluna2]>'A'&& tab[linha2][coluna2]<'a')||tab[linha2][coluna2]=='@')){
            VERIFICAR_CHECK_REI_BRANCO;
            tab[linha2][coluna2]='t';
            tab[linha1][coluna1]='@'; 
            return 1;
            }
        else return 0;
    }
    else return 0;
}


int moveBispo(char **tab, char jogada[7]){//supondo que os brancos sempre estejam em baixo
//ex: jogada = "Pf1-c4"
    int linha1 = abs(jogada[2] - '1');
    int coluna1 = abs(jogada[1] - 'a');
    int linha2 = abs(jogada[5] - '1');
    int coluna2 = abs(jogada[4] - 'a');

    int cont1=-1, cont2=-1;
    int diferencaModulo = abs(jogada[2]-jogada[5]);
    int diferencaColunas= jogada[4]-jogada[1]; //se + direita, se - esquerda (coluna2-coluna1)
    int diferencaLinhas= jogada[5]-jogada[2]; //se + sobe, se - desce (linha2-linha1)
    if(tab[linha1][coluna1]!='b'&&tab[linha1][coluna1]!='B'){
        return 0;
    }
    if(diferencaLinhas==diferencaColunas||diferencaLinhas==(-1)*diferencaColunas){ //diagonal

        if(diferencaColunas>0) cont2=1;
        else cont2=-1;

        if(diferencaLinhas>0) cont1=1;
        else cont1=-1;
                
                for(int j=1; j < diferencaModulo; j++){
                    if(tab[linha1+cont1*j][coluna1+cont2*j]!='@'){
                        return 0;
                    }
                }

        if(tab[linha1][coluna1]=='B'&& (tab[linha2][coluna2]>'a'||tab[linha2][coluna2]=='@')){
            VERIFICAR_CHECK_REI_PRETO;
            tab[linha2][coluna2]='B';
            tab[linha1][coluna1]='@'; 
            return 1;
        }

        else if(tab[linha1][coluna1]=='b'&&((tab[linha2][coluna2]>'A'&& tab[linha2][coluna2]<'a')||tab[linha2][coluna2]=='@')){
            VERIFICAR_CHECK_REI_BRANCO;
            tab[linha2][coluna2]='b';
            tab[linha1][coluna1]='@'; 
            return 1;
            }
        else return 0;
    }
    else return 0;
}


int moveCavalo(char **tab, char jogada[7]){//supondo que os brancos sempre estejam em baixo
//ex: jogada = "Pf1-c4"
    int linha1 = abs(jogada[2] - '1');
    int coluna1 = abs(jogada[1] - 'a');
    int linha2 = abs(jogada[5] - '1');
    int coluna2 = abs(jogada[4] - 'a');

    if(tab[linha1][coluna1]!='c'&&tab[linha1][coluna1]!='C'){
        return 0;
    }

        if( (abs(linha1-linha2) + abs(coluna1-coluna2)) != 3 )
        return 0;

        if(tab[linha1][coluna1]=='C'&& (tab[linha2][coluna2]>'a'||tab[linha2][coluna2]=='@')){
            VERIFICAR_CHECK_REI_PRETO;
            tab[linha2][coluna2]='C';
            tab[linha1][coluna1]='@'; 
            return 1;
            }

        else if(tab[linha1][coluna1]=='c'&&((tab[linha2][coluna2]>'A'&& tab[linha2][coluna2]<'a')||tab[linha2][coluna2]=='@')){
            VERIFICAR_CHECK_REI_BRANCO;
            tab[linha2][coluna2]='c';
            tab[linha1][coluna1]='@';
            return 1;
            }
        else return 0;

}


int moveDama(char **tab, char jogada[7]){//supondo que os brancos sempre estejam em baixo
//ex: jogada = "Pf1-c4"

    int linha1 = abs(jogada[2] - '1');
    int coluna1 = abs(jogada[1] - 'a');
    int linha2 = abs(jogada[5] - '1');
    int coluna2 = abs(jogada[4] - 'a');
    int diferencaColunas= jogada[4]-jogada[1]; //caso seja bispo
    int diferencaLinhas= jogada[5]-jogada[2];

    if(tab[linha1][coluna1]!='d'&&tab[linha1][coluna1]!='D'){
            return 0;
    }
    if(linha1==linha2||coluna1==coluna2){ //mocvimento de torre
        
        int menor, maior;

        if(coluna1<coluna2){menor = coluna1; maior = coluna2;}
        else {menor=coluna2; maior = coluna1;}

        if(jogada[2]==jogada[5]){ //mesmas linhas
            for(int j=menor+1; j<maior; j++){
                if(tab[linha1][j]!='@'){
                    return 0;
                }
            }
            if(tab[linha1][coluna1]=='D'&& (tab[linha2][coluna2]>'a'||tab[linha2][coluna2]=='@')){
                VERIFICAR_CHECK_REI_PRETO;
                tab[linha2][coluna2]='D';
                tab[linha1][coluna1]='@'; 
                return 1;
            }

            else if(tab[linha1][coluna1]=='d'&&((tab[linha2][coluna2]>'A'&& tab[linha2][coluna2]<'a')||tab[linha2][coluna2]=='@')){
                VERIFICAR_CHECK_REI_BRANCO;
                tab[linha2][coluna2]='d';
                tab[linha1][coluna1]='@'; 
                return 1;
                }
            else return 0;
        }
        else if(jogada[1]==jogada[4]){ //mesmas colunas
            for(int j=menor+1; j<maior; j++){
                if(tab[j][coluna1]!='@'){
                    return 0;
                }
            }
            if(tab[linha1][coluna1]=='D'&& (tab[linha2][coluna2]>'a'||tab[linha2][coluna2]=='@')){
                VERIFICAR_CHECK_REI_PRETO;
                tab[linha2][coluna2]='D';
                tab[linha1][coluna1]='@'; 
                return 1;
                }

            else if(tab[linha1][coluna1]=='d'&&((tab[linha2][coluna2]>'A'&& tab[linha2][coluna2]<'a')||tab[linha2][coluna2]=='@')){
                VERIFICAR_CHECK_REI_BRANCO;
                tab[linha2][coluna2]='d';
                tab[linha1][coluna1]='@'; 
                return 1;
                }
                else return 0;
        }
    }
    else if(diferencaColunas==diferencaLinhas||diferencaColunas==(-1)*diferencaLinhas){
        int diferencaModulo = abs(jogada[2]-jogada[5]);
        int cont1, cont2;
        if(diferencaColunas>0) cont2=1;
        else cont2=-1;

        if(diferencaLinhas>0) cont1=1;
        else cont1=-1;
                
                for(int j=1; j < diferencaModulo; j++){
                    if(tab[linha1+cont1*j][coluna1+cont2*j]!='@'){
                        return 0;
                    }
                }

        if(tab[linha1][coluna1]=='D'&& (tab[linha2][coluna2]>'a'||tab[linha2][coluna2]=='@')){
            VERIFICAR_CHECK_REI_PRETO;
            tab[linha2][coluna2]='D';
            tab[linha1][coluna1]='@'; 
            return 1;
        }

        else if(tab[linha1][coluna1]=='d'&&((tab[linha2][coluna2]>'A'&& tab[linha2][coluna2]<'a')||tab[linha2][coluna2]=='@')){
            VERIFICAR_CHECK_REI_BRANCO;
            tab[linha2][coluna2]='d';
            tab[linha1][coluna1]='@'; 
            return 1;
            }
            else return 0;

    }
    else return 0;
}


int moveRei(char **tab, char jogada[7]){//supondo que os brancos sempre estejam em baixo
//ex: jogada = "Pf1-c4"
    int linha1 = abs(jogada[2] - '1');
    int coluna1 = abs(jogada[1] - 'a');
    int linha2 = abs(jogada[5] - '1');
    int coluna2 = abs(jogada[4] - 'a');

    if(tab[linha1][coluna1]!='r'&&tab[linha1][coluna1]!='R'){
            return 0;
    }

    if((abs(linha1-linha2)==1 && abs(coluna1-coluna2) == 0)||
       (abs(linha1-linha2)==0 && abs(coluna1-coluna2) == 1)||
       (abs(linha1-linha2)==1 && abs(coluna1-coluna2) == 1)){

        if(tab[linha1][coluna1]=='R'&&((tab[linha2][coluna2]>'a')||tab[linha2][coluna2]=='@')){
            VERIFICAR_CHECK_REI_PRETO;
            tab[linha2][coluna2]='R';
            tab[linha1][coluna1]='@';
            return 1;
        }

        else if(tab[linha1][coluna1]=='r'&& ((tab[linha2][coluna2]>'A'&& tab[linha2][coluna2]<'a')||tab[linha2][coluna2]=='@')){
            VERIFICAR_CHECK_REI_BRANCO;
            tab[linha2][coluna2]='r';
            tab[linha1][coluna1]='@';
            return 1;
            }
            else return 0;
    }
    else return 0;
}
