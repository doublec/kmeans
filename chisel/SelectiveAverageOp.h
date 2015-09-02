#ifndef __SelectiveAverageOp__
#define __SelectiveAverageOp__

#include "emulator.h"

class SelectiveAverageOp_t : public mod_t {
 private:
  val_t __rand_seed;
  void __srand(val_t seed) { __rand_seed = seed; }
  val_t __rand_val() { return ::__rand_val(&__rand_seed); }
 public:
  dat_t<4> SelectiveAverageOp_SelectivePointOps__io_operation;
  dat_t<4> SelectiveAverageOp_SelectivePointOps_po__io_operation;
  dat_t<4> SelectiveAverageOp_SelectivePointOps_1__io_operation;
  dat_t<4> SelectiveAverageOp_SelectivePointOps_1_po__io_operation;
  dat_t<4> SelectiveAverageOp_SelectivePointOps_2__io_operation;
  dat_t<4> SelectiveAverageOp_SelectivePointOps_2_po__io_operation;
  dat_t<4> SelectiveAverageOp_SelectivePointOps_3__io_operation;
  dat_t<4> SelectiveAverageOp_SelectivePointOps_3_po__io_operation;
  dat_t<32> SelectiveAverageOp__io_cent_0;
  dat_t<32> SelectiveAverageOp_SelectivePointOps__io_cent;
  dat_t<32> SelectiveAverageOp__io_cent_1;
  dat_t<32> SelectiveAverageOp_SelectivePointOps_1__io_cent;
  dat_t<32> SelectiveAverageOp__io_cent_2;
  dat_t<32> SelectiveAverageOp_SelectivePointOps_2__io_cent;
  dat_t<32> SelectiveAverageOp_conv__io_in;
  dat_t<32> SelectiveAverageOp_SelectivePointOps_3__io_cent;
  dat_t<64> SelectiveAverageOp__io_ys_2;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2__io_p2y;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2_po__io_p2y;
  dat_t<64> SelectiveAverageOp__io_ys_1;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1__io_p2y;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1_po__io_p2y;
  dat_t<64> SelectiveAverageOp__io_ys_0;
  dat_t<64> SelectiveAverageOp_SelectivePointOps__io_p2y;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_po__io_p2y;
  dat_t<64> SelectiveAverageOp_SelectivePointOps__io_p1y;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_po__io_p1y;
  dat_t<64> SelectiveAverageOp_SelectivePointOps__io_den;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_po__io_den;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_po__io_pouty;
  dat_t<64> SelectiveAverageOp_SelectivePointOps__io_pouty;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1__io_p1y;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1_po__io_p1y;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1__io_den;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1_po__io_den;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1_po__io_pouty;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1__io_pouty;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2__io_p1y;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2_po__io_p1y;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2__io_den;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2_po__io_den;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2_po__io_pouty;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2__io_pouty;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3__io_p1y;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3_po__io_p1y;
  dat_t<64> SelectiveAverageOp__io_xs_2;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2__io_p2x;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2_po__io_p2x;
  dat_t<64> SelectiveAverageOp__io_xs_1;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1__io_p2x;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1_po__io_p2x;
  dat_t<64> SelectiveAverageOp__io_xs_0;
  dat_t<64> SelectiveAverageOp_SelectivePointOps__io_p2x;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_po__io_p2x;
  dat_t<64> SelectiveAverageOp_SelectivePointOps__io_p1x;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_po__io_p1x;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_po__io_poutx;
  dat_t<64> SelectiveAverageOp_SelectivePointOps__io_poutx;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1__io_p1x;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1_po__io_p1x;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1_po__io_poutx;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1__io_poutx;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2__io_p1x;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2_po__io_p1x;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2_po__io_poutx;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2__io_poutx;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3__io_p1x;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3_po__io_p1x;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3_po__io_out;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3__io_out;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2_po__io_out;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_2__io_out;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1_po__io_out;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_1__io_out;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_po__io_out;
  dat_t<64> SelectiveAverageOp_SelectivePointOps__io_out;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3__io_p2x;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3_po__io_p2x;
  dat_t<64> SelectiveAverageOp_conv__io_out;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3__io_den;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3_po__io_den;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3_po__io_poutx;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3__io_poutx;
  dat_t<64> SelectiveAverageOp__io_outX;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3__io_p2y;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3_po__io_p2y;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3_po__io_pouty;
  dat_t<64> SelectiveAverageOp_SelectivePointOps_3__io_pouty;
  dat_t<64> SelectiveAverageOp__io_outY;
  mem_t<64,4> T160;
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
class SelectiveAverageOp_api_t : public emul_api_t {
 public:
  SelectiveAverageOp_api_t(mod_t* m) : emul_api_t(m) { }
  void init_sim_data();
};

#endif
