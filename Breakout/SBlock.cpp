#include "SBlock.h"



SBlock::SBlock(const int& top_left_x, const int& top_left_y, const int& width, const int& height, std::shared_ptr<ALLEGRO_COLOR> color, const Util::ColorBlock & enum_color, const int & score) : Square(
	top_left_x,
	top_left_y,
	width,
	height,
	std::move(color)
){
	this->score = std::move(score);
	this->enum_color = std::move(enum_color);
}


SBlock::~SBlock()
{
}

int SBlock::get_score()
{
	return this->score;
}

Util::ColorBlock SBlock::get_enum_color()
{
	return this->enum_color;
}
