/*                                                                              
** EPITECH PROJECT, 2019                                                        
** nanoTests                                                                    
** File description:                                                            
** nanoTests.cpp                                                                  
*/

#include <criterion/criterion.h>
#include "../include/Circuit.hpp"
#include "../include/nanoTekSpice.hpp"
#include <vector>
#include <string>

namespace nts {

    Test(Circuit, addInput)
    {
        Circuit cir;
        std::string line = "input     in";

        cir.addComponent(line);
        cr_assert_eq(cir.getComponents().size(), 1);
        if (cir.getComponents().size() == 1) {
            cr_assert_eq(cir.getComponents()[0]->getName(), "in");
            cr_assert_eq(cir.getComponents()[0]->getNbPuts(), 1);
            cr_assert_eq(cir.getComponents()[0]->compute(), UNDEFINED);
            cir.getComponents()[0]->~Components();
        }
        else {
            cr_assert_eq(0, 1);
        }
    }

    Test(Circuit, addOutput)
    {
        Circuit cir;
        std::string line = "output     out";

        cir.addComponent(line);
        cr_assert_eq(cir.getComponents().size(), 1);
        if (cir.getComponents().size() == 1) {
            cr_assert_eq(cir.getComponents()[0]->getName(), "out");
            cr_assert_eq(cir.getComponents()[0]->getNbPuts(), 1);
            cr_assert_eq(cir.getComponents()[0]->compute(), UNDEFINED);
            cir.getComponents()[0]->~Components();
        }
        else {
            cr_assert_eq(0, 1);
        }
    }

    Test(Circuit, addAnd)
    {
        Circuit cir;
        std::string line = "4081     and";

        cir.addComponent(line);
        cr_assert_eq(cir.getComponents().size(), 1);
        if (cir.getComponents().size() == 1) {
            cr_assert_eq(cir.getComponents()[0]->getName(), "and");
            cr_assert_eq(cir.getComponents()[0]->getNbPuts(), 4);
            cr_assert_eq(cir.getComponents()[0]->getType(), "4081");
        }
        else {
            cr_assert_eq(0, 1);
        }
    }

    Test(NanoTekSpice, nanoTest1)
    {
        NanoTekSpice nano;
        char av[2][15] = { "./nanoTekSpice", "tests/and.nts" };

        cr_assert_eq(nano.progEntry(2, (char **)av), 84);
    }

    Test(True, trueTest)
    {
        IComponent *comp = new True("true");

        cr_assert_eq(comp->compute(1), TRUE);
        comp->~IComponent();
    }

    Test(False, falseTest)
    {
        IComponent *comp = new False("false");

        cr_assert_eq(comp->compute(1), FALSE);
        comp->~IComponent();
    }

    Test(Comp4081, andTest)
    {
        IComponent *comp = new Comp4081("and");

        comp->setValue(TRUE, 1);
        comp->setValue(FALSE, 2);
        cr_assert_eq(comp->compute(0), FALSE);
        comp->setValue(TRUE, 2);
        cr_assert_eq(comp->compute(0), TRUE);
        comp->~IComponent();
    }

    Test(Comp4071, orTest)
    {
        IComponent *comp = new Comp4071("or");

        comp->setValue(TRUE, 1);
        comp->setValue(FALSE, 2);
        cr_assert_eq(comp->compute(0), TRUE);
        comp->setValue(FALSE, 1);
        cr_assert_eq(comp->compute(0), FALSE);
        comp->~IComponent();
    }

    Test(Comp4001, norTest)
    {
        IComponent *comp = new Comp4001("nor");

        comp->setValue(TRUE, 1);
        comp->setValue(FALSE, 2);
        cr_assert_eq(comp->compute(0), FALSE);
        comp->setValue(FALSE, 1);
        cr_assert_eq(comp->compute(0), TRUE);
        comp->~IComponent();
    }

    Test(Comp4008, adderTest)
    {
        IComponent *comp = new Comp4008("adder");

        comp->setValue(TRUE, 9);
        comp->setValue(TRUE, 6);
        comp->setValue(FALSE, 7);
        comp->setValue(TRUE, 4);
        comp->setValue(TRUE, 5);
        cr_assert_eq(comp->compute(0), FALSE);
        cr_assert_eq(comp->compute(1), TRUE);
        comp->setValue(TRUE, 7);
        comp->setValue(FALSE, 4);
        comp->setValue(FALSE, 5);
        cr_assert_eq(comp->compute(0), TRUE);
        cr_assert_eq(comp->compute(1), TRUE);
        comp->setValue(FALSE, 9);
        comp->setValue(FALSE, 6);
        comp->setValue(FALSE, 7);
        cr_assert_eq(comp->compute(0), FALSE);
        cr_assert_eq(comp->compute(1), FALSE);
        comp->~IComponent();
    }

    Test(Comp4011, nandTest)
    {
        IComponent *comp = new Comp4011("nand");

        comp->setValue(TRUE, 1);
        comp->setValue(FALSE, 2);
        cr_assert_eq(comp->compute(0), TRUE);
        comp->setValue(TRUE, 2);
        cr_assert_eq(comp->compute(0), FALSE);
        comp->~IComponent();
    }

    Test(Comp4030, xorTest)
    {
        IComponent *comp = new Comp4030("xor");

        comp->setValue(TRUE, 1);
        comp->setValue(FALSE, 2);
        cr_assert_eq(comp->compute(0), TRUE);
        comp->setValue(TRUE, 2);
        cr_assert_eq(comp->compute(0), FALSE);
        comp->~IComponent();
    }

    Test(Comp4069, ReverseTest)
    {
        IComponent *comp = new Comp4069("reverse");

        comp->setValue(TRUE, 1);
        cr_assert_eq(comp->compute(0), FALSE);
        comp->setValue(FALSE, 1);
        cr_assert_eq(comp->compute(0), TRUE);
        comp->~IComponent();
    }

    Test(Clock, clockTest)
    {
        IComponent *comp = new Clock("clock");

        comp->setValue(FALSE, 1);
        cr_assert_eq(comp->compute(0), FALSE);
        comp->~IComponent();
    }

    Test(Error, errorTest)
    {
        NanoError err("error!");

        cr_assert_str_eq(err.what(), "error!");
        err.~NanoError();
    }

    Test(Parser, ParseFileTest1)
    {
        Parser parse;
        Circuit cir;

        cr_assert_eq(parse.parseFile((char *)"tests/and.nts", cir), 0);
        parse.~Parser();
    }

    Test(Parser, ParseFileTest2)
    {
        Parser parse;
        Circuit cir;

        try {
            parse.parseFile((char *)"truc", cir);
        }
        catch(NanoError &e) {
            cr_assert_str_eq(e.what(), "The file cannot be opened or doesn't exists.");
        }
    }

    Test(Parser, ParseFileTest3)
    {
        Parser parse;
        Circuit cir;

        try {
            parse.parseFile(NULL, cir);
        }
        catch(NanoError &e) {
            cr_assert_str_eq(e.what(), "The file name is empty or NULL.");
        }
    }

}