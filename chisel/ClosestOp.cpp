#include "ClosestOp.h"

void ClosestOp_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
   ClosestOp_DistanceOp_9_po1__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_8_po1__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_7_po1__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_6_po1__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_5_po1__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_4_po1__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_3_po1__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_2_po1__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_1_po1__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_po1__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_9_po2__io_p2x.randomize(&__rand_seed);
   ClosestOp_DistanceOp_9_po2__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_9_po2__io_p2y.randomize(&__rand_seed);
   ClosestOp_DistanceOp_8_po2__io_p2x.randomize(&__rand_seed);
   ClosestOp_DistanceOp_8_po2__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_8_po2__io_p2y.randomize(&__rand_seed);
   ClosestOp_DistanceOp_7_po2__io_p2x.randomize(&__rand_seed);
   ClosestOp_DistanceOp_7_po2__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_7_po2__io_p2y.randomize(&__rand_seed);
   ClosestOp_DistanceOp_6_po2__io_p2x.randomize(&__rand_seed);
   ClosestOp_DistanceOp_6_po2__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_6_po2__io_p2y.randomize(&__rand_seed);
   ClosestOp_DistanceOp_5_po2__io_p2x.randomize(&__rand_seed);
   ClosestOp_DistanceOp_5_po2__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_5_po2__io_p2y.randomize(&__rand_seed);
   ClosestOp_DistanceOp_4_po2__io_p2x.randomize(&__rand_seed);
   ClosestOp_DistanceOp_4_po2__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_4_po2__io_p2y.randomize(&__rand_seed);
   ClosestOp_DistanceOp_3_po2__io_p2x.randomize(&__rand_seed);
   ClosestOp_DistanceOp_3_po2__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_3_po2__io_p2y.randomize(&__rand_seed);
   ClosestOp_DistanceOp_2_po2__io_p2x.randomize(&__rand_seed);
   ClosestOp_DistanceOp_2_po2__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_2_po2__io_p2y.randomize(&__rand_seed);
   ClosestOp_DistanceOp_1_po2__io_p2x.randomize(&__rand_seed);
   ClosestOp_DistanceOp_1_po2__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_1_po2__io_p2y.randomize(&__rand_seed);
   ClosestOp_DistanceOp_po2__io_p2x.randomize(&__rand_seed);
   ClosestOp_DistanceOp_po2__io_den.randomize(&__rand_seed);
   ClosestOp_DistanceOp_po2__io_p2y.randomize(&__rand_seed);
  clk.len = 1;
  clk.cnt = clk.len;
  clk.values[0] = 0;
}


int ClosestOp_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk.cnt < min) min = clk.cnt;
  clk.cnt-=min;
  if (clk.cnt == 0) clock_lo( reset );
  if (clk.cnt == 0) clock_hi( reset );
  if (clk.cnt == 0) clk.cnt = clk.len;
  return min;
}


void ClosestOp_t::print ( FILE* f ) {
}
void ClosestOp_t::print ( std::ostream& s ) {
}


void ClosestOp_t::dump_init ( FILE* f ) {
}


void ClosestOp_t::dump ( FILE* f, int t ) {
}




