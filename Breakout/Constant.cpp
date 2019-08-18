#include "Constant.h"

const unsigned int Constant::SCREEN_WIDTH = 640;
const unsigned int Constant::SCREEN_HEIGHT = 480;
const unsigned int Constant::HALF_SCREEN_WIDTH = Constant::SCREEN_WIDTH / 2;
const unsigned int Constant::HALF_SCREEN_HEIGHT = Constant::SCREEN_HEIGHT / 2;
const unsigned int Constant::KEY_SEEN = 1;
const unsigned int Constant::KEY_RELEASED = 2;
const unsigned int Constant::GOAL_LINE = Constant::SCREEN_HEIGHT - Constant::BLOCK_WIDTH;
const unsigned int Constant::INITIAL_ACCELERATION = 3;

const unsigned int Constant::PLAYER_WIDTH = Constant::BLOCK_WIDTH * 3;
const unsigned int Constant::PLAYER_HEIGHT = 10;
const unsigned int Constant::PLAYER_POSITION_X = Constant::HALF_SCREEN_WIDTH - (Constant::PLAYER_WIDTH / 2);
const unsigned int Constant::PLAYER_POSITION_Y = Constant::GOAL_LINE - Constant::PLAYER_HEIGHT;

const unsigned int Constant::AMOUNT_OF_BLOCK_ALIGN_VERTICALLY = 6;
const unsigned int Constant::AMOUNT_OF_BLOCK_ALIGN_HORIZONTALLY = 18;
const unsigned int Constant::BLOCK_WIDTH = 24;
const unsigned int Constant::BLOCK_HEIGHT = 15;