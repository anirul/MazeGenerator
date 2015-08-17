#include <assert.h>
#include "maze_generator.hpp"

maze_generator::maze_generator(
    unsigned int dx,
    unsigned int dy,
    unsigned int dz) :
    dx_(dx),
    dy_(dy),
    dz_(dz)
{
    assert(dx_);
    assert(dy_);
    assert(dz_);
}

maze_generator::~maze_generator() {}
