#ifndef CRYPTOMANAGER_H
#define CRYPTOMANAGER_H

#include <string>
#include <vector>
#include <memory>

enum class Algorithm {
    RSA,
    AES,
    BLOWFISH
};

enum class HashAlgorithm {
    MD5,
    SHA256
};

class CryptoManager {
public:
    CryptoManager();
    ~CryptoManager();

    // Encryption/Decryption
    std::string encrypt(const std::string& plaintext, Algorithm algo, const std::string& key);
    std::string decrypt(const std::string& ciphertext, Algorithm algo, const std::string& key);
    
    // Hashing
    std::string hash(const std::string& data, HashAlgorithm algo);
    
    // Key Generation
    std::string generateKey(Algorithm algo, int keySize = 256);
    void generateRSAKeyPair(std::string& privateKey, std::string& publicKey);
    
    // Utility functions
    static std::string base64Encode(const std::string& data);
    static std::string base64Decode(const std::string& data);
    static std::string generateRandomBytes(size_t length);

private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};

#endif