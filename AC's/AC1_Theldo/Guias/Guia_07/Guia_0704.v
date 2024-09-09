// ------------------------- 
// Guia_0704 - GATES 
// Nome: Caio Faria Diniz  
// Matricula: 793605
// -------------------------

// ------------------------- 
//  f0704 - GATES
// ------------------------- 
module f0704( output a, output b, output c, output d, input x, input y );
    or   OR1  ( a, x, y );   // saída do OR
    nor  NOR1 ( b, x, y );   // saída do NOR
    xor  XOR1 ( c, x, y );   // saída do XOR
    xnor XNOR1 ( d, x, y );  // saída do XNOR
endmodule // f0704

// ------------------------- 
//  Multiplexador 4x1 com 2 bits de Seleção
// ------------------------- 
module mux4x1 ( output z, 
                input a, input b, input c, input d, 
                input select1, input select2 
              ); 
    // definir dados locais 
    wire not_select1, not_select2;
    wire sa, sb, sc, sd;

    // descrever por portas 
    not  NOT1 ( not_select1, select1 ); 
    not  NOT2 ( not_select2, select2 ); 

    and AND1 ( sa, a, not_select1, not_select2 ); // 00
    and AND2 ( sb, b, not_select1, select2 );     // 01
    and AND3 ( sc, c, select1, not_select2 );     // 10
    and AND4 ( sd, d, select1, select2 );         // 11

    or  OR1  ( z, sa, sb, sc, sd ); 
endmodule // mux4x1

// ------------------------- 
//  Guia_0704 - Módulo de Teste 
// -------------------------
module Guia_0704; 
    // ------------------------- definir dados 
    reg  x = 0, y = 0;         // entradas
    reg  s1 = 0, s2 = 0;       // seleção
    wire z;                    // saída MUX
    wire a, b, c, d;           // saídas OR, NOR, XOR, XNOR

    // instâncias
    f0704 LU ( a, b, c, d, x, y );
    mux4x1 MUX ( z, a, b, c, d, s1, s2 );

    // valores iniciais 
    initial begin: start 
        x = 1'b0; y = 1'b0; s1 = 1'b0; s2 = 1'b0;
    end 

    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0704 - CaioDiniz - Teste"); 
        $display("LU's module:");
        $display(" x y s1 s2 | OR  NOR XOR XNOR | MUX ");
        $monitor(" %b %b  %b  %b |  %b   %b   %b   %b  |  %b ", x, y, s1, s2, a, b, c, d, z); 

        for (integer i = 0; i < 4; i = i + 1) begin
            {s1, s2} = i;
            for (integer j = 0; j < 4; j = j + 1) begin
                {x, y} = j;
                #1;
            end
        end 
    end 
endmodule // Guia_0704
