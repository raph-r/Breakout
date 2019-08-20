#include "Util.h"

void Util::reset_array_of_keys(unsigned char * key)
{
	for (unsigned int i = 0; i < ALLEGRO_KEY_MAX; i++)
	{
		key[i] &= Constant::KEY_SEEN;
	}
}

bool Util::is_between_range(const int & min_value, const int & max_value, const int & value_to_check)
{
	return min_value <= value_to_check && value_to_check <= max_value;
}

bool Util::is_overlap_of_two_straight_lines(const int & first_line_A, const int & first_line_B, const int & second_line_A, const int & second_line_B)
{
	return (Util::is_between_range(first_line_A, first_line_B, second_line_A) || Util::is_between_range(first_line_A, first_line_B, second_line_B)
			|| Util::is_between_range(second_line_A, second_line_B, first_line_A) || Util::is_between_range(second_line_A, second_line_B, first_line_B));
}

int Util::identify_grid_column_of_point(const int & point)
{
	return point - (point % Constant::BLOCK_GRID_WIDTH);
}

int Util::identify_grid_line_of_point(const int & point)
{
	return point - (point % Constant::BLOCK_GRID_HEIGHT);
}
