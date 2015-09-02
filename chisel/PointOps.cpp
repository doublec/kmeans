#include "PointOps.h"

void PointOps_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  clk.len = 1;
  clk.cnt = clk.len;
  clk.values[0] = 0;
}


int PointOps_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk.cnt < min) min = clk.cnt;
  clk.cnt-=min;
  if (clk.cnt == 0) clock_lo( reset );
  if (clk.cnt == 0) clock_hi( reset );
  if (clk.cnt == 0) clk.cnt = clk.len;
  return min;
}


void PointOps_t::print ( FILE* f ) {
}
void PointOps_t::print ( std::ostream& s ) {
}


void PointOps_t::dump_init ( FILE* f ) {
}


void PointOps_t::dump ( FILE* f, int t ) {
}




void PointOps_t::clock_lo ( dat_t<1> reset ) {
  val_t T0;
  T0 = fromDouble(toDouble(PointOps__io_p1x.values[0]) + toDouble(PointOps__io_p2x.values[0]));
  val_t T1;
  T1 = PointOps__io_operation.values[0] == 0x1L;
  val_t T2;
  T2 = PointOps__io_operation.values[0] == 0x0L;
  val_t T3;
  { T3 = T2 ^ 0x1L;}
  val_t T4;
  { T4 = T3 & T1;}
  val_t T5;
  { T5 = TERNARY(T4, T0, 0x0L);}
  val_t T6;
  T6 = fromDouble(toDouble(PointOps__io_p1x.values[0]) - toDouble(PointOps__io_p2x.values[0]));
  val_t T7;
  T7 = PointOps__io_operation.values[0] == 0x2L;
  val_t T8;
  { T8 = T2 | T1;}
  val_t T9;
  { T9 = T8 ^ 0x1L;}
  val_t T10;
  { T10 = T9 & T7;}
  val_t T11;
  { T11 = TERNARY_1(T10, T6, T5);}
  val_t T12;
  T12 = fromDouble(toDouble(PointOps__io_p1x.values[0]) / toDouble(PointOps__io_den.values[0]));
  val_t T13;
  T13 = PointOps__io_operation.values[0] == 0x3L;
  val_t T14;
  { T14 = T8 | T7;}
  val_t T15;
  { T15 = T14 ^ 0x1L;}
  val_t T16;
  { T16 = T15 & T13;}
  val_t T17;
  { T17 = TERNARY_1(T16, T12, T11);}
  val_t T18;
  T18 = PointOps__io_operation.values[0] == 0x4L;
  val_t T19;
  { T19 = T14 | T13;}
  val_t T20;
  { T20 = T19 | T18;}
  val_t T21;
  { T21 = T20 ^ 0x1L;}
  val_t T22;
  { T22 = TERNARY(T21, 0x0L, T17);}
  { PointOps__io_poutx.values[0] = T22;}
  val_t T23;
  T23 = fromDouble(toDouble(PointOps__io_p1y.values[0]) + toDouble(PointOps__io_p2y.values[0]));
  val_t T24;
  { T24 = TERNARY(T4, T23, 0x0L);}
  val_t T25;
  T25 = fromDouble(toDouble(PointOps__io_p1y.values[0]) - toDouble(PointOps__io_p2y.values[0]));
  val_t T26;
  { T26 = TERNARY_1(T10, T25, T24);}
  val_t T27;
  T27 = fromDouble(toDouble(PointOps__io_p1y.values[0]) / toDouble(PointOps__io_den.values[0]));
  val_t T28;
  { T28 = TERNARY_1(T16, T27, T26);}
  val_t T29;
  { T29 = TERNARY(T21, 0x0L, T28);}
  { PointOps__io_pouty.values[0] = T29;}
  val_t T30;
  T30 = fromDouble(toDouble(PointOps__io_p1y.values[0]) * toDouble(PointOps__io_p1y.values[0]));
  val_t T31;
  T31 = fromDouble(toDouble(PointOps__io_p1x.values[0]) * toDouble(PointOps__io_p1x.values[0]));
  val_t T32;
  T32 = fromDouble(toDouble(T31) + toDouble(T30));
  val_t T33;
  T33 = fromDouble(sqrt(toDouble(T32)));
  val_t T34;
  { T34 = T19 ^ 0x1L;}
  val_t T35;
  { T35 = T34 & T18;}
  val_t T36;
  { T36 = TERNARY(T35, T33, 0x0L);}
  { PointOps__io_out.values[0] = T36;}
}


void PointOps_t::clock_hi ( dat_t<1> reset ) {
}


void PointOps_api_t::init_sim_data (  ) {
  sim_data.inputs.clear();
  sim_data.outputs.clear();
  sim_data.signals.clear();
  PointOps_t* mod = dynamic_cast<PointOps_t*>(module);
  assert(mod);
  sim_data.inputs.push_back(new dat_api<64>(&mod->PointOps__io_p1x));
  sim_data.inputs.push_back(new dat_api<64>(&mod->PointOps__io_p1y));
  sim_data.inputs.push_back(new dat_api<4>(&mod->PointOps__io_operation));
  sim_data.inputs.push_back(new dat_api<64>(&mod->PointOps__io_p2x));
  sim_data.inputs.push_back(new dat_api<64>(&mod->PointOps__io_p2y));
  sim_data.inputs.push_back(new dat_api<64>(&mod->PointOps__io_den));
  sim_data.outputs.push_back(new dat_api<64>(&mod->PointOps__io_poutx));
  sim_data.outputs.push_back(new dat_api<64>(&mod->PointOps__io_pouty));
  sim_data.outputs.push_back(new dat_api<64>(&mod->PointOps__io_out));
  sim_data.clk_map["clk"] = new clk_api(&mod->clk);
}
