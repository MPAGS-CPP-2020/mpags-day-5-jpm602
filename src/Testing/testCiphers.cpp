//! Unit Tests for MPAGSCipher
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Cipher.hpp"
#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher( const Cipher& cipher, const CipherMode mode,
                const std::string& inputText, const std::string& outputText )
                {
                    if( cipher.applyCipher(inputText, mode) == outputText )
                        return true;
                    else
                        return false;
                }

TEST_CASE("Caesar Cipher encryption", "[caesar]") {
  CaesarCipher cc{10};
  REQUIRE( testCipher(cc, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN") == true);
}

TEST_CASE("Playfair Cipher encryption", "[playfair]") {
  PlayfairCipher pc{"hello"};
  REQUIRE( testCipher(pc, CipherMode::Encrypt, "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", 
  "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA") == true);
}

TEST_CASE("Vigenere Cipher encryption", "[vigenere]"){
    VigenereCipher vc{"EXAMPLE"};
    REQUIRE ( testCipher(vc, CipherMode::Encrypt, "HELLOWORLD", "HDJIKTIOIU") == true );
}