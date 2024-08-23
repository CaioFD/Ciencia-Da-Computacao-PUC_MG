/*
 *  //--------- Documentação ---------//
 *  
 *  TP02Q01 - 23 / 06 / 2024
 *  Author: Caio Faria Diniz
 *  
*/

//--------- Bibliotecas ---------//
import java.util.*;
import java.io.*;
import java.text.*;

//--------- class personagem ---------//
class Personagem {

    // Atributos
    private String id;
    private String name;
    private List <String> alternate_names;
    private String house;
    private String ancestry;
    private String species;
    private String patronus;
    private boolean hogwartsStaff;
    private String hogwartsStudent;
    private String actorName;
    private boolean alive;
    private Date dateOfBirth;
    private int yearOfBirth;
    private String eyeColour;
    private String gender;
    private String hairColour;
    private boolean wizard;
    DateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy");

  //--------- constructor ---------//
    Personagem( ) {
        id = "";
        name = "";
        alternate_names = null;
        house = "";
        ancestry = "";
        species = "";
        patronus = "";
        hogwartsStaff = false;
        hogwartsStudent = "";
        actorName = "";
        alive = false;
        dateOfBirth = new Date( );
        yearOfBirth = 0;
        eyeColour = "";
        gender = "";
        hairColour = "";
        wizard = false;
    }

    // constructor secundario
    Personagem( String id ) {
        this.id = id;
        name = "";
        alternate_names = null;
        house = "";
        ancestry = "";
        species = "";
        patronus = "";
        hogwartsStaff = false;
        hogwartsStudent = "";
        actorName = "";
        alive = false;
        dateOfBirth = new Date( );
        yearOfBirth = 0;
        eyeColour = "";
        gender = "";
        hairColour = "";
        wizard = false;
    }

  //--------- MÉTODOS GET E SET ---------//
  public void setId( String id ) {
    this.id = id;
}

public String getId( ) {
    return this.id;
}

public void setName( String name ) {
    this.name = name;
}

public String getName( ) {
    return this.name;
}

public void setAlternate_names( List <String> alternate_names ) {
    this.alternate_names = alternate_names;
}

public List <String> getAlternate_names( ) {
    return this.alternate_names;
}

public void setHouse( String house ) {
    this.house = house;
}

public String getHouse( ) {
    return this.house;
}

public void setAncestry( String ancestry ) {
    this.ancestry = ancestry;
}

public String getAncestry( ) {
    return this.ancestry;
}

public void setSpecies( String species ) {
    this.species = species;
}

public String getSpecies( ) {
    return this.species;
}

public void setPatronus( String patronus ) {
    this.patronus = patronus;
}

public String getPatronus( ) {
    return this.patronus;
}

public void setHogwartsStaff( boolean hogwartsStaff ) {
    this.hogwartsStaff = hogwartsStaff;
}

public boolean getHogwartsStaff( ) {
    return this.hogwartsStaff;
}

public void setHogwartsStudent( String hogwartsStudent ) {
    this.hogwartsStudent = hogwartsStudent;
}

public String getHogwartsStudent( ) {
    return this.hogwartsStudent;
}

public void setActorName( String actorName ) {
    this.actorName = actorName;
}

public String getActorName( ) {
    return this.actorName;
}

public void setAlive( boolean alive ) {
    this.alive = alive;
}

public boolean getAlive( ) {
    return this.alive;
}

public void setDateOfBirth( Date dateOfBirth ) {
    this.dateOfBirth = dateOfBirth;
}

public Date getDateOfBirth( ) {
    return this.dateOfBirth;
}

public void setYearOfBirth( int yearOfBirth ) {
    this.yearOfBirth = yearOfBirth;
}

public int getYearOfBirth( ) {
    return this.yearOfBirth;
}

public void setEyeColour( String eyeColour ) {
    this.eyeColour = eyeColour;
}

public String getEyeColour( ) {
    return this.eyeColour;
}

public void setGender( String gender ) {
    this.gender = gender;
}

public String getGender( ) {
    return this.gender;
}

public void setHairColour( String hairColour ) {
    this.hairColour = hairColour;
}

public String getHairColour( ) {
    return this.hairColour;
}

public void setWizard( boolean wizard ) {
    this.wizard = wizard;
}

public boolean getWizard( ) {
    return this.wizard;
}

//--------- IMPRIMIR ---------//
public void imprimir( ) {
    String alternateNamesString = "";
    if ( alternate_names != null ) {
        alternateNamesString = alternate_names.toString()
                                    .replace("'", "")
                                    .replace("[[", "{")
                                    .replace("]]", "}");
    }

    System.out.println( "[" + id + " ## " + name + " ## " + alternateNamesString + " ## " + house + " ## " + ancestry
    + " ## " + species + " ## " + patronus + " ## " + hogwartsStaff + " ## " + hogwartsStudent + " ## "
    + actorName + " ## " + alive + " ## " + dateFormat.format(dateOfBirth) + " ## " + yearOfBirth + " ## " + eyeColour + " ## "
    + gender + " ## " + hairColour + " ## " + wizard + "]" );
}

// ---- clonagem ---- //
public Personagem clone ( )
{
    Personagem clone = new Personagem( );
    clone.setId             ( getId              ( ) );       
    clone.setName           ( getName            ( ) );         
    clone.setAlternate_names ( getAlternate_names  ( ) );  
    clone.setHouse          ( getHouse           ( ) );           
    clone.setAncestry       ( getAncestry        ( ) );        
    clone.setSpecies        ( getSpecies         ( ) );         
    clone.setPatronus       ( getPatronus        ( ) );        
    clone.setHogwartsStaff  ( getHogwartsStaff   ( ) );   
    clone.setHogwartsStudent( getHogwartsStudent ( ) );
    clone.setActorName      ( getActorName       ( ) );       
    clone.setAlive          ( getAlive           ( ) );           
    clone.setDateOfBirth    ( getDateOfBirth     ( ) );     
    clone.setYearOfBirth    ( getYearOfBirth     ( ) );     
    clone.setEyeColour      ( getEyeColour       ( ) );       
    clone.setGender         ( getGender          ( ) );          
    clone.setHairColour     ( getHairColour      ( ) );      
    clone.setWizard         ( getWizard          ( ) );
    return ( clone );
} // clone ( )

// ---- ler ---- //
public void leitor( String s ) throws ParseException {
    // definir dados
    String[] array = s.split(";");
    String mago;
    String vivo;
    String equipe;
    String estudante;

    id = array[0];
    name = array[1];
    alternate_names = Arrays.asList(array[2].split(",")); 
    house = array[3];
    ancestry = array[4];
    species = array[5];
    patronus = array[6];

    equipe = array[7];
    if(equipe.equals("VERDADEIRO")) {
        hogwartsStaff = true;
    } else {
        hogwartsStaff = false;
    }

    estudante = array[8];
    if(estudante.equals("VERDADEIRO")) {
        hogwartsStudent = "true";
    } else {
        hogwartsStudent = "false";
    }

    actorName = array[9];

    vivo = array[10];
    if(vivo.equals("VERDADEIRO")) {
        alive = true;
    } else {
        alive = false;
    }

    dateOfBirth = dateFormat.parse(array[12]);
    yearOfBirth = Integer.parseInt(array[13]);
    eyeColour = array[14];
    gender = array[15];
    hairColour = array[16];

    mago = array[17];

    if(mago.equals("VERDADEIRO")) {
        wizard = true;
    } else {
        wizard = false;
    }
}
}

