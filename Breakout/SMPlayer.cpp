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

void SMPlayer::move()
{
	//TODO
}
