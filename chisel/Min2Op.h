#ifndef __Min2Op__
#define __Min2Op__

#include "emulator.h"

class Min2Op_t : public mod_t {
 private:
  val_t __rand_seed;
  void __srand(val_t seed) { __rand_seed = seed; }
  val_t __rand_val() { return ::__rand_val(&__rand_seed); }
 public:
  dat_t<32> Min2Op__io_oldMin;
  dat_t<32> Min2Op__io_newMin;
  dat_t<64> Min2Op__io_oldValue;
  dat_t<64> Min2Op__io_value;
  dat_t<64> Min2Op__io_newValue;
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
class Min2Op_api_t : public emul_api_t {
 public:
  Min2Op_api_t(mod_t* m) : emul_api_t(m) { }
  void init_sim_data();
};

#endif
