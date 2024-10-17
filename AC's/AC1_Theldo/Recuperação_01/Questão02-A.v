/*
    Arquitetura de Computadores I - Guia_03
    793605 - Caio Faria Diniz
*/

/* a.) Mux (a, not(a), c)*/
module mux_2to1 (
    input a, c,
    output y
);
    assign y = (a & ~a) | (~a & c);
endmodule
