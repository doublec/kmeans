#include "MinOp.h"

void MinOp_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  clk.len = 1;
  clk.cnt = clk.len;
  clk.values[0] = 0;
}


int MinOp_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk.cnt < min) min = clk.cnt;
  clk.cnt-=min;
  if (clk.cnt == 0) clock_lo( reset );
  if (clk.cnt == 0) clock_hi( reset );
  if (clk.cnt == 0) clk.cnt = clk.len;
  return min;
}


void MinOp_t::print ( FILE* f ) {
}
void MinOp_t::print ( std::ostream& s ) {
}


void MinOp_t::dump_init ( FILE* f ) {
}


void MinOp_t::dump ( FILE* f, int t ) {
}




void MinOp_t::clock_lo ( dat_t<1> reset ) {
  { MinOp_Min2Op_8__io_value.values[0] = MinOp__io_values_9.values[0];}
  { MinOp_Min2Op_7__io_value.values[0] = MinOp__io_values_8.values[0];}
  { MinOp_Min2Op_6__io_value.values[0] = MinOp__io_values_7.values[0];}
  { MinOp_Min2Op_5__io_value.values[0] = MinOp__io_values_6.values[0];}
  { MinOp_Min2Op_4__io_value.values[0] = MinOp__io_values_5.values[0];}
  { MinOp_Min2Op_3__io_value.values[0] = MinOp__io_values_4.values[0];}
  { MinOp_Min2Op_2__io_value.values[0] = MinOp__io_values_3.values[0];}
  { MinOp_Min2Op_1__io_value.values[0] = MinOp__io_values_2.values[0];}
  { MinOp_Min2Op__io_value.values[0] = MinOp__io_values_1.values[0];}
  { MinOp_Min2Op__io_oldValue.values[0] = MinOp__io_values_0.values[0];}
  val_t T0;
  T0 = toDouble(MinOp_Min2Op__io_value.values[0]) >= toDouble(MinOp_Min2Op__io_oldValue.values[0]);
  val_t T1;
  { T1 = TERNARY_1(T0, MinOp_Min2Op__io_oldValue.values[0], MinOp_Min2Op__io_value.values[0]);}
  { MinOp_Min2Op__io_newValue.values[0] = T1;}
  { MinOp_Min2Op_1__io_oldValue.values[0] = MinOp_Min2Op__io_newValue.values[0];}
  val_t T2;
  T2 = toDouble(MinOp_Min2Op_1__io_value.values[0]) >= toDouble(MinOp_Min2Op_1__io_oldValue.values[0]);
  val_t T3;
  { T3 = TERNARY_1(T2, MinOp_Min2Op_1__io_oldValue.values[0], MinOp_Min2Op_1__io_value.values[0]);}
  { MinOp_Min2Op_1__io_newValue.values[0] = T3;}
  { MinOp_Min2Op_2__io_oldValue.values[0] = MinOp_Min2Op_1__io_newValue.values[0];}
  val_t T4;
  T4 = toDouble(MinOp_Min2Op_2__io_value.values[0]) >= toDouble(MinOp_Min2Op_2__io_oldValue.values[0]);
  val_t T5;
  { T5 = TERNARY_1(T4, MinOp_Min2Op_2__io_oldValue.values[0], MinOp_Min2Op_2__io_value.values[0]);}
  { MinOp_Min2Op_2__io_newValue.values[0] = T5;}
  { MinOp_Min2Op_3__io_oldValue.values[0] = MinOp_Min2Op_2__io_newValue.values[0];}
  val_t T6;
  T6 = toDouble(MinOp_Min2Op_3__io_value.values[0]) >= toDouble(MinOp_Min2Op_3__io_oldValue.values[0]);
  val_t T7;
  { T7 = TERNARY_1(T6, MinOp_Min2Op_3__io_oldValue.values[0], MinOp_Min2Op_3__io_value.values[0]);}
  { MinOp_Min2Op_3__io_newValue.values[0] = T7;}
  { MinOp_Min2Op_4__io_oldValue.values[0] = MinOp_Min2Op_3__io_newValue.values[0];}
  val_t T8;
  T8 = toDouble(MinOp_Min2Op_4__io_value.values[0]) >= toDouble(MinOp_Min2Op_4__io_oldValue.values[0]);
  val_t T9;
  { T9 = TERNARY_1(T8, MinOp_Min2Op_4__io_oldValue.values[0], MinOp_Min2Op_4__io_value.values[0]);}
  { MinOp_Min2Op_4__io_newValue.values[0] = T9;}
  { MinOp_Min2Op_5__io_oldValue.values[0] = MinOp_Min2Op_4__io_newValue.values[0];}
  val_t T10;
  T10 = toDouble(MinOp_Min2Op_5__io_value.values[0]) >= toDouble(MinOp_Min2Op_5__io_oldValue.values[0]);
  val_t T11;
  { T11 = TERNARY_1(T10, MinOp_Min2Op_5__io_oldValue.values[0], MinOp_Min2Op_5__io_value.values[0]);}
  { MinOp_Min2Op_5__io_newValue.values[0] = T11;}
  { MinOp_Min2Op_6__io_oldValue.values[0] = MinOp_Min2Op_5__io_newValue.values[0];}
  val_t T12;
  T12 = toDouble(MinOp_Min2Op_6__io_value.values[0]) >= toDouble(MinOp_Min2Op_6__io_oldValue.values[0]);
  val_t T13;
  { T13 = TERNARY_1(T12, MinOp_Min2Op_6__io_oldValue.values[0], MinOp_Min2Op_6__io_value.values[0]);}
  { MinOp_Min2Op_6__io_newValue.values[0] = T13;}
  { MinOp_Min2Op_7__io_oldValue.values[0] = MinOp_Min2Op_6__io_newValue.values[0];}
  val_t T14;
  T14 = toDouble(MinOp_Min2Op_7__io_value.values[0]) >= toDouble(MinOp_Min2Op_7__io_oldValue.values[0]);
  val_t T15;
  { T15 = TERNARY_1(T14, MinOp_Min2Op_7__io_oldValue.values[0], MinOp_Min2Op_7__io_value.values[0]);}
  { MinOp_Min2Op_7__io_newValue.values[0] = T15;}
  { MinOp_Min2Op_8__io_oldValue.values[0] = MinOp_Min2Op_7__io_newValue.values[0];}
  val_t T16;
  T16 = toDouble(MinOp_Min2Op_8__io_value.values[0]) >= toDouble(MinOp_Min2Op_8__io_oldValue.values[0]);
  val_t T17;
  { T17 = TERNARY_1(T16, MinOp_Min2Op_8__io_oldValue.values[0], MinOp_Min2Op_8__io_value.values[0]);}
  { MinOp_Min2Op_8__io_newValue.values[0] = T17;}
  { MinOp_Min2Op__io_oldMin.values[0] = 0x0L;}
  val_t T18;
  { T18 = TERNARY(T0, MinOp_Min2Op__io_oldMin.values[0], 0x1L);}
  { MinOp_Min2Op__io_newMin.values[0] = T18;}
  { MinOp_Min2Op_1__io_oldMin.values[0] = MinOp_Min2Op__io_newMin.values[0];}
  val_t T19;
  { T19 = TERNARY(T2, MinOp_Min2Op_1__io_oldMin.values[0], 0x2L);}
  { MinOp_Min2Op_1__io_newMin.values[0] = T19;}
  { MinOp_Min2Op_2__io_oldMin.values[0] = MinOp_Min2Op_1__io_newMin.values[0];}
  val_t T20;
  { T20 = TERNARY(T4, MinOp_Min2Op_2__io_oldMin.values[0], 0x3L);}
  { MinOp_Min2Op_2__io_newMin.values[0] = T20;}
  { MinOp_Min2Op_3__io_oldMin.values[0] = MinOp_Min2Op_2__io_newMin.values[0];}
  val_t T21;
  { T21 = TERNARY(T6, MinOp_Min2Op_3__io_oldMin.values[0], 0x4L);}
  { MinOp_Min2Op_3__io_newMin.values[0] = T21;}
  { MinOp_Min2Op_4__io_oldMin.values[0] = MinOp_Min2Op_3__io_newMin.values[0];}
  val_t T22;
  { T22 = TERNARY(T8, MinOp_Min2Op_4__io_oldMin.values[0], 0x5L);}
  { MinOp_Min2Op_4__io_newMin.values[0] = T22;}
  { MinOp_Min2Op_5__io_oldMin.values[0] = MinOp_Min2Op_4__io_newMin.values[0];}
  val_t T23;
  { T23 = TERNARY(T10, MinOp_Min2Op_5__io_oldMin.values[0], 0x6L);}
  { MinOp_Min2Op_5__io_newMin.values[0] = T23;}
  { MinOp_Min2Op_6__io_oldMin.values[0] = MinOp_Min2Op_5__io_newMin.values[0];}
  val_t T24;
  { T24 = TERNARY(T12, MinOp_Min2Op_6__io_oldMin.values[0], 0x7L);}
  { MinOp_Min2Op_6__io_newMin.values[0] = T24;}
  { MinOp_Min2Op_7__io_oldMin.values[0] = MinOp_Min2Op_6__io_newMin.values[0];}
  val_t T25;
  { T25 = TERNARY(T14, MinOp_Min2Op_7__io_oldMin.values[0], 0x8L);}
  { MinOp_Min2Op_7__io_newMin.values[0] = T25;}
  { MinOp_Min2Op_8__io_oldMin.values[0] = MinOp_Min2Op_7__io_newMin.values[0];}
  val_t T26;
  { T26 = TERNARY(T16, MinOp_Min2Op_8__io_oldMin.values[0], 0x9L);}
  { MinOp_Min2Op_8__io_newMin.values[0] = T26;}
  { MinOp__io_out.values[0] = MinOp_Min2Op_8__io_newMin.values[0];}
}


