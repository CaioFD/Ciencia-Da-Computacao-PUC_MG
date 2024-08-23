/*
 *  //--------- Documentação ---------//
 *  
 *  TP03Q01 - 01 / 05 / 2024
 *  Author: Caio Faria Diniz
 *  
*/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// constantes para o número de personagens e o tamanho máximo da fila circular
#define qtPersonagens 100
#define MAXTAM 6

// struct que representa um personagem
    typedef struct Personagem {
        char id[100];
        char name[100];
        char alternate_names[120];
        char house[100];
        char ancestry[100];
        char species[100];
        char patronus[100];
        bool hogwartsStaff;
        bool hogwartsStudent;
        char actorName[100];
        bool alive;
        char dateOfBirth[20];
        int yearOfBirth;
        char eyeColour[100];
        char gender[100];
        char hairColour[100];
        bool wizard;
    } Personagem;

// struct Celula
    typedef struct Celula {
        Personagem *personagem;
        struct Celula *prox;
    } Celula;

// construtor
    Celula *newCelulaC(Personagem *personagem) {
    Celula *nova = (Celula *)malloc(sizeof(Celula));
        if (nova != NULL) {
            nova->personagem = personagem;
            nova->prox = NULL;
        }
        return nova;
    }
Celula *newCelula() { return newCelulaC(NULL); }

// struct Fila
    typedef struct {
        struct Celula *primeiro, *ultimo;
        int tam;
    } FilaCircular;

// construtor
    FilaCircular *newFilaCircular() {
        FilaCircular *temp = (FilaCircular *)malloc(sizeof(FilaCircular));
        Personagem *tmp = NULL;
        temp->primeiro = newCelulaC(tmp);
        temp->ultimo = temp->primeiro;
        temp->tam = 0;
        return temp;
    }

// declaração de variáveis globais
char path[] = "/tmp/characters.csv";


//======FUNOCOES======//


// função que retorna a posição de uma substring dentro de uma string
    int indexOf(char *json, char *str, int index) {
        int tam_str = strlen(str);
        int tam_json = strlen(json);
        int pos = index;
        bool achou = false;
        while (pos < tam_json - tam_str + 1 && !achou) {
            if (strncmp(json + pos, str, tam_str) == 0) {
            achou = true;
            }
            if (!achou) {
            pos++;
            }
        }
        if (!achou) {
            pos = -1;
        }
        return pos;
    }

// função que extrai uma substring de uma string
    void substring(char *dest, char *src, int comeco, int fim) {
        int tamanho = fim - comeco;
        tamanho = abs(tamanho);
        strncpy(dest, src + comeco, tamanho);
        dest[tamanho] = '\0';
    }

// função que converte um caractere em um booleano
    bool trataBool(char c) {
        bool resp = false;
        if (c == 'V') {
            resp = true;
        }
        return resp;
    }

// função que formata os nomes alternativos removendo caracteres desnecessários
    char *trataAlternateName(char alternate_name[]) {
    int tam = strlen(alternate_name);

    for (int i = 0; i < tam; i++) {
        if (alternate_name[i] == '[') {
        alternate_name[i] = '{';
        } else if (alternate_name[i] == ']') {
        alternate_name[i] = '}';
        } else if (alternate_name[i] == '\'') {
        for (int j = i; j < tam - 1; j++) {
            alternate_name[j] = alternate_name[j + 1];
        }
        tam--;
        i--;
        }
    }
    alternate_name[tam] = '\0';
    return alternate_name;
    }

