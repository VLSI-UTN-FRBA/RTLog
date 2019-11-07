module join_fork_big
	(
		input wire rst,
		input wire clk,
		input wire i_w,
		input wire i_x,
		input wire i_y,
		input wire i_z,
		output reg a,
		output reg b,
		output reg d,
		output reg c,
	);

	reg q_7;
	reg q_9;
	reg q_11;
	reg q_13;
	reg q_14;
	reg q_15;
	reg q_16;
	reg q_17;
	wire and_18;
	wire and_19;
	wire and_20;
	wire and_21;
	wire and_22;
	wire and_23;
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

	assign net_4 = i_w;
	assign net_5 = i_x;
	assign net_6 = i_y;
	assign net_7 = i_z;
	assign a = net_0;
	assign net_0 = q_7;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_7 = 1'b0;
		end
		else
		begin
			q_7 = net_8;
		end
	end

	assign b = net_1;
	assign net_1 = q_9;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_9 = 1'b0;
		end
		else
		begin
			q_9 = net_11;
		end
	end

	assign d = net_2;
	assign net_2 = q_11;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_11 = 1'b0;
		end
		else
		begin
			q_11 = net_23;
		end
	end

	assign c = net_3;
	assign net_3 = q_13;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_13 = 1'b0;
		end
		else
		begin
			q_13 = net_16;
		end
	end

	assign net_8 = q_14;
	assign net_9 = q_14;
	assign net_12 = q_14;
	assign net_17 = q_14;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_14 = 1'b0;
		end
		else
		begin
			q_14 = net_4;
		end
	end

	assign net_10 = q_15;
	assign net_13 = q_15;
	assign net_18 = q_15;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_15 = 1'b0;
		end
		else
		begin
			q_15 = net_5;
		end
	end

	assign net_15 = q_16;
	assign net_20 = q_16;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_16 = 1'b0;
		end
		else
		begin
			q_16 = net_6;
		end
	end

	assign net_22 = q_17;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_17 = 1'b0;
		end
		else
		begin
			q_17 = net_7;
		end
	end

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

endmodule
