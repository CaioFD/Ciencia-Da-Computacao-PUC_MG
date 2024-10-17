// Nome: Caio Faria Diniz
// ----------------------------
// Matrícula: 793605
// -----------------------------
// --- Mealy FSM para detectar 1001 apenas uma vez
// -----------------------------

// Definições de constantes
`define found 1
`define notfound 0

// FSM para reconhecer 1001 apenas uma vez
module guia_1101 (y, x, clk, reset);
  output reg y;   // Saída do FSM 
  input x;        // Entrada de dados
  input clk;      // Sinal de clock
  input reset;    // Sinal de reset
  
  // Identificadores dos estados
  parameter start = 3'b000,  // Estado inicial
            id1 = 3'b001,    // Detectou "1"
            id10 = 3'b010,   // Detectou "10"
            id100 = 3'b011,  // Detectou "100"
            id1001 = 3'b100, // Detectou "1001"
            done = 3'b101;   // Estado final

  reg [2:0] E1;  
  reg [2:0] E2;  

  // Lógica do próximo estado
  always @(x or E1) begin
    y = `notfound;  
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
          E2 = id1001;
        else
          E2 = id1;

      id1001:
        begin
          y = `found;  
          E2 = done;    
        end

      done:
        E2 = done;  

      default: 
        E2 = 3'bxxx;  
    endcase
  end

  always @(posedge clk or negedge reset) begin
    if (!reset)
      E1 <= start;  
    else
      E1 <= E2;    
  end
endmodule // Guia_1101
