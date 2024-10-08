// ---------------------
// TRUTH TABLE 
// Nome: Caio Faria Diniz
// Matricula: 793605
// --------------------- 

// --------------------- 
// Expressoes
// --------------------- 

module g0601 (output s1,
            output s2,
            output s3,
            output s4,
            output s5,
            input  x, y, z); // mintermos 
    assign s1 = (~x&~y&z)  | (x&y); 
    assign s2 = (y&~z)     | (x&~z); 
    assign s3 = (y&~z)     | (~y&z);
    assign s4 = (~x&y&~z)  | (x&~y) | (~y&z);
    assign s5 = (~x&~y&~z) | (x&y)  | (y&z) ;
endmodule // g0601

// --------------------- 
// Guia_0601 
// --------------------- 

module Guia_0601; 
    reg   x = 0, y = 0, z = 0; 
    wire  s1, s2, s3, s4, s5; 
    integer i = 0; 
    // instancias 
    g0601 EXP (s1, s2, s3, s4, s5, x, y, z); 

    // valores iniciais 
    initial begin: start 
        x=1'bx; y=1'bx; z=1'bx;   // indefinidos 
    end // start

    // main
    initial begin: main 

        $display("Guia_0601 - Teste ");  
        
        $display("\na.)");
        $display(" x  y  z = s1"); 
        $monitor("%2b %2b %2b = %2b", x, y, z, s1 ); 
        for (i = 0; i < 8; i = i + 1) begin
            { x, y, z } = i;
            #1;
        end // for

        $display("\nb.)");
        $display(" x  y  z = s2"); 
        $monitor("%2b %2b %2b = %2b", x, y, z, s2 ); 
        for (i = 0; i < 8; i = i + 1) begin
            { x, y, z } = i;
            #1;
        end // for

        $display("\nc.)");
        $display(" x  y  z = s3"); 
        $monitor("%2b %2b %2b = %2b", x, y, z, s3 ); 
        for (i = 0; i < 8; i = i + 1) begin
            { x, y, z } = i;
            #1;
        end // for

        $display("\nd.)");
        $display(" x  y  z = s4"); 
        $monitor("%2b %2b %2b = %2b", x, y, z, s4 );  
        for (i = 0; i < 8; i = i + 1) begin
            { x, y, z } = i;
            #1;
        end // for

        $display("\ne.)");
        $display(" x  y  z = s5"); 
        $monitor("%2b %2b %2b = %2b", x, y, z, s5 );  
        for (i = 0; i < 8; i = i + 1) begin
            { x, y, z } = i;
            #1;
        end // for

    end // main

endmodule // Guia_0601 