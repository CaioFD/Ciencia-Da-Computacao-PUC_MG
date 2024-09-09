// ------------------------- 
// Guia_0703 - GATES 
// Nome: Caio Faria Diniz  
// Matricula: 793605
// -------------------------

// ------------------------- 
//  f0703_and_nand - GATES 
// ------------------------- 
module f0703_and_nand( output a, output b, input x, input y );
    and  AND1  ( a, x, y );  // saída do AND
    nand NAND1 ( b, x, y );  // saída do NAND
endmodule // f0703_and_nand

// ------------------------- 
//  f0703_or_nor - GATES 
// ------------------------- 
module f0703_or_nor( output a, output b, input x, input y );
    or  OR1  ( a, x, y );    // saída do OR
    nor NOR1 ( b, x, y );    // saída do NOR
endmodule // f0703_or_nor

// ------------------------- 
//  Multiplexador 2x1
// ------------------------- 
module mux ( output z, 
             input a, input b, 
             input select 
           ); 
    wire not_select, sa, sb;
    
    // descrever por portas 
    not NOT1 ( not_select, select ); 
    and AND1 ( sa, a, not_select ); 
    and AND2 ( sb, b, select ); 
    or  OR1  ( z, sa, sb ); 
endmodule // mux 

// ------------------------- 
//  Guia_0703 - Módulo de Teste 
// -------------------------
module Guia_0703; 
    reg  x = 0, y = 0;   // inputs
    reg  s1 = 0;         // seleção do grupo AND/NAND ou OR/NOR
    reg  s2 = 0;         // seleção entre AND/NAND ou OR/NOR
    wire z1, z2, z3;     // saídas intermediárias e final
    wire a, b;           // saídas do AND/NAND
    wire c, d;           // saídas do OR/NOR
    integer i = 0;

    // instâncias
    f0703_and_nand AND_NAND ( a, b, x, y );
    f0703_or_nor   OR_NOR   ( c, d, x, y );
    mux MUX1 ( z1, b, a, s1 ); // mux para selecionar entre AND/NAND
    mux MUX2 ( z2, d, c, s1 ); // mux para selecionar entre OR/NOR
    mux MUX3 ( z3, z1, z2, s2 ); // mux para selecionar entre os grupos

    // valores iniciais 
    initial begin: start 
        x = 1'b0; y = 1'b0; s1 = 1'b0; s2 = 1'b0;
    end // start
    
    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0703 - CaioDiniz - Teste"); 
        $display("LU's module:");
        $display("   x    y   AND NAND  s1   OR   NOR  s2  MUX1 MUX2 MUX3");
        $monitor("%4b %4b %4b %4b %4b %4b %4b %4b %4b %4b %4b", x, y, a, b, s1, c, d, s2, z1, z2, z3); 
        
        for (i = 0; i < 4; i = i + 1) begin
            { x, y } = i;
            #1;
        end // for
    end // main 
endmodule // Guia_0703
