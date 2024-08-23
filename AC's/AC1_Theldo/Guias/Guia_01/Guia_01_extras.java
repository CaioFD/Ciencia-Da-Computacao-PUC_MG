
/*
    Arquitetura de Computadores I - Guia_01_extras
    793605 - Caio Faria Diniz
*/

public class Guia_01_extras
{
    private static int errors = 0; //conta erros

    public static void test_equals( Object x, Object y ) 
    {
        if ( ( "" + x ).compareTo( "" + y ) != 0 )
            errors = errors + 1;
    }

    public static String test_report( ) //Exibir o total de erros.
    {
        return ( "" + errors );
    }

    public static String dec2bin( int value ) //Converter valor decimal para binario.
    {
        int binary = 0;
        int bit = 0;
        int position = 1;

        while( value > 0 )
        {
            bit = value % 2;
            binary = binary + bit * position;
            value = value / 2;
            position = position * 10;
        } // end while

        return ( Integer.toString( binary ) );
    } 

    public static int bin2dec( String value ) //Converter valor binario para decimal.
    {
        int length = 0;
        int decimal = 0;
        int bit = 0;

        length = value.length();
        for( int x = 0; x < length; x = x + 1 )
        {
            bit = Integer.parseInt(String.valueOf(value.charAt(x)));
            decimal = decimal + bit * (int)Math.pow(2, length-1-x);
        } 

        return ( decimal );
    } 

    public static String dec2base( int value, int base ) //Converter valor decimal para base indicada.
    {
        // int result = 0;
        int bit = 0;
        int position = 1;
        char digit;
        StringBuilder result = new StringBuilder();

        while( value > 0 )
        {
            bit = value % base;
            if( bit > 9 )
            {
                digit = (char)( 'A' + ( bit - 10 ) );
                result.insert( 0, digit );
            }
            else
            {
                result.insert( 0, bit );
            } // end if
            value = value / base;
            position = position * 10;
        } // end for

        return ( result.toString( ) );
    } // end dec2base ( )

    public static String bin2base( String value, int base ) //Converter valor binario para base indicada.
    {
        return ( dec2base( bin2dec( value ) , base ) );
    } // end bin2base ( )

    public static String ASCII2hex( String value ) //Converter valor em ASCII para hexadecimal.
    {
        StringBuilder result = new StringBuilder( );
        int ascii = 0;
        String hex;

        for ( int x = 0; x < value.length() ; x = x + 1 )
        {
            ascii = (int) value.charAt( x );
            hex = dec2base(ascii, 16);
            result.append( hex ).append( " " );
        }
        return ( result.toString( ) );
    }

    public static String hex2ASCII( String value ) //Converter valor em hexadecimal para ASCII.
    {
        return ("0");
    } // end hex2ASCII ( )

 // --------- MAIN  --------- //
    public static void main( String[] args ) 
    {
        System.out.println( "Guia_01 - Java Tests "                );
        System.out.println( "793605 - Caio Faria Diniz " );
        System.out.println( );

        test_equals( dec2bin( 26  ), "11010"      );
        test_equals( dec2bin( 53  ), "110101"     );
        test_equals( dec2bin( 713 ), "1011001001" );
        test_equals( dec2bin( 213 ), "11010101"  );
        test_equals( dec2bin( 365 ), "101101101"  );
        System.out.println("1. errorTotalReport = " + test_report());

        test_equals( bin2dec( "10101"  ), 21 );
        test_equals( bin2dec( "11011"  ), 27 );
        test_equals( bin2dec( "10010"  ), 18 );
        test_equals( bin2dec( "101011" ), 43 );
        test_equals( bin2dec( "110111" ), 55 );
        System.out.println("2. errorTotalReport = " + test_report());
        
        test_equals( dec2base( 61 , 4  ), "331" );
        test_equals( dec2base( 53 , 8  ), "65"   );
        test_equals( dec2base( 77 , 16 ), "4D"   );
        test_equals( dec2base( 153, 16 ), "99"   );
        test_equals( dec2base( 753, 16 ), "2F1"  );
        System.out.println("3. errorTotalReport = " + test_report());

        test_equals( bin2base( "10100" , 4  ), "110" );
        test_equals( bin2base( "11010" , 8  ), "32"  );
        test_equals( bin2base( "100111", 16 ), "27"  );
        test_equals( bin2base( "100101", 8  ), "45"  );
        test_equals( bin2base( "101101", 4  ), "231" );
        System.out.println("4. errorTotalReport = " + test_report());

        test_equals( ASCII2hex( "PUC-M.G." ), "50 55 43 2D 4D 2E 47 2E " );
        test_equals( ASCII2hex( "2024-02"  ), "32 30 32 34 2D 30 32 "    );
        test_equals( ASCII2hex( "Belo Horizonte" ), 
        "0100 0010  0110 0101  0110 1100  0110 1111 0100 1000  0110 1111  0111 0010  0110 1001  0111 1010  0110 1111  0110 1110  0111 0100  0110 0101" );
        test_equals(hex2ASCII("156 157 151 164 145"), "noite");
        test_equals( hex2ASCII( "4D 61 6E 68 61" ), "Manha" ); 
        System.out.println( "5. errorTotalReport = " + test_report( ) );

        System.out.print( "\n\nApertar ENTER para terminar." );
        try {
            System.console( ).readLine( );
            
        } catch ( Exception e ) {
            System.err.println( "Erro: leitura invalida." );
        }
    } // end main
} // end class
