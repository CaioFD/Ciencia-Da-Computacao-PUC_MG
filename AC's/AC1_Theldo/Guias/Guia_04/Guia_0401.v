/*
    Arquitetura de Computadores I - Guia_04.txt
    793605 - Caio Faria Diniz
*/

// --------------------- 
// fxyz
// --------------------- 


// ----- A ----- //
module fxyz ( output s, 
            input  x, y, z); 
assign s = ~x & ~(~y | z);  
endmodule // fxyzA


// ----- B ----- //
module fxyz ( output s, 
            input  x, y, z); 
assign s = ~( ~x | ~y ) & z ;  
endmodul // fxyzB


// ----- C ----- //
module fxyz ( output s, 
            input  x, y, z); 
assign s = ~( x & ~y ) & ~z ;  
endmodule  // fxyzC 


// ----- D ----- //
module fxyz ( output s, 
            input  x, y, z); 
assign s = ~( ~x & y ) & z; 
endmodule // fxyzD


// ----- E ----- //
module fxyz ( output s, 
            input  x, y, z); 
assign s = ( ~x | y ) & ~( ~y & z ); 
endmodule // fxyzE

module Guia_0401; 
    reg   x, y, z; 
    wire  s1, s2, s3, s4, s5; 
    // instancias 
    fxyzA FXYZA (s1, x, y, z); 
    fxyzB FXYZB (s2, x, y, z); 
    fxyzC FXYZC (s3, x, y, z); 
    fxyzD FXYZD (s4, x, y, z); 
    fxyzE FXYZE (s5, x, y, z); 
 
    initial begin: start 
        x=1'bx; y=1'bx; z=1'bx;   // indefinidos 
    end 

    // main
    initial begin: main 

        $display("Guia_0401 - Test"); 

        $display("\na.)"); 
        $display(" x  y  z  = s1"); 
        $monitor("%2b %2b %2b  = %2b", x, y, z, s1); 
        // sinalizacao 
        #1  x=0; y=0; z=0;
        #1  x=0; y=0; z=1;
        #1  x=0; y=1; z=0;
        #1  x=0; y=1; z=1;
        #1  x=1; y=0; z=1;
        #1  x=1; y=0; z=0;
        #1  x=1; y=1; z=1;
        #1  x=1; y=1; z=0;

        $display("\nb.)"); 
        $display(" x  y  z  = s2"); 
        $monitor("%2b %2b %2b  = %2b", x, y, z, s2); 
        // sinalizacao 
        #1  x=0; y=0; z=0;
        #1  x=0; y=0; z=1;
        #1  x=0; y=1; z=0;
        #1  x=0; y=1; z=1;
        #1  x=1; y=0; z=1;
        #1  x=1; y=0; z=0;
        #1  x=1; y=1; z=1;
        #1  x=1; y=1; z=0;

        $display("\nc.)"); 
        $display(" x  y  z  = s3"); 
        $monitor("%2b %2b %2b  = %2b", x, y, z, s3); 
        // sinalizacao 
        #1  x=0; y=0; z=0;
        #1  x=0; y=0; z=1;
        #1  x=0; y=1; z=0;
        #1  x=0; y=1; z=1;
        #1  x=1; y=0; z=1;
        #1  x=1; y=0; z=0;
        #1  x=1; y=1; z=1;
        #1  x=1; y=1; z=0;

        $display("\nd.)"); 
        $display(" x  y  z  = s4"); 
        $monitor("%2b %2b %2b  = %2b", x, y, z, s4); 
        // sinalizacao 
        #1  x=0; y=0; z=0;
        #1  x=0; y=0; z=1;
        #1  x=0; y=1; z=0;
        #1  x=0; y=1; z=1;
        #1  x=1; y=0; z=1;
        #1  x=1; y=0; z=0;
        #1  x=1; y=1; z=1;
        #1  x=1; y=1; z=0;

        $display("\ne.)"); 
        $display(" x  y  z  = s5"); 
        $monitor("%2b %2b %2b  = %2b", x, y, z, s5); 
        // sinalizacao 
        #1  x=0; y=0; z=0;
        #1  x=0; y=0; z=1;
        #1  x=0; y=1; z=0;
        #1  x=0; y=1; z=1;
        #1  x=1; y=0; z=1;
        #1  x=1; y=0; z=0;
        #1  x=1; y=1; z=1;
        #1  x=1; y=1; z=0;
    end // end_main

endmodule // Guia_0401 