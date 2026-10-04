//Header write here
//Name

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <cctype>


//Output formatting constants
const int no_items = 4;
const int item_word_width = 14;
const int item_count_width =3;

// Clean a word by removing punctuation and converting to lowercase
void clean_entry(const std::string &original, std::string &cleaned)
{
    //find first alphanumeric character
    auto first = std::find_if(original.begin(), original.end(),
        [](char ch)
        {
            return std::isalnum(static_cast<unsigned char>(ch));
        });
    // find the first non-alphanumeric character after word begins
auto last = std::find_if(first,original.end(),
[](char ch)
{
    return !std::isalnum(static_cast<unsigned char>(ch));
});
// create cleaned word
cleaned = std::string(first, last);

//convert all letters to lowercase
std::for_each(cleaned.begin(), cleaned.end(), 
[](char &ch)
{
    ch = static_cast<char>(
        std::tolower(static_cast<unsigned char>(ch))
    );

    });

}
// read & process words from input
void get_words(std::map<std::string, int> &words)
{
    std::string original;
    std::string cleaned;

    //read each word from the input
    while (std::cin >> original)
    {
        //clean the word
        clean_entry(original, cleaned);
        // ignore empty words
        if (cleaned.length() == 0)
        {
            continue;
        }
        //add the word to the map and increase its frequency
        words[cleaned]++;
    }
}
// print the words and their frequencies
void print_words(const std::map<std::string, int> &words)
{
    int total_words = 0;
    //print each word and its frequency
    int count = 0;

    for (const auto &item : words)
    {
        std::cout << std::left << std::setw(item_word_width)
            << item.first << ":"
            << std::right << std::setw(item_count_width)
            << item.second << " ";

        total_words += item.second;
        ++count;
        //start a new line after every 4 words
        if (count % no_items == 0)
        {
            std::cout << std::endl;
        }
    }
    //print a new line if the last line was not full
    if (count % no_items != 0)
    {
        std::cout << std::endl;
    }
    //print a newline if the last line was not full
    if (count % no_items != 0)
    {
        std::cout << std::endl;
    }
    //print the totals 
    std::cout << "number of words in input stream : "
            << total_words << std::endl;

    std::cout << "number of words in output stream : "
    << words.size() << std::endl;
}
//Main
int main(){

    std::map<std::string, int> words;
    //return and count the words
    get_words(words);
    //print the words and their frequencies
    print_words(words);
    return 0;
}




