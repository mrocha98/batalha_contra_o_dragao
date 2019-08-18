#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAM_NOME 30+1

typedef struct skill {
    char nome[TAM_NOME];
    int consumoMana;
} SKILL;

typedef struct personagem {
    char nome[TAM_NOME];
    int hp, mana, danoBase, danoCriticoBase, defesa, qtdPocoes;
    SKILL skills[3];
} P;

P dragon, warrior;
int turno = 1, contadorTurno = 1;

int ehTurnoDoGuerreiro(){
    return turno == 1;
}

//posteriormente mudar pra 4, pois o arqueiro e o mago entrarão na brincadeira
int ehTurnoDoDragao(){
    return turno == 2;
}

void anulaPassagemDeTurno(){
    turno--;
    contadorTurno--;
}

void printaDadosDoTurno(){
    char donoDoTurno[TAM_NOME];
    if(ehTurnoDoGuerreiro())
        strcpy(donoDoTurno, warrior.nome);
    else if(ehTurnoDoDragao)
        strcpy(donoDoTurno, dragon.nome);
    printf("TURNO: %d\tVEZ DE: %s\n", contadorTurno, donoDoTurno);
}

int jogaDado(P *personagem){
    int numSorteado = (rand() % 6 + 1);
    printf("Pressione enter para jogar o dado...\t"); setbuf(stdin, NULL); getchar();
    printf("%s jogou o dado e tirou um %d\n", personagem->nome, numSorteado);
    return numSorteado;
}

int tirou6(int n){
    return n == 6;
}

int tirou1(int n){
    return n == 1;
}

void ataque(P *atacante, P *alvo){
    int numSorteado = jogaDado(atacante), dano;
    if(tirou6(numSorteado)){
        dano = abs(atacante->danoBase * numSorteado + atacante->danoCriticoBase - alvo->defesa);
        printf("\tDANO CRITICO!!!!\n");
    }else if(tirou1(numSorteado)){
        dano = 0;
        printf("\tMISS! QUE AZAR!\n");
    }else
        dano = abs(atacante->danoBase * numSorteado - alvo->defesa);
    alvo->hp -= dano;
    printf("%s atacou %s, causando %d de dano!\n\n", atacante->nome, alvo->nome, dano);
}

void usaPocao(P *personagem){
    int numSorteado = jogaDado(personagem);
    int cura = numSorteado * 100;
    int curaBonus = 0;
    if(tirou6(numSorteado)){
        curaBonus = personagem->danoCriticoBase / 2; 
        personagem->hp += cura + curaBonus;
        printf("\tPOCAO ENCANTADA!\tCURA ADICIONAL DE %d\n", curaBonus); 
    }else if(tirou1(numSorteado)){
        cura = 0;
        printf("\tOPS! PARECE QUE A POCAO CAIU NO CHAO!\n");
    }else
        personagem->hp += cura;
    printf("%s recebeu %d de cura!\n", personagem->nome, cura+curaBonus); 
    personagem->qtdPocoes-=1;
}

void bolaDeFogo(P *alvo){
    printf("%s utilizou %s!\n", dragon.nome, dragon.skills[0].nome);
    int danoBaseReal = dragon.danoBase;
    dragon.danoBase += 40;
    ataque(&dragon, &*alvo);
    dragon.danoBase = danoBaseReal;
    dragon.mana = dragon.mana - dragon.skills[0].consumoMana;
}

void ataqueComACauda(P *alvo){
    printf("%s utilizou %s!\n", dragon.nome, dragon.skills[1].nome);
    int danoBaseReal = dragon.danoBase;
    dragon.danoBase += 12;
    ataque(&dragon, alvo);
    dragon.danoBase = danoBaseReal;
    dragon.mana = dragon.mana - dragon.skills[1].consumoMana;
}