// função que lê os dados de um personagem a partir de uma linha CSV
    void ler(char *csv, Personagem *personagem) {
        char arraytmp[18][300];
        char tmp[300];
        int i = 0;
        int posicao_inicial = 0;
        int posicao;
        while (i < 18) {
            posicao = indexOf(csv, ";", posicao_inicial);
            if (posicao == -1) {
            posicao = strlen(csv) - 1;
            }
            substring(tmp, csv, posicao_inicial, posicao);
            strcpy(arraytmp[i], tmp);
            posicao_inicial = posicao + 1;
            i++;
        }

        strcpy(personagem->id, arraytmp[0]);
        strcpy(personagem->name, arraytmp[1]);
        strcpy(personagem->alternate_names, trataAlternateName(arraytmp[2]));
        strcpy(personagem->house, arraytmp[3]);
        strcpy(personagem->ancestry, arraytmp[4]);
        strcpy(personagem->species, arraytmp[5]);
        strcpy(personagem->patronus, arraytmp[6]);
        personagem->hogwartsStaff = trataBool(arraytmp[7][0]);
        personagem->hogwartsStudent = trataBool(arraytmp[8][0]);
        strcpy(personagem->actorName, arraytmp[9]);
        personagem->alive = trataBool(arraytmp[10][0]);
        strcpy(personagem->dateOfBirth, arraytmp[12]);
        personagem->yearOfBirth = atoi(arraytmp[13]);
        strcpy(personagem->eyeColour, arraytmp[14]);
        strcpy(personagem->gender, arraytmp[15]);
        strcpy(personagem->hairColour, arraytmp[16]);
        personagem->wizard = trataBool(arraytmp[17][0]);
    }

// função que busca um personagem pelo ID no arquivo CSV
    Personagem *buscaID(char id[]) {
        char linha[500];
        bool achou = false;
        FILE *arq;
        Personagem *tmp = (Personagem *)malloc(sizeof(Personagem));
        if ((arq = fopen(path, "r")) != NULL) {
            fgets(linha, sizeof(linha), arq);

            while ((fgets(linha, sizeof(linha), arq)) != NULL && !achou) {
            ler(linha, tmp);
            if (strcmp(tmp->id, id) == 0) {
                achou = true;
            }
            }
        }
        fclose(arq);
        return tmp;
    }

// função que clona uma estrutura Personagem
    Personagem *clone(Personagem *p1) {
        Personagem *tmp = (Personagem *)calloc(1, sizeof(Personagem));
        strcpy(tmp->id, p1->id);
        strcpy(tmp->name, p1->name);
        strcpy(tmp->alternate_names, p1->alternate_names);
        strcpy(tmp->house, p1->house);
        strcpy(tmp->ancestry, p1->ancestry);
        strcpy(tmp->species, p1->species);
        strcpy(tmp->patronus, p1->patronus);
        tmp->hogwartsStaff = p1->hogwartsStaff;
        tmp->hogwartsStudent = p1->hogwartsStudent;
        strcpy(tmp->actorName, p1->actorName);
        tmp->alive = p1->alive;
        strcpy(tmp->dateOfBirth, p1->dateOfBirth);
        tmp->yearOfBirth = p1->yearOfBirth;
        strcpy(tmp->eyeColour, p1->eyeColour);
        strcpy(tmp->gender, p1->gender);
        strcpy(tmp->hairColour, p1->hairColour);
        tmp->wizard = p1->wizard;

        return tmp;
    }

// função que divide uma string em substrings com base em um delimitador
    char **meu_split(char *string, char delimitador) {
        int count = 1;
        for (char *c = string; *c; ++c) {
            count += (*c == delimitador);
        }

        char **substrings = (char **)malloc((count + 1) * sizeof(char));
        if (!substrings) {
            fprintf(stderr, "Erro na alocação de memória\n");
            exit(EXIT_FAILURE);
        }

        int inicio = 0, substring_index = 0;
        for (int i = 0; string[i] != '\0'; ++i) {
            if (string[i] == delimitador || string[i + 1] == '\0') {
            int tamanho_substring = i - inicio + (string[i + 1] == '\0');

            substrings[substring_index] =
                (char *)malloc((tamanho_substring + 1) * sizeof(char));
            if (!substrings[substring_index]) {
                fprintf(stderr, "Erro na alocação de memória\n");
                exit(EXIT_FAILURE);
            }

            strncpy(substrings[substring_index], string + inicio, tamanho_substring);
            substrings[substring_index][tamanho_substring] = '\0';

            inicio = i + 1;
            ++substring_index;
            }
        }

        substrings[substring_index] = NULL;

        return substrings;
    }

