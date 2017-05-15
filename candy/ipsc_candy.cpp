#include <iostream>
#include <vector>

int main()
{
	int packets_count;
	std::vector<int> packets;

	while (std::cin >> packets_count && packets_count != -1) {
		long long sum = 0;
		int avg;
		int moves = 0;

		packets.clear();
		for (int i = 0; i < packets_count; i++) {
			int current;

			std::cin >> current;
			packets.push_back(current);
			sum += current;

		}

		if ((sum % packets_count) != 0) { // Is it possible to divide
			std::cout << -1 << std::endl;
			continue;
		}
		avg = sum / packets_count;

		for (int i = 0; i < packets_count; i++) { // Count all moves
			if (packets[i] > avg)
				moves += packets[i] - avg;
		}
		std::cout << moves << std::endl;
	}
}