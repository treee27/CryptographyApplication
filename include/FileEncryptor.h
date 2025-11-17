#ifndef FILEENCRYPTOR_H
#define FILEENCRYPTOR_H

#include <string>
#include "CryptoManager.h"

class FileEncryptor {
public:
    FileEncryptor();
    
    bool encryptFile(const std::string& inputFile, const std::string& outputFile,
                    Algorithm algo, const std::string& key);
    bool decryptFile(const std::string& inputFile, const std::string& outputFile,
                    Algorithm algo, const std::string& key);
    
    std::string calculateFileHash(const std::string& filePath, HashAlgorithm algo);
    bool verifyFileIntegrity(const std::string& filePath, const std::string& expectedHash, HashAlgorithm algo);

private:
    CryptoManager cryptoManager;
};

#endif