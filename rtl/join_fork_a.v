module join_fork
	(
		input wire rst,
		input wire i_gamma,
		input wire i_delta,
		input wire i_epsilon,
		output reg a,
		output reg b,
		input wire lr_c,
		output wire la_c,
		input wire lr_d,
		output wire la_d,
		input wire lr_e,
		output wire la_e,
		output wire rr_a,
		input wire ra_a,
		output wire rr_b,
		input wire ra_b,
	);

	wire q_6;
	wire q_8;
	wire q_9;
	wire q_10;
	wire q_11;
	wire and_12;
	wire and_13;
	wire or_14;
	wire le_lc_15;
	wire le_lc_16;
	wire le_lc_17;
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
	wire net_24;
	wire net_25;
	wire net_26;
	wire net_27;
	wire net_28;
	wire net_29;
	wire net_30;
	wire net_31;
	wire net_32;
	wire net_33;
	wire net_34;
	wire net_35;
	wire net_36;
	wire net_37;
	wire net_38;
	wire net_39;
	wire net_40;
	wire net_41;
	wire net_42;
	wire net_43;
	wire net_44;
	wire net_45;
	wire net_46;
	wire net_47;

	assign net_2 = i_gamma;
	assign net_3 = i_delta;
	assign net_4 = i_epsilon;
	assign a = net_0;
	assign net_0 = q_6;

	Latch latch_6
	(
		.rst(rst),
		.le(net_13),
		.d(net_9),
		.q(q_6)
	);

	assign b = net_1;
	assign net_1 = q_8;

	Latch latch_8
	(
		.rst(rst),
		.le(net_14),
		.d(net_12),
		.q(q_8)
	);

	assign net_5 = q_9;
	assign net_10 = q_9;

	Latch latch_9
	(
		.rst(rst),
		.le(net_15),
		.d(net_2),
		.q(q_9)
	);

	assign net_6 = q_10;

	Latch latch_10
	(
		.rst(rst),
		.le(net_16),
		.d(net_3),
		.q(q_10)
	);

	assign net_8 = q_11;
	assign net_11 = q_11;

	Latch latch_11
	(
		.rst(rst),
		.le(net_17),
		.d(net_4),
		.q(q_11)
	);

	assign net_7 = and_12;

	assign and_12 = net_5 & net_6;

	assign net_9 = and_13;

	assign and_13 = net_7 & net_8;

	assign net_12 = or_14;

	assign or_14 = net_10 | net_11;

	LC lc_15
	(
		.rst(rst),
		.le(le_lc_15),
		.lr(net_19),
		.la(net_18),
		.rr(net_44),
		.ra(net_45)
	);

	assign net_13 = le_lc_15;

	LC lc_16
	(
		.rst(rst),
		.le(le_lc_16),
		.lr(net_23),
		.la(net_22),
		.rr(net_46),
		.ra(net_47)
	);

	assign net_14 = le_lc_16;

	LC lc_17
	(
		.rst(rst),
		.le(le_lc_17),
		.lr(net_38),
		.la(net_39),
		.rr(net_24),
		.ra(net_25)
	);

	assign net_15 = le_lc_17;

	LC lc_18
	(
		.rst(rst),
		.le(le_lc_18),
		.lr(net_40),
		.la(net_41),
		.rr(net_32),
		.ra(net_33)
	);

	assign net_16 = le_lc_18;

	LC lc_19
	(
		.rst(rst),
		.le(le_lc_19),
		.lr(net_42),
		.la(net_43),
		.rr(net_26),
		.ra(net_27)
	);

	assign net_17 = le_lc_19;

	JC jc_20
	(
		.rst(rst),
		.lr1(net_21),
		.la1(net_20),
		.lr2(net_32),
		.la2(net_33),
		.rr(net_19),
		.ra(net_18)
	);


	JC jc_21
	(
		.rst(rst),
		.lr1(net_28),
		.la1(net_29),
		.lr2(net_34),
		.la2(net_35),
		.rr(net_21),
		.ra(net_20)
	);


	JC jc_22
	(
		.rst(rst),
		.lr1(net_30),
		.la1(net_31),
		.lr2(net_36),
		.la2(net_37),
		.rr(net_23),
		.ra(net_22)
	);


	FC fc_23
	(
		.rst(rst),
		.lr(net_24),
		.la(net_25),
		.rr1(net_28),
		.ra1(net_29),
		.rr2(net_30),
		.ra2(net_31)
	);


	FC fc_24
	(
		.rst(rst),
		.lr(net_26),
		.la(net_27),
		.rr1(net_34),
		.ra1(net_35),
		.rr2(net_36),
		.ra2(net_37)
	);


	assign net_38 = lr_c;
	assign la_c = net_39;
	assign net_40 = lr_d;
	assign la_d = net_41;
	assign net_42 = lr_e;
	assign la_e = net_43;
	assign rr_a = net_44;
	assign net_45 = ra_a;
	assign rr_b = net_46;
	assign net_47 = ra_b;
endmodule
