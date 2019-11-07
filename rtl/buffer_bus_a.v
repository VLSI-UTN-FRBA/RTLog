module buffer_bus
	(
		input wire rst,
		input wire [3:0] a,
		output wire [3:0] b,
		input wire lr_a_i,
		output wire la_a_i,
		output wire rr_b_i,
		input wire ra_b_i,
	);

	wire q_10;
	wire q_11;
	wire q_12;
	wire q_13;
	wire q_14;
	wire q_15;
	wire q_16;
	wire q_17;
	wire le_lc_18;
	wire le_lc_19;
	wire net_0;
	wire net_1;
	wire net_2;
	wire net_3;
	wire net_4;
	wire net_5;
	wire net_6;
	wire net_7;
	wire net_8;
	wire net_9;
	wire net_10;
	wire net_11;
	wire net_12;
	wire net_13;
	wire net_14;
	wire net_15;
	wire net_16;
	wire net_17;
	wire net_18;
	wire net_19;
	wire net_20;
	wire net_21;
	wire net_22;
	wire net_23;

	assign net_0 = a[0];
	assign net_1 = a[1];
	assign net_2 = a[2];
	assign net_3 = a[3];
	assign b[0] = net_8;
	assign b[1] = net_9;
	assign b[2] = net_10;
	assign b[3] = net_11;
	assign net_4 = q_10;

	Latch latch_10
	(
		.rst(rst),
		.le(net_12),
		.d(net_0),
		.q(q_10)
	);

	assign net_5 = q_11;

	Latch latch_11
	(
		.rst(rst),
		.le(net_13),
		.d(net_1),
		.q(q_11)
	);

	assign net_6 = q_12;

	Latch latch_12
	(
		.rst(rst),
		.le(net_14),
		.d(net_2),
		.q(q_12)
	);

	assign net_7 = q_13;

	Latch latch_13
	(
		.rst(rst),
		.le(net_15),
		.d(net_3),
		.q(q_13)
	);

	assign net_8 = q_14;

	Latch latch_14
	(
		.rst(rst),
		.le(net_16),
		.d(net_4),
		.q(q_14)
	);

	assign net_9 = q_15;

	Latch latch_15
	(
		.rst(rst),
		.le(net_17),
		.d(net_5),
		.q(q_15)
	);

	assign net_10 = q_16;

	Latch latch_16
	(
		.rst(rst),
		.le(net_18),
		.d(net_6),
		.q(q_16)
	);

	assign net_11 = q_17;

	Latch latch_17
	(
		.rst(rst),
		.le(net_19),
		.d(net_7),
		.q(q_17)
	);

	LC lc_18
	(
		.rst(rst),
		.le(le_lc_18),
		.lr(net_22),
		.la(net_23),
		.rr(net_20),
		.ra(net_21)
	);

	assign net_12 = le_lc_18;
	assign net_13 = le_lc_18;
	assign net_14 = le_lc_18;
	assign net_15 = le_lc_18;

	LC lc_19
	(
		.rst(rst),
		.le(le_lc_19),
		.lr(net_20),
		.la(net_21),
		.rr(rr_b_i),
		.ra(ra_b_i)
	);

	assign net_16 = le_lc_19;
	assign net_17 = le_lc_19;
	assign net_18 = le_lc_19;
	assign net_19 = le_lc_19;

	assign net_22 = lr_a_i;
	assign la_a_i = net_23;
endmodule