void MinOp_t::clock_hi ( dat_t<1> reset ) {
}


void MinOp_api_t::init_sim_data (  ) {
  sim_data.inputs.clear();
  sim_data.outputs.clear();
  sim_data.signals.clear();
  MinOp_t* mod = dynamic_cast<MinOp_t*>(module);
  assert(mod);
  sim_data.inputs.push_back(new dat_api<64>(&mod->MinOp__io_values_9));
  sim_data.inputs.push_back(new dat_api<64>(&mod->MinOp__io_values_8));
  sim_data.inputs.push_back(new dat_api<64>(&mod->MinOp__io_values_7));
  sim_data.inputs.push_back(new dat_api<64>(&mod->MinOp__io_values_6));
  sim_data.inputs.push_back(new dat_api<64>(&mod->MinOp__io_values_5));
  sim_data.inputs.push_back(new dat_api<64>(&mod->MinOp__io_values_4));
  sim_data.inputs.push_back(new dat_api<64>(&mod->MinOp__io_values_3));
  sim_data.inputs.push_back(new dat_api<64>(&mod->MinOp__io_values_2));
  sim_data.inputs.push_back(new dat_api<64>(&mod->MinOp__io_values_1));
  sim_data.inputs.push_back(new dat_api<64>(&mod->MinOp__io_values_0));
  sim_data.outputs.push_back(new dat_api<32>(&mod->MinOp__io_out));
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_8__io_value));
  sim_data.signal_map["MinOp.Min2Op_8.io_value"] = 0;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_7__io_value));
  sim_data.signal_map["MinOp.Min2Op_7.io_value"] = 1;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_6__io_value));
  sim_data.signal_map["MinOp.Min2Op_6.io_value"] = 2;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_5__io_value));
  sim_data.signal_map["MinOp.Min2Op_5.io_value"] = 3;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_4__io_value));
  sim_data.signal_map["MinOp.Min2Op_4.io_value"] = 4;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_3__io_value));
  sim_data.signal_map["MinOp.Min2Op_3.io_value"] = 5;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_2__io_value));
  sim_data.signal_map["MinOp.Min2Op_2.io_value"] = 6;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_1__io_value));
  sim_data.signal_map["MinOp.Min2Op_1.io_value"] = 7;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op__io_value));
  sim_data.signal_map["MinOp.Min2Op.io_value"] = 8;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op__io_oldValue));
  sim_data.signal_map["MinOp.Min2Op.io_oldValue"] = 9;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op__io_newValue));
  sim_data.signal_map["MinOp.Min2Op.io_newValue"] = 10;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_1__io_oldValue));
  sim_data.signal_map["MinOp.Min2Op_1.io_oldValue"] = 11;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_1__io_newValue));
  sim_data.signal_map["MinOp.Min2Op_1.io_newValue"] = 12;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_2__io_oldValue));
  sim_data.signal_map["MinOp.Min2Op_2.io_oldValue"] = 13;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_2__io_newValue));
  sim_data.signal_map["MinOp.Min2Op_2.io_newValue"] = 14;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_3__io_oldValue));
  sim_data.signal_map["MinOp.Min2Op_3.io_oldValue"] = 15;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_3__io_newValue));
  sim_data.signal_map["MinOp.Min2Op_3.io_newValue"] = 16;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_4__io_oldValue));
  sim_data.signal_map["MinOp.Min2Op_4.io_oldValue"] = 17;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_4__io_newValue));
  sim_data.signal_map["MinOp.Min2Op_4.io_newValue"] = 18;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_5__io_oldValue));
  sim_data.signal_map["MinOp.Min2Op_5.io_oldValue"] = 19;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_5__io_newValue));
  sim_data.signal_map["MinOp.Min2Op_5.io_newValue"] = 20;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_6__io_oldValue));
  sim_data.signal_map["MinOp.Min2Op_6.io_oldValue"] = 21;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_6__io_newValue));
  sim_data.signal_map["MinOp.Min2Op_6.io_newValue"] = 22;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_7__io_oldValue));
  sim_data.signal_map["MinOp.Min2Op_7.io_oldValue"] = 23;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_7__io_newValue));
  sim_data.signal_map["MinOp.Min2Op_7.io_newValue"] = 24;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_8__io_oldValue));
  sim_data.signal_map["MinOp.Min2Op_8.io_oldValue"] = 25;
  sim_data.signals.push_back(new dat_api<64>(&mod->MinOp_Min2Op_8__io_newValue));
  sim_data.signal_map["MinOp.Min2Op_8.io_newValue"] = 26;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op__io_oldMin));
  sim_data.signal_map["MinOp.Min2Op.io_oldMin"] = 27;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op__io_newMin));
  sim_data.signal_map["MinOp.Min2Op.io_newMin"] = 28;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_1__io_oldMin));
  sim_data.signal_map["MinOp.Min2Op_1.io_oldMin"] = 29;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_1__io_newMin));
  sim_data.signal_map["MinOp.Min2Op_1.io_newMin"] = 30;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_2__io_oldMin));
  sim_data.signal_map["MinOp.Min2Op_2.io_oldMin"] = 31;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_2__io_newMin));
  sim_data.signal_map["MinOp.Min2Op_2.io_newMin"] = 32;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_3__io_oldMin));
  sim_data.signal_map["MinOp.Min2Op_3.io_oldMin"] = 33;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_3__io_newMin));
  sim_data.signal_map["MinOp.Min2Op_3.io_newMin"] = 34;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_4__io_oldMin));
  sim_data.signal_map["MinOp.Min2Op_4.io_oldMin"] = 35;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_4__io_newMin));
  sim_data.signal_map["MinOp.Min2Op_4.io_newMin"] = 36;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_5__io_oldMin));
  sim_data.signal_map["MinOp.Min2Op_5.io_oldMin"] = 37;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_5__io_newMin));
  sim_data.signal_map["MinOp.Min2Op_5.io_newMin"] = 38;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_6__io_oldMin));
  sim_data.signal_map["MinOp.Min2Op_6.io_oldMin"] = 39;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_6__io_newMin));
  sim_data.signal_map["MinOp.Min2Op_6.io_newMin"] = 40;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_7__io_oldMin));
  sim_data.signal_map["MinOp.Min2Op_7.io_oldMin"] = 41;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_7__io_newMin));
  sim_data.signal_map["MinOp.Min2Op_7.io_newMin"] = 42;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_8__io_oldMin));
  sim_data.signal_map["MinOp.Min2Op_8.io_oldMin"] = 43;
  sim_data.signals.push_back(new dat_api<32>(&mod->MinOp_Min2Op_8__io_newMin));
  sim_data.signal_map["MinOp.Min2Op_8.io_newMin"] = 44;
  sim_data.clk_map["clk"] = new clk_api(&mod->clk);
}
