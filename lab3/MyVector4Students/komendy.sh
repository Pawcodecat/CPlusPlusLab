# gdy mamy zainstalowany gtest w systemie (chodzi o Linuxy):
g++  main.cc  fraction.cpp  fractionTests.cpp vector.cpp vectorTests.cpp utils/argumentParsing.cc utils/programmersDetails.cc memoryManagement.cpp -o kolokwium -lgtest -lpthread

# gdy nie mamy, a jedynie zbudowaliśmy do ścieżki ${GTEST}
g++ -Ilibs/gtest/include/ main.cc  fraction.cpp  fractionTests.cpp vector.cpp vectorTests.cpp utils/argumentParsing.cc utils/programmersDetails.cc memoryManagement.cpp -o kolokwium -L-Ilibs/gtest/libsLinux -lgtest -lpthread
