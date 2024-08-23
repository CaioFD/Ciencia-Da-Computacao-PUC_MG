/*
 *  //--------- Documentação ---------//
 *  
 *  TP03Q01 - 29 / 05 / 2024
 *  Author: Caio Faria Diniz
 *  
*/

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.time.format.DateTimeFormatter;



class Pilha {
    private Personagem[] personagem;
    private int tamanho;


    public Pilha () {
        this.personagem = null;
        this.tamanho = 0;
    }


    public Pilha (int tamanho){
        if( tamanho > 0 ){
            this.personagem = new Personagem[tamanho];
            this.tamanho = 0;
        }
    }


    public void inserirFim ( Personagem perso ) throws Exception{
        if( this.tamanho >= personagem.length ) {
            throw new Exception( "ERRO: Nao foi possivel inserir (fim)!" );
        } // end if
        this.personagem[this.tamanho] = perso;
        this.tamanho++;
    } // end inserirFim ( )


    public Personagem removerFim() throws Exception {
        if (this.tamanho == 0) {
            throw new Exception("ERRO: Lista Vazia!");
        }
        this.tamanho--;
        Personagem perso = this.personagem[this.tamanho];
        this.personagem[this.tamanho] = null; // Limpar referência
        return perso;
    }


    public void mostrar ( ){
        int y = 0;
        System.out.println("[ Top ]");
        for( int i = this.tamanho ; i > 0; i = i - 1 )
        {
            this.personagem[i].imprimir( y );
            y++;
        } // end for
        System.out.println("[ Bottom ]");
    } // end mostrar ( )



} // end class Lista

//-------Classe Personagem-------//

class Personagem 
{

    //-------Atributos-------//

    
    private String    id  ; 
    private String    name  ; 
    private String[]  alternateNames  ; 
    private String    house ; 
    private String    ancestry ; 
    private String    species ; 
    private String    patronus ; 
    private Boolean   hogwartsStaff ;  
    private Boolean   hogwartsStudent ;  
    private String    actorName ; 
    private Boolean   alive ;
    private String[]  alternateActors ;
    private LocalDate dateOfBirth ; 
    private int       yearOfBirth ; 
    private String    eyeColour  ; 
    private String    gender ; 
    private String    hairColour  ; 
    private Boolean   wizard  ; 


    // ---------------- Construtores -------------------//

    
    Personagem ( )
    {
        this.id  = "" ;              
        this.name  = "" ;            
        this.alternateNames  = null  ; 
        this.house  = "" ;           
        this.ancestry  = ""  ;        
        this.species  = "" ;         
        this.patronus  = "" ;        
        this.hogwartsStaff   = false ;   
        this.hogwartsStudent = false ; 
        this.actorName = "" ;       
        this.alive  = false ;
        this.alternateActors = null ;           
        this.dateOfBirth = LocalDate.of(-1, 1, 1);
        this.yearOfBirth = -1 ;     
        this.eyeColour  = "" ;       
        this.gender = "" ;          
        this.hairColour = "" ;      
        this.wizard   = false ;          
    } 


    Personagem ( String    id         , String  name         , String[]  alternateNames , 
                 String    house      , String  ancestry     , String    species        , 
                 String    patronus   , Boolean hogwartsStaff, Boolean   hogwartsStudent, 
                 String    actorName  , Boolean alive        , String[]  alternateActors,
                 LocalDate dateOfBirth, int     yearOfBirth  , String    eyeColour      , 
                 String    gender     , String  hairColour   , Boolean   wizard )
    {
        this.id  = id ;
        this.name  = name ;
        this.alternateNames  = alternateNames  ;
        this.house  = house  ;
        this.ancestry  = ancestry ;
        this.species  = species ;
        this.patronus  = patronus ;
        this.hogwartsStaff = hogwartsStaff ;
        this.hogwartsStudent = hogwartsStudent ;
        this.actorName = actorName ;
        this.alive  = alive ;
        this.alternateActors = alternateActors ;
        this.dateOfBirth = dateOfBirth ;
        this.yearOfBirth  = yearOfBirth  ;
        this.eyeColour  = eyeColour  ;
        this.gender  = gender  ;
        this.hairColour  = hairColour  ;
        this.wizard  = wizard ;
    } 

