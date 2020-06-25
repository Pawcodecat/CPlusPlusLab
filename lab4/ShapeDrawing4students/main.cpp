#include <iostream>
#include <gtest/gtest.h>
#include <stdio.h>
#include "utils/programmerDetails.h"
#include "utils/argumentParsing.h"
#include "shape.h"
#include "shapecomposite.h"
#include "circle.h"
#include "rectangle.h"

/** Tresc zadan dla Panstwa:

Zadanie 0: absolutnie obowiazkowe, chociaz bez punktow
1) Pierwsza rzecza jest poprawa bledow kompilacji,
   czyli wpisanie poprawnych Panstwa danych w pliku: programmerDetails.h
2) Oddanne kolokwium musi sie bezwzglednie kompilowac,
   jesli sie nie skompiluje to jest to 0 punktow za kolokwium!
   Oczywiscie w razie problemow z kompilacja prosze pisać.
   Dobrze, jesli nie byloby warningow kompilacji, ale za to nie obnizam punktow.
3) Oddane kolokwium nie powinno crashować na żadnym teście,
   jeśli crashuje proszę zrobic implementacje -fake, ktora bedzie zwracac zawsze te same wartosci
   -test bedzie failowal, ale za to testy nie beda sie crashowaly.
   Jak ktos nie lubi fake'ow to moze odszukac test,
   ktory crashuje i zmienic jego nazwe dodajac z przodu prefix DISABLED_
   -wtedy test nie bedzie uruchamiany w ogole.
   W przypadku crasha biorę pod uwagę tylko tyle testów, ile przejdzie do czasu crasha!
5) Mam program antyplagiatowy, dlatego prosze pracowac samodzielnie!
   Osoby ktore udostepniaja swoje rozwiazania rowniez beda mialy kare!

Zadanie implementacyjne - patrz pliki: shape.h
**/
template< typename T >
struct array_deleter
{
    void operator ()( T const * p)
    {
        delete[] p;
    }
};

int main(int argc, char* argv[])
{

    std::shared_ptr<Shapes::Shape> sp[5];

    sp[0] = std::shared_ptr<Shapes::Shape> (new Shapes::Circle(2, 3, 5)) ;
    sp[1] = std::shared_ptr<Shapes::Shape> (new Shapes::Rectangle(1, 2, 9, 4));
    sp[2] = std::shared_ptr<Shapes::Shape> (new Shapes::ShapeComposite(sp[0], sp[1], Shapes::ShapeOperation::SUM));
    sp[3] = std::shared_ptr<Shapes::Shape> (new Shapes::ShapeComposite(sp[0], sp[1], Shapes::ShapeOperation::INTERSECTION));
    sp[4] = std::shared_ptr<Shapes::Shape> (new Shapes::ShapeComposite(sp[0], sp[1], Shapes::ShapeOperation::DIFFERENCE));

    for (auto s : sp)
        std::cout<< ((s->isIn(4,3)) ? "Pkt należy\n" : "Pkt nie należy\n");


    StudentsInfo::validateStudentsInfo();

    ArgumentParsing::reactToProgramArgumentsPossibilyExit(argc, argv);

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
