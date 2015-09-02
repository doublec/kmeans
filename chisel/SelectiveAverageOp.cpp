#include "SelectiveAverageOp.h"

void SelectiveAverageOp_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
   SelectiveAverageOp_SelectivePointOps__io_den.randomize(&__rand_seed);
   SelectiveAverageOp_SelectivePointOps_1__io_den.randomize(&__rand_seed);
   SelectiveAverageOp_SelectivePointOps_2__io_den.randomize(&__rand_seed);
   SelectiveAverageOp_SelectivePointOps_3__io_p2x.randomize(&__rand_seed);
  { T160.put(1, 0, 0x3ff0000000000000L);}
  { T160.put(2, 0, 0x4000000000000000L);}
  { T160.put(3, 0, 0x4008000000000000L);}
   SelectiveAverageOp_SelectivePointOps_3__io_cent.randomize(&__rand_seed);
   SelectiveAverageOp_SelectivePointOps_3__io_p2y.randomize(&__rand_seed);
  clk.len = 1;
  clk.cnt = clk.len;
  clk.values[0] = 0;
}


int SelectiveAverageOp_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk.cnt < min) min = clk.cnt;
  clk.cnt-=min;
  if (clk.cnt == 0) clock_lo( reset );
  if (clk.cnt == 0) clock_hi( reset );
  if (clk.cnt == 0) clk.cnt = clk.len;
  return min;
}


void SelectiveAverageOp_t::print ( FILE* f ) {
}
void SelectiveAverageOp_t::print ( std::ostream& s ) {
}


void SelectiveAverageOp_t::dump_init ( FILE* f ) {
}


void SelectiveAverageOp_t::dump ( FILE* f, int t ) {
}




