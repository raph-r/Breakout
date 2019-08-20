#pragma once
#include "Constant.h"
#include "allegro5/allegro.h"
#include "Square.h"
#include <array>
#include <unordered_map>
#include "SMBall.h"
#include <iostream>

/**
 * <EN>
 * Represents the set of blocks to be destroyed
 * <PT-Br>
 * Representa o conjunto de blocos, para serem destruidos
*/
class BlockController
{
	protected:
		typedef std::unordered_map<
			int, // column(Constant::Constant::BLOCK_INITIAL_POSITION_X * number of column)
			std::unordered_map<int, std::unique_ptr<Square>> // line(Constant::Constant::BLOCK_INITIAL_POSITION_X * number of line) / object
		> set_of_blocks;

		std::array<std::shared_ptr<ALLEGRO_COLOR>, 6> color_palette;
		set_of_blocks blocks;

		/**
		 * <EN>
		 * Verify if the right side of UPSMBall collided with some block. If true, destroy the block
		 * Internally calls BlockController::check_colisions_on_top_of_ball and BlockController::check_colisions_on_botton_of_ball
		 * @param[in] UPSMBall - Pointer to ball of game
		 * @return if some block was destroyed, return true. Otherwise false
		 *
		 * <PT-Br>
		 * Verifica se o lado direito de UPSMBall collidiu com algum bloco. Caso sim, destroi o bloco
		 * Internamente chama BlockController::check_colisions_on_top_of_ball and BlockController::check_colisions_on_botton_of_ball
		 * @param[in] UPSMBall - Ponteiro para a bola do jogo
		 * @return Se algum bloco vai destruido, retorna true, caso contrario false
		*/
		bool check_colisions_on_right_side_of_ball(const std::unique_ptr<SMBall> & UPSMBall);

		/**
		 * <EN>
		 * Verify if the left side of UPSMBall collided with some block. If true, destroy the block.
		 * Internally calls BlockController::check_colisions_on_top_of_ball and BlockController::check_colisions_on_botton_of_ball
		 * @param[in] UPSMBall - Pointer to ball of game
		 * @return if some block was destroyed, return true. Otherwise false
		 *
		 * <PT-Br>
		 * Verifica se o lado esquerda de UPSMBall collidiu com algum bloco. Caso sim, destroi o bloco
		 * Internamente chama BlockController::check_colisions_on_top_of_ball and BlockController::check_colisions_on_botton_of_ball
		 * @param[in] UPSMBall - Ponteiro para a bola do jogo
		 * @return Se algum bloco vai destruido, retorna true, caso contrario false
		*/
		bool check_colisions_on_left_side_of_ball(const std::unique_ptr<SMBall> & UPSMBall);

		/**
		 * <EN>
		 * Verify if the top of UPSMBall collided with some block. If true, destroy the block
		 * @param[in] UPSMBall - Pointer to ball of game
		 * @param[in] column - Pointer to the column that has ball
		 * @return if some block was destroyed, return true. Otherwise false
		 *
		 * <PT-Br>
		 * Verifica se o topo de UPSMBall collidiu com algum bloco. Caso sim, destroi o bloco
		 * @param[in] UPSMBall - Ponteiro para a bola do jogo
		 * @param[in] column - Ponteiro para a coluna a qual a bola esta
		 * @return Se algum bloco vai destruido, retorna true, caso contrario false
		*/
		bool check_colisions_on_top_of_ball(const std::unique_ptr<SMBall> & UPSMBall, set_of_blocks::iterator column);

		/**
		 * <EN>
		 * Verify if the botton of UPSMBall collided with some block. If true, destroy the block
		 * @param[in] UPSMBall - Pointer to ball of game
		 * @param[in] column - Pointer to the column that has ball
		 * @return if some block was destroyed, return true. Otherwise false
		 *
		 * <PT-Br>
		 * Verifica se a base de UPSMBall collidiu com algum bloco. Caso sim, destroi o bloco
		 * @param[in] UPSMBall - Ponteiro para a bola do jogo
		 * @param[in] column - Ponteiro para a coluna a qual a bola esta
		 * @return Se algum bloco vai destruido, retorna true, caso contrario false
		*/
		bool check_colisions_on_botton_of_ball(const std::unique_ptr<SMBall> & UPSMBall, set_of_blocks::iterator column);

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

		/**
		 * <EN>
		 * Verify if UPSMBall collided with some block. If true, destroy the block
		 * Internally calls BlockController::check_colisions_on_right_side_of_ball e BlockController::check_colisions_on_left_side_of_ball
		 * @param[in] UPSMBall - Pointer to ball of game
		 * @return if some block was destroyed, return true. Otherwise false
		 *
		 * <PT-Br>
		 * Verifica se UPSMBall collidiu com algum bloco. Caso sim, destroi o bloco
		 * Internamente chama BlockController::check_colisions_on_right_side_of_ball e BlockController::check_colisions_on_left_side_of_ball
		 * @param[in] UPSMBall - Ponteiro para a bola do jogo
		 * @return Se algum bloco foi destruido, retorna true, caso contrario false
		*/
		bool destroy_block(const std::unique_ptr<SMBall> & UPSMBall);
};

