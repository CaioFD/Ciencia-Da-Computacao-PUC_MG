// ------------------------- 
// Clock.v
// Clock Generator
// Nome: Caio Faria Diniz 
// Matricula: 793605
// ------------------------- 

module clock ( output clk ); 
    reg clk;
    
    initial begin : start
    clk = 1'b0; 
    end // start

    always begin : clock 
        #12 clk = ~clk; 
    end // clock
endmodule // clock ( )