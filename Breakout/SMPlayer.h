#pragma once
#include "SMovable.h"

/**
 * <EN>
 * Represents a Player object
 * <PT-Br>
 * Representa o objeto Jogador
*/
class SMPlayer : public SMovable
{
private:
	unsigned int score = 0;
	unsigned int remaining_balls = 0;

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
		SMPlayer(std::shared_ptr<ALLEGRO_COLOR> color);

		/**
		 * <EN>
		 * Class desconstructor
		 *
		 * <PT-Br>
		 * Desconstrutor da classe
		*/
		~SMPlayer();

		/**
		 * <EN>
		 * Moves SMPlayer
		 * @param[out] key - Array of flags indicating the state of each key
		 *
		 * <PT-Br>
		 * Movimenta SMPlayer
		 * @param[out] key - Array de bandeiras que identificam cada tecla
		*/
		void move(const unsigned char * key, const std::unique_ptr<Square> & left_limit, const std::unique_ptr<Square> & right_limit);

		/**
		 * <EN>
		 * Get the current score of player
		 * @return score of player
		 *
		 * <PT-Br>
		 * Captura a pontuacao atual do jogador
		 * @return pontuacao do jogador
		*/
		unsigned int get_score();

		/**
		 * <EN>
		 * Get the quantity of remaining balls of player
		 * @return quantity of remaining balls of player
		 *
		 * <PT-Br>
		 * Captura a quantidade de bolas restanted do jogador
		 * @return quantidade de bolas restantes do jogador
		*/
		unsigned int get_remaining_balls();

		/**
		 * <EN>
		 * Add 'value' to current score of player
		 * @param[in] value - value that need to be add
		 *
		 * <PT-Br>
		 * Adiciona 'value' a pontuacao atual do jogador
		 * @param[in] value - valor que devera ser adicionado
		*/
		void add_score(const int & value);

		/**
		 * <EN>
		 * Removes a remaining ball of player. if SMPlayer::remaining_balls > 0
		 * @return True if was possible to remove. Otherwise false
		 *
		 * <PT-Br>
		 * Remove uma bola restante do jogador, se SMPlayer::remaining_balls > 0
		 * @return True se foi possivel remover. Caso contrario false
		*/
		bool remove_a_remaining_ball();
};

