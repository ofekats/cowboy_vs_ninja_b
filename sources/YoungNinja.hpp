#pragma once
#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
        public:
            YoungNinja(string name, Point poi);
            //virtual
            virtual string print() override;
    };
}