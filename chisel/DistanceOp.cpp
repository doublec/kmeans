#include "DistanceOp.h"

void DistanceOp_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
   DistanceOp_po2__io_p2x.randomize(&__rand_seed);
   DistanceOp_po1__io_den.randomize(&__rand_seed);
   DistanceOp_po2__io_den.randomize(&__rand_seed);
   DistanceOp_po2__io_p2y.randomize(&__rand_seed);
  clk.len = 1;
  clk.cnt = clk.len;
  clk.values[0] = 0;
}


int DistanceOp_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk.cnt < min) min = clk.cnt;
  clk.cnt-=min;
  if (clk.cnt == 0) clock_lo( reset );
  if (clk.cnt == 0) clock_hi( reset );
  if (clk.cnt == 0) clk.cnt = clk.len;
  return min;
}


void DistanceOp_t::print ( FILE* f ) {
}
void DistanceOp_t::print ( std::ostream& s ) {
}


void DistanceOp_t::dump_init ( FILE* f ) {
}


void DistanceOp_t::dump ( FILE* f, int t ) {
}




void DistanceOp_t::clock_lo ( dat_t<1> reset ) {
  { val_t __r = this->__rand_val(); DistanceOp_po2__io_p2x.values[0] = __r;}
  { DistanceOp_po1__io_p2x.values[0] = DistanceOp__io_p2x.values[0];}
  { DistanceOp_po1__io_p1x.values[0] = DistanceOp__io_p1x.values[0];}
  val_t T0;
  T0 = fromDouble(toDouble(DistanceOp_po1__io_p1x.values[0]) + toDouble(DistanceOp_po1__io_p2x.values[0]));
  { DistanceOp_po1__io_operation.values[0] = 0x2L;}
  val_t T1;
  T1 = DistanceOp_po1__io_operation.values[0] == 0x1L;
  val_t T2;
  T2 = DistanceOp_po1__io_operation.values[0] == 0x0L;
  val_t T3;
  { T3 = T2 ^ 0x1L;}
  val_t T4;
  { T4 = T3 & T1;}
  val_t T5;
  { T5 = TERNARY(T4, T0, 0x0L);}
  val_t T6;
  T6 = fromDouble(toDouble(DistanceOp_po1__io_p1x.values[0]) - toDouble(DistanceOp_po1__io_p2x.values[0]));
  val_t T7;
  T7 = DistanceOp_po1__io_operation.values[0] == 0x2L;
  val_t T8;
  { T8 = T2 | T1;}
  val_t T9;
  { T9 = T8 ^ 0x1L;}
  val_t T10;
  { T10 = T9 & T7;}
  val_t T11;
  { T11 = TERNARY_1(T10, T6, T5);}
  { val_t __r = this->__rand_val(); DistanceOp_po1__io_den.values[0] = __r;}
  val_t T12;
  T12 = fromDouble(toDouble(DistanceOp_po1__io_p1x.values[0]) / toDouble(DistanceOp_po1__io_den.values[0]));
  val_t T13;
  T13 = DistanceOp_po1__io_operation.values[0] == 0x3L;
  val_t T14;
  { T14 = T8 | T7;}
  val_t T15;
  { T15 = T14 ^ 0x1L;}
  val_t T16;
  { T16 = T15 & T13;}
  val_t T17;
  { T17 = TERNARY_1(T16, T12, T11);}
  val_t T18;
  T18 = DistanceOp_po1__io_operation.values[0] == 0x4L;
  val_t T19;
  { T19 = T14 | T13;}
  val_t T20;
  { T20 = T19 | T18;}
  val_t T21;
  { T21 = T20 ^ 0x1L;}
  val_t T22;
  { T22 = TERNARY(T21, 0x0L, T17);}
  { DistanceOp_po1__io_poutx.values[0] = T22;}
  { DistanceOp_po2__io_p1x.values[0] = DistanceOp_po1__io_poutx.values[0];}
  val_t T23;
  T23 = fromDouble(toDouble(DistanceOp_po2__io_p1x.values[0]) + toDouble(DistanceOp_po2__io_p2x.values[0]));
  { DistanceOp_po2__io_operation.values[0] = 0x4L;}
  val_t T24;
  T24 = DistanceOp_po2__io_operation.values[0] == 0x1L;
  val_t T25;
  T25 = DistanceOp_po2__io_operation.values[0] == 0x0L;
  val_t T26;
  { T26 = T25 ^ 0x1L;}
  val_t T27;
  { T27 = T26 & T24;}
  val_t T28;
  { T28 = TERNARY(T27, T23, 0x0L);}
  val_t T29;
  T29 = fromDouble(toDouble(DistanceOp_po2__io_p1x.values[0]) - toDouble(DistanceOp_po2__io_p2x.values[0]));
  val_t T30;
  T30 = DistanceOp_po2__io_operation.values[0] == 0x2L;
  val_t T31;
  { T31 = T25 | T24;}
  val_t T32;
  { T32 = T31 ^ 0x1L;}
  val_t T33;
  { T33 = T32 & T30;}
  val_t T34;
  { T34 = TERNARY_1(T33, T29, T28);}
  { val_t __r = this->__rand_val(); DistanceOp_po2__io_den.values[0] = __r;}
  val_t T35;
  T35 = fromDouble(toDouble(DistanceOp_po2__io_p1x.values[0]) / toDouble(DistanceOp_po2__io_den.values[0]));
  val_t T36;
  T36 = DistanceOp_po2__io_operation.values[0] == 0x3L;
  val_t T37;
  { T37 = T31 | T30;}
  val_t T38;
  { T38 = T37 ^ 0x1L;}
  val_t T39;
  { T39 = T38 & T36;}
  val_t T40;
  { T40 = TERNARY_1(T39, T35, T34);}
  val_t T41;
  T41 = DistanceOp_po2__io_operation.values[0] == 0x4L;
  val_t T42;
  { T42 = T37 | T36;}
  val_t T43;
  { T43 = T42 | T41;}
  val_t T44;
  { T44 = T43 ^ 0x1L;}
  val_t T45;
  { T45 = TERNARY(T44, 0x0L, T40);}
  { DistanceOp_po2__io_poutx.values[0] = T45;}
  { val_t __r = this->__rand_val(); DistanceOp_po2__io_p2y.values[0] = __r;}
  { DistanceOp_po1__io_p2y.values[0] = DistanceOp__io_p2y.values[0];}
  { DistanceOp_po1__io_p1y.values[0] = DistanceOp__io_p1y.values[0];}
  val_t T46;
  T46 = fromDouble(toDouble(DistanceOp_po1__io_p1y.values[0]) + toDouble(DistanceOp_po1__io_p2y.values[0]));
  val_t T47;
  { T47 = TERNARY(T4, T46, 0x0L);}
  val_t T48;
  T48 = fromDouble(toDouble(DistanceOp_po1__io_p1y.values[0]) - toDouble(DistanceOp_po1__io_p2y.values[0]));
  val_t T49;
  { T49 = TERNARY_1(T10, T48, T47);}
  val_t T50;
  T50 = fromDouble(toDouble(DistanceOp_po1__io_p1y.values[0]) / toDouble(DistanceOp_po1__io_den.values[0]));
  val_t T51;
  { T51 = TERNARY_1(T16, T50, T49);}
  val_t T52;
  { T52 = TERNARY(T21, 0x0L, T51);}
  { DistanceOp_po1__io_pouty.values[0] = T52;}
  { DistanceOp_po2__io_p1y.values[0] = DistanceOp_po1__io_pouty.values[0];}
  val_t T53;
  T53 = fromDouble(toDouble(DistanceOp_po2__io_p1y.values[0]) + toDouble(DistanceOp_po2__io_p2y.values[0]));
  val_t T54;
  { T54 = TERNARY(T27, T53, 0x0L);}
  val_t T55;
  T55 = fromDouble(toDouble(DistanceOp_po2__io_p1y.values[0]) - toDouble(DistanceOp_po2__io_p2y.values[0]));
  val_t T56;
  { T56 = TERNARY_1(T33, T55, T54);}
  val_t T57;
  T57 = fromDouble(toDouble(DistanceOp_po2__io_p1y.values[0]) / toDouble(DistanceOp_po2__io_den.values[0]));
  val_t T58;
  { T58 = TERNARY_1(T39, T57, T56);}
  val_t T59;
  { T59 = TERNARY(T44, 0x0L, T58);}
  { DistanceOp_po2__io_pouty.values[0] = T59;}
  val_t T60;
  T60 = fromDouble(toDouble(DistanceOp_po1__io_p1y.values[0]) * toDouble(DistanceOp_po1__io_p1y.values[0]));
  val_t T61;
  T61 = fromDouble(toDouble(DistanceOp_po1__io_p1x.values[0]) * toDouble(DistanceOp_po1__io_p1x.values[0]));
  val_t T62;
  T62 = fromDouble(toDouble(T61) + toDouble(T60));
  val_t T63;
  T63 = fromDouble(sqrt(toDouble(T62)));
  val_t T64;
  { T64 = T19 ^ 0x1L;}
  val_t T65;
  { T65 = T64 & T18;}
  val_t T66;
  { T66 = TERNARY(T65, T63, 0x0L);}
  { DistanceOp_po1__io_out.values[0] = T66;}
  val_t T67;
  T67 = fromDouble(toDouble(DistanceOp_po2__io_p1y.values[0]) * toDouble(DistanceOp_po2__io_p1y.values[0]));
  val_t T68;
  T68 = fromDouble(toDouble(DistanceOp_po2__io_p1x.values[0]) * toDouble(DistanceOp_po2__io_p1x.values[0]));
  val_t T69;
  T69 = fromDouble(toDouble(T68) + toDouble(T67));
  val_t T70;
  T70 = fromDouble(sqrt(toDouble(T69)));
  val_t T71;
  { T71 = T42 ^ 0x1L;}
  val_t T72;
  { T72 = T71 & T41;}
  val_t T73;
  { T73 = TERNARY(T72, T70, 0x0L);}
  { DistanceOp_po2__io_out.values[0] = T73;}
  { DistanceOp__io_out.values[0] = DistanceOp_po2__io_out.values[0];}
}


