#pragma once
#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
        public:
            OldNinja(string name, Point poi);
            //virtual
            virtual string print() override;
    };
}