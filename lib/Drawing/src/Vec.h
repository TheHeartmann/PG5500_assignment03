#pragma once

struct Vec {
    int x;
    int y;

    Vec& operator=(const Vec& other){
        x = other.x;
        y = other.y;
        return *this;
    }

    Vec operator-(const Vec& other) const {
        return {x - other.x, y - other.y};
    }

    Vec operator+(const Vec& other) const {
        return {x + other.x, y + other.y};
    }
};