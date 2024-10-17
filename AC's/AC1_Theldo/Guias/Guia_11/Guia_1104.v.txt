// Nome: Caio Faria Diniz
// ----------------------------
// Matrícula: 793605
// -----------------------------
// --- FSM para reconhecer sequência x000
// -----------------------------

module guia_1104 (y, x, clk, reset);
  output reg y;   // Saída 
  input x;        // Entrada de dados 
  input clk;      // Sinal de clock
  input reset;    // Sinal de reset
  
  // Definições de estados
  parameter start = 3'b000,   // Estado inicial
            s1 = 3'b001,      // Detectou "0" ou "1"
            s2 = 3'b010,      // Detectou "00"
            s3 = 3'b011,      // Detectou "000"
            found = 3'b100;   // Estado de sequência reconhecida 

  reg [2:0] E1;  
  reg [2:0] E2;  
  // Lógica do próximo estado
  always @(x or E1) begin
    case (E1)
      start: 
        if (!x)
          E2 = s1;  
        else
          E2 = start;  

      s1: 
        if (!x)
          E2 = s2;  
        else
          E2 = start;  

      s2: 
        if (!x)
          E2 = s3;  
        else
          E2 = start;  

      s3:
        if (!x)
          E2 = found;  
        else
          E2 = start;  

      found:
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
    if (E1 == found)
      y = 1;  
    else
      y = 0;  
  end
endmodule // Guia_1104
