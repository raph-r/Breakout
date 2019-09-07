#pragma once
#include "Square.h"

/**
 * <EN>
 * Represents a block to be destroyed
 * <PT-Br>
 * Representa um bloco para ser destruido
*/
class SBlock : public Square
{
	private:
		int score = 0;
		Util::ColorBlock enum_color;

	public:
		/**
		 * <EN>
		 * Class constructor.
		 * @param[in] top_left_x
		 * @param[in] top_left_y
		 * @param[in] width
		 * @param[in] height
		 * @param[in] color
		 * @param[in] enum_color
		 * @param[in] score
		 *
		 * <PT-Br>
		 * Construtor da classe.
		 * @param[in] top_left_x
		 * @param[in] top_left_y
		 * @param[in] width
		 * @param[in] height
		 * @param[in] color
		 * @param[in] enum_color
		 * @param[in] score
		*/
		SBlock(const int& top_left_x, const int& top_left_y, const int& width, const int& height, std::shared_ptr<ALLEGRO_COLOR> color, const Util::ColorBlock & enum_color, const int & score);

		/**
		 * <EN>
		 * Class desconstructor

		 * <PT-Br>
		 * Desconstrutor da classe
		*/
		~SBlock();

		/**
		 * <EN>
		 * Get the value of SBlock::score
		 * @return quantity of score that wil be given to player, if he destroys this object 
		 *
		 * <PT-Br>
		 * Captura o valor de SBlock::score
		 * @return quantidade de pontos que sera dado ao jogador, se ele destruir este objeto
		*/
		int get_score();

		/**
		 * <EN>
		 * Get the value of SBlock::score
		 * @return color of Util::ColorBlock that SBlock represents
		 *
		 * <PT-Br>
		 * Captura o valor de SBlock::enum_color
		 * @return cor de Util::ColorBlock que este SBlock representa
		*/
		Util::ColorBlock get_enum_color();
};

