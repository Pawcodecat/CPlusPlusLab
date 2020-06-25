# gdy mamy zainstalowany gtest w systemie:
g++  main.cc  matrix.cc  matrixTests.cc utils/argumentParsing.cc utils/programmersDetails.cc -o kolokwium -lgtest -pthread

# gdy nie mamy, a chcemy skorzystać z teco, co dostarczyłem (linux):
g++ -Ilibs/gtest/include/ -I.  main.cc  matrix.cc  matrixTests.cc utils/argumentParsing.cc utils/programmersDetails.cc -o kolokwium -Llibs/gtest/libsLinux/ -lgtest -pthread


# gdy nie mamy, a chcemy skorzystać z własnego, który zbudowaliśmy do ścieżki ${GTEST}
g++ -I${GTEST}/include/ -I.  main.cc  matrix.cc  matrixTests.cc utils/argumentParsing.cc utils/programmersDetails.cc -o kolokwium -L${GTEST}/libs -lgtest -pthread


# uruchomienie:
./kolokwium

# skorzystanie z Cmake'a od p. Dima, który należy wrzucić do katalogu z kolokwium:
cmake . # 
./kolokwium



# opis instalacji gtesta: https://programowaniec.wordpress.com/2018/11/27/instalacja-gtest-na-linuxie/
