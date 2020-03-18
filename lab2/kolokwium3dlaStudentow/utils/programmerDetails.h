#ifndef PROGRAMMERS_DETAILS_H
#define PROGRAMMERS_DETAILS_H

#if __cplusplus < 201103L && !defined(_MSC_FULL_VER)
    #error C++11 or greater is required!
#endif

namespace StudentsInfo
{
    constexpr const char* const FIRSTNAME = "Paweł";
    constexpr const char* const SURNAME   = "Kocimski";

    constexpr const char* const MAIL    = "pawelpoczta1201@o2.pl";
    constexpr const char* const BOOK_ID = "305327";

    constexpr const char* const teacherMail = "bazior[at]agh.edu.pl"; // please do not change!

    void validateStudentsInfo();
}

#endif // PROGRAMMERS_DETAILS_H
