/*
    Arquitetura de Computadores I - Guia_03
    793605 - Caio Faria Diniz
*/

module Guia_0303; 

    reg signed [5:0] a = 5'b1_010    ; // binary 
    reg signed [5:0] b = 6'b1_10011  ; // binary 
    reg signed [5:0] c = 6'b1_00100  ; // binary 
    reg signed [6:0] d = 7'b1_011011 ; // binary 
    reg signed [6:0] e = 7'b1_110011 ; // binary 

    // ------- actions ------- //
    initial begin : main 

        $display ( "Guia_0303 - Tests" ); 

        $display ( "a = %5b -> C1(a) = %5b = %d", a, ~a, ~(a-1) ); 
        $display ( "b = %5b -> C1(b) = %5b = %d", b, ~b, ~(b-1) ); 
        $display ( "c = %5b -> C1(c) = %5b = %8b", c, ~c, ~(c-1) );
        $display ( "d = %6b -> C1(d) = %6b = %8b", d, ~d, ~(d-1) );
        $display ( "e = %6b -> C1(e) = %6b = %x", e, ~e, ~(e-1) );

    end 
    
endmodule // Guia_0303