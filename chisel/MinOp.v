module Min2Op_0(
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
  assign T2 = T1 ? io_oldMin : 32'h1;
endmodule

module Min2Op_1(
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
  assign T2 = T1 ? io_oldMin : 32'h2;
endmodule

module Min2Op_2(
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
  assign T2 = T1 ? io_oldMin : 32'h3;
endmodule

module Min2Op_3(
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
  assign T2 = T1 ? io_oldMin : 32'h4;
endmodule

module Min2Op_4(
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
  assign T2 = T1 ? io_oldMin : 32'h5;
endmodule

module Min2Op_5(
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
  assign T2 = T1 ? io_oldMin : 32'h6;
endmodule

module Min2Op_6(
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
  assign T2 = T1 ? io_oldMin : 32'h7;
endmodule

module Min2Op_7(
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
  assign T2 = T1 ? io_oldMin : 32'h8;
endmodule

module Min2Op_8(
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

module MinOp(
    input [63:0] io_values_9,
    input [63:0] io_values_8,
    input [63:0] io_values_7,
    input [63:0] io_values_6,
    input [63:0] io_values_5,
    input [63:0] io_values_4,
    input [63:0] io_values_3,
    input [63:0] io_values_2,
    input [63:0] io_values_1,
    input [63:0] io_values_0,
    output[31:0] io_out
);

  wire[31:0] Min2Op_io_newMin;
  wire[63:0] Min2Op_io_newValue;
  wire[31:0] Min2Op_1_io_newMin;
  wire[63:0] Min2Op_1_io_newValue;
  wire[31:0] Min2Op_2_io_newMin;
  wire[63:0] Min2Op_2_io_newValue;
  wire[31:0] Min2Op_3_io_newMin;
  wire[63:0] Min2Op_3_io_newValue;
  wire[31:0] Min2Op_4_io_newMin;
  wire[63:0] Min2Op_4_io_newValue;
  wire[31:0] Min2Op_5_io_newMin;
  wire[63:0] Min2Op_5_io_newValue;
  wire[31:0] Min2Op_6_io_newMin;
  wire[63:0] Min2Op_6_io_newValue;
  wire[31:0] Min2Op_7_io_newMin;
  wire[63:0] Min2Op_7_io_newValue;
  wire[31:0] Min2Op_8_io_newMin;


  assign io_out = Min2Op_8_io_newMin;
  Min2Op_0 Min2Op(
       .io_value( io_values_1 ),
       .io_oldMin( 32'h0 ),
       .io_oldValue( io_values_0 ),
       .io_newMin( Min2Op_io_newMin ),
       .io_newValue( Min2Op_io_newValue )
  );
  Min2Op_1 Min2Op_1(
       .io_value( io_values_2 ),
       .io_oldMin( Min2Op_io_newMin ),
       .io_oldValue( Min2Op_io_newValue ),
       .io_newMin( Min2Op_1_io_newMin ),
       .io_newValue( Min2Op_1_io_newValue )
  );
  Min2Op_2 Min2Op_2(
       .io_value( io_values_3 ),
       .io_oldMin( Min2Op_1_io_newMin ),
       .io_oldValue( Min2Op_1_io_newValue ),
       .io_newMin( Min2Op_2_io_newMin ),
       .io_newValue( Min2Op_2_io_newValue )
  );
  Min2Op_3 Min2Op_3(
       .io_value( io_values_4 ),
       .io_oldMin( Min2Op_2_io_newMin ),
       .io_oldValue( Min2Op_2_io_newValue ),
       .io_newMin( Min2Op_3_io_newMin ),
       .io_newValue( Min2Op_3_io_newValue )
  );
  Min2Op_4 Min2Op_4(
       .io_value( io_values_5 ),
       .io_oldMin( Min2Op_3_io_newMin ),
       .io_oldValue( Min2Op_3_io_newValue ),
       .io_newMin( Min2Op_4_io_newMin ),
       .io_newValue( Min2Op_4_io_newValue )
  );
  Min2Op_5 Min2Op_5(
       .io_value( io_values_6 ),
       .io_oldMin( Min2Op_4_io_newMin ),
       .io_oldValue( Min2Op_4_io_newValue ),
       .io_newMin( Min2Op_5_io_newMin ),
       .io_newValue( Min2Op_5_io_newValue )
  );
  Min2Op_6 Min2Op_6(
       .io_value( io_values_7 ),
       .io_oldMin( Min2Op_5_io_newMin ),
       .io_oldValue( Min2Op_5_io_newValue ),
       .io_newMin( Min2Op_6_io_newMin ),
       .io_newValue( Min2Op_6_io_newValue )
  );
  Min2Op_7 Min2Op_7(
       .io_value( io_values_8 ),
       .io_oldMin( Min2Op_6_io_newMin ),
       .io_oldValue( Min2Op_6_io_newValue ),
       .io_newMin( Min2Op_7_io_newMin ),
       .io_newValue( Min2Op_7_io_newValue )
  );
  Min2Op_8 Min2Op_8(
       .io_value( io_values_9 ),
       .io_oldMin( Min2Op_7_io_newMin ),
       .io_oldValue( Min2Op_7_io_newValue ),
       .io_newMin( Min2Op_8_io_newMin )
       //.io_newValue(  )
  );
endmodule

