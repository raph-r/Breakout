#include "SBlock.h"



SBlock::SBlock(const int& top_left_x, const int& top_left_y, const int& width, const int& height, std::shared_ptr<ALLEGRO_COLOR> color, const int & score) : Square(
	top_left_x,
	top_left_y,
	width,
	height,
	std::move(color)
){
	this->score = std::move(score);
}


SBlock::~SBlock()
{
}

int SBlock::get_score()
{
	return this->score;
}