    //--------- GET ---------//

    public String getId( ) 
    { 
        return ( this.id );
    }

    public String getName( ) 
    { 
        return ( this.name); 
    }

    public String[] getAlternateNames  ( ) 
    { 
        return ( this.alternateNames ); 
    }

    public String[] getAlternateActors  ( ) 
    { 
        return ( this.alternateActors ); 
    }

    public String getHouse( ) 
    { 
        return ( this.house ); 
    }

    public String getAncestry( ) 
    { 
        return ( this.ancestry ); 
    }

    public String getSpecies( ) 
    { 
        return ( this.species ); 
    }

    public String getPatronus( ) 
    { 
        return ( this.patronus ); 
    }

    public Boolean getHogwartsStaff( ) 
    { 
        return ( this.hogwartsStaff ); 
    }

    public Boolean getHogwartsStudent( ) 
    {
        return ( this.hogwartsStudent ); 
    }

    public String getActorName( ) 
    { 
        return ( this.actorName ); 
    }

    public Boolean getAlive( ) 
    { 
        return ( this.alive ); 
    }

    public LocalDate getDateOfBirth( ) 
    { 
        return ( this.dateOfBirth ); 
    }

    public int getYearOfBirth( ) 
    { 
        return ( this.yearOfBirth ); 
    }

    public String getEyeColour( ) 
    { 
        return ( this.eyeColour ); 
    }

    public String getGender( ) 
    { 
        return ( this.gender ); 
    }

    public String getHairColour( ) 
    { 
        return ( this.hairColour ); 
    }

    public Boolean getWizard( ) 
    { 
        return ( this.wizard ); 
    }

    
   //--------- SET ---------//
    

    public void setId( String id ) 
    { 
        this.id = id ; 
    }

    public void setName( String name ) 
    { 
        this.name = name ; 
    }

    public void setAlternateNames( String[] alternateNames ) 
    { 
        this.alternateNames  = alternateNames ; 
    }

    public void setAlternateActors( String[] alternateActors ) 
    { 
        this.alternateActors  = alternateActors ; 
    }

    public void setHouse( String house )
    {
        this.house  = house ; 
    }

    public void setAncestry( String ancestry ) 
    { 
        this.ancestry = ancestry ; 
    }

    public void setSpecies( String species ) 
    {
        this.species  = species  ; 
    }

    public void setPatronus( String patronus ) 
    { 
        this.patronus = patronus ; 
    }

    public void setHogwartsStaff( Boolean hogwartsStaff ) 
    { 
        this.hogwartsStaff  = hogwartsStaff ; 
    }

    public void setHogwartsStudent( Boolean hogwartsStudent ) 
    { 
        this.hogwartsStudent = hogwartsStudent ; 
    }
    
    public void setActorName( String actorName ) 
    { 
        this.actorName = actorName ; 
    }

    public void setAlive( Boolean alive ) 
    {
        this.alive  = alive ; 
    }

    public void setDateOfBirth( LocalDate dateOfBirth ) 
    { 
        this.dateOfBirth = dateOfBirth ; 
    }

    public void setYearOfBirth( int yearOfBirth ) 
    { 
        this.yearOfBirth  = yearOfBirth ; 
    }
    
    public void setEyeColour( String eyeColour ) 
    { 
        this.eyeColour = eyeColour ; 
    }

    public void setGender( String gender ) 
    { 
        this.gender = gender ; 
    }

    public void setHairColour( String hairColour ) 
    { 
        this.hairColour = hairColour ; 
    }

