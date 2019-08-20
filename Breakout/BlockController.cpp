#include "BlockController.h"

BlockController::BlockController()
{
	// initialize color palette
	this->color_palette[0] = std::make_shared<ALLEGRO_COLOR>(std::move(al_map_rgba_f(1, 0.71, 0.75, 1))); // pink
	this->color_palette[1] = std::make_shared<ALLEGRO_COLOR>(std::move(al_map_rgba_f(1, 0, 0, 1))); // red
	this->color_palette[2] = std::make_shared<ALLEGRO_COLOR>(std::move(al_map_rgba_f(1, 0.54, 0, 1))); // yellow
	this->color_palette[3] = std::make_shared<ALLEGRO_COLOR>(std::move(al_map_rgba_f(1, 1, 0, 1))); // orange
	this->color_palette[4] = std::make_shared<ALLEGRO_COLOR>(std::move(al_map_rgba_f(0, 1, 0, 1))); // green
	this->color_palette[5] = std::make_shared<ALLEGRO_COLOR>(std::move(al_map_rgba_f(0, 0, 1, 1))); // blue

	int pos_x = Constant::BLOCK_INITIAL_POSITION_X;
	int pos_y = Constant::BLOCK_INITIAL_POSITION_Y;
	for (unsigned int i = 0; i < Constant::AMOUNT_OF_BLOCK_ALIGN_HORIZONTALLY; i++)
	{
		std::unordered_map<int, std::unique_ptr<Square>> column_of_blocks;
		for (auto& color : this->color_palette)
		{
			column_of_blocks.insert(
				std::make_pair(
					pos_y,
					std::make_unique<Square>(pos_x, pos_y, Constant::BLOCK_GRID_WIDTH, Constant::BLOCK_GRID_HEIGHT, color)
				)
			);
			pos_y += Constant::BLOCK_GRID_HEIGHT;
		}
		this->blocks.insert(
			std::make_pair(
				pos_x,
				std::move(column_of_blocks)
			)
		);

		pos_x += Constant::BLOCK_GRID_WIDTH;
		pos_y = Constant::BLOCK_INITIAL_POSITION_Y;
	}
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

bool BlockController::check_colisions_on_top_of_ball(const std::unique_ptr<SMBall>& UPSMBall, set_of_blocks::iterator column)
{
	auto block = column->second.find(Util::identify_grid_line_of_point(UPSMBall->get_line_top()));
	if (block != column->second.end())
	{
		if (UPSMBall->collided_on_botton_of_other_square(block->second))
		{
			column->second.erase(block);
			UPSMBall->inverts_vertical_direction();
			return true;
		}
	}
	return false;
}

bool BlockController::check_colisions_on_botton_of_ball(const std::unique_ptr<SMBall>& UPSMBall, set_of_blocks::iterator column)
{
	auto block =  column->second.find(Util::identify_grid_line_of_point(UPSMBall->get_line_botton()));
	if (block != column->second.end())
	{
		if (UPSMBall->collided_on_top_of_other_square(block->second))
		{
			column->second.erase(block);
			UPSMBall->inverts_vertical_direction();
			return true;
		}
	}
	return false;
}

bool BlockController::check_colisions_on_right_side_of_ball(const std::unique_ptr<SMBall>& UPSMBall)
{
	auto column = this->blocks.find(Util::identify_grid_column_of_point(UPSMBall->get_line_right()));
	if (column != this->blocks.end())
	{
		return this->check_colisions_on_top_of_ball(UPSMBall, column) || this->check_colisions_on_botton_of_ball(UPSMBall, column);
	}
	return false;
}

bool BlockController::check_colisions_on_left_side_of_ball(const std::unique_ptr<SMBall>& UPSMBall)
{
	auto column = this->blocks.find(Util::identify_grid_column_of_point(UPSMBall->get_line_left()));
	if (column != this->blocks.end())
	{
		return this->check_colisions_on_top_of_ball(UPSMBall, column) || this->check_colisions_on_botton_of_ball(UPSMBall, column);
	}
	return false;
}

bool BlockController::destroy_block(const std::unique_ptr<SMBall>& UPSMBall)
{
	if (UPSMBall->get_line_top() <= Constant::HALF_SCREEN_HEIGHT)
	{
		return this->check_colisions_on_right_side_of_ball(UPSMBall) || this->check_colisions_on_left_side_of_ball(UPSMBall);
	}
	return false;
}
