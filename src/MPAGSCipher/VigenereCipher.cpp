
// Standard library includes
#include <string>
#include <algorithm>
#include <utility>

// Out project headers
#include "Alphabet.hpp"
#include "VigenereCipher.hpp"
#include "CaesarCipher.hpp"

VigenereCipher::VigenereCipher( const std::string& key )
{
    // Set the given key
    setKey(key);
}

void VigenereCipher::setKey( const std::string& key )
{
    // Store the key
    key_ = key;

    // Make sure the key is uppercase
    std::transform( std::begin(key_), std::end(key_), std::begin(key_), ::toupper );

    // Remove non-alphabet characters
    key_.erase( std::remove_if( std::begin(key_), std::end(key_), [](char c){ return !std::isalpha(c); } ),
              std::end(key_) );

    // Check if the key is empty and replace with default if so
    if ( key_.empty() == true )
        key_ = "VIGENEREEXAMPLE";

    // Loop over the key
    charLookup_.clear();
    for(const auto& character : key_)
    {

        // Check if seen the letter before
        if (charLookup_.find( character) != charLookup_.end() )
            continue;
        // Find the letter position in the alphabet
        std::size_t pos = key_.find(character);

        // Create a CaesarCipher using this position as a key
        if( pos!= std::string::npos )
            {
                CaesarCipher caesar {pos};

            // Insert a std::pair of the letter and the CaesarCipher into the lookup
            charLookup_.insert(std::make_pair(character, caesar));
            }
    }
}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode cipherMode ) const
{
    std::string outputText {""};
    outputText.reserve(inputText.size());

    // For each letter in input
    for ( size_t i{0}; i<inputText.size(); ++i )
    {
        // Find the corresponding letter in the key, repeating/truncating as needed
        const char keyChar {key_[i%key_.size()]};

        // Find the Caesar cipher from the lookup
        const CaesarCipher& cipher {charLookup_.at(keyChar)};

        // Run the decryption/encryption and add the result to the output
        const std::string character {inputText[i]};
        outputText += cipher.applyCipher(character, cipherMode);
    }   
    return outputText;
}