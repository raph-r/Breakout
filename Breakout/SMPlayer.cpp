#include "SMPlayer.h"

SMPlayer::SMPlayer(std::shared_ptr<ALLEGRO_COLOR> color) : SMovable(
	Constant::PLAYER_POSITION_X,
	Constant::PLAYER_POSITION_Y,
	Constant::PLAYER_WIDTH,
	Constant::PLAYER_HEIGHT,
	Constant::INITIAL_ACCELERATION * 2,
	std::move(color)
)
{
	this->remaining_balls = Constant::QUANTITY_OF_BALLS;
}

SMPlayer::~SMPlayer(){}

void SMPlayer::move(const unsigned char * key, const std::unique_ptr<Square> & left_limit, const std::unique_ptr<Square> & right_limit)
{
	if (key[ALLEGRO_KEY_LEFT] && !this->collided_on_right_of_other_square(left_limit))
	{
		this->left();
	}
	else if (key[ALLEGRO_KEY_RIGHT] && !this->collided_on_left_of_other_square(right_limit))
	{
		this->right();
	}
}

unsigned int SMPlayer::get_score()
{
	return this->score;
}

unsigned int SMPlayer::get_remaining_balls()
{
	return this->remaining_balls;
}

void SMPlayer::add_score(const int & value)
{
	this->score += value;
}

bool SMPlayer::remove_a_remaining_ball()
{
	if (this->remaining_balls > 0)
	{
		this->remaining_balls--;
		return true;
	}
	return false;
}

void SMPlayer::reset()
{
	this->score = std::move(0);
	this->remaining_balls = Constant::QUANTITY_OF_BALLS;
	this->reset_position_and_acceleration();
	this->width_has_been_reduced = std::move(false);
	this->width += (this->width / 4);
}

void SMPlayer::reset_position_and_acceleration()
{
	SMovable::reset();
}

void SMPlayer::reduce_width()
{
	if (!this->width_has_been_reduced && this->score >= 140)
	{
		this->width -= (this->width / 4);
		this->width_has_been_reduced = true;
	}
}
