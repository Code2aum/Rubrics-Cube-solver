#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE3DARRAY_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE3DARRAY_H

#include "RubiksCube.h"

class RubiksCube3dArray : public RubiksCube {
private:
    void rotateFace(int ind) {
        char temp_arr[3][3] = {};
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                temp_arr[i][j] = cube[ind][i][j];

        cube[ind][0][0] = temp_arr[2][0];
        cube[ind][0][1] = temp_arr[1][0];
        cube[ind][0][2] = temp_arr[0][0];
        cube[ind][1][0] = temp_arr[2][1];
        cube[ind][1][2] = temp_arr[0][1];
        cube[ind][2][0] = temp_arr[2][2];
        cube[ind][2][1] = temp_arr[1][2];
        cube[ind][2][2] = temp_arr[0][2];
    }

public:
    char cube[6][3][3]{};

    RubiksCube3dArray() {
        for(int i=0; i<6; i++)
            for(int j=0; j<3; j++)
                for(int k=0; k<3; k++)
                    cube[i][j][k] = getColorLetter(COLOR(i));
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[(int)face][row][col];
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
                    if(cube[i][j][k] != getColorLetter(COLOR(i))) return false;
                }
            }
        }
        return true;
    }

    RubiksCube &u() override {
        this->rotateFace(0);

        char temp[] = {cube[4][0][0],
                      cube[4][0][1],
                      cube[4][0][2]};
        cube[4][0][0] = cube[1][0][0];
        cube[4][0][1] = cube[1][0][1];
        cube[4][0][2] = cube[1][0][2];

        cube[1][0][0] = cube[2][0][0];
        cube[1][0][1] = cube[2][0][1];
        cube[1][0][2] = cube[2][0][2];

        cube[2][0][0] = cube[3][0][0];
        cube[2][0][1] = cube[3][0][1];
        cube[2][0][2] = cube[3][0][2];

        cube[3][0][0] = temp[0];
        cube[3][0][1] = temp[1];
        cube[3][0][2] = temp[2];

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

        char temp[] = {cube[0][0][0],
                      cube[0][1][0],
                      cube[0][2][0]};

        cube[0][0][0] = cube[4][2][2];
        cube[0][1][0] = cube[4][1][2];
        cube[0][2][0] = cube[4][0][2];

        cube[4][0][2] = cube[5][0][0];
        cube[4][1][2] = cube[5][1][0];
        cube[4][2][2] = cube[5][2][0];

        cube[5][0][0] = cube[2][0][0];
        cube[5][1][0] = cube[2][1][0];
        cube[5][2][0] = cube[2][2][0];

        cube[2][0][0] = temp[0];
        cube[2][1][0] = temp[1];
        cube[2][2][0] = temp[2];

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

        char temp[] = {cube[0][2][0],
                      cube[0][2][1],
                      cube[0][2][2]};

        cube[0][2][0] = cube[1][2][2];
        cube[0][2][1] = cube[1][1][2];
        cube[0][2][2] = cube[1][0][2];

        cube[1][0][2] = cube[5][0][0];
        cube[1][1][2] = cube[5][0][1];
        cube[1][2][2] = cube[5][0][2];

        cube[5][0][0] = cube[3][2][0];
        cube[5][0][1] = cube[3][1][0];
        cube[5][0][2] = cube[3][0][0];

        cube[3][0][0] = temp[0];
        cube[3][1][0] = temp[1];
        cube[3][2][0] = temp[2];

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

        char temp[] = {cube[0][0][2],
                      cube[0][1][2],
                      cube[0][2][2]};

        cube[0][0][2] = cube[2][0][2];
        cube[0][1][2] = cube[2][1][2];
        cube[0][2][2] = cube[2][2][2];

        cube[2][0][2] = cube[5][0][2];
        cube[2][1][2] = cube[5][1][2];
        cube[2][2][2] = cube[5][2][2];

        cube[5][0][2] = cube[4][2][0];
        cube[5][1][2] = cube[4][1][0];
        cube[5][2][2] = cube[4][0][0];

        cube[4][0][0] = temp[0];
        cube[4][1][0] = temp[1];
        cube[4][2][0] = temp[2];

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

        char temp[] = {cube[0][0][0],
                      cube[0][0][1],
                      cube[0][0][2]};

        cube[0][0][0] = cube[3][0][2];
        cube[0][0][1] = cube[3][1][2];
        cube[0][0][2] = cube[3][2][2];

        cube[3][0][2] = cube[5][2][2];
        cube[3][1][2] = cube[5][2][1];
        cube[3][2][2] = cube[5][2][0];

        cube[5][2][0] = cube[1][2][0];
        cube[5][2][1] = cube[1][1][0];
        cube[5][2][2] = cube[1][0][0];

        cube[1][0][0] = temp[0];
        cube[1][1][0] = temp[1];
        cube[1][2][0] = temp[2];

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

        char temp[] = {cube[2][2][0],
                      cube[2][2][1],
                      cube[2][2][2]};

        cube[2][2][0] = cube[1][2][0];
        cube[2][2][1] = cube[1][2][1];
        cube[2][2][2] = cube[1][2][2];

        cube[1][2][0] = cube[4][2][0];
        cube[1][2][1] = cube[4][2][1];
        cube[1][2][2] = cube[4][2][2];

        cube[4][2][0] = cube[3][2][0];
        cube[4][2][1] = cube[3][2][1];
        cube[4][2][2] = cube[3][2][2];

        cube[3][2][0] = temp[0];
        cube[3][2][1] = temp[1];
        cube[3][2][2] = temp[2];

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

    bool operator==(const RubiksCube3dArray &r1) const {
        for(int i=0; i<6; i++) {
            for(int j=0; j<3; j++) {
                for(int k=0; k<3; k++) {
                    if(cube[i][j][k] != r1.cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    RubiksCube3dArray &operator=(const RubiksCube3dArray &r1) = default;
};

struct Hash3d {
    size_t operator()(const RubiksCube3dArray &r1) const {
        string str;
        for(int i=0; i<6; i++) {
            for(int j=0; j<3; j++) {
                for(int k=0; k<3; k++) {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }
};

#endif //RUBIKS_CUBE_SOLVER_RUBIKSCUBE3DARRAY_H