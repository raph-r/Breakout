#pragma once
#include <iostream>
#include "Constant.h"
#include "allegro5/allegro.h"
#include "SBlock.h"
#include <array>
#include <unordered_map>
#include "SMBall.h"


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
			std::unordered_map<int, std::unique_ptr<SBlock>> // line(Constant::Constant::BLOCK_INITIAL_POSITION_X * number of line) / object
		> set_of_blocks;

		std::shared_ptr<SMPlayer> SPSMPlayer = nullptr;
		std::shared_ptr<SMBall> SPSMBall = nullptr;

		std::array<std::shared_ptr<ALLEGRO_COLOR>, 6> color_palette;
		set_of_blocks blocks;

		/**
		 * <EN>
		 * Verify if the right side of BlockController::SPSMBall collided with some block. If true, destroy the block
		 * Internally calls BlockController::check_colisions_on_top_of_ball and BlockController::check_colisions_on_botton_of_ball
		 * @param[in] UPSMBall - Pointer to ball of game
		 * @return if some block was destroyed, return true. Otherwise false
		 *
		 * <PT-Br>
		 * Verifica se o lado direito de BlockController::SPSMBall collidiu com algum bloco. Caso sim, destroi o bloco
		 * Internamente chama BlockController::check_colisions_on_top_of_ball and BlockController::check_colisions_on_botton_of_ball
		 * @return Se algum bloco vai destruido, retorna true, caso contrario false
		*/
		bool check_colisions_on_right_side_of_ball();

		/**
		 * <EN>
		 * Verify if the left side of BlockController::SPSMBall collided with some block. If true, destroy the block.
		 * Internally calls BlockController::check_colisions_on_top_of_ball and BlockController::check_colisions_on_botton_of_ball
		 * @param[in] UPSMBall - Pointer to ball of game
		 * @return if some block was destroyed, return true. Otherwise false
		 *
		 * <PT-Br>
		 * Verifica se o lado esquerda de BlockController::SPSMBall collidiu com algum bloco. Caso sim, destroi o bloco
		 * Internamente chama BlockController::check_colisions_on_top_of_ball and BlockController::check_colisions_on_botton_of_ball
		 * @return Se algum bloco vai destruido, retorna true, caso contrario false
		*/
		bool check_colisions_on_left_side_of_ball();

		/**
		 * <EN>
		 * Verify if the top of BlockController::SPSMBall collided with some block. If true, destroy the block
		 * @param[in] column - Pointer to the column that has ball
		 * @return if some block was destroyed, return true. Otherwise false
		 *
		 * <PT-Br>
		 * Verifica se o topo de BlockController::SPSMBall collidiu com algum bloco. Caso sim, destroi o bloco
		 * @param[in] column - Ponteiro para a coluna a qual a bola esta
		 * @return Se algum bloco vai destruido, retorna true, caso contrario false
		*/
		bool check_colisions_on_top_of_ball(set_of_blocks::iterator column);

		/**
		 * <EN>
		 * Verify if the botton of BlockController::SPSMBall collided with some block. If true, destroy the block
		 * @param[in] column - Pointer to the column that has ball
		 * @return if some block was destroyed, return true. Otherwise false
		 *
		 * <PT-Br>
		 * Verifica se a base de BlockController::SPSMBall collidiu com algum bloco. Caso sim, destroi o bloco
		 * @param[in] column - Ponteiro para a coluna a qual a bola esta
		 * @return Se algum bloco vai destruido, retorna true, caso contrario false
		*/
		bool check_colisions_on_botton_of_ball(set_of_blocks::iterator column);

	public:

		/**
		 * <EN>
		 * Class constructor.
		 * @param[in] SPSMPlayer - Shared pointer to player
		 * @param[in] SPSMBall - Shared pointer to ball
		 *
		 * <PT-Br>
		 * Construtor da classe.
		 * @param[in] SPSMPlayer - Shared pointer para o jogador
		 * @param[in] SPSMBall - Shared pointer para a bola
		*/
		BlockController(std::shared_ptr<SMPlayer> SPSMPlayer, std::shared_ptr<SMBall> SPSMBall);

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
		 * Verify if BlockController::SPSMBall collided with some block. If true, destroy the block
		 * Internally calls BlockController::check_colisions_on_right_side_of_ball e BlockController::check_colisions_on_left_side_of_ball
		 * @return if some block was destroyed, return true. Otherwise false
		 *
		 * <PT-Br>
		 * Verifica se BlockController::SPSMBall collidiu com algum bloco. Caso sim, destroi o bloco
		 * Internamente chama BlockController::check_colisions_on_right_side_of_ball e BlockController::check_colisions_on_left_side_of_ball
		 * @return Se algum bloco foi destruido, retorna true, caso contrario false
		*/
		bool destroy_block();

		/**
		 * <EN>
		 * Initializes the blocks to be destroyed
		 *
		 * <PT-Br>
		 * Inicializa os blocos para serem destruidos
		*/
		void initialize_blocks();

		/**
		 * <EN>
		 * Verify if all blocks was destroyed
		 * @return True, if all blocks was destroyed. Otherwise false
		 *
		 * <PT-Br>
		 * Verifica se todos os blocos foram destruidos
		 * @return True, se todos os blocos foram destruidos. Caso contrario false
		*/
		bool all_blocks_was_destroyed();
};

