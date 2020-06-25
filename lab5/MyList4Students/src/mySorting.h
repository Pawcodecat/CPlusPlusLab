//
// Created by pawel on 06.04.2020.
//

#ifndef MYLIST4STUDENTS_MYSORTING_H
#define MYLIST4STUDENTS_MYSORTING_H

#include <functional>

template <typename Container, typename Compare = std::greater<>>
void mySort(Container& container, Compare comp = Compare())
{
    auto start = std::begin(container);
    auto end = std::end(container);
    for (auto checked = start; start != end; end = checked ){
        checked = start;
        for (auto iter = start, before_iter = start; ++iter != end; ++before_iter){
            if ( comp(*before_iter, *iter)){
                std::iter_swap( iter, before_iter );
                checked = iter;
            }
        }
    }
}







template <int i, int j, typename Compare = std::greater<>>
void mySort(char (&container)[j][i], Compare comp = Compare())
{
    auto start = std::begin(container);
    auto end = std::end(container);
    for (auto checked = start; start != end; end = checked ){
        checked = start;
        for (auto iter = start, before_iter = start; ++iter != end; ++before_iter){
            bool flag = false;
            for(int k = 0; k < i; k++){
                if(comp(std::tolower((*before_iter)[k]), std::tolower((*iter)[k]))){
                    flag = true;
                }
                else if(comp(std::tolower((*iter)[k]), std::tolower((*before_iter)[k]))){
                    break;
                }
            }
            if (flag){
                std::iter_swap( iter, before_iter );
                checked = iter;
            }
        }
    }
}









#endif //MYLIST4STUDENTS_MYSORTING_H