void espadaDemoniaca(){
    printf("%s utilizou %s!\n", warrior.nome, warrior.skills[0].nome);
    int danoBaseReal = warrior.danoBase;
    int danoCriticoBaseReal = warrior.danoCriticoBase;
    warrior.danoBase = danoBaseReal + 50;
    warrior.danoCriticoBase = danoCriticoBaseReal + 75;
    ataque(&warrior, &dragon);
    warrior.danoBase = danoBaseReal;
    warrior.danoCriticoBase = danoCriticoBaseReal; 
    warrior.mana = warrior.mana - warrior.skills[0].consumoMana;
}

void ataqueDasMilLaminas(){
    printf("%s utilizou %s!\n", warrior.nome, warrior.skills[1].nome);
    int danoBaseReal = warrior.danoBase;
    int danoCriticoBaseReal = warrior.danoCriticoBase;
    warrior.danoBase = danoBaseReal + 30;
    warrior.danoCriticoBase = danoCriticoBaseReal + 15;
    ataque(&warrior, &dragon);
    warrior.danoBase = danoBaseReal;
    warrior.danoCriticoBase = danoCriticoBaseReal; 
    warrior.mana = warrior.mana - warrior.skills[1].consumoMana;
}

void bencaoDosDeuses(){
    printf("%s utilizou %s!\n", warrior.nome, warrior.skills[2].nome);
    int sorteado = jogaDado(&warrior);
    if(tirou1(sorteado))
        printf("Parece que os deuses nao atenderam suas oracoes... Nada acontece!\n");
    else if(tirou6(sorteado)){
        printf("Os deuses lhe concedem a maior das bencaos!");
        printf("nHP aumentado de %d para %d\n\n", warrior.hp, (warrior.hp + 500));
        warrior.hp += 500;
    }else{
        printf("HP aumentado de %d para ", warrior.hp);
        warrior.hp += sorteado * 50;
        printf("%d\n!", warrior.hp);
    }
    warrior.mana = warrior.mana - warrior.skills[2].consumoMana;
}

int acabou(){
    return (dragon.hp <= 0 || warrior.hp <= 0);
}

int dragaoMorreu(){
    return dragon.hp <= 0;
}

void printaDadosDaSkill(P *personagem, int i){
    printf("[%d]\t-\t%s\t-\tConsome %d de mana\n", i+1, personagem->skills[i].nome, personagem->skills[i].consumoMana);
}

void listaSkills(P *personagem){
    printf("========\t%s SKILLS\t========\n", personagem->nome);
    for(int i = 0; i < 3; i++){
        printaDadosDaSkill(personagem, i);
    }
    printf("===============================\n");
}

void printaDadosDoPersonagem(P *personagem){
    printf("%s\tHP: %d\tMANA: %d\tPocoes de HP: %d\n", personagem->nome, personagem->hp, personagem->mana, personagem->qtdPocoes);
}

void turnoDoDragao(){
    int acao = rand() % 3+1;
    int manaSuficienteBolaDeFogo = dragon.mana >= dragon.skills[0].consumoMana;
    int manaSuficienteAtaqueComACauda = dragon.mana >= dragon.skills[1].consumoMana;
    if(acao == 1 && manaSuficienteBolaDeFogo)
        bolaDeFogo(&warrior);
    else if(acao == 2 && manaSuficienteAtaqueComACauda)
        ataqueComACauda(&warrior);
    else
        ataque(&dragon, &warrior);
}

void txtMenu(){
    printf("1. Checar informacoes do inimigo\n");
    printf("2. Atacar\n");
    printf("3. Usar pocao\n");
    printf("4. Usar Skill\n|\n|>\t");
}

