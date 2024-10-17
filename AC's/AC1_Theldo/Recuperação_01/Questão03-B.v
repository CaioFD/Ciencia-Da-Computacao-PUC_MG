/*
    Arquitetura de Computadores I - Guia_03
    793605 - Caio Faria Diniz
*/

/* b.) (𝑥′.𝑦)′.(𝑥′.𝑦′)′ */

module expr1 (
    input a, b, c,
    output y
);
    assign y = (~a | b) & (b | ~c);
endmodule
