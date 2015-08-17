#ifndef MAZE_GENERATOR_H_
#define MAZE_GENERATOR_H_

class maze_generator {
private:
    unsigned int dx_;
    unsigned int dy_;
    unsigned int dz_;
public:
    maze_generator(
	unsigned int dx,
	unsigned int dy,
	unsigned int dz = 1);
    virtual ~maze_generator();
};

#endif // MAZE_GENERATOR_H_
