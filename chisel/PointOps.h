#ifndef __PointOps__
#define __PointOps__

#include "emulator.h"

class PointOps_t : public mod_t {
 private:
  val_t __rand_seed;
  void __srand(val_t seed) { __rand_seed = seed; }
  val_t __rand_val() { return ::__rand_val(&__rand_seed); }
 public:
  dat_t<4> PointOps__io_operation;
  dat_t<64> PointOps__io_p2x;
  dat_t<64> PointOps__io_p1x;
  dat_t<64> PointOps__io_den;
  dat_t<64> PointOps__io_poutx;
  dat_t<64> PointOps__io_p2y;
  dat_t<64> PointOps__io_p1y;
  dat_t<64> PointOps__io_pouty;
  dat_t<64> PointOps__io_out;
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
class PointOps_api_t : public emul_api_t {
 public:
  PointOps_api_t(mod_t* m) : emul_api_t(m) { }
  void init_sim_data();
};

#endif