void SelectiveAverageOp_t::clock_lo ( dat_t<1> reset ) {
  { SelectiveAverageOp_SelectivePointOps_2__io_p2y.values[0] = SelectiveAverageOp__io_ys_2.values[0];}
  { SelectiveAverageOp_SelectivePointOps_2_po__io_p2y.values[0] = SelectiveAverageOp_SelectivePointOps_2__io_p2y.values[0];}
  { SelectiveAverageOp_SelectivePointOps_1__io_p2y.values[0] = SelectiveAverageOp__io_ys_1.values[0];}
  { SelectiveAverageOp_SelectivePointOps_1_po__io_p2y.values[0] = SelectiveAverageOp_SelectivePointOps_1__io_p2y.values[0];}
  { SelectiveAverageOp_SelectivePointOps__io_p2y.values[0] = SelectiveAverageOp__io_ys_0.values[0];}
  { SelectiveAverageOp_SelectivePointOps_po__io_p2y.values[0] = SelectiveAverageOp_SelectivePointOps__io_p2y.values[0];}
  { SelectiveAverageOp_SelectivePointOps__io_p1y.values[0] = 0x0L;}
  { SelectiveAverageOp_SelectivePointOps_po__io_p1y.values[0] = SelectiveAverageOp_SelectivePointOps__io_p1y.values[0];}
  val_t T0;
  T0 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_po__io_p1y.values[0]) + toDouble(SelectiveAverageOp_SelectivePointOps_po__io_p2y.values[0]));
  { SelectiveAverageOp_SelectivePointOps__io_operation.values[0] = 0x1L;}
  { SelectiveAverageOp_SelectivePointOps_po__io_operation.values[0] = SelectiveAverageOp_SelectivePointOps__io_operation.values[0];}
  val_t T1;
  T1 = SelectiveAverageOp_SelectivePointOps_po__io_operation.values[0] == 0x1L;
  val_t T2;
  T2 = SelectiveAverageOp_SelectivePointOps_po__io_operation.values[0] == 0x0L;
  val_t T3;
  { T3 = T2 ^ 0x1L;}
  val_t T4;
  { T4 = T3 & T1;}
  val_t T5;
  { T5 = TERNARY(T4, T0, 0x0L);}
  val_t T6;
  T6 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_po__io_p1y.values[0]) - toDouble(SelectiveAverageOp_SelectivePointOps_po__io_p2y.values[0]));
  val_t T7;
  T7 = SelectiveAverageOp_SelectivePointOps_po__io_operation.values[0] == 0x2L;
  val_t T8;
  { T8 = T2 | T1;}
  val_t T9;
  { T9 = T8 ^ 0x1L;}
  val_t T10;
  { T10 = T9 & T7;}
  val_t T11;
  { T11 = TERNARY_1(T10, T6, T5);}
  { val_t __r = this->__rand_val(); SelectiveAverageOp_SelectivePointOps__io_den.values[0] = __r;}
  { SelectiveAverageOp_SelectivePointOps_po__io_den.values[0] = SelectiveAverageOp_SelectivePointOps__io_den.values[0];}
  val_t T12;
  T12 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_po__io_p1y.values[0]) / toDouble(SelectiveAverageOp_SelectivePointOps_po__io_den.values[0]));
  val_t T13;
  T13 = SelectiveAverageOp_SelectivePointOps_po__io_operation.values[0] == 0x3L;
  val_t T14;
  { T14 = T8 | T7;}
  val_t T15;
  { T15 = T14 ^ 0x1L;}
  val_t T16;
  { T16 = T15 & T13;}
  val_t T17;
  { T17 = TERNARY_1(T16, T12, T11);}
  val_t T18;
  T18 = SelectiveAverageOp_SelectivePointOps_po__io_operation.values[0] == 0x4L;
  val_t T19;
  { T19 = T14 | T13;}
  val_t T20;
  { T20 = T19 | T18;}
  val_t T21;
  { T21 = T20 ^ 0x1L;}
  val_t T22;
  { T22 = TERNARY(T21, 0x0L, T17);}
  { SelectiveAverageOp_SelectivePointOps_po__io_pouty.values[0] = T22;}
  val_t T23;
  T23 = SelectiveAverageOp_SelectivePointOps__io_operation.values[0] == 0x1L;
  { SelectiveAverageOp_SelectivePointOps__io_cent.values[0] = SelectiveAverageOp__io_cent_0.values[0];}
  val_t T24;
  T24 = SelectiveAverageOp_SelectivePointOps__io_cent.values[0] != 0x1L;
  val_t T25;
  { T25 = T24 & T23;}
  val_t T26;
  { T26 = TERNARY(T25, SelectiveAverageOp_SelectivePointOps__io_p1y.values[0], SelectiveAverageOp_SelectivePointOps_po__io_pouty.values[0]);}
  { SelectiveAverageOp_SelectivePointOps__io_pouty.values[0] = T26;}
  { SelectiveAverageOp_SelectivePointOps_1__io_p1y.values[0] = SelectiveAverageOp_SelectivePointOps__io_pouty.values[0];}
  { SelectiveAverageOp_SelectivePointOps_1_po__io_p1y.values[0] = SelectiveAverageOp_SelectivePointOps_1__io_p1y.values[0];}
  val_t T27;
  T27 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_p1y.values[0]) + toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_p2y.values[0]));
  { SelectiveAverageOp_SelectivePointOps_1__io_operation.values[0] = 0x1L;}
  { SelectiveAverageOp_SelectivePointOps_1_po__io_operation.values[0] = SelectiveAverageOp_SelectivePointOps_1__io_operation.values[0];}
  val_t T28;
  T28 = SelectiveAverageOp_SelectivePointOps_1_po__io_operation.values[0] == 0x1L;
  val_t T29;
  T29 = SelectiveAverageOp_SelectivePointOps_1_po__io_operation.values[0] == 0x0L;
  val_t T30;
  { T30 = T29 ^ 0x1L;}
  val_t T31;
  { T31 = T30 & T28;}
  val_t T32;
  { T32 = TERNARY(T31, T27, 0x0L);}
  val_t T33;
  T33 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_p1y.values[0]) - toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_p2y.values[0]));
  val_t T34;
  T34 = SelectiveAverageOp_SelectivePointOps_1_po__io_operation.values[0] == 0x2L;
  val_t T35;
  { T35 = T29 | T28;}
  val_t T36;
  { T36 = T35 ^ 0x1L;}
  val_t T37;
  { T37 = T36 & T34;}
  val_t T38;
  { T38 = TERNARY_1(T37, T33, T32);}
  { val_t __r = this->__rand_val(); SelectiveAverageOp_SelectivePointOps_1__io_den.values[0] = __r;}
  { SelectiveAverageOp_SelectivePointOps_1_po__io_den.values[0] = SelectiveAverageOp_SelectivePointOps_1__io_den.values[0];}
  val_t T39;
  T39 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_p1y.values[0]) / toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_den.values[0]));
  val_t T40;
  T40 = SelectiveAverageOp_SelectivePointOps_1_po__io_operation.values[0] == 0x3L;
  val_t T41;
  { T41 = T35 | T34;}
  val_t T42;
  { T42 = T41 ^ 0x1L;}
  val_t T43;
  { T43 = T42 & T40;}
  val_t T44;
  { T44 = TERNARY_1(T43, T39, T38);}
  val_t T45;
  T45 = SelectiveAverageOp_SelectivePointOps_1_po__io_operation.values[0] == 0x4L;
  val_t T46;
  { T46 = T41 | T40;}
  val_t T47;
  { T47 = T46 | T45;}
  val_t T48;
  { T48 = T47 ^ 0x1L;}
  val_t T49;
  { T49 = TERNARY(T48, 0x0L, T44);}
  { SelectiveAverageOp_SelectivePointOps_1_po__io_pouty.values[0] = T49;}
  val_t T50;
  T50 = SelectiveAverageOp_SelectivePointOps_1__io_operation.values[0] == 0x1L;
  { SelectiveAverageOp_SelectivePointOps_1__io_cent.values[0] = SelectiveAverageOp__io_cent_1.values[0];}
  val_t T51;
  T51 = SelectiveAverageOp_SelectivePointOps_1__io_cent.values[0] != 0x1L;
  val_t T52;
  { T52 = T51 & T50;}
  val_t T53;
  { T53 = TERNARY_1(T52, SelectiveAverageOp_SelectivePointOps_1__io_p1y.values[0], SelectiveAverageOp_SelectivePointOps_1_po__io_pouty.values[0]);}
  { SelectiveAverageOp_SelectivePointOps_1__io_pouty.values[0] = T53;}
  { SelectiveAverageOp_SelectivePointOps_2__io_p1y.values[0] = SelectiveAverageOp_SelectivePointOps_1__io_pouty.values[0];}
  { SelectiveAverageOp_SelectivePointOps_2_po__io_p1y.values[0] = SelectiveAverageOp_SelectivePointOps_2__io_p1y.values[0];}
  val_t T54;
  T54 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_p1y.values[0]) + toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_p2y.values[0]));
  { SelectiveAverageOp_SelectivePointOps_2__io_operation.values[0] = 0x1L;}
  { SelectiveAverageOp_SelectivePointOps_2_po__io_operation.values[0] = SelectiveAverageOp_SelectivePointOps_2__io_operation.values[0];}
  val_t T55;
  T55 = SelectiveAverageOp_SelectivePointOps_2_po__io_operation.values[0] == 0x1L;
  val_t T56;
  T56 = SelectiveAverageOp_SelectivePointOps_2_po__io_operation.values[0] == 0x0L;
  val_t T57;
  { T57 = T56 ^ 0x1L;}
  val_t T58;
  { T58 = T57 & T55;}
  val_t T59;
  { T59 = TERNARY(T58, T54, 0x0L);}
  val_t T60;
  T60 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_p1y.values[0]) - toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_p2y.values[0]));
  val_t T61;
  T61 = SelectiveAverageOp_SelectivePointOps_2_po__io_operation.values[0] == 0x2L;
  val_t T62;
  { T62 = T56 | T55;}
  val_t T63;
  { T63 = T62 ^ 0x1L;}
  val_t T64;
  { T64 = T63 & T61;}
  val_t T65;
  { T65 = TERNARY_1(T64, T60, T59);}
  { val_t __r = this->__rand_val(); SelectiveAverageOp_SelectivePointOps_2__io_den.values[0] = __r;}
  { SelectiveAverageOp_SelectivePointOps_2_po__io_den.values[0] = SelectiveAverageOp_SelectivePointOps_2__io_den.values[0];}
  val_t T66;
  T66 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_p1y.values[0]) / toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_den.values[0]));
  val_t T67;
  T67 = SelectiveAverageOp_SelectivePointOps_2_po__io_operation.values[0] == 0x3L;
  val_t T68;
  { T68 = T62 | T61;}
  val_t T69;
  { T69 = T68 ^ 0x1L;}
  val_t T70;
  { T70 = T69 & T67;}
  val_t T71;
  { T71 = TERNARY_1(T70, T66, T65);}
  val_t T72;
  T72 = SelectiveAverageOp_SelectivePointOps_2_po__io_operation.values[0] == 0x4L;
  val_t T73;
  { T73 = T68 | T67;}
  val_t T74;
  { T74 = T73 | T72;}
  val_t T75;
  { T75 = T74 ^ 0x1L;}
  val_t T76;
  { T76 = TERNARY(T75, 0x0L, T71);}
  { SelectiveAverageOp_SelectivePointOps_2_po__io_pouty.values[0] = T76;}
  val_t T77;
  T77 = SelectiveAverageOp_SelectivePointOps_2__io_operation.values[0] == 0x1L;
  { SelectiveAverageOp_SelectivePointOps_2__io_cent.values[0] = SelectiveAverageOp__io_cent_2.values[0];}
  val_t T78;
  T78 = SelectiveAverageOp_SelectivePointOps_2__io_cent.values[0] != 0x1L;
  val_t T79;
  { T79 = T78 & T77;}
  val_t T80;
  { T80 = TERNARY_1(T79, SelectiveAverageOp_SelectivePointOps_2__io_p1y.values[0], SelectiveAverageOp_SelectivePointOps_2_po__io_pouty.values[0]);}
  { SelectiveAverageOp_SelectivePointOps_2__io_pouty.values[0] = T80;}
  { SelectiveAverageOp_SelectivePointOps_3__io_p1y.values[0] = SelectiveAverageOp_SelectivePointOps_2__io_pouty.values[0];}
  { SelectiveAverageOp_SelectivePointOps_3_po__io_p1y.values[0] = SelectiveAverageOp_SelectivePointOps_3__io_p1y.values[0];}
  val_t T81;
  T81 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_p1y.values[0]) * toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_p1y.values[0]));
  { SelectiveAverageOp_SelectivePointOps_2__io_p2x.values[0] = SelectiveAverageOp__io_xs_2.values[0];}
  { SelectiveAverageOp_SelectivePointOps_2_po__io_p2x.values[0] = SelectiveAverageOp_SelectivePointOps_2__io_p2x.values[0];}
  { SelectiveAverageOp_SelectivePointOps_1__io_p2x.values[0] = SelectiveAverageOp__io_xs_1.values[0];}
  { SelectiveAverageOp_SelectivePointOps_1_po__io_p2x.values[0] = SelectiveAverageOp_SelectivePointOps_1__io_p2x.values[0];}
  { SelectiveAverageOp_SelectivePointOps__io_p2x.values[0] = SelectiveAverageOp__io_xs_0.values[0];}
  { SelectiveAverageOp_SelectivePointOps_po__io_p2x.values[0] = SelectiveAverageOp_SelectivePointOps__io_p2x.values[0];}
  { SelectiveAverageOp_SelectivePointOps__io_p1x.values[0] = 0x0L;}
  { SelectiveAverageOp_SelectivePointOps_po__io_p1x.values[0] = SelectiveAverageOp_SelectivePointOps__io_p1x.values[0];}
  val_t T82;
  T82 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_po__io_p1x.values[0]) + toDouble(SelectiveAverageOp_SelectivePointOps_po__io_p2x.values[0]));
  val_t T83;
  { T83 = TERNARY(T4, T82, 0x0L);}
  val_t T84;
  T84 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_po__io_p1x.values[0]) - toDouble(SelectiveAverageOp_SelectivePointOps_po__io_p2x.values[0]));
  val_t T85;
  { T85 = TERNARY_1(T10, T84, T83);}
  val_t T86;
  T86 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_po__io_p1x.values[0]) / toDouble(SelectiveAverageOp_SelectivePointOps_po__io_den.values[0]));
  val_t T87;
  { T87 = TERNARY_1(T16, T86, T85);}
  val_t T88;
  { T88 = TERNARY(T21, 0x0L, T87);}
  { SelectiveAverageOp_SelectivePointOps_po__io_poutx.values[0] = T88;}
  val_t T89;
  { T89 = TERNARY(T25, SelectiveAverageOp_SelectivePointOps__io_p1x.values[0], SelectiveAverageOp_SelectivePointOps_po__io_poutx.values[0]);}
  { SelectiveAverageOp_SelectivePointOps__io_poutx.values[0] = T89;}
  { SelectiveAverageOp_SelectivePointOps_1__io_p1x.values[0] = SelectiveAverageOp_SelectivePointOps__io_poutx.values[0];}
  { SelectiveAverageOp_SelectivePointOps_1_po__io_p1x.values[0] = SelectiveAverageOp_SelectivePointOps_1__io_p1x.values[0];}
  val_t T90;
  T90 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_p1x.values[0]) + toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_p2x.values[0]));
  val_t T91;
  { T91 = TERNARY(T31, T90, 0x0L);}
  val_t T92;
  T92 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_p1x.values[0]) - toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_p2x.values[0]));
  val_t T93;
  { T93 = TERNARY_1(T37, T92, T91);}
  val_t T94;
  T94 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_p1x.values[0]) / toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_den.values[0]));
  val_t T95;
  { T95 = TERNARY_1(T43, T94, T93);}
  val_t T96;
  { T96 = TERNARY(T48, 0x0L, T95);}
  { SelectiveAverageOp_SelectivePointOps_1_po__io_poutx.values[0] = T96;}
  val_t T97;
  { T97 = TERNARY_1(T52, SelectiveAverageOp_SelectivePointOps_1__io_p1x.values[0], SelectiveAverageOp_SelectivePointOps_1_po__io_poutx.values[0]);}
  { SelectiveAverageOp_SelectivePointOps_1__io_poutx.values[0] = T97;}
  { SelectiveAverageOp_SelectivePointOps_2__io_p1x.values[0] = SelectiveAverageOp_SelectivePointOps_1__io_poutx.values[0];}
  { SelectiveAverageOp_SelectivePointOps_2_po__io_p1x.values[0] = SelectiveAverageOp_SelectivePointOps_2__io_p1x.values[0];}
  val_t T98;
  T98 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_p1x.values[0]) + toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_p2x.values[0]));
  val_t T99;
  { T99 = TERNARY(T58, T98, 0x0L);}
  val_t T100;
  T100 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_p1x.values[0]) - toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_p2x.values[0]));
  val_t T101;
  { T101 = TERNARY_1(T64, T100, T99);}
  val_t T102;
  T102 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_p1x.values[0]) / toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_den.values[0]));
  val_t T103;
  { T103 = TERNARY_1(T70, T102, T101);}
  val_t T104;
  { T104 = TERNARY(T75, 0x0L, T103);}
  { SelectiveAverageOp_SelectivePointOps_2_po__io_poutx.values[0] = T104;}
  val_t T105;
  { T105 = TERNARY_1(T79, SelectiveAverageOp_SelectivePointOps_2__io_p1x.values[0], SelectiveAverageOp_SelectivePointOps_2_po__io_poutx.values[0]);}
  { SelectiveAverageOp_SelectivePointOps_2__io_poutx.values[0] = T105;}
  { SelectiveAverageOp_SelectivePointOps_3__io_p1x.values[0] = SelectiveAverageOp_SelectivePointOps_2__io_poutx.values[0];}
  { SelectiveAverageOp_SelectivePointOps_3_po__io_p1x.values[0] = SelectiveAverageOp_SelectivePointOps_3__io_p1x.values[0];}
  val_t T106;
  T106 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_p1x.values[0]) * toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_p1x.values[0]));
  val_t T107;
  T107 = fromDouble(toDouble(T106) + toDouble(T81));
  val_t T108;
  T108 = fromDouble(sqrt(toDouble(T107)));
  { SelectiveAverageOp_SelectivePointOps_3__io_operation.values[0] = 0x3L;}
  { SelectiveAverageOp_SelectivePointOps_3_po__io_operation.values[0] = SelectiveAverageOp_SelectivePointOps_3__io_operation.values[0];}
  val_t T109;
  T109 = SelectiveAverageOp_SelectivePointOps_3_po__io_operation.values[0] == 0x4L;
  val_t T110;
  T110 = SelectiveAverageOp_SelectivePointOps_3_po__io_operation.values[0] == 0x3L;
  val_t T111;
  T111 = SelectiveAverageOp_SelectivePointOps_3_po__io_operation.values[0] == 0x2L;
  val_t T112;
  T112 = SelectiveAverageOp_SelectivePointOps_3_po__io_operation.values[0] == 0x1L;
  val_t T113;
  T113 = SelectiveAverageOp_SelectivePointOps_3_po__io_operation.values[0] == 0x0L;
  val_t T114;
  { T114 = T113 | T112;}
  val_t T115;
  { T115 = T114 | T111;}
  val_t T116;
  { T116 = T115 | T110;}
  val_t T117;
  { T117 = T116 ^ 0x1L;}
  val_t T118;
  { T118 = T117 & T109;}
  val_t T119;
  { T119 = TERNARY(T118, T108, 0x0L);}
  { SelectiveAverageOp_SelectivePointOps_3_po__io_out.values[0] = T119;}
  { SelectiveAverageOp_SelectivePointOps_3__io_out.values[0] = SelectiveAverageOp_SelectivePointOps_3_po__io_out.values[0];}
  val_t T120;
  T120 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_p1y.values[0]) * toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_p1y.values[0]));
  val_t T121;
  T121 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_p1x.values[0]) * toDouble(SelectiveAverageOp_SelectivePointOps_2_po__io_p1x.values[0]));
  val_t T122;
  T122 = fromDouble(toDouble(T121) + toDouble(T120));
  val_t T123;
  T123 = fromDouble(sqrt(toDouble(T122)));
  val_t T124;
  { T124 = T73 ^ 0x1L;}
  val_t T125;
  { T125 = T124 & T72;}
  val_t T126;
  { T126 = TERNARY(T125, T123, 0x0L);}
  { SelectiveAverageOp_SelectivePointOps_2_po__io_out.values[0] = T126;}
  { SelectiveAverageOp_SelectivePointOps_2__io_out.values[0] = SelectiveAverageOp_SelectivePointOps_2_po__io_out.values[0];}
  val_t T127;
  T127 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_p1y.values[0]) * toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_p1y.values[0]));
  val_t T128;
  T128 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_p1x.values[0]) * toDouble(SelectiveAverageOp_SelectivePointOps_1_po__io_p1x.values[0]));
  val_t T129;
  T129 = fromDouble(toDouble(T128) + toDouble(T127));
  val_t T130;
  T130 = fromDouble(sqrt(toDouble(T129)));
  val_t T131;
  { T131 = T46 ^ 0x1L;}
  val_t T132;
  { T132 = T131 & T45;}
  val_t T133;
  { T133 = TERNARY(T132, T130, 0x0L);}
  { SelectiveAverageOp_SelectivePointOps_1_po__io_out.values[0] = T133;}
  { SelectiveAverageOp_SelectivePointOps_1__io_out.values[0] = SelectiveAverageOp_SelectivePointOps_1_po__io_out.values[0];}
  val_t T134;
  T134 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_po__io_p1y.values[0]) * toDouble(SelectiveAverageOp_SelectivePointOps_po__io_p1y.values[0]));
  val_t T135;
  T135 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_po__io_p1x.values[0]) * toDouble(SelectiveAverageOp_SelectivePointOps_po__io_p1x.values[0]));
  val_t T136;
  T136 = fromDouble(toDouble(T135) + toDouble(T134));
  val_t T137;
  T137 = fromDouble(sqrt(toDouble(T136)));
  val_t T138;
  { T138 = T19 ^ 0x1L;}
  val_t T139;
  { T139 = T138 & T18;}
  val_t T140;
  { T140 = TERNARY(T139, T137, 0x0L);}
  { SelectiveAverageOp_SelectivePointOps_po__io_out.values[0] = T140;}
  { SelectiveAverageOp_SelectivePointOps__io_out.values[0] = SelectiveAverageOp_SelectivePointOps_po__io_out.values[0];}
  { val_t __r = this->__rand_val(); SelectiveAverageOp_SelectivePointOps_3__io_p2x.values[0] = __r;}
  { SelectiveAverageOp_SelectivePointOps_3_po__io_p2x.values[0] = SelectiveAverageOp_SelectivePointOps_3__io_p2x.values[0];}
  val_t T141;
  T141 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_p1x.values[0]) + toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_p2x.values[0]));
  val_t T142;
  { T142 = T113 ^ 0x1L;}
  val_t T143;
  { T143 = T142 & T112;}
  val_t T144;
  { T144 = TERNARY(T143, T141, 0x0L);}
  val_t T145;
  T145 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_p1x.values[0]) - toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_p2x.values[0]));
  val_t T146;
  { T146 = T114 ^ 0x1L;}
  val_t T147;
  { T147 = T146 & T111;}
  val_t T148;
  { T148 = TERNARY_1(T147, T145, T144);}
  val_t T149;
  T149 = SelectiveAverageOp__io_cent_2.values[0] == 0x1L;
  val_t T150;
  { T150 = T149 | 0x0L << 1;}
  val_t T151;
  T151 = SelectiveAverageOp__io_cent_1.values[0] == 0x1L;
  val_t T152;
  { T152 = T151 | 0x0L << 1;}
  val_t T153;
  { T153 = T152+T150;}
  T153 = T153 & 0x3L;
  val_t T154;
  { T154 = T153 | 0x0L << 2;}
  val_t T155;
  T155 = SelectiveAverageOp__io_cent_0.values[0] == 0x1L;
  val_t T156;
  { T156 = T155 | 0x0L << 1;}
  val_t SelectiveAverageOp__count;
  { SelectiveAverageOp__count = T156+T154;}
  SelectiveAverageOp__count = SelectiveAverageOp__count & 0x7L;
  val_t T157;
  { T157 = SelectiveAverageOp__count | 0x0L << 3;}
  { SelectiveAverageOp_conv__io_in.values[0] = T157;}
  val_t T158;
  { T158 = SelectiveAverageOp_conv__io_in.values[0];}
  T158 = T158 & 0x3L;
  val_t T159;
  { T159 = T160.get(T158, 0);}
  { SelectiveAverageOp_conv__io_out.values[0] = T159;}
  { SelectiveAverageOp_SelectivePointOps_3__io_den.values[0] = SelectiveAverageOp_conv__io_out.values[0];}
  { SelectiveAverageOp_SelectivePointOps_3_po__io_den.values[0] = SelectiveAverageOp_SelectivePointOps_3__io_den.values[0];}
  val_t T161;
  T161 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_p1x.values[0]) / toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_den.values[0]));
  val_t T162;
  { T162 = T115 ^ 0x1L;}
  val_t T163;
  { T163 = T162 & T110;}
  val_t T164;
  { T164 = TERNARY_1(T163, T161, T148);}
  val_t T165;
  { T165 = T116 | T109;}
  val_t T166;
  { T166 = T165 ^ 0x1L;}
  val_t T167;
  { T167 = TERNARY(T166, 0x0L, T164);}
  { SelectiveAverageOp_SelectivePointOps_3_po__io_poutx.values[0] = T167;}
  val_t T168;
  T168 = SelectiveAverageOp_SelectivePointOps_3__io_operation.values[0] == 0x1L;
  { val_t __r = this->__rand_val(); SelectiveAverageOp_SelectivePointOps_3__io_cent.values[0] = __r;}
  SelectiveAverageOp_SelectivePointOps_3__io_cent.values[0] = SelectiveAverageOp_SelectivePointOps_3__io_cent.values[0] & 0xffffffffL;
  val_t T169;
  T169 = SelectiveAverageOp_SelectivePointOps_3__io_cent.values[0] != 0x1L;
  val_t T170;
  { T170 = T169 & T168;}
  val_t T171;
  { T171 = TERNARY_1(T170, SelectiveAverageOp_SelectivePointOps_3__io_p1x.values[0], SelectiveAverageOp_SelectivePointOps_3_po__io_poutx.values[0]);}
  { SelectiveAverageOp_SelectivePointOps_3__io_poutx.values[0] = T171;}
  val_t T172;
  T172 = SelectiveAverageOp__count<=0x0L;
  val_t T173;
  { T173 = TERNARY(T172, 0x0L, SelectiveAverageOp_SelectivePointOps_3__io_poutx.values[0]);}
  { SelectiveAverageOp__io_outX.values[0] = T173;}
  { val_t __r = this->__rand_val(); SelectiveAverageOp_SelectivePointOps_3__io_p2y.values[0] = __r;}
  { SelectiveAverageOp_SelectivePointOps_3_po__io_p2y.values[0] = SelectiveAverageOp_SelectivePointOps_3__io_p2y.values[0];}
  val_t T174;
  T174 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_p1y.values[0]) + toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_p2y.values[0]));
  val_t T175;
  { T175 = TERNARY(T143, T174, 0x0L);}
  val_t T176;
  T176 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_p1y.values[0]) - toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_p2y.values[0]));
  val_t T177;
  { T177 = TERNARY_1(T147, T176, T175);}
  val_t T178;
  T178 = fromDouble(toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_p1y.values[0]) / toDouble(SelectiveAverageOp_SelectivePointOps_3_po__io_den.values[0]));
  val_t T179;
  { T179 = TERNARY_1(T163, T178, T177);}
  val_t T180;
  { T180 = TERNARY(T166, 0x0L, T179);}
  { SelectiveAverageOp_SelectivePointOps_3_po__io_pouty.values[0] = T180;}
  val_t T181;
  { T181 = TERNARY_1(T170, SelectiveAverageOp_SelectivePointOps_3__io_p1y.values[0], SelectiveAverageOp_SelectivePointOps_3_po__io_pouty.values[0]);}
  { SelectiveAverageOp_SelectivePointOps_3__io_pouty.values[0] = T181;}
  val_t T182;
  { T182 = TERNARY(T172, 0x0L, SelectiveAverageOp_SelectivePointOps_3__io_pouty.values[0]);}
  { SelectiveAverageOp__io_outY.values[0] = T182;}
}


