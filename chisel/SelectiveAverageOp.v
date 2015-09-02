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

module SelectivePointOps(
    input [63:0] io_p1x,
    input [63:0] io_p1y,
    input [3:0] io_operation,
    input [63:0] io_p2x,
    input [63:0] io_p2y,
    input [63:0] io_den,
    output[63:0] io_poutx,
    output[63:0] io_pouty,
    output[63:0] io_out,
    input [31:0] io_cent
);

  wire[63:0] T0;
  wire T1;
  wire T2;
  wire T3;
  wire[63:0] T4;
  wire[63:0] po_io_poutx;
  wire[63:0] po_io_pouty;
  wire[63:0] po_io_out;


  assign io_out = po_io_out;
  assign io_pouty = T0;
  assign T0 = T1 ? io_p1y : po_io_pouty;
  assign T1 = T3 & T2;
  assign T2 = io_operation == 4'h1;
  assign T3 = io_cent != 32'h1;
  assign io_poutx = T4;
  assign T4 = T1 ? io_p1x : po_io_poutx;
  PointOps po(
       .io_p1x( io_p1x ),
       .io_p1y( io_p1y ),
       .io_operation( io_operation ),
       .io_p2x( io_p2x ),
       .io_p2y( io_p2y ),
       .io_den( io_den ),
       .io_poutx( po_io_poutx ),
       .io_pouty( po_io_pouty ),
       .io_out( po_io_out )
  );
endmodule

module IntToDblConversionOp(
    input [31:0] io_in,
    output[63:0] io_out
);

  reg [63:0] T0;
  wire[1:0] T2;


  assign io_out = T0;
  always @(*) case (T2)
    0: T0 = 64'h0;
    1: T0 = 64'h3ff0000000000000;
    2: T0 = 64'h4000000000000000;
    3: T0 = 64'h4008000000000000;
    default: begin
      T0 = 64'bx;
`ifndef SYNTHESIS
// synthesis translate_off
      T0 = {2{$random}};
// synthesis translate_on
`endif
    end
  endcase
  assign T2 = io_in[1'h1:1'h0];
endmodule

module SelectiveAverageOp(
    input [63:0] io_xs_2,
    input [63:0] io_xs_1,
    input [63:0] io_xs_0,
    input [63:0] io_ys_2,
    input [63:0] io_ys_1,
    input [63:0] io_ys_0,
    input [31:0] io_cent_2,
    input [31:0] io_cent_1,
    input [31:0] io_cent_0,
    output[63:0] io_outX,
    output[63:0] io_outY
);

  wire[31:0] T9;
  wire[2:0] count;
  wire[2:0] T0;
  wire[1:0] T1;
  wire[1:0] T2;
  wire T3;
  wire[1:0] T10;
  wire T4;
  wire[2:0] T11;
  wire T5;
  wire[63:0] T6;
  wire T7;
  wire[63:0] T8;
  wire[63:0] conv_io_out;
  wire[63:0] SelectivePointOps_io_poutx;
  wire[63:0] SelectivePointOps_io_pouty;
  wire[63:0] SelectivePointOps_1_io_poutx;
  wire[63:0] SelectivePointOps_1_io_pouty;
  wire[63:0] SelectivePointOps_2_io_poutx;
  wire[63:0] SelectivePointOps_2_io_pouty;
  wire[63:0] SelectivePointOps_3_io_poutx;
  wire[63:0] SelectivePointOps_3_io_pouty;


  assign T9 = {29'h0, count};
  assign count = T11 + T0;
  assign T0 = {1'h0, T1};
  assign T1 = T10 + T2;
  assign T2 = {1'h0, T3};
  assign T3 = io_cent_2 == 32'h1;
  assign T10 = {1'h0, T4};
  assign T4 = io_cent_1 == 32'h1;
  assign T11 = {2'h0, T5};
  assign T5 = io_cent_0 == 32'h1;
  assign io_outY = T6;
  assign T6 = T7 ? 64'h0 : SelectivePointOps_3_io_pouty;
  assign T7 = count <= 3'h0;
  assign io_outX = T8;
  assign T8 = T7 ? 64'h0 : SelectivePointOps_3_io_poutx;
  SelectivePointOps SelectivePointOps(
       .io_p1x( 64'h0 ),
       .io_p1y( 64'h0 ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_0 ),
       .io_p2y( io_ys_0 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_io_poutx ),
       .io_pouty( SelectivePointOps_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_0 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps SelectivePointOps_1(
       .io_p1x( SelectivePointOps_io_poutx ),
       .io_p1y( SelectivePointOps_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_1 ),
       .io_p2y( io_ys_1 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_1_io_poutx ),
       .io_pouty( SelectivePointOps_1_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_1 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_1.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps SelectivePointOps_2(
       .io_p1x( SelectivePointOps_1_io_poutx ),
       .io_p1y( SelectivePointOps_1_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_2 ),
       .io_p2y( io_ys_2 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_2_io_poutx ),
       .io_pouty( SelectivePointOps_2_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_2 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_2.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps SelectivePointOps_3(
       .io_p1x( SelectivePointOps_2_io_poutx ),
       .io_p1y( SelectivePointOps_2_io_pouty ),
       .io_operation( 4'h3 ),
       //.io_p2x(  )
       //.io_p2y(  )
       .io_den( conv_io_out ),
       .io_poutx( SelectivePointOps_3_io_poutx ),
       .io_pouty( SelectivePointOps_3_io_pouty )
       //.io_out(  )
       //.io_cent(  )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_3.io_p2x = {2{$random}};
    assign SelectivePointOps_3.io_p2y = {2{$random}};
    assign SelectivePointOps_3.io_cent = {1{$random}};
// synthesis translate_on
`endif
  IntToDblConversionOp conv(
       .io_in( T9 ),
       .io_out( conv_io_out )
  );
endmodule

