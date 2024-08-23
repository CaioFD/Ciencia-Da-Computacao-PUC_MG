
/* import java.io.RandomAccessFile;

public class Q8
{
    
    private static int n = 0;

    public static void main ( String[] args )
    {
        MyIO.setCharset("UTF-8");
        double input = 0.0;
        String filename = "ARQUIVO.TXT";

        n = MyIO.readInt();

        for( int x = 0; x < n; x = x + 1 )
        {
            input = MyIO.readDouble();
            writeDoubleToFile(input, filename);
        } // end for

        readDoubleFromFile( filename );
    } // end main ( )

    public static void writeDoubleToFile( double input, String filename )
    {
        try 
        {
            RandomAccessFile file = new RandomAccessFile( filename, "rw" );
            file.seek( file.length() );
            file.writeDouble( input );
            file.close();
        } 
        catch( Exception e )
        {
            MyIO.println( "ERRO: " + e.getMessage() );
        } // end try catch
    } // end writeDoubleToFile ( )

    public static void readDoubleFromFile( String filename )
    {
        double value = 0.0;
        try 
        {
            RandomAccessFile file = new RandomAccessFile( filename, "r" );
            for( int pointer = (int)file.length()-8; pointer >= 0; pointer = pointer - 8 )
            {
                file.seek(pointer);
                value = file.readDouble();
                if( value - (int)value == 0 )
                {  
                    MyIO.println( (int)value );
                }
                else{
                    MyIO.println( value );
                } // end if
            } // end for
            file.close();
        } 
        catch( Exception e )
        {
            MyIO.println( "ERRO: " + e.getMessage() );
        } // end try catch
    } // end readDoubleToFile ( )

} 
*/



import java.io.RandomAccessFile;
public class Q8{
    public static void main (String[] args) throws Exception{
        int n = MyIO.readInt();
            RandomAccessFile saida = new RandomAccessFile("saida.txt", "rw");
                for(int x = 0; x < n; x++){
                double valor = MyIO.readDouble();
                saida.writeDouble(valor);
        }
            int length = (int) saida.getFilePointer();
            saida.close();

            saida = new RandomAccessFile("saida.txt", "r");
        
        for(int x = 8; x < length; x+=8){
            saida.seek(length-x);
            double aux = saida.readDouble();
                if(aux%1 == 0){
                MyIO.println((int) aux);
            }
            else
                MyIO.println(aux);
            }
        }
}
