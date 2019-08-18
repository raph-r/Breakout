#include "SMPlayer.h"

SMPlayer::SMPlayer(std::shared_ptr<ALLEGRO_COLOR> color) : SMovable(
	Constant::PLAYER_POSITION_X,
	Constant::PLAYER_POSITION_Y,
	Constant::PLAYER_WIDTH,
	Constant::PLAYER_HEIGHT,
	Constant::INITIAL_ACCELERATION,
	std::move(color)
)
{}

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
