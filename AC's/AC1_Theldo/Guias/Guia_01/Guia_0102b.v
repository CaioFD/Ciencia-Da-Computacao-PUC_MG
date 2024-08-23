/*
    Arquitetura de Computadores I - Guia_01
    793605 - Caio Faria Diniz
*/

module Guia_0102;

    integer dec = 0; 

    reg [7:0] a = 8'b0010101, b = 8'b0011101, c =  8'b0010010, d = 8'b0101011, e = 8'b0110111; // binary (bits - little endian)  

    initial begin : main
    $display ( "Guia_0102b\n" );

    $display ( "a = %8b", a );
    dec = a;
    $display ( "dec = %d\n", dec );

    $display ( "b = %8b", b );
    dec = b;
    $display ( "dec = %d\n", dec );

    $display ( "c = %8b", c );
    dec = c;
    $display ( "dec = %d\n", dec );

    $display ( "d = %8b", d );
    dec = d;
    $display ( "dec = %d\n", dec );

    $display ( "e = %8b", e );
    dec = e;
    $display ( "dec = %d\n", dec );
    
    end // main

endmodule // Guia_0102