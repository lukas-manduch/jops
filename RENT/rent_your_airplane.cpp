#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>

struct order
{
	int from;
	int to;
	int value;
};

struct Comp
{
	bool operator()(order a, order b)
	{
		return a.to < b.to;
	}
};

void dao(std::vector<struct order> aa)
{
	for(auto a : aa)
	{
		printf("%d %d %d  |", a.from, a.to, a.value);
	}
	printf("\n");
}

void da(std::vector<int> aa)
{
	for(int a : aa)
	{
		printf("%3d |", a);
	}
	printf("\n");
}

// Vector is sorted by end times
std::vector<int> get_predcessors(const std::vector<struct order>& orders)
{
	std::vector<int> parents;

	parents.reserve(orders.size());
	for(auto order : orders) {
		int low = 0;
		int high = orders.size() - 1;
		int mid = -1;

		// Binary search
		while(low <= high) {
			mid = (low + high) / 2;
			if(orders[mid].to > order.from)
				high = mid - 1;
			else if(orders[mid].to < order.from)
				low = mid + 1;
			else
				break;
		}

		// printf("some mid %d\n", mid);

		if(mid < 0)
			mid = 0;

		if(mid >= (int)orders.size()) { // This case is invalid anyway
			parents.push_back(-1);
			assert(false);
		}
		else { // solve mutliple same values
			if(orders[mid].to > order.from) {
				while(mid >= 0 && orders[mid].to > order.from)
					mid--;
			}
			parents.push_back(mid);
		}
	}
	return parents;
}

int solve(const std::vector<struct order>& orders, const std::vector<int>& parents)
{
	std::vector<int> best;
	best.push_back(0);

	for(unsigned int i = 0; i < orders.size(); i++) {
		int res;

		res = std::max(best[best.size() -1], orders[i].value + best[parents[i] + 1] );
		best.push_back(res);
	}

	// da(best);
	return best[best.size() -1 ];
}

int main()
{
	int cases;

	scanf("%d", &cases);
	while(cases--) {
		int total;
		std::vector<struct order> orders;
		Comp cmp;

		scanf("%d", &total);
		for(int i = 0; i < total; i++) {
			struct order ord;

			scanf("%d %d %d", &ord.from, &ord.to, &ord.value);
			ord.to += ord.from;
			orders.push_back(ord);
		}
		std::sort(orders.begin(), orders.end(), cmp);
		auto parents = get_predcessors(orders);
		// dao(orders);
		// da(parents);
		printf("%d\n", solve(orders, parents));
	}
}
