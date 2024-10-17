/*
    Arquitetura de Computadores I - Guia_03
    793605 - Caio Faria Diniz
*/

/* b.) Mux (c, not(c), mux(a, not(a), b)) */
module mux_nested (
    input a, b, c,
    output y
);
    wire mux_ab;
    assign mux_ab = (a & ~a) | (~a & b); 
    assign y = (c & ~c) | (~c & mux_ab); 
endmodule