void DistanceOp_t::clock_hi ( dat_t<1> reset ) {
}


void DistanceOp_api_t::init_sim_data (  ) {
  sim_data.inputs.clear();
  sim_data.outputs.clear();
  sim_data.signals.clear();
  DistanceOp_t* mod = dynamic_cast<DistanceOp_t*>(module);
  assert(mod);
  sim_data.inputs.push_back(new dat_api<64>(&mod->DistanceOp__io_p1x));
  sim_data.inputs.push_back(new dat_api<64>(&mod->DistanceOp__io_p1y));
  sim_data.inputs.push_back(new dat_api<64>(&mod->DistanceOp__io_p2x));
  sim_data.inputs.push_back(new dat_api<64>(&mod->DistanceOp__io_p2y));
  sim_data.outputs.push_back(new dat_api<64>(&mod->DistanceOp__io_out));
  sim_data.signals.push_back(new dat_api<64>(&mod->DistanceOp_po1__io_p2x));
  sim_data.signal_map["DistanceOp.po1.io_p2x"] = 0;
  sim_data.signals.push_back(new dat_api<64>(&mod->DistanceOp_po1__io_p1x));
  sim_data.signal_map["DistanceOp.po1.io_p1x"] = 1;
  sim_data.signals.push_back(new dat_api<4>(&mod->DistanceOp_po1__io_operation));
  sim_data.signal_map["DistanceOp.po1.io_operation"] = 2;
  sim_data.signals.push_back(new dat_api<64>(&mod->DistanceOp_po1__io_poutx));
  sim_data.signal_map["DistanceOp.po1.io_poutx"] = 3;
  sim_data.signals.push_back(new dat_api<64>(&mod->DistanceOp_po2__io_p1x));
  sim_data.signal_map["DistanceOp.po2.io_p1x"] = 4;
  sim_data.signals.push_back(new dat_api<4>(&mod->DistanceOp_po2__io_operation));
  sim_data.signal_map["DistanceOp.po2.io_operation"] = 5;
  sim_data.signals.push_back(new dat_api<64>(&mod->DistanceOp_po2__io_poutx));
  sim_data.signal_map["DistanceOp.po2.io_poutx"] = 6;
  sim_data.signals.push_back(new dat_api<64>(&mod->DistanceOp_po1__io_p2y));
  sim_data.signal_map["DistanceOp.po1.io_p2y"] = 7;
  sim_data.signals.push_back(new dat_api<64>(&mod->DistanceOp_po1__io_p1y));
  sim_data.signal_map["DistanceOp.po1.io_p1y"] = 8;
  sim_data.signals.push_back(new dat_api<64>(&mod->DistanceOp_po1__io_pouty));
  sim_data.signal_map["DistanceOp.po1.io_pouty"] = 9;
  sim_data.signals.push_back(new dat_api<64>(&mod->DistanceOp_po2__io_p1y));
  sim_data.signal_map["DistanceOp.po2.io_p1y"] = 10;
  sim_data.signals.push_back(new dat_api<64>(&mod->DistanceOp_po2__io_pouty));
  sim_data.signal_map["DistanceOp.po2.io_pouty"] = 11;
  sim_data.signals.push_back(new dat_api<64>(&mod->DistanceOp_po1__io_out));
  sim_data.signal_map["DistanceOp.po1.io_out"] = 12;
  sim_data.signals.push_back(new dat_api<64>(&mod->DistanceOp_po2__io_out));
  sim_data.signal_map["DistanceOp.po2.io_out"] = 13;
  sim_data.clk_map["clk"] = new clk_api(&mod->clk);
}
