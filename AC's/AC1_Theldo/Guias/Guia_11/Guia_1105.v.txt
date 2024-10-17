// Nome: Caio Faria Diniz
// ----------------------------
// Matrícula: 793605
// -----------------------------
// --- FSM para reconhecer sequências alternadas (010 ou 101)
// -----------------------------

module guia_1105 (y, x, clk, reset);
  output reg y;    // Saída 
  input x;         // Entrada de dados 
  input clk;       // Sinal de clock
  input reset;     // Sinal de reset
  
  // Definições de estados
  parameter start = 3'b000,   // Estado inicial
            s0 = 3'b001,      // Detectou "0"
            s01 = 3'b010,     // Detectou "01"
            s010 = 3'b011,    // Detectou "010" 
            s1 = 3'b100,      // Detectou "1"
            s10 = 3'b101,     // Detectou "10"
            s101 = 3'b110;    // Detectou "101" 

  reg [2:0] E1;  
  reg [2:0] E2;  

  // Lógica do próximo estado
  always @(x or E1) begin
    case (E1)
      start:
        if (x)
          E2 = s1;    
        else
          E2 = s0;    
      
      s0:
        if (x)
          E2 = s01;  
        else
          E2 = s0;    

      s01:
        if (!x)
          E2 = s010;  
        else
          E2 = s1;    
      
      s010: 
        E2 = start;   

      s1:
        if (!x)
          E2 = s10;   
        else
          E2 = s1;    

      s10:
        if (x)
          E2 = s101;  
        else
          E2 = s0;    

      s101:
        E2 = start;   

      default:
        E2 = start;   
    endcase
  end

  // Lógica de atualização de estado
  always @(posedge clk or negedge reset) begin
    if (!reset)
      E1 <= start;    
    else
      E1 <= E2;       
  end

  // Saída da FSM
  always @(E1) begin
    if (E1 == s010 || E1 == s101)
      y = 1;          
    else
      y = 0;          
  end
endmodule // Guia_1105
