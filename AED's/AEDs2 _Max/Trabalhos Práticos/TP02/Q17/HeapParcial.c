/*
 *  //--------- Documentação ---------//
 *  
 *  TP02Q01 - 27 / 04 / 2024
 *  Author: Caio Faria Diniz
 *  
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <wchar.h>   
#include <locale.h>

// ---------------------------------- Struct Timer

typedef struct s_Timer
{
    clock_t startTime;
    clock_t endTime  ;
    double  totalTime;
} Timer;

Timer new_Timer( )
{
    Timer timer;
    timer.startTime = 0;
    timer.endTime = 0;
    timer.totalTime = 0;
    return ( timer );
} // end new_Timer ( )

void start_Timer( Timer* time ) {
    time->startTime = clock( );
} // end startTime ( )

void end_Timer( Timer* time ) {
    time->endTime = clock( );
} // end endTime ( )

double total_Timer( Timer* time ) {
    time->totalTime = difftime( time->endTime, time->startTime ) * 1000;
    return ( time->totalTime );
} // end timeTotal ( )

// ---------------------------------- Struct Log

typedef struct s_Log
{
    int comparacoes;
    int movimentacoes;
} Log;

Log new_Log( )
{
    Log log;
    log.movimentacoes = 0;
    log.comparacoes = 0;
    return ( log ); 
} // end new_Log ( )

void registro( char* filename, Timer* time, Log* log )
{
    FILE *file = fopen( filename, "wt" );
    fprintf( file, "793605\tComparacoes: %d\tMovimentacoes: %d\tTempo de Execucao(ms): %lf\n",
                        log->comparacoes, log->movimentacoes, total_Timer( time ) );
    fclose( file );
} // end registro ( )

// ---------------------------------- Struct Pesonagem

typedef struct s_Personagem
{
    char*   id              ; 
    char*   name            ; 
    char*   alternateNames  ;
    char*   house           ; 
    char*   ancestry        ; 
    char*   species         ; 
    char*   patronus        ; 
    bool    hogwartsStaff   ;  
    bool    hogwartsStudent ;  
    char*   actorName       ; 
    bool    alive           ;
    char*   alternateActors ; 
    char*   dateOfBirth     ; 
    int     yearOfBirth     ; 
    char*   eyeColour       ; 
    char*   gender          ; 
    char*   hairColour      ; 
    bool    wizard          ; 
} Personagem;

// ---------------------------------- Funções


bool exist_Personagem( Personagem *perso )
{
    bool exist = false;
    if( perso != NULL && 
        perso->id != NULL && perso->name != NULL && perso->alternateNames != NULL && perso->house != NULL &&
        perso->ancestry != NULL && perso->species != NULL && perso->patronus != NULL && perso->actorName != NULL &&
        perso->alternateActors != NULL && perso->dateOfBirth != NULL && perso->eyeColour != NULL && 
        perso->gender != NULL && perso->hairColour != NULL )
    {
        exist = true;
    } 
    return ( exist );
} 


Personagem* new_Personagem( void )
{
    Personagem *perso = (Personagem*) malloc ( 1 * sizeof(Personagem) );
    if( perso != NULL )
    {
        perso->id              = (char*) calloc (  50, sizeof(char) );
        perso->name            = (char*) calloc (  50, sizeof(char) );
        perso->alternateNames  = (char*) calloc ( 300, sizeof(char) );
        perso->house           = (char*) calloc (  50, sizeof(char) );
        perso->ancestry        = (char*) calloc (  50, sizeof(char) );
        perso->species         = (char*) calloc (  50, sizeof(char) );
        perso->patronus        = (char*) calloc (  50, sizeof(char) );
        perso->hogwartsStaff   = false                               ; 
        perso->hogwartsStudent = false                               ; 
        perso->actorName       = (char*) calloc (  50, sizeof(char) );
        perso->alive           = false                               ; 
        perso->alternateActors = (char*) calloc ( 255, sizeof(char) );
        perso->dateOfBirth     = (char*) calloc (  50, sizeof(char) );
        perso->yearOfBirth     = -1                                  ; 
        perso->eyeColour       = (char*) calloc (  50, sizeof(char) );
        perso->gender          = (char*) calloc (  50, sizeof(char) );
        perso->hairColour      = (char*) calloc (  50, sizeof(char) );
        perso->wizard          = false                               ; 

        if( !exist_Personagem( perso ) )
        {
            printf( "\n%s\n", "ERROR: Unable to alloc memory for \'Personagem\'." );
        } 
    } 
    return ( perso );
} 


