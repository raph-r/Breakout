#include "BlockController.h"

BlockController::BlockController(std::shared_ptr<SMPlayer> SPSMPlayer, std::shared_ptr<SMBall> SPSMBall)
{
	this->SPSMPlayer = std::move(SPSMPlayer);
	this->SPSMBall = std::move(SPSMBall);

	// initialize color palette
	this->color_palette[0] = std::make_shared<ALLEGRO_COLOR>(std::move(al_map_rgba_f(1, 0.71, 0.75, 0.2))); // pink
	this->color_palette[1] = std::make_shared<ALLEGRO_COLOR>(std::move(al_map_rgba_f(1, 0, 0, 0.2))); // red
	this->color_palette[2] = std::make_shared<ALLEGRO_COLOR>(std::move(al_map_rgba_f(1, 0.54, 0, 0.2))); // yellow
	this->color_palette[3] = std::make_shared<ALLEGRO_COLOR>(std::move(al_map_rgba_f(1, 1, 0, 0.2))); // orange
	this->color_palette[4] = std::make_shared<ALLEGRO_COLOR>(std::move(al_map_rgba_f(0, 1, 0, 0.2))); // green
	this->color_palette[5] = std::make_shared<ALLEGRO_COLOR>(std::move(al_map_rgba_f(0, 0, 1, 0.2))); // blue

	this->initialize_blocks();
}

BlockController::~BlockController(){}

void BlockController::draw_blocks()
{
	for (auto& column : this->blocks)
	{
		for (auto& block : column.second)
		{
			block.second->draw();
		}
	}
}

bool BlockController::check_colisions_on_top_of_ball(set_of_blocks::iterator column)
{
	auto block = column->second.find(Util::identify_grid_line_of_point(this->SPSMBall->get_line_top()));
	if (block != column->second.end())
	{
		if (this->SPSMBall->collided_on_botton_of_other_square(std::make_unique<Square>(*block->second)))
		{
			this->SPSMPlayer->add_score(block->second->get_score());
			column->second.erase(block);
			this->SPSMBall->inverts_vertical_direction();
			this->SPSMBall->set_can_destroy_block(false);
			return true;
		}
	}
	return false;
}

bool BlockController::check_colisions_on_botton_of_ball(set_of_blocks::iterator column)
{
	auto block =  column->second.find(Util::identify_grid_line_of_point(this->SPSMBall->get_line_botton()));
	if (block != column->second.end())
	{
		if (this->SPSMBall->collided_on_top_of_other_square(std::make_unique<Square>(*block->second)))
		{
			this->SPSMPlayer->add_score(block->second->get_score());
			column->second.erase(block);
			this->SPSMBall->inverts_vertical_direction();
			this->SPSMBall->set_can_destroy_block(false);
			return true;
		}
	}
	return false;
}

bool BlockController::check_colisions_on_right_side_of_ball()
{
	auto column = this->blocks.find(Util::identify_grid_column_of_point(this->SPSMBall->get_line_right()));
	if (column != this->blocks.end())
	{
		return this->check_colisions_on_top_of_ball(column) || this->check_colisions_on_botton_of_ball(column);
	}
	return false;
}

bool BlockController::check_colisions_on_left_side_of_ball()
{
	auto column = this->blocks.find(Util::identify_grid_column_of_point(this->SPSMBall->get_line_left()));
	if (column != this->blocks.end())
	{
		return this->check_colisions_on_top_of_ball(column) || this->check_colisions_on_botton_of_ball(column);
	}
	return false;
}

bool BlockController::destroy_block()
{
	if (this->SPSMBall->can_destroy_block() && this->SPSMBall->get_line_top() <= Constant::HALF_SCREEN_HEIGHT)
	{
		return this->check_colisions_on_right_side_of_ball() || this->check_colisions_on_left_side_of_ball();
	}
	return false;
}

void BlockController::initialize_blocks()
{
	int pos_x = Constant::BLOCK_INITIAL_POSITION_X;
	int pos_y = Constant::BLOCK_INITIAL_POSITION_Y;
	int points = Constant::MAX_POINT_EACH_BLOCK;
	for (unsigned int i = 0; i < Constant::AMOUNT_OF_BLOCK_ALIGN_HORIZONTALLY; i++)
	{

		std::unordered_map<int, std::unique_ptr<SBlock>> column_of_blocks;
		for (int x = 0; x < 6; x++)
		{
			if (x > 0 && (x % 2) == 0)
			{
				points -= 3;
			}
			column_of_blocks.insert(
				std::make_pair(
					pos_y,
					std::make_unique<SBlock>(pos_x, pos_y, Constant::BLOCK_GRID_WIDTH, Constant::BLOCK_GRID_HEIGHT, this->color_palette[x], points)
				)
			);
			pos_y += Constant::BLOCK_GRID_HEIGHT;
		}
		this->blocks.insert(
			std::make_pair(pos_x, std::move(column_of_blocks))
		);
		points = Constant::MAX_POINT_EACH_BLOCK;
		pos_x += Constant::BLOCK_GRID_WIDTH;
		pos_y = Constant::BLOCK_INITIAL_POSITION_Y;
	}
}