void ClosestOp_t::clock_lo ( dat_t<1> reset ) {
  { ClosestOp_DistanceOp_9__io_p2y.values[0] = ClosestOp__io_ys_9.values[0];}
  { ClosestOp_DistanceOp_9_po1__io_p2y.values[0] = ClosestOp_DistanceOp_9__io_p2y.values[0];}
  { ClosestOp_DistanceOp_9__io_p1y.values[0] = ClosestOp__io_pointY.values[0];}
  { ClosestOp_DistanceOp_9_po1__io_p1y.values[0] = ClosestOp_DistanceOp_9__io_p1y.values[0];}
  val_t T0;
  T0 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po1__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_9_po1__io_p2y.values[0]));
  { ClosestOp_DistanceOp_9_po1__io_operation.values[0] = 0x2L;}
  val_t T1;
  T1 = ClosestOp_DistanceOp_9_po1__io_operation.values[0] == 0x1L;
  val_t T2;
  T2 = ClosestOp_DistanceOp_9_po1__io_operation.values[0] == 0x0L;
  val_t T3;
  { T3 = T2 ^ 0x1L;}
  val_t T4;
  { T4 = T3 & T1;}
  val_t T5;
  { T5 = TERNARY(T4, T0, 0x0L);}
  val_t T6;
  T6 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po1__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_9_po1__io_p2y.values[0]));
  val_t T7;
  T7 = ClosestOp_DistanceOp_9_po1__io_operation.values[0] == 0x2L;
  val_t T8;
  { T8 = T2 | T1;}
  val_t T9;
  { T9 = T8 ^ 0x1L;}
  val_t T10;
  { T10 = T9 & T7;}
  val_t T11;
  { T11 = TERNARY_1(T10, T6, T5);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_9_po1__io_den.values[0] = __r;}
  val_t T12;
  T12 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po1__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_9_po1__io_den.values[0]));
  val_t T13;
  T13 = ClosestOp_DistanceOp_9_po1__io_operation.values[0] == 0x3L;
  val_t T14;
  { T14 = T8 | T7;}
  val_t T15;
  { T15 = T14 ^ 0x1L;}
  val_t T16;
  { T16 = T15 & T13;}
  val_t T17;
  { T17 = TERNARY_1(T16, T12, T11);}
  val_t T18;
  T18 = ClosestOp_DistanceOp_9_po1__io_operation.values[0] == 0x4L;
  val_t T19;
  { T19 = T14 | T13;}
  val_t T20;
  { T20 = T19 | T18;}
  val_t T21;
  { T21 = T20 ^ 0x1L;}
  val_t T22;
  { T22 = TERNARY(T21, 0x0L, T17);}
  { ClosestOp_DistanceOp_9_po1__io_pouty.values[0] = T22;}
  { ClosestOp_DistanceOp_9_po2__io_p1y.values[0] = ClosestOp_DistanceOp_9_po1__io_pouty.values[0];}
  val_t T23;
  T23 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po2__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_9_po2__io_p1y.values[0]));
  { ClosestOp_DistanceOp_9__io_p2x.values[0] = ClosestOp__io_xs_9.values[0];}
  { ClosestOp_DistanceOp_9_po1__io_p2x.values[0] = ClosestOp_DistanceOp_9__io_p2x.values[0];}
  { ClosestOp_DistanceOp_9__io_p1x.values[0] = ClosestOp__io_pointX.values[0];}
  { ClosestOp_DistanceOp_9_po1__io_p1x.values[0] = ClosestOp_DistanceOp_9__io_p1x.values[0];}
  val_t T24;
  T24 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po1__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_9_po1__io_p2x.values[0]));
  val_t T25;
  { T25 = TERNARY(T4, T24, 0x0L);}
  val_t T26;
  T26 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po1__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_9_po1__io_p2x.values[0]));
  val_t T27;
  { T27 = TERNARY_1(T10, T26, T25);}
  val_t T28;
  T28 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po1__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_9_po1__io_den.values[0]));
  val_t T29;
  { T29 = TERNARY_1(T16, T28, T27);}
  val_t T30;
  { T30 = TERNARY(T21, 0x0L, T29);}
  { ClosestOp_DistanceOp_9_po1__io_poutx.values[0] = T30;}
  { ClosestOp_DistanceOp_9_po2__io_p1x.values[0] = ClosestOp_DistanceOp_9_po1__io_poutx.values[0];}
  val_t T31;
  T31 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po2__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_9_po2__io_p1x.values[0]));
  val_t T32;
  T32 = fromDouble(toDouble(T31) + toDouble(T23));
  val_t T33;
  T33 = fromDouble(sqrt(toDouble(T32)));
  { ClosestOp_DistanceOp_9_po2__io_operation.values[0] = 0x4L;}
  val_t T34;
  T34 = ClosestOp_DistanceOp_9_po2__io_operation.values[0] == 0x4L;
  val_t T35;
  T35 = ClosestOp_DistanceOp_9_po2__io_operation.values[0] == 0x3L;
  val_t T36;
  T36 = ClosestOp_DistanceOp_9_po2__io_operation.values[0] == 0x2L;
  val_t T37;
  T37 = ClosestOp_DistanceOp_9_po2__io_operation.values[0] == 0x1L;
  val_t T38;
  T38 = ClosestOp_DistanceOp_9_po2__io_operation.values[0] == 0x0L;
  val_t T39;
  { T39 = T38 | T37;}
  val_t T40;
  { T40 = T39 | T36;}
  val_t T41;
  { T41 = T40 | T35;}
  val_t T42;
  { T42 = T41 ^ 0x1L;}
  val_t T43;
  { T43 = T42 & T34;}
  val_t T44;
  { T44 = TERNARY(T43, T33, 0x0L);}
  { ClosestOp_DistanceOp_9_po2__io_out.values[0] = T44;}
  { ClosestOp_DistanceOp_9__io_out.values[0] = ClosestOp_DistanceOp_9_po2__io_out.values[0];}
  { ClosestOp_mo__io_values_9.values[0] = ClosestOp_DistanceOp_9__io_out.values[0];}
  { ClosestOp_mo_Min2Op_8__io_value.values[0] = ClosestOp_mo__io_values_9.values[0];}
  { ClosestOp_DistanceOp_8__io_p2y.values[0] = ClosestOp__io_ys_8.values[0];}
  { ClosestOp_DistanceOp_8_po1__io_p2y.values[0] = ClosestOp_DistanceOp_8__io_p2y.values[0];}
  { ClosestOp_DistanceOp_8__io_p1y.values[0] = ClosestOp__io_pointY.values[0];}
  { ClosestOp_DistanceOp_8_po1__io_p1y.values[0] = ClosestOp_DistanceOp_8__io_p1y.values[0];}
  val_t T45;
  T45 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po1__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_8_po1__io_p2y.values[0]));
  { ClosestOp_DistanceOp_8_po1__io_operation.values[0] = 0x2L;}
  val_t T46;
  T46 = ClosestOp_DistanceOp_8_po1__io_operation.values[0] == 0x1L;
  val_t T47;
  T47 = ClosestOp_DistanceOp_8_po1__io_operation.values[0] == 0x0L;
  val_t T48;
  { T48 = T47 ^ 0x1L;}
  val_t T49;
  { T49 = T48 & T46;}
  val_t T50;
  { T50 = TERNARY(T49, T45, 0x0L);}
  val_t T51;
  T51 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po1__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_8_po1__io_p2y.values[0]));
  val_t T52;
  T52 = ClosestOp_DistanceOp_8_po1__io_operation.values[0] == 0x2L;
  val_t T53;
  { T53 = T47 | T46;}
  val_t T54;
  { T54 = T53 ^ 0x1L;}
  val_t T55;
  { T55 = T54 & T52;}
  val_t T56;
  { T56 = TERNARY_1(T55, T51, T50);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_8_po1__io_den.values[0] = __r;}
  val_t T57;
  T57 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po1__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_8_po1__io_den.values[0]));
  val_t T58;
  T58 = ClosestOp_DistanceOp_8_po1__io_operation.values[0] == 0x3L;
  val_t T59;
  { T59 = T53 | T52;}
  val_t T60;
  { T60 = T59 ^ 0x1L;}
  val_t T61;
  { T61 = T60 & T58;}
  val_t T62;
  { T62 = TERNARY_1(T61, T57, T56);}
  val_t T63;
  T63 = ClosestOp_DistanceOp_8_po1__io_operation.values[0] == 0x4L;
  val_t T64;
  { T64 = T59 | T58;}
  val_t T65;
  { T65 = T64 | T63;}
  val_t T66;
  { T66 = T65 ^ 0x1L;}
  val_t T67;
  { T67 = TERNARY(T66, 0x0L, T62);}
  { ClosestOp_DistanceOp_8_po1__io_pouty.values[0] = T67;}
  { ClosestOp_DistanceOp_8_po2__io_p1y.values[0] = ClosestOp_DistanceOp_8_po1__io_pouty.values[0];}
  val_t T68;
  T68 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po2__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_8_po2__io_p1y.values[0]));
  { ClosestOp_DistanceOp_8__io_p2x.values[0] = ClosestOp__io_xs_8.values[0];}
  { ClosestOp_DistanceOp_8_po1__io_p2x.values[0] = ClosestOp_DistanceOp_8__io_p2x.values[0];}
  { ClosestOp_DistanceOp_8__io_p1x.values[0] = ClosestOp__io_pointX.values[0];}
  { ClosestOp_DistanceOp_8_po1__io_p1x.values[0] = ClosestOp_DistanceOp_8__io_p1x.values[0];}
  val_t T69;
  T69 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po1__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_8_po1__io_p2x.values[0]));
  val_t T70;
  { T70 = TERNARY(T49, T69, 0x0L);}
  val_t T71;
  T71 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po1__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_8_po1__io_p2x.values[0]));
  val_t T72;
  { T72 = TERNARY_1(T55, T71, T70);}
  val_t T73;
  T73 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po1__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_8_po1__io_den.values[0]));
  val_t T74;
  { T74 = TERNARY_1(T61, T73, T72);}
  val_t T75;
  { T75 = TERNARY(T66, 0x0L, T74);}
  { ClosestOp_DistanceOp_8_po1__io_poutx.values[0] = T75;}
  { ClosestOp_DistanceOp_8_po2__io_p1x.values[0] = ClosestOp_DistanceOp_8_po1__io_poutx.values[0];}
  val_t T76;
  T76 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po2__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_8_po2__io_p1x.values[0]));
  val_t T77;
  T77 = fromDouble(toDouble(T76) + toDouble(T68));
  val_t T78;
  T78 = fromDouble(sqrt(toDouble(T77)));
  { ClosestOp_DistanceOp_8_po2__io_operation.values[0] = 0x4L;}
  val_t T79;
  T79 = ClosestOp_DistanceOp_8_po2__io_operation.values[0] == 0x4L;
  val_t T80;
  T80 = ClosestOp_DistanceOp_8_po2__io_operation.values[0] == 0x3L;
  val_t T81;
  T81 = ClosestOp_DistanceOp_8_po2__io_operation.values[0] == 0x2L;
  val_t T82;
  T82 = ClosestOp_DistanceOp_8_po2__io_operation.values[0] == 0x1L;
  val_t T83;
  T83 = ClosestOp_DistanceOp_8_po2__io_operation.values[0] == 0x0L;
  val_t T84;
  { T84 = T83 | T82;}
  val_t T85;
  { T85 = T84 | T81;}
  val_t T86;
  { T86 = T85 | T80;}
  val_t T87;
  { T87 = T86 ^ 0x1L;}
  val_t T88;
  { T88 = T87 & T79;}
  val_t T89;
  { T89 = TERNARY(T88, T78, 0x0L);}
  { ClosestOp_DistanceOp_8_po2__io_out.values[0] = T89;}
  { ClosestOp_DistanceOp_8__io_out.values[0] = ClosestOp_DistanceOp_8_po2__io_out.values[0];}
  { ClosestOp_mo__io_values_8.values[0] = ClosestOp_DistanceOp_8__io_out.values[0];}
  { ClosestOp_mo_Min2Op_7__io_value.values[0] = ClosestOp_mo__io_values_8.values[0];}
  { ClosestOp_DistanceOp_7__io_p2y.values[0] = ClosestOp__io_ys_7.values[0];}
  { ClosestOp_DistanceOp_7_po1__io_p2y.values[0] = ClosestOp_DistanceOp_7__io_p2y.values[0];}
  { ClosestOp_DistanceOp_7__io_p1y.values[0] = ClosestOp__io_pointY.values[0];}
  { ClosestOp_DistanceOp_7_po1__io_p1y.values[0] = ClosestOp_DistanceOp_7__io_p1y.values[0];}
  val_t T90;
  T90 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po1__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_7_po1__io_p2y.values[0]));
  { ClosestOp_DistanceOp_7_po1__io_operation.values[0] = 0x2L;}
  val_t T91;
  T91 = ClosestOp_DistanceOp_7_po1__io_operation.values[0] == 0x1L;
  val_t T92;
  T92 = ClosestOp_DistanceOp_7_po1__io_operation.values[0] == 0x0L;
  val_t T93;
  { T93 = T92 ^ 0x1L;}
  val_t T94;
  { T94 = T93 & T91;}
  val_t T95;
  { T95 = TERNARY(T94, T90, 0x0L);}
  val_t T96;
  T96 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po1__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_7_po1__io_p2y.values[0]));
  val_t T97;
  T97 = ClosestOp_DistanceOp_7_po1__io_operation.values[0] == 0x2L;
  val_t T98;
  { T98 = T92 | T91;}
  val_t T99;
  { T99 = T98 ^ 0x1L;}
  val_t T100;
  { T100 = T99 & T97;}
  val_t T101;
  { T101 = TERNARY_1(T100, T96, T95);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_7_po1__io_den.values[0] = __r;}
  val_t T102;
  T102 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po1__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_7_po1__io_den.values[0]));
  val_t T103;
  T103 = ClosestOp_DistanceOp_7_po1__io_operation.values[0] == 0x3L;
  val_t T104;
  { T104 = T98 | T97;}
  val_t T105;
  { T105 = T104 ^ 0x1L;}
  val_t T106;
  { T106 = T105 & T103;}
  val_t T107;
  { T107 = TERNARY_1(T106, T102, T101);}
  val_t T108;
  T108 = ClosestOp_DistanceOp_7_po1__io_operation.values[0] == 0x4L;
  val_t T109;
  { T109 = T104 | T103;}
  val_t T110;
  { T110 = T109 | T108;}
  val_t T111;
  { T111 = T110 ^ 0x1L;}
  val_t T112;
  { T112 = TERNARY(T111, 0x0L, T107);}
  { ClosestOp_DistanceOp_7_po1__io_pouty.values[0] = T112;}
  { ClosestOp_DistanceOp_7_po2__io_p1y.values[0] = ClosestOp_DistanceOp_7_po1__io_pouty.values[0];}
  val_t T113;
  T113 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po2__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_7_po2__io_p1y.values[0]));
  { ClosestOp_DistanceOp_7__io_p2x.values[0] = ClosestOp__io_xs_7.values[0];}
  { ClosestOp_DistanceOp_7_po1__io_p2x.values[0] = ClosestOp_DistanceOp_7__io_p2x.values[0];}
  { ClosestOp_DistanceOp_7__io_p1x.values[0] = ClosestOp__io_pointX.values[0];}
  { ClosestOp_DistanceOp_7_po1__io_p1x.values[0] = ClosestOp_DistanceOp_7__io_p1x.values[0];}
  val_t T114;
  T114 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po1__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_7_po1__io_p2x.values[0]));
  val_t T115;
  { T115 = TERNARY(T94, T114, 0x0L);}
  val_t T116;
  T116 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po1__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_7_po1__io_p2x.values[0]));
  val_t T117;
  { T117 = TERNARY_1(T100, T116, T115);}
  val_t T118;
  T118 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po1__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_7_po1__io_den.values[0]));
  val_t T119;
  { T119 = TERNARY_1(T106, T118, T117);}
  val_t T120;
  { T120 = TERNARY(T111, 0x0L, T119);}
  { ClosestOp_DistanceOp_7_po1__io_poutx.values[0] = T120;}
  { ClosestOp_DistanceOp_7_po2__io_p1x.values[0] = ClosestOp_DistanceOp_7_po1__io_poutx.values[0];}
  val_t T121;
  T121 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po2__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_7_po2__io_p1x.values[0]));
  val_t T122;
  T122 = fromDouble(toDouble(T121) + toDouble(T113));
  val_t T123;
  T123 = fromDouble(sqrt(toDouble(T122)));
  { ClosestOp_DistanceOp_7_po2__io_operation.values[0] = 0x4L;}
  val_t T124;
  T124 = ClosestOp_DistanceOp_7_po2__io_operation.values[0] == 0x4L;
  val_t T125;
  T125 = ClosestOp_DistanceOp_7_po2__io_operation.values[0] == 0x3L;
  val_t T126;
  T126 = ClosestOp_DistanceOp_7_po2__io_operation.values[0] == 0x2L;
  val_t T127;
  T127 = ClosestOp_DistanceOp_7_po2__io_operation.values[0] == 0x1L;
  val_t T128;
  T128 = ClosestOp_DistanceOp_7_po2__io_operation.values[0] == 0x0L;
  val_t T129;
  { T129 = T128 | T127;}
  val_t T130;
  { T130 = T129 | T126;}
  val_t T131;
  { T131 = T130 | T125;}
  val_t T132;
  { T132 = T131 ^ 0x1L;}
  val_t T133;
  { T133 = T132 & T124;}
  val_t T134;
  { T134 = TERNARY(T133, T123, 0x0L);}
  { ClosestOp_DistanceOp_7_po2__io_out.values[0] = T134;}
  { ClosestOp_DistanceOp_7__io_out.values[0] = ClosestOp_DistanceOp_7_po2__io_out.values[0];}
  { ClosestOp_mo__io_values_7.values[0] = ClosestOp_DistanceOp_7__io_out.values[0];}
  { ClosestOp_mo_Min2Op_6__io_value.values[0] = ClosestOp_mo__io_values_7.values[0];}
  { ClosestOp_DistanceOp_6__io_p2y.values[0] = ClosestOp__io_ys_6.values[0];}
  { ClosestOp_DistanceOp_6_po1__io_p2y.values[0] = ClosestOp_DistanceOp_6__io_p2y.values[0];}
  { ClosestOp_DistanceOp_6__io_p1y.values[0] = ClosestOp__io_pointY.values[0];}
  { ClosestOp_DistanceOp_6_po1__io_p1y.values[0] = ClosestOp_DistanceOp_6__io_p1y.values[0];}
  val_t T135;
  T135 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po1__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_6_po1__io_p2y.values[0]));
  { ClosestOp_DistanceOp_6_po1__io_operation.values[0] = 0x2L;}
  val_t T136;
  T136 = ClosestOp_DistanceOp_6_po1__io_operation.values[0] == 0x1L;
  val_t T137;
  T137 = ClosestOp_DistanceOp_6_po1__io_operation.values[0] == 0x0L;
  val_t T138;
  { T138 = T137 ^ 0x1L;}
  val_t T139;
  { T139 = T138 & T136;}
  val_t T140;
  { T140 = TERNARY(T139, T135, 0x0L);}
  val_t T141;
  T141 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po1__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_6_po1__io_p2y.values[0]));
  val_t T142;
  T142 = ClosestOp_DistanceOp_6_po1__io_operation.values[0] == 0x2L;
  val_t T143;
  { T143 = T137 | T136;}
  val_t T144;
  { T144 = T143 ^ 0x1L;}
  val_t T145;
  { T145 = T144 & T142;}
  val_t T146;
  { T146 = TERNARY_1(T145, T141, T140);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_6_po1__io_den.values[0] = __r;}
  val_t T147;
  T147 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po1__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_6_po1__io_den.values[0]));
  val_t T148;
  T148 = ClosestOp_DistanceOp_6_po1__io_operation.values[0] == 0x3L;
  val_t T149;
  { T149 = T143 | T142;}
  val_t T150;
  { T150 = T149 ^ 0x1L;}
  val_t T151;
  { T151 = T150 & T148;}
  val_t T152;
  { T152 = TERNARY_1(T151, T147, T146);}
  val_t T153;
  T153 = ClosestOp_DistanceOp_6_po1__io_operation.values[0] == 0x4L;
  val_t T154;
  { T154 = T149 | T148;}
  val_t T155;
  { T155 = T154 | T153;}
  val_t T156;
  { T156 = T155 ^ 0x1L;}
  val_t T157;
  { T157 = TERNARY(T156, 0x0L, T152);}
  { ClosestOp_DistanceOp_6_po1__io_pouty.values[0] = T157;}
  { ClosestOp_DistanceOp_6_po2__io_p1y.values[0] = ClosestOp_DistanceOp_6_po1__io_pouty.values[0];}
  val_t T158;
  T158 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po2__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_6_po2__io_p1y.values[0]));
  { ClosestOp_DistanceOp_6__io_p2x.values[0] = ClosestOp__io_xs_6.values[0];}
  { ClosestOp_DistanceOp_6_po1__io_p2x.values[0] = ClosestOp_DistanceOp_6__io_p2x.values[0];}
  { ClosestOp_DistanceOp_6__io_p1x.values[0] = ClosestOp__io_pointX.values[0];}
  { ClosestOp_DistanceOp_6_po1__io_p1x.values[0] = ClosestOp_DistanceOp_6__io_p1x.values[0];}
  val_t T159;
  T159 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po1__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_6_po1__io_p2x.values[0]));
  val_t T160;
  { T160 = TERNARY(T139, T159, 0x0L);}
  val_t T161;
  T161 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po1__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_6_po1__io_p2x.values[0]));
  val_t T162;
  { T162 = TERNARY_1(T145, T161, T160);}
  val_t T163;
  T163 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po1__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_6_po1__io_den.values[0]));
  val_t T164;
  { T164 = TERNARY_1(T151, T163, T162);}
  val_t T165;
  { T165 = TERNARY(T156, 0x0L, T164);}
  { ClosestOp_DistanceOp_6_po1__io_poutx.values[0] = T165;}
  { ClosestOp_DistanceOp_6_po2__io_p1x.values[0] = ClosestOp_DistanceOp_6_po1__io_poutx.values[0];}
  val_t T166;
  T166 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po2__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_6_po2__io_p1x.values[0]));
  val_t T167;
  T167 = fromDouble(toDouble(T166) + toDouble(T158));
  val_t T168;
  T168 = fromDouble(sqrt(toDouble(T167)));
  { ClosestOp_DistanceOp_6_po2__io_operation.values[0] = 0x4L;}
  val_t T169;
  T169 = ClosestOp_DistanceOp_6_po2__io_operation.values[0] == 0x4L;
  val_t T170;
  T170 = ClosestOp_DistanceOp_6_po2__io_operation.values[0] == 0x3L;
  val_t T171;
  T171 = ClosestOp_DistanceOp_6_po2__io_operation.values[0] == 0x2L;
  val_t T172;
  T172 = ClosestOp_DistanceOp_6_po2__io_operation.values[0] == 0x1L;
  val_t T173;
  T173 = ClosestOp_DistanceOp_6_po2__io_operation.values[0] == 0x0L;
  val_t T174;
  { T174 = T173 | T172;}
  val_t T175;
  { T175 = T174 | T171;}
  val_t T176;
  { T176 = T175 | T170;}
  val_t T177;
  { T177 = T176 ^ 0x1L;}
  val_t T178;
  { T178 = T177 & T169;}
  val_t T179;
  { T179 = TERNARY(T178, T168, 0x0L);}
  { ClosestOp_DistanceOp_6_po2__io_out.values[0] = T179;}
  { ClosestOp_DistanceOp_6__io_out.values[0] = ClosestOp_DistanceOp_6_po2__io_out.values[0];}
  { ClosestOp_mo__io_values_6.values[0] = ClosestOp_DistanceOp_6__io_out.values[0];}
  { ClosestOp_mo_Min2Op_5__io_value.values[0] = ClosestOp_mo__io_values_6.values[0];}
  { ClosestOp_DistanceOp_5__io_p2y.values[0] = ClosestOp__io_ys_5.values[0];}
  { ClosestOp_DistanceOp_5_po1__io_p2y.values[0] = ClosestOp_DistanceOp_5__io_p2y.values[0];}
  { ClosestOp_DistanceOp_5__io_p1y.values[0] = ClosestOp__io_pointY.values[0];}
  { ClosestOp_DistanceOp_5_po1__io_p1y.values[0] = ClosestOp_DistanceOp_5__io_p1y.values[0];}
  val_t T180;
  T180 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po1__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_5_po1__io_p2y.values[0]));
  { ClosestOp_DistanceOp_5_po1__io_operation.values[0] = 0x2L;}
  val_t T181;
  T181 = ClosestOp_DistanceOp_5_po1__io_operation.values[0] == 0x1L;
  val_t T182;
  T182 = ClosestOp_DistanceOp_5_po1__io_operation.values[0] == 0x0L;
  val_t T183;
  { T183 = T182 ^ 0x1L;}
  val_t T184;
  { T184 = T183 & T181;}
  val_t T185;
  { T185 = TERNARY(T184, T180, 0x0L);}
  val_t T186;
  T186 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po1__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_5_po1__io_p2y.values[0]));
  val_t T187;
  T187 = ClosestOp_DistanceOp_5_po1__io_operation.values[0] == 0x2L;
  val_t T188;
  { T188 = T182 | T181;}
  val_t T189;
  { T189 = T188 ^ 0x1L;}
  val_t T190;
  { T190 = T189 & T187;}
  val_t T191;
  { T191 = TERNARY_1(T190, T186, T185);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_5_po1__io_den.values[0] = __r;}
  val_t T192;
  T192 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po1__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_5_po1__io_den.values[0]));
  val_t T193;
  T193 = ClosestOp_DistanceOp_5_po1__io_operation.values[0] == 0x3L;
  val_t T194;
  { T194 = T188 | T187;}
  val_t T195;
  { T195 = T194 ^ 0x1L;}
  val_t T196;
  { T196 = T195 & T193;}
  val_t T197;
  { T197 = TERNARY_1(T196, T192, T191);}
  val_t T198;
  T198 = ClosestOp_DistanceOp_5_po1__io_operation.values[0] == 0x4L;
  val_t T199;
  { T199 = T194 | T193;}
  val_t T200;
  { T200 = T199 | T198;}
  val_t T201;
  { T201 = T200 ^ 0x1L;}
  val_t T202;
  { T202 = TERNARY(T201, 0x0L, T197);}
  { ClosestOp_DistanceOp_5_po1__io_pouty.values[0] = T202;}
  { ClosestOp_DistanceOp_5_po2__io_p1y.values[0] = ClosestOp_DistanceOp_5_po1__io_pouty.values[0];}
  val_t T203;
  T203 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po2__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_5_po2__io_p1y.values[0]));
  { ClosestOp_DistanceOp_5__io_p2x.values[0] = ClosestOp__io_xs_5.values[0];}
  { ClosestOp_DistanceOp_5_po1__io_p2x.values[0] = ClosestOp_DistanceOp_5__io_p2x.values[0];}
  { ClosestOp_DistanceOp_5__io_p1x.values[0] = ClosestOp__io_pointX.values[0];}
  { ClosestOp_DistanceOp_5_po1__io_p1x.values[0] = ClosestOp_DistanceOp_5__io_p1x.values[0];}
  val_t T204;
  T204 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po1__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_5_po1__io_p2x.values[0]));
  val_t T205;
  { T205 = TERNARY(T184, T204, 0x0L);}
  val_t T206;
  T206 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po1__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_5_po1__io_p2x.values[0]));
  val_t T207;
  { T207 = TERNARY_1(T190, T206, T205);}
  val_t T208;
  T208 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po1__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_5_po1__io_den.values[0]));
  val_t T209;
  { T209 = TERNARY_1(T196, T208, T207);}
  val_t T210;
  { T210 = TERNARY(T201, 0x0L, T209);}
  { ClosestOp_DistanceOp_5_po1__io_poutx.values[0] = T210;}
  { ClosestOp_DistanceOp_5_po2__io_p1x.values[0] = ClosestOp_DistanceOp_5_po1__io_poutx.values[0];}
  val_t T211;
  T211 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po2__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_5_po2__io_p1x.values[0]));
  val_t T212;
  T212 = fromDouble(toDouble(T211) + toDouble(T203));
  val_t T213;
  T213 = fromDouble(sqrt(toDouble(T212)));
  { ClosestOp_DistanceOp_5_po2__io_operation.values[0] = 0x4L;}
  val_t T214;
  T214 = ClosestOp_DistanceOp_5_po2__io_operation.values[0] == 0x4L;
  val_t T215;
  T215 = ClosestOp_DistanceOp_5_po2__io_operation.values[0] == 0x3L;
  val_t T216;
  T216 = ClosestOp_DistanceOp_5_po2__io_operation.values[0] == 0x2L;
  val_t T217;
  T217 = ClosestOp_DistanceOp_5_po2__io_operation.values[0] == 0x1L;
  val_t T218;
  T218 = ClosestOp_DistanceOp_5_po2__io_operation.values[0] == 0x0L;
  val_t T219;
  { T219 = T218 | T217;}
  val_t T220;
  { T220 = T219 | T216;}
  val_t T221;
  { T221 = T220 | T215;}
  val_t T222;
  { T222 = T221 ^ 0x1L;}
  val_t T223;
  { T223 = T222 & T214;}
  val_t T224;
  { T224 = TERNARY(T223, T213, 0x0L);}
  { ClosestOp_DistanceOp_5_po2__io_out.values[0] = T224;}
  { ClosestOp_DistanceOp_5__io_out.values[0] = ClosestOp_DistanceOp_5_po2__io_out.values[0];}
  { ClosestOp_mo__io_values_5.values[0] = ClosestOp_DistanceOp_5__io_out.values[0];}
  { ClosestOp_mo_Min2Op_4__io_value.values[0] = ClosestOp_mo__io_values_5.values[0];}
  { ClosestOp_DistanceOp_4__io_p2y.values[0] = ClosestOp__io_ys_4.values[0];}
  { ClosestOp_DistanceOp_4_po1__io_p2y.values[0] = ClosestOp_DistanceOp_4__io_p2y.values[0];}
  { ClosestOp_DistanceOp_4__io_p1y.values[0] = ClosestOp__io_pointY.values[0];}
  { ClosestOp_DistanceOp_4_po1__io_p1y.values[0] = ClosestOp_DistanceOp_4__io_p1y.values[0];}
  val_t T225;
  T225 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po1__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_4_po1__io_p2y.values[0]));
  { ClosestOp_DistanceOp_4_po1__io_operation.values[0] = 0x2L;}
  val_t T226;
  T226 = ClosestOp_DistanceOp_4_po1__io_operation.values[0] == 0x1L;
  val_t T227;
  T227 = ClosestOp_DistanceOp_4_po1__io_operation.values[0] == 0x0L;
  val_t T228;
  { T228 = T227 ^ 0x1L;}
  val_t T229;
  { T229 = T228 & T226;}
  val_t T230;
  { T230 = TERNARY(T229, T225, 0x0L);}
  val_t T231;
  T231 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po1__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_4_po1__io_p2y.values[0]));
  val_t T232;
  T232 = ClosestOp_DistanceOp_4_po1__io_operation.values[0] == 0x2L;
  val_t T233;
  { T233 = T227 | T226;}
  val_t T234;
  { T234 = T233 ^ 0x1L;}
  val_t T235;
  { T235 = T234 & T232;}
  val_t T236;
  { T236 = TERNARY_1(T235, T231, T230);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_4_po1__io_den.values[0] = __r;}
  val_t T237;
  T237 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po1__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_4_po1__io_den.values[0]));
  val_t T238;
  T238 = ClosestOp_DistanceOp_4_po1__io_operation.values[0] == 0x3L;
  val_t T239;
  { T239 = T233 | T232;}
  val_t T240;
  { T240 = T239 ^ 0x1L;}
  val_t T241;
  { T241 = T240 & T238;}
  val_t T242;
  { T242 = TERNARY_1(T241, T237, T236);}
  val_t T243;
  T243 = ClosestOp_DistanceOp_4_po1__io_operation.values[0] == 0x4L;
  val_t T244;
  { T244 = T239 | T238;}
  val_t T245;
  { T245 = T244 | T243;}
  val_t T246;
  { T246 = T245 ^ 0x1L;}
  val_t T247;
  { T247 = TERNARY(T246, 0x0L, T242);}
  { ClosestOp_DistanceOp_4_po1__io_pouty.values[0] = T247;}
  { ClosestOp_DistanceOp_4_po2__io_p1y.values[0] = ClosestOp_DistanceOp_4_po1__io_pouty.values[0];}
  val_t T248;
  T248 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po2__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_4_po2__io_p1y.values[0]));
  { ClosestOp_DistanceOp_4__io_p2x.values[0] = ClosestOp__io_xs_4.values[0];}
  { ClosestOp_DistanceOp_4_po1__io_p2x.values[0] = ClosestOp_DistanceOp_4__io_p2x.values[0];}
  { ClosestOp_DistanceOp_4__io_p1x.values[0] = ClosestOp__io_pointX.values[0];}
  { ClosestOp_DistanceOp_4_po1__io_p1x.values[0] = ClosestOp_DistanceOp_4__io_p1x.values[0];}
  val_t T249;
  T249 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po1__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_4_po1__io_p2x.values[0]));
  val_t T250;
  { T250 = TERNARY(T229, T249, 0x0L);}
  val_t T251;
  T251 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po1__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_4_po1__io_p2x.values[0]));
  val_t T252;
  { T252 = TERNARY_1(T235, T251, T250);}
  val_t T253;
  T253 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po1__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_4_po1__io_den.values[0]));
  val_t T254;
  { T254 = TERNARY_1(T241, T253, T252);}
  val_t T255;
  { T255 = TERNARY(T246, 0x0L, T254);}
  { ClosestOp_DistanceOp_4_po1__io_poutx.values[0] = T255;}
  { ClosestOp_DistanceOp_4_po2__io_p1x.values[0] = ClosestOp_DistanceOp_4_po1__io_poutx.values[0];}
  val_t T256;
  T256 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po2__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_4_po2__io_p1x.values[0]));
  val_t T257;
  T257 = fromDouble(toDouble(T256) + toDouble(T248));
  val_t T258;
  T258 = fromDouble(sqrt(toDouble(T257)));
  { ClosestOp_DistanceOp_4_po2__io_operation.values[0] = 0x4L;}
  val_t T259;
  T259 = ClosestOp_DistanceOp_4_po2__io_operation.values[0] == 0x4L;
  val_t T260;
  T260 = ClosestOp_DistanceOp_4_po2__io_operation.values[0] == 0x3L;
  val_t T261;
  T261 = ClosestOp_DistanceOp_4_po2__io_operation.values[0] == 0x2L;
  val_t T262;
  T262 = ClosestOp_DistanceOp_4_po2__io_operation.values[0] == 0x1L;
  val_t T263;
  T263 = ClosestOp_DistanceOp_4_po2__io_operation.values[0] == 0x0L;
  val_t T264;
  { T264 = T263 | T262;}
  val_t T265;
  { T265 = T264 | T261;}
  val_t T266;
  { T266 = T265 | T260;}
  val_t T267;
  { T267 = T266 ^ 0x1L;}
  val_t T268;
  { T268 = T267 & T259;}
  val_t T269;
  { T269 = TERNARY(T268, T258, 0x0L);}
  { ClosestOp_DistanceOp_4_po2__io_out.values[0] = T269;}
  { ClosestOp_DistanceOp_4__io_out.values[0] = ClosestOp_DistanceOp_4_po2__io_out.values[0];}
  { ClosestOp_mo__io_values_4.values[0] = ClosestOp_DistanceOp_4__io_out.values[0];}
  { ClosestOp_mo_Min2Op_3__io_value.values[0] = ClosestOp_mo__io_values_4.values[0];}
  { ClosestOp_DistanceOp_3__io_p2y.values[0] = ClosestOp__io_ys_3.values[0];}
  { ClosestOp_DistanceOp_3_po1__io_p2y.values[0] = ClosestOp_DistanceOp_3__io_p2y.values[0];}
  { ClosestOp_DistanceOp_3__io_p1y.values[0] = ClosestOp__io_pointY.values[0];}
  { ClosestOp_DistanceOp_3_po1__io_p1y.values[0] = ClosestOp_DistanceOp_3__io_p1y.values[0];}
  val_t T270;
  T270 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po1__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_3_po1__io_p2y.values[0]));
  { ClosestOp_DistanceOp_3_po1__io_operation.values[0] = 0x2L;}
  val_t T271;
  T271 = ClosestOp_DistanceOp_3_po1__io_operation.values[0] == 0x1L;
  val_t T272;
  T272 = ClosestOp_DistanceOp_3_po1__io_operation.values[0] == 0x0L;
  val_t T273;
  { T273 = T272 ^ 0x1L;}
  val_t T274;
  { T274 = T273 & T271;}
  val_t T275;
  { T275 = TERNARY(T274, T270, 0x0L);}
  val_t T276;
  T276 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po1__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_3_po1__io_p2y.values[0]));
  val_t T277;
  T277 = ClosestOp_DistanceOp_3_po1__io_operation.values[0] == 0x2L;
  val_t T278;
  { T278 = T272 | T271;}
  val_t T279;
  { T279 = T278 ^ 0x1L;}
  val_t T280;
  { T280 = T279 & T277;}
  val_t T281;
  { T281 = TERNARY_1(T280, T276, T275);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_3_po1__io_den.values[0] = __r;}
  val_t T282;
  T282 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po1__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_3_po1__io_den.values[0]));
  val_t T283;
  T283 = ClosestOp_DistanceOp_3_po1__io_operation.values[0] == 0x3L;
  val_t T284;
  { T284 = T278 | T277;}
  val_t T285;
  { T285 = T284 ^ 0x1L;}
  val_t T286;
  { T286 = T285 & T283;}
  val_t T287;
  { T287 = TERNARY_1(T286, T282, T281);}
  val_t T288;
  T288 = ClosestOp_DistanceOp_3_po1__io_operation.values[0] == 0x4L;
  val_t T289;
  { T289 = T284 | T283;}
  val_t T290;
  { T290 = T289 | T288;}
  val_t T291;
  { T291 = T290 ^ 0x1L;}
  val_t T292;
  { T292 = TERNARY(T291, 0x0L, T287);}
  { ClosestOp_DistanceOp_3_po1__io_pouty.values[0] = T292;}
  { ClosestOp_DistanceOp_3_po2__io_p1y.values[0] = ClosestOp_DistanceOp_3_po1__io_pouty.values[0];}
  val_t T293;
  T293 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po2__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_3_po2__io_p1y.values[0]));
  { ClosestOp_DistanceOp_3__io_p2x.values[0] = ClosestOp__io_xs_3.values[0];}
  { ClosestOp_DistanceOp_3_po1__io_p2x.values[0] = ClosestOp_DistanceOp_3__io_p2x.values[0];}
  { ClosestOp_DistanceOp_3__io_p1x.values[0] = ClosestOp__io_pointX.values[0];}
  { ClosestOp_DistanceOp_3_po1__io_p1x.values[0] = ClosestOp_DistanceOp_3__io_p1x.values[0];}
  val_t T294;
  T294 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po1__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_3_po1__io_p2x.values[0]));
  val_t T295;
  { T295 = TERNARY(T274, T294, 0x0L);}
  val_t T296;
  T296 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po1__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_3_po1__io_p2x.values[0]));
  val_t T297;
  { T297 = TERNARY_1(T280, T296, T295);}
  val_t T298;
  T298 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po1__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_3_po1__io_den.values[0]));
  val_t T299;
  { T299 = TERNARY_1(T286, T298, T297);}
  val_t T300;
  { T300 = TERNARY(T291, 0x0L, T299);}
  { ClosestOp_DistanceOp_3_po1__io_poutx.values[0] = T300;}
  { ClosestOp_DistanceOp_3_po2__io_p1x.values[0] = ClosestOp_DistanceOp_3_po1__io_poutx.values[0];}
  val_t T301;
  T301 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po2__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_3_po2__io_p1x.values[0]));
  val_t T302;
  T302 = fromDouble(toDouble(T301) + toDouble(T293));
  val_t T303;
  T303 = fromDouble(sqrt(toDouble(T302)));
  { ClosestOp_DistanceOp_3_po2__io_operation.values[0] = 0x4L;}
  val_t T304;
  T304 = ClosestOp_DistanceOp_3_po2__io_operation.values[0] == 0x4L;
  val_t T305;
  T305 = ClosestOp_DistanceOp_3_po2__io_operation.values[0] == 0x3L;
  val_t T306;
  T306 = ClosestOp_DistanceOp_3_po2__io_operation.values[0] == 0x2L;
  val_t T307;
  T307 = ClosestOp_DistanceOp_3_po2__io_operation.values[0] == 0x1L;
  val_t T308;
  T308 = ClosestOp_DistanceOp_3_po2__io_operation.values[0] == 0x0L;
  val_t T309;
  { T309 = T308 | T307;}
  val_t T310;
  { T310 = T309 | T306;}
  val_t T311;
  { T311 = T310 | T305;}
  val_t T312;
  { T312 = T311 ^ 0x1L;}
  val_t T313;
  { T313 = T312 & T304;}
  val_t T314;
  { T314 = TERNARY(T313, T303, 0x0L);}
  { ClosestOp_DistanceOp_3_po2__io_out.values[0] = T314;}
  { ClosestOp_DistanceOp_3__io_out.values[0] = ClosestOp_DistanceOp_3_po2__io_out.values[0];}
  { ClosestOp_mo__io_values_3.values[0] = ClosestOp_DistanceOp_3__io_out.values[0];}
  { ClosestOp_mo_Min2Op_2__io_value.values[0] = ClosestOp_mo__io_values_3.values[0];}
  { ClosestOp_DistanceOp_2__io_p2y.values[0] = ClosestOp__io_ys_2.values[0];}
  { ClosestOp_DistanceOp_2_po1__io_p2y.values[0] = ClosestOp_DistanceOp_2__io_p2y.values[0];}
  { ClosestOp_DistanceOp_2__io_p1y.values[0] = ClosestOp__io_pointY.values[0];}
  { ClosestOp_DistanceOp_2_po1__io_p1y.values[0] = ClosestOp_DistanceOp_2__io_p1y.values[0];}
  val_t T315;
  T315 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po1__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_2_po1__io_p2y.values[0]));
  { ClosestOp_DistanceOp_2_po1__io_operation.values[0] = 0x2L;}
  val_t T316;
  T316 = ClosestOp_DistanceOp_2_po1__io_operation.values[0] == 0x1L;
  val_t T317;
  T317 = ClosestOp_DistanceOp_2_po1__io_operation.values[0] == 0x0L;
  val_t T318;
  { T318 = T317 ^ 0x1L;}
  val_t T319;
  { T319 = T318 & T316;}
  val_t T320;
  { T320 = TERNARY(T319, T315, 0x0L);}
  val_t T321;
  T321 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po1__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_2_po1__io_p2y.values[0]));
  val_t T322;
  T322 = ClosestOp_DistanceOp_2_po1__io_operation.values[0] == 0x2L;
  val_t T323;
  { T323 = T317 | T316;}
  val_t T324;
  { T324 = T323 ^ 0x1L;}
  val_t T325;
  { T325 = T324 & T322;}
  val_t T326;
  { T326 = TERNARY_1(T325, T321, T320);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_2_po1__io_den.values[0] = __r;}
  val_t T327;
  T327 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po1__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_2_po1__io_den.values[0]));
  val_t T328;
  T328 = ClosestOp_DistanceOp_2_po1__io_operation.values[0] == 0x3L;
  val_t T329;
  { T329 = T323 | T322;}
  val_t T330;
  { T330 = T329 ^ 0x1L;}
  val_t T331;
  { T331 = T330 & T328;}
  val_t T332;
  { T332 = TERNARY_1(T331, T327, T326);}
  val_t T333;
  T333 = ClosestOp_DistanceOp_2_po1__io_operation.values[0] == 0x4L;
  val_t T334;
  { T334 = T329 | T328;}
  val_t T335;
  { T335 = T334 | T333;}
  val_t T336;
  { T336 = T335 ^ 0x1L;}
  val_t T337;
  { T337 = TERNARY(T336, 0x0L, T332);}
  { ClosestOp_DistanceOp_2_po1__io_pouty.values[0] = T337;}
  { ClosestOp_DistanceOp_2_po2__io_p1y.values[0] = ClosestOp_DistanceOp_2_po1__io_pouty.values[0];}
  val_t T338;
  T338 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po2__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_2_po2__io_p1y.values[0]));
  { ClosestOp_DistanceOp_2__io_p2x.values[0] = ClosestOp__io_xs_2.values[0];}
  { ClosestOp_DistanceOp_2_po1__io_p2x.values[0] = ClosestOp_DistanceOp_2__io_p2x.values[0];}
  { ClosestOp_DistanceOp_2__io_p1x.values[0] = ClosestOp__io_pointX.values[0];}
  { ClosestOp_DistanceOp_2_po1__io_p1x.values[0] = ClosestOp_DistanceOp_2__io_p1x.values[0];}
  val_t T339;
  T339 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po1__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_2_po1__io_p2x.values[0]));
  val_t T340;
  { T340 = TERNARY(T319, T339, 0x0L);}
  val_t T341;
  T341 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po1__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_2_po1__io_p2x.values[0]));
  val_t T342;
  { T342 = TERNARY_1(T325, T341, T340);}
  val_t T343;
  T343 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po1__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_2_po1__io_den.values[0]));
  val_t T344;
  { T344 = TERNARY_1(T331, T343, T342);}
  val_t T345;
  { T345 = TERNARY(T336, 0x0L, T344);}
  { ClosestOp_DistanceOp_2_po1__io_poutx.values[0] = T345;}
  { ClosestOp_DistanceOp_2_po2__io_p1x.values[0] = ClosestOp_DistanceOp_2_po1__io_poutx.values[0];}
  val_t T346;
  T346 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po2__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_2_po2__io_p1x.values[0]));
  val_t T347;
  T347 = fromDouble(toDouble(T346) + toDouble(T338));
  val_t T348;
  T348 = fromDouble(sqrt(toDouble(T347)));
  { ClosestOp_DistanceOp_2_po2__io_operation.values[0] = 0x4L;}
  val_t T349;
  T349 = ClosestOp_DistanceOp_2_po2__io_operation.values[0] == 0x4L;
  val_t T350;
  T350 = ClosestOp_DistanceOp_2_po2__io_operation.values[0] == 0x3L;
  val_t T351;
  T351 = ClosestOp_DistanceOp_2_po2__io_operation.values[0] == 0x2L;
  val_t T352;
  T352 = ClosestOp_DistanceOp_2_po2__io_operation.values[0] == 0x1L;
  val_t T353;
  T353 = ClosestOp_DistanceOp_2_po2__io_operation.values[0] == 0x0L;
  val_t T354;
  { T354 = T353 | T352;}
  val_t T355;
  { T355 = T354 | T351;}
  val_t T356;
  { T356 = T355 | T350;}
  val_t T357;
  { T357 = T356 ^ 0x1L;}
  val_t T358;
  { T358 = T357 & T349;}
  val_t T359;
  { T359 = TERNARY(T358, T348, 0x0L);}
  { ClosestOp_DistanceOp_2_po2__io_out.values[0] = T359;}
  { ClosestOp_DistanceOp_2__io_out.values[0] = ClosestOp_DistanceOp_2_po2__io_out.values[0];}
  { ClosestOp_mo__io_values_2.values[0] = ClosestOp_DistanceOp_2__io_out.values[0];}
  { ClosestOp_mo_Min2Op_1__io_value.values[0] = ClosestOp_mo__io_values_2.values[0];}
  { ClosestOp_DistanceOp_1__io_p2y.values[0] = ClosestOp__io_ys_1.values[0];}
  { ClosestOp_DistanceOp_1_po1__io_p2y.values[0] = ClosestOp_DistanceOp_1__io_p2y.values[0];}
  { ClosestOp_DistanceOp_1__io_p1y.values[0] = ClosestOp__io_pointY.values[0];}
  { ClosestOp_DistanceOp_1_po1__io_p1y.values[0] = ClosestOp_DistanceOp_1__io_p1y.values[0];}
  val_t T360;
  T360 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po1__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_1_po1__io_p2y.values[0]));
  { ClosestOp_DistanceOp_1_po1__io_operation.values[0] = 0x2L;}
  val_t T361;
  T361 = ClosestOp_DistanceOp_1_po1__io_operation.values[0] == 0x1L;
  val_t T362;
  T362 = ClosestOp_DistanceOp_1_po1__io_operation.values[0] == 0x0L;
  val_t T363;
  { T363 = T362 ^ 0x1L;}
  val_t T364;
  { T364 = T363 & T361;}
  val_t T365;
  { T365 = TERNARY(T364, T360, 0x0L);}
  val_t T366;
  T366 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po1__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_1_po1__io_p2y.values[0]));
  val_t T367;
  T367 = ClosestOp_DistanceOp_1_po1__io_operation.values[0] == 0x2L;
  val_t T368;
  { T368 = T362 | T361;}
  val_t T369;
  { T369 = T368 ^ 0x1L;}
  val_t T370;
  { T370 = T369 & T367;}
  val_t T371;
  { T371 = TERNARY_1(T370, T366, T365);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_1_po1__io_den.values[0] = __r;}
  val_t T372;
  T372 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po1__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_1_po1__io_den.values[0]));
  val_t T373;
  T373 = ClosestOp_DistanceOp_1_po1__io_operation.values[0] == 0x3L;
  val_t T374;
  { T374 = T368 | T367;}
  val_t T375;
  { T375 = T374 ^ 0x1L;}
  val_t T376;
  { T376 = T375 & T373;}
  val_t T377;
  { T377 = TERNARY_1(T376, T372, T371);}
  val_t T378;
  T378 = ClosestOp_DistanceOp_1_po1__io_operation.values[0] == 0x4L;
  val_t T379;
  { T379 = T374 | T373;}
  val_t T380;
  { T380 = T379 | T378;}
  val_t T381;
  { T381 = T380 ^ 0x1L;}
  val_t T382;
  { T382 = TERNARY(T381, 0x0L, T377);}
  { ClosestOp_DistanceOp_1_po1__io_pouty.values[0] = T382;}
  { ClosestOp_DistanceOp_1_po2__io_p1y.values[0] = ClosestOp_DistanceOp_1_po1__io_pouty.values[0];}
  val_t T383;
  T383 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po2__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_1_po2__io_p1y.values[0]));
  { ClosestOp_DistanceOp_1__io_p2x.values[0] = ClosestOp__io_xs_1.values[0];}
  { ClosestOp_DistanceOp_1_po1__io_p2x.values[0] = ClosestOp_DistanceOp_1__io_p2x.values[0];}
  { ClosestOp_DistanceOp_1__io_p1x.values[0] = ClosestOp__io_pointX.values[0];}
  { ClosestOp_DistanceOp_1_po1__io_p1x.values[0] = ClosestOp_DistanceOp_1__io_p1x.values[0];}
  val_t T384;
  T384 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po1__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_1_po1__io_p2x.values[0]));
  val_t T385;
  { T385 = TERNARY(T364, T384, 0x0L);}
  val_t T386;
  T386 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po1__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_1_po1__io_p2x.values[0]));
  val_t T387;
  { T387 = TERNARY_1(T370, T386, T385);}
  val_t T388;
  T388 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po1__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_1_po1__io_den.values[0]));
  val_t T389;
  { T389 = TERNARY_1(T376, T388, T387);}
  val_t T390;
  { T390 = TERNARY(T381, 0x0L, T389);}
  { ClosestOp_DistanceOp_1_po1__io_poutx.values[0] = T390;}
  { ClosestOp_DistanceOp_1_po2__io_p1x.values[0] = ClosestOp_DistanceOp_1_po1__io_poutx.values[0];}
  val_t T391;
  T391 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po2__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_1_po2__io_p1x.values[0]));
  val_t T392;
  T392 = fromDouble(toDouble(T391) + toDouble(T383));
  val_t T393;
  T393 = fromDouble(sqrt(toDouble(T392)));
  { ClosestOp_DistanceOp_1_po2__io_operation.values[0] = 0x4L;}
  val_t T394;
  T394 = ClosestOp_DistanceOp_1_po2__io_operation.values[0] == 0x4L;
  val_t T395;
  T395 = ClosestOp_DistanceOp_1_po2__io_operation.values[0] == 0x3L;
  val_t T396;
  T396 = ClosestOp_DistanceOp_1_po2__io_operation.values[0] == 0x2L;
  val_t T397;
  T397 = ClosestOp_DistanceOp_1_po2__io_operation.values[0] == 0x1L;
  val_t T398;
  T398 = ClosestOp_DistanceOp_1_po2__io_operation.values[0] == 0x0L;
  val_t T399;
  { T399 = T398 | T397;}
  val_t T400;
  { T400 = T399 | T396;}
  val_t T401;
  { T401 = T400 | T395;}
  val_t T402;
  { T402 = T401 ^ 0x1L;}
  val_t T403;
  { T403 = T402 & T394;}
  val_t T404;
  { T404 = TERNARY(T403, T393, 0x0L);}
  { ClosestOp_DistanceOp_1_po2__io_out.values[0] = T404;}
  { ClosestOp_DistanceOp_1__io_out.values[0] = ClosestOp_DistanceOp_1_po2__io_out.values[0];}
  { ClosestOp_mo__io_values_1.values[0] = ClosestOp_DistanceOp_1__io_out.values[0];}
  { ClosestOp_mo_Min2Op__io_value.values[0] = ClosestOp_mo__io_values_1.values[0];}
  { ClosestOp_DistanceOp__io_p2y.values[0] = ClosestOp__io_ys_0.values[0];}
  { ClosestOp_DistanceOp_po1__io_p2y.values[0] = ClosestOp_DistanceOp__io_p2y.values[0];}
  { ClosestOp_DistanceOp__io_p1y.values[0] = ClosestOp__io_pointY.values[0];}
  { ClosestOp_DistanceOp_po1__io_p1y.values[0] = ClosestOp_DistanceOp__io_p1y.values[0];}
  val_t T405;
  T405 = fromDouble(toDouble(ClosestOp_DistanceOp_po1__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_po1__io_p2y.values[0]));
  { ClosestOp_DistanceOp_po1__io_operation.values[0] = 0x2L;}
  val_t T406;
  T406 = ClosestOp_DistanceOp_po1__io_operation.values[0] == 0x1L;
  val_t T407;
  T407 = ClosestOp_DistanceOp_po1__io_operation.values[0] == 0x0L;
  val_t T408;
  { T408 = T407 ^ 0x1L;}
  val_t T409;
  { T409 = T408 & T406;}
  val_t T410;
  { T410 = TERNARY(T409, T405, 0x0L);}
  val_t T411;
  T411 = fromDouble(toDouble(ClosestOp_DistanceOp_po1__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_po1__io_p2y.values[0]));
  val_t T412;
  T412 = ClosestOp_DistanceOp_po1__io_operation.values[0] == 0x2L;
  val_t T413;
  { T413 = T407 | T406;}
  val_t T414;
  { T414 = T413 ^ 0x1L;}
  val_t T415;
  { T415 = T414 & T412;}
  val_t T416;
  { T416 = TERNARY_1(T415, T411, T410);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_po1__io_den.values[0] = __r;}
  val_t T417;
  T417 = fromDouble(toDouble(ClosestOp_DistanceOp_po1__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_po1__io_den.values[0]));
  val_t T418;
  T418 = ClosestOp_DistanceOp_po1__io_operation.values[0] == 0x3L;
  val_t T419;
  { T419 = T413 | T412;}
  val_t T420;
  { T420 = T419 ^ 0x1L;}
  val_t T421;
  { T421 = T420 & T418;}
  val_t T422;
  { T422 = TERNARY_1(T421, T417, T416);}
  val_t T423;
  T423 = ClosestOp_DistanceOp_po1__io_operation.values[0] == 0x4L;
  val_t T424;
  { T424 = T419 | T418;}
  val_t T425;
  { T425 = T424 | T423;}
  val_t T426;
  { T426 = T425 ^ 0x1L;}
  val_t T427;
  { T427 = TERNARY(T426, 0x0L, T422);}
  { ClosestOp_DistanceOp_po1__io_pouty.values[0] = T427;}
  { ClosestOp_DistanceOp_po2__io_p1y.values[0] = ClosestOp_DistanceOp_po1__io_pouty.values[0];}
  val_t T428;
  T428 = fromDouble(toDouble(ClosestOp_DistanceOp_po2__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_po2__io_p1y.values[0]));
  { ClosestOp_DistanceOp__io_p2x.values[0] = ClosestOp__io_xs_0.values[0];}
  { ClosestOp_DistanceOp_po1__io_p2x.values[0] = ClosestOp_DistanceOp__io_p2x.values[0];}
  { ClosestOp_DistanceOp__io_p1x.values[0] = ClosestOp__io_pointX.values[0];}
  { ClosestOp_DistanceOp_po1__io_p1x.values[0] = ClosestOp_DistanceOp__io_p1x.values[0];}
  val_t T429;
  T429 = fromDouble(toDouble(ClosestOp_DistanceOp_po1__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_po1__io_p2x.values[0]));
  val_t T430;
  { T430 = TERNARY(T409, T429, 0x0L);}
  val_t T431;
  T431 = fromDouble(toDouble(ClosestOp_DistanceOp_po1__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_po1__io_p2x.values[0]));
  val_t T432;
  { T432 = TERNARY_1(T415, T431, T430);}
  val_t T433;
  T433 = fromDouble(toDouble(ClosestOp_DistanceOp_po1__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_po1__io_den.values[0]));
  val_t T434;
  { T434 = TERNARY_1(T421, T433, T432);}
  val_t T435;
  { T435 = TERNARY(T426, 0x0L, T434);}
  { ClosestOp_DistanceOp_po1__io_poutx.values[0] = T435;}
  { ClosestOp_DistanceOp_po2__io_p1x.values[0] = ClosestOp_DistanceOp_po1__io_poutx.values[0];}
  val_t T436;
  T436 = fromDouble(toDouble(ClosestOp_DistanceOp_po2__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_po2__io_p1x.values[0]));
  val_t T437;
  T437 = fromDouble(toDouble(T436) + toDouble(T428));
  val_t T438;
  T438 = fromDouble(sqrt(toDouble(T437)));
  { ClosestOp_DistanceOp_po2__io_operation.values[0] = 0x4L;}
  val_t T439;
  T439 = ClosestOp_DistanceOp_po2__io_operation.values[0] == 0x4L;
  val_t T440;
  T440 = ClosestOp_DistanceOp_po2__io_operation.values[0] == 0x3L;
  val_t T441;
  T441 = ClosestOp_DistanceOp_po2__io_operation.values[0] == 0x2L;
  val_t T442;
  T442 = ClosestOp_DistanceOp_po2__io_operation.values[0] == 0x1L;
  val_t T443;
  T443 = ClosestOp_DistanceOp_po2__io_operation.values[0] == 0x0L;
  val_t T444;
  { T444 = T443 | T442;}
  val_t T445;
  { T445 = T444 | T441;}
  val_t T446;
  { T446 = T445 | T440;}
  val_t T447;
  { T447 = T446 ^ 0x1L;}
  val_t T448;
  { T448 = T447 & T439;}
  val_t T449;
  { T449 = TERNARY(T448, T438, 0x0L);}
  { ClosestOp_DistanceOp_po2__io_out.values[0] = T449;}
  { ClosestOp_DistanceOp__io_out.values[0] = ClosestOp_DistanceOp_po2__io_out.values[0];}
  { ClosestOp_mo__io_values_0.values[0] = ClosestOp_DistanceOp__io_out.values[0];}
  { ClosestOp_mo_Min2Op__io_oldValue.values[0] = ClosestOp_mo__io_values_0.values[0];}
  val_t T450;
  T450 = toDouble(ClosestOp_mo_Min2Op__io_value.values[0]) >= toDouble(ClosestOp_mo_Min2Op__io_oldValue.values[0]);
  val_t T451;
  { T451 = TERNARY_1(T450, ClosestOp_mo_Min2Op__io_oldValue.values[0], ClosestOp_mo_Min2Op__io_value.values[0]);}
  { ClosestOp_mo_Min2Op__io_newValue.values[0] = T451;}
  { ClosestOp_mo_Min2Op_1__io_oldValue.values[0] = ClosestOp_mo_Min2Op__io_newValue.values[0];}
  val_t T452;
  T452 = toDouble(ClosestOp_mo_Min2Op_1__io_value.values[0]) >= toDouble(ClosestOp_mo_Min2Op_1__io_oldValue.values[0]);
  val_t T453;
  { T453 = TERNARY_1(T452, ClosestOp_mo_Min2Op_1__io_oldValue.values[0], ClosestOp_mo_Min2Op_1__io_value.values[0]);}
  { ClosestOp_mo_Min2Op_1__io_newValue.values[0] = T453;}
  { ClosestOp_mo_Min2Op_2__io_oldValue.values[0] = ClosestOp_mo_Min2Op_1__io_newValue.values[0];}
  val_t T454;
  T454 = toDouble(ClosestOp_mo_Min2Op_2__io_value.values[0]) >= toDouble(ClosestOp_mo_Min2Op_2__io_oldValue.values[0]);
  val_t T455;
  { T455 = TERNARY_1(T454, ClosestOp_mo_Min2Op_2__io_oldValue.values[0], ClosestOp_mo_Min2Op_2__io_value.values[0]);}
  { ClosestOp_mo_Min2Op_2__io_newValue.values[0] = T455;}
  { ClosestOp_mo_Min2Op_3__io_oldValue.values[0] = ClosestOp_mo_Min2Op_2__io_newValue.values[0];}
  val_t T456;
  T456 = toDouble(ClosestOp_mo_Min2Op_3__io_value.values[0]) >= toDouble(ClosestOp_mo_Min2Op_3__io_oldValue.values[0]);
  val_t T457;
  { T457 = TERNARY_1(T456, ClosestOp_mo_Min2Op_3__io_oldValue.values[0], ClosestOp_mo_Min2Op_3__io_value.values[0]);}
  { ClosestOp_mo_Min2Op_3__io_newValue.values[0] = T457;}
  { ClosestOp_mo_Min2Op_4__io_oldValue.values[0] = ClosestOp_mo_Min2Op_3__io_newValue.values[0];}
  val_t T458;
  T458 = toDouble(ClosestOp_mo_Min2Op_4__io_value.values[0]) >= toDouble(ClosestOp_mo_Min2Op_4__io_oldValue.values[0]);
  val_t T459;
  { T459 = TERNARY_1(T458, ClosestOp_mo_Min2Op_4__io_oldValue.values[0], ClosestOp_mo_Min2Op_4__io_value.values[0]);}
  { ClosestOp_mo_Min2Op_4__io_newValue.values[0] = T459;}
  { ClosestOp_mo_Min2Op_5__io_oldValue.values[0] = ClosestOp_mo_Min2Op_4__io_newValue.values[0];}
  val_t T460;
  T460 = toDouble(ClosestOp_mo_Min2Op_5__io_value.values[0]) >= toDouble(ClosestOp_mo_Min2Op_5__io_oldValue.values[0]);
  val_t T461;
  { T461 = TERNARY_1(T460, ClosestOp_mo_Min2Op_5__io_oldValue.values[0], ClosestOp_mo_Min2Op_5__io_value.values[0]);}
  { ClosestOp_mo_Min2Op_5__io_newValue.values[0] = T461;}
  { ClosestOp_mo_Min2Op_6__io_oldValue.values[0] = ClosestOp_mo_Min2Op_5__io_newValue.values[0];}
  val_t T462;
  T462 = toDouble(ClosestOp_mo_Min2Op_6__io_value.values[0]) >= toDouble(ClosestOp_mo_Min2Op_6__io_oldValue.values[0]);
  val_t T463;
  { T463 = TERNARY_1(T462, ClosestOp_mo_Min2Op_6__io_oldValue.values[0], ClosestOp_mo_Min2Op_6__io_value.values[0]);}
  { ClosestOp_mo_Min2Op_6__io_newValue.values[0] = T463;}
  { ClosestOp_mo_Min2Op_7__io_oldValue.values[0] = ClosestOp_mo_Min2Op_6__io_newValue.values[0];}
  val_t T464;
  T464 = toDouble(ClosestOp_mo_Min2Op_7__io_value.values[0]) >= toDouble(ClosestOp_mo_Min2Op_7__io_oldValue.values[0]);
  val_t T465;
  { T465 = TERNARY_1(T464, ClosestOp_mo_Min2Op_7__io_oldValue.values[0], ClosestOp_mo_Min2Op_7__io_value.values[0]);}
  { ClosestOp_mo_Min2Op_7__io_newValue.values[0] = T465;}
  { ClosestOp_mo_Min2Op_8__io_oldValue.values[0] = ClosestOp_mo_Min2Op_7__io_newValue.values[0];}
  val_t T466;
  T466 = toDouble(ClosestOp_mo_Min2Op_8__io_value.values[0]) >= toDouble(ClosestOp_mo_Min2Op_8__io_oldValue.values[0]);
  val_t T467;
  { T467 = TERNARY_1(T466, ClosestOp_mo_Min2Op_8__io_oldValue.values[0], ClosestOp_mo_Min2Op_8__io_value.values[0]);}
  { ClosestOp_mo_Min2Op_8__io_newValue.values[0] = T467;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_9_po2__io_p2x.values[0] = __r;}
  val_t T468;
  T468 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po2__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_9_po2__io_p2x.values[0]));
  val_t T469;
  { T469 = T38 ^ 0x1L;}
  val_t T470;
  { T470 = T469 & T37;}
  val_t T471;
  { T471 = TERNARY(T470, T468, 0x0L);}
  val_t T472;
  T472 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po2__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_9_po2__io_p2x.values[0]));
  val_t T473;
  { T473 = T39 ^ 0x1L;}
  val_t T474;
  { T474 = T473 & T36;}
  val_t T475;
  { T475 = TERNARY_1(T474, T472, T471);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_9_po2__io_den.values[0] = __r;}
  val_t T476;
  T476 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po2__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_9_po2__io_den.values[0]));
  val_t T477;
  { T477 = T40 ^ 0x1L;}
  val_t T478;
  { T478 = T477 & T35;}
  val_t T479;
  { T479 = TERNARY_1(T478, T476, T475);}
  val_t T480;
  { T480 = T41 | T34;}
  val_t T481;
  { T481 = T480 ^ 0x1L;}
  val_t T482;
  { T482 = TERNARY(T481, 0x0L, T479);}
  { ClosestOp_DistanceOp_9_po2__io_poutx.values[0] = T482;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_9_po2__io_p2y.values[0] = __r;}
  val_t T483;
  T483 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po2__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_9_po2__io_p2y.values[0]));
  val_t T484;
  { T484 = TERNARY(T470, T483, 0x0L);}
  val_t T485;
  T485 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po2__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_9_po2__io_p2y.values[0]));
  val_t T486;
  { T486 = TERNARY_1(T474, T485, T484);}
  val_t T487;
  T487 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po2__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_9_po2__io_den.values[0]));
  val_t T488;
  { T488 = TERNARY_1(T478, T487, T486);}
  val_t T489;
  { T489 = TERNARY(T481, 0x0L, T488);}
  { ClosestOp_DistanceOp_9_po2__io_pouty.values[0] = T489;}
  val_t T490;
  T490 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po1__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_9_po1__io_p1y.values[0]));
  val_t T491;
  T491 = fromDouble(toDouble(ClosestOp_DistanceOp_9_po1__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_9_po1__io_p1x.values[0]));
  val_t T492;
  T492 = fromDouble(toDouble(T491) + toDouble(T490));
  val_t T493;
  T493 = fromDouble(sqrt(toDouble(T492)));
  val_t T494;
  { T494 = T19 ^ 0x1L;}
  val_t T495;
  { T495 = T494 & T18;}
  val_t T496;
  { T496 = TERNARY(T495, T493, 0x0L);}
  { ClosestOp_DistanceOp_9_po1__io_out.values[0] = T496;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_8_po2__io_p2x.values[0] = __r;}
  val_t T497;
  T497 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po2__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_8_po2__io_p2x.values[0]));
  val_t T498;
  { T498 = T83 ^ 0x1L;}
  val_t T499;
  { T499 = T498 & T82;}
  val_t T500;
  { T500 = TERNARY(T499, T497, 0x0L);}
  val_t T501;
  T501 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po2__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_8_po2__io_p2x.values[0]));
  val_t T502;
  { T502 = T84 ^ 0x1L;}
  val_t T503;
  { T503 = T502 & T81;}
  val_t T504;
  { T504 = TERNARY_1(T503, T501, T500);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_8_po2__io_den.values[0] = __r;}
  val_t T505;
  T505 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po2__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_8_po2__io_den.values[0]));
  val_t T506;
  { T506 = T85 ^ 0x1L;}
  val_t T507;
  { T507 = T506 & T80;}
  val_t T508;
  { T508 = TERNARY_1(T507, T505, T504);}
  val_t T509;
  { T509 = T86 | T79;}
  val_t T510;
  { T510 = T509 ^ 0x1L;}
  val_t T511;
  { T511 = TERNARY(T510, 0x0L, T508);}
  { ClosestOp_DistanceOp_8_po2__io_poutx.values[0] = T511;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_8_po2__io_p2y.values[0] = __r;}
  val_t T512;
  T512 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po2__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_8_po2__io_p2y.values[0]));
  val_t T513;
  { T513 = TERNARY(T499, T512, 0x0L);}
  val_t T514;
  T514 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po2__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_8_po2__io_p2y.values[0]));
  val_t T515;
  { T515 = TERNARY_1(T503, T514, T513);}
  val_t T516;
  T516 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po2__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_8_po2__io_den.values[0]));
  val_t T517;
  { T517 = TERNARY_1(T507, T516, T515);}
  val_t T518;
  { T518 = TERNARY(T510, 0x0L, T517);}
  { ClosestOp_DistanceOp_8_po2__io_pouty.values[0] = T518;}
  val_t T519;
  T519 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po1__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_8_po1__io_p1y.values[0]));
  val_t T520;
  T520 = fromDouble(toDouble(ClosestOp_DistanceOp_8_po1__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_8_po1__io_p1x.values[0]));
  val_t T521;
  T521 = fromDouble(toDouble(T520) + toDouble(T519));
  val_t T522;
  T522 = fromDouble(sqrt(toDouble(T521)));
  val_t T523;
  { T523 = T64 ^ 0x1L;}
  val_t T524;
  { T524 = T523 & T63;}
  val_t T525;
  { T525 = TERNARY(T524, T522, 0x0L);}
  { ClosestOp_DistanceOp_8_po1__io_out.values[0] = T525;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_7_po2__io_p2x.values[0] = __r;}
  val_t T526;
  T526 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po2__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_7_po2__io_p2x.values[0]));
  val_t T527;
  { T527 = T128 ^ 0x1L;}
  val_t T528;
  { T528 = T527 & T127;}
  val_t T529;
  { T529 = TERNARY(T528, T526, 0x0L);}
  val_t T530;
  T530 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po2__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_7_po2__io_p2x.values[0]));
  val_t T531;
  { T531 = T129 ^ 0x1L;}
  val_t T532;
  { T532 = T531 & T126;}
  val_t T533;
  { T533 = TERNARY_1(T532, T530, T529);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_7_po2__io_den.values[0] = __r;}
  val_t T534;
  T534 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po2__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_7_po2__io_den.values[0]));
  val_t T535;
  { T535 = T130 ^ 0x1L;}
  val_t T536;
  { T536 = T535 & T125;}
  val_t T537;
  { T537 = TERNARY_1(T536, T534, T533);}
  val_t T538;
  { T538 = T131 | T124;}
  val_t T539;
  { T539 = T538 ^ 0x1L;}
  val_t T540;
  { T540 = TERNARY(T539, 0x0L, T537);}
  { ClosestOp_DistanceOp_7_po2__io_poutx.values[0] = T540;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_7_po2__io_p2y.values[0] = __r;}
  val_t T541;
  T541 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po2__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_7_po2__io_p2y.values[0]));
  val_t T542;
  { T542 = TERNARY(T528, T541, 0x0L);}
  val_t T543;
  T543 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po2__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_7_po2__io_p2y.values[0]));
  val_t T544;
  { T544 = TERNARY_1(T532, T543, T542);}
  val_t T545;
  T545 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po2__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_7_po2__io_den.values[0]));
  val_t T546;
  { T546 = TERNARY_1(T536, T545, T544);}
  val_t T547;
  { T547 = TERNARY(T539, 0x0L, T546);}
  { ClosestOp_DistanceOp_7_po2__io_pouty.values[0] = T547;}
  val_t T548;
  T548 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po1__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_7_po1__io_p1y.values[0]));
  val_t T549;
  T549 = fromDouble(toDouble(ClosestOp_DistanceOp_7_po1__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_7_po1__io_p1x.values[0]));
  val_t T550;
  T550 = fromDouble(toDouble(T549) + toDouble(T548));
  val_t T551;
  T551 = fromDouble(sqrt(toDouble(T550)));
  val_t T552;
  { T552 = T109 ^ 0x1L;}
  val_t T553;
  { T553 = T552 & T108;}
  val_t T554;
  { T554 = TERNARY(T553, T551, 0x0L);}
  { ClosestOp_DistanceOp_7_po1__io_out.values[0] = T554;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_6_po2__io_p2x.values[0] = __r;}
  val_t T555;
  T555 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po2__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_6_po2__io_p2x.values[0]));
  val_t T556;
  { T556 = T173 ^ 0x1L;}
  val_t T557;
  { T557 = T556 & T172;}
  val_t T558;
  { T558 = TERNARY(T557, T555, 0x0L);}
  val_t T559;
  T559 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po2__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_6_po2__io_p2x.values[0]));
  val_t T560;
  { T560 = T174 ^ 0x1L;}
  val_t T561;
  { T561 = T560 & T171;}
  val_t T562;
  { T562 = TERNARY_1(T561, T559, T558);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_6_po2__io_den.values[0] = __r;}
  val_t T563;
  T563 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po2__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_6_po2__io_den.values[0]));
  val_t T564;
  { T564 = T175 ^ 0x1L;}
  val_t T565;
  { T565 = T564 & T170;}
  val_t T566;
  { T566 = TERNARY_1(T565, T563, T562);}
  val_t T567;
  { T567 = T176 | T169;}
  val_t T568;
  { T568 = T567 ^ 0x1L;}
  val_t T569;
  { T569 = TERNARY(T568, 0x0L, T566);}
  { ClosestOp_DistanceOp_6_po2__io_poutx.values[0] = T569;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_6_po2__io_p2y.values[0] = __r;}
  val_t T570;
  T570 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po2__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_6_po2__io_p2y.values[0]));
  val_t T571;
  { T571 = TERNARY(T557, T570, 0x0L);}
  val_t T572;
  T572 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po2__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_6_po2__io_p2y.values[0]));
  val_t T573;
  { T573 = TERNARY_1(T561, T572, T571);}
  val_t T574;
  T574 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po2__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_6_po2__io_den.values[0]));
  val_t T575;
  { T575 = TERNARY_1(T565, T574, T573);}
  val_t T576;
  { T576 = TERNARY(T568, 0x0L, T575);}
  { ClosestOp_DistanceOp_6_po2__io_pouty.values[0] = T576;}
  val_t T577;
  T577 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po1__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_6_po1__io_p1y.values[0]));
  val_t T578;
  T578 = fromDouble(toDouble(ClosestOp_DistanceOp_6_po1__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_6_po1__io_p1x.values[0]));
  val_t T579;
  T579 = fromDouble(toDouble(T578) + toDouble(T577));
  val_t T580;
  T580 = fromDouble(sqrt(toDouble(T579)));
  val_t T581;
  { T581 = T154 ^ 0x1L;}
  val_t T582;
  { T582 = T581 & T153;}
  val_t T583;
  { T583 = TERNARY(T582, T580, 0x0L);}
  { ClosestOp_DistanceOp_6_po1__io_out.values[0] = T583;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_5_po2__io_p2x.values[0] = __r;}
  val_t T584;
  T584 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po2__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_5_po2__io_p2x.values[0]));
  val_t T585;
  { T585 = T218 ^ 0x1L;}
  val_t T586;
  { T586 = T585 & T217;}
  val_t T587;
  { T587 = TERNARY(T586, T584, 0x0L);}
  val_t T588;
  T588 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po2__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_5_po2__io_p2x.values[0]));
  val_t T589;
  { T589 = T219 ^ 0x1L;}
  val_t T590;
  { T590 = T589 & T216;}
  val_t T591;
  { T591 = TERNARY_1(T590, T588, T587);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_5_po2__io_den.values[0] = __r;}
  val_t T592;
  T592 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po2__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_5_po2__io_den.values[0]));
  val_t T593;
  { T593 = T220 ^ 0x1L;}
  val_t T594;
  { T594 = T593 & T215;}
  val_t T595;
  { T595 = TERNARY_1(T594, T592, T591);}
  val_t T596;
  { T596 = T221 | T214;}
  val_t T597;
  { T597 = T596 ^ 0x1L;}
  val_t T598;
  { T598 = TERNARY(T597, 0x0L, T595);}
  { ClosestOp_DistanceOp_5_po2__io_poutx.values[0] = T598;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_5_po2__io_p2y.values[0] = __r;}
  val_t T599;
  T599 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po2__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_5_po2__io_p2y.values[0]));
  val_t T600;
  { T600 = TERNARY(T586, T599, 0x0L);}
  val_t T601;
  T601 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po2__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_5_po2__io_p2y.values[0]));
  val_t T602;
  { T602 = TERNARY_1(T590, T601, T600);}
  val_t T603;
  T603 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po2__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_5_po2__io_den.values[0]));
  val_t T604;
  { T604 = TERNARY_1(T594, T603, T602);}
  val_t T605;
  { T605 = TERNARY(T597, 0x0L, T604);}
  { ClosestOp_DistanceOp_5_po2__io_pouty.values[0] = T605;}
  val_t T606;
  T606 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po1__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_5_po1__io_p1y.values[0]));
  val_t T607;
  T607 = fromDouble(toDouble(ClosestOp_DistanceOp_5_po1__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_5_po1__io_p1x.values[0]));
  val_t T608;
  T608 = fromDouble(toDouble(T607) + toDouble(T606));
  val_t T609;
  T609 = fromDouble(sqrt(toDouble(T608)));
  val_t T610;
  { T610 = T199 ^ 0x1L;}
  val_t T611;
  { T611 = T610 & T198;}
  val_t T612;
  { T612 = TERNARY(T611, T609, 0x0L);}
  { ClosestOp_DistanceOp_5_po1__io_out.values[0] = T612;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_4_po2__io_p2x.values[0] = __r;}
  val_t T613;
  T613 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po2__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_4_po2__io_p2x.values[0]));
  val_t T614;
  { T614 = T263 ^ 0x1L;}
  val_t T615;
  { T615 = T614 & T262;}
  val_t T616;
  { T616 = TERNARY(T615, T613, 0x0L);}
  val_t T617;
  T617 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po2__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_4_po2__io_p2x.values[0]));
  val_t T618;
  { T618 = T264 ^ 0x1L;}
  val_t T619;
  { T619 = T618 & T261;}
  val_t T620;
  { T620 = TERNARY_1(T619, T617, T616);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_4_po2__io_den.values[0] = __r;}
  val_t T621;
  T621 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po2__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_4_po2__io_den.values[0]));
  val_t T622;
  { T622 = T265 ^ 0x1L;}
  val_t T623;
  { T623 = T622 & T260;}
  val_t T624;
  { T624 = TERNARY_1(T623, T621, T620);}
  val_t T625;
  { T625 = T266 | T259;}
  val_t T626;
  { T626 = T625 ^ 0x1L;}
  val_t T627;
  { T627 = TERNARY(T626, 0x0L, T624);}
  { ClosestOp_DistanceOp_4_po2__io_poutx.values[0] = T627;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_4_po2__io_p2y.values[0] = __r;}
  val_t T628;
  T628 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po2__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_4_po2__io_p2y.values[0]));
  val_t T629;
  { T629 = TERNARY(T615, T628, 0x0L);}
  val_t T630;
  T630 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po2__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_4_po2__io_p2y.values[0]));
  val_t T631;
  { T631 = TERNARY_1(T619, T630, T629);}
  val_t T632;
  T632 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po2__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_4_po2__io_den.values[0]));
  val_t T633;
  { T633 = TERNARY_1(T623, T632, T631);}
  val_t T634;
  { T634 = TERNARY(T626, 0x0L, T633);}
  { ClosestOp_DistanceOp_4_po2__io_pouty.values[0] = T634;}
  val_t T635;
  T635 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po1__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_4_po1__io_p1y.values[0]));
  val_t T636;
  T636 = fromDouble(toDouble(ClosestOp_DistanceOp_4_po1__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_4_po1__io_p1x.values[0]));
  val_t T637;
  T637 = fromDouble(toDouble(T636) + toDouble(T635));
  val_t T638;
  T638 = fromDouble(sqrt(toDouble(T637)));
  val_t T639;
  { T639 = T244 ^ 0x1L;}
  val_t T640;
  { T640 = T639 & T243;}
  val_t T641;
  { T641 = TERNARY(T640, T638, 0x0L);}
  { ClosestOp_DistanceOp_4_po1__io_out.values[0] = T641;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_3_po2__io_p2x.values[0] = __r;}
  val_t T642;
  T642 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po2__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_3_po2__io_p2x.values[0]));
  val_t T643;
  { T643 = T308 ^ 0x1L;}
  val_t T644;
  { T644 = T643 & T307;}
  val_t T645;
  { T645 = TERNARY(T644, T642, 0x0L);}
  val_t T646;
  T646 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po2__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_3_po2__io_p2x.values[0]));
  val_t T647;
  { T647 = T309 ^ 0x1L;}
  val_t T648;
  { T648 = T647 & T306;}
  val_t T649;
  { T649 = TERNARY_1(T648, T646, T645);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_3_po2__io_den.values[0] = __r;}
  val_t T650;
  T650 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po2__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_3_po2__io_den.values[0]));
  val_t T651;
  { T651 = T310 ^ 0x1L;}
  val_t T652;
  { T652 = T651 & T305;}
  val_t T653;
  { T653 = TERNARY_1(T652, T650, T649);}
  val_t T654;
  { T654 = T311 | T304;}
  val_t T655;
  { T655 = T654 ^ 0x1L;}
  val_t T656;
  { T656 = TERNARY(T655, 0x0L, T653);}
  { ClosestOp_DistanceOp_3_po2__io_poutx.values[0] = T656;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_3_po2__io_p2y.values[0] = __r;}
  val_t T657;
  T657 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po2__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_3_po2__io_p2y.values[0]));
  val_t T658;
  { T658 = TERNARY(T644, T657, 0x0L);}
  val_t T659;
  T659 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po2__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_3_po2__io_p2y.values[0]));
  val_t T660;
  { T660 = TERNARY_1(T648, T659, T658);}
  val_t T661;
  T661 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po2__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_3_po2__io_den.values[0]));
  val_t T662;
  { T662 = TERNARY_1(T652, T661, T660);}
  val_t T663;
  { T663 = TERNARY(T655, 0x0L, T662);}
  { ClosestOp_DistanceOp_3_po2__io_pouty.values[0] = T663;}
  val_t T664;
  T664 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po1__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_3_po1__io_p1y.values[0]));
  val_t T665;
  T665 = fromDouble(toDouble(ClosestOp_DistanceOp_3_po1__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_3_po1__io_p1x.values[0]));
  val_t T666;
  T666 = fromDouble(toDouble(T665) + toDouble(T664));
  val_t T667;
  T667 = fromDouble(sqrt(toDouble(T666)));
  val_t T668;
  { T668 = T289 ^ 0x1L;}
  val_t T669;
  { T669 = T668 & T288;}
  val_t T670;
  { T670 = TERNARY(T669, T667, 0x0L);}
  { ClosestOp_DistanceOp_3_po1__io_out.values[0] = T670;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_2_po2__io_p2x.values[0] = __r;}
  val_t T671;
  T671 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po2__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_2_po2__io_p2x.values[0]));
  val_t T672;
  { T672 = T353 ^ 0x1L;}
  val_t T673;
  { T673 = T672 & T352;}
  val_t T674;
  { T674 = TERNARY(T673, T671, 0x0L);}
  val_t T675;
  T675 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po2__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_2_po2__io_p2x.values[0]));
  val_t T676;
  { T676 = T354 ^ 0x1L;}
  val_t T677;
  { T677 = T676 & T351;}
  val_t T678;
  { T678 = TERNARY_1(T677, T675, T674);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_2_po2__io_den.values[0] = __r;}
  val_t T679;
  T679 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po2__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_2_po2__io_den.values[0]));
  val_t T680;
  { T680 = T355 ^ 0x1L;}
  val_t T681;
  { T681 = T680 & T350;}
  val_t T682;
  { T682 = TERNARY_1(T681, T679, T678);}
  val_t T683;
  { T683 = T356 | T349;}
  val_t T684;
  { T684 = T683 ^ 0x1L;}
  val_t T685;
  { T685 = TERNARY(T684, 0x0L, T682);}
  { ClosestOp_DistanceOp_2_po2__io_poutx.values[0] = T685;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_2_po2__io_p2y.values[0] = __r;}
  val_t T686;
  T686 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po2__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_2_po2__io_p2y.values[0]));
  val_t T687;
  { T687 = TERNARY(T673, T686, 0x0L);}
  val_t T688;
  T688 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po2__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_2_po2__io_p2y.values[0]));
  val_t T689;
  { T689 = TERNARY_1(T677, T688, T687);}
  val_t T690;
  T690 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po2__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_2_po2__io_den.values[0]));
  val_t T691;
  { T691 = TERNARY_1(T681, T690, T689);}
  val_t T692;
  { T692 = TERNARY(T684, 0x0L, T691);}
  { ClosestOp_DistanceOp_2_po2__io_pouty.values[0] = T692;}
  val_t T693;
  T693 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po1__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_2_po1__io_p1y.values[0]));
  val_t T694;
  T694 = fromDouble(toDouble(ClosestOp_DistanceOp_2_po1__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_2_po1__io_p1x.values[0]));
  val_t T695;
  T695 = fromDouble(toDouble(T694) + toDouble(T693));
  val_t T696;
  T696 = fromDouble(sqrt(toDouble(T695)));
  val_t T697;
  { T697 = T334 ^ 0x1L;}
  val_t T698;
  { T698 = T697 & T333;}
  val_t T699;
  { T699 = TERNARY(T698, T696, 0x0L);}
  { ClosestOp_DistanceOp_2_po1__io_out.values[0] = T699;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_1_po2__io_p2x.values[0] = __r;}
  val_t T700;
  T700 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po2__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_1_po2__io_p2x.values[0]));
  val_t T701;
  { T701 = T398 ^ 0x1L;}
  val_t T702;
  { T702 = T701 & T397;}
  val_t T703;
  { T703 = TERNARY(T702, T700, 0x0L);}
  val_t T704;
  T704 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po2__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_1_po2__io_p2x.values[0]));
  val_t T705;
  { T705 = T399 ^ 0x1L;}
  val_t T706;
  { T706 = T705 & T396;}
  val_t T707;
  { T707 = TERNARY_1(T706, T704, T703);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_1_po2__io_den.values[0] = __r;}
  val_t T708;
  T708 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po2__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_1_po2__io_den.values[0]));
  val_t T709;
  { T709 = T400 ^ 0x1L;}
  val_t T710;
  { T710 = T709 & T395;}
  val_t T711;
  { T711 = TERNARY_1(T710, T708, T707);}
  val_t T712;
  { T712 = T401 | T394;}
  val_t T713;
  { T713 = T712 ^ 0x1L;}
  val_t T714;
  { T714 = TERNARY(T713, 0x0L, T711);}
  { ClosestOp_DistanceOp_1_po2__io_poutx.values[0] = T714;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_1_po2__io_p2y.values[0] = __r;}
  val_t T715;
  T715 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po2__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_1_po2__io_p2y.values[0]));
  val_t T716;
  { T716 = TERNARY(T702, T715, 0x0L);}
  val_t T717;
  T717 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po2__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_1_po2__io_p2y.values[0]));
  val_t T718;
  { T718 = TERNARY_1(T706, T717, T716);}
  val_t T719;
  T719 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po2__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_1_po2__io_den.values[0]));
  val_t T720;
  { T720 = TERNARY_1(T710, T719, T718);}
  val_t T721;
  { T721 = TERNARY(T713, 0x0L, T720);}
  { ClosestOp_DistanceOp_1_po2__io_pouty.values[0] = T721;}
  val_t T722;
  T722 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po1__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_1_po1__io_p1y.values[0]));
  val_t T723;
  T723 = fromDouble(toDouble(ClosestOp_DistanceOp_1_po1__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_1_po1__io_p1x.values[0]));
  val_t T724;
  T724 = fromDouble(toDouble(T723) + toDouble(T722));
  val_t T725;
  T725 = fromDouble(sqrt(toDouble(T724)));
  val_t T726;
  { T726 = T379 ^ 0x1L;}
  val_t T727;
  { T727 = T726 & T378;}
  val_t T728;
  { T728 = TERNARY(T727, T725, 0x0L);}
  { ClosestOp_DistanceOp_1_po1__io_out.values[0] = T728;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_po2__io_p2x.values[0] = __r;}
  val_t T729;
  T729 = fromDouble(toDouble(ClosestOp_DistanceOp_po2__io_p1x.values[0]) + toDouble(ClosestOp_DistanceOp_po2__io_p2x.values[0]));
  val_t T730;
  { T730 = T443 ^ 0x1L;}
  val_t T731;
  { T731 = T730 & T442;}
  val_t T732;
  { T732 = TERNARY(T731, T729, 0x0L);}
  val_t T733;
  T733 = fromDouble(toDouble(ClosestOp_DistanceOp_po2__io_p1x.values[0]) - toDouble(ClosestOp_DistanceOp_po2__io_p2x.values[0]));
  val_t T734;
  { T734 = T444 ^ 0x1L;}
  val_t T735;
  { T735 = T734 & T441;}
  val_t T736;
  { T736 = TERNARY_1(T735, T733, T732);}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_po2__io_den.values[0] = __r;}
  val_t T737;
  T737 = fromDouble(toDouble(ClosestOp_DistanceOp_po2__io_p1x.values[0]) / toDouble(ClosestOp_DistanceOp_po2__io_den.values[0]));
  val_t T738;
  { T738 = T445 ^ 0x1L;}
  val_t T739;
  { T739 = T738 & T440;}
  val_t T740;
  { T740 = TERNARY_1(T739, T737, T736);}
  val_t T741;
  { T741 = T446 | T439;}
  val_t T742;
  { T742 = T741 ^ 0x1L;}
  val_t T743;
  { T743 = TERNARY(T742, 0x0L, T740);}
  { ClosestOp_DistanceOp_po2__io_poutx.values[0] = T743;}
  { val_t __r = this->__rand_val(); ClosestOp_DistanceOp_po2__io_p2y.values[0] = __r;}
  val_t T744;
  T744 = fromDouble(toDouble(ClosestOp_DistanceOp_po2__io_p1y.values[0]) + toDouble(ClosestOp_DistanceOp_po2__io_p2y.values[0]));
  val_t T745;
  { T745 = TERNARY(T731, T744, 0x0L);}
  val_t T746;
  T746 = fromDouble(toDouble(ClosestOp_DistanceOp_po2__io_p1y.values[0]) - toDouble(ClosestOp_DistanceOp_po2__io_p2y.values[0]));
  val_t T747;
  { T747 = TERNARY_1(T735, T746, T745);}
  val_t T748;
  T748 = fromDouble(toDouble(ClosestOp_DistanceOp_po2__io_p1y.values[0]) / toDouble(ClosestOp_DistanceOp_po2__io_den.values[0]));
  val_t T749;
  { T749 = TERNARY_1(T739, T748, T747);}
  val_t T750;
  { T750 = TERNARY(T742, 0x0L, T749);}
  { ClosestOp_DistanceOp_po2__io_pouty.values[0] = T750;}
  val_t T751;
  T751 = fromDouble(toDouble(ClosestOp_DistanceOp_po1__io_p1y.values[0]) * toDouble(ClosestOp_DistanceOp_po1__io_p1y.values[0]));
  val_t T752;
  T752 = fromDouble(toDouble(ClosestOp_DistanceOp_po1__io_p1x.values[0]) * toDouble(ClosestOp_DistanceOp_po1__io_p1x.values[0]));
  val_t T753;
  T753 = fromDouble(toDouble(T752) + toDouble(T751));
  val_t T754;
  T754 = fromDouble(sqrt(toDouble(T753)));
  val_t T755;
  { T755 = T424 ^ 0x1L;}
  val_t T756;
  { T756 = T755 & T423;}
  val_t T757;
  { T757 = TERNARY(T756, T754, 0x0L);}
  { ClosestOp_DistanceOp_po1__io_out.values[0] = T757;}
  { ClosestOp_mo_Min2Op__io_oldMin.values[0] = 0x0L;}
  val_t T758;
  { T758 = TERNARY(T450, ClosestOp_mo_Min2Op__io_oldMin.values[0], 0x1L);}
  { ClosestOp_mo_Min2Op__io_newMin.values[0] = T758;}
  { ClosestOp_mo_Min2Op_1__io_oldMin.values[0] = ClosestOp_mo_Min2Op__io_newMin.values[0];}
  val_t T759;
  { T759 = TERNARY(T452, ClosestOp_mo_Min2Op_1__io_oldMin.values[0], 0x2L);}
  { ClosestOp_mo_Min2Op_1__io_newMin.values[0] = T759;}
  { ClosestOp_mo_Min2Op_2__io_oldMin.values[0] = ClosestOp_mo_Min2Op_1__io_newMin.values[0];}
  val_t T760;
  { T760 = TERNARY(T454, ClosestOp_mo_Min2Op_2__io_oldMin.values[0], 0x3L);}
  { ClosestOp_mo_Min2Op_2__io_newMin.values[0] = T760;}
  { ClosestOp_mo_Min2Op_3__io_oldMin.values[0] = ClosestOp_mo_Min2Op_2__io_newMin.values[0];}
  val_t T761;
  { T761 = TERNARY(T456, ClosestOp_mo_Min2Op_3__io_oldMin.values[0], 0x4L);}
  { ClosestOp_mo_Min2Op_3__io_newMin.values[0] = T761;}
  { ClosestOp_mo_Min2Op_4__io_oldMin.values[0] = ClosestOp_mo_Min2Op_3__io_newMin.values[0];}
  val_t T762;
  { T762 = TERNARY(T458, ClosestOp_mo_Min2Op_4__io_oldMin.values[0], 0x5L);}
  { ClosestOp_mo_Min2Op_4__io_newMin.values[0] = T762;}
  { ClosestOp_mo_Min2Op_5__io_oldMin.values[0] = ClosestOp_mo_Min2Op_4__io_newMin.values[0];}
  val_t T763;
  { T763 = TERNARY(T460, ClosestOp_mo_Min2Op_5__io_oldMin.values[0], 0x6L);}
  { ClosestOp_mo_Min2Op_5__io_newMin.values[0] = T763;}
  { ClosestOp_mo_Min2Op_6__io_oldMin.values[0] = ClosestOp_mo_Min2Op_5__io_newMin.values[0];}
  val_t T764;
  { T764 = TERNARY(T462, ClosestOp_mo_Min2Op_6__io_oldMin.values[0], 0x7L);}
  { ClosestOp_mo_Min2Op_6__io_newMin.values[0] = T764;}
  { ClosestOp_mo_Min2Op_7__io_oldMin.values[0] = ClosestOp_mo_Min2Op_6__io_newMin.values[0];}
  val_t T765;
  { T765 = TERNARY(T464, ClosestOp_mo_Min2Op_7__io_oldMin.values[0], 0x8L);}
  { ClosestOp_mo_Min2Op_7__io_newMin.values[0] = T765;}
  { ClosestOp_mo_Min2Op_8__io_oldMin.values[0] = ClosestOp_mo_Min2Op_7__io_newMin.values[0];}
  val_t T766;
  { T766 = TERNARY(T466, ClosestOp_mo_Min2Op_8__io_oldMin.values[0], 0x9L);}
  { ClosestOp_mo_Min2Op_8__io_newMin.values[0] = T766;}
  { ClosestOp_mo__io_out.values[0] = ClosestOp_mo_Min2Op_8__io_newMin.values[0];}
  { ClosestOp__io_closest.values[0] = ClosestOp_mo__io_out.values[0];}
}