    public void setWizard( Boolean wizard ) 
    { 
        this.wizard = wizard ; 
    }
    
    public void set(String    id         , String  name         , String[] alternateNames , 
    String    house      , String  ancestry     , String   species        , 
    String    patronus   , Boolean hogwartsStaff, Boolean  hogwartsStudent, 
    String    actorName  , Boolean alive        , String[] alternateActors,
    LocalDate dateOfBirth, int     yearOfBirth  , String   eyeColour      , 
    String    gender     , String  hairColour   , Boolean  wizard)
{
setId              ( id );
setName            ( name );
setAlternateNames  ( alternateNames );
setHouse           ( house );
setAncestry        ( ancestry );
setSpecies         ( species );
setPatronus        ( patronus );
setHogwartsStaff   ( hogwartsStaff );
setHogwartsStudent ( hogwartsStudent );
setActorName       ( actorName );
setAlive           ( alive );
setAlternateActors ( alternateActors );
setDateOfBirth     ( dateOfBirth );
setYearOfBirth     ( yearOfBirth );
setEyeColour       ( eyeColour );
setGender          ( gender );
setHairColour      ( hairColour );
setWizard          ( wizard );
} //end
    
   //--------- Métodos Uteis ---------//

    public String[] tratamentoArrayString ( String str ) 
    {  
        String [] array = null;
        if( str == null ) {
            array = null;
        }
        else
        {
            String tratada = "";
            for( int x = 0; x < str.length( ); x = x + 1 )
            {
                if( str.charAt(x) == '[' ) {
                    tratada = tratada + '{';
                } else if( str.charAt(x) == ']' ) {
                    tratada = tratada + '}';
                } else if ( str.charAt(x) == '\'' ) {
                    tratada = tratada + "";
                } else {
                    tratada = tratada + str.charAt(x);
                }
            } 
            array = tratada.split( "," );
        } 
        return ( array );
    } // end


    public LocalDate tratamentoDate ( String str ) 
    {        
        return ( LocalDate.parse( str, DateTimeFormatter.ofPattern("dd-M-yyyy") ) );
    }


    public Boolean tratamentoBool( String str )
    {
        if( str.equals("VERDADEIRO") || str.equals("true") || str.equals("1") )
            return ( true );
        else
            return ( false );
    }


    public int tratamentoInt( String str ) {
        return ( Integer.parseInt( str ) );
    }


    public String altNamesToString ( ) 
    {
        String result = "";
        if( alternateNames == null ) {
            result = "{}";
        }
        else
        {
            for( int x = 0; x < this.alternateNames.length; x++ )
            {
                if( x < this.alternateNames.length-1 ) {
                    result = result + this.alternateNames[x] + ",";
                }
                else {        
                    result = result + this.alternateNames[x];
                }
            } 
        } 
        return( result );
    }


    public String dateBirthToString ( )
    {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");
        String date = this.dateOfBirth.format(formatter);
        return ( date );
    }
    
    //--------- Metodos Gerais ---------//



