/*
    Arquitetura de Computadores I - Guia_02
    793605 - Caio Faria Diniz
*/

module Guia_0201; 

   integer x = 0 ;     // -> var
   integer y = 7 ;     // -> counter 
   real power2 = 1.0 ; // -> power of 2 
   real dec [0:4] ;    // -> decimal 
   reg  [0:4][7:0] bin = {8'b00011000, 8'b01001000, 8'b10101000, 8'b11101000, 8'b11001000}; // binary (only fraction part, Big Endian)


    initial begin : main 

        $display ( "Guia_0201 - Tests" );  
        for ( x = 0; x < 5 ; x = x + 1 ) begin
            y = 7;
            while ( y >= 0 ) begin 
            power2 = power2 / 2.0; 

            if ( bin[x][y] == 1 ) 
            begin 
                temp_dec = temp_dec + power2; 
            end 
            y=y-1; 
        end 
    end 
        for ( x = 0; x < 5; x = x + 1 ) begin
        $display ( "%d = %f",x+1, dec[x] ); 
    end

end

endmodule // Guia_0201