/*
    Arquitetura de Computadores I - Guia_03
    793605 - Caio Faria Diniz
*/

module Guia_0302; 

    reg [5:0] a = 8'o321 ; // base-4 
    reg [7:0] b = 8'hb2  ; // hexa 
    reg [5:0] c = 8'o231 ; // base-4 
    reg [9:0] d = 8'o146 ; // octal 
    reg [7:0] e = 8'h6f  ; // hexa
    reg [5:0] c1  = 0    ; // binary 
    reg [9:0] d1  = 0    ; // binary 
    reg [7:0] e1  = 0    ; // binary 

 // ------- actions ------- //
    initial begin : main 

        $display ( "Guia_0302 - Tests" );

        $display ( "a = %6b -> C1(a) = %6b", a, ~a ); 
        $display ( "b = %8b -> C1(b) = %8b", b, ~b ); 

        c1 = ~c+1; 
        $display ( "c = %6b -> C1(c) = %6b -> C2(c) = %6b", c, ~c, c1 );
        
        d1 = ~d+1; 
        $display ( "d = %10b -> C1(d) = %10b -> C2(d) = %10b", d, ~d, d1 );
        
        e1 = ~e+1; 
        $display ( "e = %8b -> C1(e) = %8b -> C2(e) = %8b", e, ~e, e1 ); 
        
    end 

endmodule // Guia_0302