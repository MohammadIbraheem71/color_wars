#pragma once

// TODO: need to figure out how to manage collisions

enum class player{
    none,
    player1,
    player2
};

class cell{
    private:
        int value;
        player owner;
    public:
        cell();

        // returns the current cell value
        int get_value();

        // sets an owner for this cell
        void set_owner(player player_value);

        // get the current owner for this cell
        player get_owner() const;

        //resets the current cell, value to 0, owner to none
        void reset();

        // increments the current cell value
        void increment(player player_value);

        // returns true if the cell value is above 4
        bool critical();
};
