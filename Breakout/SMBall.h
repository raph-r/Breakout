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
		bool destroy_block = false;
		std::shared_ptr<SMPlayer> SPSMPlayer = nullptr;
		int hits = 0;

	public:
		/**
		 * <EN>
		 * Class constructor.
		 * @param[in] SPSMPlayer - Shared pointer to player
		 * @param[in] color - Color of object
		 *
		 * <PT-Br>
		 * Construtor da classe.
		 * @param[in] SPSMPlayer - Shared pointer para o jogador
		 * @param[in] color - Cor do objeto
		*/
		SMBall(std::shared_ptr<SMPlayer> SPSMPlayer, std::shared_ptr<ALLEGRO_COLOR> color);

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
		 * @param[in] key - Array of flags indicating the state of each key
		 *
		 * <PT-Br>
		 * Verifica se SMBall colidiu com o jogador e altera a direcao dos movimentos
		 * @param[in] key - Array de bandeiras que identificam cada tecla
		*/
		void check_collision_with_player(const unsigned char * key);

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

		/**
		 * <EN>
		 * If the quantity of SMBall::hits was been reached, adds acceleration to SMBall and player
		 *
		 * <PT-Br>
		 * Caso a quantidade de SMBall::hits tenha sido alcancada, aumenta a velocidade de momento de SMBall e dos players
		*/
		void increase_speed();

		/**
		 * <EN>
		 * Reverts all attributes, to the values that was defined at the moment of creation of object
		 *
		 * <PT-Br>
		 * Reverte todos os atributos para os valores definidos no momento da criacao do objeto
		*/
		void reset();

		/**
		 * <EN>
		 * Defines SMBall::destroy_block
		 * @param[in] value - Value that will define the variable
		 *
		 * <PT-Br>
		 * Define SMBall::destroy_block
		 * @param[in] value - Valor que sera definido para a variavel
		*/
		void set_can_destroy_block(const bool & value);

		/**
		 * <EN>
		 * Get the value of SMBall::destroy_block
		 * @return True, if SMBall can destroy blocks. Otherwise false
		 *
		 * <PT-Br>
		 * Captura o valor de SMBall::destroy_block
		 * @return True, se SMBall puder destruir blocos. Caso contrario false
		*/
		bool can_destroy_block();
};

