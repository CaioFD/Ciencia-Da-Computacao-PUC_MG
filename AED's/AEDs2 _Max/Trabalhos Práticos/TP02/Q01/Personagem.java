/*
 *  //--------- Documentação ---------//
 *  
 *  TP02Q01 - 12 / 04 / 2024
 *  Author: Caio Faria Diniz
 *  
*/

import java.time.LocalDate;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.time.format.DateTimeFormatter;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.time.ZoneId;

public class Personagem 
{
    //--------- Atributos ---------//

    private String    id              ; 
    private String    name            ; 
    private String[]  alternateNames  ; 
    private String    house           ; 
    private String    ancestry        ; 
    private String    species         ; 
    private String    patronus        ; 
    private Boolean   hogwartsStaff   ;  
    private Boolean   hogwartsStudent ;  
    private String    actorName       ; 
    private Boolean   alive           ;
    private String[]  alternateActors ;
    private LocalDate dateOfBirth     ; 
    private int       yearOfBirth     ; 
    private String    eyeColour       ; 
    private String    gender          ; 
    private String    hairColour      ; 
    private Boolean   wizard          ; 

    //--------- Constructors ---------//

    Personagem ( ){
        this.id              = "" ;              
        this.name            = "" ;            
        this.alternateNames  = null ; 
        this.house           = "" ;           
        this.ancestry        = "" ;        
        this.species         = "" ;         
        this.patronus        = "" ;        
        this.hogwartsStaff   = false ;   
        this.hogwartsStudent = false ; 
        this.actorName       = "" ;       
        this.alive           = false ;
        this.alternateActors = null  ;           
        this.dateOfBirth     = LocalDate.of(-1, 1, 1);
        this.yearOfBirth     = -1 ;     
        this.eyeColour       = "" ;       
        this.gender          = "" ;          
        this.hairColour      = "" ;      
        this.wizard          = false ;          
    } //end

    Personagem ( String    id         , String  name         , String[]  alternateNames , 
                String    house      , String  ancestry     , String    species        , 
                String    patronus   , Boolean hogwartsStaff, Boolean   hogwartsStudent, 
                String    actorName  , Boolean alive        , String[]  alternateActors,
                LocalDate dateOfBirth, int     yearOfBirth  , String    eyeColour      , 
                String    gender     , String  hairColour   , Boolean   wizard )
    {
        this.id              = id ;
        this.name            = name  ;
        this.alternateNames  = alternateNames ;
        this.house           = house ;
        this.ancestry        = ancestry ;
        this.species         = species ;
        this.patronus        = patronus ;
        this.hogwartsStaff   = hogwartsStaff ;
        this.hogwartsStudent = hogwartsStudent ;
        this.actorName       = actorName ;
        this.alive           = alive ;
        this.alternateActors = alternateActors ;
        this.dateOfBirth     = dateOfBirth ;
        this.yearOfBirth     = yearOfBirth ;
        this.eyeColour       = eyeColour ;
        this.gender          = gender ;
        this.hairColour      = hairColour ;
        this.wizard          = wizard ;
    } //end


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

    public void setYearOfBirth( int YearOfBirth ) 
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
    
    //--------- Metodos SET Alternate ---------//

    public void setAlternateNames( String  alternateNames  ) 
    {  
        if( alternateNames == null ) {
            this.alternateNames = null;
        }
        else
        {
            String tratada = "";
            for( int p = 0, x = 0; x < alternateNames.length( ); x = x + 1 )
            {
                if( alternateNames.charAt(x) == '[' ) {
                    tratada = tratada + '{';
                } else if( alternateNames.charAt(x) == ']' ) {
                    tratada = tratada + '}';
                } else if ( alternateNames. charAt(x) == '\'' ) {
                    tratada = tratada + "";
                } else {
                    tratada = tratada + alternateNames.charAt(x);
                } 
            } 
            
            this.alternateNames = tratada.split( "," );
        } 
    } 

    public void setAlternateActors(String alternateActors  ) 
    {  
        if( alternateActors == null ) {
            this.alternateActors = null;
        }
        else
        {
            String tratada = "";
            for( int p = 0, x = 0; x < alternateActors.length(); x = x + 1 )
            {
                if( alternateActors.charAt(x) == '[' ) {
                    tratada = tratada + '{';
                } else if( alternateActors.charAt(x) == ']' ) {
                    tratada = tratada + '}';
                } else if ( alternateActors.charAt(x) == '\'' ) {
                    tratada = tratada + "";
                } else {
                    tratada = tratada + alternateActors.charAt(x);
                } 
            } 
            this.alternateActors = tratada.split( "," );
        }
    }

        //--------- Metodos SET Boolean ---------//

    public void setHogwartsStaff( String hogwartsStaff ) 
    { 
        if( hogwartsStaff.equals("VERDADEIRO") || hogwartsStaff.equals("true") || hogwartsStaff.equals("1") ) 
            setHogwartsStaff(true); 
        else
            setHogwartsStaff(false); 
    }


