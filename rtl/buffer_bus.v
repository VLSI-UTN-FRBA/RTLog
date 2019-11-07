module buffer_bus
	(
		input wire rst,
		input wire clk,
		input wire [3:0] a,
		output wire [3:0] b,
	);

	reg q_10;
	reg q_11;
	reg q_12;
	reg q_13;
	reg q_14;
	reg q_15;
	reg q_16;
	reg q_17;
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

	assign net_0 = a[0];
	assign net_1 = a[1];
	assign net_2 = a[2];
	assign net_3 = a[3];
	assign b[0] = net_8;
	assign b[1] = net_9;
	assign b[2] = net_10;
	assign b[3] = net_11;
	assign net_4 = q_10;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_10 = 1'b0;
		end
		else
		begin
			q_10 = net_0;
		end
	end

	assign net_5 = q_11;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_11 = 1'b0;
		end
		else
		begin
			q_11 = net_1;
		end
	end

	assign net_6 = q_12;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_12 = 1'b0;
		end
		else
		begin
			q_12 = net_2;
		end
	end

	assign net_7 = q_13;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_13 = 1'b0;
		end
		else
		begin
			q_13 = net_3;
		end
	end

	assign net_8 = q_14;

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

	assign net_9 = q_15;

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

	assign net_10 = q_16;

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

	assign net_11 = q_17;

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

endmodule
