/*
    Arquitetura de Computadores I - Guia_04.txt
    793605 - Caio Faria Diniz
*/

module PoS (output S1,
            output S2,
            output S3,
            output S4,
            output S5,
            input  X, Y, W, Z); // MAXTERMOS

// ----- A ----- //
 assign S1  = ( X |  Y | ~Z) //1
            & ( X | ~Y |  Z) //2
            & (~X | ~Y |  Z) //6
            & (~X | ~Y | ~Z) //7
            ; 
// ----- B ----- //
 assign S2  = ( X |  Y |  Z) //0
            & ( X | ~Y | ~Z) //3
            & (~X |  Y |  Z) //4
            & (~X | ~Y | ~Z) //7
            ; 
// ----- C ----- //
 assign S3  = ( X |  Y |  W |  Z) //0
            & ( X |  Y |  W | ~Z) //1
            & ( X |  Y | ~W |  Z) //2
            & ( X | ~Y |  W |  Z) //4
            & ( X | ~Y | ~W |  Z) //6
            & (~X |  Y |  W |  Z) //8
            & (~X |  Y | ~W | ~Z) //11
            & (~X | ~Y |  W |  Z) //12
            ;
// ----- D ----- //
 assign S4  = ( X |  Y |  W | ~Z) //1
            & ( X |  Y | ~W |  Z) //2
            & ( X | ~Y |  W |  Z) //4
            & ( X | ~Y | ~W | ~Z) //7
            & (~X |  Y |  W |  Z) //8
            & (~X |  Y |  W | ~Z) //9
            & (~X | ~Y | ~W | ~Z) //15
            ;
// ----- E ----- //
 assign S5  = (~X | ~Y | ~W | ~Z) //0
            & ( X |  Y |  W | ~Z) //1
            & ( X |  Y | ~W |  Z) //2
            & ( X | ~Y |  W |  Z) //4
            & ( X | ~Y |  W | ~Z) //5
            & (~X |  Y | ~W |  Z) //10
            & (~X | ~Y |  W | ~Z) //13
            ; 
endmodule // PoS


module Guia_0404; 
    reg   X = 0, Y = 0, W = 0, Z = 0; 
    wire  S1, S2, S3, S4, S5;
    integer  i = 0; 
    // instancias 
    PoS POS (S1, S2, S3, S4, S5 , X, Y, W, Z); 

    initial begin: start 
        X=1'bx; Y=1'bx; W=1'bx; Z=1'bx;  // indefinidos 
    end 

    // main 
    initial begin: main 
        $display("Guia_0404 - Test"); 

        $display("\na.)"); 
        $display(" X  Y  Z  = S1"); 
        $monitor("%2b %2b %2b  = %2b", X, Y, Z, S1); 
        for (i = 0; i < 8; i = i + 1) begin
            { X, Y, Z } = i;
            #1;
        end // end for

        $display("\nb.)");
        $display(" X  Y  Z  = S2"); 
        $monitor("%2b %2b %2b  = %2b", X, Y, Z, S2); 
        for (i = 0; i < 8; i = i + 1) begin
            { X, Y, Z } = i;
            #1;
        end // end for

        $display("\nc.)");
        $display(" X  Y  W  Z  = S3"); 
        $monitor("%2b %2b %2b %2b  = %2b", X, Y, W, Z, S3); 
        for (i = 0; i < 16; i = i + 1) begin
            { X, Y, W, Z } = i;
            #1;
        end // end for

        $display("\nd.)"); 
        $display(" X  Y  W  Z  = S4"); 
        $monitor("%2b %2b %2b %2b  = %2b", X, Y, W, Z, S4); 
        for (i = 0; i < 16; i = i + 1) begin
            { X, Y, W, Z } = i;
            #1;
        end // end for

        $display("\ne.)"); 
        $display(" X  Y  W  Z  = S5"); 
        $monitor("%2b %2b %2b %2b  = %2b", X, Y, W, Z, S5); 
        for (i = 0; i < 16; i = i + 1) begin
            { X, Y, W, Z } = i;
            #1;
        end // end for
    end // end main 

endmodule // Guia_0404