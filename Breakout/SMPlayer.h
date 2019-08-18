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
};