void ClosestOp_t::clock_hi ( dat_t<1> reset ) {
}


void ClosestOp_api_t::init_sim_data (  ) {
  sim_data.inputs.clear();
  sim_data.outputs.clear();
  sim_data.signals.clear();
  ClosestOp_t* mod = dynamic_cast<ClosestOp_t*>(module);
  assert(mod);
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_pointX));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_pointY));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_xs_9));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_xs_8));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_xs_7));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_xs_6));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_xs_5));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_xs_4));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_xs_3));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_xs_2));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_xs_1));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_xs_0));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_ys_9));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_ys_8));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_ys_7));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_ys_6));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_ys_5));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_ys_4));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_ys_3));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_ys_2));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_ys_1));
  sim_data.inputs.push_back(new dat_api<64>(&mod->ClosestOp__io_ys_0));
  sim_data.outputs.push_back(new dat_api<32>(&mod->ClosestOp__io_closest));
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_9.io_p2y"] = 0;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9_po1__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_9.po1.io_p2y"] = 1;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_9.io_p1y"] = 2;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9_po1__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_9.po1.io_p1y"] = 3;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_9_po1__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_9.po1.io_operation"] = 4;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9_po1__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_9.po1.io_pouty"] = 5;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9_po2__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_9.po2.io_p1y"] = 6;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_9.io_p2x"] = 7;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9_po1__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_9.po1.io_p2x"] = 8;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_9.io_p1x"] = 9;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9_po1__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_9.po1.io_p1x"] = 10;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9_po1__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_9.po1.io_poutx"] = 11;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9_po2__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_9.po2.io_p1x"] = 12;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_9_po2__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_9.po2.io_operation"] = 13;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9_po2__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_9.po2.io_out"] = 14;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_9.io_out"] = 15;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo__io_values_9));
  sim_data.signal_map["ClosestOp.mo.io_values_9"] = 16;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_8__io_value));
  sim_data.signal_map["ClosestOp.mo.Min2Op_8.io_value"] = 17;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_8.io_p2y"] = 18;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8_po1__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_8.po1.io_p2y"] = 19;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_8.io_p1y"] = 20;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8_po1__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_8.po1.io_p1y"] = 21;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_8_po1__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_8.po1.io_operation"] = 22;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8_po1__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_8.po1.io_pouty"] = 23;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8_po2__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_8.po2.io_p1y"] = 24;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_8.io_p2x"] = 25;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8_po1__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_8.po1.io_p2x"] = 26;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_8.io_p1x"] = 27;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8_po1__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_8.po1.io_p1x"] = 28;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8_po1__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_8.po1.io_poutx"] = 29;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8_po2__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_8.po2.io_p1x"] = 30;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_8_po2__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_8.po2.io_operation"] = 31;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8_po2__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_8.po2.io_out"] = 32;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_8.io_out"] = 33;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo__io_values_8));
  sim_data.signal_map["ClosestOp.mo.io_values_8"] = 34;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_7__io_value));
  sim_data.signal_map["ClosestOp.mo.Min2Op_7.io_value"] = 35;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_7.io_p2y"] = 36;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7_po1__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_7.po1.io_p2y"] = 37;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_7.io_p1y"] = 38;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7_po1__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_7.po1.io_p1y"] = 39;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_7_po1__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_7.po1.io_operation"] = 40;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7_po1__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_7.po1.io_pouty"] = 41;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7_po2__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_7.po2.io_p1y"] = 42;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_7.io_p2x"] = 43;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7_po1__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_7.po1.io_p2x"] = 44;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_7.io_p1x"] = 45;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7_po1__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_7.po1.io_p1x"] = 46;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7_po1__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_7.po1.io_poutx"] = 47;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7_po2__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_7.po2.io_p1x"] = 48;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_7_po2__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_7.po2.io_operation"] = 49;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7_po2__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_7.po2.io_out"] = 50;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_7.io_out"] = 51;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo__io_values_7));
  sim_data.signal_map["ClosestOp.mo.io_values_7"] = 52;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_6__io_value));
  sim_data.signal_map["ClosestOp.mo.Min2Op_6.io_value"] = 53;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_6.io_p2y"] = 54;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6_po1__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_6.po1.io_p2y"] = 55;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_6.io_p1y"] = 56;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6_po1__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_6.po1.io_p1y"] = 57;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_6_po1__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_6.po1.io_operation"] = 58;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6_po1__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_6.po1.io_pouty"] = 59;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6_po2__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_6.po2.io_p1y"] = 60;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_6.io_p2x"] = 61;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6_po1__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_6.po1.io_p2x"] = 62;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_6.io_p1x"] = 63;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6_po1__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_6.po1.io_p1x"] = 64;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6_po1__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_6.po1.io_poutx"] = 65;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6_po2__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_6.po2.io_p1x"] = 66;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_6_po2__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_6.po2.io_operation"] = 67;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6_po2__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_6.po2.io_out"] = 68;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_6.io_out"] = 69;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo__io_values_6));
  sim_data.signal_map["ClosestOp.mo.io_values_6"] = 70;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_5__io_value));
  sim_data.signal_map["ClosestOp.mo.Min2Op_5.io_value"] = 71;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_5.io_p2y"] = 72;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5_po1__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_5.po1.io_p2y"] = 73;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_5.io_p1y"] = 74;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5_po1__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_5.po1.io_p1y"] = 75;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_5_po1__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_5.po1.io_operation"] = 76;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5_po1__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_5.po1.io_pouty"] = 77;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5_po2__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_5.po2.io_p1y"] = 78;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_5.io_p2x"] = 79;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5_po1__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_5.po1.io_p2x"] = 80;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_5.io_p1x"] = 81;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5_po1__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_5.po1.io_p1x"] = 82;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5_po1__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_5.po1.io_poutx"] = 83;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5_po2__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_5.po2.io_p1x"] = 84;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_5_po2__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_5.po2.io_operation"] = 85;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5_po2__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_5.po2.io_out"] = 86;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_5.io_out"] = 87;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo__io_values_5));
  sim_data.signal_map["ClosestOp.mo.io_values_5"] = 88;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_4__io_value));
  sim_data.signal_map["ClosestOp.mo.Min2Op_4.io_value"] = 89;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_4.io_p2y"] = 90;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4_po1__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_4.po1.io_p2y"] = 91;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_4.io_p1y"] = 92;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4_po1__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_4.po1.io_p1y"] = 93;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_4_po1__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_4.po1.io_operation"] = 94;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4_po1__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_4.po1.io_pouty"] = 95;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4_po2__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_4.po2.io_p1y"] = 96;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_4.io_p2x"] = 97;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4_po1__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_4.po1.io_p2x"] = 98;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_4.io_p1x"] = 99;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4_po1__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_4.po1.io_p1x"] = 100;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4_po1__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_4.po1.io_poutx"] = 101;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4_po2__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_4.po2.io_p1x"] = 102;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_4_po2__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_4.po2.io_operation"] = 103;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4_po2__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_4.po2.io_out"] = 104;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_4.io_out"] = 105;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo__io_values_4));
  sim_data.signal_map["ClosestOp.mo.io_values_4"] = 106;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_3__io_value));
  sim_data.signal_map["ClosestOp.mo.Min2Op_3.io_value"] = 107;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_3.io_p2y"] = 108;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3_po1__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_3.po1.io_p2y"] = 109;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_3.io_p1y"] = 110;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3_po1__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_3.po1.io_p1y"] = 111;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_3_po1__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_3.po1.io_operation"] = 112;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3_po1__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_3.po1.io_pouty"] = 113;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3_po2__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_3.po2.io_p1y"] = 114;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_3.io_p2x"] = 115;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3_po1__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_3.po1.io_p2x"] = 116;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_3.io_p1x"] = 117;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3_po1__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_3.po1.io_p1x"] = 118;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3_po1__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_3.po1.io_poutx"] = 119;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3_po2__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_3.po2.io_p1x"] = 120;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_3_po2__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_3.po2.io_operation"] = 121;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3_po2__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_3.po2.io_out"] = 122;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_3.io_out"] = 123;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo__io_values_3));
  sim_data.signal_map["ClosestOp.mo.io_values_3"] = 124;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_2__io_value));
  sim_data.signal_map["ClosestOp.mo.Min2Op_2.io_value"] = 125;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_2.io_p2y"] = 126;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2_po1__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_2.po1.io_p2y"] = 127;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_2.io_p1y"] = 128;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2_po1__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_2.po1.io_p1y"] = 129;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_2_po1__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_2.po1.io_operation"] = 130;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2_po1__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_2.po1.io_pouty"] = 131;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2_po2__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_2.po2.io_p1y"] = 132;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_2.io_p2x"] = 133;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2_po1__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_2.po1.io_p2x"] = 134;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_2.io_p1x"] = 135;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2_po1__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_2.po1.io_p1x"] = 136;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2_po1__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_2.po1.io_poutx"] = 137;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2_po2__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_2.po2.io_p1x"] = 138;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_2_po2__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_2.po2.io_operation"] = 139;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2_po2__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_2.po2.io_out"] = 140;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_2.io_out"] = 141;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo__io_values_2));
  sim_data.signal_map["ClosestOp.mo.io_values_2"] = 142;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_1__io_value));
  sim_data.signal_map["ClosestOp.mo.Min2Op_1.io_value"] = 143;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_1.io_p2y"] = 144;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1_po1__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp_1.po1.io_p2y"] = 145;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_1.io_p1y"] = 146;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1_po1__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_1.po1.io_p1y"] = 147;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_1_po1__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_1.po1.io_operation"] = 148;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1_po1__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_1.po1.io_pouty"] = 149;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1_po2__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp_1.po2.io_p1y"] = 150;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_1.io_p2x"] = 151;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1_po1__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp_1.po1.io_p2x"] = 152;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_1.io_p1x"] = 153;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1_po1__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_1.po1.io_p1x"] = 154;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1_po1__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_1.po1.io_poutx"] = 155;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1_po2__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp_1.po2.io_p1x"] = 156;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_1_po2__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp_1.po2.io_operation"] = 157;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1_po2__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_1.po2.io_out"] = 158;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_1.io_out"] = 159;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo__io_values_1));
  sim_data.signal_map["ClosestOp.mo.io_values_1"] = 160;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op__io_value));
  sim_data.signal_map["ClosestOp.mo.Min2Op.io_value"] = 161;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp.io_p2y"] = 162;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_po1__io_p2y));
  sim_data.signal_map["ClosestOp.DistanceOp.po1.io_p2y"] = 163;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp.io_p1y"] = 164;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_po1__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp.po1.io_p1y"] = 165;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_po1__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp.po1.io_operation"] = 166;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_po1__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp.po1.io_pouty"] = 167;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_po2__io_p1y));
  sim_data.signal_map["ClosestOp.DistanceOp.po2.io_p1y"] = 168;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp.io_p2x"] = 169;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_po1__io_p2x));
  sim_data.signal_map["ClosestOp.DistanceOp.po1.io_p2x"] = 170;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp.io_p1x"] = 171;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_po1__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp.po1.io_p1x"] = 172;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_po1__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp.po1.io_poutx"] = 173;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_po2__io_p1x));
  sim_data.signal_map["ClosestOp.DistanceOp.po2.io_p1x"] = 174;
  sim_data.signals.push_back(new dat_api<4>(&mod->ClosestOp_DistanceOp_po2__io_operation));
  sim_data.signal_map["ClosestOp.DistanceOp.po2.io_operation"] = 175;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_po2__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp.po2.io_out"] = 176;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp.io_out"] = 177;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo__io_values_0));
  sim_data.signal_map["ClosestOp.mo.io_values_0"] = 178;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op__io_oldValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op.io_oldValue"] = 179;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op__io_newValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op.io_newValue"] = 180;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_1__io_oldValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_1.io_oldValue"] = 181;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_1__io_newValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_1.io_newValue"] = 182;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_2__io_oldValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_2.io_oldValue"] = 183;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_2__io_newValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_2.io_newValue"] = 184;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_3__io_oldValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_3.io_oldValue"] = 185;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_3__io_newValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_3.io_newValue"] = 186;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_4__io_oldValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_4.io_oldValue"] = 187;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_4__io_newValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_4.io_newValue"] = 188;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_5__io_oldValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_5.io_oldValue"] = 189;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_5__io_newValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_5.io_newValue"] = 190;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_6__io_oldValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_6.io_oldValue"] = 191;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_6__io_newValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_6.io_newValue"] = 192;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_7__io_oldValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_7.io_oldValue"] = 193;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_7__io_newValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_7.io_newValue"] = 194;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_8__io_oldValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_8.io_oldValue"] = 195;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_mo_Min2Op_8__io_newValue));
  sim_data.signal_map["ClosestOp.mo.Min2Op_8.io_newValue"] = 196;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9_po2__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_9.po2.io_poutx"] = 197;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9_po2__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_9.po2.io_pouty"] = 198;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_9_po1__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_9.po1.io_out"] = 199;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8_po2__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_8.po2.io_poutx"] = 200;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8_po2__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_8.po2.io_pouty"] = 201;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_8_po1__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_8.po1.io_out"] = 202;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7_po2__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_7.po2.io_poutx"] = 203;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7_po2__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_7.po2.io_pouty"] = 204;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_7_po1__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_7.po1.io_out"] = 205;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6_po2__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_6.po2.io_poutx"] = 206;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6_po2__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_6.po2.io_pouty"] = 207;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_6_po1__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_6.po1.io_out"] = 208;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5_po2__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_5.po2.io_poutx"] = 209;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5_po2__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_5.po2.io_pouty"] = 210;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_5_po1__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_5.po1.io_out"] = 211;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4_po2__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_4.po2.io_poutx"] = 212;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4_po2__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_4.po2.io_pouty"] = 213;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_4_po1__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_4.po1.io_out"] = 214;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3_po2__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_3.po2.io_poutx"] = 215;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3_po2__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_3.po2.io_pouty"] = 216;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_3_po1__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_3.po1.io_out"] = 217;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2_po2__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_2.po2.io_poutx"] = 218;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2_po2__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_2.po2.io_pouty"] = 219;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_2_po1__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_2.po1.io_out"] = 220;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1_po2__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp_1.po2.io_poutx"] = 221;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1_po2__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp_1.po2.io_pouty"] = 222;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_1_po1__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp_1.po1.io_out"] = 223;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_po2__io_poutx));
  sim_data.signal_map["ClosestOp.DistanceOp.po2.io_poutx"] = 224;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_po2__io_pouty));
  sim_data.signal_map["ClosestOp.DistanceOp.po2.io_pouty"] = 225;
  sim_data.signals.push_back(new dat_api<64>(&mod->ClosestOp_DistanceOp_po1__io_out));
  sim_data.signal_map["ClosestOp.DistanceOp.po1.io_out"] = 226;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op__io_oldMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op.io_oldMin"] = 227;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op__io_newMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op.io_newMin"] = 228;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_1__io_oldMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_1.io_oldMin"] = 229;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_1__io_newMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_1.io_newMin"] = 230;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_2__io_oldMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_2.io_oldMin"] = 231;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_2__io_newMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_2.io_newMin"] = 232;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_3__io_oldMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_3.io_oldMin"] = 233;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_3__io_newMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_3.io_newMin"] = 234;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_4__io_oldMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_4.io_oldMin"] = 235;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_4__io_newMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_4.io_newMin"] = 236;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_5__io_oldMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_5.io_oldMin"] = 237;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_5__io_newMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_5.io_newMin"] = 238;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_6__io_oldMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_6.io_oldMin"] = 239;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_6__io_newMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_6.io_newMin"] = 240;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_7__io_oldMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_7.io_oldMin"] = 241;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_7__io_newMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_7.io_newMin"] = 242;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_8__io_oldMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_8.io_oldMin"] = 243;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo_Min2Op_8__io_newMin));
  sim_data.signal_map["ClosestOp.mo.Min2Op_8.io_newMin"] = 244;
  sim_data.signals.push_back(new dat_api<32>(&mod->ClosestOp_mo__io_out));
  sim_data.signal_map["ClosestOp.mo.io_out"] = 245;
  sim_data.clk_map["clk"] = new clk_api(&mod->clk);
}
