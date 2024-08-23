/*
    Arquitetura de Computadores I - Guia_02
    793605 - Caio Faria Diniz
*/

module Guia_0202; 

    real  x [0:4] = { 0.375, 0.125, 0.625, 0.03125, 0.75 }; // decimal (10)
    integer   i   = 0   ;
    reg [7:0] bin = 0 ; // binary (2)

    function [7:0] real2bin(real x);
        reg [7:0] b;
        integer y;
        b = 0;
        y = 7;
        while (x > 0 && y >= 0) begin 
            if (x*2 >= 1) begin 
                b[y] = 1; 
                x = x*2.0 - 1.0; 
            end 
            else begin 
                b[y] = 0; 
                x = x*2.0; 
            end 
            y = y - 1; 
        end 
        fdec2fbin = b;
    endfunction

    initial begin : main
        $display ("Guia_0202 - Tests"); 
        for (i = 0; i < 5; i = i + 1) begin
            bin = fdec2fbin(x[i]);
            $display ("bin = 0.%8b", bin);
        end 

   end // main 

endmodule // Guia_0202