#ifndef _TYPE_
#define _TYPE_

#include <string>

/**
*	@brief Type d'un symbole.
*/
class Type {

	private:

		std::string* type; /** @param type variable, fonction, procedure, temporaire, etiquette ...  */

	public:

		Type(std::string _type);
		~Type();

        /**
        *   \brief Récupérer le type du symbole sous la forme d'une chaine de caractères
        *   \return Retourne un pointeur sur une chaine de caractères
        */
		std::string* getStringType();

};

#endif