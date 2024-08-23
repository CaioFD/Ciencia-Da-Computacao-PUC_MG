/*
    Arquitetura de Computadores I - Guia_01
    793605 - Caio Faria Diniz
*/

module Guia_0105;

    integer x = 0; // decimal
    reg [0:7][7:0]  a = "PUC-M.G."    ; // char array[3] (3x8 bits - little Endian)
    reg [0:7][7:0]  b = "2024-02"     ;
    reg [0:11][7:0] c = "Belo Horizonte";
    reg [0:4][7:0]  d = { 8'o156, 8'o157, 8'o151, 8'o164, 8'o145 };
    reg [0:4][7:0]  e = { 8'h4D, 8'h61, 8'h6E, 8'h68, 8'h61 };

    initial begin : main
    $display ( "Guia_0105b\n" );

    $write ( "a = \"%s\" = " , a);
    for ( x = 0; x < 7; x = x + 1 ) begin
        $write ( "%h " , a[x] );
    end
    $write( "(16_ASCII)\n" );

    $write ( "b = \"%s\" = " , b );
    for ( x = 0; x < 8; x = x + 1 ) begin
        $write ( "%h " , b[x] );
    end
    $write( "(16_ASCII)\n" );

    $write ( "c = \"%s\" = " , c );
    for ( x = 0; x < 12; x = x + 1 ) begin
        $write ( "%b " , c[x] );
    end
    $write( "(2_ASCII)\n" );

    $write ( "d = " );
    for ( x = 0; x < 5; x = x + 1 ) begin
        $write ( "%o " , d[x] );
    end
    $write ( "(8) = " );
    for ( x = 0; x < 5; x = x + 1 ) begin
        $write ( "%c " , d[x] );
    end
    $write( "(ASCII)\n" );

    $write ( "e = " );
    for ( x = 0; x < 5; x = x + 1 ) begin
        $write ( "%h " , e[x] );
    end
    $write ( "(16) = " );
    for ( x = 0; x < 5; x = x + 1 ) begin
        $write ( "%c " , e[x] );
    end
    $write( "(ASCII)\n" );
    end // main

endmodule // Guia_0105