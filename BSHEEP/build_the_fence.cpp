#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

// #define DEBUG

struct Sheep
{
	int x;
	int y;
	int rank;
};

struct Cmp
{
	Cmp(Sheep base, bool in_line = true)
	{
		m_base = base;
		m_inline = in_line;
	}

	/** Compare operator
	 *
	 * Operator expects, that no three points are on the same line
	 *
	 * Returns true if a is less than b
	 */
	bool operator()(const Sheep& a, const Sheep& b) {
		int x1, x2, y1, y2;
		int area;

		x1 = a.x - m_base.x;
		x2 = b.x - m_base.x;
		y1 = a.y - m_base.y;
		y2 = b.y - m_base.y;

		area = x1*y2 - x2*y1;
		if(area == 0) { // There is "base sheep"
			if(a.x == m_base.x && a.y == m_base.y) {
				if (b.x != a.x || b.y != a.y) // If both are same then false
					return true; // a is base and must be less than anything
			}
			else {
				if(!m_inline) // Sort by what is more far from base
					return false;
				int a_dist, b_dist;

				a_dist = x1*x1 + y1*y1; // This is distance^2
				b_dist = x2*x2 + y2*y2;
				return a_dist < b_dist;
			}
		}

		return area > 0;
	}

private:
	Sheep m_base;
	bool m_inline;
};

bool points_equal(Sheep a, Sheep b)
{
	return a.y == b.y && a.x == b.x;
}

void output_fence(const std::vector<Sheep>& sheeps)
{
	// Count length of fence
	double length = 0;

	for(size_t i = 1; i < sheeps.size(); i++) {
		length += std::sqrt(std::pow(sheeps[i-1].x - sheeps[i].x, 2)
		                    + std::pow(sheeps[i-1].y - sheeps[i].y, 2));
	}

	size_t last = sheeps.size() - 1;
	length += std::sqrt(std::pow(sheeps[last].x - sheeps[0].x, 2)
	                    + std::pow(sheeps[last].y - sheeps[0].y, 2));

	printf("%.2lf\n", length);
	for(Sheep sh : sheeps) {
		printf("%d ", sh.rank);

#ifdef DEBUG
		printf("\n%d %d\n\n", sh.x, sh.y);
#endif
	}
	printf("\n\n");
}

bool turns_right(Sheep a, Sheep b, Sheep c)
{
	Cmp cmp{a, false};

	return !cmp(b,c); //
}

/*
 * Preconditions:
 *  vector must be sorted by rising angle counterclockwise to
 *  bottom-most sheep (as describded in Graham's scan algo
 *  First member should be starting eelement - the one that
 *  certainly will be in convex hull
 */
std::vector<Sheep> compute_ch(const std::vector<Sheep>& sheeps)
{
	std::vector<Sheep> current_stack;

	for(const Sheep& s : sheeps) {
		while(current_stack.size() > 1) {
			size_t index = current_stack.size() - 1;

			if(!turns_right(current_stack[index-1],
			                current_stack[index], s))
				break;
			current_stack.pop_back();
		}
		current_stack.push_back(s);
	}

	// Now question is if last element added is ok
	while(current_stack.size() > 2) {
		size_t index = current_stack.size() - 1;

		if(!turns_right(current_stack[index-1],
		                current_stack[index], current_stack[0]))
			break;
		current_stack.pop_back();
	}

	return current_stack;
}

int main()
{
	int cases;

	scanf("%d", &cases);
	while(cases--) {
		int sheeps_count;
		std::vector<Sheep> sheeps;
		Sheep base_sheep;
		base_sheep.x = 0x7FFFFFFF;
		base_sheep.y = 0x7FFFFFFF;


		scanf("%d", &sheeps_count);
		for(int i = 0; i < sheeps_count; i++) {
			Sheep sh;

			scanf("%d %d", &sh.x, &sh.y);
			sh.rank = i + 1;
			sheeps.push_back(sh);

			// find starting sheep for Graham's scan
			if(sh.y <= base_sheep.y) {
				if(sh.y < base_sheep.y
				   ||  sh.x < base_sheep.x) {
					base_sheep.x = sh.x;
					base_sheep.y = sh.y;
				}
			}
		}

		Cmp cmp{base_sheep};
		std::stable_sort(sheeps.begin(), sheeps.end(), cmp);
		auto it = std::unique(sheeps.begin(), sheeps.end(), points_equal); // Get rid of duplicates
		sheeps.resize(it - sheeps.begin());
		// output_fence(sheeps);

		std::vector<Sheep> ch = compute_ch(sheeps);
		output_fence(ch);
	}
	return 0;
}
