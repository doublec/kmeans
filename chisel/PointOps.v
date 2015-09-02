module PointOps(
    input [63:0] io_p1x,
    input [63:0] io_p1y,
    input [3:0] io_operation,
    input [63:0] io_p2x,
    input [63:0] io_p2y,
    input [63:0] io_den,
    output[63:0] io_poutx,
    output[63:0] io_pouty,
    output[63:0] io_out
);

  wire[63:0] T0;
  wire[63:0] T1;
  wire[63:0] T2;
  wire[63:0] T3;
  wire[63:0] T4;
  wire T5;
  wire T6;
  wire T7;
  wire T8;
  wire T9;
  wire T10;
  wire T11;
  wire T12;
  wire T13;
  wire T14;
  wire[63:0] T15;
  wire[63:0] T16;
  wire[63:0] T17;
  wire[63:0] T18;
  wire[63:0] T19;
  wire T20;
  wire T21;
  wire[63:0] T22;
  wire T23;
  wire T24;
  wire[63:0] T25;
  wire T26;
  wire T27;
  wire T28;
  wire T29;
  wire[63:0] T30;
  wire[63:0] T31;
  wire[63:0] T32;
  wire[63:0] T33;
  wire[63:0] T34;
  wire[63:0] T35;
  wire[63:0] T36;


  assign io_out = T0;
  assign T0 = T5 ? T1 : 64'h0;
  assign T1 = dsqrt T2;
  assign T2 = T4 d+ T3;
  assign T3 = io_p1y d* io_p1y;
  assign T4 = io_p1x d* io_p1x;
  assign T5 = T7 & T6;
  assign T6 = io_operation == 4'h4;
  assign T7 = T8 ^ 1'h1;
  assign T8 = T10 | T9;
  assign T9 = io_operation == 4'h3;
  assign T10 = T12 | T11;
  assign T11 = io_operation == 4'h2;
  assign T12 = T14 | T13;
  assign T13 = io_operation == 4'h1;
  assign T14 = io_operation == 4'h0;
  assign io_pouty = T15;
  assign T15 = T28 ? 64'h0 : T16;
  assign T16 = T26 ? T25 : T17;
  assign T17 = T23 ? T22 : T18;
  assign T18 = T20 ? T19 : 64'h0;
  assign T19 = io_p1y d+ io_p2y;
  assign T20 = T21 & T13;
  assign T21 = T14 ^ 1'h1;
  assign T22 = io_p1y d- io_p2y;
  assign T23 = T24 & T11;
  assign T24 = T12 ^ 1'h1;
  assign T25 = io_p1y d/ io_den;
  assign T26 = T27 & T9;
  assign T27 = T10 ^ 1'h1;
  assign T28 = T29 ^ 1'h1;
  assign T29 = T8 | T6;
  assign io_poutx = T30;
  assign T30 = T28 ? 64'h0 : T31;
  assign T31 = T26 ? T36 : T32;
  assign T32 = T23 ? T35 : T33;
  assign T33 = T20 ? T34 : 64'h0;
  assign T34 = io_p1x d+ io_p2x;
  assign T35 = io_p1x d- io_p2x;
  assign T36 = io_p1x d/ io_den;
endmodule

