/**
    Template AVL tree
    Copyright (C) 2014 Caleb Donovick

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 */
#include <iostream>
#include "metatree.h"
#include <chrono>
#include <random>
#include <limits>
#include <cassert>

int main()
{

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);
    std::uniform_int_distribution<int> range (std::numeric_limits<int>::min()>>11, std::numeric_limits<int>::max()>>11);
    std::uniform_int_distribution<int> coin (0,3);
    int roll;

    metaTree<int> t;
    std::cout << "stress test #1 (inserts):\n";

    for(size_t i = 0; i < 0x00100000; i++) {
        roll = range(gen);
        t.insert(roll);
        if (i%0x000010000 == 0) {
            std::cout << '.';
            std::cout.flush();
        }
    }
    std::cout << std::endl;

    assert(t.pointerCheck());
    std::cout << "Pointers are consistent" << std::endl;

    assert(t.heightCheck());
    std::cout << "Heights are correct" << std::endl;

    assert(t.bstCheck());
    std::cout << "The tree is a BST" << std::endl;

    assert(t.balancedCheck());
    std::cout << "The tree is balanced" << std::endl;

    assert(t.size() == t.sizeCheck());
    std::cout << "Size is correct " << t.size() <<std::endl;

    std::cout << "\nstress test #2 (removes):\n";

    for(size_t i = 0; i < 0x00100000; i++) {
        roll = range(gen);
        t.remove(roll);
        if (i%0x000010000 == 0) {
            std::cout << '.';
            std::cout.flush();
        }
    }
    std::cout << std::endl;

    assert(t.pointerCheck());
    std::cout << "Pointers are consistent" << std::endl;

    assert(t.heightCheck());
    std::cout << "Heights are correct" << std::endl;

    assert(t.bstCheck());
    std::cout << "The tree is a BST" << std::endl;

    assert(t.balancedCheck());
    std::cout << "The tree is balanced" << std::endl;

    assert(t.size() == t.sizeCheck());
    std::cout << "Size is correct " << t.size() <<std::endl;

    std::cout << "\nstress test #3 (inserts & removes):\n";
    for(size_t i = 0; i < 0x00200000; i++) {
        roll = range(gen);
        if (coin(gen) == 0) {
            t.insert(roll);
        } else {
            t.remove(roll);
        }
        if (i%0x000020000 == 0) {
            std::cout << '.';
            std::cout.flush();
        }
    }
    std::cout << std::endl;

    assert(t.pointerCheck());
    std::cout << "Pointers are consistent" << std::endl;

    assert(t.heightCheck());
    std::cout << "Heights are correct" << std::endl;

    assert(t.bstCheck());
    std::cout << "The tree is a BST" << std::endl;

    assert(t.balancedCheck());
    std::cout << "The tree is balanced" << std::endl;

    assert(t.size() == t.sizeCheck());
    std::cout << "Size is correct " << t.size() << std::endl;

    do {
        roll = range(gen);
    } while(!t.search(roll));

    for(size_t i = 0; i < 0x00010000 && roll != std::numeric_limits<int>::min(); i++) {
        assert(t.succ(roll) == std::numeric_limits<int>::min() || t.pred(t.succ(roll)) == roll);
        roll = t.succ(roll);
        if (i%0x000001000 == 0) {
            std::cout << '.';
            std::cout.flush();
        }
    }
    std::cout << std::endl;

    std::cout << "Predecessors and successors are good " << std::endl;
    return 0;
}
