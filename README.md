# RTLog
RTLog Framework: Yet another open HDL and compiler, this time for Relative-Timing design

Invocation command:

	$ ./compile RTLOG_FILE [OPTIONS]

Help showed when running without arguments:

How to use: ./compile RTLOG_FILE [OPTIONS]
Converts a hdl file codified in rtlog (.rtl) in a Verilog file (.v) 

  -c, --clock=CLOCK      Specifies the sincronization metodology 
                         CLOCK: global, local.
  -R, --report=REPORT    Specifies the type of compilation report with 
                         REPORT: general, graph, async-graph, meta-graph, 
                                 cloud-logic, i2r-paths, r2o-paths, r2r-paths,.

Output result:
  0  if everything went right
  1  if it didn't do anything (for example, it run this help),