void SelectiveAverageOp_t::clock_hi ( dat_t<1> reset ) {
}


void SelectiveAverageOp_api_t::init_sim_data (  ) {
  sim_data.inputs.clear();
  sim_data.outputs.clear();
  sim_data.signals.clear();
  SelectiveAverageOp_t* mod = dynamic_cast<SelectiveAverageOp_t*>(module);
  assert(mod);
  sim_data.inputs.push_back(new dat_api<64>(&mod->SelectiveAverageOp__io_xs_2));
  sim_data.inputs.push_back(new dat_api<64>(&mod->SelectiveAverageOp__io_xs_1));
  sim_data.inputs.push_back(new dat_api<64>(&mod->SelectiveAverageOp__io_xs_0));
  sim_data.inputs.push_back(new dat_api<64>(&mod->SelectiveAverageOp__io_ys_2));
  sim_data.inputs.push_back(new dat_api<64>(&mod->SelectiveAverageOp__io_ys_1));
  sim_data.inputs.push_back(new dat_api<64>(&mod->SelectiveAverageOp__io_ys_0));
  sim_data.inputs.push_back(new dat_api<32>(&mod->SelectiveAverageOp__io_cent_2));
  sim_data.inputs.push_back(new dat_api<32>(&mod->SelectiveAverageOp__io_cent_1));
  sim_data.inputs.push_back(new dat_api<32>(&mod->SelectiveAverageOp__io_cent_0));
  sim_data.outputs.push_back(new dat_api<64>(&mod->SelectiveAverageOp__io_outX));
  sim_data.outputs.push_back(new dat_api<64>(&mod->SelectiveAverageOp__io_outY));
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_2__io_p2y));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.io_p2y"] = 0;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_2_po__io_p2y));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.po.io_p2y"] = 1;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_1__io_p2y));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.io_p2y"] = 2;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_1_po__io_p2y));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.po.io_p2y"] = 3;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps__io_p2y));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.io_p2y"] = 4;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_po__io_p2y));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.po.io_p2y"] = 5;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps__io_p1y));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.io_p1y"] = 6;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_po__io_p1y));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.po.io_p1y"] = 7;
  sim_data.signals.push_back(new dat_api<4>(&mod->SelectiveAverageOp_SelectivePointOps__io_operation));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.io_operation"] = 8;
  sim_data.signals.push_back(new dat_api<4>(&mod->SelectiveAverageOp_SelectivePointOps_po__io_operation));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.po.io_operation"] = 9;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_po__io_den));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.po.io_den"] = 10;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_po__io_pouty));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.po.io_pouty"] = 11;
  sim_data.signals.push_back(new dat_api<32>(&mod->SelectiveAverageOp_SelectivePointOps__io_cent));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.io_cent"] = 12;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps__io_pouty));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.io_pouty"] = 13;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_1__io_p1y));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.io_p1y"] = 14;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_1_po__io_p1y));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.po.io_p1y"] = 15;
  sim_data.signals.push_back(new dat_api<4>(&mod->SelectiveAverageOp_SelectivePointOps_1__io_operation));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.io_operation"] = 16;
  sim_data.signals.push_back(new dat_api<4>(&mod->SelectiveAverageOp_SelectivePointOps_1_po__io_operation));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.po.io_operation"] = 17;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_1_po__io_den));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.po.io_den"] = 18;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_1_po__io_pouty));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.po.io_pouty"] = 19;
  sim_data.signals.push_back(new dat_api<32>(&mod->SelectiveAverageOp_SelectivePointOps_1__io_cent));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.io_cent"] = 20;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_1__io_pouty));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.io_pouty"] = 21;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_2__io_p1y));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.io_p1y"] = 22;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_2_po__io_p1y));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.po.io_p1y"] = 23;
  sim_data.signals.push_back(new dat_api<4>(&mod->SelectiveAverageOp_SelectivePointOps_2__io_operation));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.io_operation"] = 24;
  sim_data.signals.push_back(new dat_api<4>(&mod->SelectiveAverageOp_SelectivePointOps_2_po__io_operation));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.po.io_operation"] = 25;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_2_po__io_den));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.po.io_den"] = 26;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_2_po__io_pouty));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.po.io_pouty"] = 27;
  sim_data.signals.push_back(new dat_api<32>(&mod->SelectiveAverageOp_SelectivePointOps_2__io_cent));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.io_cent"] = 28;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_2__io_pouty));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.io_pouty"] = 29;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_3__io_p1y));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.io_p1y"] = 30;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_3_po__io_p1y));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.po.io_p1y"] = 31;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_2__io_p2x));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.io_p2x"] = 32;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_2_po__io_p2x));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.po.io_p2x"] = 33;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_1__io_p2x));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.io_p2x"] = 34;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_1_po__io_p2x));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.po.io_p2x"] = 35;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps__io_p2x));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.io_p2x"] = 36;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_po__io_p2x));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.po.io_p2x"] = 37;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps__io_p1x));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.io_p1x"] = 38;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_po__io_p1x));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.po.io_p1x"] = 39;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_po__io_poutx));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.po.io_poutx"] = 40;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps__io_poutx));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.io_poutx"] = 41;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_1__io_p1x));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.io_p1x"] = 42;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_1_po__io_p1x));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.po.io_p1x"] = 43;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_1_po__io_poutx));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.po.io_poutx"] = 44;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_1__io_poutx));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.io_poutx"] = 45;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_2__io_p1x));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.io_p1x"] = 46;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_2_po__io_p1x));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.po.io_p1x"] = 47;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_2_po__io_poutx));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.po.io_poutx"] = 48;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_2__io_poutx));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.io_poutx"] = 49;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_3__io_p1x));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.io_p1x"] = 50;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_3_po__io_p1x));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.po.io_p1x"] = 51;
  sim_data.signals.push_back(new dat_api<4>(&mod->SelectiveAverageOp_SelectivePointOps_3__io_operation));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.io_operation"] = 52;
  sim_data.signals.push_back(new dat_api<4>(&mod->SelectiveAverageOp_SelectivePointOps_3_po__io_operation));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.po.io_operation"] = 53;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_3_po__io_out));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.po.io_out"] = 54;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_3__io_out));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.io_out"] = 55;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_2_po__io_out));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.po.io_out"] = 56;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_2__io_out));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_2.io_out"] = 57;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_1_po__io_out));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.po.io_out"] = 58;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_1__io_out));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_1.io_out"] = 59;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_po__io_out));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.po.io_out"] = 60;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps__io_out));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps.io_out"] = 61;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_3_po__io_p2x));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.po.io_p2x"] = 62;
  sim_data.signals.push_back(new dat_api<32>(&mod->SelectiveAverageOp_conv__io_in));
  sim_data.signal_map["SelectiveAverageOp.conv.io_in"] = 63;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_conv__io_out));
  sim_data.signal_map["SelectiveAverageOp.conv.io_out"] = 64;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_3__io_den));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.io_den"] = 65;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_3_po__io_den));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.po.io_den"] = 66;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_3_po__io_poutx));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.po.io_poutx"] = 67;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_3__io_poutx));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.io_poutx"] = 68;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_3_po__io_p2y));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.po.io_p2y"] = 69;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_3_po__io_pouty));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.po.io_pouty"] = 70;
  sim_data.signals.push_back(new dat_api<64>(&mod->SelectiveAverageOp_SelectivePointOps_3__io_pouty));
  sim_data.signal_map["SelectiveAverageOp.SelectivePointOps_3.io_pouty"] = 71;
  sim_data.clk_map["clk"] = new clk_api(&mod->clk);
}
