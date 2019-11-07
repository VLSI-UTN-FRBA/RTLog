module join_fork
	(
		input wire rst,
		input wire clk,
		input wire i_gamma,
		input wire i_delta,
		input wire i_epsilon,
		output reg a,
		output reg b,
	);

	reg q_6;
	reg q_8;
	reg q_9;
	reg q_10;
	reg q_11;
	wire and_12;
	wire and_13;
	wire or_14;
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

	assign net_2 = i_gamma;
	assign net_3 = i_delta;
	assign net_4 = i_epsilon;
	assign a = net_0;
	assign net_0 = q_6;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_6 = 1'b0;
		end
		else
		begin
			q_6 = net_9;
		end
	end

	assign b = net_1;
	assign net_1 = q_8;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_8 = 1'b0;
		end
		else
		begin
			q_8 = net_12;
		end
	end

	assign net_5 = q_9;
	assign net_10 = q_9;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_9 = 1'b0;
		end
		else
		begin
			q_9 = net_2;
		end
	end

	assign net_6 = q_10;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_10 = 1'b0;
		end
		else
		begin
			q_10 = net_3;
		end
	end

	assign net_8 = q_11;
	assign net_11 = q_11;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_11 = 1'b0;
		end
		else
		begin
			q_11 = net_4;
		end
	end

	assign net_7 = and_12;

	assign and_12 = net_5 & net_6;

	assign net_9 = and_13;

	assign and_13 = net_7 & net_8;

	assign net_12 = or_14;

	assign or_14 = net_10 | net_11;

endmodule
