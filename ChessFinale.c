#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 8
#define MOSTRAR_TAB printf("\n   a b c d e f g h");\
                    printf("\n   ---------------");\
                    for(int k=0; k<TAM; k++){\
                        printf("\n");\
                        printf("%d| ", k+1);\
                        for(int j=0; j<TAM; j++){\
                            if(tab[k][j]=='@'){\
                                printf("  ");\
                            }\
                            else{\
                            printf("%c ", tab[k][j]);\
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
                    remove("C:\\Users\\augus\\Desktop\\jogo.bin");\
                    return 0;\
                }\
\
                else if(verificacao==3){\
                    fprintf(jogo, "%s\n", movimento);\
                    printf("As Pretas ganharam!\n");\
                    LIMPA_ALOCACOES;\
                    fclose(jogo);\
                    remove("C:\\Users\\augus\\Desktop\\jogo.bin");\
                    return 0;\
                }

FILE *jogo;
char **tab; //tab eh o tabuleiro [linha/numeros][coluna/letras], as linhas sao invertidas
int main(){
    //isto eh, comeca o 8 e daí, vai pra linha 1    primeiora posicao tab[7][0]
    char **jogada, **jogadaTmp= NULL; //jogada eh a string
    char movimento[7];
    int i=0;
    if( (jogo = fopen("C:\\Users\\augus\\Desktop\\jogo.bin", "a+b")) != NULL){
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

        printf("\nDiga um movimento: ");

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
    int incorreto=0;
    if(tab[jogada[2]-'1'][jogada[1]-'a']!='p'&&tab[jogada[2]-'1'][jogada[1]-'a']!='P'){
        incorreto=1;
    }
        if(jogada[5]-jogada[2]==1||jogada[5]-jogada[2]==-1){ //uma linha pra frente ou pra traz

            if(jogada[4]-jogada[1]==0){ //mesma letra

                if(tab[jogada[5]-'1'][jogada[4]-'a']=='@'){ //note que na string esta invertido linha coluna

                    if(jogada[0]=='P'){
                        if(jogada[5]-jogada[2]==1){
                            tab[jogada[2]-'1'][jogada[1]-'a']='@'; //deixando vazio no lugar que o peao saiu
                            tab[jogada[5]-'1'][jogada[4]-'a']='P';}
                        else {incorreto=1;}
                    } //colocando peao no destino

                    else if(jogada[0]=='p'){
                        if(jogada[5]-jogada[2]==-1){
                            tab[jogada[2]-'1'][jogada[1]-'a']='@';
                            tab[jogada[5]-'1'][jogada[4]-'a']='p';}
                        else {incorreto=1;}
                    } //colocando peao no destino

                }
                else {incorreto=1;}

            }
            else if(jogada[4]-jogada[1]==1||jogada[4]-jogada[1]==-1){ //indo para a direita ou esquerda

                if(tab[jogada[5]-'1'][jogada[4]-'a']!='@'){//peao so move na diagonal se tiver alguem pra comer
                    if(jogada[0]=='P'){
                        VERIFICAR_CHECK_REI_PRETO;
                        tab[jogada[5]-'1'][jogada[4]-'a']='P';
                        tab[jogada[2]-'1'][jogada[1]-'a']='@';}
                    else if(jogada[0]=='p'){
                        VERIFICAR_CHECK_REI_BRANCO;
                        tab[jogada[5]-'1'][jogada[4]-'a']='p';
                        tab[jogada[2]-'1'][jogada[1]-'a']='@';}
                }
                else {incorreto=1;}

            }
            else {incorreto=1;}

        }
        else {incorreto=1;}

    if(incorreto==1){
        return 0;
    }
    else return 1;
}


int moveTorre(char **tab, char jogada[7]){//supondo que os brancos sempre estejam em baixo
//ex: jogada = "Pf1-c4"
    int incorreto=0;
    if(tab[jogada[2]-'1'][jogada[1]-'a']!='t'&&tab[jogada[2]-'1'][jogada[1]-'a']!='T'){
        incorreto=1;
    }
    if(jogada[2]==jogada[5]){ //mesmas linhas
        for(int j=jogada[1]-'a'+1; j<jogada[4]-'a'; j++){
            if(tab[jogada[2]-'1'][j]!='@'){
                incorreto=1;
            }
        }
    }
    else if(jogada[1]==jogada[4]){ //mesmas colunas
        for(int j=jogada[2]-'1'; j<jogada[5]-'a'; j++){
            if(tab[j][jogada[1]-'a']!='@'){
                incorreto=1;
            }
        }
    }
    else incorreto=1;
    if(incorreto==0){
        if(tab[jogada[2]-'1'][jogada[1]-'a']=='T'){
            VERIFICAR_CHECK_REI_PRETO;
            tab[jogada[5]-'1'][jogada[4]-'a']='T';
            tab[jogada[2]-'1'][jogada[1]-'a']='@'; }

        else if(tab[jogada[2]-'1'][jogada[1]-'a']=='t'){
            VERIFICAR_CHECK_REI_BRANCO;
            tab[jogada[5]-'1'][jogada[4]-'a']='t';
            tab[jogada[2]-'1'][jogada[1]-'a']='@'; }
    }
    if(incorreto==1){
        return 0;
    }
    else return 1;
}


int moveBispo(char **tab, char jogada[7]){//supondo que os brancos sempre estejam em baixo
//ex: jogada = "Pf1-c4"
    int incorreto=0;
    int cont1=-1, cont2=-1;
    int diferencaModulo = fabs(jogada[2]-jogada[5]);
    int diferencaHorizontal=jogada[4]-jogada[1]; //se + direita, se - esquerda
    int diferencaVertical=jogada[5]-jogada[2]; //se + sobe, se - desce
    if(tab[jogada[2]-'1'][jogada[1]-'a']!='b'&&tab[jogada[2]-'1'][jogada[1]-'a']!='B'){
        incorreto=1;
    }
    if(jogada[2]-jogada[5]==jogada[1]-jogada[4]||jogada[5]-jogada[2]==jogada[1]-jogada[4]){ //diagonal

        if(diferencaHorizontal>0) cont2=1;
        else cont2=-1;

        if(diferencaVertical>0) cont1=1;
        else cont1=-1;
                
                for(int j=1; j < diferencaModulo; j++){
                    if(tab[jogada[2]-'1'+cont1*j][jogada[1]-'a'+cont2*j]!='@'){
                        incorreto=1;
                    }
                }

        
    }
    if(incorreto==0){
        if(tab[jogada[2]-'1'][jogada[1]-'a']=='B'){
            VERIFICAR_CHECK_REI_PRETO;
            tab[jogada[5]-'1'][jogada[4]-'a']='B';
            tab[jogada[2]-'1'][jogada[1]-'a']='@'; }

        else if(tab[jogada[2]-'1'][jogada[1]-'a']=='b'){
            VERIFICAR_CHECK_REI_BRANCO;
            tab[jogada[5]-'1'][jogada[4]-'a']='b';
            tab[jogada[2]-'1'][jogada[1]-'a']='@'; }
    }
    if(incorreto==1){
        return 0;
    }
    else return 1;
}


int moveCavalo(char **tab, char jogada[7]){//supondo que os brancos sempre estejam em baixo
//ex: jogada = "Pf1-c4"
    int incorreto=0;
    if(tab[jogada[2]-'1'][jogada[1]-'a']!='c'&&tab[jogada[2]-'1'][jogada[1]-'a']!='C'){
        incorreto=1;
    }

    if(incorreto==0){

        if(tab[jogada[2]-'1'][jogada[1]-'a']=='C'){
            VERIFICAR_CHECK_REI_PRETO;
            tab[jogada[5]-'1'][jogada[4]-'a']='C';
            tab[jogada[2]-'1'][jogada[1]-'a']='@'; }

        else if(tab[jogada[2]-'1'][jogada[1]-'a']=='c'){
            VERIFICAR_CHECK_REI_BRANCO;
            tab[jogada[5]-'1'][jogada[4]-'a']='c';
            tab[jogada[2]-'1'][jogada[1]-'a']='@'; }

    }

    if(incorreto==1){
        return 0;
    }
    else return 1;
}


int moveDama(char **tab, char jogada[7]){//supondo que os brancos sempre estejam em baixo
//ex: jogada = "Pf1-c4"
    int incorreto=0;

    int moveTorre(char **tab, char jogada[7]);

    tab[jogada[2]-'1'][jogada[1]-'a']='t';
    int torre = moveTorre(tab, jogada);

    int moveBispo(char **tab, char jogada[7]);

    tab[jogada[2]-'1'][jogada[1]-'a']='b';
    int bispo = moveBispo(tab, jogada);

    if(tab[jogada[2]-'1'][jogada[1]-'a']=='D'){

        if(torre==1){
            tab[jogada[5]-'1'][jogada[4]-'a']='D';
            tab[jogada[2]-'1'][jogada[1]-'a']='@';
        }
        else if(torre==2){ //dama branca so come rei preto
            return 2;
        }
        else if(torre==0){

            if(bispo==1){
                tab[jogada[5]-'1'][jogada[4]-'a']='D';
                tab[jogada[2]-'1'][jogada[1]-'a']='@';
            }
            else if(bispo==2){
                return 2;
            }
        }
    }

    else if(tab[jogada[2]-'1'][jogada[1]-'a']=='d'){

        if(torre==1){
            tab[jogada[5]-'1'][jogada[4]-'a']='d';
            tab[jogada[2]-'1'][jogada[1]-'a']='@';
        }
        else if(torre==3){
            return 3;
        }
        else if(torre==0){
        
            if(bispo==1){
                tab[jogada[5]-'1'][jogada[4]-'a']='d';
                tab[jogada[2]-'1'][jogada[1]-'a']='@';
            }
            else if(bispo==3){
                return 3;
            }
        }
    }
    if(incorreto==1){
        return 0;
    }
    else return 1;
}


int moveRei(char **tab, char jogada[7]){//supondo que os brancos sempre estejam em baixo
//ex: jogada = "Pf1-c4"
    int incorreto=0;
    if(((abs(jogada[5]-jogada[2])==1)||(abs(jogada[5]-jogada[2])==1)==0) &&\
    ((abs(jogada[4]-jogada[1])==1)||(abs(jogada[4]-jogada[1])==1))){

        if(tab[jogada[2]-'1'][jogada[1]-'a']=='R'){
            VERIFICAR_CHECK_REI_PRETO;
            tab[jogada[5]-'1'][jogada[4]-'a']='R';
            tab[jogada[2]-'1'][jogada[1]-'a']='@';}

        else if(tab[jogada[2]-'1'][jogada[1]-'a']=='r'){
            VERIFICAR_CHECK_REI_BRANCO;
            tab[jogada[5]-'1'][jogada[4]-'a']='r';
            tab[jogada[2]-'1'][jogada[1]-'a']='@';}
    }
    else incorreto=1;
    if(incorreto==1){
        return 0;
    }
    else return 1;
}