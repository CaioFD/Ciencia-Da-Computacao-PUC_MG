/*
    Arquitetura de Computadores I - Guia_03
    793605 - Caio Faria Diniz
*/

module Guia_0305; 
    
    reg [5:0] a = 0  ; // binary 
    reg [7:0] b = 0  ; // binary 
    reg [7:0] bf = 0 ; // binary 
    reg [7:0] c = 0  ; // binary 
    reg [7:0] d = 0  ; // binary 
    reg [7:0] e = 0  ; // binary 

    reg [7:0] x = 0  ; // binary 
    reg [7:0] xf = 0 ; // binary 
    reg [7:0] y = 0  ; // binary 
    reg [7:0] yf = 0 ; // binary 
    integer z;

     // ------- actions ------- //
    initial  begin : main 
        $display ( "Guia_0305 - Tests" ); 

        // ------- A ------- //
        x = 8'b110101;
        y = 8'b1011;
        a = x-y;
        $display( "a = %8b(2) - %8b(2) = %8b(2)\n", x, y, a );

        // ------- B ------- //
        x = 8'b101;
        xf = 8'b10010000;
        y = 8'o3;
        yf = 8'o1;
        b = x - y;
        bf = xf - yf;
        $display( "b = %3b,%4b(2) - %o,%o(8) = %8b,%5b(2)\n", x[2:0], xf[7:4], y, yf, b , bf[4:0] );

        // ------- C ------- //
        x = 8'b100111;
        y = 16'h3d;
        c = x - y;
        $display( "c = %d%d%d(4) - %h(2) = %5b(2)\n", x[5:4], x[3:2], x[1:0], y, c );

        // ------- D ------- //
        x = 16'hc5;
        y = 8'b1011001;
        d = x + ~(y+1);
        $display( "d = %h(16) - %8b(2) = %8b(2)\n" , x, y, d );

        // ------- E ------- //
        x = 16'h7e;
        y = 16'h2d;
        e = x - y;
        $display( "e = %d - %x = %8b\n", x, y , e );

    end // main 

endmodule // Guia_0305