// função que imprime os dados de um personagem
    void imprimir(Personagem *p1) {
    printf("[%s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## "
            "%s ## %d ## %s ## %s ## %s ## %s]\n",
            p1->id, p1->name, p1->alternate_names, p1->house, p1->ancestry,
            p1->species, p1->patronus, ((p1->hogwartsStaff) ? "true" : "false"),
            ((p1->hogwartsStudent) ? "true" : "false"), p1->actorName,
            ((p1->alive) ? "true" : "false"), p1->dateOfBirth, p1->yearOfBirth,
            p1->eyeColour, p1->gender, p1->hairColour,
            ((p1->wizard) ? "true" : "false"));
    }

// função que remove um personagem da fila circular
    Personagem *remover(FilaCircular *fila) {
        Personagem *tmp = (Personagem *)malloc(sizeof(Personagem));
        if (fila->tam != 0) {
            Celula *temp = fila->primeiro;
            fila->primeiro = fila->primeiro->prox;
            fila->tam = fila->tam - 1;
            free(temp);
            tmp = fila->primeiro->personagem;
        }
        return tmp;
    }

    void calcularMedia(FilaCircular *fila) {
        if (fila->tam > 0) {
            int soma = 0;
            Celula *atual = fila->primeiro->prox;
            for (int i = 0; i < fila->tam; i++) {
            soma += atual->personagem->yearOfBirth;
            atual = atual->prox;
            }
            double media = (soma / (double)fila->tam);
            int resp = round(media);
            printf(">> Year Birthday Average: %d\n", resp);
        }
    }

// método que insere um personagem na fila circular
    void inserir(FilaCircular *fila, Personagem *personagem) {
        if (fila != NULL && personagem != NULL) {
            if (fila->ultimo->prox == fila->primeiro) {
            Personagem *personagemRemovido = remover(fila);
            free(personagemRemovido);
            }
            fila->ultimo->prox = newCelulaC(personagem);
            fila->ultimo = fila->ultimo->prox;
            fila->tam++;

            if (fila->tam == 5) {
            fila->ultimo->prox = fila->primeiro;
            }
            calcularMedia(fila);
        }
    }

// função que mostra os personagens na fila circular
    void mostrar(FilaCircular *fila) {
        int j = 0;
        Celula *atual = fila->primeiro->prox;
        printf(" [ Head ]");
        while (atual != NULL && j < fila->tam) {
            printf("[%d ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## "
                "%s ## %s ## %d ## %s ## %s ## %s ## %s]\n",
                j, atual->personagem->id, atual->personagem->name,
                atual->personagem->alternate_names, atual->personagem->house,
                atual->personagem->ancestry, atual->personagem->species,
                atual->personagem->patronus,
                ((atual->personagem->hogwartsStaff) ? "true" : "false"),
                ((atual->personagem->hogwartsStudent) ? "true" : "false"),
                atual->personagem->actorName,
                ((atual->personagem->alive) ? "true" : "false"),
                atual->personagem->dateOfBirth, atual->personagem->yearOfBirth,
                atual->personagem->eyeColour, atual->personagem->gender,
                atual->personagem->hairColour,
                ((atual->personagem->wizard) ? "true" : "false"));
            atual = atual->prox;
            j++;
        }
        printf(" [ Tail ]");
    }

//======MAIN======//
    int main() {
        int i = 0;
        char str[100];

        // cria a FilaCircular
        FilaCircular *filaPersonagens = newFilaCircular();

        // lê o primeiro comando ou ID de personagem
        scanf(" %[^\r\n]s", str);

        // loop até que o comando "FIM" seja recebido
        while (strcmp(str, "FIM") != 0) {
            inserir(filaPersonagens,
                    buscaID(str)); // insere o personagem buscado pelo ID
            scanf(" %[^\r\n]s", str);
            getchar();
        }
        int n;

        // lê o número de comandos adicionais
        scanf("%d", &n);

        for (i = 0; i < n; i++) {
            char comando[100];
            scanf(" %[^\r\n]s", comando);
            char **comandos = meu_split(comando, ' '); // divide o comando em partes

            Personagem *tmp;
            if (strcmp(comandos[0], "I") == 0) {
            inserir(filaPersonagens,
                    buscaID(comandos[1])); // insere um novo personagem
            } else if (strcmp(comandos[0], "R") == 0) {
            tmp = remover(filaPersonagens); // remove um personagem
            printf("(R) %s\n", tmp->name);
            }
        }
        mostrar(filaPersonagens);

        return 0;
    }