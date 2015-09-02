#ifndef __MinOp__
#define __MinOp__

#include "emulator.h"

class MinOp_t : public mod_t {
 private:
  val_t __rand_seed;
  void __srand(val_t seed) { __rand_seed = seed; }
  val_t __rand_val() { return ::__rand_val(&__rand_seed); }
 public:
  dat_t<32> MinOp_Min2Op__io_oldMin;
  dat_t<32> MinOp_Min2Op__io_newMin;
  dat_t<32> MinOp_Min2Op_1__io_oldMin;
  dat_t<32> MinOp_Min2Op_1__io_newMin;
  dat_t<32> MinOp_Min2Op_2__io_oldMin;
  dat_t<32> MinOp_Min2Op_2__io_newMin;
  dat_t<32> MinOp_Min2Op_3__io_oldMin;
  dat_t<32> MinOp_Min2Op_3__io_newMin;
  dat_t<32> MinOp_Min2Op_4__io_oldMin;
  dat_t<32> MinOp_Min2Op_4__io_newMin;
  dat_t<32> MinOp_Min2Op_5__io_oldMin;
  dat_t<32> MinOp_Min2Op_5__io_newMin;
  dat_t<32> MinOp_Min2Op_6__io_oldMin;
  dat_t<32> MinOp_Min2Op_6__io_newMin;
  dat_t<32> MinOp_Min2Op_7__io_oldMin;
  dat_t<32> MinOp_Min2Op_7__io_newMin;
  dat_t<32> MinOp_Min2Op_8__io_oldMin;
  dat_t<32> MinOp_Min2Op_8__io_newMin;
  dat_t<32> MinOp__io_out;
  dat_t<64> MinOp__io_values_9;
  dat_t<64> MinOp_Min2Op_8__io_value;
  dat_t<64> MinOp__io_values_8;
  dat_t<64> MinOp_Min2Op_7__io_value;
  dat_t<64> MinOp__io_values_7;
  dat_t<64> MinOp_Min2Op_6__io_value;
  dat_t<64> MinOp__io_values_6;
  dat_t<64> MinOp_Min2Op_5__io_value;
  dat_t<64> MinOp__io_values_5;
  dat_t<64> MinOp_Min2Op_4__io_value;
  dat_t<64> MinOp__io_values_4;
  dat_t<64> MinOp_Min2Op_3__io_value;
  dat_t<64> MinOp__io_values_3;
  dat_t<64> MinOp_Min2Op_2__io_value;
  dat_t<64> MinOp__io_values_2;
  dat_t<64> MinOp_Min2Op_1__io_value;
  dat_t<64> MinOp__io_values_1;
  dat_t<64> MinOp_Min2Op__io_value;
  dat_t<64> MinOp__io_values_0;
  dat_t<64> MinOp_Min2Op__io_oldValue;
  dat_t<64> MinOp_Min2Op__io_newValue;
  dat_t<64> MinOp_Min2Op_1__io_oldValue;
  dat_t<64> MinOp_Min2Op_1__io_newValue;
  dat_t<64> MinOp_Min2Op_2__io_oldValue;
  dat_t<64> MinOp_Min2Op_2__io_newValue;
  dat_t<64> MinOp_Min2Op_3__io_oldValue;
  dat_t<64> MinOp_Min2Op_3__io_newValue;
  dat_t<64> MinOp_Min2Op_4__io_oldValue;
  dat_t<64> MinOp_Min2Op_4__io_newValue;
  dat_t<64> MinOp_Min2Op_5__io_oldValue;
  dat_t<64> MinOp_Min2Op_5__io_newValue;
  dat_t<64> MinOp_Min2Op_6__io_oldValue;
  dat_t<64> MinOp_Min2Op_6__io_newValue;
  dat_t<64> MinOp_Min2Op_7__io_oldValue;
  dat_t<64> MinOp_Min2Op_7__io_newValue;
  dat_t<64> MinOp_Min2Op_8__io_oldValue;
  dat_t<64> MinOp_Min2Op_8__io_newValue;
  clk_t clk;

  void init ( val_t rand_init = 0 );
  void clock_lo ( dat_t<1> reset );
  void clock_hi ( dat_t<1> reset );
  int clock ( dat_t<1> reset );
  void print ( FILE* f );
  void print ( std::ostream& s );
  void dump ( FILE* f, int t );
  void dump_init ( FILE* f );

};

#include "emul_api.h"
class MinOp_api_t : public emul_api_t {
 public:
  MinOp_api_t(mod_t* m) : emul_api_t(m) { }
  void init_sim_data();
};

#endif
