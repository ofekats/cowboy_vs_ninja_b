#pragma once
#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja : public Ninja
    {
        public:
            TrainedNinja(string name, Point poi);
            //virtual
            string print() override;
    };
}
