/*
    Arquitetura de Computadores I - Guia_04.txt
    793605 - Caio Faria Diniz
*/


module SoP (output s1,
            output s2,
            output s3,
            output s4,
            output s5,
            input  x, y, w, z); // mintermos 

// ----- A ----- //
 assign s1  = ( ~x &  ~y &  z) //1
            | (  x &  ~y &  z) //5
            | (  x &   y & ~z) //6
            | (  x &   y &  z) //7
            ; 
// ----- B ----- //
 assign s2  = ( ~x  &  y  & ~z ) //2
            | (  x  & ~y  &  z ) //5
            | (  x  &  y  & ~z ) //6
            | (  x  &  y  &  z ) //7
            ; 
endmodule 
// ----- C ----- //
 assign s3  = (~x & ~y & ~w &  z) //1
            | (~x & ~y &  w & ~z) //2
            | (~x &  y &  w &  z) //3
            | (~x &  y &  w & ~z) //6
            | ( x & ~y & ~w & ~z) //7
            | ( x & ~y &  w &  z) //11
            | ( x &  y &  w &  z) //15
            ;
// ----- D ----- //
 assign s4  = (~x & ~y & ~w &  z) //1
            | (~x & ~y &  w & ~z) //2
            | (~x &  y &  w & ~z) //6
            | ( x & ~y & ~w & ~z) //8
            | ( x & ~y &  w & ~z) //10
            | ( x &  y & ~w & ~z) //12
            | ( x &  y &  w & ~z) //14
            ;
// ----- E ----- //
 assign s5  = (~x & ~y & ~w & ~z) //0
            | (~x & ~y &  w & ~z) //2
            | (~x &  y & ~w &  z) //5
            | (~x &  y &  w &  z) //7
            | ( x & ~y & ~w &  z) //8
            | ( x & ~y &  w &  z) //11
            ;
endmodule // SoP

module Guia_0403; 
    reg   x = 0, y = 0, w = 0, z = 0; 
    wire  s1, s2, s3, s4, s5;
    integer  i = 0; 
    // instancias 
    SoP SOP (s1, s2, s3, s4, s5 , x, y, w, z); 

    initial begin: start 
        x=1'bx; y=1'bx; w=1'bx; z=1'bx;  // indefinidos 
    end 

    //main 
    initial begin: main 
        // identificacao 
        $display("Guia_0403 - Test"); 

        $display("\na.)"); 
        $display(" x  y  z  = s1");
        $monitor("%2b %2b %2b  = %2b", x, y, z, s1); 
        for (i = 0; i < 8; i = i + 1) begin
            { x, y, z } = i;
            #1;
        end // end for

        $display("\nb.)");
        $display(" x  y  z  = s2"); 
        $monitor("%2b %2b %2b  = %2b", x, y, z, s2); 
        for (i = 0; i < 8; i = i + 1) begin
            { x, y, z } = i;
            #1;
        end // end for

        $display("\nc.)"); 
        $display(" x  y  w  z  = s3");
        $monitor("%2b %2b %2b %2b  = %2b", x, y, w, z, s3); 
        for (i = 0; i < 16; i = i + 1) begin
            { x, y, w, z } = i;
            #1;
        end // end for

        $display("\nd.)"); 
        $display(" x  y  w  z  = s4");
        $monitor("%2b %2b %2b %2b  = %2b", x, y, w, z, s4); 
        for (i = 0; i < 16; i = i + 1) begin
            { x, y, w, z } = i;
            #1;
        end // end for

        $display("\ne.)");
        $display(" x  y  w  z  = s5"); 
        $monitor("%2b %2b %2b %2b  = %2b", x, y, w, z, s5); 
        for (i = 0; i < 16; i = i + 1) begin
            { x, y, w, z } = i;
            #1;
        end // end for
    end // end main 

endmodule // Guia_0403 