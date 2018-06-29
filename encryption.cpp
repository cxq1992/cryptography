#include <iostream>
#include <string>
class caesarEncryption
{
  public:
    caesarEncryption() : key(5) {}
    caesarEncryption(int k) : key(k) {}
    std::string encrypting(std::string str)
    {
        for (int i = 0; i < str.length(); i++)
            str[i] = char(97 + (str[i] - 97 + key) % 26);
        return str;
    }
    std::string decrypting(std::string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            int tmp = str[i] - 97 - key;
            str[i] = char(97 + (tmp > 0 ? tmp : tmp + 26) % 26);
        }
        return str;
    }

  private:
    int key;
};

class vigenereEncryption
{
  public:
    vigenereEncryption() : key("vigenere") {}
    vigenereEncryption(std::string k) : key(k) {}
    std::string encrypting(std::string str)
    {
        for (int i = 0, j = 0; i < str.length(); i++, j = (j + 1) % key.length())
            str[i] = char(97 + (str[i] - 97 + key[j] - 97) % 26);
        return str;
    }
    std::string decrypting(std::string str)
    {
        for (int i = 0, j = 0; i < str.length(); i++, j = (j + 1) % key.length())
        {
            int tmp = str[i] - key[j];
            str[i] = char(97 + (tmp > 0 ? tmp : tmp + 26) % 26);
        }
        return str;
    }

  private:
    std::string key;
};

int main()
{
    caesarEncryption caesar(7);
    std::string str = "beginattacknow";
    std::string tmp = caesar.encrypting(str);
    std::cout << "caesarEncryption: " << tmp << std::endl;
    std::cout << "caesarDecryption: " << caesar.decrypting(tmp) << std::endl;
    std::cout << std::endl;
    vigenereEncryption vigenere;
    std::string tmp1 = vigenere.encrypting(str);
    std::cout << "vigenereEncryption: " << tmp1 << std::endl;
    std::cout << "vigenereEncryption: " << vigenere.decrypting(tmp1) << std::endl;
}