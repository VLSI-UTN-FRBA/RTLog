module buffer
	(
		input wire rst,
		input wire a,
		output wire b,
		input wire lr_a_i,
		output wire la_a_i,
	);

	wire q_4;
	wire q_5;
	wire le_lc_6;
	wire le_lc_7;
	wire net_0;
	wire net_1;
	wire net_2;
	wire net_3;
	wire net_4;
	wire net_5;
	wire net_6;
	wire net_7;
	wire net_8;

	assign net_0 = a;
	assign b = net_2;
	assign net_1 = q_4;

	Latch latch_4
	(
		.rst(rst),
		.le(net_3),
		.d(net_0),
		.q(q_4)
	);

	assign net_2 = q_5;

	Latch latch_5
	(
		.rst(rst),
		.le(net_4),
		.d(net_1),
		.q(q_5)
	);

	LC lc_6
	(
		.rst(rst),
		.le(le_lc_6),
		.lr(net_7),
		.la(net_8),
		.rr(net_5),
		.ra(net_6)
	);

	assign net_3 = le_lc_6;

	LC lc_7
	(
		.rst(rst),
		.le(le_lc_7),
		.lr(net_5),
		.la(net_6),
		.rr(net_-1),
		.ra(net_-1)
	);

	assign net_4 = le_lc_7;

	assign net_7 = lr_a_i;
	assign la_a_i = net_8;
endmodule
