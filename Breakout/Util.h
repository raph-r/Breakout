#pragma once
#include "allegro5/allegro.h"
#include "Constant.h"

/**
 * <EN>
 * Namespace of methods to general use
 * 
 * <PT-Br>
 * Namespace de metodos para uso geral
*/
namespace Util
{
	/**
	 * <EN>
	 * Use only with: ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT, ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN
	 * Verify if the received direction is horizontal(ALLEGRO_KEY_LEFT ou ALLEGRO_KEY_RIGHT)
	 * @param[in] direction - ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT, ALLEGRO_KEY_UP or ALLEGRO_KEY_DOWN 
	 * @return - True if it is equal, otherwise false
	 *
	 * <PT-Br>
	 * Utilizar apenas com: ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT, ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN 
	 * Verifica se a direcao recebida e horizontal(ALLEGRO_KEY_LEFT ou ALLEGRO_KEY_RIGHT)
	 * @param[in] direction - ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT, ALLEGRO_KEY_UP ou ALLEGRO_KEY_DOWN 
	 * @return - True se for igual, caso contrario false
	*/
	bool is_horizontal(const unsigned int & direction);

	/**
	 * <EN>
	 * Identify what key was pressed
	 * @param[in] key - Array of flags indicating the state of each key
	 * @return ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT, ALLEGRO_KEY_UP ou ALLEGRO_KEY_DOWN. Otherwise NULL
	 *
	 * <PT-Br>
	 * Identifica a tecla que foi pressionada
	 * @param[in] key - Array de bandeiras que identificam cada tecla
	 * @return ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT, ALLEGRO_KEY_UP ou ALLEGRO_KEY_DOWN. Caso contrario NULL
	*/
	unsigned int identify_pressed_key(const unsigned char * key);

	/**
	 * <EN>
	 * Reset array of flags indicating the state of each key
	 * @param[out] key - Array of flags indicating the state of each key
	 *
	 * <PT-Br>
	 * Reseta o array de bandeiras que identificam cada tecla
	 * @param[out] key - Array de bandeiras que identificam cada tecla
	*/
	void reset_array_of_keys(unsigned char * key);

	/**
	 * <EN>
	 * Verify if 'value_to_check' is between 'man_value' and 'max_value'. min_value <= value_to_check <= max_value
	 * @param[in] min_value - minimum value of range
	 * @oaram[in] max_value - maximum value of range
	 * @param[in] value_to_check - value to check
	 * @return True, if 'pos' is between 'man_value' and 'max_value'. Otherwise, False
	 *
	 * <PT-Br>
	 * Verifica se 'pos' esta entre 'min_value' e 'max_value'. min_value <= value_to_check <= max_value
	 * @param[in] min_value - valor minimo do intervalo
	 * @oaram[in] max_value - valor maximo do intervalo
	 * @param[in] value_to_check - valor para verificar
	 * @return True caso 'value_to_check' esteja entre 'min_value' e 'max_value'. Caso contrario, False
	*/
	bool is_between_range(const int & min_value, const int & max_value, const int & value_to_check);

	/**
	 * <EN>
	 * Verify if there is overlap between two straight lines(first_line and second_line).
	 * @param[in] first_line_A - A point of first line
	 * @oaram[in] first_line_B - B point of first line
	 * @param[in] second_line_A - A point of second line
	 * @param[in] second_line_B - B point of second line
	 * @return True, if there is overlap. Otherwise, False
	 *
	 * <PT-Br>
	 * Verifica se houve sobreposicao entre duas retas(first_line e second_line).
	 * @param[in] first_line_A - ponto A da primeira reta
	 * @oaram[in] first_line_B - ponto B da primeira reta
	 * @param[in] second_line_A - ponto A da segunda reta
	 * @param[in] second_line_B - ponto B da segunda reta
	 * @return True caso houve sobreposicao. Caso contrario false
	*/
	bool is_overlap_of_two_straight_lines(const int & first_line_A, const int & first_line_B, const int & second_line_A, const int & second_line_B);
}
