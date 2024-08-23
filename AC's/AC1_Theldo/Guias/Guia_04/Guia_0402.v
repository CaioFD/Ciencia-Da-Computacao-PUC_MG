/*
    Arquitetura de Computadores I - Guia_04.txt
    793605 - Caio Faria Diniz
*/


// ----- A ----- //
module fxyz (output s1, output s2, input  x, y, z); 
    assign s1 = x & ( ~x | y ); 
    assign s2 =  x & ~y;
endmodule // fxyzA 


// ----- B ----- //
module fxyz (output s1, output s2, input  x, y, z); 
    assign s1 = ( ~x | y ) | ( ~x & y ); 
    assign s2 =  ~x | y; 
endmodule // fxyzB


// ----- C ----- //
module fxyz (output s1, output s2, input  x, y, z); 
    assign s1 = ~( ~x & ~y  ) & ( x | y ); 
    assign s2 =  x | y; 
endmodule // fxyzC


// ----- D ----- //
module fxyz (output s1, output s2, input  x, y, z); 
    assign s1 = ~( ~x & y ) | ~( ~x | y ); 
    assign s2 =  x | ~y; 
endmodule // fxyzD


// ----- E ----- //
module fxyz (output s1, output s2, input  x, y, z); 
    assign s1 = ( y | ~x ) & ( ~y | x ); 
    assign s2 =  y & ~x; 
endmodule // fxyzE


module Guia_0402; 

    reg   x = 0, y = 0; 
    wire  s1, s2, s3, s4, s5; // expressao
    wire  S1, S2, S3, S4, S5; // expressao simplificada
    integer i = 0; 

    fxyzA FXYZA (s1, S1, x, y); 
    fxyzB FXYZB (s2, S2, x, y); 
    fxyzC FXYZC (s3, S3, x, y); 
    fxyzD FXYZD (s4, S4, x, y); 
    fxyzE FXYZE (s5, S5, x, y); 


initial begin: start 
    x=1'bx; y=1'bx;   // indefinidos 
end 

initial begin: main  // main

    $display("Guia_0402 - Test"); 

    $display("\na.)"); 
    $display(" x  y  = s1 s2");
    $monitor("%2b %2b  = %2b %2b", x, y, s1, S1); 
    for (i = 0; i < 4; i = i + 1) begin
        { x, y } = i;
        #1;
    end // end for

    $display("\nb.)"); 
    $display(" x  y  = s1 s2");
    $monitor("%2b %2b  = %2b %2b", x, y, s2, S2); 
    for (i = 0; i < 4; i = i + 1) begin
        { x, y } = i;
        #1;
    end // end for

    $display("\nc.)"); 
    $display(" x  y  = s1 s2");
    $monitor("%2b %2b  = %2b %2b", x, y, s3, S3); 
    for (i = 0; i < 4; i = i + 1) begin
        { x, y } = i;
        #1;
    end // end for

    $display("\nd.)"); 
    $display(" x  y  = s1 s2");
    $monitor("%2b %2b  = %2b %2b", x, y, s4, S4); 
    for (i = 0; i < 4; i = i + 1) begin
        { x, y } = i;
        #1;
    end // end for

    $display("\ne.)"); 
    $display(" x  y  = s1 s2");
    $monitor("%2b %2b  = %2b %2b", x, y, s5, S5); 
    for (i = 0; i < 4; i = i + 1) begin
        { x, y } = i;
        #1;
    end // end for 
end 

endmodule // Guia_0402