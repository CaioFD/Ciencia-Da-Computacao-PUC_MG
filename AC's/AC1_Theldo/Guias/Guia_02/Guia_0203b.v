/*
    Arquitetura de Computadores I - Guia_02
    793605 - Caio Faria Diniz
*/

module Guia_0203; 

   reg [7:0] a = 8'b01111000 ; //  binary (2); 
   reg [7:0] b = 8'b10100100 ; //  binary (2);
   reg [7:0] c = 8'b10011000 ; //  binary (2); 
   reg [7:0] d = 8'b11101100 ; //  binary (2);
   reg [7:0] e = 8'b10010000 ; //  binary (2);

    initial begin : main 

    $display ( "Guia_0203 - Tests" ); 

    $display ( "a = 0.%8b = 0.%d%d%d%d (4)" , a[7:0], a[7:6], a[5:4], a[3:2], a[1:0] );
    $display ( "b = 0.%8b = 0.%o%o%o (8)"   , b[7:0], b[7:5], b[4:2], b[1:0] );
    $display ( "c = 0.%8b = 0.%x%x (16)"    , c[7:0], c[7:4], c[3:0] );
    $display ( "d = 0.%8b = 0.%o%o%o (8)"   , d[7:0], d[7:5], d[4:2], d[1:0] );
    $display ( "e = 0.%8b = 0.%x%x (16)"    , e[7:0], e[7:4], e[3:0] );

   end // main 

endmodule // Guia_0203 