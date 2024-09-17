// ------------------------- 
// Guia_0803 - EQUALITY COMPARATOR (05 bits)
// Nome: Caio Faria Diniz 
// Matricula: 793605
// ------------------------- 

// ------------------------- 
// equality comparator 
// ------------------------- 
module isEquals ( output s, input a, input b ); 
    // descrever por portas 
    xnor XNOR0 ( s, a, b ); 
endmodule // isEquals 

// ------------------------- 
//  Guia_0803 
// ------------------------- 
module Guia_0803; 
    // ------------------------- definir dados 
    reg  [4:0] x; // input1 (05 bits)
    reg  [4:0] y; // input2

    reg  [4:0] a; // input3
    reg  [4:0] b; // input4

    wire [4:0] s1; // output1
    wire [4:0] s2; // output2
    
    // Instancias de s1, x, y
    isEquals XY0 ( s1[0], x[0], y[0] );
    isEquals XY1 ( s1[1], x[1], y[1] );
    isEquals XY2 ( s1[2], x[2], y[2] );
    isEquals XY3 ( s1[3], x[3], y[3] );
    isEquals XY4 ( s1[4], x[4], y[4] );

    // Instancias de s2, a, b
    isEquals AB0 ( s2[0], a[0], b[0] );
    isEquals AB1 ( s2[1], a[1], b[1] );
    isEquals AB2 ( s2[2], a[2], b[2] );
    isEquals AB3 ( s2[3], a[3], b[3] );
    isEquals AB4 ( s2[4], a[4], b[4] );

    // Atribuindo valores
    initial begin : start
        // valores iguais para 'x' e 'y'
        x = 5'b10101;
        y = 5'b10101;
        // valores diferentes para 'a' e 'b'
        a = 5'b10011;
        b = 5'b10010;
    end // start

    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0803 - Caio Faria Diniz - 793605"); 
        $display("Test ALU’s equality comparator"); 

        #1;
        // Teste de igualdade entre x e y
        $write( "%b  ==  %b ? %b = ", x, y, s1 );
		if( s1 == 5'b11111 ) begin
			$display( "true" );
		end // if
		else begin
			$display( "false" );
		end // else

        #1;
        // Teste de igualdade entre a e b
        $write( "%b  ==  %b ? %b = ", a, b, s2 );
		if( s2 == 5'b11111 ) begin
			$display( "true" );
		end // if
		else begin
			$display( "false" );
		end // else
    end // main
endmodule // Guia_0803
