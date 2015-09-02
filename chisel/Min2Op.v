module Min2Op(
    input [63:0] io_value,
    input [31:0] io_oldMin,
    input [63:0] io_oldValue,
    output[31:0] io_newMin,
    output[63:0] io_newValue
);

  wire[63:0] T0;
  wire T1;
  wire[31:0] T2;


  assign io_newValue = T0;
  assign T0 = T1 ? io_oldValue : io_value;
  assign T1 = io_value d>= io_oldValue;
  assign io_newMin = T2;
  assign T2 = T1 ? io_oldMin : 32'h9;
endmodule

