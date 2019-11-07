module join_fork_big
	(
		input wire rst,
		input wire i_w,
		input wire i_x,
		input wire i_y,
		input wire i_z,
		output reg a,
		output reg b,
		output reg d,
		output reg c,
		input wire lr_w,
		output wire la_w,
		input wire lr_x,
		output wire la_x,
		input wire lr_y,
		output wire la_y,
		input wire lr_z,
		output wire la_z,
		output wire rr_a,
		input wire ra_a,
		output wire rr_b,
		input wire ra_b,
		output wire rr_d,
		input wire ra_d,
		output wire rr_c,
		input wire ra_c,
	);

	wire q_7;
	wire q_9;
	wire q_11;
	wire q_13;
	wire q_14;
	wire q_15;
	wire q_16;
	wire q_17;
	wire and_18;
	wire and_19;
	wire and_20;
	wire and_21;
	wire and_22;
	wire and_23;
	wire le_lc_24;
	wire le_lc_25;
	wire le_lc_26;
	wire le_lc_27;
	wire le_lc_28;
	wire le_lc_29;
	wire le_lc_30;
	wire le_lc_31;
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
	wire net_48;
	wire net_49;
	wire net_50;
	wire net_51;
	wire net_52;
	wire net_53;
	wire net_54;
	wire net_55;
	wire net_56;
	wire net_57;
	wire net_58;
	wire net_59;
	wire net_60;
	wire net_61;
	wire net_62;
	wire net_63;
	wire net_64;
	wire net_65;
	wire net_66;
	wire net_67;
	wire net_68;
	wire net_69;
	wire net_70;
	wire net_71;
	wire net_72;
	wire net_73;
	wire net_74;
	wire net_75;
	wire net_76;
	wire net_77;
	wire net_78;
	wire net_79;
	wire net_80;
	wire net_81;
	wire net_82;
	wire net_83;
	wire net_84;
	wire net_85;
	wire net_86;
	wire net_87;
	wire net_88;
	wire net_89;
	wire net_90;
	wire net_91;

	assign net_4 = i_w;
	assign net_5 = i_x;
	assign net_6 = i_y;
	assign net_7 = i_z;
	assign a = net_0;
	assign net_0 = q_7;

	Latch latch_7
	(
		.rst(rst),
		.le(net_24),
		.d(net_8),
		.q(q_7)
	);

	assign b = net_1;
	assign net_1 = q_9;

	Latch latch_9
	(
		.rst(rst),
		.le(net_25),
		.d(net_11),
		.q(q_9)
	);

	assign d = net_2;
	assign net_2 = q_11;

	Latch latch_11
	(
		.rst(rst),
		.le(net_26),
		.d(net_23),
		.q(q_11)
	);

	assign c = net_3;
	assign net_3 = q_13;

	Latch latch_13
	(
		.rst(rst),
		.le(net_27),
		.d(net_16),
		.q(q_13)
	);

	assign net_8 = q_14;
	assign net_9 = q_14;
	assign net_12 = q_14;
	assign net_17 = q_14;

	Latch latch_14
	(
		.rst(rst),
		.le(net_28),
		.d(net_4),
		.q(q_14)
	);

	assign net_10 = q_15;
	assign net_13 = q_15;
	assign net_18 = q_15;

	Latch latch_15
	(
		.rst(rst),
		.le(net_29),
		.d(net_5),
		.q(q_15)
	);

	assign net_15 = q_16;
	assign net_20 = q_16;

	Latch latch_16
	(
		.rst(rst),
		.le(net_30),
		.d(net_6),
		.q(q_16)
	);

	assign net_22 = q_17;

	Latch latch_17
	(
		.rst(rst),
		.le(net_31),
		.d(net_7),
		.q(q_17)
	);

	assign net_11 = and_18;

	assign and_18 = net_9 & net_10;

	assign net_14 = and_19;

	assign and_19 = net_12 & net_13;

	assign net_16 = and_20;

	assign and_20 = net_14 & net_15;

	assign net_19 = and_21;

	assign and_21 = net_17 & net_18;

	assign net_21 = and_22;

	assign and_22 = net_19 & net_20;

	assign net_23 = and_23;

	assign and_23 = net_21 & net_22;

	LC lc_24
	(
		.rst(rst),
		.le(le_lc_24),
		.lr(net_56),
		.la(net_57),
		.rr(net_84),
		.ra(net_85)
	);

	assign net_24 = le_lc_24;

	LC lc_25
	(
		.rst(rst),
		.le(le_lc_25),
		.lr(net_33),
		.la(net_32),
		.rr(net_86),
		.ra(net_87)
	);

	assign net_25 = le_lc_25;

	LC lc_26
	(
		.rst(rst),
		.le(le_lc_26),
		.lr(net_35),
		.la(net_34),
		.rr(net_88),
		.ra(net_89)
	);

	assign net_26 = le_lc_26;

	LC lc_27
	(
		.rst(rst),
		.le(le_lc_27),
		.lr(net_41),
		.la(net_40),
		.rr(net_90),
		.ra(net_91)
	);

	assign net_27 = le_lc_27;

	LC lc_28
	(
		.rst(rst),
		.le(le_lc_28),
		.lr(net_76),
		.la(net_77),
		.rr(net_44),
		.ra(net_45)
	);

	assign net_28 = le_lc_28;

	LC lc_29
	(
		.rst(rst),
		.le(le_lc_29),
		.lr(net_78),
		.la(net_79),
		.rr(net_50),
		.ra(net_51)
	);

	assign net_29 = le_lc_29;

	LC lc_30
	(
		.rst(rst),
		.le(le_lc_30),
		.lr(net_80),
		.la(net_81),
		.rr(net_54),
		.ra(net_55)
	);

	assign net_30 = le_lc_30;

	LC lc_31
	(
		.rst(rst),
		.le(le_lc_31),
		.lr(net_82),
		.la(net_83),
		.rr(net_74),
		.ra(net_75)
	);

	assign net_31 = le_lc_31;

	JC jc_32
	(
		.rst(rst),
		.lr1(net_58),
		.la1(net_59),
		.lr2(net_64),
		.la2(net_65),
		.rr(net_33),
		.ra(net_32)
	);


	JC jc_33
	(
		.rst(rst),
		.lr1(net_37),
		.la1(net_36),
		.lr2(net_39),
		.la2(net_38),
		.rr(net_35),
		.ra(net_34)
	);


	JC jc_34
	(
		.rst(rst),
		.lr1(net_62),
		.la1(net_63),
		.lr2(net_72),
		.la2(net_73),
		.rr(net_37),
		.ra(net_36)
	);


	JC jc_35
	(
		.rst(rst),
		.lr1(net_68),
		.la1(net_69),
		.lr2(net_74),
		.la2(net_75),
		.rr(net_39),
		.ra(net_38)
	);


	JC jc_36
	(
		.rst(rst),
		.lr1(net_43),
		.la1(net_42),
		.lr2(net_66),
		.la2(net_67),
		.rr(net_41),
		.ra(net_40)
	);


	JC jc_37
	(
		.rst(rst),
		.lr1(net_60),
		.la1(net_61),
		.lr2(net_70),
		.la2(net_71),
		.rr(net_43),
		.ra(net_42)
	);


	FC fc_38
	(
		.rst(rst),
		.lr(net_44),
		.la(net_45),
		.rr1(net_46),
		.ra1(net_47),
		.rr2(net_48),
		.ra2(net_49)
	);


	FC fc_39
	(
		.rst(rst),
		.lr(net_46),
		.la(net_47),
		.rr1(net_56),
		.ra1(net_57),
		.rr2(net_60),
		.ra2(net_61)
	);


	FC fc_40
	(
		.rst(rst),
		.lr(net_48),
		.la(net_49),
		.rr1(net_58),
		.ra1(net_59),
		.rr2(net_62),
		.ra2(net_63)
	);


	FC fc_41
	(
		.rst(rst),
		.lr(net_50),
		.la(net_51),
		.rr1(net_52),
		.ra1(net_53),
		.rr2(net_66),
		.ra2(net_67)
	);


	FC fc_42
	(
		.rst(rst),
		.lr(net_52),
		.la(net_53),
		.rr1(net_64),
		.ra1(net_65),
		.rr2(net_68),
		.ra2(net_69)
	);


	FC fc_43
	(
		.rst(rst),
		.lr(net_54),
		.la(net_55),
		.rr1(net_70),
		.ra1(net_71),
		.rr2(net_72),
		.ra2(net_73)
	);


	assign net_76 = lr_w;
	assign la_w = net_77;
	assign net_78 = lr_x;
	assign la_x = net_79;
	assign net_80 = lr_y;
	assign la_y = net_81;
	assign net_82 = lr_z;
	assign la_z = net_83;
	assign rr_a = net_84;
	assign net_85 = ra_a;
	assign rr_b = net_86;
	assign net_87 = ra_b;
	assign rr_d = net_88;
	assign net_89 = ra_d;
	assign rr_c = net_90;
	assign net_91 = ra_c;
endmodule