void delete_Personagem( Personagem *perso ) // desaloca memoria
{
    if( perso != NULL )
    {
        if( exist_Personagem( perso ) ) 
        {
            free( perso->id ); 
            perso->id  = NULL;

            free( perso->name );
            perso->name = NULL;

            free( perso->alternateNames ); 
            perso->alternateNames = NULL;

            free( perso->house ); 
            perso->house  = NULL;

            free( perso->ancestry  ); 
            perso->ancestry  = NULL;

            free( perso->species  ); 
            perso->species = NULL;

            free( perso->patronus ); 
            perso->patronus  = NULL;

            free( perso->actorName  ); 
            perso->actorName = NULL;

            free( perso->alternateActors ); 
            perso->alternateActors = NULL;

            free( perso->dateOfBirth ); 
            perso->dateOfBirth = NULL;

            free( perso->eyeColour ); 
            perso->eyeColour = NULL;
        }
        free( perso ); perso = NULL;  
    } 
} 

//--------- GET ---------//

char* getId( Personagem *perso ) 
{ 
    return ( perso->id ); 
}

char* getName( Personagem *perso ) 
{ 
    return ( perso->name ); 
}

char* getAlternateNames( Personagem *perso ) 
{ 
    return ( perso->alternateNames  ); 
}

char* getHouse( Personagem *perso ) 
{ 
    return ( perso->house           ); 
}

char* getAncestry ( Personagem *perso ) 
{
    return ( perso->ancestry); 
}

char* getSpecies( Personagem *perso ) 
{ 
    return ( perso->species ); 
}

char* getPatronus( Personagem *perso ) 
{ 
    return ( perso->patronus ); 
}

bool  getHogwartsStaff( Personagem *perso ) 
{
    return ( perso->hogwartsStaff   ); 
}

bool  getHogwartsStudent( Personagem *perso ) 
{ 
    return ( perso->hogwartsStudent ); 
}

char* getActorName( Personagem *perso ) 
{ 
    return ( perso->actorName ); 
}

bool  getAlive( Personagem *perso ) 
{ 
    return ( perso->alive ); 
}

char* getAlternateActors( Personagem *perso ) 
{ 
    return ( perso->alternateActors ); 
}

char* getDateOfBirth( Personagem *perso ) 
{ 
    return ( perso->dateOfBirth ); 
}

int   getYearOfBirth( Personagem *perso ) 
{ 
    return ( perso->yearOfBirth ); 
}

char* getEyeColour( Personagem *perso ) 
{ 
    return ( perso->eyeColour); 
}

char* getGender( Personagem *perso ) 
{ 
    return ( perso->gender  ); 
}

char* getHairColour( Personagem *perso ) 
{ 
    return ( perso->hairColour ); 
}

bool  getWizard( Personagem *perso ) 
{ 
    return ( perso->wizard  ); 
}


    //--------- SET ---------//


void setId( Personagem *perso, char* id ) 
{ 
    strcpy( perso->id , id ) ; 
}

void setName( Personagem *perso, char* name ) 
{ 
    strcpy( perso->name , name ) ; 
}

void setAlternateNames( Personagem *perso, char* alternateNames  ) 
{ 
    strcpy( perso->alternateNames , alternateNames ) ; 
} 

void setHouse( Personagem *perso, char* house ) 
{ 
    strcpy( perso->house , house ) ; 
}

void setAncestry( Personagem *perso, char* ancestry ) 
{ 
    strcpy( perso->ancestry , ancestry ) ; 
}

void setSpecies( Personagem *perso, char* species ) 
{ 
    strcpy( perso->species , species ) ; 
}

void setPatronus( Personagem *perso, char* patronus) 
{ 
    strcpy( perso->patronus  , patronus ) ; 
}

void setHogwartsStaff( Personagem *perso, bool  hogwartsStaff ) 
{         
    perso->hogwartsStaff  = hogwartsStaff ; 
}

void setHogwartsStudent( Personagem *perso, bool  hogwartsStudent ) 
{         
    perso->hogwartsStudent = hogwartsStudent ; 
}

