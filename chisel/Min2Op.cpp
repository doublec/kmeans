#include "Min2Op.h"

void Min2Op_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  clk.len = 1;
  clk.cnt = clk.len;
  clk.values[0] = 0;
}


int Min2Op_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk.cnt < min) min = clk.cnt;
  clk.cnt-=min;
  if (clk.cnt == 0) clock_lo( reset );
  if (clk.cnt == 0) clock_hi( reset );
  if (clk.cnt == 0) clk.cnt = clk.len;
  return min;
}


void Min2Op_t::print ( FILE* f ) {
}
void Min2Op_t::print ( std::ostream& s ) {
}


void Min2Op_t::dump_init ( FILE* f ) {
}


void Min2Op_t::dump ( FILE* f, int t ) {
}




void Min2Op_t::clock_lo ( dat_t<1> reset ) {
  val_t T0;
  T0 = toDouble(Min2Op__io_value.values[0]) >= toDouble(Min2Op__io_oldValue.values[0]);
  val_t T1;
  { T1 = TERNARY(T0, Min2Op__io_oldMin.values[0], 0x9L);}
  { Min2Op__io_newMin.values[0] = T1;}
  val_t T2;
  { T2 = TERNARY_1(T0, Min2Op__io_oldValue.values[0], Min2Op__io_value.values[0]);}
  { Min2Op__io_newValue.values[0] = T2;}
}


void Min2Op_t::clock_hi ( dat_t<1> reset ) {
}


void Min2Op_api_t::init_sim_data (  ) {
  sim_data.inputs.clear();
  sim_data.outputs.clear();
  sim_data.signals.clear();
  Min2Op_t* mod = dynamic_cast<Min2Op_t*>(module);
  assert(mod);
  sim_data.inputs.push_back(new dat_api<64>(&mod->Min2Op__io_value));
  sim_data.inputs.push_back(new dat_api<32>(&mod->Min2Op__io_oldMin));
  sim_data.inputs.push_back(new dat_api<64>(&mod->Min2Op__io_oldValue));
  sim_data.outputs.push_back(new dat_api<32>(&mod->Min2Op__io_newMin));
  sim_data.outputs.push_back(new dat_api<64>(&mod->Min2Op__io_newValue));
  sim_data.clk_map["clk"] = new clk_api(&mod->clk);
}
