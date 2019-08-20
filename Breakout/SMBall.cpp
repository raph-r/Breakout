#include "SMBall.h"

SMBall::SMBall(std::shared_ptr<ALLEGRO_COLOR> color) : SMovable(
	Constant::BALL_INITIAL_POSITION_X,
	Constant::BALL_INITIAL_POSITION_Y,
	Constant::BALL_WIDTH,
	Constant::BALL_HEIGHT,
	Constant::INITIAL_ACCELERATION,
	std::move(color)
){}

SMBall::~SMBall(){}

void SMBall::move()
{
	if (this->going_to_right)
	{
		this->right();
	}
	else
	{
		this->left();
	}

	if (this->going_to_down)
	{
		this->down();
	}
	else
	{
		this->up();
	}
}

void SMBall::inverts_horizontal_direction()
{
	this->going_to_right = std::move(!this->going_to_right);
}

void SMBall::inverts_vertical_direction()
{
	this->going_to_down = std::move(!this->going_to_down);
}

void SMBall::check_collision_with_limits(const std::unique_ptr<Square>& upper_limit, const std::unique_ptr<Square>& left_limit, const std::unique_ptr<Square>& right_limit)
{
	if (this->collided_on_botton_of_other_square(upper_limit))
	{
		this->inverts_vertical_direction();
		this->move();
	}
	else if (this->collided_on_right_of_other_square(left_limit) || this->collided_on_left_of_other_square(right_limit))
	{
		this->inverts_horizontal_direction();
		this->move();
	}
}

void SMBall::check_collision_with_player(const std::unique_ptr<SMPlayer>& player, const unsigned char * key)
{
	std::unique_ptr<Square> UPSPlayer = std::make_unique<Square>(*player);
	if (this->collided_on_top_of_other_square(UPSPlayer))
	{
		this->inverts_vertical_direction();
		if ((key[ALLEGRO_KEY_LEFT] && this->going_to_right)
			|| (key[ALLEGRO_KEY_RIGHT] && !this->going_to_right))
		{
			this->inverts_horizontal_direction();
			this->move();
		}
	}
}

bool SMBall::is_ball_lost()
{
	return (this->top_left_y + this->height) >= Constant::LOST_BALL_LINE;
}

void SMBall::increase_speed(std::unique_ptr<SMPlayer> & UPSMPlayer)
{
	if (++this->hits >= 10)
	{
		this->add_acceleration();
		this->hits = std::move(0);
		UPSMPlayer->add_acceleration();
	}
}

void SMBall::reset()
{
	this->hits = std::move(0);
	SMovable::reset();
}