void setActorName( Personagem *perso, char* actorName ) 
{ 
    strcpy( perso->actorName , actorName ) ; 
}

void setAlive( Personagem *perso, bool  alive ) 
{         
    perso->alive = alive ; 
}

void setAlternateActors( Personagem *perso, char* alternateActors ) 
{ 
    strcpy( perso->alternateActors , alternateActors) ; 
}

void setDateOfBirth( Personagem *perso, char* dateOfBirth ) 
{ 
    strcpy( perso->dateOfBirth , dateOfBirth ) ; 
}

void setYearOfBirth( Personagem *perso, int   yearOfBirth     ) 
{         
    perso->yearOfBirth = yearOfBirth ; 
}

void setEyeColour( Personagem *perso, char* eyeColour ) 
{ 
    strcpy( perso->eyeColour , eyeColour ) ; 
}

void setGender ( Personagem *perso, char* gender ) 
{ 
    strcpy( perso->gender  , gender  ) ; 
}

void setHairColour( Personagem *perso, char* hairColour      ) 
{ 
    strcpy( perso->hairColour , hairColour ) ; 
}

void setWizard( Personagem *perso, bool  wizard ) 
{         
    perso->wizard  = wizard  ; 
}


void init_Personagem ( Personagem *perso,
                        char* id             , char* name       , char* alternateNames , char* house          , 
                        char* ancestry       , char* species    , char* patronus       , bool  hogwartsStaff  ,
                        bool  hogwartsStudent, char* actorName  , bool  alive          , char* alternateActors, 
                        char* dateOfBirth    , int   yearOfBirth, char* eyeColour      , char* gender         , 
                        char* hairColour     , bool wizard )
{
    if( exist_Personagem( perso ) ) 
    {
        setId              ( perso, id              );
        setName            ( perso, name            );
        setAlternateNames  ( perso, alternateNames  );
        setHouse           ( perso, house           );
        setAncestry        ( perso, ancestry        );
        setSpecies         ( perso, species         );
        setPatronus        ( perso, patronus        );
        setHogwartsStaff   ( perso, hogwartsStaff   );
        setHogwartsStudent ( perso, hogwartsStudent );
        setActorName       ( perso, actorName       );
        setAlive           ( perso, alive           );
        setAlternateActors ( perso, alternateActors );
        setDateOfBirth     ( perso, dateOfBirth     );
        setYearOfBirth     ( perso, yearOfBirth     );
        setEyeColour       ( perso, eyeColour       );
        setGender          ( perso, gender          );
        setHairColour      ( perso, hairColour      );
        setWizard          ( perso, wizard          );
    }
    else {
        printf( "\n%s\n", "ERROR: Unable to inicialize the \'Personagem\'." );
    } 
} 


Personagem* clone( Personagem *perso )
{
    Personagem *copy = new_Personagem( );
    if( exist_Personagem ( perso ) && exist_Personagem( copy ) )
    {
        init_Personagem(copy,
                        getId              ( perso ),
                        getName            ( perso ),
                        getAlternateNames  ( perso ),
                        getHouse           ( perso ),
                        getAncestry        ( perso ),
                        getSpecies         ( perso ),
                        getPatronus        ( perso ),
                        getHogwartsStaff   ( perso ),
                        getHogwartsStudent ( perso ),
                        getActorName       ( perso ),
                        getAlive           ( perso ),
                        getAlternateActors ( perso ),
                        getDateOfBirth     ( perso ),
                        getYearOfBirth     ( perso ),
                        getEyeColour       ( perso ),
                        getGender          ( perso ),
                        getHairColour      ( perso ),
                        getWizard          ( perso )  );
    } 
    else {
        printf( "\n%s\n", "ERROR: Unable to clone the \'Personagem\'." );    
    }
    return ( copy );
} 


void imprimir ( Personagem *perso )
{
    printf( "[%s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %d ## %s ## %s ## %s ## %s]\n",
            getId              ( perso ),
            getName            ( perso ),
            getAlternateNames  ( perso ),
            getHouse           ( perso ),
            getAncestry        ( perso ),
            getSpecies         ( perso ),
            getPatronus        ( perso ),
            getHogwartsStaff   ( perso ) ? "true" : "false",
            getHogwartsStudent ( perso ) ? "true" : "false",
            getActorName       ( perso ),
            getAlive           ( perso ) ? "true" : "false",
            getDateOfBirth     ( perso ),
            getYearOfBirth     ( perso ),
            getEyeColour       ( perso ),
            getGender          ( perso ),
            getHairColour      ( perso ),
            getWizard          ( perso ) ? "true" : "false" ); 
} 


