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
		 *
		 * <PT-Br>
		 * Movimenta SMPlayer
		*/
		void move();
};

