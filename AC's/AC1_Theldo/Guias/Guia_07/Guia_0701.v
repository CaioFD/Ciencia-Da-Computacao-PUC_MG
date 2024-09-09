// ------------------------- 
// Guia_0701 - GATES 
// Nome: Caio Faria Diniz  
// Matricula: 793605
// -------------------------

// ------------------------- 
//  f0701 - GATES 
// ------------------------- 
module f0701( output a, output b, input x, input y );
    and  AND1  ( a, x, y ); // saída do AND
    nand NAND1 ( b, x, y ); // saída do NAND
endmodule // f0701

// ------------------------- 
//  Multiplexador com 1 bit para Seleção 
// ------------------------- 
module mux ( output z, 
             input a, input b, 
             input select 
           ); 
    // definir dados locais 
    wire not_select; 
    wire sa; 
    wire sb; 
    // descrever por portas 
    not NOT1 ( not_select, select ); 
    and AND1 ( sa, b, not_select ); // Modificação: 'b' para NAND com select=0
    and AND2 ( sb, a,     select ); // Modificação: 'a' para AND com select=1
    or  OR1  ( z, sa, sb ); 
endmodule // mux 

// ------------------------- 
//  Guia_0701 - Módulo de Teste 
// -------------------------
module Guia_0701; 
    // ------------------------- definir dados 
    reg  x = 0, y = 0; // inputs
    reg  s = 0;        // input selecionável
    wire z;            // output MUX
    wire a, b;         // outputs AND/NAND
    reg [2:0]i;

    // instâncias
    f0701 MOD ( a, b, x, y );
    mux   MUX ( z, a, b, s );

    // valores iniciais 
    initial begin: start 
        x=1'b0; y=1'b0; s=1'b0;
    end // start

    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0701 - CaioDiniz - Teste"); 
        $display("LU's module:");
        $display( "   x    y    s   AND NAND  MUX" );
        $monitor("%4b %4b %4b %4b %4b %4b", x, y, s, a, b, z ); 
        for ( i = 1; i < 4; i++ )
        begin
            #10 x=i[1]; y=i[0]; s = ~s;
        end // for
    end // main 
endmodule // Guia_0701 
