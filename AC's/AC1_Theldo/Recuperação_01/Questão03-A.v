/*
    Arquitetura de Computadores I - Guia_03
    793605 - Caio Faria Diniz
*/

/* a.) (∼𝑎∣𝑏)&(𝑏∣∼𝑐) */
module expr1 (
    input a, b, c,
    output y
);
    assign y = (~a | b) & (b | ~c);
endmodule
