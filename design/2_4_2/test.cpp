#include <iostream>
#include <string>
using namespace std;

// ��ϵͳ�ࣺFileReader
class FileReader
{
public:
    string Read(const string &fileNameSrc)
    {
        // ģ���ȡ�ļ�����
        cout << "Reading file: " << fileNameSrc << endl;
        return "FileContent";
    }
};

// ��ϵͳ�ࣺFileWriter
class FileWriter
{
public:
    void Write(const string &encryptText, const string &fileNameDes)
    {
        // ģ��д���ļ�����
        cout << "Writing encrypted text to file: " << fileNameDes << endl;
    }
};

// ��ϵͳ�ࣺCipherMachine
class CipherMachine
{
public:
    string Encrypt(const string &plainText)
    {
        // ģ����ܹ���
        cout << "Encrypting text: " << plainText << endl;
        return "EncryptedText";
    }
};

// ��ϵͳ�ࣺNewCipherMachine
class NewCipherMachine
{
public:
    string Encrypt(const string &plainText)
    {
        // ģ���µļ��ܹ���
        cout << "New Encrypting text: " << plainText << endl;
        return "NewEncryptedText";
    }
};

// ��������ࣺAbstractEncryptFacade
class AbstractEncryptFacade
{
public:
    virtual void FileEncrypt(const string &fileNameSrc, const string &fileNameDes) = 0;
    virtual ~AbstractEncryptFacade() = default;
};

// ��������ࣺEncryptFacade
class EncryptFacade : public AbstractEncryptFacade
{
private:
    FileReader reader;
    CipherMachine cipher;
    FileWriter writer;

public:
    void FileEncrypt(const string &fileNameSrc, const string &fileNameDes) override
    {
        string plainText = reader.Read(fileNameSrc);
        string encryptText = cipher.Encrypt(plainText);
        writer.Write(encryptText, fileNameDes);
    }
};

// ��������ࣺNewEncryptFacade
class NewEncryptFacade : public AbstractEncryptFacade
{
private:
    FileReader reader;
    NewCipherMachine cipher;
    FileWriter writer;

public:
    void FileEncrypt(const string &fileNameSrc, const string &fileNameDes) override
    {
        string plainText = reader.Read(fileNameSrc);
        string encryptText = cipher.Encrypt(plainText);
        writer.Write(encryptText, fileNameDes);
    }
};

// �ͻ��˴���
int main()
{
    AbstractEncryptFacade *encryptFacade = new EncryptFacade();
    encryptFacade->FileEncrypt("source.txt", "destination.txt");
    delete encryptFacade;

    AbstractEncryptFacade *newEncryptFacade = new NewEncryptFacade();
    newEncryptFacade->FileEncrypt("source.txt", "destination.txt");
    delete newEncryptFacade;

    return 0;
}