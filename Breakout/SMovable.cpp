#include "SMovable.h"

SMovable::SMovable(const int & top_left_x, const int & top_left_y, const int & width, const int & height, const int & acceleration, std::shared_ptr<ALLEGRO_COLOR> color) : Square(
	top_left_x,
	top_left_y,
	width,
	height,
	std::move(color)
){
	this->acceleration = std::move(acceleration);
	this->initial_position_x = this->top_left_x;
	this->initial_position_y = this->top_left_y;
	this->initial_acceleration = this->acceleration;
}

SMovable::~SMovable(){}


void SMovable::up()
{
	this->top_left_y -= this->acceleration;
}

void SMovable::down()
{
	this->top_left_y += this->acceleration;
}

void SMovable::left()
{
	this->top_left_x -= this->acceleration;
}

void SMovable::right()
{
	this->top_left_x += this->acceleration;
}

void SMovable::double_acceleration()
{
	if (this->acceleration == this->initial_acceleration)
	{
		this->acceleration += (this->acceleration / 2.5);
	}
}

void SMovable::reset()
{
	this->top_left_x = this->initial_position_x;
	this->top_left_y = this->initial_position_y;
	this->acceleration = this->initial_acceleration;
}