#ifndef WALLETRSA_H
#define WALLETRSA_H

#include <string>

#include <QString>

#include "openssl_wrapper/openssl_wrapper.h"

class WalletRsa {
public:

    WalletRsa(const QString &folder, const std::string &addr);

    static WalletRsa fromPublicKey(const std::string &publicKey);

    static void createRsaKey(const QString &folder, const std::string &addr, const std::string &password);

    /*
       Возвращает публичный ключ в base16
    */
    const std::string& getPublikKey() const;

    std::string encrypt(const std::string &message) const;

    void unlock(const std::string &password);

    std::string decryptMessage(const std::string &encryptedMessageHex) const;

private:

    WalletRsa() = default;

private:

    static std::string getPublicRsaKey(const QString &folder, const std::string &addr);

private:

    QString folder;

    std::string address;

    std::string publicKey;

    RsaKey publicKeyRsa;

    RsaKey privateKeyRsa;

};

#endif // WALLETRSA_H