char* tratamentoBool( char* strbool )
{
    char* tratada = strbool;
    tratada[strcspn(tratada,"\n")] = '\0';
    tratada[strcspn(tratada,"\r")] = '\0';
    return ( tratada );
} 


char* tratamentoData( char* dateOfBirth )
{
    char *tratada = dateOfBirth;
    int len = strlen( dateOfBirth );
    if( len < 10 )
    {
        tratada = (char*) calloc ( 11, sizeof(char) );
        strcpy( tratada, dateOfBirth );
        for( int x = len; x > 3; x = x - 1 )
        {
            tratada[x] = tratada[x-1];
        }
        tratada[3] = '0';
    } 
    return ( tratada );
}


Personagem* ler( char* filename, char* id_procurado ) 
{
    Personagem *perso = new_Personagem( );
    FILE* file = fopen( filename, "rt" );

    if( file == NULL || !exist_Personagem( perso ) ) {
        printf( "\n%s\n", "ERROR: Unable to read.");
    }
    else
    {
        char line[500];
        bool idFound = false;

        
        fgets( line, sizeof(line), file );
        while( fgets( line, sizeof(line), file ) != NULL && !idFound ) 
        {
            char* token = strtok( line, ";" );
            char *atributos[18];
            int index = 0;
            while( token != NULL ) 
            {
                atributos[index++] = strdup( token );
                token = strtok( NULL, ";" );
            }

            char temp[500] = {0};
            int pos = 0;
            int len = strlen( atributos[2] );
            for( int x = 0; x < len; x = x + 1 ) 
            {
                if( atributos[2][x] == '[' ) {
                    temp[pos] = '{';
                } else if( atributos[2][x] == ']' ) {
                    temp[pos] = '}';
                } else if( atributos[2][x] == '\'' ) {
                    continue; 
                } else {
                    temp[pos] = atributos[2][x];
                }
                pos++; 
            }
            temp[pos] = '\0'; 
            free( atributos[2] ) ; atributos[2] = strdup(temp);

            if( strcmp(atributos[0], id_procurado) == 0 ) 
            {
                idFound = true;
                if( index < 18 )
                {
                    if( index > 16 ) 
                    {
                        init_Personagem(perso,
                                        atributos[0], atributos[1], atributos[2], atributos[3],
                                        atributos[4], atributos[5], "" ,
                                 strcmp(tratamentoBool(atributos[6]), "VERDADEIRO") == 0,
                                 strcmp(tratamentoBool(atributos[7]), "VERDADEIRO") == 0,
                                        atributos[8], 
                                 strcmp(tratamentoBool(atributos[9]), "VERDADEIRO") == 0,
                                        atributos[10], 
                         tratamentoData(atributos[11]),
                                   atoi(atributos[12]), 
                                        atributos[13], atributos[14],atributos[15], 
                                 strcmp(tratamentoBool(atributos[16]), "VERDADEIRO") == 0 );
                    } 
                    else
                    {
                        init_Personagem(perso,
                                        atributos[0], atributos[1], atributos[2], atributos[3],
                                        atributos[4], atributos[5], "" ,
                                 strcmp(tratamentoBool(atributos[6]), "VERDADEIRO") == 0,
                                 strcmp(tratamentoBool(atributos[7]), "VERDADEIRO") == 0, "", 
                                 strcmp(tratamentoBool(atributos[8]), "VERDADEIRO") == 0,
                                        atributos[9],
                         tratamentoData(atributos[10]),
                                   atoi(atributos[11]), atributos[12], 
                                        atributos[13],atributos[14], 
                                 strcmp(tratamentoBool(atributos[15]), "VERDADEIRO") == 0 );
                    } // end if
                }
                else
                {
                    init_Personagem(perso,
                                    atributos[0], atributos[1], atributos[2], atributos[3],
                                    atributos[4], atributos[5], atributos[6],
                             strcmp(tratamentoBool(atributos[7]), "VERDADEIRO") == 0,
                             strcmp(tratamentoBool(atributos[8]), "VERDADEIRO") == 0,
                                    atributos[9], 
                             strcmp(tratamentoBool(atributos[10]), "VERDADEIRO") == 0,
                                    atributos[11], 
                     tratamentoData(atributos[12]),
                               atoi(atributos[13]), 
                                    atributos[14], atributos[15],
                                    atributos[16], 
                             strcmp(tratamentoBool(atributos[17]), "VERDADEIRO") == 0 );
                } 
            } 

            for (int x = 0; x < index; x++) {
                free(atributos[x]);
            } 
        } 
        fclose(file);
    } 
    return ( perso );
}