//==== CLASS HASH ====//
class Hash {
    Personagem tabela[];
    int tam, n;
    public Hash() {
        this(21);
    }
    public Hash(int tam) {
        this.tam = tam;
        this.n = 0;
        this.tabela = new Personagem[tam];
        for(int i = 0; i < tam; i++) {
            this.tabela[i] = null;
        }
    }
    private int asciiValue(String x) {
        int resp = 0;
        for(int i = 0; i < x.length(); i++) {
            resp += (int)x.charAt(i);
        }
        return resp;
    }
    private int hashing(String x) {
        return asciiValue(x) % tam;
    }
    private int hashing2(String x) {
        return (asciiValue(x) + 1) % tam;
    }

    public void inserir(Personagem x) throws Exception {
        if(n == tam) {
            return;
        } 
        int pos = hashing(x.getName());
        if(tabela[pos] == null) {
            tabela[pos] = x;
            n++;
        } else {
            pos = hashing2(x.getName());
            if(tabela[pos] == null) {
                tabela[pos] = x;
                n++;
            }
        }
    }

    public void mostrar() {
        for(int i = 0; i < tam; i++) {
            if(tabela[i] != null) {
                tabela[i].imprimir();
            }
        }
    }

    public boolean pesquisar(String x) {
        System.out.print(x + " ");
        boolean resp = false;
        for(int i = 0; i < tam; i++) {
            if(tabela[i] != null) {
                if(x.equals(tabela[i].getName())) {
                    resp = true;
                    System.out.print("(pos: " + i + ") ");
                }
            }
        }
        return resp;
    }
}

class HashReserva {
    public static void main( String args[] ) throws Exception {
        RandomAccessFile raf = new RandomAccessFile( "/tmp/characters.csv", "r" );
        String str = raf.readLine();
        Personagem[] personagens = new Personagem[500];
        for (int i = 0; i < personagens.length; i++) {
            personagens[i] = new Personagem();
        }
        int i = 0;
        String entrada;
        Scanner sc = new Scanner(System.in);
        while(!EOF(raf)) {
            str = raf.readLine();
            personagens[i].leitor( str );
            i = i + 1;
        }
        Hash hash = new Hash();
        do {
            entrada = sc.nextLine();
            if( !entrada.equals("FIM") ) {
                for( int j = 0; j < personagens.length; j = j + 1 ) {
                    if( personagens[j].getId().equals( entrada ) ) {
                        hash.inserir(personagens[j]);
                    }
                }
            }

        } while( !entrada.equals("FIM") );
        boolean resp;
        do {
            entrada = sc.nextLine();
            if( !entrada.equals("FIM") ) {
                resp = hash.pesquisar(entrada);
                if(resp == true) {
                    System.out.println("SIM");
                } else {
                    System.out.println("NAO");
                }
            }
        } while ( !entrada.equals("FIM") );
        sc.close();
    }

    public static boolean EOF( RandomAccessFile raf ) throws Exception {
        return( raf.getFilePointer() == raf.length() );
    }
}