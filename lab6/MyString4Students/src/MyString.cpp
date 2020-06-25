//
// Created by pawel on 27.04.2020.
//

#include "MyString.h"

#include <cstring>
#include <iterator>
#include <random>

MyString::MyString(const char* str): MyString(std::string(str))
{

}

MyString::MyString(const std::string& str) : size_(str.size()), capacity_(initialBufferSize + str.capacity())
{
    std::memcpy(initial_buffer, str.data(), std::min(initialBufferSize, str.size()));
    if(str.size() > initialBufferSize)
    {
        rest = std::string(str.data()+initialBufferSize);
    }
}

void MyString::clear()
{
    memset(initial_buffer, 0, initialBufferSize);
    rest.resize(0);
    capacity_ = initialBufferSize;
    size_ = 0;

}

const char& MyString::operator[](size_t index) const
{
    if(size_ <= index)
    {
        throw std::out_of_range("Out of range");
    }
    if(index >= initialBufferSize)
    {
        return rest[index - initialBufferSize];
    }
    else
    {
        return initial_buffer[index];
    }
}

char& MyString::operator[](size_t index)
{
    if(size_ <= index)
    {
        throw std::out_of_range("Out of range");
    }
    if(index >= initialBufferSize)
    {
        return rest[index - initialBufferSize];
    }
    else
    {
        return initial_buffer[index];
    }
}

MyString::iterator MyString::begin()
{
    return MyString::iterator(0, this);
}

MyString::const_iterator MyString::begin() const
{
    return cbegin();
}

MyString::const_iterator MyString::cbegin() const
{
    return MyString::const_iterator(0, this);
}

MyString::iterator MyString::end()
{
    return MyString::iterator(size_, this);
}

MyString::const_iterator MyString::end() const
{
    return cend();
}

MyString::const_iterator MyString::cend() const
{
    return MyString::const_iterator(size_, this);
}

std::ostringstream& operator<<(std::ostringstream& out, const MyString& my_str)
{
    for(auto character : my_str)
    {
        out << character;
    }
    return out;
}

void MyString::trim()
{
    auto start = std::find_if_not(this->begin(), this->end(), ::isspace);
    auto end_ = std::find_if_not(this->rbegin(), this->rend(), ::isspace);

    std::string temp;
    if(end_.base() == end()) {

    }
    temp.resize(std::distance(start, end_.base()));
    std::copy(start, end_.base(), temp.begin());
    *this = temp;
}

std::reverse_iterator<MyString::iterator> MyString::rbegin()
{
    return std::reverse_iterator<iterator>(end());
}

std::reverse_iterator<MyString::const_iterator> MyString::rbegin() const
{
    return crbegin();
}

MyString::const_reverse_iterator MyString::crbegin() const
{
    return std::reverse_iterator<const_iterator>(cend());
}


std::reverse_iterator<MyString::iterator> MyString::rend()
{
    return std::reverse_iterator<iterator>(iterator(0, this));
}

std::reverse_iterator<MyString::const_iterator> MyString::rend() const
{
    return crend();
}

MyString::const_reverse_iterator MyString::crend() const
{
    return std::reverse_iterator<const_iterator>(cbegin());
}

MyString& MyString::operator+=(const std::string& rhs)
{
    if(size_ >= initialBufferSize)
    {
        rest += rhs;
        size_ += rhs.size();
        capacity_ = initialBufferSize + rest.capacity();
    }
    else
    {
        std::memcpy(&initial_buffer[size_], rhs.data(), initialBufferSize - size_);
        rest = rhs.data() + (initialBufferSize - size_);
        size_ += rhs.size();
        capacity_ = initialBufferSize + rest.capacity();
    }
    return *this;
}

MyString& MyString::operator+=(char rhs)
{
    if(size_ >= initialBufferSize)
    {
        rest += rhs;
        ++size_;
        capacity_ = initialBufferSize + rest.capacity();
    }
    else
    {
        initial_buffer[size_] = rhs;
        ++size_;
        capacity_ = initialBufferSize + rest.capacity();
    }
    return *this;
}

std::set<MyString> MyString::getUniqueWords() const
{
    std::set<MyString> retval;
    std::string temp_str;
    std::transform(begin(), end(), std::back_inserter(temp_str), ::tolower);
    auto start = std::find_if(temp_str.begin(), temp_str.end(), ::isalpha);
    while(start != temp_str.end())
    {
        std::string token;
        auto end_ = std::find_if_not(start, temp_str.end(), ::isalpha);
        std::copy(start, end_, std::back_inserter(token));
        retval.insert(token);
        start = std::find_if(end_, temp_str.end(), ::isalpha);
    }
    return retval;
}

bool MyString::operator<(const MyString& rhs) const
{
    return std::lexicographical_compare(begin(), end(), rhs.begin(), rhs.end());
}

bool MyString::operator>(const MyString& rhs) const
{
    return std::lexicographical_compare(begin(), end(), rhs.begin(), rhs.end(), std::greater<>());
}

bool MyString::operator<=(const MyString& rhs) const
{
    return !(*this > rhs);
}

bool MyString::operator>=(const MyString& rhs) const
{
    return !(*this < rhs);
}

bool MyString::operator==(const MyString& rhs) const
{
    auto temp =  std::mismatch(begin(), end(), rhs.begin(), rhs.end());
    return temp.first == end();
}

bool MyString::operator!=(const MyString& rhs) const
{
    return !(*this == rhs);
}

std::map<MyString, size_t> MyString::countWordsUsage() const
{
    std::map<MyString, size_t> tmp;
    auto start = std::find_if(begin(), end(), ::isalpha);
    while(start != end())
    {
        std::string token;
        auto end_ = std::find_if_not(start, end(), ::isalpha);
        std::copy(start, end_, std::back_inserter(token));
        ++tmp[token];
        start = std::find_if(end_, end(), ::isalpha);
    }
    return tmp;
}

void MyString::toLower()
{
    std::transform(begin(), end(), begin(), ::tolower);
}

std::ostream& operator<<(std::ostream& out, const MyString& my_str)
{
    for(const auto& val : my_str)
    {
        out << val;
    }
    return out;
}

std::istringstream& operator>>(std::istringstream& in, MyString& my_str)
{
    my_str = in.str();
    return in;
}

std::istream& operator>>(std::istream& in, MyString& my_str)
{
    std::string temp;
    in >> temp;
    my_str = temp;
    return in;
}

MyString MyString::generateRandomWord(size_t length)
{

    thread_local static std::mt19937 rg{std::random_device{}()};
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(range) - 2);

    MyString retval;
    std::generate_n(std::back_inserter(retval), length, []() {return range[pick(rg)];});
    return retval;
}

bool MyString::startsWith(const MyString& pre) const
{
    return std::search(begin(), end(), pre.begin(), pre.end()) == begin();
}

bool MyString::endsWith(const MyString& past) const
{
    return std::search(rbegin(), rend(), past.rbegin(), past.rend()) == rbegin();
}

void MyString::push_back(char character)
{
    *this += character;
}

MyString MyString::join(const std::vector<MyString>& to_join) const
{
    MyString temp;
    for(size_t i = 0; i < to_join.size()-1; ++i)
    {
        std::copy(to_join[i].begin(), to_join[i].end(), std::back_inserter(temp));
        std::copy(begin(), end(), std::back_inserter(temp));
    }
    if(!to_join.empty())
    {
        const auto last_index = to_join.size() - 1;
        std::copy(to_join[last_index].begin(), to_join[last_index].end(), std::back_inserter(temp));
    }
    return temp;
}

MyString::MyString() : capacity_(initialBufferSize+rest.capacity())
{
}


