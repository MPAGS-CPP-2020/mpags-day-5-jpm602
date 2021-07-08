#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <string>

#include "CipherMode.hpp"

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the Cipher purely abstract base class
 */

/**
 * \class Cipher
 * \brief Purely abstract base class for a cipher
 */

class Cipher
{
    public:
        /// Default constructor
        Cipher() = default;
        /// Default copy constructor
        Cipher(const Cipher& rhs) = default;
        /// Default move constructor
        Cipher(Cipher&& rhs) = default;
        /// Default copy assignment constructor
        Cipher& operator=(const Cipher& rhs) = default;
        /// Default move assignment constructor
        Cipher& operator=(Cipher&& rhs) = default;
        /// Virtual default destructor
        virtual ~Cipher() = default;

        /**
        * Apply the cipher to the provided text
        *
        * \param inputText the text to encrypt or decrypt
        * \param cipherMode whether to encrypt or decrypt the input text
        * \return the result of applying the cipher to the input text
        */
        virtual std::string applyCipher( const std::string& input,
                                            const CipherMode mode ) const = 0;
};

#endif