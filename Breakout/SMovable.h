#pragma once
#include "Square.h"

/**
 * <EN>
 * Represents a movable square
 * <PT-Br>
 * Representa uma Square movel
*/
class SMovable : public Square
{
	private:

		int acceleration = 0;
		int initial_position_x = 0;
		int initial_position_y = 0;
		int initial_acceleration = 0;

		/**
		 * <EN>
		 * Move the object to up
		 *
		 * <PT-Br>
		 * Movimenta o objeto para cima
		*/
		void up();

		/**
		 * <EN>
		 * Move the object to down
		 *
		 * <PT-Br>
		 * Movimenta o objeto para baixo
		*/
		void down();

		/**
		 * <EN>
		 * Move the object to left
		 *
		 * <PT-Br>
		 * Movimenta o objeto para esquerda
		*/
		void left();

		/**
		 * <EN>
		 * Move the object to right
		 *
		 * <PT-Br>
		 * Movimenta o objeto para direta
		*/
		void right();

	public:

		/**
		 * <EN>
		 * Class constructor.
		 * @param[in] top_left_x
		 * @param[in] top_left_y
		 * @param[in] width
		 * @param[in] height
		 * @param[in] acceleration
		 * @param[in] color
		 *
		 * <PT-Br>
		 * Construtor da classe.
		 * @param[in] top_left_x
		 * @param[in] top_left_y
		 * @param[in] width
		 * @param[in] height
		 * @param[in] acceleration
		 * @param[in] color
		*/
		SMovable(const int & top_left_x, const int & top_left_y, const int & width, const int & height, const int & acceleration, std::shared_ptr<ALLEGRO_COLOR> color);

		/**
		 * <EN>
		 * Class desconstructor
		 *
		 * <PT-Br>
		 * Desconstrutor da classe
		*/
		~SMovable();

		/**
		 * <EN>
		 * Add 1 to acceleration of SMovable
		 *
		 * <PT-Br>
		 * Adiciona 1 a aceleracao de SMovable
		*/
		void add_acceleration();

		/**
		 * <EN>
		 * Reverts all attributes, to the values that was defined at the moment of creation of object
		 *
		 * <PT-Br>
		 * Reverte todos os atributos para os valores definidos no momento da criacao do objeto
		*/
		virtual void reset();

		/**
		 * <EN>
		 * Moves the object. Pure virtual method to be implemented. 
		 *
		 * <PT-Br>
		 * Movimenta o objeto. Metodo pure virtual para ser implementado. 
		*/
		virtual void move() = 0;
};

