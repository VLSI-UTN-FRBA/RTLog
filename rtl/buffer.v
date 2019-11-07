module buffer
	(
		input wire rst,
		input wire clk,
		input wire a,
		output wire b,
	);

	reg q_4;
	reg q_5;
	wire net_0;
	wire net_1;
	wire net_2;

	assign net_0 = a;
	assign b = net_2;
	assign net_1 = q_4;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_4 = 1'b0;
		end
		else
		begin
			q_4 = net_0;
		end
	end

	assign net_2 = q_5;

	always@(posedge clk, posedge rst)
	begin
		if (rst)
		begin
			q_5 = 1'b0;
		end
		else
		begin
			q_5 = net_1;
		end
	end

endmodule
