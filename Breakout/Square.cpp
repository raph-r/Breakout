#include "Square.h"

Square::Square(const int& top_left_x, const int& top_left_y, const int& width, const int& height, std::shared_ptr<ALLEGRO_COLOR> color)
{
	this->top_left_x = top_left_x;
	this->top_left_y = top_left_y;
	this->width = width;
	this->height = height;
	this->color = std::move(color);
}

Square::~Square(){}

int Square::get_line_top() const
{
	return this->top_left_y;
}

int Square::get_line_botton() const
{
	return this->top_left_y + this->height;
}

int Square::get_line_left() const
{
	return this->top_left_x;
}

int Square::get_line_right() const
{
	return this->top_left_x + this->width;
}

bool Square::collided_on_top_of_other_square(const Square const * other_square)
{
	if (this->top_left_y + this->height >= other_square->top_left_y)
	{
		return Util::is_overlap_of_two_straight_lines(this->top_left_x, this->top_left_x + this->width, other_square->top_left_x, other_square->top_left_x + other_square->width);
	}
	return false;
}

bool Square::collided_on_botton_of_other_square(const Square const * other_square)
{
	if (this->top_left_y <= other_square->top_left_y + other_square->height)
	{
		return Util::is_overlap_of_two_straight_lines(this->top_left_x, this->top_left_x + this->width, other_square->top_left_x, other_square->top_left_x + other_square->width);
	}
	return false;
}

bool Square::collided_on_left_of_other_square(const Square const * other_square)
{
	if (this->top_left_x + this->width >= other_square->top_left_x)
	{
		return Util::is_overlap_of_two_straight_lines(this->top_left_y, this->top_left_y + this->height, other_square->top_left_y, other_square->top_left_y + other_square->height);
	}
	return false;
}

bool Square::collided_on_right_of_other_square(const Square const * other_square)
{
	if (this->top_left_x <= other_square->top_left_x + other_square->width)
	{
		return Util::is_overlap_of_two_straight_lines(this->top_left_y, this->top_left_y + this->height, other_square->top_left_y, other_square->top_left_y + other_square->height);
	}
	return false;
}

void Square::draw()
{
	al_draw_filled_rectangle(this->top_left_x, this->top_left_y, (this->top_left_x + this->width), (this->top_left_y + this->height), *this->color);
}
