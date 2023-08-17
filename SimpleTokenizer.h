#pragma once
#include <iostream>

#include <tuple>
#include <regex>
#include <string>
#include <map>

/// <summary>
/// �ı�ת��Ϊ��������
/// </summary>
class SimpleTokenizer
{
public:
    SimpleTokenizer();
    virtual ~SimpleTokenizer();

    void Init();//��ʼ����Ա����
protected:
    std::regex pat;//������ʽ
    const int contextLength = 77;//�����ĳ��ȣ����ӳ���
    std::map<std::string, int> encoder;
    std::map<int, std::string> decoder;

    std::map<int, std::string> byte_encoder;
    std::map<std::string, int> byte_decoder;

    std::map<std::string, std::string> cache;
    std::map<std::tuple<std::string, std::string>, int> bpe_ranks;

    std::string bpe(const std::string& token);
    std::string whitespace_clean(std::string text);
    std::map<int, std::string> BytesToUnicode();
    std::string Decode(const std::vector<int>& tokens);
    std::vector<int64_t> Encode(const std::string& text);
    std::vector<std::tuple<std::string, std::string>> LoadBPEMerges(const std::string& bpePath);
    std::vector<std::pair<std::string, std::string>> GetPairs(const std::vector<std::string>& words);
};