void swap ( int i, int j, Personagem **perso )
{
    Personagem *temp = perso[i];
    perso[i] = perso[j];
    perso[j] = temp;
} 

int compareHairColour( Personagem* perso1, Personagem* perso2 )
{
    int result = 0;
    char* str1 = getHairColour( perso1 );
    char* str2 = getHairColour( perso2 );
    if( strcmp( str1, str2 ) < 0 ) { 
        result = -1;
    } 
    else if( strcmp( str1, str2 ) > 0  ) {
        result = 1;
    } 
    else // d1 == d2 
    {
        if( strcmp( getName( perso1 ), getName( perso2 ) ) < 0 ) { 
            result = -1;
        } 
        else { 
            result = 1;
        } 
    } 
    return ( result );
} 

void construir( Personagem** perso, int length, Log* log ) 
{
    for( int i = length; i > 1 && compareHairColour( perso[i], perso[i/2] ) > 0; i /= 2 ) {
        swap( i, i/2, perso );
        log->movimentacoes += 3;
    } 
} 

int getMaiorFilho( Personagem** perso, int i, int length, Log* log )
{
    int filho;
    if( 2*i == length || compareHairColour( perso[2*i], perso[2*i+1] ) > 0 ) {
        filho = 2*i;
        log->comparacoes++;
    } 
    else {
        filho = 2*i + 1;
        log->comparacoes++;
    } 
    return ( filho );
} 

void reconstruir( Personagem** perso, int length, Log* log )
{
    int i = 1;
    while( i <= (length/2) )
    {
        int filho = getMaiorFilho( perso, i, length, log );
        if( compareHairColour( perso[i], perso[filho] ) < 0 ) 
        {
            swap( i, filho, perso );
            log->movimentacoes += 3;
            log->comparacoes++;
            i = filho;
        }
        else {
            i = length;
            log->comparacoes++;
        } 
    } 
} 

void heapsort( Personagem** perso, int length, int k, Log* log ) 
{
    Personagem* arrayTmp[length+1];
    for( int i = 0; i < length; i = i + 1 ) {
        arrayTmp[i+1] = perso[i];
        log->movimentacoes++;
    } 

    for( int tamHeap = 2; tamHeap <= length; tamHeap++ ) {
        construir( arrayTmp, tamHeap, log );
    } 

    int tamHeap = length;
    while( tamHeap > 1 )
    {
        swap( 1, tamHeap--, arrayTmp );
        log->movimentacoes += 3; 
        reconstruir( arrayTmp, tamHeap, log );
    } 

    for(int i = 0; i < length; i = i + 1){ 
        log->movimentacoes++; 
        perso[i] = arrayTmp[i+1];
    } 
}


int main ( void )
{
    setlocale( LC_CTYPE, "UTF-8" ); 

    Personagem* perso[100] = { NULL };
    Timer timer = new_Timer ( );
    Log   log   = new_Log   ( );

    char id  [81] = { '\0' };
    char nome[81] = { '\0' };
    char* filename = "/tmp/characters.csv"; 
    
    scanf( "%s", id ); getchar( );
    int tam = 0;
    while( strcmp( id,"FIM" ) != 0 )
    {
        perso[tam] = ler( filename, id );
        tam++;
        scanf( "%s", id ); getchar( );
    } 

    start_Timer( &timer );
    heapsort( perso, tam, 10, &log );
    end_Timer( &timer );
    registro( "793605_heapsortParcial.txt", &timer, &log );
    
    for( int x = 0; x < 10; x = x + 1 ) {
        imprimir( perso[x] );
        delete_Personagem( perso[x] );
    } 

    return ( 0 );
} // end main 
