// Nome: Caio Faria Diniz
// ----------------------------
// Matrícula: 793605
// -----------------------------
// --- Moore FSM para reconhecer 1001 com interseção
// -----------------------------

// Definições de constantes
`define found 1
`define notfound 0

// FSM de Moore para reconhecer a sequência 1001
module guia_1103 (y, x, clk, reset);
  output reg y;   // Saída da FSM 
  input x;        // Entrada de dados
  input clk;      // Sinal de clock
  input reset;    // Sinal de reset
  
  // Definições de estados
  parameter start = 3'b000,   // Estado inicial
            id1 = 3'b001,     // Detectou "1"
            id10 = 3'b010,    // Detectou "10"
            id100 = 3'b011,   // Detectou "100"
            found = 3'b100;   // Detectou "1001"

  reg [2:0] E1;  
  reg [2:0] E2;  

  // Lógica do próximo estado (FSM de Moore)
  always @(x or E1) begin
    case (E1)
      start: 
        if (x)
          E2 = id1;
        else
          E2 = start;

      id1: 
        if (!x)
          E2 = id10;
        else
          E2 = id1;

      id10: 
        if (x)
          E2 = id100;
        else
          E2 = start;

      id100: 
        if (!x)
          E2 = found;
        else
          E2 = id1;

      found:
        if (x)
          E2 = id1;  
        else
          E2 = start;

      default: 
        E2 = start;  
    endcase
  end

  // Lógica de saída (FSM de Moore)
  always @(posedge clk or negedge reset) begin
    if (!reset)
      E1 <= start;  
    else
      E1 <= E2;     
  end

  // Saída do FSM de Moore
  always @(E1) begin
    case (E1)
      found: y = `found; 
      default: y = `notfound;
    endcase
  end
endmodule // Guia_1103
