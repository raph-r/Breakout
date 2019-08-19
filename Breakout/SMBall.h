#pragma once
#include "SMovable.h"
#include "Constant.h"
#include "SMPlayer.h"

/**
 * <EN>
 * Represents the ball of game
 * <PT-Br>
 * Representa a bola do jogo
*/
class SMBall : public SMovable
{
	private:
		bool going_to_right = true;
		bool going_to_down = true;

	public:
		/**
		 * <EN>
		 * Class constructor.
		 * @param[in] color - Color of object
		 *
		 * <PT-Br>
		 * Construtor da classe.
		 * @param[in] color - Cor do objeto
		*/
		SMBall(std::shared_ptr<ALLEGRO_COLOR> color);

		/**
		 * <EN>
		 * Class desconstructor
		 *
		 * <PT-Br>
		 * Desconstrutor da classe
		*/
		~SMBall();

		/**
		 * <EN>
		 * Move the object
		 *
		 * <PT-Br>
		 * Movimenta o objeto
		*/
		void move();

		/**
		 * <EN>
		 * Inverts the horizontal direction of movement
		 *
		 * <PT-Br>
		 * Inverte a direcao horizontal do movimento
		*/
		void inverts_horizontal_direction();

		/**
		 * <EN>
		 * Inverts the vertical direction of movement
		 *
		 * <PT-Br>
		 * Inverte a direcao vertical do movimento
		*/
		void inverts_vertical_direction();

		/**
		 * <EN>
		 * Verify if SMBall collided with some object and change the directions of your movements
		 * @param[in] upper_limit - Pointer to Object that represents the top limit of screen
		 * @param[in] left_limit - Pointer to Object that represents the left limit of screen
		 * @param[in] right_limit - Pointer to Object that represents the right limit of screen
		 *
		 * <PT-Br>
		 * Verifica se SMBall colidiu com algum objeto e altera a direcao dos movimentos, de acordo com cada resultado
		 * @param[in] upper_limit - Ponteiro para o objeto que representa o limite superior da tela
		 * @param[in] left_limit - Ponteiro para o objeto que representa o limite esquerdo da tela
		 * @param[in] right_limit - Ponteiro para o objeto que representa o limite direito da tela
		*/
		void check_collision_with_limits(const std::unique_ptr<Square> & upper_limit, const std::unique_ptr<Square> & left_limit, const std::unique_ptr<Square> & right_limit);

		/**
		 * <EN>
		 * Verify if SMBall collided with player and change the directions of your movements
		 * @param[in] player - Pointer to Object that represents player
		 * @param[in] key - Array of flags indicating the state of each key
		 *
		 * <PT-Br>
		 * Verifica se SMBall colidiu com o jogador e altera a direcao dos movimentos
		 * @param[in] player - Ponteiro para o objeto que representa o jogador
		 * @param[in] key - Array de bandeiras que identificam cada tecla
		*/
		void check_collision_with_player(const std::unique_ptr<SMPlayer> & player, const unsigned char * key);

		/**
		 * <EN>
		 * Verify if SMBall reached Constant::LOST_BALL_LINE
		 * @return True if reached. Otherwise false
		 *
		 * <PT-Br>
		 * Verifica se SMBall alcancou Constant::LOST_BALL_LINE
		 * @return True se alcancou. Caso contrario false
		*/
		bool is_ball_lost();
};