void turnoDoGuerreiro(){
    int n;
    txtMenu(); scanf("%d", &n);
    if(n == 1){
        printaDadosDoPersonagem(&dragon);
        listaSkills(&dragon);
        anulaPassagemDeTurno();
    }else if(n == 2)
        ataque(&warrior, &dragon);
    else if(n == 3){
        if(warrior.qtdPocoes == 0){
            printf("%s nao possui pocoes!\n", warrior.nome);
            anulaPassagemDeTurno();
        }else{
            usaPocao(&warrior);
        }
    }else if(n == 4){
        int skillEscolhida;
        listaSkills(&warrior);
        scanf("%d", &skillEscolhida);
        skillEscolhida--;
        int escolhaInvalida = skillEscolhida > 2 || skillEscolhida < 0;
        if(escolhaInvalida){
            printf("Opcao invalida...\n");
            anulaPassagemDeTurno();
        }else{
            int manaInsuficiente = warrior.mana < warrior.skills[skillEscolhida].consumoMana;
            if(manaInsuficiente){
                printf("%s nao possui mana suficiente para usar essa skill!\n", warrior.nome);
                anulaPassagemDeTurno();
            }else{
                switch(skillEscolhida){
                    case 0:
                        espadaDemoniaca();
                        break;
                    case 1:
                        ataqueDasMilLaminas();
                        break; 
                    case 2:
                        bencaoDosDeuses();
                        break;
                }
            }
        }
    }
    else
        printf("Opcao invalida... %s fica nervoso e perde o turno!\n\n", warrior.nome);
}

void inicializaSkill(P *pers, int index, char nome[], int consumo){
    strcpy(pers->skills[index].nome, nome);
    pers->skills[index].consumoMana = consumo;
}

void inicializaPersonagem(P *pers, int hp, int mana, int dB, int dCB, char nome[], int d, int qP){
    pers->hp = hp;
    pers->mana = mana;
    pers->danoBase = dB;
    pers->danoCriticoBase = dCB;
    strcpy(pers->nome, nome);
    pers->defesa = d;
    pers->qtdPocoes = qP;
}

int main(){
    printf("\n\t\t====================================\n");
    printf("\t\tJOGUIN DO DRAGAO\tVersao Alpha\tBy: Rxa e Leleco\n");
    printf("\t\t====================================\n");
    srand(time(0));
        
    inicializaPersonagem(&dragon, 4000, 1500, 60, 100, "Dragao", 10, 0);
    inicializaSkill(&dragon, 0, "Bola de Fogo", 500);
    inicializaSkill(&dragon, 1, "Ataque com a cauda", 250);

    inicializaPersonagem(&warrior, 2500, 2000, 45, 250, "Guerreiro", 50, (rand()%10+1));
    inicializaSkill(&warrior, 0, "Espada Demoniaca", 350);
    inicializaSkill(&warrior, 1, "Ataque das Mil Laminas", 600);
    inicializaSkill(&warrior, 2, "Bencao dos Deuses", 450);

    printf("Nomeie o guerreiro: "); setbuf(stdin, NULL); scanf("%[^\n]s", warrior.nome);
    printf("Nomeie o dragao: "); setbuf(stdin, NULL); scanf("%[^\n]s", dragon.nome);
    printf("\n\nIniciando partida....\n\n");

    while(!acabou()){
        printaDadosDoTurno();
        printaDadosDoPersonagem(&dragon);
        printaDadosDoPersonagem(&warrior);
        if(ehTurnoDoGuerreiro())
            turnoDoGuerreiro();
        else if(ehTurnoDoDragao())
            turnoDoDragao();
        if(turno == 2)
            turno = 1;
        else
            turno++;
        contadorTurno++;
        getchar();
    }
    if(dragaoMorreu()){
        printf("%s matou %s!\n", warrior.nome, dragon.nome);
        printf("\nParabens! Voce venceu a batalha!\n\n");
    }else{
        printf("%s matou %s!\n", dragon.nome, warrior.nome);
        printf("\nVoce perdeu... Mais sorte na proxima!\n\n");
    }printf("\t\t==========\t\tFIM DE JOGO\t\t==========\t\t\n");
    system("pause");
    return 0;
}