// ---------------------
// TRUTH TABLE 
// Nome: Caio Faria Diniz
// Matricula: 793605
// --------------------- 

// --------------------- 
// Expressoes
// --------------------- 

module g0603 (output s1,
            output s2,
            output s3,
            output s4,
            output s5,
            input  x, y, w, z); // mintermos 
    assign s1 = (~x&~y&w&~z)   | (~x&~w&z) | (y&~w&z) | (x&~w&~z); 
    assign s2 = (~x&~y&~w)     | (~x&z)    | (y&z); 
    assign s3 = (~x&~w)        | (w&~z)    | (y&w);
    assign s4 = (x&y&~w&z)     | (~x&y&~z) | (~x&y&w) | (w&~z);
    assign s5 = (~y&~w | ~y&z) | (~x&w&z)  | (x&~w&z);
endmodule // g0603

// --------------------- 
// Guia_0603 
// --------------------- 

module Guia_0603; 
    reg   x = 0, y = 0, w = 0, z = 0; 
    wire  s1, s2, s3, s4, s5; 
    integer i = 0; 
    // instancias 
    g0603 EXP (s1, s2, s3, s4, s5, x, y, w, z); 

    // valores iniciais 
    initial begin: start 
        x=1'bx; y=1'bx; w=1'bx; z=1'bx;   // indefinidos 
    end // start

    // main 
    initial begin: main  
        $display("Guia_0603 - Teste ");  
        
        $display("\na.)");
        $display(" x  y  w  z = s1"); 
        $monitor("%2b %2b %2b %2b = %2b", x, y, w, z, s1 ); 
        for (i = 0; i < 16; i = i + 1) begin
            { x, y, w, z } = i;
            #1;
        end // for

        $display("\nb.)");
        $display(" x  y  w  z = s2"); 
        $monitor("%2b %2b %2b %2b = %2b", x, y, w, z, s2 ); 
        for (i = 0; i < 16; i = i + 1) begin
            { x, y, w, z } = i;
            #1;
        end // for

        $display("\nc.)");
        $display(" x  y  w  z = s3"); 
        $monitor("%2b %2b %2b %2b = %2b", x, y, w, z, s3 ); 
        for (i = 0; i < 16; i = i + 1) begin
            { x, y, w, z } = i;
            #1;
        end // for

        $display("\nd.)");
        $display(" x  y  w  z = s4"); 
        $monitor("%2b %2b %2b %2b = %2b", x, y, w, z, s4 );  
        for (i = 0; i < 16; i = i + 1) begin
            { x, y, w, z } = i;
            #1;
        end // for

        $display("\ne.)");
        $display(" x  y  w  z = s5"); 
        $monitor("%2b %2b %2b %2b = %2b", x, y, w, z, s5 );  
        for (i = 0; i < 16; i = i + 1) begin
            { x, y, w, z } = i;
            #1;
        end // for
        
    end // main

endmodule // Guia_0603 