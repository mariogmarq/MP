/**
 * @file move.h
 * @author DECSAI
 * @note To be implemented by students
 * @warning Adjust const and references when needed
 */
#ifndef MOVE_H
#define MOVE_H

#define UNKNOWN             -1  //Error generico
#define BOARD_OVERFLOW      -2  //Se sale del tablero
#define NONEXISTENT_WORD    -3  //No esta en el diccionario
#define INFEASIBLE_WORD     -4  //No compatible con player
#define NOT_FREE            -5  //Empieza en una celda ya ocupada
#define MISSING_CROSSWORDS  -6  //No tiene cruces

#include <iostream>
#include "language.h"
/**
 * @class Move
 * @brief Class to represent both a single movement, which might not be
 * a recognizable word, and a crossword in the table, which must be a known
 * word in the chosen language.
 * 
 * **Please note that all the characters are stored in ISO8859 standard and in uppercase**
*/
class Move {
private:
	int row, column;		/// Coordinates of the first letter
	bool ishorizontal;	/// Horizontal or vertical
	std::string letters;	/// Letters of the movement
	int score;				/// Total value of movement according to the language chosen
public:
	/**
	 * @brief Basic constructor e initializator
	 */
	Move();
	/**
	 * @brief Sets the main data of the class 
	 * @param r row
	 * @param c column
	 * @param h 'H' horizontal or 'V' vertical
	 * @param l letters
	 */
	void set(int r, int c, char h, const std::string  &l);
	/**
	 * @brief Sets the main data of the class 
	 * @param r row
	 */
	inline void setRow(int r){row = r;};
	/**
	 * @brief Sets the main data of the class 
	 * @param c Column
	 */
	inline void setCol(int c){column = c;};
	/**
	 * @brief Sets the main data of the class 
	 * @param h 'H' horizontal or 'V' vertical
	 */
	void setHorizontal(char h);
	/**
	 * @brief Sets the main data of the class 
	 * @param l Letters
	 */
	inline void setLetters(const std::string &l){letters = l;};
	/**
	 * @brief Calculates the value of the movement by adding the value 
	 * each letter according to the chosen language. If the word contained in 
	 * the set of letters does not belong to the language, its score would be -1 
	 * @param l The language
	 * @return The sum of individual values according to the language, or -1 if the 
	 * word does not belong to the language.
	 */
	int findScore(const Language &l)const;
	/**
	 * @brief Sets the value of the movement which have been calculated elsewhere 
	 * @param s The value of the movement
	 */
	inline void setScore(int s){score = s;};
	/**
	 * @brief Query data stored in the class
	 * @return The value stored
	 */
	int getScore() const;
	/**
	 * @brief Query data stored in the class
	 * @return The row stored
	 */
	int getRow() const;
	/**
	 * @brief Query data stored in the class
	 * @return The column stored
	 */
	int getCol() const;
	/**
	 * @brief Query data stored in the class
	 * @return @retval true if it is a horizontal move, @retval false otherwise
	 */
	bool isHorizontal() const;
	/**
	 * @brief Query data stored in the class
	 * @return The letters
	 */
	std::string getLetters() const;

	/**
	 * @brief Shows the values stored in the screen, except score 
	 */
	void print(std::ostream &os) const;
	/**
	 * @brief Reads from keyboard the values of the class, except score 
	 */
	void read(std::istream &is);

	///...
	// Friend functions
	friend std::ostream& operator<<(std::ostream& os, const Move & m);
	friend std::istream& operator>>(std::istream& is, Move & m);
};

/**
 * @brief Overload of the insertion operator
 * @param os Output stream (cout)
 * @param m The class to be inserted in the stream
 * @return The output stream (cout)
 */
std::ostream& operator<<(std::ostream& os, const Move & m);
/**
 * @brief Overload of the extraction operator
 * @param os Input stream (cin)
 * @param m The class to be extracted from the stream
 * @return The input stream (cin)
 */
std::istream& operator>>(std::istream& is, Move & m);

#endif /* MOVE_H */
