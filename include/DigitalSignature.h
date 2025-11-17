#ifndef DIGITALSIGNATURE_H
#define DIGITALSIGNATURE_H

#include <string>
#include <vector>
#include <memory> 

class DigitalSignature {
public:
    DigitalSignature();
    ~DigitalSignature();

    // Sign and verify with RSA
    std::string signMessage(const std::string& message, const std::string& privateKey);
    bool verifySignature(const std::string& message, const std::string& signature, 
                        const std::string& publicKey);

    // Sign and verify with DSA
    std::string signMessageDSA(const std::string& message, const std::string& privateKey);
    bool verifySignatureDSA(const std::string& message, const std::string& signature,
                           const std::string& publicKey);

    // Key generation
    void generateDSAParams(std::string& params);
    void generateDSAKeyPair(const std::string& params, std::string& privateKey, std::string& publicKey);

private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};

#endif