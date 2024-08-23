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

// declaração de variáveis globais
    Personagem *array[MAXTAM + 1];
        int primeiro, ultimo;
        int n;
        char path[] = "/tmp/characters.csv";

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

//======funcoes======//
    void substring(char *dest, char *src, int comeco, int fim) {
        int tamanho = fim - comeco;
        tamanho = abs(tamanho);
        strncpy(dest, src + comeco, tamanho);
        dest[tamanho] = '\0';
    }

    bool trataBool(char c) {
    bool resp = false;
        if (c == 'V') {
            resp = true;
        }
    return resp;
    }


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


    void start() { primeiro = ultimo = 0; }

    Personagem *remover() {
    if (primeiro == ultimo)
        exit(1);
    Personagem *resp = array[primeiro];
    primeiro = (primeiro + 1) % MAXTAM;
    return resp;
}


    int calcularAnoNascimentoMedio() {
        int somaAnoNascimento = 0;
        int count = 0;
        for (int i = primeiro; i != ultimo; i = (i + 1) % MAXTAM) {
            somaAnoNascimento += array[i]->yearOfBirth;
            count++;
        }
        return (count == 0) ? 0 : round((float)somaAnoNascimento / count);
    }


    void inserir(Personagem *x) {
        if (((ultimo + 1) % MAXTAM) == primeiro) {
            Personagem *tmp = remover();
        }

        array[ultimo] = clone(x);
        ultimo = (ultimo + 1) % MAXTAM;

        int mediaAlturas = 0;
        mediaAlturas = calcularAnoNascimentoMedio();
        if (mediaAlturas != 0)
            printf(">> Year Birthday Average: %d\n", mediaAlturas);
    }


    void mostrar() {
        int j = 0;
        printf(" [ Head ]");
        for (int i = primeiro; i != ultimo; i = (i + 1) % MAXTAM, j++) {
            printf("[%d ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## "
                "%s ## %s ## %d ## %s ## %s ## %s ## %s]\n",
                j, array[i]->id, array[i]->name, array[i]->alternate_names,
                array[i]->house, array[i]->ancestry, array[i]->species,
                array[i]->patronus, ((array[i]->hogwartsStaff) ? "true" : "false"),
                ((array[i]->hogwartsStudent) ? "true" : "false"),
                array[i]->actorName, ((array[i]->alive) ? "true" : "false"),
                array[i]->dateOfBirth, array[i]->yearOfBirth, array[i]->eyeColour,
                array[i]->gender, array[i]->hairColour,
                ((array[i]->wizard) ? "true" : "false"));
        }
    printf(" [ Tail ]");
    }

//======MAIN======//
    int main() {
    int i = 0;
    char str[100];

    scanf(" %[^\r\n]s", str);


    while (strcmp(str, "FIM") != 0) {
        inserir(buscaID(str));
        scanf(" %[^\r\n]s", str);
        getchar();
        i++;
    }
    int n;


    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        char comando[100];
        scanf(" %[^\r\n]s", comando);
        char **comandos = meu_split(comando, ' '); 

        Personagem *tmp;
        if (strcmp(comandos[0], "I") == 0) {
        inserir(buscaID(comandos[1])); 
        } else if (strcmp(comandos[0], "R") == 0) {
        tmp = remover();
        printf("(R) %s\n", tmp->name);
        }
    }
    mostrar(); 

    return 0;
    }