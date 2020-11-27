
// Standard library includes
#include <string>
#include <algorithm>

// Out project headers
#include "Alphabet.hpp"
#include "VigenereCipher.hpp"

VigenereCipher::VigenereCipher( const std::string& key )
{
    // Set the given key
    setKey(key);
}

void VigenereCipher::setKey( const std::string& key )
{
    key_ = key;
}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode /*cipherMode*/ ) const
{
    return inputText;
}