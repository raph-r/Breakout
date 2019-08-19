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
					std::make_unique<Square>(pos_x, pos_y, Constant::BLOCK_WIDTH, Constant::BLOCK_HEIGHT, color)
				)
			);
			pos_y += Constant::BLOCK_HEIGHT;
		}
		this->blocks.insert(
			std::make_pair(
				pos_x,
				std::move(column_of_blocks)
			)
		);

		pos_x += Constant::BLOCK_WIDTH;
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
