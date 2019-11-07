module fifo_8b_8d
	(
		input wire rst,
		input wire clk,
		input wire [7:0] din,
		output wire [7:0] dout,
	);

	reg q_18;
	reg q_19;
	reg q_20;
	reg q_21;
	reg q_22;
	reg q_23;
	reg q_24;
	reg q_25;
	reg q_26;
	reg q_27;
	reg q_28;
	reg q_29;
	reg q_30;
	reg q_31;
	reg q_32;
	reg q_33;
	reg q_34;
	reg q_35;
	reg q_36;
	reg q_37;
	reg q_38;
	reg q_39;
	reg q_40;
	reg q_41;
	reg q_42;
	reg q_43;
	reg q_44;
	reg q_45;
	reg q_46;
	reg q_47;
	reg q_48;
	reg q_49;
	reg q_50;
	reg q_51;
	reg q_52;
	reg q_53;
	reg q_54;
	reg q_55;
	reg q_56;
	reg q_57;
	reg q_58;
	reg q_59;
	reg q_60;
	reg q_61;
	reg q_62;
	reg q_63;
	reg q_64;
	reg q_65;
	reg q_66;
	reg q_67;
	reg q_68;
	reg q_69;
	reg q_70;
	reg q_71;
	reg q_72;
	reg q_73;
	reg q_74;
	reg q_75;
	reg q_76;
	reg q_77;
	reg q_78;
	reg q_79;
	reg q_80;
	reg q_81;
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

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_18 = 1'b0;
		end
		else
		begin
			q_18 = net_0;
		end
	end

	assign net_9 = q_19;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_19 = 1'b0;
		end
		else
		begin
			q_19 = net_1;
		end
	end

	assign net_10 = q_20;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_20 = 1'b0;
		end
		else
		begin
			q_20 = net_2;
		end
	end

	assign net_11 = q_21;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_21 = 1'b0;
		end
		else
		begin
			q_21 = net_3;
		end
	end

	assign net_12 = q_22;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_22 = 1'b0;
		end
		else
		begin
			q_22 = net_4;
		end
	end

	assign net_13 = q_23;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_23 = 1'b0;
		end
		else
		begin
			q_23 = net_5;
		end
	end

	assign net_14 = q_24;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_24 = 1'b0;
		end
		else
		begin
			q_24 = net_6;
		end
	end

	assign net_15 = q_25;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_25 = 1'b0;
		end
		else
		begin
			q_25 = net_7;
		end
	end

	assign net_16 = q_26;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_26 = 1'b0;
		end
		else
		begin
			q_26 = net_8;
		end
	end

	assign net_17 = q_27;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_27 = 1'b0;
		end
		else
		begin
			q_27 = net_9;
		end
	end

	assign net_18 = q_28;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_28 = 1'b0;
		end
		else
		begin
			q_28 = net_10;
		end
	end

	assign net_19 = q_29;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_29 = 1'b0;
		end
		else
		begin
			q_29 = net_11;
		end
	end

	assign net_20 = q_30;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_30 = 1'b0;
		end
		else
		begin
			q_30 = net_12;
		end
	end

	assign net_21 = q_31;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_31 = 1'b0;
		end
		else
		begin
			q_31 = net_13;
		end
	end

	assign net_22 = q_32;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_32 = 1'b0;
		end
		else
		begin
			q_32 = net_14;
		end
	end

	assign net_23 = q_33;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_33 = 1'b0;
		end
		else
		begin
			q_33 = net_15;
		end
	end

	assign net_24 = q_34;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_34 = 1'b0;
		end
		else
		begin
			q_34 = net_16;
		end
	end

	assign net_25 = q_35;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_35 = 1'b0;
		end
		else
		begin
			q_35 = net_17;
		end
	end

	assign net_26 = q_36;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_36 = 1'b0;
		end
		else
		begin
			q_36 = net_18;
		end
	end

	assign net_27 = q_37;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_37 = 1'b0;
		end
		else
		begin
			q_37 = net_19;
		end
	end

	assign net_28 = q_38;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_38 = 1'b0;
		end
		else
		begin
			q_38 = net_20;
		end
	end

	assign net_29 = q_39;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_39 = 1'b0;
		end
		else
		begin
			q_39 = net_21;
		end
	end

	assign net_30 = q_40;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_40 = 1'b0;
		end
		else
		begin
			q_40 = net_22;
		end
	end

	assign net_31 = q_41;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_41 = 1'b0;
		end
		else
		begin
			q_41 = net_23;
		end
	end

	assign net_32 = q_42;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_42 = 1'b0;
		end
		else
		begin
			q_42 = net_24;
		end
	end

	assign net_33 = q_43;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_43 = 1'b0;
		end
		else
		begin
			q_43 = net_25;
		end
	end

	assign net_34 = q_44;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_44 = 1'b0;
		end
		else
		begin
			q_44 = net_26;
		end
	end

	assign net_35 = q_45;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_45 = 1'b0;
		end
		else
		begin
			q_45 = net_27;
		end
	end

	assign net_36 = q_46;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_46 = 1'b0;
		end
		else
		begin
			q_46 = net_28;
		end
	end

	assign net_37 = q_47;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_47 = 1'b0;
		end
		else
		begin
			q_47 = net_29;
		end
	end

	assign net_38 = q_48;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_48 = 1'b0;
		end
		else
		begin
			q_48 = net_30;
		end
	end

	assign net_39 = q_49;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_49 = 1'b0;
		end
		else
		begin
			q_49 = net_31;
		end
	end

	assign net_40 = q_50;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_50 = 1'b0;
		end
		else
		begin
			q_50 = net_32;
		end
	end

	assign net_41 = q_51;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_51 = 1'b0;
		end
		else
		begin
			q_51 = net_33;
		end
	end

	assign net_42 = q_52;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_52 = 1'b0;
		end
		else
		begin
			q_52 = net_34;
		end
	end

	assign net_43 = q_53;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_53 = 1'b0;
		end
		else
		begin
			q_53 = net_35;
		end
	end

	assign net_44 = q_54;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_54 = 1'b0;
		end
		else
		begin
			q_54 = net_36;
		end
	end

	assign net_45 = q_55;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_55 = 1'b0;
		end
		else
		begin
			q_55 = net_37;
		end
	end

	assign net_46 = q_56;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_56 = 1'b0;
		end
		else
		begin
			q_56 = net_38;
		end
	end

	assign net_47 = q_57;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_57 = 1'b0;
		end
		else
		begin
			q_57 = net_39;
		end
	end

	assign net_48 = q_58;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_58 = 1'b0;
		end
		else
		begin
			q_58 = net_40;
		end
	end

	assign net_49 = q_59;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_59 = 1'b0;
		end
		else
		begin
			q_59 = net_41;
		end
	end

	assign net_50 = q_60;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_60 = 1'b0;
		end
		else
		begin
			q_60 = net_42;
		end
	end

	assign net_51 = q_61;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_61 = 1'b0;
		end
		else
		begin
			q_61 = net_43;
		end
	end

	assign net_52 = q_62;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_62 = 1'b0;
		end
		else
		begin
			q_62 = net_44;
		end
	end

	assign net_53 = q_63;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_63 = 1'b0;
		end
		else
		begin
			q_63 = net_45;
		end
	end

	assign net_54 = q_64;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_64 = 1'b0;
		end
		else
		begin
			q_64 = net_46;
		end
	end

	assign net_55 = q_65;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_65 = 1'b0;
		end
		else
		begin
			q_65 = net_47;
		end
	end

	assign net_56 = q_66;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_66 = 1'b0;
		end
		else
		begin
			q_66 = net_48;
		end
	end

	assign net_57 = q_67;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_67 = 1'b0;
		end
		else
		begin
			q_67 = net_49;
		end
	end

	assign net_58 = q_68;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_68 = 1'b0;
		end
		else
		begin
			q_68 = net_50;
		end
	end

	assign net_59 = q_69;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_69 = 1'b0;
		end
		else
		begin
			q_69 = net_51;
		end
	end

	assign net_60 = q_70;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_70 = 1'b0;
		end
		else
		begin
			q_70 = net_52;
		end
	end

	assign net_61 = q_71;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_71 = 1'b0;
		end
		else
		begin
			q_71 = net_53;
		end
	end

	assign net_62 = q_72;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_72 = 1'b0;
		end
		else
		begin
			q_72 = net_54;
		end
	end

	assign net_63 = q_73;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_73 = 1'b0;
		end
		else
		begin
			q_73 = net_55;
		end
	end

	assign net_64 = q_74;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_74 = 1'b0;
		end
		else
		begin
			q_74 = net_56;
		end
	end

	assign net_65 = q_75;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_75 = 1'b0;
		end
		else
		begin
			q_75 = net_57;
		end
	end

	assign net_66 = q_76;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_76 = 1'b0;
		end
		else
		begin
			q_76 = net_58;
		end
	end

	assign net_67 = q_77;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_77 = 1'b0;
		end
		else
		begin
			q_77 = net_59;
		end
	end

	assign net_68 = q_78;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_78 = 1'b0;
		end
		else
		begin
			q_78 = net_60;
		end
	end

	assign net_69 = q_79;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_79 = 1'b0;
		end
		else
		begin
			q_79 = net_61;
		end
	end

	assign net_70 = q_80;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_80 = 1'b0;
		end
		else
		begin
			q_80 = net_62;
		end
	end

	assign net_71 = q_81;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_81 = 1'b0;
		end
		else
		begin
			q_81 = net_63;
		end
	end

endmodule
