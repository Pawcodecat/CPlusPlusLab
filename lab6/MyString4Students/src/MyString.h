//
// Created by pawel on 27.04.2020.
//
#ifndef MYSTRING4STUDENTS_MYSTRING_H
#define MYSTRING4STUDENTS_MYSTRING_H
#include <sstream>
#include <stdlib.h>
#include <set>
#include <functional>
#include <map>

class MyString
{
public:
    static constexpr size_t initialBufferSize = 20;

private:
    size_t size_ = 0;
    std::string rest{};
    size_t capacity_ = initialBufferSize;
    char initial_buffer[initialBufferSize] = {};

public:

    MyString();
    MyString(const char* str);
    MyString(const std::string& str);

    const char& operator[](size_t index) const;
    char& operator[](size_t index);
    void clear();

    [[nodiscard]] size_t size() const
    {
        return size_;
    };

    [[nodiscard]] size_t capacity() const
    {
        return capacity_;
    }
    [[nodiscard]] bool empty() const
    {
        return size_==0;
    }

    struct const_iterator
    {
        typedef const_iterator self_type;
        typedef char value_type;
        typedef const char& reference;
        typedef const char* pointer;
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;
    private:
        int index_;
        const MyString* mystring_;
        explicit const_iterator(int index, const MyString* mystring) : index_(index), mystring_(mystring) {};
    public:
        reference operator*() const {return (*mystring_)[index_];}
        pointer operator->() const {return  &((*mystring_)[index_]);}
        self_type& operator++() {++index_; return *this;}
        self_type operator++(int) {auto ret = *this; ++index_; return ret;}
        self_type& operator--() {--index_; return *this;}
        self_type operator--(int) {auto ret = *this; --index_; return ret;}
        bool operator==(const const_iterator& rhs) const { return index_ == rhs.index_; }
        bool operator!=(const const_iterator& rhs) const { return index_ != rhs.index_; }

        const_iterator(): index_(-1), mystring_(nullptr){};
        friend class MyString;
    };

    struct iterator
    {
        typedef iterator self_type;
        typedef char value_type;
        typedef char& reference;
        typedef char* pointer;
        typedef ptrdiff_t difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;
    private:
        int index_;
        MyString* mystring_;

    public:
        reference operator*() const {return (*mystring_)[index_];}
        pointer operator->() const {return  &((*mystring_)[index_]);}
        self_type& operator++() {++index_; return *this;}
        self_type operator++(int) {auto ret = *this; ++index_; return ret;}
        self_type& operator--() {--index_; return *this;}
        self_type operator--(int) {auto ret = *this; --index_; return ret;}
        bool operator==(iterator rhs) const {return index_ == rhs.index_ && mystring_ == rhs.mystring_;}
        bool operator!=(iterator rhs) const {return index_ != rhs.index_ || mystring_ != rhs.mystring_;}
        operator const_iterator() {return const_iterator{index_, mystring_};};

        iterator(): index_(-1), mystring_(nullptr){};
    private:
        explicit iterator(int index, MyString* mystring) : index_(index),mystring_(mystring) {};
        friend class MyString;
    };

    typedef char value_type;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    [[nodiscard]]iterator begin();
    [[nodiscard]]const_iterator begin() const;
    [[nodiscard]]const_iterator cbegin() const;

    [[nodiscard]]reverse_iterator rbegin();
    [[nodiscard]]const_reverse_iterator rbegin() const;
    [[nodiscard]]const_reverse_iterator crbegin() const;

    [[nodiscard]]iterator end();
    [[nodiscard]]const_iterator end() const;
    [[nodiscard]]const_iterator cend() const;

    [[nodiscard]]reverse_iterator rend();
    [[nodiscard]]const_reverse_iterator rend() const;
    [[nodiscard]]const_reverse_iterator crend() const;

    void trim();
    MyString& operator+=(const std::string& rhs);
    MyString& operator+=(char rhs);
    void push_back(char character);

    bool operator <(const MyString& rhs) const;
    bool operator <=(const MyString& rhs) const;
    bool operator >=(const MyString& rhs) const;
    bool operator >(const MyString& rhs) const;
    bool operator ==(const MyString& rhs) const;
    bool operator !=(const MyString& rhs) const;

    [[nodiscard]] std::set<MyString> getUniqueWords() const;
    std::map<MyString, size_t> countWordsUsage() const;
    void toLower();

    friend std::ostream& operator<<(std::ostream& out, const MyString& my_str);
    friend std::istream& operator>>(std::istream& in, MyString& my_str);
    friend std::istringstream& operator>>(std::istringstream& in, MyString& my_str);

    static MyString generateRandomWord(size_t length);
    bool startsWith(const MyString& pre) const;
    bool endsWith(const MyString& past) const;

    MyString join(const std::vector<MyString>& to_join) const;

    template <typename UnaryPredicate>
    bool all_of(UnaryPredicate p) const;

    static constexpr char range[] = "abcdefghijklmnopqrstuvwxyz"
                                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

};

template<typename UnaryPredicate>
bool MyString::all_of(UnaryPredicate p) const
{
    return std::all_of(begin(), end(), p);
}


#endif //MYSTRING4STUDENTS_MYSTRING_H