    public void setHogwartsStudent( String hogwartsStudent ) 
    { 
        if( hogwartsStudent.equals("VERDADEIRO") || hogwartsStudent.equals("true") || hogwartsStudent.equals("1") ) 
            setHogwartsStudent(true); 
        else 
            setHogwartsStudent(false); 
    }


    public void setAlive( String alive ) 
    { 
        if( alive.equals("VERDADEIRO") || alive.equals("true") || alive.equals("1") ) 
            setAlive(true); 
        else 
            setAlive(false); 
    }


    public void setDateOfBirth( String dateOfBirth ) 
    {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-M-yyyy");
        //SimpleDateFormat formatter = new SimpleDateFormat("dd-MM-yyyy");
        LocalDate dob = LocalDate.parse( dateOfBirth, formatter );
        this.dateOfBirth = dob;
    }


    public void setYearOfBirth( String yearOfBirth ) 
    { 
        this.yearOfBirth = Integer.parseInt(yearOfBirth); 
    }


    public void setWizard ( String wizard ) 
    { 
        if( wizard.equals("VERDADEIRO") || wizard.equals("true") || wizard.equals("1") ) 
            setWizard(true); 
        else 
            setWizard(false); 
    }


    public void set(String    id         , String  name         , String  alternateNames , 
                    String    house      , String  ancestry     , String  species        , 
                    String    patronus   , String  hogwartsStaff, String  hogwartsStudent, 
                    String    actorName  , String  alive        , String  alternateActors,
                    String    dateOfBirth, String  yearOfBirth  , String  eyeColour      , 
                    String    gender     , String  hairColour   , String  wizard)
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

    //--------- Metodos Auxiliares ---------//

    public static boolean isFim( String s )//verifica se a entrada é igual a "FIM" 
    {
        boolean result = false;
        if( s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M' )
        {
            result = true;
        }
        return ( result );
    }//end

    
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
    } //end


        //--------- Metodos Padroes ---------//

    @Override
    public String toString( ) // retorna os atributos de um objeto em forma de string
    {
        String toString = "";
        toString =  getId         ( ) + " ## " + getName         ( ) + " ## " + altNamesToString  ( ) + " ## " + 
                    getHouse      ( ) + " ## " + getAncestry     ( ) + " ## " + getSpecies        ( ) + " ## " + 
                    getPatronus   ( ) + " ## " + getHogwartsStaff( ) + " ## " + getHogwartsStudent( ) + " ## " + 
                    getActorName  ( ) + " ## " + getAlive        ( ) + " ## " + getDateOfBirth    ( ) + " ## " + 
                    getYearOfBirth( ) + " ## " + getEyeColour    ( ) + " ## " + getGender         ( ) + " ## " + 
                    getHairColour ( ) + " ## " + getWizard       ( ); 
		return ( toString );
	} //end


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

    

    public void imprimir ( )//imprime os personagens
    {
        System.out.println( "[" + toString( ) + "]" );
    }//end 


    public void ler ( String id )// ler atributos
    {
        String input = "";
        String path = "/tmp/characters.csv";
        // String path = C:\Users\caiod\OneDrive\Área de Trabalho\PROGRAMING\Algoritimo e Estrutura de Dados 2 - Max\Trabalhos Práticos\TP02\Q01\\characters.csv";
        try 
        { 
            File file = new File( path );
            Scanner scan = new Scanner( file );
            
            scan.nextLine( ); 

            if( scan.hasNextLine( ) )
            {
                boolean found = false;
                while( scan.hasNextLine() && !found )
                {
                    input = scan.nextLine( );
                    if( id.equals( input.substring( 0, input.indexOf( ";" ) ) ) )
                    {
                        found = true;
                        String [] atributos = input.split( ";" );
                        set(atributos[0], atributos[1], atributos[2], atributos[3], atributos[4], atributos[5], 
                            atributos[6], atributos[7], atributos[8], atributos[9], atributos[10], atributos[11], 
                            atributos[12], atributos[13], atributos[14], atributos[15], atributos[16], atributos[17]);
                    } 
                } 
                if( !found ) {
                    System.out.println( "Character Not Found!" );
                } 
            } 
            scan.close( );
        } 
        catch( FileNotFoundException e ) {
            System.out.println( "ERROR: File Not Found!" );
        } 
    } //end


        //--------- Main ---------//

    public static void main(String[] args) 
    {
        String input = "";
        Scanner scan = new Scanner( System.in );
        Personagem personagem = new Personagem( );
        do
        {
            input = scan.nextLine( );
            if( !isFim( input ) )
            {
                personagem.ler( input );
                personagem.imprimir( );
            } 
        } while ( !isFim( input ) ); 
    }

} //end 
