#pragma once
#include "Constant.h"
#include "allegro5/allegro.h"
#include "Square.h"
#include <array>
#include <unordered_map>

/**
 * <EN>
 * Represents the set of blocks to be destroyed
 * <PT-Br>
 * Representa o conjunto de blocos, para serem destruidos
*/
class BlockController
{
	protected:
		std::array<std::shared_ptr<ALLEGRO_COLOR>, 6> color_palette;
		std::unordered_map<
			int, // column(Constant::Constant::BLOCK_INITIAL_POSITION_X * number of column)
			std::unordered_map<int, std::unique_ptr<Square>> // line(Constant::Constant::BLOCK_INITIAL_POSITION_X * number of line) / object
		> blocks;
	public:

		/**
		 * <EN>
		 * Class constructor.
		 *
		 * <PT-Br>
		 * Construtor da classe.
		*/
		BlockController();

		/**
		 * <EN>
		 * Class desconstructor
		 *
		 * <PT-Br>
		 * Desconstrutor da classe
		*/
		~BlockController();

		/**
		 * <EN>
		 * Draw all blocks in BlockController::blocks
		 *
		 * <PT-Br>
		 * Desenha todos os blocos em BlockController::blocks
		*/
		void draw_blocks();
};

