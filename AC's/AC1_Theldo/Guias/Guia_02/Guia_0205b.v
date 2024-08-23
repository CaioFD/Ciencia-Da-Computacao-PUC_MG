/*
    Arquitetura de Computadores I - Guia_02
    793605 - Caio Faria Diniz
*/

module Guia_0205; 
    
    reg [7:0] a  ; // binary (2)
    reg [7:0] af ; // fractional binary
    reg [7:0] b  ; // binary (2)
    reg [7:0] bf ; // fractional binary
    reg [7:0] i;
    reg [7:0] f;
    
    initial begin : main 

        $display("Guia_0205 - Tests\n"); 
        //====== A ======//
        a  = 8'b000_0101 ;  // binary (2)
        af = 8'b1100_0000 ; // fractional binary
        b  = 8'b000_0010;   // binary (2)
        bf = 8'b0110_0000;  // fractional binary
        $display("a = %8b", a);
        $display("b = %8b", b); 
        $display("af = %8b", af);
        $display("bf = %8b", bf); 
        i = a + b; 
        f = af + bf; 
        $display("a.) = a+b = %b,%b\n", i, f);


        //====== B ======//
        a  = 8'b0000_1000 ; // binary (2)
        b  = 8'b0000_0010 ; // binary (2)
        af = 8'b1010_0000 ; // fractional binary
        bf = 8'b0100_0000 ; // fractional binary
        $display("a = %8b", a);
        $display("b = %8b", b); 
        $display("af = %8b", af);
        $display("bf = %8b", bf); 
        i = a - b;
        f = af - bf;
        $display("b.) = a-b = %b,%b\n", i, f);


        //====== C ======//
        a  = 8'b0000_0101 ; // binary (2)
        b  = 8'b0000_0010 ; // binary (2)
        af = 8'b0000_0101 ; // fractional binary
        bf = 8'b0000_0101 ; // fractional binary
        $display("a = %8b", a);
        $display("b = %8b", b); 
        $display("af = %8b", af);
        $display("bf = %8b", bf); 
        i = a * b;
        f = af * bf;  
        $display("c.) = a*b = %b,%b\n", i, f);


        //====== D ======//
        a  = 8'b0001_0111 ; // binary (2)
        b  = 8'b0000_0011 ; // binary (2)
        af = 8'b0100_0000 ; // fractional binary
        bf = 8'b0110_0000 ; // fractional binary
        $display("a = %8b", a);
        $display("b = %8b", b); 
        $display("af = %8b", af);
        $display("bf = %8b", bf); 
        i = a / b;
        f = af / bf; 
        $display("d.) = a/b = %b,%b\n", i, f);


        //====== E ======//
        a  = 8'b0110_1011 ; // binary (2) + fractional binary
        b  = 8'b0000_1101 ; // binary (2) + fractional binary
        $display("a = %8b", a);
        $display("b = %8b", b); 
        i = a % b;
        $display("e.) = a%%b = %b\n", i);

    end // main 

endmodule // Guia_0205