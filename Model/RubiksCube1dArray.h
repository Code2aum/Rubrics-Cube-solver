#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE1DARRAY_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE1DARRAY_H

#include "RubiksCube.h"

class RubiksCube1dArray : public RubiksCube {
private:
    static inline int getIndex(int ind, int row, int col) {
        return (ind * 9) + (row * 3) + col;
    }

    void rotateFace(int ind) {
        char temp_arr[3][3];
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                temp_arr[i][j] = cube[getIndex(ind,i,j)];

        //Corners
        cube[getIndex(ind,0,0)] = temp_arr[2][0];
        cube[getIndex(ind,0,2)] = temp_arr[0][0];
        cube[getIndex(ind,2,2)] = temp_arr[0][2];
        cube[getIndex(ind,2,0)] = temp_arr[2][2];

        //Edges
        cube[getIndex(ind,0,1)] = temp_arr[1][0];
        cube[getIndex(ind,1,2)] = temp_arr[0][1];
        cube[getIndex(ind,2,1)] = temp_arr[1][2];
        cube[getIndex(ind,1,0)] = temp_arr[2][1];
    }

public:
    char cube[54]{};

    RubiksCube1dArray() {
        for(int i=0; i<6; i++)
            for(int j=0; j<3; j++)
                for(int k=0; k<3; k++)
                    cube[getIndex(i,j,k)] = getColorLetter(COLOR(i));
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[getIndex((int)face, row, col)];
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }

    bool isSolved() const override {
        for(int i=0; i<6; i++) {
            for(int j=0; j<3; j++) {
                for(int k=0; k<3; k++) {
                    if(cube[getIndex(i,j,k)] != getColorLetter(COLOR(i))) return false;
                }
            }
        }
        return true;
    }

    RubiksCube &u() override {
        this->rotateFace(0);

        char temp_arr[] = {cube[getIndex(4,0,0)],
                         cube[getIndex(4,0,1)],
                         cube[getIndex(4,0,2)]};

        cube[getIndex(4,0,0)] = cube[getIndex(1,0,0)];
        cube[getIndex(4,0,1)] = cube[getIndex(1,0,1)];
        cube[getIndex(4,0,2)] = cube[getIndex(1,0,2)];

        cube[getIndex(1,0,0)] = cube[getIndex(2,0,0)];
        cube[getIndex(1,0,1)] = cube[getIndex(2,0,1)];
        cube[getIndex(1,0,2)] = cube[getIndex(2,0,2)];

        cube[getIndex(2,0,0)] = cube[getIndex(3,0,0)];
        cube[getIndex(2,0,1)] = cube[getIndex(3,0,1)];
        cube[getIndex(2,0,2)] = cube[getIndex(3,0,2)];

        cube[getIndex(3,0,0)] = temp_arr[0];
        cube[getIndex(3,0,1)] = temp_arr[1];
        cube[getIndex(3,0,2)] = temp_arr[2];

        return *this;
    }

