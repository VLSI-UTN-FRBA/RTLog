# RTLog
RTLog Framework: Yet another open HDL and compiler, this time for Relative-Timing design

Constraints Generator:

Invocation command:

	$ ./constrainer file\_r2r file\_const top\_name

Help showed when running without arguments:

	Use: ./constrainer file\_r2r file\_const top\_name

Where:

-file\_r2r is the output file with the R2R path, normally "top"\_constraints

-file\_const is the desired output file, normally "top".tcl

-top\_name is the name of the block we want to generate the constraints

Currently, every constraint is mapped for fixed frequency.

