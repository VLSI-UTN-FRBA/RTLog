module fifo_8b_8d
	(
		input wire rst,
		input wire [7:0] din,
		output wire [7:0] dout,
		input wire lr_r1,
		output wire la_r1,
		output wire rr_r8,
		input wire ra_r8,
	);

	wire q_18;
	wire q_19;
	wire q_20;
	wire q_21;
	wire q_22;
	wire q_23;
	wire q_24;
	wire q_25;
	wire q_26;
	wire q_27;
	wire q_28;
	wire q_29;
	wire q_30;
	wire q_31;
	wire q_32;
	wire q_33;
	wire q_34;
	wire q_35;
	wire q_36;
	wire q_37;
	wire q_38;
	wire q_39;
	wire q_40;
	wire q_41;
	wire q_42;
	wire q_43;
	wire q_44;
	wire q_45;
	wire q_46;
	wire q_47;
	wire q_48;
	wire q_49;
	wire q_50;
	wire q_51;
	wire q_52;
	wire q_53;
	wire q_54;
	wire q_55;
	wire q_56;
	wire q_57;
	wire q_58;
	wire q_59;
	wire q_60;
	wire q_61;
	wire q_62;
	wire q_63;
	wire q_64;
	wire q_65;
	wire q_66;
	wire q_67;
	wire q_68;
	wire q_69;
	wire q_70;
	wire q_71;
	wire q_72;
	wire q_73;
	wire q_74;
	wire q_75;
	wire q_76;
	wire q_77;
	wire q_78;
	wire q_79;
	wire q_80;
	wire q_81;
	wire le_lc_82;
	wire le_lc_83;
	wire le_lc_84;
	wire le_lc_85;
	wire le_lc_86;
	wire le_lc_87;
	wire le_lc_88;
	wire le_lc_89;
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
	wire net_92;
	wire net_93;
	wire net_94;
	wire net_95;
	wire net_96;
	wire net_97;
	wire net_98;
	wire net_99;
	wire net_100;
	wire net_101;
	wire net_102;
	wire net_103;
	wire net_104;
	wire net_105;
	wire net_106;
	wire net_107;
	wire net_108;
	wire net_109;
	wire net_110;
	wire net_111;
	wire net_112;
	wire net_113;
	wire net_114;
	wire net_115;
	wire net_116;
	wire net_117;
	wire net_118;
	wire net_119;
	wire net_120;
	wire net_121;
	wire net_122;
	wire net_123;
	wire net_124;
	wire net_125;
	wire net_126;
	wire net_127;
	wire net_128;
	wire net_129;
	wire net_130;
	wire net_131;
	wire net_132;
	wire net_133;
	wire net_134;
	wire net_135;
	wire net_136;
	wire net_137;
	wire net_138;
	wire net_139;
	wire net_140;
	wire net_141;
	wire net_142;
	wire net_143;
	wire net_144;
	wire net_145;
	wire net_146;
	wire net_147;
	wire net_148;
	wire net_149;
	wire net_150;
	wire net_151;

	assign net_0 = din[0];
	assign net_1 = din[1];
	assign net_2 = din[2];
	assign net_3 = din[3];
	assign net_4 = din[4];
	assign net_5 = din[5];
	assign net_6 = din[6];
	assign net_7 = din[7];
	assign dout[0] = net_64;
	assign dout[1] = net_65;
	assign dout[2] = net_66;
	assign dout[3] = net_67;
	assign dout[4] = net_68;
	assign dout[5] = net_69;
	assign dout[6] = net_70;
	assign dout[7] = net_71;
	assign net_8 = q_18;

	Latch latch_18
	(
		.rst(rst),
		.le(net_72),
		.d(net_0),
		.q(q_18)
	);

	assign net_9 = q_19;

	Latch latch_19
	(
		.rst(rst),
		.le(net_73),
		.d(net_1),
		.q(q_19)
	);

	assign net_10 = q_20;

	Latch latch_20
	(
		.rst(rst),
		.le(net_74),
		.d(net_2),
		.q(q_20)
	);

	assign net_11 = q_21;

	Latch latch_21
	(
		.rst(rst),
		.le(net_75),
		.d(net_3),
		.q(q_21)
	);

	assign net_12 = q_22;

	Latch latch_22
	(
		.rst(rst),
		.le(net_76),
		.d(net_4),
		.q(q_22)
	);

	assign net_13 = q_23;

	Latch latch_23
	(
		.rst(rst),
		.le(net_77),
		.d(net_5),
		.q(q_23)
	);

	assign net_14 = q_24;

	Latch latch_24
	(
		.rst(rst),
		.le(net_78),
		.d(net_6),
		.q(q_24)
	);

	assign net_15 = q_25;

	Latch latch_25
	(
		.rst(rst),
		.le(net_79),
		.d(net_7),
		.q(q_25)
	);

	assign net_16 = q_26;

	Latch latch_26
	(
		.rst(rst),
		.le(net_80),
		.d(net_8),
		.q(q_26)
	);

	assign net_17 = q_27;

	Latch latch_27
	(
		.rst(rst),
		.le(net_81),
		.d(net_9),
		.q(q_27)
	);

	assign net_18 = q_28;

	Latch latch_28
	(
		.rst(rst),
		.le(net_82),
		.d(net_10),
		.q(q_28)
	);

	assign net_19 = q_29;

	Latch latch_29
	(
		.rst(rst),
		.le(net_83),
		.d(net_11),
		.q(q_29)
	);

	assign net_20 = q_30;

	Latch latch_30
	(
		.rst(rst),
		.le(net_84),
		.d(net_12),
		.q(q_30)
	);

	assign net_21 = q_31;

	Latch latch_31
	(
		.rst(rst),
		.le(net_85),
		.d(net_13),
		.q(q_31)
	);

	assign net_22 = q_32;

	Latch latch_32
	(
		.rst(rst),
		.le(net_86),
		.d(net_14),
		.q(q_32)
	);

	assign net_23 = q_33;

	Latch latch_33
	(
		.rst(rst),
		.le(net_87),
		.d(net_15),
		.q(q_33)
	);

	assign net_24 = q_34;

	Latch latch_34
	(
		.rst(rst),
		.le(net_88),
		.d(net_16),
		.q(q_34)
	);

	assign net_25 = q_35;

	Latch latch_35
	(
		.rst(rst),
		.le(net_89),
		.d(net_17),
		.q(q_35)
	);

	assign net_26 = q_36;

	Latch latch_36
	(
		.rst(rst),
		.le(net_90),
		.d(net_18),
		.q(q_36)
	);

	assign net_27 = q_37;

	Latch latch_37
	(
		.rst(rst),
		.le(net_91),
		.d(net_19),
		.q(q_37)
	);

	assign net_28 = q_38;

	Latch latch_38
	(
		.rst(rst),
		.le(net_92),
		.d(net_20),
		.q(q_38)
	);

	assign net_29 = q_39;

	Latch latch_39
	(
		.rst(rst),
		.le(net_93),
		.d(net_21),
		.q(q_39)
	);

	assign net_30 = q_40;

	Latch latch_40
	(
		.rst(rst),
		.le(net_94),
		.d(net_22),
		.q(q_40)
	);

	assign net_31 = q_41;

	Latch latch_41
	(
		.rst(rst),
		.le(net_95),
		.d(net_23),
		.q(q_41)
	);

	assign net_32 = q_42;

	Latch latch_42
	(
		.rst(rst),
		.le(net_96),
		.d(net_24),
		.q(q_42)
	);

	assign net_33 = q_43;

	Latch latch_43
	(
		.rst(rst),
		.le(net_97),
		.d(net_25),
		.q(q_43)
	);

	assign net_34 = q_44;

	Latch latch_44
	(
		.rst(rst),
		.le(net_98),
		.d(net_26),
		.q(q_44)
	);

	assign net_35 = q_45;

	Latch latch_45
	(
		.rst(rst),
		.le(net_99),
		.d(net_27),
		.q(q_45)
	);

	assign net_36 = q_46;

	Latch latch_46
	(
		.rst(rst),
		.le(net_100),
		.d(net_28),
		.q(q_46)
	);

	assign net_37 = q_47;

	Latch latch_47
	(
		.rst(rst),
		.le(net_101),
		.d(net_29),
		.q(q_47)
	);

	assign net_38 = q_48;

	Latch latch_48
	(
		.rst(rst),
		.le(net_102),
		.d(net_30),
		.q(q_48)
	);

	assign net_39 = q_49;

	Latch latch_49
	(
		.rst(rst),
		.le(net_103),
		.d(net_31),
		.q(q_49)
	);

	assign net_40 = q_50;

	Latch latch_50
	(
		.rst(rst),
		.le(net_104),
		.d(net_32),
		.q(q_50)
	);

	assign net_41 = q_51;

	Latch latch_51
	(
		.rst(rst),
		.le(net_105),
		.d(net_33),
		.q(q_51)
	);

	assign net_42 = q_52;

	Latch latch_52
	(
		.rst(rst),
		.le(net_106),
		.d(net_34),
		.q(q_52)
	);

	assign net_43 = q_53;

	Latch latch_53
	(
		.rst(rst),
		.le(net_107),
		.d(net_35),
		.q(q_53)
	);

	assign net_44 = q_54;

	Latch latch_54
	(
		.rst(rst),
		.le(net_108),
		.d(net_36),
		.q(q_54)
	);

	assign net_45 = q_55;

	Latch latch_55
	(
		.rst(rst),
		.le(net_109),
		.d(net_37),
		.q(q_55)
	);

	assign net_46 = q_56;

	Latch latch_56
	(
		.rst(rst),
		.le(net_110),
		.d(net_38),
		.q(q_56)
	);

	assign net_47 = q_57;

	Latch latch_57
	(
		.rst(rst),
		.le(net_111),
		.d(net_39),
		.q(q_57)
	);

	assign net_48 = q_58;

	Latch latch_58
	(
		.rst(rst),
		.le(net_112),
		.d(net_40),
		.q(q_58)
	);

	assign net_49 = q_59;

	Latch latch_59
	(
		.rst(rst),
		.le(net_113),
		.d(net_41),
		.q(q_59)
	);

	assign net_50 = q_60;

	Latch latch_60
	(
		.rst(rst),
		.le(net_114),
		.d(net_42),
		.q(q_60)
	);

	assign net_51 = q_61;

	Latch latch_61
	(
		.rst(rst),
		.le(net_115),
		.d(net_43),
		.q(q_61)
	);

	assign net_52 = q_62;

	Latch latch_62
	(
		.rst(rst),
		.le(net_116),
		.d(net_44),
		.q(q_62)
	);

	assign net_53 = q_63;

	Latch latch_63
	(
		.rst(rst),
		.le(net_117),
		.d(net_45),
		.q(q_63)
	);

	assign net_54 = q_64;

	Latch latch_64
	(
		.rst(rst),
		.le(net_118),
		.d(net_46),
		.q(q_64)
	);

	assign net_55 = q_65;

	Latch latch_65
	(
		.rst(rst),
		.le(net_119),
		.d(net_47),
		.q(q_65)
	);

	assign net_56 = q_66;

	Latch latch_66
	(
		.rst(rst),
		.le(net_120),
		.d(net_48),
		.q(q_66)
	);

	assign net_57 = q_67;

	Latch latch_67
	(
		.rst(rst),
		.le(net_121),
		.d(net_49),
		.q(q_67)
	);

	assign net_58 = q_68;

	Latch latch_68
	(
		.rst(rst),
		.le(net_122),
		.d(net_50),
		.q(q_68)
	);

	assign net_59 = q_69;

	Latch latch_69
	(
		.rst(rst),
		.le(net_123),
		.d(net_51),
		.q(q_69)
	);

	assign net_60 = q_70;

	Latch latch_70
	(
		.rst(rst),
		.le(net_124),
		.d(net_52),
		.q(q_70)
	);

	assign net_61 = q_71;

	Latch latch_71
	(
		.rst(rst),
		.le(net_125),
		.d(net_53),
		.q(q_71)
	);

	assign net_62 = q_72;

	Latch latch_72
	(
		.rst(rst),
		.le(net_126),
		.d(net_54),
		.q(q_72)
	);

	assign net_63 = q_73;

	Latch latch_73
	(
		.rst(rst),
		.le(net_127),
		.d(net_55),
		.q(q_73)
	);

	assign net_64 = q_74;

	Latch latch_74
	(
		.rst(rst),
		.le(net_128),
		.d(net_56),
		.q(q_74)
	);

	assign net_65 = q_75;

	Latch latch_75
	(
		.rst(rst),
		.le(net_129),
		.d(net_57),
		.q(q_75)
	);

	assign net_66 = q_76;

	Latch latch_76
	(
		.rst(rst),
		.le(net_130),
		.d(net_58),
		.q(q_76)
	);

	assign net_67 = q_77;

	Latch latch_77
	(
		.rst(rst),
		.le(net_131),
		.d(net_59),
		.q(q_77)
	);

	assign net_68 = q_78;

	Latch latch_78
	(
		.rst(rst),
		.le(net_132),
		.d(net_60),
		.q(q_78)
	);

	assign net_69 = q_79;

	Latch latch_79
	(
		.rst(rst),
		.le(net_133),
		.d(net_61),
		.q(q_79)
	);

	assign net_70 = q_80;

	Latch latch_80
	(
		.rst(rst),
		.le(net_134),
		.d(net_62),
		.q(q_80)
	);

	assign net_71 = q_81;

	Latch latch_81
	(
		.rst(rst),
		.le(net_135),
		.d(net_63),
		.q(q_81)
	);

	LC lc_82
	(
		.rst(rst),
		.le(le_lc_82),
		.lr(net_150),
		.la(net_151),
		.rr(net_136),
		.ra(net_137)
	);

	assign net_72 = le_lc_82;
	assign net_73 = le_lc_82;
	assign net_74 = le_lc_82;
	assign net_75 = le_lc_82;
	assign net_76 = le_lc_82;
	assign net_77 = le_lc_82;
	assign net_78 = le_lc_82;
	assign net_79 = le_lc_82;

	LC lc_83
	(
		.rst(rst),
		.le(le_lc_83),
		.lr(net_136),
		.la(net_137),
		.rr(net_138),
		.ra(net_139)
	);

	assign net_80 = le_lc_83;
	assign net_81 = le_lc_83;
	assign net_82 = le_lc_83;
	assign net_83 = le_lc_83;
	assign net_84 = le_lc_83;
	assign net_85 = le_lc_83;
	assign net_86 = le_lc_83;
	assign net_87 = le_lc_83;

	LC lc_84
	(
		.rst(rst),
		.le(le_lc_84),
		.lr(net_138),
		.la(net_139),
		.rr(net_140),
		.ra(net_141)
	);

	assign net_88 = le_lc_84;
	assign net_89 = le_lc_84;
	assign net_90 = le_lc_84;
	assign net_91 = le_lc_84;
	assign net_92 = le_lc_84;
	assign net_93 = le_lc_84;
	assign net_94 = le_lc_84;
	assign net_95 = le_lc_84;

	LC lc_85
	(
		.rst(rst),
		.le(le_lc_85),
		.lr(net_140),
		.la(net_141),
		.rr(net_142),
		.ra(net_143)
	);

	assign net_96 = le_lc_85;
	assign net_97 = le_lc_85;
	assign net_98 = le_lc_85;
	assign net_99 = le_lc_85;
	assign net_100 = le_lc_85;
	assign net_101 = le_lc_85;
	assign net_102 = le_lc_85;
	assign net_103 = le_lc_85;

	LC lc_86
	(
		.rst(rst),
		.le(le_lc_86),
		.lr(net_142),
		.la(net_143),
		.rr(net_144),
		.ra(net_145)
	);

	assign net_104 = le_lc_86;
	assign net_105 = le_lc_86;
	assign net_106 = le_lc_86;
	assign net_107 = le_lc_86;
	assign net_108 = le_lc_86;
	assign net_109 = le_lc_86;
	assign net_110 = le_lc_86;
	assign net_111 = le_lc_86;

	LC lc_87
	(
		.rst(rst),
		.le(le_lc_87),
		.lr(net_144),
		.la(net_145),
		.rr(net_146),
		.ra(net_147)
	);

	assign net_112 = le_lc_87;
	assign net_113 = le_lc_87;
	assign net_114 = le_lc_87;
	assign net_115 = le_lc_87;
	assign net_116 = le_lc_87;
	assign net_117 = le_lc_87;
	assign net_118 = le_lc_87;
	assign net_119 = le_lc_87;

	LC lc_88
	(
		.rst(rst),
		.le(le_lc_88),
		.lr(net_146),
		.la(net_147),
		.rr(net_148),
		.ra(net_149)
	);

	assign net_120 = le_lc_88;
	assign net_121 = le_lc_88;
	assign net_122 = le_lc_88;
	assign net_123 = le_lc_88;
	assign net_124 = le_lc_88;
	assign net_125 = le_lc_88;
	assign net_126 = le_lc_88;
	assign net_127 = le_lc_88;

	LC lc_89
	(
		.rst(rst),
		.le(le_lc_89),
		.lr(net_148),
		.la(net_149),
		.rr(rr_r8),
		.ra(ra_r8)
	);

	assign net_128 = le_lc_89;
	assign net_129 = le_lc_89;
	assign net_130 = le_lc_89;
	assign net_131 = le_lc_89;
	assign net_132 = le_lc_89;
	assign net_133 = le_lc_89;
	assign net_134 = le_lc_89;
	assign net_135 = le_lc_89;

	assign net_150 = lr_r1;
	assign la_r1 = net_151;
endmodule