    RubiksCube &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &u2() override {
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &l() override {
        this->rotateFace(1);

        char temp_arr[] = {cube[getIndex(0,0,0)],
                         cube[getIndex(0,1,0)],
                         cube[getIndex(0,2,0)]};

        cube[getIndex(0,0,0)] = cube[getIndex(4,2,2)];
        cube[getIndex(0,1,0)] = cube[getIndex(4,1,2)];
        cube[getIndex(0,2,0)] = cube[getIndex(4,0,2)];

        cube[getIndex(4,0,2)] = cube[getIndex(5,0,0)];
        cube[getIndex(4,1,2)] = cube[getIndex(5,1,0)];
        cube[getIndex(4,2,2)] = cube[getIndex(5,2,0)];

        cube[getIndex(5,0,0)] = cube[getIndex(2,0,0)];
        cube[getIndex(5,1,0)] = cube[getIndex(2,1,0)];
        cube[getIndex(5,2,0)] = cube[getIndex(2,2,0)];

        cube[getIndex(2,0,0)] = temp_arr[0];
        cube[getIndex(2,1,0)] = temp_arr[1];
        cube[getIndex(2,2,0)] = temp_arr[2];

        return *this;
    }

    RubiksCube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &l2() override {
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &f() override {
        this->rotateFace(2);

        char temp_arr[] = {cube[getIndex(0,2,0)],
                         cube[getIndex(0,2,1)],
                         cube[getIndex(0,2,2)]};

        cube[getIndex(0,2,0)] = cube[getIndex(1,2,2)];
        cube[getIndex(0,2,1)] = cube[getIndex(1,1,2)];
        cube[getIndex(0,2,2)] = cube[getIndex(1,0,2)];

        cube[getIndex(1,0,2)] = cube[getIndex(5,0,0)];
        cube[getIndex(1,1,2)] = cube[getIndex(5,0,1)];
        cube[getIndex(1,2,2)] = cube[getIndex(5,0,2)];

        cube[getIndex(5,0,0)] = cube[getIndex(3,2,0)];
        cube[getIndex(5,0,1)] = cube[getIndex(3,1,0)];
        cube[getIndex(5,0,2)] = cube[getIndex(3,0,0)];

        cube[getIndex(3,0,0)] = temp_arr[0];
        cube[getIndex(3,1,0)] = temp_arr[1];
        cube[getIndex(3,2,0)] = temp_arr[2];

        return *this;
    }

    RubiksCube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &f2() override {
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &r() override {
        this->rotateFace(3);

        char temp_arr[] = {cube[getIndex(0,0,2)],
                         cube[getIndex(0,1,2)],
                         cube[getIndex(0,2,2)]};

        cube[getIndex(0,0,2)] = cube[getIndex(2,0,2)];
        cube[getIndex(0,1,2)] = cube[getIndex(2,1,2)];
        cube[getIndex(0,2,2)] = cube[getIndex(2,2,2)];

        cube[getIndex(2,0,2)] = cube[getIndex(5,0,2)];
        cube[getIndex(2,1,2)] = cube[getIndex(5,1,2)];
        cube[getIndex(2,2,2)] = cube[getIndex(5,2,2)];

        cube[getIndex(5,0,2)] = cube[getIndex(4,2,0)];
        cube[getIndex(5,1,2)] = cube[getIndex(4,1,0)];
        cube[getIndex(5,2,2)] = cube[getIndex(4,0,0)];

        cube[getIndex(4,0,0)] = temp_arr[0];
        cube[getIndex(4,1,0)] = temp_arr[1];
        cube[getIndex(4,2,0)] = temp_arr[2];

        return *this;
    }

    RubiksCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &b() override {
        this->rotateFace(4);

        char temp_arr[] = {cube[getIndex(0,0,0)],
                         cube[getIndex(0,0,1)],
                         cube[getIndex(0,0,2)]};

        cube[getIndex(0,0,0)] = cube[getIndex(3,0,2)];
        cube[getIndex(0,0,1)] = cube[getIndex(3,1,2)];
        cube[getIndex(0,0,2)] = cube[getIndex(3,2,2)];

        cube[getIndex(3,0,2)] = cube[getIndex(5,2,2)];
        cube[getIndex(3,1,2)] = cube[getIndex(5,2,1)];
        cube[getIndex(3,2,2)] = cube[getIndex(5,2,0)];

        cube[getIndex(5,2,0)] = cube[getIndex(1,2,0)];
        cube[getIndex(5,2,1)] = cube[getIndex(1,1,0)];
        cube[getIndex(5,2,2)] = cube[getIndex(1,0,0)];

        cube[getIndex(1,0,0)] = temp_arr[0];
        cube[getIndex(1,1,0)] = temp_arr[1];
        cube[getIndex(1,2,0)] = temp_arr[2];

        return *this;
    }

    RubiksCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &d() override {
        this->rotateFace(5);

        char temp_arr[] = {cube[getIndex(2,2,0)],
                         cube[getIndex(2,2,1)],
                         cube[getIndex(2,2,2)]};

        cube[getIndex(2,2,0)] = cube[getIndex(1,2,0)];
        cube[getIndex(2,2,1)] = cube[getIndex(1,2,1)];
        cube[getIndex(2,2,2)] = cube[getIndex(1,2,2)];

        cube[getIndex(1,2,0)] = cube[getIndex(4,2,0)];
        cube[getIndex(1,2,1)] = cube[getIndex(4,2,1)];
        cube[getIndex(1,2,2)] = cube[getIndex(4,2,2)];

        cube[getIndex(4,2,0)] = cube[getIndex(3,2,0)];
        cube[getIndex(4,2,1)] = cube[getIndex(3,2,1)];
        cube[getIndex(4,2,2)] = cube[getIndex(3,2,2)];

        cube[getIndex(3,2,0)] = temp_arr[0];
        cube[getIndex(3,2,1)] = temp_arr[1];
        cube[getIndex(3,2,2)] = temp_arr[2];

        return *this;
    }

    RubiksCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    RubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    }

    bool operator==(const RubiksCube1dArray &r1) const {
        for(int i=0; i<54; i++) {
            if(cube[i] != r1.cube[i]) return false;
        }
        return true;
    }

    RubiksCube1dArray &operator=(const RubiksCube1dArray &r1) = default;
};

struct Hash1d {
    size_t operator()(const RubiksCube1dArray &r1) const {
        string str;
        for(int i=0; i<54; i++) str += r1.cube[i];
        return hash<string>()(str);
    }
};

#endif //RUBIKS_CUBE_SOLVER_RUBIKSCUBE1DARRAY_H