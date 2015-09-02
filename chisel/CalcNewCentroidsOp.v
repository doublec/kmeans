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

module SelectivePointOps_0(
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
  assign T3 = io_cent != 32'h0;
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
  wire[3:0] T2;


  assign io_out = T0;
  always @(*) case (T2)
    0: T0 = 64'h0;
    1: T0 = 64'h3ff0000000000000;
    2: T0 = 64'h4000000000000000;
    3: T0 = 64'h4008000000000000;
    4: T0 = 64'h4010000000000000;
    5: T0 = 64'h4014000000000000;
    6: T0 = 64'h4018000000000000;
    7: T0 = 64'h401c000000000000;
    8: T0 = 64'h4020000000000000;
    9: T0 = 64'h4022000000000000;
    10: T0 = 64'h4024000000000000;
    default: begin
      T0 = 64'bx;
`ifndef SYNTHESIS
// synthesis translate_off
      T0 = {2{$random}};
// synthesis translate_on
`endif
    end
  endcase
  assign T2 = io_in[2'h3:1'h0];
endmodule

module SelectiveAverageOp_0(
    input [63:0] io_xs_9,
    input [63:0] io_xs_8,
    input [63:0] io_xs_7,
    input [63:0] io_xs_6,
    input [63:0] io_xs_5,
    input [63:0] io_xs_4,
    input [63:0] io_xs_3,
    input [63:0] io_xs_2,
    input [63:0] io_xs_1,
    input [63:0] io_xs_0,
    input [63:0] io_ys_9,
    input [63:0] io_ys_8,
    input [63:0] io_ys_7,
    input [63:0] io_ys_6,
    input [63:0] io_ys_5,
    input [63:0] io_ys_4,
    input [63:0] io_ys_3,
    input [63:0] io_ys_2,
    input [63:0] io_ys_1,
    input [63:0] io_ys_0,
    input [31:0] io_cent_9,
    input [31:0] io_cent_8,
    input [31:0] io_cent_7,
    input [31:0] io_cent_6,
    input [31:0] io_cent_5,
    input [31:0] io_cent_4,
    input [31:0] io_cent_3,
    input [31:0] io_cent_2,
    input [31:0] io_cent_1,
    input [31:0] io_cent_0,
    output[63:0] io_outX,
    output[63:0] io_outY
);

  wire[31:0] T30;
  wire[4:0] count;
  wire[4:0] T0;
  wire[3:0] T1;
  wire[3:0] T2;
  wire[2:0] T3;
  wire[2:0] T4;
  wire[1:0] T5;
  wire[1:0] T6;
  wire T7;
  wire[1:0] T31;
  wire T8;
  wire[2:0] T32;
  wire T9;
  wire[3:0] T33;
  wire[1:0] T10;
  wire[1:0] T11;
  wire T12;
  wire[1:0] T34;
  wire T13;
  wire[4:0] T35;
  wire[3:0] T14;
  wire[3:0] T15;
  wire[2:0] T16;
  wire[2:0] T17;
  wire[1:0] T18;
  wire[1:0] T19;
  wire T20;
  wire[1:0] T36;
  wire T21;
  wire[2:0] T37;
  wire T22;
  wire[3:0] T38;
  wire[1:0] T23;
  wire[1:0] T24;
  wire T25;
  wire[1:0] T39;
  wire T26;
  wire[63:0] T27;
  wire T28;
  wire[63:0] T29;
  wire[63:0] conv_io_out;
  wire[63:0] SelectivePointOps_io_poutx;
  wire[63:0] SelectivePointOps_io_pouty;
  wire[63:0] SelectivePointOps_1_io_poutx;
  wire[63:0] SelectivePointOps_1_io_pouty;
  wire[63:0] SelectivePointOps_2_io_poutx;
  wire[63:0] SelectivePointOps_2_io_pouty;
  wire[63:0] SelectivePointOps_3_io_poutx;
  wire[63:0] SelectivePointOps_3_io_pouty;
  wire[63:0] SelectivePointOps_4_io_poutx;
  wire[63:0] SelectivePointOps_4_io_pouty;
  wire[63:0] SelectivePointOps_5_io_poutx;
  wire[63:0] SelectivePointOps_5_io_pouty;
  wire[63:0] SelectivePointOps_6_io_poutx;
  wire[63:0] SelectivePointOps_6_io_pouty;
  wire[63:0] SelectivePointOps_7_io_poutx;
  wire[63:0] SelectivePointOps_7_io_pouty;
  wire[63:0] SelectivePointOps_8_io_poutx;
  wire[63:0] SelectivePointOps_8_io_pouty;
  wire[63:0] SelectivePointOps_9_io_poutx;
  wire[63:0] SelectivePointOps_9_io_pouty;
  wire[63:0] SelectivePointOps_10_io_poutx;
  wire[63:0] SelectivePointOps_10_io_pouty;


  assign T30 = {27'h0, count};
  assign count = T35 + T0;
  assign T0 = {1'h0, T1};
  assign T1 = T33 + T2;
  assign T2 = {1'h0, T3};
  assign T3 = T32 + T4;
  assign T4 = {1'h0, T5};
  assign T5 = T31 + T6;
  assign T6 = {1'h0, T7};
  assign T7 = io_cent_9 == 32'h0;
  assign T31 = {1'h0, T8};
  assign T8 = io_cent_8 == 32'h0;
  assign T32 = {2'h0, T9};
  assign T9 = io_cent_7 == 32'h0;
  assign T33 = {2'h0, T10};
  assign T10 = T34 + T11;
  assign T11 = {1'h0, T12};
  assign T12 = io_cent_6 == 32'h0;
  assign T34 = {1'h0, T13};
  assign T13 = io_cent_5 == 32'h0;
  assign T35 = {1'h0, T14};
  assign T14 = T38 + T15;
  assign T15 = {1'h0, T16};
  assign T16 = T37 + T17;
  assign T17 = {1'h0, T18};
  assign T18 = T36 + T19;
  assign T19 = {1'h0, T20};
  assign T20 = io_cent_4 == 32'h0;
  assign T36 = {1'h0, T21};
  assign T21 = io_cent_3 == 32'h0;
  assign T37 = {2'h0, T22};
  assign T22 = io_cent_2 == 32'h0;
  assign T38 = {2'h0, T23};
  assign T23 = T39 + T24;
  assign T24 = {1'h0, T25};
  assign T25 = io_cent_1 == 32'h0;
  assign T39 = {1'h0, T26};
  assign T26 = io_cent_0 == 32'h0;
  assign io_outY = T27;
  assign T27 = T28 ? 64'h0 : SelectivePointOps_10_io_pouty;
  assign T28 = count <= 5'h0;
  assign io_outX = T29;
  assign T29 = T28 ? 64'h0 : SelectivePointOps_10_io_poutx;
  SelectivePointOps_0 SelectivePointOps(
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
  SelectivePointOps_0 SelectivePointOps_1(
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
  SelectivePointOps_0 SelectivePointOps_2(
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
  SelectivePointOps_0 SelectivePointOps_3(
       .io_p1x( SelectivePointOps_2_io_poutx ),
       .io_p1y( SelectivePointOps_2_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_3 ),
       .io_p2y( io_ys_3 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_3_io_poutx ),
       .io_pouty( SelectivePointOps_3_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_3 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_3.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_0 SelectivePointOps_4(
       .io_p1x( SelectivePointOps_3_io_poutx ),
       .io_p1y( SelectivePointOps_3_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_4 ),
       .io_p2y( io_ys_4 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_4_io_poutx ),
       .io_pouty( SelectivePointOps_4_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_4 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_4.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_0 SelectivePointOps_5(
       .io_p1x( SelectivePointOps_4_io_poutx ),
       .io_p1y( SelectivePointOps_4_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_5 ),
       .io_p2y( io_ys_5 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_5_io_poutx ),
       .io_pouty( SelectivePointOps_5_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_5 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_5.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_0 SelectivePointOps_6(
       .io_p1x( SelectivePointOps_5_io_poutx ),
       .io_p1y( SelectivePointOps_5_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_6 ),
       .io_p2y( io_ys_6 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_6_io_poutx ),
       .io_pouty( SelectivePointOps_6_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_6 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_6.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_0 SelectivePointOps_7(
       .io_p1x( SelectivePointOps_6_io_poutx ),
       .io_p1y( SelectivePointOps_6_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_7 ),
       .io_p2y( io_ys_7 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_7_io_poutx ),
       .io_pouty( SelectivePointOps_7_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_7 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_7.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_0 SelectivePointOps_8(
       .io_p1x( SelectivePointOps_7_io_poutx ),
       .io_p1y( SelectivePointOps_7_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_8 ),
       .io_p2y( io_ys_8 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_8_io_poutx ),
       .io_pouty( SelectivePointOps_8_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_8 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_8.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_0 SelectivePointOps_9(
       .io_p1x( SelectivePointOps_8_io_poutx ),
       .io_p1y( SelectivePointOps_8_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_9 ),
       .io_p2y( io_ys_9 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_9_io_poutx ),
       .io_pouty( SelectivePointOps_9_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_9 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_9.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_0 SelectivePointOps_10(
       .io_p1x( SelectivePointOps_9_io_poutx ),
       .io_p1y( SelectivePointOps_9_io_pouty ),
       .io_operation( 4'h3 ),
       //.io_p2x(  )
       //.io_p2y(  )
       .io_den( conv_io_out ),
       .io_poutx( SelectivePointOps_10_io_poutx ),
       .io_pouty( SelectivePointOps_10_io_pouty )
       //.io_out(  )
       //.io_cent(  )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_10.io_p2x = {2{$random}};
    assign SelectivePointOps_10.io_p2y = {2{$random}};
    assign SelectivePointOps_10.io_cent = {1{$random}};
// synthesis translate_on
`endif
  IntToDblConversionOp conv(
       .io_in( T30 ),
       .io_out( conv_io_out )
  );
endmodule

module SelectivePointOps_1(
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

module SelectiveAverageOp_1(
    input [63:0] io_xs_9,
    input [63:0] io_xs_8,
    input [63:0] io_xs_7,
    input [63:0] io_xs_6,
    input [63:0] io_xs_5,
    input [63:0] io_xs_4,
    input [63:0] io_xs_3,
    input [63:0] io_xs_2,
    input [63:0] io_xs_1,
    input [63:0] io_xs_0,
    input [63:0] io_ys_9,
    input [63:0] io_ys_8,
    input [63:0] io_ys_7,
    input [63:0] io_ys_6,
    input [63:0] io_ys_5,
    input [63:0] io_ys_4,
    input [63:0] io_ys_3,
    input [63:0] io_ys_2,
    input [63:0] io_ys_1,
    input [63:0] io_ys_0,
    input [31:0] io_cent_9,
    input [31:0] io_cent_8,
    input [31:0] io_cent_7,
    input [31:0] io_cent_6,
    input [31:0] io_cent_5,
    input [31:0] io_cent_4,
    input [31:0] io_cent_3,
    input [31:0] io_cent_2,
    input [31:0] io_cent_1,
    input [31:0] io_cent_0,
    output[63:0] io_outX,
    output[63:0] io_outY
);

  wire[31:0] T30;
  wire[4:0] count;
  wire[4:0] T0;
  wire[3:0] T1;
  wire[3:0] T2;
  wire[2:0] T3;
  wire[2:0] T4;
  wire[1:0] T5;
  wire[1:0] T6;
  wire T7;
  wire[1:0] T31;
  wire T8;
  wire[2:0] T32;
  wire T9;
  wire[3:0] T33;
  wire[1:0] T10;
  wire[1:0] T11;
  wire T12;
  wire[1:0] T34;
  wire T13;
  wire[4:0] T35;
  wire[3:0] T14;
  wire[3:0] T15;
  wire[2:0] T16;
  wire[2:0] T17;
  wire[1:0] T18;
  wire[1:0] T19;
  wire T20;
  wire[1:0] T36;
  wire T21;
  wire[2:0] T37;
  wire T22;
  wire[3:0] T38;
  wire[1:0] T23;
  wire[1:0] T24;
  wire T25;
  wire[1:0] T39;
  wire T26;
  wire[63:0] T27;
  wire T28;
  wire[63:0] T29;
  wire[63:0] conv_io_out;
  wire[63:0] SelectivePointOps_io_poutx;
  wire[63:0] SelectivePointOps_io_pouty;
  wire[63:0] SelectivePointOps_1_io_poutx;
  wire[63:0] SelectivePointOps_1_io_pouty;
  wire[63:0] SelectivePointOps_2_io_poutx;
  wire[63:0] SelectivePointOps_2_io_pouty;
  wire[63:0] SelectivePointOps_3_io_poutx;
  wire[63:0] SelectivePointOps_3_io_pouty;
  wire[63:0] SelectivePointOps_4_io_poutx;
  wire[63:0] SelectivePointOps_4_io_pouty;
  wire[63:0] SelectivePointOps_5_io_poutx;
  wire[63:0] SelectivePointOps_5_io_pouty;
  wire[63:0] SelectivePointOps_6_io_poutx;
  wire[63:0] SelectivePointOps_6_io_pouty;
  wire[63:0] SelectivePointOps_7_io_poutx;
  wire[63:0] SelectivePointOps_7_io_pouty;
  wire[63:0] SelectivePointOps_8_io_poutx;
  wire[63:0] SelectivePointOps_8_io_pouty;
  wire[63:0] SelectivePointOps_9_io_poutx;
  wire[63:0] SelectivePointOps_9_io_pouty;
  wire[63:0] SelectivePointOps_10_io_poutx;
  wire[63:0] SelectivePointOps_10_io_pouty;


  assign T30 = {27'h0, count};
  assign count = T35 + T0;
  assign T0 = {1'h0, T1};
  assign T1 = T33 + T2;
  assign T2 = {1'h0, T3};
  assign T3 = T32 + T4;
  assign T4 = {1'h0, T5};
  assign T5 = T31 + T6;
  assign T6 = {1'h0, T7};
  assign T7 = io_cent_9 == 32'h1;
  assign T31 = {1'h0, T8};
  assign T8 = io_cent_8 == 32'h1;
  assign T32 = {2'h0, T9};
  assign T9 = io_cent_7 == 32'h1;
  assign T33 = {2'h0, T10};
  assign T10 = T34 + T11;
  assign T11 = {1'h0, T12};
  assign T12 = io_cent_6 == 32'h1;
  assign T34 = {1'h0, T13};
  assign T13 = io_cent_5 == 32'h1;
  assign T35 = {1'h0, T14};
  assign T14 = T38 + T15;
  assign T15 = {1'h0, T16};
  assign T16 = T37 + T17;
  assign T17 = {1'h0, T18};
  assign T18 = T36 + T19;
  assign T19 = {1'h0, T20};
  assign T20 = io_cent_4 == 32'h1;
  assign T36 = {1'h0, T21};
  assign T21 = io_cent_3 == 32'h1;
  assign T37 = {2'h0, T22};
  assign T22 = io_cent_2 == 32'h1;
  assign T38 = {2'h0, T23};
  assign T23 = T39 + T24;
  assign T24 = {1'h0, T25};
  assign T25 = io_cent_1 == 32'h1;
  assign T39 = {1'h0, T26};
  assign T26 = io_cent_0 == 32'h1;
  assign io_outY = T27;
  assign T27 = T28 ? 64'h0 : SelectivePointOps_10_io_pouty;
  assign T28 = count <= 5'h0;
  assign io_outX = T29;
  assign T29 = T28 ? 64'h0 : SelectivePointOps_10_io_poutx;
  SelectivePointOps_1 SelectivePointOps(
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
  SelectivePointOps_1 SelectivePointOps_1(
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
  SelectivePointOps_1 SelectivePointOps_2(
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
  SelectivePointOps_1 SelectivePointOps_3(
       .io_p1x( SelectivePointOps_2_io_poutx ),
       .io_p1y( SelectivePointOps_2_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_3 ),
       .io_p2y( io_ys_3 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_3_io_poutx ),
       .io_pouty( SelectivePointOps_3_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_3 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_3.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_1 SelectivePointOps_4(
       .io_p1x( SelectivePointOps_3_io_poutx ),
       .io_p1y( SelectivePointOps_3_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_4 ),
       .io_p2y( io_ys_4 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_4_io_poutx ),
       .io_pouty( SelectivePointOps_4_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_4 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_4.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_1 SelectivePointOps_5(
       .io_p1x( SelectivePointOps_4_io_poutx ),
       .io_p1y( SelectivePointOps_4_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_5 ),
       .io_p2y( io_ys_5 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_5_io_poutx ),
       .io_pouty( SelectivePointOps_5_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_5 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_5.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_1 SelectivePointOps_6(
       .io_p1x( SelectivePointOps_5_io_poutx ),
       .io_p1y( SelectivePointOps_5_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_6 ),
       .io_p2y( io_ys_6 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_6_io_poutx ),
       .io_pouty( SelectivePointOps_6_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_6 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_6.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_1 SelectivePointOps_7(
       .io_p1x( SelectivePointOps_6_io_poutx ),
       .io_p1y( SelectivePointOps_6_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_7 ),
       .io_p2y( io_ys_7 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_7_io_poutx ),
       .io_pouty( SelectivePointOps_7_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_7 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_7.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_1 SelectivePointOps_8(
       .io_p1x( SelectivePointOps_7_io_poutx ),
       .io_p1y( SelectivePointOps_7_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_8 ),
       .io_p2y( io_ys_8 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_8_io_poutx ),
       .io_pouty( SelectivePointOps_8_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_8 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_8.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_1 SelectivePointOps_9(
       .io_p1x( SelectivePointOps_8_io_poutx ),
       .io_p1y( SelectivePointOps_8_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_9 ),
       .io_p2y( io_ys_9 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_9_io_poutx ),
       .io_pouty( SelectivePointOps_9_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_9 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_9.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_1 SelectivePointOps_10(
       .io_p1x( SelectivePointOps_9_io_poutx ),
       .io_p1y( SelectivePointOps_9_io_pouty ),
       .io_operation( 4'h3 ),
       //.io_p2x(  )
       //.io_p2y(  )
       .io_den( conv_io_out ),
       .io_poutx( SelectivePointOps_10_io_poutx ),
       .io_pouty( SelectivePointOps_10_io_pouty )
       //.io_out(  )
       //.io_cent(  )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_10.io_p2x = {2{$random}};
    assign SelectivePointOps_10.io_p2y = {2{$random}};
    assign SelectivePointOps_10.io_cent = {1{$random}};
// synthesis translate_on
`endif
  IntToDblConversionOp conv(
       .io_in( T30 ),
       .io_out( conv_io_out )
  );
endmodule

module SelectivePointOps_2(
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
  assign T3 = io_cent != 32'h2;
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

module SelectiveAverageOp_2(
    input [63:0] io_xs_9,
    input [63:0] io_xs_8,
    input [63:0] io_xs_7,
    input [63:0] io_xs_6,
    input [63:0] io_xs_5,
    input [63:0] io_xs_4,
    input [63:0] io_xs_3,
    input [63:0] io_xs_2,
    input [63:0] io_xs_1,
    input [63:0] io_xs_0,
    input [63:0] io_ys_9,
    input [63:0] io_ys_8,
    input [63:0] io_ys_7,
    input [63:0] io_ys_6,
    input [63:0] io_ys_5,
    input [63:0] io_ys_4,
    input [63:0] io_ys_3,
    input [63:0] io_ys_2,
    input [63:0] io_ys_1,
    input [63:0] io_ys_0,
    input [31:0] io_cent_9,
    input [31:0] io_cent_8,
    input [31:0] io_cent_7,
    input [31:0] io_cent_6,
    input [31:0] io_cent_5,
    input [31:0] io_cent_4,
    input [31:0] io_cent_3,
    input [31:0] io_cent_2,
    input [31:0] io_cent_1,
    input [31:0] io_cent_0,
    output[63:0] io_outX,
    output[63:0] io_outY
);

  wire[31:0] T30;
  wire[4:0] count;
  wire[4:0] T0;
  wire[3:0] T1;
  wire[3:0] T2;
  wire[2:0] T3;
  wire[2:0] T4;
  wire[1:0] T5;
  wire[1:0] T6;
  wire T7;
  wire[1:0] T31;
  wire T8;
  wire[2:0] T32;
  wire T9;
  wire[3:0] T33;
  wire[1:0] T10;
  wire[1:0] T11;
  wire T12;
  wire[1:0] T34;
  wire T13;
  wire[4:0] T35;
  wire[3:0] T14;
  wire[3:0] T15;
  wire[2:0] T16;
  wire[2:0] T17;
  wire[1:0] T18;
  wire[1:0] T19;
  wire T20;
  wire[1:0] T36;
  wire T21;
  wire[2:0] T37;
  wire T22;
  wire[3:0] T38;
  wire[1:0] T23;
  wire[1:0] T24;
  wire T25;
  wire[1:0] T39;
  wire T26;
  wire[63:0] T27;
  wire T28;
  wire[63:0] T29;
  wire[63:0] conv_io_out;
  wire[63:0] SelectivePointOps_io_poutx;
  wire[63:0] SelectivePointOps_io_pouty;
  wire[63:0] SelectivePointOps_1_io_poutx;
  wire[63:0] SelectivePointOps_1_io_pouty;
  wire[63:0] SelectivePointOps_2_io_poutx;
  wire[63:0] SelectivePointOps_2_io_pouty;
  wire[63:0] SelectivePointOps_3_io_poutx;
  wire[63:0] SelectivePointOps_3_io_pouty;
  wire[63:0] SelectivePointOps_4_io_poutx;
  wire[63:0] SelectivePointOps_4_io_pouty;
  wire[63:0] SelectivePointOps_5_io_poutx;
  wire[63:0] SelectivePointOps_5_io_pouty;
  wire[63:0] SelectivePointOps_6_io_poutx;
  wire[63:0] SelectivePointOps_6_io_pouty;
  wire[63:0] SelectivePointOps_7_io_poutx;
  wire[63:0] SelectivePointOps_7_io_pouty;
  wire[63:0] SelectivePointOps_8_io_poutx;
  wire[63:0] SelectivePointOps_8_io_pouty;
  wire[63:0] SelectivePointOps_9_io_poutx;
  wire[63:0] SelectivePointOps_9_io_pouty;
  wire[63:0] SelectivePointOps_10_io_poutx;
  wire[63:0] SelectivePointOps_10_io_pouty;


  assign T30 = {27'h0, count};
  assign count = T35 + T0;
  assign T0 = {1'h0, T1};
  assign T1 = T33 + T2;
  assign T2 = {1'h0, T3};
  assign T3 = T32 + T4;
  assign T4 = {1'h0, T5};
  assign T5 = T31 + T6;
  assign T6 = {1'h0, T7};
  assign T7 = io_cent_9 == 32'h2;
  assign T31 = {1'h0, T8};
  assign T8 = io_cent_8 == 32'h2;
  assign T32 = {2'h0, T9};
  assign T9 = io_cent_7 == 32'h2;
  assign T33 = {2'h0, T10};
  assign T10 = T34 + T11;
  assign T11 = {1'h0, T12};
  assign T12 = io_cent_6 == 32'h2;
  assign T34 = {1'h0, T13};
  assign T13 = io_cent_5 == 32'h2;
  assign T35 = {1'h0, T14};
  assign T14 = T38 + T15;
  assign T15 = {1'h0, T16};
  assign T16 = T37 + T17;
  assign T17 = {1'h0, T18};
  assign T18 = T36 + T19;
  assign T19 = {1'h0, T20};
  assign T20 = io_cent_4 == 32'h2;
  assign T36 = {1'h0, T21};
  assign T21 = io_cent_3 == 32'h2;
  assign T37 = {2'h0, T22};
  assign T22 = io_cent_2 == 32'h2;
  assign T38 = {2'h0, T23};
  assign T23 = T39 + T24;
  assign T24 = {1'h0, T25};
  assign T25 = io_cent_1 == 32'h2;
  assign T39 = {1'h0, T26};
  assign T26 = io_cent_0 == 32'h2;
  assign io_outY = T27;
  assign T27 = T28 ? 64'h0 : SelectivePointOps_10_io_pouty;
  assign T28 = count <= 5'h0;
  assign io_outX = T29;
  assign T29 = T28 ? 64'h0 : SelectivePointOps_10_io_poutx;
  SelectivePointOps_2 SelectivePointOps(
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
  SelectivePointOps_2 SelectivePointOps_1(
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
  SelectivePointOps_2 SelectivePointOps_2(
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
  SelectivePointOps_2 SelectivePointOps_3(
       .io_p1x( SelectivePointOps_2_io_poutx ),
       .io_p1y( SelectivePointOps_2_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_3 ),
       .io_p2y( io_ys_3 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_3_io_poutx ),
       .io_pouty( SelectivePointOps_3_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_3 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_3.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_2 SelectivePointOps_4(
       .io_p1x( SelectivePointOps_3_io_poutx ),
       .io_p1y( SelectivePointOps_3_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_4 ),
       .io_p2y( io_ys_4 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_4_io_poutx ),
       .io_pouty( SelectivePointOps_4_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_4 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_4.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_2 SelectivePointOps_5(
       .io_p1x( SelectivePointOps_4_io_poutx ),
       .io_p1y( SelectivePointOps_4_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_5 ),
       .io_p2y( io_ys_5 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_5_io_poutx ),
       .io_pouty( SelectivePointOps_5_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_5 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_5.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_2 SelectivePointOps_6(
       .io_p1x( SelectivePointOps_5_io_poutx ),
       .io_p1y( SelectivePointOps_5_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_6 ),
       .io_p2y( io_ys_6 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_6_io_poutx ),
       .io_pouty( SelectivePointOps_6_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_6 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_6.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_2 SelectivePointOps_7(
       .io_p1x( SelectivePointOps_6_io_poutx ),
       .io_p1y( SelectivePointOps_6_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_7 ),
       .io_p2y( io_ys_7 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_7_io_poutx ),
       .io_pouty( SelectivePointOps_7_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_7 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_7.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_2 SelectivePointOps_8(
       .io_p1x( SelectivePointOps_7_io_poutx ),
       .io_p1y( SelectivePointOps_7_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_8 ),
       .io_p2y( io_ys_8 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_8_io_poutx ),
       .io_pouty( SelectivePointOps_8_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_8 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_8.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_2 SelectivePointOps_9(
       .io_p1x( SelectivePointOps_8_io_poutx ),
       .io_p1y( SelectivePointOps_8_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_9 ),
       .io_p2y( io_ys_9 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_9_io_poutx ),
       .io_pouty( SelectivePointOps_9_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_9 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_9.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_2 SelectivePointOps_10(
       .io_p1x( SelectivePointOps_9_io_poutx ),
       .io_p1y( SelectivePointOps_9_io_pouty ),
       .io_operation( 4'h3 ),
       //.io_p2x(  )
       //.io_p2y(  )
       .io_den( conv_io_out ),
       .io_poutx( SelectivePointOps_10_io_poutx ),
       .io_pouty( SelectivePointOps_10_io_pouty )
       //.io_out(  )
       //.io_cent(  )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_10.io_p2x = {2{$random}};
    assign SelectivePointOps_10.io_p2y = {2{$random}};
    assign SelectivePointOps_10.io_cent = {1{$random}};
// synthesis translate_on
`endif
  IntToDblConversionOp conv(
       .io_in( T30 ),
       .io_out( conv_io_out )
  );
endmodule

module SelectivePointOps_3(
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
  assign T3 = io_cent != 32'h3;
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

module SelectiveAverageOp_3(
    input [63:0] io_xs_9,
    input [63:0] io_xs_8,
    input [63:0] io_xs_7,
    input [63:0] io_xs_6,
    input [63:0] io_xs_5,
    input [63:0] io_xs_4,
    input [63:0] io_xs_3,
    input [63:0] io_xs_2,
    input [63:0] io_xs_1,
    input [63:0] io_xs_0,
    input [63:0] io_ys_9,
    input [63:0] io_ys_8,
    input [63:0] io_ys_7,
    input [63:0] io_ys_6,
    input [63:0] io_ys_5,
    input [63:0] io_ys_4,
    input [63:0] io_ys_3,
    input [63:0] io_ys_2,
    input [63:0] io_ys_1,
    input [63:0] io_ys_0,
    input [31:0] io_cent_9,
    input [31:0] io_cent_8,
    input [31:0] io_cent_7,
    input [31:0] io_cent_6,
    input [31:0] io_cent_5,
    input [31:0] io_cent_4,
    input [31:0] io_cent_3,
    input [31:0] io_cent_2,
    input [31:0] io_cent_1,
    input [31:0] io_cent_0,
    output[63:0] io_outX,
    output[63:0] io_outY
);

  wire[31:0] T30;
  wire[4:0] count;
  wire[4:0] T0;
  wire[3:0] T1;
  wire[3:0] T2;
  wire[2:0] T3;
  wire[2:0] T4;
  wire[1:0] T5;
  wire[1:0] T6;
  wire T7;
  wire[1:0] T31;
  wire T8;
  wire[2:0] T32;
  wire T9;
  wire[3:0] T33;
  wire[1:0] T10;
  wire[1:0] T11;
  wire T12;
  wire[1:0] T34;
  wire T13;
  wire[4:0] T35;
  wire[3:0] T14;
  wire[3:0] T15;
  wire[2:0] T16;
  wire[2:0] T17;
  wire[1:0] T18;
  wire[1:0] T19;
  wire T20;
  wire[1:0] T36;
  wire T21;
  wire[2:0] T37;
  wire T22;
  wire[3:0] T38;
  wire[1:0] T23;
  wire[1:0] T24;
  wire T25;
  wire[1:0] T39;
  wire T26;
  wire[63:0] T27;
  wire T28;
  wire[63:0] T29;
  wire[63:0] conv_io_out;
  wire[63:0] SelectivePointOps_io_poutx;
  wire[63:0] SelectivePointOps_io_pouty;
  wire[63:0] SelectivePointOps_1_io_poutx;
  wire[63:0] SelectivePointOps_1_io_pouty;
  wire[63:0] SelectivePointOps_2_io_poutx;
  wire[63:0] SelectivePointOps_2_io_pouty;
  wire[63:0] SelectivePointOps_3_io_poutx;
  wire[63:0] SelectivePointOps_3_io_pouty;
  wire[63:0] SelectivePointOps_4_io_poutx;
  wire[63:0] SelectivePointOps_4_io_pouty;
  wire[63:0] SelectivePointOps_5_io_poutx;
  wire[63:0] SelectivePointOps_5_io_pouty;
  wire[63:0] SelectivePointOps_6_io_poutx;
  wire[63:0] SelectivePointOps_6_io_pouty;
  wire[63:0] SelectivePointOps_7_io_poutx;
  wire[63:0] SelectivePointOps_7_io_pouty;
  wire[63:0] SelectivePointOps_8_io_poutx;
  wire[63:0] SelectivePointOps_8_io_pouty;
  wire[63:0] SelectivePointOps_9_io_poutx;
  wire[63:0] SelectivePointOps_9_io_pouty;
  wire[63:0] SelectivePointOps_10_io_poutx;
  wire[63:0] SelectivePointOps_10_io_pouty;


  assign T30 = {27'h0, count};
  assign count = T35 + T0;
  assign T0 = {1'h0, T1};
  assign T1 = T33 + T2;
  assign T2 = {1'h0, T3};
  assign T3 = T32 + T4;
  assign T4 = {1'h0, T5};
  assign T5 = T31 + T6;
  assign T6 = {1'h0, T7};
  assign T7 = io_cent_9 == 32'h3;
  assign T31 = {1'h0, T8};
  assign T8 = io_cent_8 == 32'h3;
  assign T32 = {2'h0, T9};
  assign T9 = io_cent_7 == 32'h3;
  assign T33 = {2'h0, T10};
  assign T10 = T34 + T11;
  assign T11 = {1'h0, T12};
  assign T12 = io_cent_6 == 32'h3;
  assign T34 = {1'h0, T13};
  assign T13 = io_cent_5 == 32'h3;
  assign T35 = {1'h0, T14};
  assign T14 = T38 + T15;
  assign T15 = {1'h0, T16};
  assign T16 = T37 + T17;
  assign T17 = {1'h0, T18};
  assign T18 = T36 + T19;
  assign T19 = {1'h0, T20};
  assign T20 = io_cent_4 == 32'h3;
  assign T36 = {1'h0, T21};
  assign T21 = io_cent_3 == 32'h3;
  assign T37 = {2'h0, T22};
  assign T22 = io_cent_2 == 32'h3;
  assign T38 = {2'h0, T23};
  assign T23 = T39 + T24;
  assign T24 = {1'h0, T25};
  assign T25 = io_cent_1 == 32'h3;
  assign T39 = {1'h0, T26};
  assign T26 = io_cent_0 == 32'h3;
  assign io_outY = T27;
  assign T27 = T28 ? 64'h0 : SelectivePointOps_10_io_pouty;
  assign T28 = count <= 5'h0;
  assign io_outX = T29;
  assign T29 = T28 ? 64'h0 : SelectivePointOps_10_io_poutx;
  SelectivePointOps_3 SelectivePointOps(
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
  SelectivePointOps_3 SelectivePointOps_1(
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
  SelectivePointOps_3 SelectivePointOps_2(
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
  SelectivePointOps_3 SelectivePointOps_3(
       .io_p1x( SelectivePointOps_2_io_poutx ),
       .io_p1y( SelectivePointOps_2_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_3 ),
       .io_p2y( io_ys_3 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_3_io_poutx ),
       .io_pouty( SelectivePointOps_3_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_3 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_3.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_3 SelectivePointOps_4(
       .io_p1x( SelectivePointOps_3_io_poutx ),
       .io_p1y( SelectivePointOps_3_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_4 ),
       .io_p2y( io_ys_4 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_4_io_poutx ),
       .io_pouty( SelectivePointOps_4_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_4 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_4.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_3 SelectivePointOps_5(
       .io_p1x( SelectivePointOps_4_io_poutx ),
       .io_p1y( SelectivePointOps_4_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_5 ),
       .io_p2y( io_ys_5 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_5_io_poutx ),
       .io_pouty( SelectivePointOps_5_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_5 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_5.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_3 SelectivePointOps_6(
       .io_p1x( SelectivePointOps_5_io_poutx ),
       .io_p1y( SelectivePointOps_5_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_6 ),
       .io_p2y( io_ys_6 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_6_io_poutx ),
       .io_pouty( SelectivePointOps_6_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_6 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_6.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_3 SelectivePointOps_7(
       .io_p1x( SelectivePointOps_6_io_poutx ),
       .io_p1y( SelectivePointOps_6_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_7 ),
       .io_p2y( io_ys_7 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_7_io_poutx ),
       .io_pouty( SelectivePointOps_7_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_7 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_7.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_3 SelectivePointOps_8(
       .io_p1x( SelectivePointOps_7_io_poutx ),
       .io_p1y( SelectivePointOps_7_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_8 ),
       .io_p2y( io_ys_8 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_8_io_poutx ),
       .io_pouty( SelectivePointOps_8_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_8 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_8.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_3 SelectivePointOps_9(
       .io_p1x( SelectivePointOps_8_io_poutx ),
       .io_p1y( SelectivePointOps_8_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_9 ),
       .io_p2y( io_ys_9 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_9_io_poutx ),
       .io_pouty( SelectivePointOps_9_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_9 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_9.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_3 SelectivePointOps_10(
       .io_p1x( SelectivePointOps_9_io_poutx ),
       .io_p1y( SelectivePointOps_9_io_pouty ),
       .io_operation( 4'h3 ),
       //.io_p2x(  )
       //.io_p2y(  )
       .io_den( conv_io_out ),
       .io_poutx( SelectivePointOps_10_io_poutx ),
       .io_pouty( SelectivePointOps_10_io_pouty )
       //.io_out(  )
       //.io_cent(  )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_10.io_p2x = {2{$random}};
    assign SelectivePointOps_10.io_p2y = {2{$random}};
    assign SelectivePointOps_10.io_cent = {1{$random}};
// synthesis translate_on
`endif
  IntToDblConversionOp conv(
       .io_in( T30 ),
       .io_out( conv_io_out )
  );
endmodule

module SelectivePointOps_4(
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
  assign T3 = io_cent != 32'h4;
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

module SelectiveAverageOp_4(
    input [63:0] io_xs_9,
    input [63:0] io_xs_8,
    input [63:0] io_xs_7,
    input [63:0] io_xs_6,
    input [63:0] io_xs_5,
    input [63:0] io_xs_4,
    input [63:0] io_xs_3,
    input [63:0] io_xs_2,
    input [63:0] io_xs_1,
    input [63:0] io_xs_0,
    input [63:0] io_ys_9,
    input [63:0] io_ys_8,
    input [63:0] io_ys_7,
    input [63:0] io_ys_6,
    input [63:0] io_ys_5,
    input [63:0] io_ys_4,
    input [63:0] io_ys_3,
    input [63:0] io_ys_2,
    input [63:0] io_ys_1,
    input [63:0] io_ys_0,
    input [31:0] io_cent_9,
    input [31:0] io_cent_8,
    input [31:0] io_cent_7,
    input [31:0] io_cent_6,
    input [31:0] io_cent_5,
    input [31:0] io_cent_4,
    input [31:0] io_cent_3,
    input [31:0] io_cent_2,
    input [31:0] io_cent_1,
    input [31:0] io_cent_0,
    output[63:0] io_outX,
    output[63:0] io_outY
);

  wire[31:0] T30;
  wire[4:0] count;
  wire[4:0] T0;
  wire[3:0] T1;
  wire[3:0] T2;
  wire[2:0] T3;
  wire[2:0] T4;
  wire[1:0] T5;
  wire[1:0] T6;
  wire T7;
  wire[1:0] T31;
  wire T8;
  wire[2:0] T32;
  wire T9;
  wire[3:0] T33;
  wire[1:0] T10;
  wire[1:0] T11;
  wire T12;
  wire[1:0] T34;
  wire T13;
  wire[4:0] T35;
  wire[3:0] T14;
  wire[3:0] T15;
  wire[2:0] T16;
  wire[2:0] T17;
  wire[1:0] T18;
  wire[1:0] T19;
  wire T20;
  wire[1:0] T36;
  wire T21;
  wire[2:0] T37;
  wire T22;
  wire[3:0] T38;
  wire[1:0] T23;
  wire[1:0] T24;
  wire T25;
  wire[1:0] T39;
  wire T26;
  wire[63:0] T27;
  wire T28;
  wire[63:0] T29;
  wire[63:0] conv_io_out;
  wire[63:0] SelectivePointOps_io_poutx;
  wire[63:0] SelectivePointOps_io_pouty;
  wire[63:0] SelectivePointOps_1_io_poutx;
  wire[63:0] SelectivePointOps_1_io_pouty;
  wire[63:0] SelectivePointOps_2_io_poutx;
  wire[63:0] SelectivePointOps_2_io_pouty;
  wire[63:0] SelectivePointOps_3_io_poutx;
  wire[63:0] SelectivePointOps_3_io_pouty;
  wire[63:0] SelectivePointOps_4_io_poutx;
  wire[63:0] SelectivePointOps_4_io_pouty;
  wire[63:0] SelectivePointOps_5_io_poutx;
  wire[63:0] SelectivePointOps_5_io_pouty;
  wire[63:0] SelectivePointOps_6_io_poutx;
  wire[63:0] SelectivePointOps_6_io_pouty;
  wire[63:0] SelectivePointOps_7_io_poutx;
  wire[63:0] SelectivePointOps_7_io_pouty;
  wire[63:0] SelectivePointOps_8_io_poutx;
  wire[63:0] SelectivePointOps_8_io_pouty;
  wire[63:0] SelectivePointOps_9_io_poutx;
  wire[63:0] SelectivePointOps_9_io_pouty;
  wire[63:0] SelectivePointOps_10_io_poutx;
  wire[63:0] SelectivePointOps_10_io_pouty;


  assign T30 = {27'h0, count};
  assign count = T35 + T0;
  assign T0 = {1'h0, T1};
  assign T1 = T33 + T2;
  assign T2 = {1'h0, T3};
  assign T3 = T32 + T4;
  assign T4 = {1'h0, T5};
  assign T5 = T31 + T6;
  assign T6 = {1'h0, T7};
  assign T7 = io_cent_9 == 32'h4;
  assign T31 = {1'h0, T8};
  assign T8 = io_cent_8 == 32'h4;
  assign T32 = {2'h0, T9};
  assign T9 = io_cent_7 == 32'h4;
  assign T33 = {2'h0, T10};
  assign T10 = T34 + T11;
  assign T11 = {1'h0, T12};
  assign T12 = io_cent_6 == 32'h4;
  assign T34 = {1'h0, T13};
  assign T13 = io_cent_5 == 32'h4;
  assign T35 = {1'h0, T14};
  assign T14 = T38 + T15;
  assign T15 = {1'h0, T16};
  assign T16 = T37 + T17;
  assign T17 = {1'h0, T18};
  assign T18 = T36 + T19;
  assign T19 = {1'h0, T20};
  assign T20 = io_cent_4 == 32'h4;
  assign T36 = {1'h0, T21};
  assign T21 = io_cent_3 == 32'h4;
  assign T37 = {2'h0, T22};
  assign T22 = io_cent_2 == 32'h4;
  assign T38 = {2'h0, T23};
  assign T23 = T39 + T24;
  assign T24 = {1'h0, T25};
  assign T25 = io_cent_1 == 32'h4;
  assign T39 = {1'h0, T26};
  assign T26 = io_cent_0 == 32'h4;
  assign io_outY = T27;
  assign T27 = T28 ? 64'h0 : SelectivePointOps_10_io_pouty;
  assign T28 = count <= 5'h0;
  assign io_outX = T29;
  assign T29 = T28 ? 64'h0 : SelectivePointOps_10_io_poutx;
  SelectivePointOps_4 SelectivePointOps(
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
  SelectivePointOps_4 SelectivePointOps_1(
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
  SelectivePointOps_4 SelectivePointOps_2(
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
  SelectivePointOps_4 SelectivePointOps_3(
       .io_p1x( SelectivePointOps_2_io_poutx ),
       .io_p1y( SelectivePointOps_2_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_3 ),
       .io_p2y( io_ys_3 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_3_io_poutx ),
       .io_pouty( SelectivePointOps_3_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_3 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_3.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_4 SelectivePointOps_4(
       .io_p1x( SelectivePointOps_3_io_poutx ),
       .io_p1y( SelectivePointOps_3_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_4 ),
       .io_p2y( io_ys_4 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_4_io_poutx ),
       .io_pouty( SelectivePointOps_4_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_4 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_4.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_4 SelectivePointOps_5(
       .io_p1x( SelectivePointOps_4_io_poutx ),
       .io_p1y( SelectivePointOps_4_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_5 ),
       .io_p2y( io_ys_5 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_5_io_poutx ),
       .io_pouty( SelectivePointOps_5_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_5 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_5.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_4 SelectivePointOps_6(
       .io_p1x( SelectivePointOps_5_io_poutx ),
       .io_p1y( SelectivePointOps_5_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_6 ),
       .io_p2y( io_ys_6 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_6_io_poutx ),
       .io_pouty( SelectivePointOps_6_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_6 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_6.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_4 SelectivePointOps_7(
       .io_p1x( SelectivePointOps_6_io_poutx ),
       .io_p1y( SelectivePointOps_6_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_7 ),
       .io_p2y( io_ys_7 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_7_io_poutx ),
       .io_pouty( SelectivePointOps_7_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_7 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_7.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_4 SelectivePointOps_8(
       .io_p1x( SelectivePointOps_7_io_poutx ),
       .io_p1y( SelectivePointOps_7_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_8 ),
       .io_p2y( io_ys_8 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_8_io_poutx ),
       .io_pouty( SelectivePointOps_8_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_8 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_8.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_4 SelectivePointOps_9(
       .io_p1x( SelectivePointOps_8_io_poutx ),
       .io_p1y( SelectivePointOps_8_io_pouty ),
       .io_operation( 4'h1 ),
       .io_p2x( io_xs_9 ),
       .io_p2y( io_ys_9 ),
       //.io_den(  )
       .io_poutx( SelectivePointOps_9_io_poutx ),
       .io_pouty( SelectivePointOps_9_io_pouty ),
       //.io_out(  )
       .io_cent( io_cent_9 )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_9.io_den = {2{$random}};
// synthesis translate_on
`endif
  SelectivePointOps_4 SelectivePointOps_10(
       .io_p1x( SelectivePointOps_9_io_poutx ),
       .io_p1y( SelectivePointOps_9_io_pouty ),
       .io_operation( 4'h3 ),
       //.io_p2x(  )
       //.io_p2y(  )
       .io_den( conv_io_out ),
       .io_poutx( SelectivePointOps_10_io_poutx ),
       .io_pouty( SelectivePointOps_10_io_pouty )
       //.io_out(  )
       //.io_cent(  )
  );
`ifndef SYNTHESIS
// synthesis translate_off
    assign SelectivePointOps_10.io_p2x = {2{$random}};
    assign SelectivePointOps_10.io_p2y = {2{$random}};
    assign SelectivePointOps_10.io_cent = {1{$random}};
// synthesis translate_on
`endif
  IntToDblConversionOp conv(
       .io_in( T30 ),
       .io_out( conv_io_out )
  );
endmodule

module CalcNewCentroidsOp(
    input [63:0] io_xs_9,
    input [63:0] io_xs_8,
    input [63:0] io_xs_7,
    input [63:0] io_xs_6,
    input [63:0] io_xs_5,
    input [63:0] io_xs_4,
    input [63:0] io_xs_3,
    input [63:0] io_xs_2,
    input [63:0] io_xs_1,
    input [63:0] io_xs_0,
    input [63:0] io_ys_9,
    input [63:0] io_ys_8,
    input [63:0] io_ys_7,
    input [63:0] io_ys_6,
    input [63:0] io_ys_5,
    input [63:0] io_ys_4,
    input [63:0] io_ys_3,
    input [63:0] io_ys_2,
    input [63:0] io_ys_1,
    input [63:0] io_ys_0,
    input [31:0] io_cent_9,
    input [31:0] io_cent_8,
    input [31:0] io_cent_7,
    input [31:0] io_cent_6,
    input [31:0] io_cent_5,
    input [31:0] io_cent_4,
    input [31:0] io_cent_3,
    input [31:0] io_cent_2,
    input [31:0] io_cent_1,
    input [31:0] io_cent_0,
    output[63:0] io_centroidXs_4,
    output[63:0] io_centroidXs_3,
    output[63:0] io_centroidXs_2,
    output[63:0] io_centroidXs_1,
    output[63:0] io_centroidXs_0,
    output[63:0] io_centroidYs_4,
    output[63:0] io_centroidYs_3,
    output[63:0] io_centroidYs_2,
    output[63:0] io_centroidYs_1,
    output[63:0] io_centroidYs_0
);

  wire[63:0] SelectiveAverageOp_io_outX;
  wire[63:0] SelectiveAverageOp_io_outY;
  wire[63:0] SelectiveAverageOp_1_io_outX;
  wire[63:0] SelectiveAverageOp_1_io_outY;
  wire[63:0] SelectiveAverageOp_2_io_outX;
  wire[63:0] SelectiveAverageOp_2_io_outY;
  wire[63:0] SelectiveAverageOp_3_io_outX;
  wire[63:0] SelectiveAverageOp_3_io_outY;
  wire[63:0] SelectiveAverageOp_4_io_outX;
  wire[63:0] SelectiveAverageOp_4_io_outY;


  assign io_centroidYs_0 = SelectiveAverageOp_io_outY;
  assign io_centroidYs_1 = SelectiveAverageOp_1_io_outY;
  assign io_centroidYs_2 = SelectiveAverageOp_2_io_outY;
  assign io_centroidYs_3 = SelectiveAverageOp_3_io_outY;
  assign io_centroidYs_4 = SelectiveAverageOp_4_io_outY;
  assign io_centroidXs_0 = SelectiveAverageOp_io_outX;
  assign io_centroidXs_1 = SelectiveAverageOp_1_io_outX;
  assign io_centroidXs_2 = SelectiveAverageOp_2_io_outX;
  assign io_centroidXs_3 = SelectiveAverageOp_3_io_outX;
  assign io_centroidXs_4 = SelectiveAverageOp_4_io_outX;
  SelectiveAverageOp_0 SelectiveAverageOp(
       .io_xs_9( io_xs_9 ),
       .io_xs_8( io_xs_8 ),
       .io_xs_7( io_xs_7 ),
       .io_xs_6( io_xs_6 ),
       .io_xs_5( io_xs_5 ),
       .io_xs_4( io_xs_4 ),
       .io_xs_3( io_xs_3 ),
       .io_xs_2( io_xs_2 ),
       .io_xs_1( io_xs_1 ),
       .io_xs_0( io_xs_0 ),
       .io_ys_9( io_ys_9 ),
       .io_ys_8( io_ys_8 ),
       .io_ys_7( io_ys_7 ),
       .io_ys_6( io_ys_6 ),
       .io_ys_5( io_ys_5 ),
       .io_ys_4( io_ys_4 ),
       .io_ys_3( io_ys_3 ),
       .io_ys_2( io_ys_2 ),
       .io_ys_1( io_ys_1 ),
       .io_ys_0( io_ys_0 ),
       .io_cent_9( io_cent_9 ),
       .io_cent_8( io_cent_8 ),
       .io_cent_7( io_cent_7 ),
       .io_cent_6( io_cent_6 ),
       .io_cent_5( io_cent_5 ),
       .io_cent_4( io_cent_4 ),
       .io_cent_3( io_cent_3 ),
       .io_cent_2( io_cent_2 ),
       .io_cent_1( io_cent_1 ),
       .io_cent_0( io_cent_0 ),
       .io_outX( SelectiveAverageOp_io_outX ),
       .io_outY( SelectiveAverageOp_io_outY )
  );
  SelectiveAverageOp_1 SelectiveAverageOp_1(
       .io_xs_9( io_xs_9 ),
       .io_xs_8( io_xs_8 ),
       .io_xs_7( io_xs_7 ),
       .io_xs_6( io_xs_6 ),
       .io_xs_5( io_xs_5 ),
       .io_xs_4( io_xs_4 ),
       .io_xs_3( io_xs_3 ),
       .io_xs_2( io_xs_2 ),
       .io_xs_1( io_xs_1 ),
       .io_xs_0( io_xs_0 ),
       .io_ys_9( io_ys_9 ),
       .io_ys_8( io_ys_8 ),
       .io_ys_7( io_ys_7 ),
       .io_ys_6( io_ys_6 ),
       .io_ys_5( io_ys_5 ),
       .io_ys_4( io_ys_4 ),
       .io_ys_3( io_ys_3 ),
       .io_ys_2( io_ys_2 ),
       .io_ys_1( io_ys_1 ),
       .io_ys_0( io_ys_0 ),
       .io_cent_9( io_cent_9 ),
       .io_cent_8( io_cent_8 ),
       .io_cent_7( io_cent_7 ),
       .io_cent_6( io_cent_6 ),
       .io_cent_5( io_cent_5 ),
       .io_cent_4( io_cent_4 ),
       .io_cent_3( io_cent_3 ),
       .io_cent_2( io_cent_2 ),
       .io_cent_1( io_cent_1 ),
       .io_cent_0( io_cent_0 ),
       .io_outX( SelectiveAverageOp_1_io_outX ),
       .io_outY( SelectiveAverageOp_1_io_outY )
  );
  SelectiveAverageOp_2 SelectiveAverageOp_2(
       .io_xs_9( io_xs_9 ),
       .io_xs_8( io_xs_8 ),
       .io_xs_7( io_xs_7 ),
       .io_xs_6( io_xs_6 ),
       .io_xs_5( io_xs_5 ),
       .io_xs_4( io_xs_4 ),
       .io_xs_3( io_xs_3 ),
       .io_xs_2( io_xs_2 ),
       .io_xs_1( io_xs_1 ),
       .io_xs_0( io_xs_0 ),
       .io_ys_9( io_ys_9 ),
       .io_ys_8( io_ys_8 ),
       .io_ys_7( io_ys_7 ),
       .io_ys_6( io_ys_6 ),
       .io_ys_5( io_ys_5 ),
       .io_ys_4( io_ys_4 ),
       .io_ys_3( io_ys_3 ),
       .io_ys_2( io_ys_2 ),
       .io_ys_1( io_ys_1 ),
       .io_ys_0( io_ys_0 ),
       .io_cent_9( io_cent_9 ),
       .io_cent_8( io_cent_8 ),
       .io_cent_7( io_cent_7 ),
       .io_cent_6( io_cent_6 ),
       .io_cent_5( io_cent_5 ),
       .io_cent_4( io_cent_4 ),
       .io_cent_3( io_cent_3 ),
       .io_cent_2( io_cent_2 ),
       .io_cent_1( io_cent_1 ),
       .io_cent_0( io_cent_0 ),
       .io_outX( SelectiveAverageOp_2_io_outX ),
       .io_outY( SelectiveAverageOp_2_io_outY )
  );
  SelectiveAverageOp_3 SelectiveAverageOp_3(
       .io_xs_9( io_xs_9 ),
       .io_xs_8( io_xs_8 ),
       .io_xs_7( io_xs_7 ),
       .io_xs_6( io_xs_6 ),
       .io_xs_5( io_xs_5 ),
       .io_xs_4( io_xs_4 ),
       .io_xs_3( io_xs_3 ),
       .io_xs_2( io_xs_2 ),
       .io_xs_1( io_xs_1 ),
       .io_xs_0( io_xs_0 ),
       .io_ys_9( io_ys_9 ),
       .io_ys_8( io_ys_8 ),
       .io_ys_7( io_ys_7 ),
       .io_ys_6( io_ys_6 ),
       .io_ys_5( io_ys_5 ),
       .io_ys_4( io_ys_4 ),
       .io_ys_3( io_ys_3 ),
       .io_ys_2( io_ys_2 ),
       .io_ys_1( io_ys_1 ),
       .io_ys_0( io_ys_0 ),
       .io_cent_9( io_cent_9 ),
       .io_cent_8( io_cent_8 ),
       .io_cent_7( io_cent_7 ),
       .io_cent_6( io_cent_6 ),
       .io_cent_5( io_cent_5 ),
       .io_cent_4( io_cent_4 ),
       .io_cent_3( io_cent_3 ),
       .io_cent_2( io_cent_2 ),
       .io_cent_1( io_cent_1 ),
       .io_cent_0( io_cent_0 ),
       .io_outX( SelectiveAverageOp_3_io_outX ),
       .io_outY( SelectiveAverageOp_3_io_outY )
  );
  SelectiveAverageOp_4 SelectiveAverageOp_4(
       .io_xs_9( io_xs_9 ),
       .io_xs_8( io_xs_8 ),
       .io_xs_7( io_xs_7 ),
       .io_xs_6( io_xs_6 ),
       .io_xs_5( io_xs_5 ),
       .io_xs_4( io_xs_4 ),
       .io_xs_3( io_xs_3 ),
       .io_xs_2( io_xs_2 ),
       .io_xs_1( io_xs_1 ),
       .io_xs_0( io_xs_0 ),
       .io_ys_9( io_ys_9 ),
       .io_ys_8( io_ys_8 ),
       .io_ys_7( io_ys_7 ),
       .io_ys_6( io_ys_6 ),
       .io_ys_5( io_ys_5 ),
       .io_ys_4( io_ys_4 ),
       .io_ys_3( io_ys_3 ),
       .io_ys_2( io_ys_2 ),
       .io_ys_1( io_ys_1 ),
       .io_ys_0( io_ys_0 ),
       .io_cent_9( io_cent_9 ),
       .io_cent_8( io_cent_8 ),
       .io_cent_7( io_cent_7 ),
       .io_cent_6( io_cent_6 ),
       .io_cent_5( io_cent_5 ),
       .io_cent_4( io_cent_4 ),
       .io_cent_3( io_cent_3 ),
       .io_cent_2( io_cent_2 ),
       .io_cent_1( io_cent_1 ),
       .io_cent_0( io_cent_0 ),
       .io_outX( SelectiveAverageOp_4_io_outX ),
       .io_outY( SelectiveAverageOp_4_io_outY )
  );
endmodule