    public static boolean isFim( String s )
    {
        boolean result = false;
        if( s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M' )
        {
            result = true;
        }
        return ( result );
    } 

    @Override
    public String toString( ) 
    {
        String toString = "";
        toString =  getId         ( ) + " ## " + getName         ( ) + " ## " + altNamesToString  ( ) + " ## " + 
                    getHouse      ( ) + " ## " + getAncestry     ( ) + " ## " + getSpecies        ( ) + " ## " + 
                    getPatronus   ( ) + " ## " + getHogwartsStaff( ) + " ## " + getHogwartsStudent( ) + " ## " + 
                    getActorName  ( ) + " ## " + getAlive        ( ) + " ## " + dateBirthToString ( ) + " ## " + 
                    getYearOfBirth( ) + " ## " + getEyeColour    ( ) + " ## " + getGender         ( ) + " ## " + 
                    getHairColour ( ) + " ## " + getWizard       ( ); 
		return ( toString );
	} 


    public Personagem clone ( ) //clona um personagem
    {
        Personagem clone = new Personagem( );
        clone.setId             ( getId() );       
        clone.setName           ( getName() );         
        clone.setAlternateNames ( getAlternateNames() );  
        clone.setHouse          ( getHouse() );           
        clone.setAncestry       ( getAncestry() );        
        clone.setSpecies        ( getSpecies() );         
        clone.setPatronus       ( getPatronus() );        
        clone.setHogwartsStaff  ( getHogwartsStaff() );   
        clone.setHogwartsStudent( getHogwartsStudent() );
        clone.setActorName      ( getActorName() );       
        clone.setAlive          ( getAlive() );           
        clone.setDateOfBirth    ( getDateOfBirth() );     
        clone.setYearOfBirth    ( getYearOfBirth() );     
        clone.setEyeColour      ( getEyeColour() );       
        clone.setGender         ( getGender() );          
        clone.setHairColour     ( getHairColour() );      
        clone.setWizard         ( getWizard() );
        return ( clone );
    } //end



    public void imprimir ( )
    {
        System.out.println( "[" + toString( ) + "]" );
    } // end imprimir ( )

    /**
     *  Metodo para imprimir personagem.
     */
    public void imprimir ( int x )
    {
        System.out.println( "[" + x + " ## " + toString( ) + "]" );
    } // end imprimir ( )


    public Personagem ler ( String id )//ler atributos
    {
        Personagem perso = new Personagem( );
        String path = "/tmp/characters.csv";
        try 
        { 
            File file = new File( path );
            Scanner scan = new Scanner( file );
            
            scan.nextLine( ); 
            
            boolean found = false;
            while( scan.hasNextLine() && !found )
            {
                String input = scan.nextLine( );
                if( id.equals( input.substring( 0, input.indexOf( ";" ) ) ) )
                {
                    found = true;
                    String [] atributos = input.split( ";" );
                    perso.set(  atributos[0], atributos[1], tratamentoArrayString(atributos[2]),
                                atributos[3], atributos[4], atributos[5], atributos[6],
                                tratamentoBool(atributos[7]), tratamentoBool(atributos[8]), atributos[9], 
                                tratamentoBool(atributos[10]), tratamentoArrayString(atributos[11]),
                                tratamentoDate(atributos[12]) , tratamentoInt(atributos[13]),
                                atributos[14],atributos[15], atributos[16], tratamentoBool(atributos[17])  );
                } 
            } 

            if( !found ) {
                System.out.println( "Character Not Found." );
            } 

            scan.close( );
        } 
        catch( FileNotFoundException e ) {
            System.out.println( "ERROR: File Not Found." );
        } 
        return ( perso );
    } 

}//end class


public class PilhaSequencial extends Personagem
{
    public static void main ( String [] args ) throws Exception
    {
        Scanner scan = new Scanner( System.in );
        Personagem perso = new Personagem( );
        Pilha lista = new Pilha( 405 );
        // fazer a leitura dos dados
        String input = scan.nextLine( );
        while( !isFim( input ) )
        {
            lista.inserirFim( perso.ler( input ) );
            input = scan.nextLine( );
        } // end while
        // fazer a leitura dos metodos 
        while( scan.hasNextLine() ) 
        {
            input = scan.nextLine( );
            String[] str = input.split( " " );
            Personagem outro;
            try 
            {
                switch( str[0] ) 
                {
                    case "I":
                        outro = perso.ler( str[1] );
                        lista.inserirFim( outro );
                        break;
                    case "R":
                        outro = lista.removerFim( );
                        System.out.println( "(R) " + outro.getName( ) );
                        break;
                    default:
                        break;
                } // end switch 
            } catch( Exception e ) {
                e.getMessage();
            } // end try catch
        } // end while
        lista.mostrar( );
        scan.close( );
    }
}//end main